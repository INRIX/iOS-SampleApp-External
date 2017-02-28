///
/// :header: AboutViewController.swift
///
/// :author: Jeffrey White
/// :created: 08-31-2016
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

class AboutViewController: UIViewController {

    @IBOutlet weak var buildVersionLabel: UILabel!
    @IBOutlet weak var copyrightLabel: UILabel!
    @IBOutlet weak var userIdLabel: UILabel!

    var buildVersion: String {
            let infoDictionary: [AnyHashable: Any]? = Bundle.main.infoDictionary
            let name = (infoDictionary?["CFBundleName"] as? String) ?? "NoAppName"
            let version = (infoDictionary?["CFBundleShortVersionString"] as? String) ?? "NoAppVersion"
            let build = (infoDictionary?["CFBundleVersion"] as? String) ?? "NoAppBuild"

            return "\(name), Version \(version) (\(build))"
    }

    class func create() -> AboutViewController? {
        let storyBoard = UIStoryboard(name: "Settings", bundle: nil)
        if let viewController = storyBoard.instantiateViewController(withIdentifier: "AboutViewController") as? AboutViewController {
            return viewController
        }
        return nil
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.navigationItem.title = "About"
        self.buildVersionLabel.text = self.buildVersion
        self.copyrightLabel.text = "Copyright \u{00A9} 2008-2016 INRIX Inc. All rights reserved."
        self.userIdLabel.text = "USER-ID"
    }
}
