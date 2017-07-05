///
/// :header: FindRoute.swift
///
/// :author: Patrick Winchell
/// :created: 09-02-2016
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

class FindRoute: SampleAction {
    required init () {}
    static let description = "Finds a route between two coordinates."
    static let category = CategoryConstants.routes

    static let defaults: [String : ParamValue] = [ParameterConstants.start : CommonConstants.coordinateSpaceNeedle,
                                                  ParameterConstants.end : CommonConstants.coordinateInrix,
                                                  ParameterConstants.overrideMaxDistance : false]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let start = values[ParameterConstants.start] as? CLLocationCoordinate2D,
            let end = values[ParameterConstants.end] as? CLLocationCoordinate2D,
            let overrideMaxDistance = values[ParameterConstants.overrideMaxDistance] as? Bool else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLRoutesFromPointsOptions(startPoint: CLLocation(latitude: start.latitude, longitude: start.longitude), endPoint: end)
        options?.routeOutputFieldsMask = .fieldMaskAll
        options?.overrideMaxDistance = overrideMaxDistance
        options?.maxAlternates = 1

        core.routesController.requestRoutes(with: options) { (routesResponse: IXCLRoutesResponse?) in
            if let error = routesResponse?.error {
                completionHandler(nil, (error as NSError), false)
            } else if let routesCollection = routesResponse?.routesCollection,
            let routes = routesCollection.routes, routes.count > 0 {
                let mappedRoutes = routes.flatMap({ $0 as? IXCLRoute })
                let resultText = mappedRoutes.description

                let viewControllers = [MapAnnotationResultsViewController(overlays: mappedRoutes),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
