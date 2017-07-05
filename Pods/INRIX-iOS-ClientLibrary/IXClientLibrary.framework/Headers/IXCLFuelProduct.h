/*
 * @header IXCLFuelProduct.h
 * @abstract Gas station fuel product data object.
 * @author Patrick Winchell
 * @updated 02-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

/*!
 * @class IXCLFuelProduct
 * @abstract
 *      The model object representing a type of fuel.
 */
@interface IXCLFuelProduct : NSObject <NSCoding, NSCopying>

/*!
 * @abstract NSString describing the fuel type.
 */
@property (nonatomic, copy, readwrite) NSString * type;

/*!
 * @abstract Price in the local currency.
 */
@property (nonatomic, assign, readwrite) double price;

/*!
 * @abstract The 3 letter (ISO 4217) currency code for the price value.
 */
@property (nonatomic, copy, readwrite) NSString * currencyCode;

/*!
 * @abstract The date and time that the price data was last verified.
 */
@property (nonatomic, strong, readwrite) NSDate * updateDate;

@end
