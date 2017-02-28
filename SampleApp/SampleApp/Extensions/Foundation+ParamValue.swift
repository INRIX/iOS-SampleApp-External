///
/// :header: Foundation+ParamValue.swift
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

extension String : ParamValue {
    func toString() -> String {
        return self
    }
}

extension Int : ParamValue {
    func toString() -> String {
        return String(self)
    }
}

extension UInt : ParamValue {
    func toString() -> String {
        return String(self)
    }
}

extension Float : ParamValue {
    func toString() -> String {
        return String(self)
    }
}

extension Double : ParamValue {
    func toString() -> String {
        return String(self)
    }
}

extension Bool : ParamValueWithAccessoryView {
    func toString() -> String {
        return String(self)
    }

    func createAccessoryView(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIView {
        let thisSwitch = UISwitchWithBlock(changeHandler: changeHandler)
        thisSwitch.isOn = self
        return thisSwitch
    }
}
