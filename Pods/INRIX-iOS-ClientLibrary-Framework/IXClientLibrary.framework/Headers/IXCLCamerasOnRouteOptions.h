/*
 * @header IXCLCamerasOnRouteOptions.h
 * @abstract Options class for requesting cameras on a route.
 * @author David Potter
 * @updated 04-25-2014
 * @copyright Copyright (c) 2014-2015 INRIX. All rights reserved.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLCamerasOnRouteOptions
 * @abstract Represents request parameters for retrieving cameras on a route.
 */
@interface IXCLCamerasOnRouteOptions : IXCLBaseOptions <NSCopying>


//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Points describing the route.
 */
@property (nonatomic, strong, readwrite) NSArray * routePoints;

/*!
 * @abstract
 *      Distance in miles from the route that a camera can be located in order
 *      to be included.
 */
@property (nonatomic, assign, readwrite) float distanceInMiles;

/*!
 * @abstract
 *      Determines whether the cameras that out of service should be excluded
 *      from the response. Default is NO.
 */
@property (nonatomic, assign, readwrite) BOOL shouldExcludeOutOfServiceCameras;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a camera ID.
 *
 * @param routePoints Points describing the route.
 * @param distanceInMiles Distance in miles from the route that a camera can
 *  be located in order to be included.
 *
 * @return Instance of the IXCLCameraImageOptions class.
 */
- (instancetype) initWithRoutePoints: (NSArray *) routePoints distanceInMiles: (float) distanceInMiles;

@end
