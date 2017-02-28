///
/// :header: SampleAction.swift
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

/// Completion handler for all SampleActions.
typealias ActionCompletionHandler =  (_ resultsController: UIViewController?, _ error: Error?, _ success: Bool) -> Void

/// Base protocol of a sample action.
protocol SampleAction : class {

    /// Init is required to be a SampleAction.
    init()

    /// Name presented on title and selection screens.
    static var name: String { get }

    /// Description of what is expected by this SampleAction.
    static var description: String { get }

    /// Category, should be a period delimited list: 'requests.incidents'
    static var category: String { get }

    /// Default values for the SampleAction.
    static var defaults: [String : ParamValue] { get }

    /// Custom view controller for the SampleAction.
    static func customViewController(core: InrixCore) -> UIViewController?

    /// Is testable by automated tested.
    static var isTestable: Bool { get }

    /// Standard Action
    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler)
}

extension SampleAction {
    func verifyValuesAndPerformAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard self.verifyValues(values) else {
            completionHandler(nil, nil, false)
            return
        }
        self.performAction(core: core, values: values, completionHandler: completionHandler)
    }

    /// Verifies that all values are the type that was specified by the default object.
    func verifyValues(_ values: [String : ParamValue] ) -> Bool {
        let defaults = Self.defaults

        for (key, value) in defaults {
            if let newValue = values[key] {
                if type(of: newValue) != type(of: value) {
                    print("\(type(of: newValue)) instead of \(type(of: value)) for key \(key)")
                    return false
                }
            } else {
                return false
            }
        }
        return true
    }
}

/// Provide defaults
extension SampleAction {

    static var name: String {
        return String(describing: self).unCamelCaseString()
    }

    static var description: String { return "No description given." }
    static var category: String { return "" }
    static var displayName: String { return self.name }
    static var defaults: [String : ParamValue] { return [ : ] }
    static func customViewController(core: InrixCore) -> UIViewController? {
        return nil
    }
    static var isTestable: Bool { return true }

    /// Default testing action.
    func performAction(core: InrixCore, completionHandler: @escaping ActionCompletionHandler) {
        self.verifyValuesAndPerformAction(core: core, values: Self.defaults, completionHandler: completionHandler)
    }
}
