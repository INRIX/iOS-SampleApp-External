///
/// :header: TrafficTile.swift
///
/// :author: Patrick Winchell
/// :created: 02-22-2016
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

class TrafficTiles: SampleAction {
    required init () {}
    static let description = "Returns incidents found in the area between two coordinates."
    static let category = CategoryConstants.trafficTiles

    static let defaults: [String : ParamValue] = [ParameterConstants.quadkey : CommonConstants.quadkeyDowntownSeattle,
                                                  ParameterConstants.penWidth : RangedParamValue<UInt>(value: 1, range: Range(uncheckedBounds: (lower: 1, upper: 16))),
                                                  ParameterConstants.opacity : RangedParamValue<UInt>(value: 90, range: Range(uncheckedBounds: (lower: 1, upper: 100))),
                                                  ParameterConstants.frcMask : IXCLTrafficTileOptionsFRCLevelMask.maskAll]

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        guard let quadkey = values[ParameterConstants.quadkey] as? Quadkey,
            let penWidth = (values[ParameterConstants.penWidth] as? RangedParamValue<UInt>)?.value,
            let opacity = (values[ParameterConstants.opacity] as? RangedParamValue<UInt>)?.value,
            let frcMask = values[ParameterConstants.frcMask] as? IXCLTrafficTileOptionsFRCLevelMask else {
                completionHandler(nil, nil, false)
                return
        }

        let options = IXCLTrafficTileOptions()
        options.quadkey = quadkey.toString()
        options.penWidth = penWidth
        options.opacity = opacity
        options.frcLevelMask = frcMask
        options.useCache = false

        core.trafficTilesController.requestTrafficTile(with: options) {
            (image: UIImage?, response: IXCLCoreResponse?) in

            if let error = response?.error as? NSError {
                completionHandler(nil, error, false)
            } else {
                completionHandler(ImageResultsController(image: image), response?.error, image != nil)
            }
        }
    }
}
