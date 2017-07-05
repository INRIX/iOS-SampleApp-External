/*
 * @header IXCLUpdatedRouteOptions.h
 * @abstract Represents request parameters for route get calls based on an
 *           existing route.
 * @author Gaurav Agarwal
 * @updated 03-04-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLRoutesBaseOptions.h"

@class IXCLRoute;


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLUpdatedRouteOptions
 * @abstract Represents request parameters for calls that obtain routes based on route ID.
 */
@interface IXCLUpdatedRouteOptions : IXCLRoutesBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract A route ID from which to return traffic and routing information.
 */
@property (nonatomic, strong, readwrite) NSString * routeId;

/*!
 * The user's location. This location must be within 150 meters of the route,
 * or the route request may return an error.
 */
@property (nonatomic, strong, readwrite) CLLocation * userLocation;

/*!
 * Flag indicating whether to request a better route.
 */
@property (nonatomic, assign, readwrite) BOOL isGetBetterRoute;

/*!
 * Flag indicating whether to request an alternate route.
 */
@property (nonatomic, assign, readwrite) BOOL isGetAlternateRoute;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize the IXCLUpdatedRouteOptions from an existing route.
 *
 * @param route The route to update.
 *
 * @return Instance of the IXCLUpdatedRouteOptions class.
 */
- (instancetype) initWithRoute: (IXCLRoute *) route;

/*!
 * @abstract Initialize the IXCLUpdatedRouteOptions with specified route ID.
 *
 * @param routeId The route ID.
 *
 * @return Instance of the IXCLUpdatedRouteOptions class.
 */
- (instancetype) initWithRouteId: (NSString *) routeId;

/*!
 * @abstract
 *      Creates a key to be used for the cache.
 * @discussion
 *      Subclasses of this base class should implement this method.
 *
 * @return
 *      A string that uniquely identifies the request identified in this
 *      option.
 */
- (NSString *) keyForCacheEntry;

@end
