/*
 * @header IXCLTripSchedule.h
 * @abstract The Trip Schedule model object
 * @author Kent Lottis
 * @updated 03-02-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

/*!
 * @enum IXCLTripScheduleType
 * @abstract
 * Describes whether a trip schedule refers to the
 *      the desired departure time or arrival time.
 */
typedef NS_ENUM (NSUInteger, IXCLTripScheduleType)
{
    IXCLTripScheduleTypeArrival = 0,
    IXCLTripScheduleTypeDeparture
};

/*!
 * @enum IXCLTripScheduleWeekday
 * @abstract
 *      Represents the days of the week for use
 *      in recurring scheduled trips.
 * @discussion
 *      Recurring trips that occur on multiple days of the week
 *      can be expressed by bitwise OR-ing together multiple enum values.
 */
typedef NS_OPTIONS (NSUInteger, IXCLTripScheduleWeekday)
{
    IXCLTripScheduleWeekdayNone      = 0,
    IXCLTripScheduleWeekdaySunday    = (1 << 0),
    IXCLTripScheduleWeekdayMonday    = (1 << 1),
    IXCLTripScheduleWeekdayTuesday   = (1 << 2),
    IXCLTripScheduleWeekdayWednesday = (1 << 3),
    IXCLTripScheduleWeekdayThursday  = (1 << 4),
    IXCLTripScheduleWeekdayFriday    = (1 << 5),
    IXCLTripScheduleWeekdaySaturday  = (1 << 6),
};

/*!
 * @class IXCLTripScheduleDate
 *
 * @abstract
 *      Represents the date and time properties of a one-time trip.
 */
@interface IXCLTripScheduleDate : NSObject <NSCopying>

/*!
 * @abstract The base date for a scheduled trip.
 */
@property (nonatomic, strong, readwrite) NSDate * date;

/*!
 * @abstract Represents whether the scheduled is based on arrival or deperture time.
 *
 */
@property (nonatomic, assign, readwrite) IXCLTripScheduleType scheduleType;

/*!
 * @abstract Indicates whether the trip is recurring or not.
 *
 */
@property (nonatomic, assign, readwrite) BOOL isRecurring;

/*!
 * @abstract The days of the week on which a recurring scheduled trip should occur.
 *
 */
@property (nonatomic, assign, readwrite) IXCLTripScheduleWeekday weekdays;

/*!
 * @abstract Creates a one-time Trip Schedule with date and type information.
 * @param date The date and time for the scheduled trip.
 * @param scheduleType Indicates whether the trip date and time are for arrival or departure time.
 * @return An initialized ScheduleDate object.
 */
- (instancetype) initWithDate: (NSDate *) date
                 scheduleType: (IXCLTripScheduleType) scheduleType;
/*!
 * @abstract Creates a recurring Trip Schedule with date, type and weekday information.
 * @param weekdays Specifies the day or days of the week when the trip should happen.
 * @param date The date and time when the recurring trip takes effect.
 * @param scheduleType Indicates whether the date time are the departure or desired arrival time.
 * @return An initialized ScheduleDate object.
 */
- (instancetype) initWithRecurrence: (IXCLTripScheduleWeekday) weekdays
                               date: (NSDate *) date
                       scheduletype: (IXCLTripScheduleType) scheduleType;
@end
