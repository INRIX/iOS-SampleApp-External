///
/// :header: DangerousSlowdownsRadius.swift
///
/// :author: Patrick Winchell
/// :created: 02-28-2017
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

class DangerousSlowdownsRadius: SampleAction {
    required init () {}
    static let description = "Returns dangerous slowdowns found in the radius arround a coordinate."
    static let category = CategoryConstants.dangerousSlowdowns

    static let defaults: [String : ParamValue] = [ParameterConstants.radius : CommonConstants.radiusGreaterSeattle]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let radius = values[ParameterConstants.radius] as? MKCircle else {
            completionHandler(nil, nil, false)
            return
        }

        let options = IXCLDangerousSlowdownsInRadiusOptions(center: radius.coordinate, radius: radius.radius / 1000)
        options?.distanceUnits = .kilometers

        core.dangerousSlowdownsController.requestDangerousSlowdowns(inRadius: options) {
            (slowdowns: [Any]?, response: IXCLCoreResponse?) in
            if let slowdowns = slowdowns {

                let mappedSlowdowns = slowdowns.flatMap({ $0 as? IXCLDangerousSlowdown })

                let resultText = mappedSlowdowns.description

                let viewControllers = [MapAnnotationResultsViewController(annotations: mappedSlowdowns),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
