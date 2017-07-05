/*
 * @header IXCLUserToken.h
 * @abstract Model object representing auth token.
 * @author Cheng Cheng
 * @updated 03-05-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

//-----------------------------------------------------------------------------
#pragma mark Global Exports

FOUNDATION_EXPORT NSString * IXCLUserTokenAccessTokenKey;
FOUNDATION_EXPORT NSString * IXCLUserTokenExpiryDateKey;
FOUNDATION_EXPORT NSString * IXCLUserTokenUASTokenKey;
FOUNDATION_EXPORT NSString * IXCLUserTokenRefreshTokenKey;

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLUserToken
 * @abstract Model object representing auth token.
 */
@interface IXCLUserToken : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract authentication token from UAS.
 */
@property (atomic, copy, readwrite) NSString * uasToken;

/*!
 * @abstract Expiration date of authentication token.
 */
@property (atomic, strong, readwrite) NSDate * accessTokenExpiryDate;

/*!
 * @abstract authentication token when renew expired token.
 */
@property (atomic, copy, readwrite) NSString * refreshToken;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Save user token to local disk.
 *
 * @param userToken
 *      Access token from UAS.
 */
+ (void) saveUserTokenToLocalStoreWithToken: (IXCLUserToken *) userToken;

/*!
 * @abstract
 *      Returns the user token stored locally.
 *
 * @return
 *      IXCLUserToken contains user token stored locally.
 */
+ (IXCLUserToken *) userTokenFromLocalStore;

/*!
 * @abstract
 *      Reset locally stored token.
 */
+ (void) resetLocalUserTokenStore;

/*!
 * @abstract
 *      Validate if a token is valid.
 *
 * @param userToken
 *      The token to be validated.
 *
 * @return
 *      Bool value represent if the token is valid or not.
 */
+ (BOOL) isUserTokenValidForToken: (IXCLUserToken *) userToken;

@end
