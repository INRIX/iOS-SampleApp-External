/*
 * @header IXCLParkingStructuredRate.h
 * @author Patrick Winchell
 * @updated 12-08-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSUInteger, IXCLParkingDayOfWeek)
{
    IXCLParkingDayOfWeekMonday              = 1,
    IXCLParkingDayOfWeekTuesday             = 2,
    IXCLParkingDayOfWeekWednesday           = 3,
    IXCLParkingDayOfWeekThursday            = 4,
    IXCLParkingDayOfWeekFriday              = 5,
    IXCLParkingDayOfWeekSaturday            = 6,
    IXCLParkingDayOfWeekSunday              = 7,
};

/*!
 * @class IXCLParkingLotReview
 *
 * @abstract
 *      Model object which respresents structured rate information for a parking object.
 */
@interface IXCLParkingStructuredRate : NSObject <NSCopying>

/*!
 * @abstract Numeric value for the rate payment in local currency.
 */
@property (nonatomic, strong, readwrite) NSNumber * rate;

/*!
 * @abstract Day of the week this rate starts being available.
 */
@property (nonatomic, assign, readwrite) IXCLParkingDayOfWeek dowStart;

/*!
 * @abstract Day of the week this rate stops being available.
 */
@property (nonatomic, assign, readwrite) IXCLParkingDayOfWeek dowEnd;

/*!
 * @abstract Duration of rate in minutes.
 */
@property (nonatomic, assign, readwrite) int increment;

/*!
 * @abstract Date string representing when the car can enter for this rate.
 */
@property (nonatomic, strong, readwrite) NSString * timeIn;

/*!
 * @abstract Date string representing when the car can exit for this rate.
 */
@property (nonatomic, strong, readwrite) NSString * timeOut;

/*!
 * @abstract Does the rate repeat.
 */
@property (nonatomic, assign, readwrite) BOOL repeats;

/*!
 * @abstract Additional minutes if the rate is additive.
 */
@property (nonatomic, assign, readwrite) int additional;

/*!
 * @abstract Minimum length of stay in minutes.
 */
@property (nonatomic, assign, readwrite) int min;

/*!
 * @abstract Maximum length of stay in minutes.
 */
@property (nonatomic, assign, readwrite) int max;

/*!
 * @abstract The start of this rate if monthly.
 */
@property (nonatomic, assign, readwrite) int monthlyStart;

/*!
 * @abstract The end of this rate if monthly.
 */
@property (nonatomic, assign, readwrite) int monthlyEnd;

@end
