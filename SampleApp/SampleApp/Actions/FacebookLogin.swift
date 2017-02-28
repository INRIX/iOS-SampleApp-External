///
/// :header: FacebookLogin.swift
///
/// :author: Patrick Winchell
/// :created: 02-21-2017
///
/// :copyright: Copyright (c) 2017 INRIX, Inc.
///
///     INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
///     trademark notice(s) contained herein or in related code, files or
///     documentation shall not be altered and shall be included in all copies and
///     substantial portions of the software. This software is "Sample".
///     Refer to the License.pdf file for your rights to use this software.
///

import Foundation

class FacebookLogin: SampleAction {
    required init () {}
    static let description = "Logs in through Facebook"
    static let category = CategoryConstants.auth

    static let defaults: [String : ParamValue] = [ : ]

    static func customViewController(core: InrixCore) -> UIViewController? {
        return FacebookLoginViewController(withCore: core)
    }

    static var isTestable: Bool { return false }

    func performAction(core: InrixCore, values: [String : ParamValue], completionHandler: @escaping ActionCompletionHandler) {
        completionHandler(nil, nil, true)
    }
}

/// Presents a view with a FBSDKLoginButton and a textView.
class FacebookLoginViewController: UIViewController, FBSDKLoginButtonDelegate {

    lazy var facebookProvider = FacebookSocialProvider()

    weak var core: InrixCore?
    weak var textView: UITextView?

    init(withCore core: InrixCore) {
        self.core = core
        super.init(nibName: nil, bundle: nil)
    }

    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.view.backgroundColor = UIColor.white

        FBSDKSettings.setAppID(KeysAndSettings.facebookApplicationId)

        let loginButton = FBSDKLoginButton()
        loginButton.translatesAutoresizingMaskIntoConstraints = false
        loginButton.delegate = self
        loginButton.readPermissions = ["email", "public_profile"]

        self.view.addSubview(loginButton)

        self.view.addConstraints([NSLayoutConstraint(item: loginButton, attribute: .centerX, relatedBy: .equal, toItem: self.view, attribute: .centerX, multiplier: 1.0, constant: 0.0), NSLayoutConstraint(item: loginButton, attribute: .centerY, relatedBy: .equal, toItem: self.view, attribute: .centerY, multiplier: 0.5, constant: 0.0)])

        let textView = UITextView(frame: CGRect(x: 0, y: self.view.frame.height / 2, width: self.view.frame.width, height: self.view.frame.height / 2))
        textView.layer.borderWidth = 1
        textView.layer.borderColor = UIColor.black.cgColor
        textView.isEditable = false
        self.view.addSubview(textView)
        self.textView = textView
        self.updateTextField()
    }

    /// If the user has used FBSDKLoginButton use their Facebook token to log into INRIX.
    func loginButton(_ loginButton: FBSDKLoginButton!, didCompleteWith result: FBSDKLoginManagerLoginResult!, error: Error!) {
        if let error = error {
            self.updateTextField("\(error)")
        } else if result?.token != nil,
            let authController = self.core?.authController {
            self.updateTextField("Logged into Facebook. Logging into INRIX.")
            let options = IXCLUserAuthOptions(authOperationType: IXCLUserAuthType.socialSignIn, userAccount: IXCLUserAccount(), password: "")
            authController.requestSocialSignIn(with: options, socialProvider: self.facebookProvider) {
                [weak self] (response: IXCLCoreResponse?) in
                if let response = response {
                    let success = (response.error == nil)
                    let resultString = success ? "Logged into INRIX with Facebook." : "Failed to log in to INRIX in with Facebook."
                    self?.updateTextField(resultString)
                }
            }
        } else {
            self.updateTextField("Failed to log into Facebook.")
        }
    }

    func loginButtonDidLogOut(_ loginButton: FBSDKLoginButton!) {
        self.core?.authController.requestSignOut(completion: { _ in
            self.updateTextField("Logged out...")
        })
    }

    func loginButtonWillLogin(_ loginButton: FBSDKLoginButton!) -> Bool {
        // Sign out of INRIX services if there is currently an account.
        self.core?.authController.requestSignOut(completion: { _ in
        })
        self.updateTextField("Logging in...")
        return true
    }

    func updateTextField(_ statusString: String? = nil) {
        var values = [(String, String?)]()

        values.append(("Status", statusString))

        if let currentUserAccount = self.core?.authController.userAccount {
            values.append(("currentUserId", currentUserAccount.userId))
            values.append(("email", currentUserAccount.email))
            values.append(("given name", currentUserAccount.givenName))
            values.append(("surname", currentUserAccount.surname))
            values.append(("profileName", currentUserAccount.profileName))
            values.append(("OAuthEmail", currentUserAccount.oAuthEmail))
            values.append(("OAuthUserId", currentUserAccount.oAuthUserId))
            values.append(("OAuthProvider", currentUserAccount.oAuthProvider))
        }

        var lines = [String]()

        for value in values {
            lines.append("\(value.0): \(value.1 ?? "nil")")
        }

        DispatchQueue.main.async {
            self.textView?.text = lines.joined(separator: "\n")
        }
    }
}

class FacebookSocialProvider: NSObject, IXCLSocialProviderProtocol {

    static let providerIdentifier: String = "Facebook"

    lazy var loginManager: FBSDKLoginManager = { return FBSDKLoginManager() }()

    let name: String = FacebookSocialProvider.providerIdentifier

    var isSignedIn: Bool { return FBSDKAccessToken.current() != nil }

    /// Uses the current Facebook token to get the user's name and email from Facebook.
    func getOAuthInfo(_ completion: ((IXCLOAuthInfo?, Error?) -> Void)!) {
        if let token = FBSDKAccessToken.current() {
            FBSDKGraphRequest.init(graphPath: "me", parameters: ["fields" : "email,name"]).start {
                (_, result: Any?, _) in

                if let result = result as? [String : Any],
                    let email = result["email"] as? String,
                    let name = result["name"] as? String {
                    let oAuth = IXCLOAuthInfo()
                    oAuth.provider = FacebookSocialProvider.providerIdentifier
                    oAuth.accessToken = token.tokenString
                    oAuth.userId = token.userID
                    oAuth.userName = name
                    oAuth.email = email
                    completion(oAuth, nil)
                } else {
                    completion(nil, NSError(domain: "FacebookLogin", code: 1, userInfo: nil))
                }
            }
        }
    }

    func signOut() {
        self.loginManager.logOut()
    }
}
