///
/// :header: GasStationsInBox.swift
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

class GasStationsInBox: SampleAction {
    required init () {}
    static let description = "Returns gas stations found in the area between two coordinates."
    static let category = CategoryConstants.gasStations

    static let defaults: [String : ParamValue] = [ParameterConstants.region : CommonConstants.boxSpaceNeedle,
                                                  ParameterConstants.outputFieldMask : IXCLGasStationOptionsOutputFieldMask.maskAll,
                                                  ParameterConstants.productTypeMask : IXCLGasStationProductTypeMask.maskAll]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let region = values[ParameterConstants.region] as? MKCoordinateRegion,
            let outputFieldMask = values[ParameterConstants.outputFieldMask] as? IXCLGasStationOptionsOutputFieldMask,
            let productTypeMask = values[ParameterConstants.productTypeMask] as? IXCLGasStationProductTypeMask else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLGasStationsInBoxOptions(corner1: region.sw, corner2: region.ne)
        options?.outputFieldMask = outputFieldMask
        options?.productTypeMask = productTypeMask

        core.gasStationsController.requestGasStationsInBox(with: options) {
            (gasStations: [Any]?, response: IXCLCoreResponse?) in
            if let gasStations = gasStations {

                let mappedGasStations = gasStations.flatMap({ $0 as? IXCLGasStation })

                let resultText = mappedGasStations.description

                let viewControllers = [MapAnnotationResultsViewController(annotations: mappedGasStations),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
