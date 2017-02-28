/*
 * @header IXCLUpdateUserOptions.h
 * @abstract Represents request parameters for updating a user.
 * @author Aleksei Zhilin
 * @updated 08-26-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLUpdateUserOptions
 * @abstract Represents request parameters for updating a user.
 */
@interface IXCLUpdateUserOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      User's account email. Optional. If not provided, email is not changed.
 */
@property (nonatomic, strong, readwrite) NSString * email;

/*!
 * @abstract
 *      User's account password. Optional. If password is provided then options
 *      are valid only if the user account doesn't have a password yet.
 */
@property (nonatomic, strong, readwrite) NSString * password;

/*!
 * @abstract User's given name. Optional.
 */
@property (nonatomic, strong, readwrite) NSString * givenName;

/*!
 * @abstract User's surname. Optional.
 */
@property (nonatomic, strong, readwrite) NSString * surname;

/*!
 * @abstract User's gender. Optional.
 */
@property (nonatomic, strong, readwrite) NSString * gender;

/*!
 * @abstract Profile name for this user.
 */
@property (nonatomic, strong, readwrite) NSString * profileName;

/*!
 * @abstract Avatar index for this user.
 */
@property (nonatomic, strong, readwrite) NSString * avatarIndex;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLUpdateUserOptions with the specified email and
 *      password.
 *
 * @param email
 *      User's account email. Optional. If not provided, email is not changed.
 * @param password
 *      User's account password. Optional. If password is provided then options
 *      are valid only if the user account doesn't have a password yet.
 *
 * @return
 *      Instance of the IXCLUpdateUserOptions class.
 */
- (instancetype) initWithEmail: (NSString *) email
                      password: (NSString *) password;

@end
