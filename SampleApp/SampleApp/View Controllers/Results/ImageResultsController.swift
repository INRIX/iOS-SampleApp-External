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
class ImageResultsController: UIViewController {

    init(image: UIImage?) {
        super.init(nibName: nil, bundle: nil)
        self.image = image
        self.tabBarItem = UITabBarItem(title: "Results", image: nil, tag: 0)
        self.title = "Results"
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    var imageView: UIImageView!

    var image: UIImage? {
        didSet {
            self.imageView?.image = self.image
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = UIColor.white

        if let tileBackgound = ImageResultsController.createTileBackground() {
            self.view.backgroundColor = UIColor(patternImage: tileBackgound)
        }

        let imageView = UIImageView(frame: self.view.frame)
        imageView.translatesAutoresizingMaskIntoConstraints = true
        imageView.contentMode = .center
        self.view.addSubview(imageView)

        self.imageView = imageView
        self.imageView?.image = self.image
    }

    class func createTileBackground() -> UIImage? {
        UIGraphicsBeginImageContextWithOptions(CGSize(width: 32, height: 32), true, 0)
        let context = UIGraphicsGetCurrentContext()

        context?.setFillColor(UIColor.white.cgColor)

        context?.fill(CGRect(origin: CGPoint.zero, size: CGSize(width: 32, height: 32)))

        context?.setFillColor(UIColor.init(white: 0.9, alpha: 1.0).cgColor)

        context?.fill(CGRect(origin: CGPoint(x: 16, y: 0), size: CGSize(width: 16, height: 16)))
        context?.fill(CGRect(origin: CGPoint(x: 0, y: 16), size: CGSize(width: 16, height: 16)))

        let image = UIGraphicsGetImageFromCurrentImageContext()
        UIGraphicsEndImageContext()
        return image
    }
}
