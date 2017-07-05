///
/// :header: IXCL+ParamValue.swift
///
/// :author: Patrick Winchell
/// :created: 02-23-2017
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

/// Extension for Incident filter selection.
extension IXCLIncidentsFilter : ParamValueWithPushablePicker {
    func toString() -> String {
        switch self {
        case IXCLIncidentsFilter.includeAll:
            return "All"
        case IXCLIncidentsFilter.includeAccident:
            return "Accident"
        case IXCLIncidentsFilter.includeCongestion:
            return "Congestion"
        case IXCLIncidentsFilter.includeConstruction:
            return "Construction"
        case IXCLIncidentsFilter.includeEvent:
            return "Event"
        case IXCLIncidentsFilter.includePolice:
            return "Police"
        case IXCLIncidentsFilter.includeHazard:
            return "Hazard"
        case IXCLIncidentsFilter.includeRoadClosure:
            return "Road Closure"
        case IXCLIncidentsFilter.includeLaneClosure:
            return "Lane Closure"
        case IXCLIncidentsFilter():
            return "None"
        default:
            return "Some"
        }
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let options: [IXCLIncidentsFilter] = [.includeAccident,
                                              .includeCongestion,
                                              .includeConstruction,
                                              .includeEvent,
                                              .includePolice,
                                              .includeHazard,
                                              .includeRoadClosure,
                                              .includeLaneClosure]

        let optionPickerOptions = options.map({ OptionPickerOption(name: $0.toString(), option: $0, value: self.contains($0)) })

        let picker =  OptionsPickerViewController<IXCLIncidentsFilter>(options: optionPickerOptions) {
            (newValues: [IXCLIncidentsFilter]) in
            let newValue = IXCLIncidentsFilter(newValues)
            changeHandler(newValue)
        }
        return picker
    }
}

/// Extension for parking type selection.
extension IXCLParkingLotOptionsParkingType: ParamValueWithPresentablePicker {

    func toString() -> String {
        switch self {
        case IXCLParkingLotOptionsParkingType.all:
            return "All"
        case IXCLParkingLotOptionsParkingType.parkingLots:
            return "Lots"
        case IXCLParkingLotOptionsParkingType.parkingBlocks:
            return "Blocks"
        default:
            return "Unknown"
        }
    }

    func createPresentablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let options: [UIPickerOption] = [(name: "All", value: IXCLParkingLotOptionsParkingType.all),
                                         (name: "Lots", value: IXCLParkingLotOptionsParkingType.parkingLots),
                                         (name: "Blocks", value: IXCLParkingLotOptionsParkingType.parkingBlocks)]

        let picker = UIPickerViewController(options: [options], values: [self]) {
            values in
            if let value = values.first as? IXCLParkingLotOptionsParkingType {
                changeHandler(value)
            }
        }
        return picker
    }
}

/// Extension for FRC mask selection.
extension IXCLTrafficTileOptionsFRCLevelMask : ParamValueWithPushablePicker {
    func toString() -> String {
        switch self {
        case IXCLTrafficTileOptionsFRCLevelMask.maskAll:
            return "All"
        case IXCLTrafficTileOptionsFRCLevelMask(rawValue: 0):
            return "None"
        case IXCLTrafficTileOptionsFRCLevelMask.mask1:
            return "FRC Level 1"
        case IXCLTrafficTileOptionsFRCLevelMask.mask2:
            return "FRC Level 2"
        case IXCLTrafficTileOptionsFRCLevelMask.mask3:
            return "FRC Level 3"
        case IXCLTrafficTileOptionsFRCLevelMask.mask4:
            return "FRC Level 4"
        case IXCLTrafficTileOptionsFRCLevelMask.mask5:
            return "FRC Level 5"
        case IXCLTrafficTileOptionsFRCLevelMask.mask6:
            return "FRC Level 6"
        case IXCLTrafficTileOptionsFRCLevelMask.mask7:
            return "FRC Level 7"
        default:
            break
        }
        return "Some"
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let options: [IXCLTrafficTileOptionsFRCLevelMask] = [.mask1,
                                                               .mask2,
                                                               .mask3,
                                                               .mask4,
                                                               .mask5,
                                                               .mask6,
                                                               .mask7]

        let optionPickerOptions = options.map({ OptionPickerOption(name: $0.toString(), option: $0, value: self.contains($0)) })

        let picker =  OptionsPickerViewController<IXCLTrafficTileOptionsFRCLevelMask>(options: optionPickerOptions) {
            (newValues: [IXCLTrafficTileOptionsFRCLevelMask]) in
            let newValue = IXCLTrafficTileOptionsFRCLevelMask(newValues)
            changeHandler(newValue)
        }
        return picker
    }
}

