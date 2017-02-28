///
/// :header: MapRadiusPickerViewController.swift
///
/// :author: Patrick Winchell
/// :created: 09-08-2016
///
/// :copyright: Copyright (c) 2016 INRIX, Inc.
///
///     INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
///     trademark notice(s) contained herein or in related code, files or
///     documentation shall not be altered and shall be included in all copies and
///     substantial portions of the software. This software is "Sample".
///     Refer to the License.pdf file for your rights to use this software.
///

import Foundation

/// Picker map displays a rect that the user can drag.
class MapQuadkeyPickerViewController: MapViewController {

    init(quadkey: Quadkey, changeHandler: @escaping (_ newValue: ParamValue) -> Void) {
        super.init(nibName: nil, bundle: nil)
        self.quadkey = quadkey
        self.changeHandler = changeHandler
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var quadkey = Quadkey(coordinate: CLLocationCoordinate2D(latitude: 0, longitude: 0), zoomLevel: 12) {
        didSet {
            if oldValue != self.quadkey {
                self.updateOverlay()
                self.changeHandler(self.quadkey)
            }
        }
    }

    var overlay: MKOverlay?
    var tileOverlay: MKTileOverlay?

    var changeHandler: (_ newValue: ParamValue) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.updateOverlay()

        let rect = self.quadkey.toMKMapRect()

        self.mapView.visibleMapRect = MKMapRectInset(rect, -rect.size.width, -rect.size.height)
        let recognizer = UITapGestureRecognizer(target: self, action: #selector(MapQuadkeyPickerViewController.handleTap(recognizer:)))
        recognizer.cancelsTouchesInView = false
        self.mapView.addGestureRecognizer(recognizer)

        let tileOverlay = QuadkeyTileOverlay()
        self.mapView.add(tileOverlay)

    }

    func updateOverlay() {
        DispatchQueue.main.async {
            if let mapView = self.mapView {
                if let overlay = self.overlay {
                    mapView.remove(overlay)
                }
                let overlay = self.quadkey.toMKCoordinateRegion().polygon
                self.overlay = overlay
                mapView.add(overlay)
            }
        }
    }

    func mapView(_ mapView: MKMapView, rendererForOverlay overlay: MKOverlay) -> MKOverlayRenderer {
        if let overlay = overlay as? MKPolygon {
            let renderer = MKPolygonRenderer(polygon: overlay)
            renderer.fillColor = UIColor(red: 0, green: 0, blue: 1.0, alpha: 0.25)
            return renderer
        }
        if let overlay = overlay as? QuadkeyTileOverlay {
            let renderer = QuadkeyTileOverlayRender(tileOverlay: overlay)
            return renderer
        }
        return MKOverlayRenderer(overlay: overlay)
    }

    func handleTap(recognizer:UITapGestureRecognizer) {
        if (recognizer.state == .ended) {
            let point = recognizer.location(in: self.mapView)
            self.updateQuadkey(mapView: self.mapView, point: point)
        }
    }

    func updateQuadkey(mapView: MKMapView, point: CGPoint) {
        let left = MKMapPointForCoordinate(mapView.convert(CGPoint(x: 0, y: 0), toCoordinateFrom: mapView))
        let right = MKMapPointForCoordinate(mapView.convert(CGPoint(x: mapView.frame.width, y: 0), toCoordinateFrom: mapView))

        let distance = sqrt(pow(left.x - right.x, 2) + pow(left.y - right.y, 2))
        let zoomScale = Double(mapView.frame.width) / distance
        let zoom = Int(floor((20 + log(zoomScale) / log(2)) + 1.51))
        let coordinate = mapView.convert(point, toCoordinateFrom: self.mapView)
        self.quadkey = Quadkey(coordinate: coordinate, zoomLevel: zoom)
    }
}

class QuadkeyTileOverlay : MKTileOverlay {
}

class QuadkeyTileOverlayRender : MKTileOverlayRenderer {

    override init(overlay: MKOverlay) {
        super.init(overlay: overlay)
    }

    override init(tileOverlay overlay: MKTileOverlay) {
        super.init(tileOverlay: overlay)
    }

    override func canDraw(_ mapRect: MKMapRect, zoomScale: MKZoomScale) -> Bool {
        return true
    }

    override func draw(_ mapRect: MKMapRect, zoomScale: MKZoomScale, in context: CGContext) {
        let scaleModifier = CGFloat(1.0 / zoomScale)
        let lineWidth = 2.0 * scaleModifier
        let fontSize = 24 * scaleModifier
        context.setStrokeColor(UIColor.black.cgColor)
        context.setLineWidth(lineWidth)

        let rect = CGRect(origin: CGPoint(x: mapRect.origin.x, y: mapRect.origin.y),
                          size: CGSize(width: mapRect.size.width, height: mapRect.size.height))

        context.stroke(rect)

        context.saveGState()

        context.translateBy(x: rect.origin.x, y: rect.origin.y)
        context.scaleBy(x: 1.0, y: -1.0)
        context.translateBy(x: 0, y: -rect.size.height)

        let zoom = Int(floor((20 + log(zoomScale) / log(2)) + 1.51))
        let quadkey = Quadkey(coordinate: MKCoordinateForMapPoint(mapRect.origin), zoomLevel: zoom - 1)
        let quadkeyValue = quadkey.toString()
        let attributes = [NSFontAttributeName : UIFont.monospacedDigitSystemFont(ofSize: fontSize, weight: UIFontWeightRegular)]

        // Create the Core Text framesetter using the attributed string.
        let framesetter = CTFramesetterCreateWithAttributedString(NSAttributedString(string: quadkeyValue, attributes: attributes))

        // Create the Core Text frame using our current view rect bounds.
        let pathRect = CGRect(origin: CGPoint.zero, size: CGSize(width: rect.size.width, height: rect.size.height)).insetBy(dx: 4 * scaleModifier, dy: 4 * scaleModifier)
        let path = UIBezierPath(rect: pathRect)
        let frame =  CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path.cgPath, nil)

        CTFrameDraw(frame, context)

        context.restoreGState()
    }
}
