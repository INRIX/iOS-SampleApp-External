///
/// :header: MapKit+ParamValue.swift
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

extension MKCircle: ParamValueWithPushablePicker {

    func toString() -> String {
        return String(format: "%.0fm @ %.2f, %.2f", self.radius, self.coordinate.latitude, self.coordinate.longitude)
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {
        return MapRadiusPickerViewController(radius: self, changeHandler: changeHandler)
    }
}

/// CLLocationCoordinate2D creates a MapPicker for edits.
extension CLLocationCoordinate2D : ParamValueWithPushablePicker {
    func toString() -> String {
        return String(format: "%.4f, %.4f", self.latitude, self.longitude)
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {
        return MapPickerViewController(coordinate: self, changeHandler: changeHandler)
    }

}

extension MKCoordinateRegion : ParamValueWithPushablePicker {
    func toString() -> String {
        return self.center.toString()
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {
        return MapRegionPickerViewController(region: self, changeHandler: changeHandler)
    }
}
