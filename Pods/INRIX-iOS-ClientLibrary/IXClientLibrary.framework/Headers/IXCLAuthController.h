/*
 * @header IXCLAuthController.h
 * @abstract Controller for authenticating with INRIX web services.
 * @author Cheng Cheng
 * @updated 04-15-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"
#import "IXCLSocialProviderProtocol.h"

@class IXCLChangePasswordOptions;
@class IXCLCoreResponse;
@class IXCLEmailOptions;
@class IXCLPushToken;
@class IXCLResetPasswordOptions;
@class IXCLUpdateUserOptions;
@class IXCLUserAccount;
@class IXCLUserAuthOptions;

FOUNDATION_EXPORT NSString * const IXCLAuthControllerUserStatusDidChangeNotification;
FOUNDATION_EXPORT NSString * const IXCLAuthControllerUserTokenWasInvalidatedNotification;

FOUNDATION_EXPORT NSString * const IXCLAuthControllerUserAccountUserInfoKey;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLAuthControllerProtocol
 * @abstract
 *      Protocol declaration for the Auth Controller
 */
@protocol IXCLAuthControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Boolean value indicating whether the user is currently signed in.
 */
@property (nonatomic, assign, readonly) BOOL isUserSignedIn;

/*!
 * @abstract
 *      User account of the currently signed-in user.
 */
@property (atomic, strong, readonly) IXCLUserAccount * userAccount;

/*!
 * @abstract
 *      The client generated ID of the device.
 * @discussion
 *      The clientDeviceId ID will be generated if it is not already stored.
 */
@property (nonatomic, copy, readonly) NSString * clientDeviceId; // UAS: Don't need to expose to outside

/*!
 * @abstract
 *      The ID of the device that server generated.
 * @discussion
 *      The serverDeviceId will be sent from server. This property will be an
 *      empty string when unset.
 */
@property (nonatomic, copy, readonly) NSString * serverDeviceId;

/*!
 * @abstract
 *      The push notification token for the device
 */
@property (nonatomic, strong, readwrite) IXCLPushToken * pushToken;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Register a new user in with specified options.
 *
 * @param options
 *      Options for registering a user account on server.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestRegisterWithOptions: (IXCLUserAuthOptions *) options
                         completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Signs a user in with specified options.
 *
 * @param options
 *      Options for signing in to user account on server.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestSignInWithOptions: (IXCLUserAuthOptions *) options
                       completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;


/*!
 * @abstract Signs a user in with the specified social provider.
 *
 * @param options Options for signing into the user acccount.
 *
 * @param provider The social provider to sign in with.
 *
 * @param completion Block that returns server repsonse with errors if any.
 */
- (void) requestSocialSignInWithOptions: (IXCLUserAuthOptions *) options
                         socialProvider: (id <IXCLSocialProviderProtocol> ) provider
                             completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Change the user account email on server.
 *
 * @param options
 *      Options for changing the user account email.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestChangeEmailWithOptions: (IXCLEmailOptions *) options
                            completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Change the user account password on server.
 *
 * @param options
 *      Options for changing the user account password.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestChangePasswordWithOptions: (IXCLChangePasswordOptions *) options
                               completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Reset the user account password on server.
 *
 * @param options
 *      Options for resetting the user account password.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestResetPasswordWithOptions: (IXCLResetPasswordOptions *) options
                              completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Get user account information for current user.
 *
 * @param completion
 *      Block that returns user account and server response with errors if any.
 */
- (void) requestUserAccountWithCompletion: (void (^)(IXCLUserAccount * userAccount, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Get user account information for current user.
 *
 * @param options
 *      Options for retrieving user acccount.
 * @param completion
 *      Block that returns user account and server response with errors if any.
 */
- (void) requestUserAccountWithOptions: (IXCLUserAuthOptions *) options
                            completion: (void (^)(IXCLUserAccount * userAccount, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Update user account on a server.
 *
 * @param options
 *      Options for updating the user account.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestUpdateUserWithOptions: (IXCLUpdateUserOptions *) options
                           completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Update device Id for current device.
 *  @param pushToken
 *      Updated push notification object.
 * @param completion
 *     Block that returns server response with errors if any.
 */
- (void) requestUpdateDeviceIdWithPushToken: (IXCLPushToken *) pushToken
                                 completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Update push notification for current user.
 * @param pushToken
 *      Updated push notification object.
 * @param completion
 *     Block that returns server response with errors if any.
 */
- (void) requestUpdatePushNotificationToken: (IXCLPushToken *) pushToken
                                 completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Sign out current user.
 * @param completion
 *      Block that returns server response with errors if any.
 */
- (void) requestSignOutWithCompletion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLAuthController
 * @abstract Controller for authenticating with INRIX web services.
 */
@interface IXCLAuthController : IXCLBaseController <IXCLAuthControllerProtocol>
@end
