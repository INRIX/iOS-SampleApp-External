/*
 * @header IXCLParkingBlockPayStation.h
 * @abstract
 *      Model object which respresents a single pay station in an on-street
 *      parking block.
 * @author Aleksei Zhilin
 * @updated 3-15-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLMapPoint.h"

@class IXCLParkingBlockPaymentMethod;

@interface IXCLParkingBlockPayStation : IXCLMapPoint <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier associated with the pay station.
 */
@property (nonatomic, copy, readwrite) NSString * payStationId;

/*!
 * @abstract The list of payment methods in a pay station.
 */
@property (nonatomic, strong, readonly) NSArray <IXCLParkingBlockPaymentMethod *> * paymentMethods;

@end
