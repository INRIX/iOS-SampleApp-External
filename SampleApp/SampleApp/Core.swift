///
/// :header: Core.swift
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

class ApplicationCore {
    static let sharedInstance = ApplicationCore()

    static let appVersion: String     = (Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String) ?? "NoAppVersion"
    static let appBuildNumber: String = (Bundle.main.infoDictionary?["CFBundleVersion"] as? String) ?? "NoAppBuild"

    lazy var inrixCore: InrixCore = {
        return ApplicationCore.createCore()
    }()

    lazy var samples: [SampleAction.Type] = ApplicationCore.getActionClasses()

    /// Filter samples by category.
    func samplesForCategory(_ category: String) -> [SampleAction.Type] {
        if category.isEmpty == false {
            let filteredSamples = samples.filter({ $0.category.lowercased().hasPrefix(category.lowercased())})
            return ApplicationCore.sortSampleActions(filteredSamples) // These should already be sorted, but just in case.
        }
        return self.samples
    }

    /// Creates an inrix core with the app's key and id.
    class func createCore() -> InrixCore {
        let coreOptions: IXCLCoreOptions = IXCLCoreOptions(
            applicationId: KeysAndSettings.applicationId,
            applicationKey: KeysAndSettings.applicationKey,
            applicationName: "test",
            applicationVersion: "\(self.appVersion).\(self.appBuildNumber)")

        coreOptions.backgroundLocationUpdates = false
        coreOptions.userLocationUpdatesEnabled = false
        coreOptions.calendarSyncingEnabled = false
        coreOptions.tripRecordingEnabled = false

        let inrixCore = IXCLCreateInrixCore(coreOptions)

        return inrixCore!
    }

    /// Returns all SampleAction classes that exist in the app.
    class func getActionClasses() -> [SampleAction.Type] {
        var classes = [SampleAction.Type]()
        let numClasses = objc_getClassList(nil, 0)
        if numClasses > 0 {
            let allClasses = UnsafeMutablePointer<AnyClass?>.allocate(capacity: Int(numClasses))
            let autoreleasingAllClasses = AutoreleasingUnsafeMutablePointer<AnyClass?>(allClasses)
            let actualClassCount: Int32 = objc_getClassList(autoreleasingAllClasses, numClasses)

            for i in 0 ..< actualClassCount {
                if let currentClass: AnyClass = allClasses[Int(i)] {
                    if let protocolClass = currentClass as? SampleAction.Type {
                        classes.append(protocolClass)
                    }
                }
            }
        }
        return self.sortSampleActions(classes)
    }

    /// Returns a sorted array of sample actions.
    class func sortSampleActions(_ samples: [SampleAction.Type]) -> [SampleAction.Type] {
        let stringFoldingOptions: NSString.CompareOptions = NSString.CompareOptions([.caseInsensitive, .diacriticInsensitive])
        return samples.sorted(by: {
            let comparisonResult = $0.0.category.compare($0.1.category, options: stringFoldingOptions)
            if comparisonResult == .orderedAscending {
                return true
            }
            if comparisonResult == .orderedSame {
                return $0.0.name.compare($0.1.name, options: stringFoldingOptions) == .orderedAscending
            }
            return false
        })
    }
}
