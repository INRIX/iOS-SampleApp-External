///
/// :header: CommonConstants.swift
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
import UIKit

struct CommonConstants {

    static let coordinateSpaceNeedle = CLLocationCoordinate2D(latitude: 47.6205, longitude: -122.3493)
    static let coordinateInrix =  CLLocationCoordinate2D(latitude: 47.6436, longitude: -122.2037)

    static let boxGreaterSeattle = MKCoordinateRegion(center: CommonConstants.coordinateSpaceNeedle,
                                                        span: MKCoordinateSpan(latitudeDelta: 0.75, longitudeDelta: 0.75))
    static let radiusGreaterSeattle = MKCircle(center: CommonConstants.coordinateSpaceNeedle, radius: 25000)

    static let boxSeattle = MKCoordinateRegion(center: CommonConstants.coordinateSpaceNeedle,
                                                   span: MKCoordinateSpan(latitudeDelta: 0.1, longitudeDelta: 0.1))
    static let radiusSeattle = MKCircle(center: CommonConstants.coordinateSpaceNeedle, radius: 5000)

    static let boxSpaceNeedle = MKCoordinateRegion(center: CommonConstants.coordinateSpaceNeedle,
                                                     span: MKCoordinateSpan(latitudeDelta: 0.02, longitudeDelta: 0.02))
    static let boxSpaceNeedleSmall = MKCoordinateRegion(center: CommonConstants.coordinateSpaceNeedle,
                                                          span: MKCoordinateSpan(latitudeDelta: 0.01, longitudeDelta: 0.01))

    static let radiusSpaceNeedle = MKCircle(center: CommonConstants.coordinateSpaceNeedle, radius: 1000)
    static let radiusSpaceNeedleSmall = MKCircle(center: CommonConstants.coordinateSpaceNeedle, radius: 250)

    static let quadkeyDowntownSeattle = Quadkey(coordinate: CLLocationCoordinate2D(latitude: 47.6205, longitude: -122.32), zoomLevel: 12)
}

struct ParameterConstants {

    static let end = "end"

    static let frcMask = "frcMask"

    static let incidentsFilter = "incidentsFilter"

    static let opacity = "opacity"
    static let outputFieldMask = "outputFieldMask"
    static let overrideMaxDistance = "overrideMaxDistance"

    static let parkingType = "parkingType"
    static let penWidth = "penWidth"
    static let productTypeMask = "productTypeMask"

    static let quadkey = "quadkey"

    static let radius = "radius"
    static let region = "region"

    static let shouldExcludeOutOfServiceCameras = "shouldExcludeOutOfServiceCameras"
    static let start = "start"
}

struct CategoryConstants {
    static let auth = "Auth"
    static let routes = "Routes"
    static let cameras = "Cameras"
    static let dangerousSlowdowns = "DangerousSlowdowns"
    static let gasStations = "GasStations"
    static let incidents = "Incidents"
    static let parking = "Parking"
    static let trafficTiles = "TrafficTiles"
    static let test = "test"
}
