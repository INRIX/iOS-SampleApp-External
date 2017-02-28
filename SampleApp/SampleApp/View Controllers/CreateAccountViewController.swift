///
/// :header: CreateAccountViewController.swift
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

class CreateAccountViewController: UIViewController {

    @IBOutlet weak var emailTextField: UITextField!
    @IBOutlet weak var passwordTextField1: UITextField!
    @IBOutlet weak var passwordTextField2: UITextField!
    @IBOutlet weak var signUpButton: UIButton!

    class func create() -> CreateAccountViewController? {
        let storyBoard = UIStoryboard(name: "Settings", bundle: nil)
        if let viewController = storyBoard.instantiateViewController(withIdentifier: "CreateAccountViewController") as? CreateAccountViewController {
            return viewController
        }
        return nil
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let dismissButton = UIBarButtonItem(title: "Cancel", style: .plain, target: self, action: #selector(CreateAccountViewController.dismissAction))
        self.navigationItem.setLeftBarButton(dismissButton, animated: false)
        self.navigationItem.title = "Sign Up"
        self.signUpButton.layer.cornerRadius = 5.0
    }

    @IBAction func buttonTapped(_ sender: UIButton) {
        if sender == self.signUpButton {
            self.createAccount()
        }
    }

    func createAccount() {
        // TODO: create account
    }

    func dismissAction() {
        self.dismiss(animated: true, completion: nil)
    }
}

extension CreateAccountViewController: UITextFieldDelegate {

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        if textField == self.emailTextField {
            self.passwordTextField1.becomeFirstResponder()
        } else if textField == self.passwordTextField1 {
            self.passwordTextField2.becomeFirstResponder()
        } else if textField == self.passwordTextField2 {
            self.createAccount()
        }

        return true
    }
}
