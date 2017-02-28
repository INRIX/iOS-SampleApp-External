///
/// :header: SettingsViewController.swift
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

import UIKit

class SettingsViewController: UITableViewController {

    enum Row: Int {
        case account = 0
        case about

        var title: String {
            switch self {
            case .account:
                return "Account"
            case .about:
                return "About"
            }
        }

        var viewController: UIViewController? {
            switch self {
            case .account:
                return AccountViewController.create()
            case .about:
                return AboutViewController.create()
            }
        }

        static let count: Int = {
            var max: Int = 0
            while let _ = Row(rawValue: max) { max += 1 }
            return max
        }()
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let dismissButton = UIBarButtonItem(title: "Done", style: .plain, target: self, action: #selector(SettingsViewController.dismissAction))
        self.navigationItem.setLeftBarButton(dismissButton, animated: false)
        self.navigationItem.title = "Settings"
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return Row.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .default, reuseIdentifier: nil)

        if let row = Row(rawValue: indexPath.row) {
            cell.textLabel?.text = row.title.capitalized(with: Locale.current)
            cell.accessoryType = .disclosureIndicator
            return cell
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if let row = Row(rawValue: indexPath.row) {
            if let viewController = row.viewController {
                self.navigationController?.pushViewController(viewController, animated: true)
            }
        }
    }

    func dismissAction() {
        self.dismiss(animated: true, completion: nil)
    }
}
