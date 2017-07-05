/*
 * @header IXCLRoutesController.h
 * @abstract Controller for managing requests for routes.
 * @author Gaurav Agarwal
 * @updated 04-24-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>

#import "IXCLBaseControllerWithCache.h"
#import "IXCLRoutesBaseOptions.h"
#import "IXCLRoutesFromPointsOptions.h"


@class IXCLCoreResponse;
@class IXCLRoute;
@class IXCLRoutesCollection;
@class IXCLRoutesResponse;


//-----------------------------------------------------------------------------
#pragma mark Global Exports - Caching

/*!
 * @abstract Default cache size limit for cached routes.
 * @discussion Value is 100.
 */
FOUNDATION_EXPORT NSUInteger const IXCLRoutesControllerDefaultCacheLimit;


//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLRoutesControllerProtocol
 * @abstract
 *      Protocol definition for the Routes Controller
 */
@protocol IXCLRoutesControllerProtocol <IXCLBaseControllerWithCacheProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Recommendation Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing routes.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing routes.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Min/Max Routable Distance

/*!
 * @abstract
 *      Minimum distance for requesting routes.
 * @discussion
 *      Routes are not loaded from the server if the distance between the start
 *      point and end point is less than this minimum distance.
 */
@property (nonatomic, assign, readonly) double minRouteDistanceInMiles;

/*!
 * @abstract
 *      Maximum distance for requesting routes.
 * @discussion
 *      Routes are not loaded from the server if the distance between the start
 *      point and end point is greater than this maximum distance.  In order to
 *      request longer routes, set the overrideMaxDistance property to YES in
 *      the options object.
 */
@property (nonatomic, assign, readonly) double maxRouteDistanceInMiles;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Calculates routes using specified route options.
 *
 * @param options
 *      Route options used for calculating the route.
 * @param completion
 *      Block that returns a routes collection containing an array of routes
 *      and other state information.
 */
- (void) requestRoutesWithOptions: (IXCLRoutesBaseOptions *) options
                       completion: (void (^)(IXCLRoutesResponse * routesResponse)) completion;

/*!
 * @abstract
 *      Retrieves routes from the cache using the specified route options.
 * @discussion
 *      If there are no routes in the cache, no network request will be made
 *      and an empty collection will be returned.
 *
 * @param options
 *      Route options used for calculating the route.
 * @param error
 *      Value is set if there is an error due to the options.
 *
 * @return
 *      IXCLRoutesCollection containing array of routes and other state
 *      information.
 */
- (IXCLRoutesCollection *) cachedRoutesWithOptions: (IXCLRoutesBaseOptions *) options
                                             error: (NSError **) error;

/*!
 * @abstract
 *      Replaces values in properties specified to use default values with the
 *      default values stored in the controller.
 */
- (void) replaceDefaultsInRequestOptions: (IXCLRoutesBaseOptions *) options;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoutesController
 * @abstract Controller for managing requests for routes.
 */
@interface IXCLRoutesController : IXCLBaseControllerWithCache<IXCLRoutesControllerProtocol>
@end
