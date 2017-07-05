/*
 * @header IXCLAuthResponse.h
 * @abstract Model object containing the resposne from the auth controller.
 * @author David Potter
 * @updated 04-18-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLAuthResponse
 * @abstract Model object containing the response from the auth controller.
 */
@interface IXCLAuthResponse : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The auth token from UAS.
 */
@property (nonatomic, copy, readwrite) NSString * uasToken;

@end
