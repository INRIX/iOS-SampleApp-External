/*
 * @header IXCLParkingBlock.h
 * @abstract Model object which respresents an on-street parking block.
 * @author Aleksei Zhilin
 * @updated 3-14-2016
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
#import "IXCLParkingObjectProtocol.h"

@class IXCLParkingBlockSection;

typedef NS_ENUM (NSUInteger, IXCLParkingSectionOccupancyBucket)
{
    IXCLParkingSectionOccupancyBucketUnknown = 0,
    IXCLParkingSectionOccupancyBucket1       = 1, // > 75% occupied
    IXCLParkingSectionOccupancyBucket2       = 2,
    IXCLParkingSectionOccupancyBucket3       = 3, // < 51% occupied
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingBlock
 * @abstract Model object that respresents a single on-street parking block.
 */
@interface IXCLParkingBlock : IXCLMapPoint <NSCopying, IXCLParkingObjectProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier associated with the parking block.
 */
@property (nonatomic, copy, readwrite) NSString * parkingBlockId;

/*!
 * @abstract The points to draw parking block outline.
 */
@property (nonatomic, strong, readonly) NSArray <CLLocation *> * points;

/*!
 * @abstract The street's name where the parking block is located.
 */
@property (nonatomic, copy, readwrite) NSString * streetName;

/*!
 * @abstract The list of sections in the parking block.
 */
@property (nonatomic, strong, readonly) NSArray <IXCLParkingBlockSection *> * sections;

/*!
 * @abstract Indicates occupancy bucket of a parking section.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionOccupancyBucket occupancyBucket;

/*!
 * @abstract An array of payment types accepted in the parking block.
 */
@property (nonatomic, strong, readwrite) NSArray <NSString *> * paymentTypes;

/*!
 * @abstract Currency symbol used in the parking block.
 */
@property (nonatomic, strong, readwrite) NSString * currency;

/*!
 * @abstract Unique id for the street.
 */
@property (nonatomic, strong, readwrite) NSString * streetID;

@end
