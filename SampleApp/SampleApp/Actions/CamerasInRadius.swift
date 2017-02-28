///
/// :header: CamerasInRadius.swift
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

class CamerasInRadius: SampleAction {
    required init () {}
    static let description = "Returns cameras found in the radius arround a coordinate."
    static let category = CategoryConstants.cameras

    static let defaults: [String : ParamValue] = [ParameterConstants.radius : CommonConstants.radiusSpaceNeedle,
                                                  ParameterConstants.shouldExcludeOutOfServiceCameras : false]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let radius = values[ParameterConstants.radius] as? MKCircle,
            let shouldExcludeOutOfServiceCameras = values[ParameterConstants.shouldExcludeOutOfServiceCameras] as? Bool else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLCamerasInRadiusOptions(radius: Float(radius.radius / IXCLMetersPerMile), center: radius.coordinate)
        options?.shouldExcludeOutOfServiceCameras = shouldExcludeOutOfServiceCameras

        core.camerasController.requestCamerasInRadius(with: options) {
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
