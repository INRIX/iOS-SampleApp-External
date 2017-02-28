///
/// :header: IncidentsInBox.swift
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

class IncidentsInBox: SampleAction {
    required init () {}
    static let description = "Returns incidents found in the area between two coordinates."
    static let category = CategoryConstants.incidents

    static let defaults: [String : ParamValue] = [ParameterConstants.region : CommonConstants.boxSeattle,
                                                  ParameterConstants.incidentsFilter : IXCLIncidentsFilter.includeAll]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let region = values[ParameterConstants.region] as? MKCoordinateRegion,
            let filter = values[ParameterConstants.incidentsFilter] as? IXCLIncidentsFilter else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLIncidentsInBoxOptions(corner1: region.sw, corner2: region.ne)

        core.incidentsController.requestIncidentsInBox(with: options, incidentsFilter: filter) {
            (incidents: [Any]?, response: IXCLCoreResponse?) in
            if let incidents = incidents {

                let mappedIncidents = incidents.flatMap({ $0 as? IXCLIncident })

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
