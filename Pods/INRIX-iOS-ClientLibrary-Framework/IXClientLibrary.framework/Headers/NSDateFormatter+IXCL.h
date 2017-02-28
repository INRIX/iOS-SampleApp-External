/*
 * @header NSDateFormatter+IXCL.h
 * @abstract Category on the NSDateFormatter class with functionality useful to the IXCL.
 * @author David Potter
 * @updated 06-18-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface NSDateFormatter (IXCL)

/*!
 * @abstract
 *      Configures the NSDateFormatter to format Internet-style dates.
 * @discussion
 *      Sets the locale to en_US_POSIX, sets the calendar to Gregorian, and
 *      sets the time zone to GMT.  This is useful when parsing dates embedded
 *      in a protocol like HTTP, or when a single standard date format is
 *      desired.
 *
 *  https://devforums.apple.com/message/170171#170171
 *  https://developer.apple.com/library/ios/qa/qa1480/_index.html
 */
- (void) ixcl_configureForInternetStyleDates;

@end
