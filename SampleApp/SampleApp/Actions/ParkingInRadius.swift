///
/// :header: ParkingInRadius.swift
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

class ParkingInRadius: SampleAction {
    required init () {}
    static let description = "Returns parking found in the radius arround a coordinate."
    static let category = CategoryConstants.parking

    static let defaults: [String : ParamValue] = [ParameterConstants.radius : CommonConstants.radiusSpaceNeedleSmall,
                                                  ParameterConstants.parkingType : IXCLParkingLotOptionsParkingType.all]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let radius = values[ParameterConstants.radius] as? MKCircle,
            let parkingType = values[ParameterConstants.parkingType] as? IXCLParkingLotOptionsParkingType else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLParkingLotsInRadiusOptions(center: radius.coordinate, radius: radius.radius)
        options?.outputField = IXCLParkingLotOptionsOutputField.all
        options?.unitsType = .meters
        options?.parkingType = parkingType

        core.parkingLotsController.requestParkingLotsInRadius(with: options) { (parking: [Any]?, response: IXCLCoreResponse?) in
            if let error = response?.error {
                completionHandler(nil, (error as NSError), false)
            } else if let parking = parking {
                let mappedParking = parking.flatMap({ $0 as? IXCLParkingObjectProtocol })

                let resultText = mappedParking.description
                let annotations = mappedParking.flatMap({ $0 as? MKAnnotation})

                let viewControllers = [MapAnnotationResultsViewController(annotations: annotations),
                                       StringResultsController(text: resultText)]

                completionHandler(ResultsTabBarController(viewControllers: viewControllers), nil, true)
            } else {
                completionHandler(nil, nil, false)
            }
        }
    }
}
