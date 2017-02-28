/*!
 * @header      IXCLOAuthInfo.m
 *
 * @abstract    Represents user information from an OAuth provider.
 *
 * @author      Nathan Clark
 *
 * @date     August 29, 2016
 *
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */


#import <Foundation/Foundation.h>

@interface IXCLOAuthInfo : NSObject <NSCopying>

/*!
 * @abstract The third-party OAuth provider name.
 */
@property (nonatomic, copy, readwrite)  NSString * provider;

/*!
 * @abstract The user name provided by the third-party OAuth provider.
 */
@property (nonatomic, copy, readwrite) NSString * userName;

/*!
 * @abstract The user ID provided by the third-party OAuth provider.
 */
@property (nonatomic, copy, readwrite) NSString * userId;

/*!
 * @abstract The email address provided by the third-party OAuth provider.
 */
@property (nonatomic, copy, readwrite) NSString * email;

/*!
 * @abstract The access token provided by the third-party OAuth provider.
 */
@property (nonatomic, copy, readwrite) NSString * accessToken;

@end
