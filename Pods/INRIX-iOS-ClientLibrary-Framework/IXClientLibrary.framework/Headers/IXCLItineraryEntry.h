/*
 * @header IXCLItineraryEntry.h
 * @abstract The Itinerary Item model object.
 * @author Kent Lottis
 * @updated 06-24-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

#import "IXCLTrip.h"
#import "IXCLTripSchedule.h"

/*!
 * @enum IXCLTripType
 * @abstract
 * Describes what kind of a @ref IXCLTrip is described by the itinerary entry
 */
typedef NS_ENUM (NSUInteger, IXCLTripType)
{
    IXCLTripTypeSaved = 0,
    IXCLTripTypeLearned,
    IXCLTripTypeCalendar
};


/*!
 * @class IXCLItineraryEntry
 *
 * @abstract
 *      Represents an itinerary which may contain itinerary infomation and trips.
 */
@interface IXCLItineraryEntry : NSObject <NSCopying>


/*!
 * @abstract The date/time of this trip instance (UTC).
 */
@property (nonatomic, strong, readonly) NSDate * dateTime;

/*!
 * @abstract The final destination of the trip.
 */
@property (nonatomic, strong, readonly) IXCLTripPoint * destination;

/*!
 * @abstract An array of @ref IXCLTripPoint objects representing
 *      the expected origins of the trip.
 */
@property (nonatomic, strong, readonly) NSArray * expectedOrigins;

/*!
 * @abstract
 *      The time in minutes before the scheduled
 *      departure time when the notification will be issued.
 */
@property (nonatomic, assign, readonly) NSUInteger notificationTime;

/*!
 * @abstract
 *      Represents whether the scheduled is based on arrival or departure time.
 */
@property (nonatomic, assign, readonly) IXCLTripScheduleType scheduleType;

/*!
 * @abstract The type of a trip which this itinerary entry was created from.
 */
@property (nonatomic, assign, readonly) IXCLTripType tripType;

/*!
 * @abstract The trip represented by this itinerary entry.
 */
@property (nonatomic, strong, readonly) IXCLTrip * trip;

/*!
 * @abstract The ordered list of waypoints along the trip.
 */
@property (nonatomic, strong, readonly) NSArray * wayPoints;
/*!
 * @abstract
 *      Indicates if the driver will need to stop for fuel to complete
 *      this trip.
 */
@property (nonatomic, assign, readonly) BOOL isFuelRequired;

/*!
 * @abstract Indicates whether the schedule notification is enabled.
 */
@property (nonatomic, assign, readonly) BOOL isNotificationEnabled;

/*!
 * @abstract List of Trips which are associated with this ItineraryEntry
 */
@property (nonatomic, strong, readonly) NSArray * associatedTrips;

@end
