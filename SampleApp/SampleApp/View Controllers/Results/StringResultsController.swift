///
/// :header: StringResultsController.swift
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

/// Viewcontroller with an UITextView.
class StringResultsController: UIViewController {

    init(text: String) {
        super.init(nibName: nil, bundle: nil)
        self.text = text
        self.tabBarItem = UITabBarItem(title: "Results", image: nil, tag: 0)
        self.title = "Results"
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var textView: UITextView!

    var text = "" {
        didSet {
            self.textView?.text = text
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let textView = UITextView()
        textView.translatesAutoresizingMaskIntoConstraints = true
        textView.frame = self.view.frame
        self.view.addSubview(textView)

        self.textView = textView
        self.textView?.text = text

        if let tabBar = self.tabBarController?.tabBar {
            self.textView?.contentInset.bottom = tabBar.frame.height
        }
    }
}
