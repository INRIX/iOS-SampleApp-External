/*
 * @header IXCLParkingBlockPaymentMethod.h
 * @abstract
 *      Model object which respresents payment method in an on-street
 *      parking block.
 * @author Aleksei Zhilin
 * @updated 03-21-2016
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
 * @class IXCLParkingBlockPaymentMethod
 *
 * @abstract
 *      Model object which respresents payment method in an on-street
 *      parking block.
 */
@interface IXCLParkingBlockPaymentMethod : NSObject <NSCopying>

/*!
 * @abstract The value of a payment method.
 */
@property (nonatomic, copy, readwrite) NSString * value;

/*!
 * @abstract The details of a payment method.
 */
@property (nonatomic, copy, readwrite) NSString * details;

@end
