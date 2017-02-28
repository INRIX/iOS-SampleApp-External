///
/// :header: ParameterViewController.swift
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

class ParameterViewController: UITableViewController {

    init(sampleType: SampleAction.Type) {
        self.sample = sampleType
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }

    var sample: SampleAction.Type
    var currentSample: SampleAction?
    var keys = [String]()
    var values = [String : ParamValue]()

    override func viewDidLoad() {
        super.viewDidLoad()
        self.tableView.rowHeight = UITableViewAutomaticDimension
        self.title = sample.displayName
        let defaults = sample.defaults
        self.values = defaults // Copy the default parameter values from the sample action.
        self.keys = Array(defaults.keys) // Create keys array so the order stays consistent.

        let goButton = UIBarButtonItem(title: "Go", style: .plain, target: self, action: #selector(ParameterViewController.performAction))
        self.navigationItem.setRightBarButton(goButton, animated: false)
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        self.tableView.reloadData()
    }

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        self.tableView.reloadData()
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.keys.count
    }

    override func tableView(_ tableView: UITableView, estimatedHeightForRowAt indexPath: IndexPath) -> CGFloat {
        return 44.0
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .value1, reuseIdentifier: nil) // Nice key value style.

        let key = self.keys[indexPath.row]
        if let value = values[key] {
            cell.textLabel?.text = key.unCamelCaseString().titleCasedString()

            switch value {
            case let value as ParamValueWithAccessoryView:
                cell.accessoryView = value.createAccessoryView({
                    [weak self] (newValue) in
                    self?.values[key] = newValue
                })
                cell.selectionStyle = .none
            case let value as ParamValueWithDetailView:
                let detailCell = DetailViewCell()
                let detailView = value.createDetailView({
                    [weak self, weak detailCell] (newValue) in
                    detailCell?.detailTextLabel?.text = newValue.toString()
                    self?.values[key] = newValue
                })
                detailCell.configureWithView(detailView: detailView)
                detailCell.textLabel?.text = key.unCamelCaseString().titleCasedString()
                detailCell.detailTextLabel?.text = value.toString()
                detailCell.selectionStyle = .none
                return detailCell

            case _ as ParamValueWithPushablePicker :
                cell.accessoryType = .disclosureIndicator
                cell.detailTextLabel?.text = value.toString()
            case _ as ParamValueWithPresentablePicker :
                cell.accessoryType = .disclosureIndicator
                cell.detailTextLabel?.text = value.toString()
            default:
                cell.detailTextLabel?.text = value.toString()
            }
        }

        return cell
    }

    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: true)

        // If the value can create a picker display that picker.
        let key = self.keys[indexPath.row]
        if let value = self.values[key] {
            switch value {
            case let vcValue as ParamValueWithPushablePicker:
                let vc = vcValue.createPushablePicker({
                    [weak self] (newValue) in
                    self?.values[key] = newValue
                })
                self.navigationController?.pushViewController(vc, animated: true)
            case let vcValue as ParamValueWithPresentablePicker:
                let vc = vcValue.createPresentablePicker({
                    [weak self] (newValue) in
                    self?.values[key] = newValue
                    DispatchQueue.main.async {
                        self?.tableView.beginUpdates()
                        self?.tableView.reloadRows(at: [indexPath], with: .automatic)
                        self?.tableView.endUpdates()
                    }
                    })
                vc.modalPresentationStyle = .overCurrentContext
                self.present(vc, animated: true, completion: nil)
            default:
                break
            }
        }
    }

    /// GO button action.
    func performAction() {
        let newSample = sample.init()
        self.currentSample = newSample
        self.navigationItem.rightBarButtonItem?.isEnabled = false
        newSample.verifyValuesAndPerformAction(core: ApplicationCore.sharedInstance.inrixCore, values: self.values) {
            [weak self] (resultsController: UIViewController?, error: Error?, success: Bool) in
            DispatchQueue.main.async {
                if let strongSelf = self {
                    strongSelf.navigationItem.rightBarButtonItem?.isEnabled = true
                    strongSelf.presentResults(resultsController, error: error)
                }
            }
        }
    }

    /// Action finished and came back with an error or a results view controller.
    func presentResults(_ resultsController: UIViewController?, error: Error?) {
        if let resultsController = resultsController {
            self.navigationController?.pushViewController(resultsController, animated: true)
        } else if let error = error {
            let alertController = UIAlertController(title: "Error", message: String(describing: error), preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler:nil))
            self.present(alertController, animated: true, completion: nil)
        } else {
            let alertController = UIAlertController(title: "No response", message: "An error may have occurred", preferredStyle: .alert)
            alertController.addAction(UIAlertAction(title: "Ok", style: .default, handler:nil))
            self.present(alertController, animated: true, completion: nil)
        }
    }
}

/// A cell for displaying a detail view that is auto-sized using autolayout.
class DetailViewCell : UITableViewCell {

    override var textLabel: UILabel? { return self.internalTextLabel }
    override var detailTextLabel: UILabel? { return self.internalDetailTextLabel }

    weak var internalTextLabel: UILabel?
    weak var internalDetailTextLabel: UILabel?

    func configureWithView(detailView: UIView) {
        let textLabel = UILabel()
        let detailLabel = UILabel()
        self.internalTextLabel = textLabel
        self.internalDetailTextLabel = detailLabel

        textLabel.translatesAutoresizingMaskIntoConstraints = false
        detailLabel.translatesAutoresizingMaskIntoConstraints = false
        detailView.translatesAutoresizingMaskIntoConstraints = false

        textLabel.textAlignment = .left
        detailLabel.textAlignment = .right

        self.contentView.addSubview(textLabel)
        self.contentView.addSubview(detailLabel)
        self.contentView.addSubview(detailView)

        let constraints = [NSLayoutConstraint(item: textLabel, attribute: .top, relatedBy: .equal, toItem: self.contentView, attribute: .top, multiplier: 1.0, constant: 8),
                           NSLayoutConstraint(item: textLabel, attribute: .left, relatedBy: .equal, toItem: self.contentView, attribute: .left, multiplier: 1.0, constant: 16),
                           NSLayoutConstraint(item: textLabel, attribute: .right, relatedBy: .equal, toItem: self.contentView, attribute: .right, multiplier: 1.0, constant: -16),
                           NSLayoutConstraint(item: detailLabel, attribute: .top, relatedBy: .equal, toItem: self.contentView, attribute: .top, multiplier: 1.0, constant: 8),
                           NSLayoutConstraint(item: detailLabel, attribute: .left, relatedBy: .equal, toItem: self.contentView, attribute: .left, multiplier: 1.0, constant: 16),
                           NSLayoutConstraint(item: detailLabel, attribute: .right, relatedBy: .equal, toItem: self.contentView, attribute: .right, multiplier: 1.0, constant: -16),
                           NSLayoutConstraint(item: detailView, attribute: .top, relatedBy: .equal, toItem: textLabel, attribute: .bottom, multiplier: 1.0, constant: 16),
                           NSLayoutConstraint(item: detailView, attribute: .bottom, relatedBy: .equal, toItem: self.contentView, attribute: .bottom, multiplier: 1.0, constant: -16),
                           NSLayoutConstraint(item: detailView, attribute: .left, relatedBy: .equal, toItem: self.contentView, attribute: .left, multiplier: 1.0, constant: 16),
                           NSLayoutConstraint(item: detailView, attribute: .right, relatedBy: .equal, toItem: self.contentView, attribute: .right, multiplier: 1.0, constant: -16)]
        self.contentView.addConstraints(constraints)

    }
}
