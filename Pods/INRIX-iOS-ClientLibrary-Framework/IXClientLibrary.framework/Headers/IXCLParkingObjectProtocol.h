/*
 * @header IXCLParkingObjectProtocol.h
 * @abstract Protocol definition for the Parking objects.
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

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

typedef NS_ENUM (NSUInteger, IXCLParkingObjectAvailabilityStatus)
{
    IXCLParkingObjectAvailabilityStatusUnknown      = 0,
    IXCLParkingObjectAvailabilityStatusAvailable    = 1,
    IXCLParkingObjectAvailabilityStatusNotAvailable = 2
};

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLParking
 *
 * @abstract Protocol definition for the Parking objects.
 */

@protocol IXCLParkingObjectProtocol <NSObject>

/// Center coordinate of the parking object.
@property (nonatomic, assign, readonly) CLLocationCoordinate2D coordinate;

/// The availability status of the most available section of the parking object.
@property (nonatomic, assign, readonly) IXCLParkingObjectAvailabilityStatus availabilityStatus;

/// The parking object's id.
@property (nonatomic, copy, readonly) NSString * parkingId;

@end
