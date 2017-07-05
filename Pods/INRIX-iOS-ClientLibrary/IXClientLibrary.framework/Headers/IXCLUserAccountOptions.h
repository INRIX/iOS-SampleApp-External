/*
 * @header IXCLUserAccountOptions.h
 * @abstract Represents request parameters for managing user account.
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

#import "IXCLBaseOptions.h"
#import "IXCLUserAccount.h"

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLUserAccountOptions
 * @abstract Represents request parameters for managing user account.
 */
@interface IXCLUserAccountOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract User's account.
 */
@property (nonatomic, strong, readwrite) IXCLUserAccount * userAccount;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLUserAccountOptions with the specified user account.
 *
 * @param userAccount
 *      User's account.
 *
 * @return
 *      Instance of the IXCLUserAccountOptions class.
 */
- (instancetype) initWithUserAccount: (IXCLUserAccount *) userAccount;

@end
