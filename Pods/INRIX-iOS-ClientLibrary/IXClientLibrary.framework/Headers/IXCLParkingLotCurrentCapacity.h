/*
 * @header IXCLParkingLotCurrentCapacity.h
 * @abstract Definitions describing current capacity for a parking lot.
 * @author Cheng Cheng
 * @updated 02-26-2015
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

/*!
 * @class IXCLParkingLotCurrentCapacity
 * @abstract Model object describing current capacity for a parking lot.
 */
@interface IXCLParkingLotCurrentCapacity : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The time at which the data on this parking lot was acquired.
 */
@property (nonatomic, copy, readwrite) NSString * timeStampDataAquisition;

/*!
 * @abstract
 *      The number of available spaces at the parking lot.
 */
@property (nonatomic, assign, readwrite) NSInteger availableSpaces;

/*!
 * @abstract
 *      The percentage of occupied parking places at this parking lot.
 */
@property (nonatomic, assign, readwrite) NSInteger parkingOccupancyPercentage;

/*!
 * TODO-DOCUMENT-METHOD
 * @param dictionary A dictionary of parking lot parameters.
 * @param totalSpaces total number of spaces in the lot
 * @return TODO-DOCUMENT-RETURN
 */
+ (IXCLParkingLotCurrentCapacity *) currentCapacityFromDictionary: (NSDictionary *) dictionary
                                                      totalSpaces: (NSInteger) totalSpaces;

@end