extension IXCLGasStationOptionsOutputFieldMask : ParamValueWithPushablePicker {
    func toString() -> String {
        switch self {
        case IXCLGasStationOptionsOutputFieldMask.maskAll:
            return "All"
        case IXCLGasStationOptionsOutputFieldMask.maskBrand:
            return "Brand"
        case IXCLGasStationOptionsOutputFieldMask.maskLocation:
            return "Location"
        case IXCLGasStationOptionsOutputFieldMask.maskAddress:
            return "Address"
        case IXCLGasStationOptionsOutputFieldMask.maskProducts:
            return "Products"
        case IXCLGasStationOptionsOutputFieldMask.maskCurrencyCode:
            return "Currency Code"
        default:
            break
        }
        return "Some"
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let options: [IXCLGasStationOptionsOutputFieldMask] = [.maskBrand,
                                                               .maskLocation,
                                                               .maskAddress,
                                                               .maskProducts,
                                                               .maskCurrencyCode]

        let optionPickerOptions = options.map({ OptionPickerOption(name: $0.toString(), option: $0, value: self.contains($0)) })

        let picker =  OptionsPickerViewController<IXCLGasStationOptionsOutputFieldMask>(options: optionPickerOptions) {
            (newValues: [IXCLGasStationOptionsOutputFieldMask]) in
            let newValue = IXCLGasStationOptionsOutputFieldMask(newValues)
            changeHandler(newValue)
        }
        return picker
    }
}

extension IXCLGasStationProductTypeMask : ParamValueWithPushablePicker {
    func toString() -> String {
        switch self {
        case IXCLGasStationProductTypeMask.maskBiodiesel:
        return "Biodiesel"
        case IXCLGasStationProductTypeMask.maskDiesel:
            return "Diesel"
        case IXCLGasStationProductTypeMask.maskDieselPlus:
            return "Diesel Plus"
        case IXCLGasStationProductTypeMask.maskDieselTruck:
            return "Diesel Truck"
        case IXCLGasStationProductTypeMask.maskLPG:
            return "LPG"
        case IXCLGasStationProductTypeMask.maskMethane:
            return "Methane"
        case IXCLGasStationProductTypeMask.maskGasolineRegular:
            return "Gasoline Regular"
        case IXCLGasStationProductTypeMask.maskGasolineMidgrade:
            return "Gasoline Midgrade"
        case IXCLGasStationProductTypeMask.maskGasolinePremium:
            return "Gasoline Premium"
        case IXCLGasStationProductTypeMask.maskGasolineE85:
            return "Gasoline E85"
        case IXCLGasStationProductTypeMask.maskGasolineNormal:
            return "Gasoline Normal"
        case IXCLGasStationProductTypeMask.maskGasolineSP92:
            return "Gasoline SP92"
        case IXCLGasStationProductTypeMask.maskGasolineSP95:
            return "Gasoline SP95"
        case IXCLGasStationProductTypeMask.maskGasolineSP95_E10:
            return "Gasoline SP95 E10"
        case IXCLGasStationProductTypeMask.maskGasolineSP98:
            return "Gasoline SP9"
        case IXCLGasStationProductTypeMask.maskAll:
            return "All"
        default:
            break
        }
        return "Some"
    }

    func createPushablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let options: [IXCLGasStationProductTypeMask] = [.maskBiodiesel,
                                                        .maskDiesel,
                                                        .maskDieselPlus,
                                                        .maskDieselTruck,
                                                        .maskLPG,
                                                        .maskMethane,
                                                        .maskGasolineRegular,
                                                        .maskGasolineMidgrade,
                                                        .maskGasolinePremium,
                                                        .maskGasolineE85,
                                                        .maskGasolineNormal,
                                                        .maskGasolineSP92,
                                                        .maskGasolineSP95,
                                                        .maskGasolineSP95_E10,
                                                        .maskGasolineSP98]

        let optionPickerOptions = options.map({ OptionPickerOption(name: $0.toString(), option: $0, value: self.contains($0)) })

        let picker =  OptionsPickerViewController<IXCLGasStationProductTypeMask>(options: optionPickerOptions) {
            (newValues: [IXCLGasStationProductTypeMask]) in
            let newValue = IXCLGasStationProductTypeMask(newValues)
            changeHandler(newValue)
        }
        return picker
    }
}
