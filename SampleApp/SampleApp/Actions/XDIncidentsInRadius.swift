///
/// :header: IncidentsInRadius.swift
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

class XDIncidentsInRadius: SampleAction {
    required init () {}
    static let description = "Returns incidents found in the radius arround a coordinate."
    static let category = CategoryConstants.incidents

    static let defaults: [String : ParamValue] = [ParameterConstants.radius : CommonConstants.radiusSeattle,
                                                  ParameterConstants.incidentsFilter : IXCLIncidentsFilter.includeAll]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let radius = values[ParameterConstants.radius] as? MKCircle,
            let filter = values[ParameterConstants.incidentsFilter] as? IXCLIncidentsFilter else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLXDIncidentsInRadiusOptions(center: radius.coordinate, radius: radius.radius / 1000)
        options?.distanceUnits = .meters

        core.incidentsController.requestXDIncidentsInRadius(with: options, incidentsFilter: filter) {
            (incidents: [Any]?, response: IXCLCoreResponse?) in

            if let error = response?.error as? NSError {
                completionHandler(nil, error, false)
            } else if let incidents = incidents {
                let mappedIncidents = incidents.flatMap({ $0 as? IXCLXDIncident })

                let resultText = mappedIncidents.description

                let viewControllers = [MapAnnotationResultsViewController(annotations: mappedIncidents),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
