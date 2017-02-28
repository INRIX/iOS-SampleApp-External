/*
 * @header IXCLTrafficQualityOptions.h
 * @abstract Represents request parameters for traffic quality calls.
 * @author David Potter
 * @updated 03-05-2014
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
#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLTrafficQualityOptions
 * @abstract Represents request parameters for traffic quality calls.
 */
@interface IXCLTrafficQualityOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract A coordinate used as the center point.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D centerPoint;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a center point.
 *
 * @param centerPoint A coordinate to be used as the center point.
 *
 * @return Instance of the IXCLTrafficQualityOptions class.
 */
- (instancetype) initWithCenterPoint: (CLLocationCoordinate2D) centerPoint;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
