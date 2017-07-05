/*
 * @header IXCLXDIncidentReoccurringSchedule.h
 * @abstract Model class for XD incident reoccurring schedules.
 * @author Steven Warkentin
 * @updated 04-30-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

/*!
 * @class IXCLXDIncidentReoccurringSchedule
 * @abstract Model object providing information on the schedule for
 *      an incident which reoccurs over time.
 */

@interface IXCLXDIncidentReoccurringSchedule : NSObject <NSCoding, NSCopying>

/*!
 * @abstract
 *      The reoccurence schedule for the incident.
 * @discussion
 *      The days of the week this incident reoccurs on.
 *      Ex. "Mon,Tue,Wed,Thu,Fri,Sat,Sun"
 */
@property (nonatomic, strong, readwrite) NSString * scheduleForDay;

/*!
 * @abstract
 *      The time from midnight UTC each reoccurance event starts.
 * @discussion
 *      This field is for repeating planned events, which may repeat
 *      often at the same time, e.g. roadwork at 9pm to 5am.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval reoccurringFrom;

/*!
 * @abstract
 *      The time from midnight UTC each reoccurance event lasts until.
 * @discussion
 *      This field is for repeating planned events, which may repeat
 *      often at the same time, e.g. roadwork at 9pm to 5am.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval reoccurringUntil;

/*!
 * @abstract
 *      If the incident is a planned event.
 */
@property (nonatomic, assign, readwrite) BOOL isPlanned;

/*!
 * @abstract
 *      If there is advance warning for the incident.
 */
@property (nonatomic, assign, readwrite) BOOL advanceWarning;

/*!
 * @abstract
 *      The date when occurences begin to occur.
 */
@property (nonatomic, strong, readwrite) NSDate * startTime;

/*!
 * @abstract
 *      The date when occurences stop occuring.
 */
@property (nonatomic, strong, readwrite) NSDate * endTime;

/*!
 * @abstract
 *      The descriptions for the occurrences, separate from the
 *      incident's general description.
 */
@property (nonatomic, strong, readwrite) NSString * occurrenceDescriptions;


/*!
 * @abstract
 *      Returns the start and end time for the incident on the day specified.
 * @param day
 *      Day of week to get the schedule for.  Sunday is 1, Saturday is 7.
 * @return
 *      NSArray containing the from and until times for the occurrence.
 * @discussion
 *      From/Until time is returned as two NSNumbers in an array; if the incident
 *      does not repeat on that day, nil is returned.  From is first in the array.
 *      The numbers corespond to the seconds since midnight UTC.
 */
- (NSArray *) getScheduleForDay: (NSInteger) day;

@end
