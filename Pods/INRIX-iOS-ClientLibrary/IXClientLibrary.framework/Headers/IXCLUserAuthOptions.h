/*
 * @header IXCLUserAuthOptions.h
 * @abstract Represents request parameters for authenticating a user.
 * @author Gaurav Agarwal
 * @updated 11-26-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLUserAccountOptions.h"
#import "IXCLPushToken.h"
@class IXCLOAuthInfo;

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract The minimum length of the password.
 * @discussion Value is 6.
 */
FOUNDATION_EXPORT NSUInteger const IXCLUserAuthOptionsMinimumPasswordLength;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract Type of auth operation.
 * @discussion Describes types of auth operations.
 *
 * @constant IXCLUserAuthTypeSignIn         Signin operation.
 * @constant IXCLUserAuthTypeRegister       Register operation.
 * @constant IXCLUserAuthTypeRenewToken     Renew the current user token.
 * @constant IXCLUserAuthTypeSocialSignIn   Sign in using OAuth from an third-party OAuth provider.
 */
typedef NS_ENUM (NSUInteger, IXCLUserAuthType)
{
    IXCLUserAuthTypeSignIn       = 0,
    IXCLUserAuthTypeRegister     = 1,
    IXCLUserAuthTypeRenewToken   = 2,
    IXCLUserAuthTypeSocialSignIn = 3
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLUserAuthOptions
 * @abstract Represents request parameters for authenticating a user.
 */
@interface IXCLUserAuthOptions : IXCLUserAccountOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract User's account password.
 */
@property (nonatomic, strong, readwrite) NSString * password;

/*!
 * @abstract Auth operation type.
 */
@property (nonatomic, assign, readwrite) IXCLUserAuthType authType;

/*!
 * @abstract Optional device's push token.
 */
@property (nonatomic, strong, readwrite) IXCLPushToken * pushToken;

/*!
 * @abstract Oauth information provided by third-party OAuth provider.
 * The authType property must be set to IXCLUserAuthTypeSocialSignIn
 * for this information to be used.
 */
@property (nonatomic, strong, readwrite) IXCLOAuthInfo * oAuthInfo;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLUserAuthOptions with the specified auth type, user
 *      account and password.
 *
 * @param authType
 *      Auth operation type
 * @param userAccount
 *      User's account.
 * @param password
 *      User's account password.
 *
 * @return
 *      Instance of the IXCLUserAuthOptions class.
 */
- (instancetype) initWithAuthOperationType: (IXCLUserAuthType) authType
                               userAccount: (IXCLUserAccount *) userAccount
                                  password: (NSString *) password;

@end
