/*
 * @header IXCLTravelTimesOptions.h
 * @abstract Represents request parameters for route travel times call.
 * @author Gaurav Agarwal
 * @updated 03-04-2014
 * @copyright Copyright (c) 2009-2015 INRIX, Inc.
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
#pragma mark Global Exports

/*!
 * @abstract
 *      Represents the minimum value for departure time.
 * @discussion
 *      Value is -3600, meaning the. departure time can be 1 hour before the
 *      current time.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLTravelTimesDepartureTimeMinTimeInterval;

/*!
 * @abstract
 *      Represents the maximum value for departure time.
 * @discussion
 *      Value is 31536000, meaning departure time must be within one year in
 *      future.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLTravelTimesDepartureTimeMaxTimeInterval;

/*!
 * @abstract
 *      Represents the minimum value for arrival time.
 * @discussion
 *      Value is -3600, meaning the. arrival time can be 1 hour before the
 *      current time.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLTravelTimesArrivalTimeMinTimeInterval;

/*!
 * @abstract
 *      Represents the maximum value for arrival time.
 * @discussion
 *      Value is 31536000, meaning arrival time must be within one year in
 *      future.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLTravelTimesArrivalTimeMaxTimeInterval;

/*!
 * @abstract Represents the minimum value for travel time count.
 * @discussion Value is 1.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTravelTimeCountMin;

/*!
 * @abstract Represents the maximum value for travel time count.
 * @discussion Value is 96.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTravelTimeCountMax;

/*!
 * @abstract Represents the minimum value for travel time timerval.
 * @discussion Value is 1.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTravelTimeIntervalMin;

/*!
 * @abstract Represents the minimum value for travel time interval.
 * @discussion Value is 1440.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTravelTimeIntervalMax;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTravelTimesOptions
 * @abstract
 *      Represents request parameters for route travel times call.
 * @discussion
 *      Travel times consist of a count (the number of travel times from the
 *      departure time into the future) and an interval (time span between each
 *      travel time).
 */
@interface IXCLTravelTimesOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract A valid route ID from which to return traffic and routing information.
 */
@property (nonatomic, strong, readwrite) NSString * routeId;

/*!
 * @abstract
 *      The time of departure.
 * @discussion
 *      Defaults to “now” if not specified. DepartureTime must be within one
 *      year from the time of the API call, and must occur in the future. The
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
 *      The number of travel times you want to be returned for this route.
 * @discussion
 *      Must be a value greater than 0, but less than or equal to 96.  Defaults
 *      to IXCLTravelTimeCountMin.
 */
@property (nonatomic, assign, readwrite) NSUInteger travelTimeCount;

/*!
 * @abstract
 *      The time span between the travel times specified in travelTimeCount.
 * @discussion
 *      Must be a value greater than 0, but less than or equal to 1440 minutes.
 *      Defaults to IXCLTravelTimeIntervalMin.
 */
@property (nonatomic, assign, readwrite) NSUInteger travelTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes the IXCLTravelTimesOptions with specified route ID.
 *
 * @param routeId A valid route ID.
 *
 * @return Instance of the IXCLTravelTimesOptions class.
 */
- (instancetype) initWithRouteId: (NSString *) routeId;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
