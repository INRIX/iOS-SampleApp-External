/*
 * @header IXCLGetUserPropertiesResponse.h
 * @abstract The server response to the User Properties Controller Get call.
 * @author Kent Lottis
 * @updated 05-19-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

/*!
 * @abstract
 *      Represents the server response from a Get User Properties call via
 *      the User Properties Controller
 */
@interface IXCLGetUserPropertiesResponse : NSObject

/*!
 * @abstract
 *      A dictionary with the user's global (applicaton-independent) properties.
 */
@property (nonatomic, strong, readonly) NSDictionary * globalProperties;

/*!
 * @abstract
 *      A dictionary with the user's application-specific properties.
 */
@property (nonatomic, strong, readonly) NSDictionary * applicationProperties;
@end
