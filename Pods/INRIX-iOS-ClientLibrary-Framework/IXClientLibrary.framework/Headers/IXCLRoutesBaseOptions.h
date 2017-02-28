/*
 * @header IXCLRoutesBaseOptions.h
 * @abstract Represents common request parameters for route calls.
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


#import "IXCLBaseOptions.h"
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract
 *      Value which indicates that the default value stored in the
 *      defaultOptionsUseTraffic property on IXCLRoutesController should be
 *      used.
 */
FOUNDATION_EXPORT BOOL const IXCLRouteOptionsUseTrafficUseDefault;

/*!
 * @abstract
 *      Value which indicates that the default geometry tolerance stored in the
 *      defaultOptionsGeometryTolerance property on IXCLRoutesController
 *      should be used.
 */
FOUNDATION_EXPORT NSUInteger const IXCLRouteOptionsGeometryToleranceUseDefault;

/*!
 * @abstract
 *      Value which indicates that the default value stored in the
 *      defaultOptionsCollapseManeuvers property on IXCLRoutesController should
 *      be used.
 */
FOUNDATION_EXPORT BOOL const IXCLRouteOptionsCollapseManeuversUseDefault;

/*!
 * @abstract
 *      Represents the minimum value for departure time.
 * @discussion
 *      Value is -3600, i.e. departure time can be 1 hour before the current
 *      time.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLRouteOptionsDepartureTimeMin;

/*!
 * @abstract
 *      Represents the maximum value for departure time.
 * @discussion
 *      Its value is 31536000, i.e. departure time must be within one year in
 *      the future.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLRouteOptionsDepartureTimeMax;

/*!
 * @abstract
 *      Represents the minimum value for arrival time.
 * @discussion
 *      Value is -3600, i.e. arrival time can be 1 hour before the current
 *      time.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLRouteOptionsArrivalTimeMin;

/*!
 * @abstract
 *      Represents the maximum value for arrival time.
 * @discussion
 *      Its value is 31536000, i.e. arrival time must be within one year in
 *      the future.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLRouteOptionsArrivalTimeMax;

/*!
 * @abstract
 *      Represents the minimum value for number of alternate routes calculated.
 * @discussion
 *      Value is 0.
 */
FOUNDATION_EXPORT NSUInteger const IXCLRouteOptionsMaxAlternatesMin;

/*!
 * @abstract
 *      Represents the maximum value for number of alternate routes calculated.
 * @discussion
 *      Value is 2.
 */
FOUNDATION_EXPORT NSUInteger const IXCLRouteOptionsMaxAlternatesMax;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      The type of route requested, fastest or shortest.
 * @discussion
 *      If IXCLRouteOptionsTypeShortest is specified, useTraffic is ignored.
 *
 * @constant IXCLRouteOptionsTypeUseDefault
 *      The default type specified by the defaultRouteType property on
 *      IXCLRoutesController.
 * @constant IXCLRouteOptionsTypeFastest
 *      The fastest route.
 * @constant IXCLRouteOptionsTypeShortest
 *      The shortest route.
 */
typedef NS_ENUM (NSUInteger, IXCLRouteOptionsType)
{
    IXCLRouteOptionsTypeUseDefault = -1,

    IXCLRouteOptionsTypeFastest  = 0,
    IXCLRouteOptionsTypeShortest = 1
};

/*!
 * @abstract
 *      The unit in which distances in route should be returned in the server
 *      response.
 *
 * @constant IXCLRouteOptionsDistanceUnitsUseDefault
 *      The default distance units specified by the defaultDistanceUnitsType
 *      property on IXCLRoutesController.
 * @constant IXCLRouteOptionsDistanceUnitsMiles
 *      Distances in miles.
 * @constant IXCLRouteOptionsDistanceUnitsMeters
 *      Distances in meters.
 */
typedef NS_ENUM (NSUInteger, IXCLRouteOptionsDistanceUnitsType)
{
    IXCLRouteOptionsDistanceUnitsUseDefault = -1,

    IXCLRouteOptionsDistanceUnitsMiles  = 0,
    IXCLRouteOptionsDistanceUnitsMeters = 1
};

/*!
 * @abstract
 *      Specifies the route elements to send in the server response.
 * @discussion
 *      More than one options can be specified by using | operator.
 *
 * @constant IXCLRouteOptionsOutputFieldsUseDefault
 *      The default output fields specified by the defaultOutputFields
 *      property on IXCLRoutsController.
 * @constant IXCLRouteOptionsOutputFieldMaskDescription
 *      The textual descriptions of the trip and route.
 * @constant IXCLRouteOptionsOutputFieldMaskSummary
 *      The route summary contains a high level summary of the major roads on
 *      the route.
 * @constant IXCLRouteOptionsOutputFieldMaskWaypoints
 *      The waypoints used to calculate the route.
 * @constant IXCLRouteOptionsOutputFieldMaskBoundingBox
 *      The geographical bounding box of the entire route.
 * @constant IXCLRouteOptionsOutputFieldMaskPoints
 *      A list of points along the route, returned in latitude/longitude pairs.
 * @constant IXCLRouteOptionsOutputFieldMaskIncidents
 *      A list of any incidents occuring on the route.
 * @constant IXCLRouteOptionsOutputFieldMaskAll
 *      Returns all fields.
 */
