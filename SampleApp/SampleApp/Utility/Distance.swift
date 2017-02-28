///
/// :header: Distance.swift
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

/// Struct for distances, creates a UIPickerview for edits.
struct Distance: ParamValueWithPresentablePicker {
    var value: Double
    var metric: Bool

    var metricValue: CLLocationDistance {
        if self.metric == false {
            return value * 1609.34
        }
        return value
    }

    var KMValue: Double {
        return self.metricValue / 1000
    }

    var mileValue: Double {
        return self.metricValue / 1609.34
    }

    func toString() -> String {
        let formatter = MKDistanceFormatter()
        formatter.units = self.metric ? .metric : .imperial
        return formatter.string(fromDistance: metricValue)
    }

    func createPresentablePicker(_ changeHandler: @escaping (_ newValue: ParamValue) -> Void) -> UIViewController {

        let distanceOptions: [UIPickerOption] = [(name: "0.5", value: 0.5),
                                                 (name: "1", value: 1.0),
                                                 (name: "5", value: 5.0),
                                                 (name: "10", value: 10.0),
                                                 (name: "100", value: 100.0),
                                                 (name: "500", value: 500.0),
                                                 (name: "1000", value: 1000.0),
                                                 (name: "5000", value: 5000.0)]

        let unitOptions: [UIPickerOption] = [(name: "Meters", value: true),
                                             (name: "Miles", value: false)]

        let picker = UIPickerViewController(options: [distanceOptions, unitOptions], values: [self.value, self.metric]) {
            values in
            if let value = values[0] as? Double,
                let metric = values[1] as? Bool {
                changeHandler(Distance(value: value, metric: metric))
            }
        }

        return picker
    }
}
