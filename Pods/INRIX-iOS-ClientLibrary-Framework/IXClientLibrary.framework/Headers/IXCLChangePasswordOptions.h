/*
 * @header IXCLChangePasswordOptions.h
 * @abstract Represents request parameters for changing user's password.
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

#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLChangePasswordOptions
 * @abstract Represents request parameters for changing user's password.
 */
@interface IXCLChangePasswordOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract User's old account password.
 */
@property (nonatomic, strong, readwrite) NSString * passwordOld;

/*!
 * @abstract User's new account password.
 */
@property (nonatomic, strong, readwrite) NSString * passwordNew;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLChangePasswordOptions with the specified old
 *      and new passwords.
 *
 * @param passwordOld
 *      User's old account password.
 * @param passwordNew
 *      User's new account password.
 *
 * @return
 *      Instance of the IXCLChangePasswordOptions class.
 */
- (instancetype) initWithOldPassword: (NSString *) passwordOld
                         newPassword: (NSString *) passwordNew;

@end
