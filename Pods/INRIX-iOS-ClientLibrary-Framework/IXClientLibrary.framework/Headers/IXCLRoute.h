/*
 * @header IXCLRoute.h
 * @abstract
 *      Model object representing the root element of a route, containing
 *      information such as travel times, distance, and maneuvers.
 * @author Akvelon
 * @updated 10-20-2009
 * @copyright Copyright (c) 2009-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

@class CLLocation;
@class IXCLBoundingBox;
@class IXCLRouteSummary;


//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract Quality of the route, typically scaled from 0 (most congested) to 3 (least congested).
 *
 * @constant IXCLRouteQualityUnknown   Invalid or unrecognized type was assigned to the route quality.
 * @constant IXCLRouteQualityStopAndGo Travel time is greater than 175% of free flow traffic time.
 * @constant IXCLRouteQualityHeavy     Travel time is between 150% and 175% of free flow traffic time.
 * @constant IXCLRouteQualityModerate  Travel time is between 125% and 150% of free flow traffic time.
 * @constant IXCLRouteQualityFreeFlow  Travel time is less than 125% of free flow traffic time.
 * @constant IXCLRouteQualityClosed    Route is unusable due to a closure or restriction on the route.
 */
typedef NS_ENUM (NSInteger, IXCLRouteQuality)
{
    IXCLRouteQualityUnknown   = -1,
    IXCLRouteQualityStopAndGo = 0,
    IXCLRouteQualityHeavy     = 1,
    IXCLRouteQualityModerate  = 2,
    IXCLRouteQualityFreeFlow  = 3,
    IXCLRouteQualityClosed    = 255
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoute
 * @abstract
 *      Model object representing the root element of a route, containing
 *      information such as travel times, distance, and maneuvers.
 */
@interface IXCLRoute : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier of the route.
 */
@property (nonatomic, copy, readwrite) NSString * routeId;

/*!
 * @abstract The travel time, given no traffic congestion.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval uncongestedTravelTimeMinutes;

/*!
 * @abstract
 *      Quality of the route, typically scaled from 0 (most congested) to 3
 *      (least congested).
 */
@property (nonatomic, assign, readwrite) IXCLRouteQuality routeQuality;

/*!
 * @abstract
 *      A Boolean value indicating if there are road closures along the route.
 * @discussion
 *      If YES, then travel times will not be returned; otherwise travel times
 *      are returned.
 */
@property (nonatomic, assign, readwrite) BOOL hasClosures;

/*!
 * @abstract
 *      A Boolean value indicating if there are restrictions along the route.
 * @discussion
 *      A restriction could be times when traffic is not allowed to flow in a
 *      particular direction.  If YES, then travel times will not be returned;
 *      otherwise travel times are returned.
 */
@property (nonatomic, assign, readwrite) BOOL hasRestrictions;

/*!
 * @abstract
 *      The currently calculated travel time.
 * @discussion
 *      If there are road closures or restrictions along the route, the value
 *      will be 0 and you should call FindRoute to get a new route.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval travelTimeMinutes;

/*!
 * @abstract
 *      The difference in minutes between the travel time for the returned
 *      route and the normal travel time expected for the time and day.
 * @discussion
 *      If there are road closures along the route, the value will be 0.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval abnormalityMinutes;

/*!
 * @abstract
 *      The average speed on the route.
 * @discussion
 *      If there are road closures along the route, the value will be 0.
 */
@property (nonatomic, assign, readwrite) double averageSpeed;

/*!
 * @abstract
 *      A Boolean value indicating if traffic was used in calulating the route.
 */
@property (nonatomic, assign, readwrite) BOOL trafficConsidered;

/*!
 * @abstract The status ID for the request.
 */
@property (nonatomic, assign, readwrite) NSUInteger statusId;

/*!
 * @abstract
 *      The length of the route.
 * @discussion
 *      The units of this value will be in miles or kilometers depending on the
 *      value of the units property on the options object used to request the
 *      route.
 */
@property (nonatomic, assign, readwrite) double totalDistance;

/*!
 * @abstract Any waypoints along the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * waypoints;

/*!
 * @abstract Information about the roads used in the route.
 */
@property (nonatomic, strong, readwrite) IXCLRouteSummary * routeSummary;

/*!
 * @abstract Route points encoded as polyline.
 */
@property (nonatomic, strong, readwrite) NSString * compressionPoints;

/*!
 * @abstract The points in the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * points;

/*!
 * @abstract Coordinates of the rectangular region of the route.
 */
@property (nonatomic, strong, readwrite) IXCLBoundingBox * boundingBox;

/*!
 * @abstract Incident information (if any) on the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * incidents;

/*!
 * @abstract Speed buckets associated with the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * speedBuckets;

/*!
 * @abstract Original cached speed buckets associated with the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * originalSpeedBuckets;

/*!
 * @abstract
 *      Returns estimated arrival time calculated by adding travelTimeMinutes
 *      to current NSDate.
 */
@property (nonatomic, weak, readonly) NSDate * estimatedArrivalTime;

/*!
 * @abstract Returns estimatedArrivalTime as string in "h':'mm aaa" format.
 */
@property (nonatomic, weak, readonly) NSString * estimatedArrivalTimeString;

/*!
 * @abstract Returns week of the day for estimatedArrivalTime.
 */
@property (nonatomic, weak, readonly) NSString * estimatedArrivalDayString;

/*!
 * @abstract Returns travel time in formatted in days, hours and minutes.
 */
@property (nonatomic, weak, readonly) NSString * shortTravelTimeString;

/*!
 * @abstract The date this IXCLRoute object was created.
 */
@property (nonatomic, strong, readwrite) NSDate * creationDate;

/*!
 * @abstract The origin that was originally requested for this route.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D requestOrigin;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns the estimated arrival time for given departure date.
 * @discussion
 *      This is calculated by adding travelTimeMinutes to given departureDate.
 *
 * @param departureDate
 *      NSDate for departure.
 *
 * @return
 *      The estimated arrival time as a NSDate object.
 */
- (NSDate *) estimatedArrivalTimeForDate: (NSDate *) departureDate;

/*!
 * @abstract
 *      Returns the estimated arrival time as string in "h':'mm aaa" format for
 *      given departure date.
 * @discussion
 *      This is calculated by adding travelTimeMinutes to given departureDate.
 *
 * @param departureDate
 *      The departure time as an NSDate object.
 *
 * @return
 *      NSDate.
 */
- (NSString *) estimatedArrivalTimeStringForDate: (NSDate *) departureDate;

/*!
 * @abstract
 *      Returns the estimated arrival time as string in
 *      NSDateFormatterShortStyle (e.g. 3:30pm) format for given departure date.
 * @discussion
 *      This is calculated by adding travelTimeMinutes to given departureDate.
 *
 * @param departureDate
 *      The departure date and time.
 *
 * @return
 *      A formatted string with the departure date.
 */
- (NSString *) shortEstimatedArrivalTimeStringForDate: (NSDate *) departureDate;

@end
