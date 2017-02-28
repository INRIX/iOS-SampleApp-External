/*
 * @header IXCLParkingBlockPricingPayment.h
 * @abstract
 *      Model object which respresents pricing and payments in an on-street
 *      parking block.
 * @author Aleksei Zhilin
 * @updated 03-16-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLParkingBlockSection.h"

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingBlockPricingPayment
 *
 * @abstract
 *      Model object which respresents pricing and payments in an on-street
 *      parking block.
 */
@interface IXCLParkingBlockPricingPayment : NSObject <NSCopying>

/*!
 * @abstract The duration units of a parking price.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionDurationUnits durationUnits;

/*!
 * @abstract
 *      The duration of parking price specified in units from durationUnits
 *      property.
 */
@property (nonatomic, assign, readwrite) NSInteger duration;

/*!
 * @abstract
 *      The price of the parking duration specidied in the duration property.
 */
@property (nonatomic, assign, readwrite) double amount;

/*!
 * @abstract The currency type.
 */
@property (nonatomic, copy, readwrite) NSString * currencyType;

@end
