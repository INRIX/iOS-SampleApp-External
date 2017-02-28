///
/// :header: UIPickerViewController.swift
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

typealias UIPickerOption = (name: String, value: ParamValue)

/// View controller with a UIPickerView that is configured with a list of values and options.
class UIPickerViewController: UIViewController, UIPickerViewDelegate, UIPickerViewDataSource {

    init(options: [[UIPickerOption]], values: [Any], changeHandler: @escaping (_ newValues: [Any]) -> Void) {
        super.init(nibName: nil, bundle: nil)

        guard options.count == values.count else {
            fatalError("UIPickerViewController should be configured with the same number of values as options")
        }

        for i in 0..<options.count {
            let theseOptions = options[i]
            let value = values[i]

            for j in 0..<theseOptions.count {
                let option = theseOptions[j]
                if type(of: option.value) != type(of: value) {
                    fatalError("UIPickerViewController should be configured with options with the same type as the values.")
                }
            }
        }

        self.options = options
        self.values = values
        self.changeHandler = changeHandler
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var pickerView: UIPickerView!

    var values = [Any]()

    var options = [[UIPickerOption]]()

    var changeHandler: (_ newValues: [Any]) -> Void = { _ in }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor(white: 0.25, alpha: 0.05)

        // Set the picker to take up half of the screen.
        let picker = UIPickerView(frame: CGRect(x: 0, y: self.view.frame.height / 2, width: self.view.frame.width, height: self.view.frame.height / 2))
        picker.backgroundColor = UIColor.white
        picker.translatesAutoresizingMaskIntoConstraints = true
        picker.delegate = self
        picker.dataSource = self

        for i in 0..<self.options.count {
            let theseOptions = self.options[i]
            let value = self.values[i]

            for j in 0..<theseOptions.count {
                let option = theseOptions[j]
                if String(describing: option.value) == String(describing: value) {
                    picker.selectRow(j, inComponent: i, animated: false)
                }
            }
        }

        self.modalPresentationStyle = .overFullScreen

        self.view.addSubview(picker)
        self.pickerView = picker
        picker.reloadAllComponents()

        // Tap the background view to dismiss.
        let tapGesture = UITapGestureRecognizer(target: self, action: #selector(UIPickerViewController.dismissAction))
        self.view.addGestureRecognizer(tapGesture)
    }

    func pickerView(_ pickerView: UIPickerView, rowHeightForComponent component: Int) -> CGFloat {
        return 22
    }
    func pickerView(_ pickerView: UIPickerView, widthForComponent component: Int) -> CGFloat {
        return self.view.frame.width / CGFloat(self.options.count + 1)
    }

    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        return self.options.count
    }

    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        return self.options[component].count
    }

    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        let option = self.options[component][row]

        return option.name
    }

    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        let option = options[component][row]
        self.values[component] = option.value
        self.changeHandler(self.values)
    }

    func dismissAction() {
        self.dismiss(animated: true, completion: nil)
    }
}
