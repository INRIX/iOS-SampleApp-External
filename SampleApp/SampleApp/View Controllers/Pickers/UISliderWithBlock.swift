///
/// :header: UISliderWithBlock.swift
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

class UISliderWithBlock<Element: FloatConvertable & ParamValue>: UISlider {

    var param: RangedParamValue<Element> {
        didSet {
            self.changeHandler(self.param)
        }
    }

    let changeHandler: (_ newValue: RangedParamValue<Element>) -> Void

    init(param: RangedParamValue<Element>, changeHandler: @escaping (_ newValue: RangedParamValue<Element>) -> Void) {
        self.param = param
        self.changeHandler = changeHandler
        super.init(frame: CGRect.zero)
        self.minimumValue = param.range.lowerBound.floatValue
        self.maximumValue = param.range.upperBound.floatValue
        self.value = param.value.floatValue
        self.addTarget(self, action: #selector(UISliderWithBlock.didChange(_:)), for: .valueChanged)
    }

    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func didChange(_ thisSwitch: UISlider) {
        self.param = self.param.updateWith(newValue: thisSwitch.value)
    }
}
