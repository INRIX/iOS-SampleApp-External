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

#import "IXCLTripScheduleDate.h"
#import "IXCLTripScheduleNotification.h"

/*!
 * @class IXCLTripSchedule
 *
 * @abstract
 *      Represents the schedule information for a saved trip.
 */
@interface IXCLTripSchedule : NSObject <NSCopying>

/*!
 * @abstract Represents the notification times for the trip.
 */
@property (nonatomic, strong, readwrite) IXCLTripScheduleNotification * notification;

/*!
 * @abstract Represents the scheduling times for the trip.
 */
@property (nonatomic, strong, readwrite) IXCLTripScheduleDate * date;

/*!
 * @abstract Initializes an instance of the IXCLTripSchedule class with date and notification information.
 * @param date The date and time for the trip departure or arrival time.
 * @param notification Describes the notifications to be issues for the scheduled trip.
 * @return An initialized TripSchedule object.
 */
- (instancetype) initWithDateAndNotification: (IXCLTripScheduleDate *) date
                        scheduleNotification: (IXCLTripScheduleNotification *) notification;

@end
