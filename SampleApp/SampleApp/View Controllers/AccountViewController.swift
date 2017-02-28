///
/// :header: AccountViewController.swift
///
/// :author: Jeffrey White
/// :created: 09-01-2016
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

class AccountViewController: UIViewController {

    @IBOutlet weak var emailTextField: UITextField!
    @IBOutlet weak var passwordTextField: UITextField!
    @IBOutlet weak var logInButton: UIButton!
    @IBOutlet weak var signUpButton: UIButton!

    class func create() -> AccountViewController? {
        let storyBoard = UIStoryboard(name: "Settings", bundle: nil)
        if let viewController = storyBoard.instantiateViewController(withIdentifier: "AccountViewController") as? AccountViewController {
            return viewController
        }
        return nil
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        self.navigationItem.title = "Account"
        self.logInButton.layer.cornerRadius = 5.0
    }

    @IBAction func buttonTapped(_ sender: UIButton) {
        if sender == self.logInButton {
            self.authenticate()
        } else if sender == self.signUpButton {
            self.displaySignUp()
        }
    }

    func authenticate() {
        // TODO: authenticate
    }

    func displaySignUp() {
        if let createAccountViewController = CreateAccountViewController.create() {
            let navigationController = UINavigationController(rootViewController: createAccountViewController)
            self.present(navigationController, animated: true, completion: nil)
        }
    }
}

extension AccountViewController: UITextFieldDelegate {

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        if textField == self.emailTextField {
            self.passwordTextField.becomeFirstResponder()
        } else if textField == self.passwordTextField {
            self.authenticate()
        }

        return true
    }
}
