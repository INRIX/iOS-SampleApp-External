/*
 * @header IXCLUserPropertiesOptions.h
 * @abstract The options class for the User Properties Controller
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

#import "IXCLBaseOptions.h"

/*!
 * @class IXCLGetUserPropertiesOptions
 *
 * @abstract
 *      Represents to options to the getUserProperties method on the User Properties Controller.
 */
@interface IXCLGetUserPropertiesOptions : IXCLBaseOptions <NSCopying>
@end

/*!
 * @class IXCLSaveUserPropertiesOptions
 *
 * @abstract
 *      Represents to options to the saveUserProperties method on the User Properties Controller.
 */
@interface IXCLSaveUserPropertiesOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract
 *      A dictionary with the user's global (application-independent) properties.
 */
@property (nonatomic, strong, readwrite) NSDictionary * globalProperties;

/*!
 * @abstract
 *      A dictionary with the user's application-specific properties.
 */
@property (nonatomic, strong, readwrite) NSDictionary * applicationProperties;
@end
