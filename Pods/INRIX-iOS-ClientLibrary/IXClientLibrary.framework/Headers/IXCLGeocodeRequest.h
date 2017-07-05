/*
 * @header IXCLGeocodeRequest.h
 * @abstract Request object passed to IXCLGeocodeController.
 * @author Aleksei Zhilin
 * @updated 01-23-2015
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLGeocodeRequest : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract A string describing the location you want to look up.
 */
@property (nonatomic, strong, readwrite) NSString * addressString;

/*!
 * @abstract A dictionary describing the location you want to look up.
 */
@property (nonatomic, strong, readwrite) NSDictionary * addressDictionary;

/*!
 * @abstract The location object containing the coordinate data to look up.
 */
@property (nonatomic, strong, readwrite) CLLocation * location;

/*!
 * @abstract
 *      A block object containing the code to execute at the end of the
 *      request.
 * @discussion
 *      This code is called whether the request is successful or unsuccessful.
 */
@property (nonatomic, copy, readwrite) CLGeocodeCompletionHandler completionBlock;

@end
