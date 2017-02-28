///
/// :header: CamerasInBox.swift
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

class CamerasInBox: SampleAction {
    required init () {}
    static let description = "Returns cameras found in the area between two coordinates."
    static let category = CategoryConstants.cameras

    static let defaults: [String : ParamValue] = [ParameterConstants.region : CommonConstants.boxSpaceNeedle,
                                                  ParameterConstants.shouldExcludeOutOfServiceCameras : false]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let region = values[ParameterConstants.region] as? MKCoordinateRegion,
            let shouldExcludeOutOfServiceCameras = values[ParameterConstants.shouldExcludeOutOfServiceCameras] as? Bool else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLCamerasInBoxOptions(corner1: region.sw, corner2: region.ne)
        options?.shouldExcludeOutOfServiceCameras = shouldExcludeOutOfServiceCameras

        core.camerasController.requestCamerasInBox(with: options) {
            (cameras: [Any]?, response: IXCLCoreResponse?) in
            if let cameras = cameras {

                let mappedCameras = cameras.flatMap({ $0 as? IXCLServerCamera })

                let resultText = mappedCameras.description

                let viewControllers = [MapAnnotationResultsViewController(annotations: mappedCameras),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
