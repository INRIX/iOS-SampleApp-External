/*
 * @header IXCLRouteTrackingSearch.h
 * @abstract
 *      Controller for tracking along a route and searching for points along
 *      the route
 * @author Douglas Lanford
 * @updated 04-02-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLPointQuadTree.h"

@class IXCLCore;
@class IXCLRoute;
@class IXCLRoutePoint;
@class IXCLSphericalMercatorProjection;


//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      Status of progression of current drive along a route.
 *
 * @constant IXCLRouteTrackingStatusUndefined Route status is not determined.
 * @constant IXCLRouteTrackingStatusAtStart User is at start of route.
 * @constant IXCLRouteTrackingStatusOnRoute Use is driving along route.
 * @constant IXCLRouteTrackingStatusAtDestination User is at end of route.
 * @constant IXCLRouteTrackingStatusOffRoute Use has driven off route.
 */
typedef NS_ENUM (NSUInteger, IXCLRouteTrackingStatus)
{
    IXCLRouteTrackingStatusUndefined = 0,
    IXCLRouteTrackingStatusAtStart,
    IXCLRouteTrackingStatusOnRoute,
    IXCLRouteTrackingStatusAtDestination,
    IXCLRouteTrackingStatusOffRoute,
};

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Route points are interploated if distance between them is greater than
 *      this threshold.
 * @discussion Value is 150 meters.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLRouteTrackingDefaultInterpolationDistanceThresholdInMeters;

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLRouteTrackingSearch : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Route tracked by this controller.
 */
@property (nonatomic, strong, readonly) IXCLRoute * route;

/*!
 * @abstract Map projection used by this controller.
 */
@property (nonatomic, strong, readonly) IXCLSphericalMercatorProjection * sphericalMercatorProjection;

/*!
 * @abstract Point quad tree storing the interpolated route points.
 */
@property (nonatomic, strong, readwrite) IXCLPointQuadTree * pointQuadTree;

/*!
 * @abstract
 *      Interpolated route points.
 * @discussion
 *      Route points are interploated if distance between them is greater
 *      than IXCLRouteTrackingDefaultInterpolationDistanceThresholdInMeters.
 */
@property (nonatomic, strong, readwrite) NSArray * interpolatedRoutePoints;

/*!
 * @abstract
 *      Interpolated distance threshold in meters.
 * @discussion
 *      Two route points are interpolated if they are more than this threshold
 *      apart.
 *      Default value is:
 *          IXCLRouteTrackingDefaultInterpolationDistanceThresholdInMeters.
 */
@property (nonatomic, assign, readwrite) CLLocationDistance interpolationDistanceThreshold;

/*!
 * @abstract
 *      flag for if the search controller is currently tracking
 */
@property (nonatomic, assign, readwrite) BOOL isTracking;


/*!
 * @abstract
 *      The sum of the distances between the interpolated route points.
 */
@property (nonatomic, assign, readonly) CLLocationDistance routeLength;

//-----------------------------------------------------------------------------
#pragma mark - Init Methods

- (instancetype) initWithRoute: (IXCLRoute *) route;

//-----------------------------------------------------------------------------
#pragma mark - Public Methods

/*!
 * @abstract
 *      Starts tracking the route (sets up the search controller for searching)
 */
- (void) startRouteTracking;

/*!
 * @abstract
 *      Stops tracking the route.
 */
- (void) stopRouteTracking;

/*!
 * @abstract
 *      Return a list of route points that are within a threshold distance of
 *      an input coordinate
 *
 * @param coordinate
 *      coordinate to search from
 * @param threshold
 *      distance threshold to check within
 *
 * @return array of searched points along the route
 */
- (NSArray *) searchCoordinate: (CLLocationCoordinate2D) coordinate
                 withThreshold: (CLLocationDistance) threshold;

/*!
 * @abstract
 *      Return the status of a point along this route (at start, at end,
 *      off-route, etc.)
 *
 * @param coordinate
 *      coordinate to search from
 * @param threshold
 *      distance threshold to route
 * @param youAreHereThreshold
 *      endpoint distance threshold (distance to start/end of route)
 *
 * @return status of the input coordinate
 */
- (IXCLRouteTrackingStatus) statusForCoordinate: (CLLocationCoordinate2D) coordinate
                                  withThreshold: (CLLocationDistance) threshold
                            youAreHereThreshold: (CLLocationDistance) youAreHereThreshold;

/*!
 * @abstract
 *      Calculates distance between two route points by their sequence numbers.
 *
 * @param sequence1 Sequence number of the first route point.
 * @param sequence2 Sequence number of the second route point.
 *
 * @return Distance between two route points.
 */
- (CLLocationDistance) distanceOnRouteBetweenSequence1: (NSUInteger) sequence1
                                          andSequence2: (NSUInteger) sequence2;

/*!
 * @abstract
 *      Return the closest route point to an input point
 *
 * @param coordinate
 *      coordinate to search from
 * @param threshold
 *      distance threshold to route
 *
 * @return closest route point
 */
- (IXCLRoutePoint *) closestRoutePointToCoordinate: (CLLocationCoordinate2D) coordinate
                                     withThreshold: (CLLocationDistance) threshold;

/*!
 * @abstract
 *      Gets the distance along the route start of the route to the current point.
 *
 * @param coordinate
 *      Coordinate to search from.
 * @param threshold
 *      Distance threshold to route.
 *
 * @return Distance along the route. Returns CLLocationDistanceMax if point is not on the route.
 */
- (CLLocationDistance) distanceFromStartforCoordinate: (CLLocationCoordinate2D) coordinate
                                        withThreshold: (CLLocationDistance) threshold;

//-----------------------------------------------------------------------------
#pragma mark - Public Class Methods

/*!
 * @abstract
 *      Returns true if the input coordinate is along the input route
 * @discussion
 *      This creates a route tracking search object for the input route, starts
 *      tracking, and gets the status of the point against the route (using the
 *      search object). It returns YES if the calculated status is not
 *      "off-route" or "undefined".
 * @param coordinate
 *      The coordinate to check against the input route
 * @param route
 *      The route to search
 * @param threshold
 *      distance threshold to route
 * @param youAreHereThreshold
 *      endpoint distance threshold (distance to start/end of route)
 *
 * @return
 *      Whether or not the coordinate is on the route.
 */
+ (BOOL)   isCoordinate: (CLLocationCoordinate2D) coordinate
                onRoute: (IXCLRoute *) route
          withThreshold: (CLLocationDistance) threshold
    youAreHereThreshold: (CLLocationDistance) youAreHereThreshold;

/*!
 * @abstract
 *      Returns the status of a coordinate on a route.
 * @discussion
 *      This creates a route tracking search object for the input route, starts
 *      tracking, and gets the status of the point against the route (using the
 *      search object). It returns the IXCLRouteTrackingStatus for the point.
 * @param coordinate
 *      The coordinate to check against the input route
 * @param route
 *      The route to search
 * @param threshold
 *      distance threshold to route
 * @param youAreHereThreshold
 *      endpoint distance threshold (distance to start/end of route)
 *
 * @return
 *      IXCLRouteTrackingStatus for the coordinate on the route.
 */
+ (IXCLRouteTrackingStatus) statusForCoordinate: (CLLocationCoordinate2D) coordinate
                                        onRoute: (IXCLRoute *) route
                                  withThreshold: (CLLocationDistance) threshold
                            youAreHereThreshold: (CLLocationDistance) youAreHereThreshold;

@end
