///
/// :header: Quadkey.swift
///
/// :author: Patrick Winchell
/// :created: 02-23-2017
///
/// :copyright: Copyright (c) 2017 INRIX, Inc.
///
///     INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
///     trademark notice(s) contained herein or in related code, files or
///     documentation shall not be altered and shall be included in all copies and
///     substantial portions of the software. This software is "Sample".
///     Refer to the License.pdf file for your rights to use this software.
///

import Foundation

struct Quadkey : Hashable, ParamValue {
    //-----------------------------------------------------------------------------
    // MARK: - Properties

    fileprivate var stringVal = ""

    var hashValue: Int { return stringVal.hashValue }

    var zoomLevel: Double { return Double(self.stringVal.characters.count) }

    //-----------------------------------------------------------------------------
    // MARK: - Lifecycle

    init(coordinate: CLLocationCoordinate2D, zoomLevel: Int) {
        let pixelXY = latLongToPixelXY(coordinate.latitude, lon: coordinate.longitude, levelOfDetail: zoomLevel)
        let tileXY = pixelXYToTileXY(pixelXY)
        self.stringVal = tileXYToQuadKey(tileXY.x, tileY: tileXY.y, levelOfDetail: zoomLevel)
    }

    //-----------------------------------------------------------------------------
    // MARK: - Conversions

    func toString() -> String {
        return self.stringVal
    }

    func toMKCoordinateRegion() -> MKCoordinateRegion {
        let tile = self.quadkeyToTile(self.stringVal)

        // Get the next tile diagonally down-right
        let nextTile = (x: tile.x + 1, y: tile.y + 1)
        let first = tileToLocation(tile, zoomLevel: self.zoomLevel)
        let second = tileToLocation(nextTile, zoomLevel: self.zoomLevel)
        let minCoord = CLLocationCoordinate2D( latitude: min(first.latitude, second.latitude), longitude: min(first.longitude, second.longitude))
        let maxCoord = CLLocationCoordinate2D( latitude: max(first.latitude, second.latitude), longitude: max(first.longitude, second.longitude))

        let centerCoord = CLLocationCoordinate2D(latitude: (minCoord.latitude + maxCoord.latitude) / 2, longitude: (minCoord.longitude + maxCoord.longitude) / 2)
        let span = MKCoordinateSpan(latitudeDelta: abs(minCoord.latitude - maxCoord.latitude), longitudeDelta: abs(minCoord.longitude - maxCoord.longitude))
        return MKCoordinateRegion(center: centerCoord, span: span)
    }

    func toMKMapRect() -> MKMapRect {
        let tile = self.quadkeyToTile(self.stringVal)

        // Get the next tile diagonally down-right
        let nextTile = (x: tile.x + 1, y: tile.y + 1)
        let firstCoord = tileToLocation(tile, zoomLevel: self.zoomLevel)
        let secondCoord = tileToLocation(nextTile, zoomLevel: self.zoomLevel)

        let firstPoint = MKMapPointForCoordinate(firstCoord)
        let secondPoint = MKMapPointForCoordinate(secondCoord)

        return MKMapRect(origin: MKMapPoint(x: min(firstPoint.x, secondPoint.x), y: min(firstPoint.y, secondPoint.y)),
                         size: MKMapSize(width: abs(secondPoint.x - firstPoint.x), height: abs(secondPoint.y - firstPoint.y)))
    }

    //-----------------------------------------------------------------------------
    // MARK: - QuadKey Math
    // Most of this is a reimplmentation of the Bing Maps Tile System library
    // https://msdn.microsoft.com/en-us/library/bb259689.aspx

    fileprivate func latLongToPixelXY(_ lat:Double, lon:Double, levelOfDetail:Int) -> (x:Int, y:Int) {
        let x = (lon + 180) / 360
        let sinLatitude = sin(lat * M_PI / 180)
        let y = 0.5 - log((1 + sinLatitude) / (1 - sinLatitude)) / (4 * M_PI)

        let mapSize = MapSize(levelOfDetail)
        let pixelX = Clip(x * mapSize + 0.5, minValue: 0, maxValue: mapSize - 1)
        let pixelY = Clip(y * mapSize + 0.5, minValue: 0, maxValue: mapSize - 1)

        return (Int(pixelX), Int(pixelY))
    }

    fileprivate func MapSize(_ levelOfDetail:Int) -> Double {
        if (levelOfDetail == 23) {
            return 2147483648
        }
        return Double(256 << levelOfDetail)
    }

    fileprivate func Clip(_ n:Double, minValue:Double, maxValue:Double) -> Double {
        return min(max(n, minValue), maxValue)
    }

    fileprivate func pixelXYToTileXY(_ pixel:(x:Int, y:Int)) -> (x:Int, y:Int) {
        return (pixel.x / 256, pixel.y / 256)
    }

    fileprivate func tileXYToQuadKey(_ tileX: Int, tileY: Int, levelOfDetail: Int) -> String {
        var quadKey = ""
        for i in (1 ... levelOfDetail).reversed() {
            var digit = 0
            let mask = 1 << (i - 1)
            if ((tileX & mask) != 0) {
                digit += 1
            }
            if ((tileY & mask) != 0) {
                digit += 2
            }
            quadKey += String(digit)
        }
        return quadKey
    }

    fileprivate func quadkeyToTile(_ qk: String) -> (x: Double, y: Double) {
        let chars = qk.characters.map { String($0) }
        let zoomLevel: Double = Double(chars.count)
        var x: Double = 0
        var y: Double = 0

        for i in (0 ..< chars.count).reversed() {
            let factor = pow(2.0, zoomLevel - Double(i) - 1.0)
            let char = chars[i]
            switch Int(char)! {
            case 0:
                break
            case 1:
                x += factor
                break
            case 2:
                y += factor
                break
            case 3:
                x += factor
                y += factor
                break
            default:
                break
            }
        }

        return (x: x, y: y)
    }

    fileprivate func tileToLocation(_ tile:(x:Double, y:Double), zoomLevel:Double) -> CLLocationCoordinate2D {
        let longitude = ((tile.x * 360.0) / pow(2.0, zoomLevel)) - 180.0
        let expY = exp((0.5 - (tile.y / pow(2.0, zoomLevel))) * 4.0 * M_PI)
        let latitude = asin(  (expY - 1.0) / (expY + 1.0)) * 180.0 / M_PI

        return CLLocationCoordinate2D(latitude: latitude, longitude: longitude)
    }
}

func ==(lhs: Quadkey, rhs: Quadkey) -> Bool {
    return lhs.toString() == rhs.toString()
}

extension Quadkey: ParamValueWithPushablePicker {
    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {
        return MapQuadkeyPickerViewController(quadkey: self, changeHandler: changeHandler)
    }
}
