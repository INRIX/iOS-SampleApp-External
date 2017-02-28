/*
 * @header IXCLRequestInRadiusOptions.h
 * @abstract Represents request parameters for getting data in a radius.
 * @author David Potter
 * @updated 04-25-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>

#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Implementation

/*!
 * @abstract
 *      Options for requests for data in a circular region.
 */
@interface IXCLRequestInRadiusOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The radius of the circular bounding area from which to return data.
 */
@property (nonatomic, assign, readwrite) float radius;

/*!
 * @abstract The center of the region in which to get data.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D center;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a radius and a center coordinate.
 *
 * @param radius The radius of the circular bounding area from which to return data.
 * @param center The center of the region in which to get data.
 *
 * @return Instance of the IXCLRequestInRadiusOptions class.
 */
- (instancetype) initWithRadius: (float) radius center: (CLLocationCoordinate2D) center;

@end
