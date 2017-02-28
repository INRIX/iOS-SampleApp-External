///
/// :header: UISwitchWithBlock.swift
///
/// :author: Patrick Winchell
/// :created: 08-31-2016
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

open class UISwitchWithBlock: UISwitch {

    let changeHandler: (_ newValue: Bool) -> Void

    init(changeHandler: @escaping (_ newValue: Bool) -> Void) {
        self.changeHandler = changeHandler
        super.init(frame: CGRect.zero)
        self.addTarget(self, action: #selector(UISwitchWithBlock.didChange(_:)), for: .valueChanged)
    }

    required public init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    func didChange(_ thisSwitch: UISwitch) {
        self.changeHandler(thisSwitch.isOn)
    }
}
