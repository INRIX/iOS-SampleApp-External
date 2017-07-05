/*
 * @header IXCLParkingBlockSection.h
 * @abstract
 *      Model object which respresents a single section in an on-street
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

@class IXCLParkingBlockPricingPayment;
@class IXCLParkingBlockRestriction;

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

typedef NS_ENUM (NSUInteger, IXCLParkingSectionSide)
{
    IXCLParkingSectionSideUnknown = 0,
    IXCLParkingSectionSideLeft    = 1,
    IXCLParkingSectionSideRight   = 2,
    IXCLParkingSectionSideCenter  = 3,
};

typedef NS_ENUM (NSUInteger, IXCLParkingSectionZone)
{
    IXCLParkingSectionZoneUnknown             = 0,
    IXCLParkingSectionZoneNone                = 1,
    IXCLParkingSectionZoneNoParking           = 2,
    IXCLParkingSectionZonePaidParking         = 3,
    IXCLParkingSectionZoneCarpoolParking      = 4,
    IXCLParkingSectionZoneRestrictedParking   = 5,
    IXCLParkingSectionZoneNonPaidParking      = 6,
    IXCLParkingSectionZoneUnrestrictedParking = 7,
    IXCLParkingSectionZoneTimeLimitedParking  = 8,
};

typedef NS_ENUM (NSUInteger, IXCLParkingSectionOccupancyBucket)
{
    IXCLParkingSectionOccupancyBucketUnknown = 0,
    IXCLParkingSectionOccupancyBucket1       = 1, // > 75% occupied
    IXCLParkingSectionOccupancyBucket2       = 2,
    IXCLParkingSectionOccupancyBucket3       = 3, // < 51% occupied
};

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

typedef NS_ENUM (NSUInteger, IXCLParkingSectionDurationUnits)
{
    IXCLParkingSectionDurationUnitsUnknown = 0,
    IXCLParkingSectionDurationUnitsMinutes = 1,
    IXCLParkingSectionDurationUnitsHours   = 2,
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLParkingBlockSection : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Indicates side of a street for parking.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionSide side;

/*!
 * @abstract Indicates offset in meters of the parking section head.
 */
@property (nonatomic, assign, readwrite) NSInteger startOffset;

/*!
 * @abstract Indicates offset in meters of the parking section tail.
 */
@property (nonatomic, assign, readwrite) NSInteger endOffset;

/*!
 * @abstract Indicates parking capacity of a parking section.
 */
@property (nonatomic, assign, readwrite) NSInteger capacity;

/*!
 * @abstract The list of restrictions applied to the parking section.
 */
@property (nonatomic, strong, readonly) NSArray <IXCLParkingBlockRestriction *> * restrictions;

/*!
 * @abstract
 *      The dictionary with available payment method names as a key and payment
 *      method details as a value if available.
 */
@property (nonatomic, strong, readonly) NSArray <IXCLParkingBlockPricingPayment *> * pricingPayments;

/*!
 * @abstract Indicates zone of a parking section.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionZone parkingZone;

/*!
 * @abstract Indicates the percentage of available (unoccupied) parking spots.
 */
@property (nonatomic, assign, readwrite) NSInteger availability;

/*!
 * @abstract Indicates occupancy bucket of a parking section.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionOccupancyBucket occupancyBucket;

@end
