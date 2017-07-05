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


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

FOUNDATION_EXPORT NSUInteger const IXCLMaxTripScheduleNotificationTime;

/*!
 * @class IXCLTripScheduleNotification
 *
 * @abstract
 *      Represents the notification properties of a saved trip schedule.
 */
@interface IXCLTripScheduleNotification : NSObject <NSCopying>

/*!
 * @abstract Indicates whether the schedule notification is enabled.
 */
@property (nonatomic, assign, readwrite) BOOL isEnabled;

/*!
 * @abstract
 *      An integer representing the time in minutes before the scheduled
 *      departure time when the notification will be issued. Has a maximum
 *      value of 60.
 */
@property (nonatomic, assign, readwrite) NSUInteger notificationTime;

/*!
 * @abstract Initializes an instance of the IXCLTripScheduleNotification class with notification times and enabled status.
 * @param time an integers representing the time in minutes before the scheduled departure time.
 * @param isEnabled Indicates whether the notification is initially enabled or disabled.
 * @return An initialized ScheduleNotification object.
 */
- (instancetype) initWithTime: (NSUInteger) time
                    isEnabled: (BOOL) isEnabled;

@end
