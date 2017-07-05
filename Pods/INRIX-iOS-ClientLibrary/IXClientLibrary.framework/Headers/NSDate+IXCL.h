/*
 * @header NSDate+IXCL.h
 * @abstract Category on the NSDate class adding methods helful for working with the IXCL.
 * @author Gaurav Agarwal
 * @updated 03-23-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Class Category Declaration

/*!
 * @category
 *      NSDate (IXCL)
 * @abstract
 *      Category on the NSDate class adding methods helpful for working with the
 *      IXCL.
 */
@interface NSDate (IXCL)

/*!
 * @abstract Compares two dates for equality.
 *
 * @param date An NSDate to compare.
 * @param anotherDate Another NSDate to compare with.
 *
 * @return YES if dates are equal; otherwise NO.
 */
+ (BOOL) ixcl_isDate: (NSDate *) date equalToDate: (NSDate *) anotherDate;

/*!
 * @abstract Determines if the date is earlier than another date.
 *
 * @param date An NSDate to compare with.
 *
 * @return YES if the date is earlier than the specified date; otherwise NO.
 */
- (BOOL) ixcl_isLessThanDate: (NSDate *) date;

/*!
 * @abstract Determines if the date is earlier or equal to another date.
 *
 * @param date An NSDate to compare with.
 *
 * @return YES if the date is earlier or equal to the specified date; otherwise NO.
 */
- (BOOL) ixcl_isLessThanOrEqualToDate: (NSDate *) date;

/*!
 * @abstract Test whether a date is between two dates.
 *
 * @param startDate
 *      Start date of range. This date must occur before endDate.
 * @param endDate
 *      End date of range. This date must occur after startDate.
 * @return YES if self is between startDate and endDate, NO otherwise.
 */
- (BOOL) ixcl_isBetweenDate: (NSDate *) startDate andDate: (NSDate *) endDate;

/*!
 * @abstract
 *      Constructs an NSDate from a string using a long format commonly used in
 *      Internet protocols such as HTTP.
 *
 * @param dateTimeString
 *      String that conforms to the following format:
 *      "yyyy'-'MM'-'dd'T'HH':'mm':'ss'Z'".
 *
 * @return
 *      NSDate constructed from the string.
 */
+ (NSDate *) ixcl_dateFromLongDateTimeInternetStyleString: (NSString *) dateTimeString;

/*!
 * @abstract
 *      Constructs an NSDate from a string and a format.
 *
 * @param dateTimeString
 *      The date string.
 *
 * @param format
 *      The format string.
 *
 * @return
 *      NSDate constructed from the string.
 */
+ (NSDate *) ixcl_dateFromInternetString: (NSString *) dateTimeString format:(NSString*)format;

/*!
 * @abstract
 *      Constructs an NSDate from a string using a short format.
 *
 * @param dateTimeString
 *      String that conforms to the following format: "MM'/'dd'/'yy' 'HH':'mm".
 *
 * @return
 *      NSDate constructed from the string.
 */
+ (NSDate *) ixcl_dateFromShortDateTimeString: (NSString *) dateTimeString;

/*!
 * @abstract
 *      Constructs a NSString from an NSDate using the following format:
 *      "yyyy'-'MM'-'dd'T'HH':'mm':'ss'Z'".
 *
 * @param date
 *      An NSDate object.
 *
 * @return
 *      NSString constructed from the NSDate.
 */
+ (NSString *) ixcl_dateToUTCString: (NSDate *) date;

/*!
 * @abstract
 *      Constructs an NSString from an NSDate using short format style for date
 *      and time.
 *
 * @param date
 *      An NSDate object.
 *
 * @return
 *      NSString constructed from the NSDate with date and time.
 */
+ (NSString *) ixcl_dateToShortDateTimeString: (NSDate *) date;

/*!
 * @abstract
 *      Constructs an NSString from an NSDate using short format style for date.
 *
 * @param date
 *      An NSDate object.
 *
 * @return
 *      NSString constructed from the NSDate with date.
 */
+ (NSString *) ixcl_dateToShortDateString: (NSDate *) date;

/*!
 * @abstract
 *      Constructs an NSString from an NSDate using short format style for
 *      time.
 *
 * @param date
 *      An NSDate object.
 *
 * @return
 *      NSString constructed from the NSDate with time.
 */
+ (NSString *) ixcl_dateToShortTimeString: (NSDate *) date;

/*!
 * @abstract Determine if two dates are in the same day.
 *
 * @param date An NSDate to compare.
 * @param anotherDate Another NSDate to compare with.
 *
 * @return YES if dates are in same day; otherwise NO.
 */
+ (BOOL) ixcl_isDate: (NSDate *) date sameDayToDate: (NSDate *) anotherDate;

/*!
 * @abstract Determine if the date is within one hour from current time.
 *
 * @param date An NSDate to compare.
 *
 * @return YES if date is within one hour from current date; otherwise NO.
 */
+ (BOOL) ixcl_isDateWithinNextHour: (NSDate *) date;

/*!
 * @abstract Return a new NSDate which begins at midnight on the given NSDate.
 * @param date Given date.
 * @return A new date at 12:00am on the given date.
 */
+ (NSDate *) ixcl_dateAtMidnight: (NSDate *) date;

/*!
 * @abstract Return a new NSDate object at midnight on a specified month, day
 *           and year.
 * @param month Month (1-12)
 * @param day   Day   (1-31)
 * @param year  Year  (XXXX) Four-digit year.
 * @return A new NSDate object or nil if none created.
 */
+ (NSDate *) ixcl_dateAtMidnightMonth: (NSInteger) month
                                  day: (NSInteger) day
                                 year: (NSInteger) year;

@end
