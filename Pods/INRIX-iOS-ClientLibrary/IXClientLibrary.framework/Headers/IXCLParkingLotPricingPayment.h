/*
 * @header IXCLParkingLotPricingPayment.h
 * @abstract Definitions describing parking lot pricing payment.
 * @author Cheng Cheng
 * @updated 02-23-2015
 * @copyright Copyright (c) 2016 INRIX, Inc.
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

/*!
 * @class IXCLParkingLotPricingPayment
 * @abstract Model object describing a parking pricing payment.
 */
@interface IXCLParkingLotPricingPayment : NSObject <NSCopying>

/*!
 * @abstract The duration in hours of pricing payment.
 */
@property (nonatomic, assign, readwrite) NSInteger durationInHours;

/*!
 * @abstract Determines whether the price is specified.
 */
@property (nonatomic, assign, readwrite) BOOL amountSpecified;

/*!
 * @abstract The amount of value of pricing payment.
 */
@property (nonatomic, assign, readwrite) double paymentAmount;

/*!
 * @abstract The currency value of pricing payment.
 */
@property (nonatomic, copy, readwrite) NSString * currencyType;

/*!
 * @abstract The description of pricing payment.
 */
@property (nonatomic, copy, readwrite) NSString * notes;

/// @cond
+ (NSArray *) pricingPaymentsFromDictionaries: (NSArray *) dictionaries;

@end
