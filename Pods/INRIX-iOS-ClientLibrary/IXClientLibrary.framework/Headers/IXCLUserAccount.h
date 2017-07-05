/*
 * @header IXCLUserAccount.h
 * @abstract Model object representing a user account.
 * @author Cheng Cheng
 * @updated 03-04-2015
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
#pragma mark - Class Declaration

/*!
 * @class IXCLUserAccount
 * @abstract Model object representing a user account.
 */
@interface IXCLUserAccount : NSObject <NSCopying, NSCoding>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Id for this user.
 */
@property (nonatomic, copy, readwrite) NSString * userId;

/*!
 * @abstract Email for this user.
 */
@property (nonatomic, copy, readwrite) NSString * email;

/*!
 * @abstract Given name for this user.
 */
@property (nonatomic, copy, readwrite) NSString * givenName;

/*!
 * @abstract Surname for this user.
 */
@property (nonatomic, copy, readwrite) NSString * surname;

/*!
 * @abstract Profile name for this user.
 */
@property (nonatomic, copy, readwrite) NSString * profileName;

/*!
 * @abstract Avatar index for this user.
 */
@property (nonatomic, copy, readwrite) NSString * avatarIndex;

/*!
 * @abstract Gender for this user.
 */
@property (nonatomic, copy, readwrite) NSString * gender;

/*!
 * @abstract Tag for this user.
 */
@property (nonatomic, copy, readwrite) NSString * tag;

/*!
 * @abstract OAuth email for this user.
 */
@property (nonatomic, copy, readwrite) NSString * oAuthEmail;

/*!
 * @abstract OAuth user id for this user.
 */
@property (nonatomic, copy, readwrite) NSString * oAuthUserId;

/*!
 * @abstract OAuth provider for this user.
 */
@property (nonatomic, copy, readwrite) NSString * oAuthProvider;

@end
