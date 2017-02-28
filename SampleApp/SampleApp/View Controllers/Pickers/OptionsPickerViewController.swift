//
//  OptionsPickerViewController.swift
//  SampleApp
//
//  Created by Patrick Winchell on 8/30/16.
//  Copyright © 2016 Inrix. All rights reserved.
//

import Foundation

struct OptionPickerOption<Element> {
    var name: String
    var option: Element
    var value: Bool
}

/// Viewcontroller with a bunch of check boxes
class OptionsPickerViewController<Element>: UITableViewController {

    init(options: [OptionPickerOption<Element>], changeHandler: @escaping (_ newValues: [Element]) -> Void) {
        super.init(nibName: nil, bundle: nil)
        self.options = options
        self.changeHandler = changeHandler
    }

    var options = [OptionPickerOption<Element>]()
    var changeHandler: (_ newValues: [Element]) -> Void = { _ in }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return options.count
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = UITableViewCell(style: .value1, reuseIdentifier: nil) // Nice key value style.

        let option = self.options[indexPath.row]
        cell.textLabel?.text = option.name

        let rowSwitch = UISwitch()
        rowSwitch.isOn = option.value

        rowSwitch.tag = indexPath.row
        rowSwitch.addTarget(self, action: #selector(OptionsPickerViewController.switchStateChange), for: .valueChanged)

        cell.accessoryView = rowSwitch

        return cell
    }

    func switchStateChange(_ thisSwitch: UISwitch) {
        let tag = thisSwitch.tag
        if tag >= 0 && tag < self.options.count {
            self.options[tag].value = thisSwitch.isOn
            self.postUpdate()
        }
    }

    func postUpdate() {
        let elements = self.options.filter({ $0.value }).map { $0.option }
        self.changeHandler(elements)
    }
}
