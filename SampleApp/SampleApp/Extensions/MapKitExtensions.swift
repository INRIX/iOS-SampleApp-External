///
/// :header: MapKitExtensions.swift
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

extension MKCoordinateRegion {
    var nw: CLLocationCoordinate2D { return CLLocationCoordinate2D(latitude: self.center.latitude + self.span.latitudeDelta / 2, longitude: self.center.longitude - self.span.longitudeDelta / 2 ) }
    var ne: CLLocationCoordinate2D { return CLLocationCoordinate2D(latitude: self.center.latitude + self.span.latitudeDelta / 2, longitude: self.center.longitude + self.span.longitudeDelta / 2 ) }
    var sw: CLLocationCoordinate2D { return CLLocationCoordinate2D(latitude: self.center.latitude - self.span.latitudeDelta / 2, longitude: self.center.longitude - self.span.longitudeDelta / 2 ) }
    var se: CLLocationCoordinate2D { return CLLocationCoordinate2D(latitude: self.center.latitude - self.span.latitudeDelta / 2, longitude: self.center.longitude + self.span.longitudeDelta / 2 ) }

    var polygon: MKPolygon {
        var coords = [self.nw, self.ne, self.se, self.sw]
        return MKPolygon(coordinates: &coords, count: 4)
    }

    init?(coordinates: [CLLocationCoordinate2D]) {

        let latitudes = coordinates.map { $0.latitude }
        let longitudes = coordinates.map { $0.longitude }

        guard let minLat = latitudes.min(),
            let maxLat = latitudes.max(),
            let minLon = longitudes.min(),
            let maxLon = longitudes.max() else {
                return nil
        }

        self.center = CLLocationCoordinate2D(latitude: (minLat + maxLat) / 2, longitude: (minLon + maxLon) / 2)
        self.span = MKCoordinateSpan(latitudeDelta: (maxLat - minLat), longitudeDelta: (maxLon - minLon))
    }
}
