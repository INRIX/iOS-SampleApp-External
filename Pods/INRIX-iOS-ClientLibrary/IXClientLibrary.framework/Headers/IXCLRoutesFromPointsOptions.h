/*
 * @header IXCLRoutesFromPointsOptions.h
 * @abstract
 *      Represents request parameters for calls that obtain routes based on
 *      route coordinates.
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


//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract
 *      Represents the maximum number of intermediate waypoints for a route.
 * @discussion
 *      Value is 8.
 */
FOUNDATION_EXPORT NSUInteger const IXCLRouteOptionsIntermediateWaypointsMaxCount;

/*!
 * @abstract
 *      Value which indicates that the default value stored in the
 *      defaultOptionsIncludeSpeedBuckets property on IXCLRoutesController
 *      should be used.
 */
FOUNDATION_EXPORT BOOL const IXCLRouteOptionsIncludeSpeedBucketsUseDefault;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      Any avoidance criteria which should be considered in calculating the route.
 * @discussion
 *      More than one options can be specified by using ',' operator.
 *
 * @constant IXCLRouteOptionsCriteriaMaskNoRestrictions
 *      No restrictions while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskAvoidTollRoads
 *      Avoid toll roads while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskAvoidHighways
 *      Avoid highways while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskAvoidFerries
 *      Avoid ferries while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskAvoidVignette
 *      Avoid vignette (road toll subscription) while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskPreferExpress
 *      Prefer express while calculating routes.
 * @constant IXCLRouteOptionsCriteriaMaskPreferCarPool
 *      Prefer carpool while calculating routes.
 */
typedef NS_OPTIONS (NSUInteger, IXCLRouteOptionsCriteriaMask)
{
    IXCLRouteOptionsCriteriaMaskUseDefault = 0,

    IXCLRouteOptionsCriteriaMaskNoRestrictions = (1 << 0),
    IXCLRouteOptionsCriteriaMaskAvoidTollRoads = (1 << 1),
    IXCLRouteOptionsCriteriaMaskAvoidHighways  = (1 << 2),
    IXCLRouteOptionsCriteriaMaskAvoidFerries   = (1 << 3),
    IXCLRouteOptionsCriteriaMaskAvoidVignette  = (1 << 4),
    IXCLRouteOptionsCriteriaMaskPreferExpress  = (1 << 5),
    IXCLRouteOptionsCriteriaMaskPreferCarPool  = (1 << 6),
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoutesFromPointsOptions
 * @abstract
 *      Represents request parameters for calls that obtain routes based on
 *      route coordinates.
 */
@interface IXCLRoutesFromPointsOptions : IXCLRoutesBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      A starting waypoint.
 * @discussion
 *      This first point can also take a position-heading-speed (PHS) record.
 *      Heading is used to determine best route, this is important for
 *      non-divided (non-freeway/motorway/expressway) roads.
 */
@property (nonatomic, strong, readwrite) CLLocation * startPoint;

/*!
 * @abstract An end waypoint.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D endPoint;

/*!
 * @abstract
 *      The intermediate IXCLRoutePoints used to calculate the route.
 * @discussion
 *      Route can have maximumum of 8 intermediate waypoints.
 */
@property (nonatomic, strong, readwrite) NSArray * intermediateWaypoints;

/*!
 * @abstract The criteria for this route find request.
 * @discussion Defaults to IXCLRouteOptionsCriteriaUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsCriteriaMask criteriaMask;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLRoutesFromPointsOptions with the specified start and
 *      end points.
 *
 * @param startPoint The starting waypoint.
 * @param endPoint  The end waypoint.
 *
 * @return Instance of the IXCLRoutesFromPointsOptions class.
 */
- (instancetype) initWithStartPoint: (CLLocation *) startPoint
                           endPoint: (CLLocationCoordinate2D) endPoint;

/*!
 * @abstract
 *      Returns IXCLRouteOptionsCriteriaMask as string to be used in the server
 *      request.
 *
 * @return
 *      NSString.
 */
- (NSString *) criteriaMaskAsString;

/*!
 * @abstract
 *      Creates a key to be used for the cache.
 * @discussion
 *      Sublasses of this base class should implment this method.
 *
 * @return
 *      A string that uniquely identifies the request identified in this
 *      option.
 */
- (NSString *) keyForCacheEntry;

@end
