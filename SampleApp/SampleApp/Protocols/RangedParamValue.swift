///
/// :header: RangedParamValue.swift
///
/// :author: Patrick Winchell
/// :created: 02-24-2017
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

/// Protocol for ranged parameters.
struct RangedParamValue<Element : ParamValue & FloatConvertable> : ParamValue {
    func toString() -> String {
        return self.value.toString()
    }

    let value: Element
    let range: Range<Element>

    func updateWith(newValue: Element) -> RangedParamValue<Element> {
        return RangedParamValue(value: newValue, range: self.range)
    }

    func updateWith(newValue: Float) -> RangedParamValue<Element> {
        return RangedParamValue(value: Element.init(newValue), range: self.range)
    }
}

extension RangedParamValue : ParamValueWithDetailView {
    func createDetailView(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIView {
        let thisView = UISliderWithBlock(param: self, changeHandler: changeHandler)
        return thisView
    }
}

/// Protocol for values that can be converted to and from floats.
protocol FloatConvertable: Comparable {
    init(_ v: Float)
    var floatValue: Float { get }
}

extension Double : FloatConvertable {
    var floatValue: Float { return Float(self) }
}

extension Float : FloatConvertable {
    var floatValue: Float { return self }
}

extension CGFloat : FloatConvertable {
    var floatValue: Float { return Float(self) }
}

extension Int : FloatConvertable {
    var floatValue: Float { return Float(self) }
}

extension UInt : FloatConvertable {
    var floatValue: Float { return Float(self) }
}
