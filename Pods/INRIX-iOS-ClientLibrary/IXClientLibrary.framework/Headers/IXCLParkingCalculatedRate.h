/*
 * @header IXCLParkingCalculatedRate.h
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

/*!
 * @class IXCLParkingCalculatedRate
 *
 * @abstract
 *      Model object which respresents the calculated rate information for a parking object.
 */
@interface IXCLParkingCalculatedRate : NSObject

/*!
 * @abstract Numeric value for the rate.
 */
@property (nonatomic, strong, readwrite) NSNumber * rateCost;

/*!
 * @abstract String representing the type of rate.
 */
@property (nonatomic, strong, readwrite) NSString * rateType;

/*!
 * @abstract String representing the duration that the rate is for.
 */
@property (nonatomic, strong, readwrite) NSString * quotedDuration;

@end
