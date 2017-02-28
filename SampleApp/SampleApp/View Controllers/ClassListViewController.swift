///
/// :header: ClassListViewController.swift
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

import UIKit

class ClassListViewController: UITableViewController {

    enum Sections: Int {
        case categories = 0
        case samples = 1

        var name: String {
            switch self {
            case .categories:
                return "Categories"
            case .samples:
                return "Samples"
            }
        }
    }

    struct ViewModel {
        let category: String
        let allSamples: [SampleAction.Type]
        let samples: [SampleAction.Type]
        let categories: [String]
        let isSearch: Bool

        init(category: String) {
            self.isSearch = false
            self.category = category
            let samples = ApplicationCore.sharedInstance.samplesForCategory(category)
            let filteredSamples = samples.filter({ $0.category.lowercased() == category.lowercased() })

            var allCategories = samples.filter({ $0.category.lowercased() != category.lowercased() }).map({ $0.category })
            allCategories = allCategories.map({ $0.substring(from: category.endIndex) }).map({ $0.trimmingCharacters(in: CharacterSet(charactersIn: ".")) })
            allCategories = allCategories.flatMap({ $0.components(separatedBy: ".").first })
            allCategories = Array(Set(allCategories)).sorted()

            self.allSamples = samples
            self.samples = filteredSamples
            self.categories = allCategories
        }

        init(search: String) {
            self.isSearch = true

            // Fold the string to be case insensitive and remove diacritics.
            let stringFoldingOptions: NSString.CompareOptions = NSString.CompareOptions([.caseInsensitive, .diacriticInsensitive])
            let searchString = search.folding(options: stringFoldingOptions, locale: nil).trimmingCharacters(in: CharacterSet.whitespacesAndNewlines)

            let samples = ApplicationCore.sharedInstance.samplesForCategory("")

            self.category = ""
            self.allSamples = samples
            self.categories = []

            if searchString.isEmpty == false {
                let scoredSamples = samples.map({ return (sample: $0, score: $0.searchValue(for: searchString)) })

                // If no samples contain the complete substring, show ones that contain partial results.
                let maxScore = scoredSamples.reduce(0) { max($0, $1.score) }
                let scoreThreshold: Float = maxScore < 1 ? 0 : 1

                // Filter out all samples that don't contain the string.
                let filteredSamples = scoredSamples.filter({ $0.score > scoreThreshold })
                // Sort by better score.
                let sortedSamples = filteredSamples.sorted(by: { return $0.score > $1.score })

                self.samples = sortedSamples.map({ $0.sample })
            } else {
                self.samples = []
            }
        }
    }

    lazy var model = ViewModel(category: "")

    /// Search controller properties
    fileprivate var searchController: UISearchController?
    fileprivate var searchResultsController: ClassListViewController?

    override func viewDidLoad() {
        super.viewDidLoad()

        if let title = self.model.category.components(separatedBy: ".").last, title.isEmpty == false {
            self.title = title.capitalized(with: Locale.current)
        }

        /// Only install these buttons on the root view.
        if self.model.category == "" && self.model.isSearch == false {
            let settingsButton = UIBarButtonItem(title: "Settings", style: .plain, target: self, action: #selector(ClassListViewController.showSettings))
            self.navigationItem.setLeftBarButton(settingsButton, animated: false)

            let testButton = UIBarButtonItem(title: "Test", style: .plain, target: self, action: #selector(ClassListViewController.performTests))
            self.navigationItem.setRightBarButton(testButton, animated: false)

            let searchResultsController = ClassListViewController()
            searchResultsController.configureForSearch()

            let searchController = UISearchController(searchResultsController: searchResultsController)

            searchController.searchResultsUpdater = searchResultsController
            searchController.dimsBackgroundDuringPresentation = false
            self.definesPresentationContext = true
            self.tableView.tableHeaderView = searchController.searchBar
            self.searchController = searchController
            self.searchResultsController = searchResultsController
        }
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return self.tableView(tableView, numberOfRowsInSection: section) > 0 ? Sections(rawValue: section)?.name : nil
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if let section = Sections(rawValue: section) {
            switch section {
            case .categories:
                return self.model.categories.count
            case .samples:
                return self.model.samples.count
            }
        }
        return 0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {

        if let section = Sections(rawValue: indexPath.section) {
            switch section {
            case .categories:
                let cell = UITableViewCell(style: .default, reuseIdentifier: nil)
                let category = self.model.categories[indexPath.row]
                cell.textLabel?.text = category.unCamelCaseString()
                cell.accessoryType = .disclosureIndicator
                return cell
            case .samples:
                let cell = UITableViewCell(style: .subtitle, reuseIdentifier: nil)
                let sample = self.model.samples[indexPath.row]
                cell.textLabel?.text = sample.displayName
                cell.detailTextLabel?.text = sample.description
                return cell
            }
        }

        return UITableViewCell(style: .default, reuseIdentifier: nil)
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if let section = Sections(rawValue: indexPath.section) {
            switch section {
            case .categories:
                let newVC = ClassListViewController()
                let category = self.model.categories[indexPath.row]
                let newCategory = self.model.category + (self.model.category.isEmpty ? "" : ".") + category
                newVC.model = ViewModel(category: newCategory)
                self.pushViewController(newVC)
            case .samples:
                let sample = self.model.samples[indexPath.row]
                let newVC: UIViewController
                if let customViewController = sample.customViewController(core: ApplicationCore.sharedInstance.inrixCore) {
                    newVC = customViewController
                } else {
                    newVC = ParameterViewController(sampleType: sample)
                }
                self.pushViewController(newVC)
            }
        }
    }

    func showSettings() {
        let settingsViewController = SettingsViewController()
        let navigationController = UINavigationController(rootViewController: settingsViewController)
        self.present(navigationController, animated: true, completion: nil)
    }

    func performTests() {
        let testViewController = TestListViewController()
        self.pushViewController(testViewController)
    }

    func pushViewController(_ viewController: UIViewController) {
        // If the view is a search view it has to reach up to the presenting view to push onto the nav stack.
        if self.model.isSearch == true {
            self.presentingViewController?.navigationController?.pushViewController(viewController, animated: true)
        } else {
            self.navigationController?.pushViewController(viewController, animated: true)
        }
    }
}

extension ClassListViewController : UISearchResultsUpdating {

    func configureForSearch() {
        self.model = ViewModel(search: "")
    }

    func updateSearchResults(for searchController: UISearchController) {
        let text = searchController.searchBar.text ?? ""
        self.model = ViewModel(search: text)
        self.tableView.reloadData()
    }
}

extension SampleAction {
    static func searchValue(for searchString: String) -> Float {
        let stringFoldingOptions: NSString.CompareOptions = NSString.CompareOptions([.caseInsensitive, .diacriticInsensitive])
        let category = self.category.folding(options: stringFoldingOptions, locale: nil)
        let name = self.name.folding(options: stringFoldingOptions, locale: nil)
        let description = self.description.folding(options: stringFoldingOptions, locale: nil)

        let searchSources = [category, name, description]

        var value: Float = 0
        let searchSet = CharacterSet(charactersIn: searchString)

        searchSources.forEach { (source) in
            if source.contains(searchString) {
                value += 1
            }
            /// Give partial credit to entries that include the characters but not the complete substring.
            let sourceSet = CharacterSet(charactersIn: source)
            if searchSet.isSubset(of: sourceSet) {
                value += 0.1
            }
        }
        return value
    }
}
