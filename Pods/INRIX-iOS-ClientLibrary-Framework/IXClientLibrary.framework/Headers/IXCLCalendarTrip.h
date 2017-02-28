/*
 * @header IXCLCalendarTrip.h
 * @abstract The CalendarTrip model object.
 * @author Jeff White
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
#import "IXCLTripPoint.h"

/*!
 * @class IXCLCalendarTrip
 *
 * @abstract Represents the geometry and scheduling properties of trip inferred
 *          from a synched Calendar event.
 */
@interface IXCLCalendarTrip : IXCLTrip

/*!
 * @abstract
 *      The location of the calendar event associated with this trip.
 */
@property (nonatomic, strong, readonly, null_unspecified) IXCLTripPoint * destination;

/*!
 * @abstract
 *      The title of the calendar event associated with this trip. Can be null.
 */
@property (nonatomic, strong, readonly, nullable) NSString * subject;

/*!
 * @abstract
 *      The start date and time of the calendar event associated with this trip.
 */
@property (nonatomic, strong, readonly, null_unspecified) NSDate * startDate;

/*!
 * @abstract
 *      Length of the calendar trip event in seconds.
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/*!
 * @abstract
 *      Specificies the time zone for the start date/time of this trip.
 */
@property (nonatomic, strong, readonly, null_unspecified) NSTimeZone * timeZone;

/*!
 * @abstract
 *      Indicates whether this is a recurring trip.
 */
@property (nonatomic, assign, readonly) BOOL isRecurring;

/*!
 * @abstract
 *      Indicates whether pre-drive notifications are enabled for this trip.
 */
@property (nonatomic, assign, readwrite) BOOL isPreDriveNotificationEnabled;

/*!
 * @abstract
 *      Specifies the notification time before the expected departure for this trip.
 */
@property (nonatomic, assign, readwrite) NSUInteger preDriveNotificationMinutes;

@end
