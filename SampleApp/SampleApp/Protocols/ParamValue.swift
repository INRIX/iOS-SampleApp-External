///
/// :header: ParamValue.swift
///
/// :author: Patrick Winchell
/// :created: 08-30-2016
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

/// Protocol for parameters.
protocol ParamValue {
    func toString() -> String
}

/// Protocol for parameters that provide an accessoryView for editing.
protocol ParamValueWithAccessoryView: ParamValue {
    func createAccessoryView(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIView
}

/// Protocol for parameters that provide an accessoryView for editing.
protocol ParamValueWithDetailView: ParamValue {
    func createDetailView(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIView
}

/// Protocol for parameters that provide a pushable view controller for editing.
protocol ParamValueWithPushablePicker: ParamValue {
    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController
}

/// Protocol for parameters that provide a presentable self-dismissing view controller for editing.
protocol ParamValueWithPresentablePicker: ParamValue {
    func createPresentablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController
}

/// Converts an object into a collection of parameters.
func objectToParameters(_ obj: Any) -> (keys: [String], dict: [String : ParamValue]) {
    var keys = [String]()
    var values = [String : ParamValue]()
    let mirror = Mirror(reflecting: obj)
    for child in mirror.children {
        if let label = child.label,
            let value = child.value as? ParamValue {
            keys.append(label)
            values[label] = value
            print("\(label): \(value)")
        }
    }
    return (keys: keys, dict: values)
}
