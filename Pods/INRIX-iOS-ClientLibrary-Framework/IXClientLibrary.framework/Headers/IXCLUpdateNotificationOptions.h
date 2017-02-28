/*
 * @header IXCLUpdateNotificationOptions.h
 * @abstract The options class for the Trip Controller's update notification method.
 * @author Jeff White
 * @updated 07-07-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

#import "IXCLBaseOptions.h"
#import "IXCLCalendarTrip.h"

/*!
 * @class IXCLUpdateNotificationOptions
 *
 * @abstract
 *      Represents to options to the updatePreDriveNotification method in the trip controller.
 */
@interface IXCLUpdateNotificationOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract
 *      Calendar event ID unique per user.
 */
@property (nonatomic, strong, readonly) NSString * calendarEventId;

/*!
 * @abstract
 *      Is pre-drive alert enabled.
 */
@property (nonatomic, strong, readonly) NSNumber * preDriveAlertEnabled;

/*!
 * @abstract
 *      How far ahead of time user wants pre-drive alerts.
 */
@property (nonatomic, strong, readonly) NSNumber * preDriveAlertMinutes;

/*!
 * @abstract
 *      Initializes an instance of the IXCLUpdateNotificationOptions class with the
 *      calendar event ID, pre-drive alert enabled state, and pre-drive alert time to be saved.
 * @param
 *      calendarTrip The calendar event ID to be saved.
 * @param
 *      preDriveAlertEnabled The pre-drive alert enabled state to be saved.
 * @param
 *      preDriveAlertMinutes The pre-drive alert time to be saved.
 * @return
 *      An IXCLUpdateNotificationOptions object with the specific calendar event ID, pre-drive
 *      alert enabled state, and pre-drive alert time to be saved.
 */
- (instancetype) initWithCalendarTrip: (IXCLCalendarTrip *) calendarTrip
                 preDriveAlertEnabled: (NSNumber *) preDriveAlertEnabled
                 preDriveAlertMinutes: (NSNumber *) preDriveAlertMinutes;

/*!
 * @abstract
 *      Determines whether the combination of properties are valid.
 * @return
 *      NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end