typedef NS_OPTIONS (NSUInteger, IXCLRouteOptionsOutputFieldsMask)
{
    IXCLRouteOptionsOutputFieldsUseDefault = 0,

    IXCLRouteOptionsOutputFieldMaskDescription = (1 << 0),
    IXCLRouteOptionsOutputFieldMaskSummary     = (1 << 1),
    IXCLRouteOptionsOutputFieldMaskWaypoints   = (1 << 2),
    IXCLRouteOptionsOutputFieldMaskBoundingBox = (1 << 3),
    IXCLRouteOptionsOutputFieldMaskPoints      = (1 << 4),
    IXCLRouteOptionsOutputFieldMaskIncidents   = (1 << 5),
    IXCLRouteOptionsOutputFieldMaskAll         = (IXCLRouteOptionsOutputFieldMaskDescription |
                                                  IXCLRouteOptionsOutputFieldMaskSummary |
                                                  IXCLRouteOptionsOutputFieldMaskWaypoints |
                                                  IXCLRouteOptionsOutputFieldMaskBoundingBox |
                                                  IXCLRouteOptionsOutputFieldMaskPoints |
                                                  IXCLRouteOptionsOutputFieldMaskIncidents),
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoutesBaseOptions
 * @abstract Represents common request parameters for route calls.
 */
@interface IXCLRoutesBaseOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The time of departure.
 * @discussion
 *      Defaults to “now” if not specified. DepartureTime must be within one
 *      year from the time of the API call, and must occur in the future.  The
 *      date format must be in the form YYYY-MM-DDTHH:MM:SSZ; for example
 *      2009-04-04T13:42:41Z.
 */
@property (nonatomic, strong, readwrite) NSDate * departureTime;

/*!
 * @abstract
 *      The time of arrival.
 * @discussion
 *      Ignored if DepartureTime is specified. ArrivalTime must be within one
 *      year from the time of the API call, and must occur in the future. The
 *      date format must be in the form YYYY-MM-DDTHH:MM:SSZ; for example
 *      2009-04-04T13:42:41Z.
 */
@property (nonatomic, strong, readwrite) NSDate * arrivalTime;

/*!
 * @abstract
 *      A Boolean value indicating if traffic flow is used in calculating the
 *      route.
 * @discussion
 *      Defaults to IXCLRouteOptionsUseTrafficUseDefault. Ignored if RouteType
 *      is IXCLRouteOptionsTypeShortest.
 */
@property (nonatomic, assign, readwrite) BOOL useTraffic;

/*!
 * @abstract
 *      The type of route to return.
 * @discussion
 *      Defaults to IXCLRouteOptionsTypeUseDefault. If
 *      IXCLRouteOptionsTypeShortest is specified, useTraffic is ignored.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsType routeType;

/*!
 * @abstract The units to use for distances in the request and the response.
 * @discussion Defaults to IXCLRouteOptionsDistanceUnitsUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsDistanceUnitsType distanceUnits;

/*!
 * @abstract The route elements to return in the response.
 * @discussion Defaults to IXCLRouteOptionsOutputFieldsUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsOutputFieldsMask routeOutputFieldsMask;

/*!
 * @abstract
 *      Specifies the desired detail of the route in yards or meters.
 * @discussion
 *      This property is used to reduce the number of latitude/longitude points
 *      returned when describing a route when
 *      IXCLRouteOptionsOutputFieldMaskPoints is specified in the
 *      routeOutputFieldsMask property.  This value should be greater than or
 *      equal to 0 and is specified in yards for English units and meters for
 *      metric units.  Defaults to 0, which means exact (no inaccuracy is
 *      tolerated), and results in the entire Points set being returned when
 *      points are requested in the output field.  Higher values will reduce
 *      the number of points by eliminating points whose distance from each
 *      other is less than the specified tolerance.  Based on the level
 *      of zoom used to draw the map, you can save bandwidth by reducing
 *      the size of the return payload.  For example, if the map is zoomed
 *      to a 300-mile level, you may want to return fewer data points.
 *      Defaults to IXCLRouteOptionsGeometryToleranceUseDefault.
 */
@property (nonatomic, assign, readwrite) NSUInteger geometryTolerance;

/*!
 * @abstract
 *      A Boolean value indicating if maneuvers are collapsed for routes.
 * @discussion
 *      Defaults to YES.
 */
@property (nonatomic, assign, readwrite) BOOL collapseManeuvers;

/*!
 * @abstract
 *      A Boolean value indicating if routes are forced to be loaded if they
 *      exceed the maximum route distance limit.
 * @discussion
 *      Defaults to NO.
 */
@property (nonatomic, assign, readwrite) BOOL overrideMaxDistance;

/*!
 * @abstract
 *      A Boolean value indicating if speed buckets are enabled in the
 *      request for route.
 * @discussion
 *      Defaults to NO.
 */
@property (nonatomic, assign, readwrite) BOOL includeSpeedBuckets;

/*!
 * @abstract
 *      The number of alternate routes calculated.
 * @discussion
 *      By default, only one route is returned, but you can request up to 2
 *      alternates.  If all the routes have closures and cannot be driven, the
 *      third route returned is replaced with a fastest traffic-aware route
 *      that is navigable.  In other words, no matter what the conditions are
 *      on the primary (and maybe secondary) routes, the API request always
 *      returns at least one navigable route.
 */
@property (nonatomic, assign, readwrite) NSUInteger maxAlternates;

/*!
 * @abstract
 *      The original coordinate the route is being requested out.
 * @discussion
 *      Defaults to kCLLocationCoordinate2DInvalid.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D requestOrigin;


//-----------------------------------------------------------------------------
#pragma mark - Methods

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

/*!
 * @abstract
 *      Returns IXCLRouteOptionsOutputFieldsMask as string to be used in the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) routeOutputFieldsMaskAsString;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
