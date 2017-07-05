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
#pragma mark Enum Definitions

typedef NS_ENUM (NSUInteger, IXCLParkingReservability)
{
    IXCLParkingReservabilityUnknown             = 0,
    IXCLParkingReservabilityPartlyReservable    = 1,
    IXCLParkingReservabilityReservable          = 2,
    IXCLParkingReservabilityNotReservable       = 3,
    IXCLParkingReservabilityReservationRequired = 4,
};

typedef NS_ENUM (NSUInteger, IXCLParkingTendency)
{
    IXCLParkingTendencyUnknown         = 0,
    IXCLParkingTendencyFillingQuickly  = 1,
    IXCLParkingTendencyFilling         = 2,
    IXCLParkingTendencyFillingSlowly   = 3,
    IXCLParkingTendencyUnchanging      = 4,
    IXCLParkingTendencyEmptyingSlowly  = 5,
    IXCLParkingTendencyEmptying        = 6,
    IXCLParkingTendencyEmptyingQuickly = 7,
};

typedef NS_ENUM (NSUInteger, IXCLParkingStatus)
{
    IXCLParkingStatusUnknown                = 0,
    IXCLParkingStatusFull                   = 1,
    IXCLParkingStatusBusy                   = 2,
    IXCLParkingStatusVacant                 = 3,
    IXCLParkingStatusClosed                 = 4,
    IXCLParkingStatusNoParkingAllowed       = 5,
    IXCLParkingStatusSpecialConditionsApply = 6,
};

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
 * @abstract
 *      The rate at which the parking is filling up.
 */
@property (nonatomic, assign, readwrite) NSInteger fillStateRate;

/*!
 * @abstract
 *      The current status of the parking lot.
 *
 */
@property (nonatomic, assign, readwrite) IXCLParkingStatus parkingStatus;

/*!
 * @abstract
 *      The occupancy trend for this parking lot.
 */
@property (nonatomic, assign, readwrite) IXCLParkingTendency tendency;

/*!
 * @abstract
 *      Indicates the type of reservation policy supported by this lot.
 */
@property (nonatomic, assign, readwrite) IXCLParkingReservability reservability;


/*!
 * TODO-DOCUMENT-METHOD
 * @param dictionary A dictionary of parking lot parameters.
 * @return TODO-DOCUMENT-RETURN
 */
+ (IXCLParkingLotCurrentCapacity *) currentCapacityFromDictionary: (NSDictionary *) dictionary;

@end
