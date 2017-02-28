///
/// :header: DangerousSlowdownsInBox.swift
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

class DangerousSlowdownsInBox: SampleAction {
    required init () {}
    static let description = "Returns dangerous slowdowns found in the area between two coordinates."
    static let category = CategoryConstants.dangerousSlowdowns

    static let defaults: [String : ParamValue] = [ParameterConstants.region : CommonConstants.boxGreaterSeattle]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let region = values[ParameterConstants.region] as? MKCoordinateRegion else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLDangerousSlowdownsInBoxOptions(corner1: region.nw, corner2: region.se)
        options?.distanceUnits = .kilometers

        core.dangerousSlowdownsController.requestDangerousSlowdowns(inBox: options) {
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
