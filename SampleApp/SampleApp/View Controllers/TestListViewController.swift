///
/// :header: TestListViewController.swift
///
/// :author: Patrick Winchell
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

/// A view controller that lists all SampleAction classes and uses their defaults to test them.
class TestListViewController: UITableViewController {

    enum Sections: Int {
        case results = 0
        case tests = 1
    }

    init() {
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    fileprivate let allClasses = ApplicationCore.sharedInstance.samples.filter({ $0.isTestable })
    fileprivate var currentTest: SampleActionsTestRun?
    fileprivate var createdTests = [SampleActionsTestRun]()
    fileprivate var needsReload = true

    override func viewDidLoad() {
        super.viewDidLoad()
        self.title = "Tests"
        self.startTesting()
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 2
    }

    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        if let thisSection = Sections(rawValue: section), thisSection == .tests {
            return "Tests"
        }
        return nil
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if let thisSection = Sections(rawValue: section) {
            switch thisSection {
            case .results:
                return 1
            case .tests:
                return allClasses.count
            }
        }
        return 0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .value1, reuseIdentifier: nil)

        if let section = Sections(rawValue: indexPath.section) {
            switch section {
            case .results:
                if let currentTest = currentTest {
                    switch currentTest.state {
                    case .notStarted:
                        cell.textLabel?.text = "Start Tests"
                    default:

                        let results = Array(currentTest.results.values)
                        var failures = 0
                        var successes = 0

                        for result in results {
                            switch result {
                            case .failure, .timeout:
                                failures += 1
                            case .success:
                                successes += 1
                            default:
                                break
                            }
                        }

                        cell.textLabel?.text = currentTest.state == .running ? "Testing" : "Finished"                        
                        var font = UIFont.systemFont(ofSize: UIFont.labelFontSize)
                        
                        if #available(iOS 9.0, *) {
                            font = UIFont.monospacedDigitSystemFont(ofSize: UIFont.labelFontSize, weight: UIFontWeightRegular)
                        }
                        
                        cell.detailTextLabel?.text = "\(successes) ✅    \(failures) ⛔️"
                        cell.detailTextLabel?.font = font
                        cell.detailTextLabel?.textColor = UIColor.black
                    }
                } else {
                    cell.textLabel?.text = "Start Tests"
                }
                return cell
            case .tests:
                let sample = self.allClasses[indexPath.row]
                cell.textLabel?.text = sample.displayName

                if let results = self.currentTest?[sample] {
                    switch results {
                    case .running:
                        let spinner = UIActivityIndicatorView(activityIndicatorStyle: .gray)
                        spinner.startAnimating()
                        cell.accessoryView = spinner

                    case .failure:
                        cell.detailTextLabel?.text = "⛔️"
                    case .success:
                        cell.detailTextLabel?.text = "✅"
                    case .timeout:
                        cell.detailTextLabel?.text = "⏲"
                    }
                }
                cell.selectionStyle = .none

                return cell
            }
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)
        if let section = Sections(rawValue: indexPath.section) {
            switch section {
            case .results:
                self.startTesting()
            default:
                break
            }
        }
    }

    func startTesting() {
        let newTestRun = SampleActionsTestRun(classes: self.allClasses, timeout: 10.0) {
            [weak self] (samples) in
            self?.update(samples)
        }
        self.currentTest = newTestRun
        newTestRun.startTesting()

        self.createdTests = self.createdTests.filter({ $0.state != .finished })
        self.createdTests.append(newTestRun)
    }

    var samplesToUpdate = [SampleAction.Type]()

    /// Updates the table view.
    func update(_ updatedSamples: [SampleAction.Type]) {
        self.samplesToUpdate.append(contentsOf: updatedSamples)
        self.needsReload = true
        DispatchQueue.main.async {
            if self.needsReload == true {
                self.needsReload = false
                let samples = self.samplesToUpdate
                self.samplesToUpdate.removeAll()
                if samples.count == 0 {
                    self.tableView.reloadData()
                } else {
                    var rowsToUpdate = Set([IndexPath(item: 0, section: Sections.results.rawValue)])
                    for sample in samples {
                        if let index = self.allClasses.index(where: { sample == $0 }) {
                            rowsToUpdate.insert(IndexPath(item: index, section: Sections.tests.rawValue))
                        }
                    }

                    self.tableView.beginUpdates()
                    self.tableView.reloadRows(at: Array(rowsToUpdate), with: .none)
                    self.tableView.endUpdates()
                }
            }
        }
    }
}

/// Class that runs each SampleAction as a test using its defaults.
class SampleActionsTestRun {

    /// State of the all the collective tests.
    enum TotalTestingState {
        case notStarted
        case running
        case finished
    }

    /// State of individual tests.
    enum IndividualTestState {
        case running
        case success
        case failure
        case timeout
    }

    var state = TotalTestingState.notStarted

    fileprivate let updateHandler: ([SampleAction.Type]) -> Void
    fileprivate let classes: [SampleAction.Type]
    fileprivate let timeoutTime: TimeInterval

    fileprivate var core: InrixCore?
    fileprivate var instances = [SampleAction]()
    fileprivate var results = [String : IndividualTestState]()

    init(classes: [SampleAction.Type], timeout: TimeInterval, updateHandler: @escaping ([SampleAction.Type]) -> Void) {
        self.updateHandler = updateHandler
        self.classes = classes
        self.timeoutTime = timeout
    }

    func startTesting() {
        guard self.state == .notStarted else {
            return
        }
        self.state = .running

        // Create a new core so that any caches are bypassed.
        let core = ApplicationCore.createCore()
        self.core = core

        for thisClass in self.classes {
            let className = String(describing: thisClass)
            self.results[className] = .running
            let instance = thisClass.init()
            DispatchQueue.main.async {

                instance.performAction(core: core) {
                    [weak self] (resultsController, error, success: Bool) in
                    if let strongSelf = self {
                        strongSelf.results[className] = success == true ? IndividualTestState.success : IndividualTestState.failure
                        strongSelf.update([thisClass])
                    }
                }

                let timeout: DispatchTime = DispatchTime.now() + Double(Int64(self.timeoutTime * Double(NSEC_PER_SEC))) / Double(NSEC_PER_SEC)
                DispatchQueue.main.asyncAfter(deadline: timeout) {
                    [weak self] in
                    if let strongSelf = self {
                        if strongSelf.results[className] == .running {
                            strongSelf.results[className] = .timeout
                            strongSelf.update([thisClass])
                        }
                    }
                }

                self.instances.append(instance)
            }
        }
        self.update(self.classes)
    }

    subscript(sample: SampleAction.Type) -> IndividualTestState? {
        let className = String(describing: sample)
        return self.results[className]
    }

    fileprivate func update(_ samples: [SampleAction.Type]) {
        DispatchQueue.main.async {
            let stillRunning = self.results.values.contains(.running)
            if self.state == .running && stillRunning == false {
                self.state = .finished
                self.instances = []
                self.core = nil
            }

            self.updateHandler(samples)
        }
    }
}
