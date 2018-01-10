/*
 * @header IXCLParkingBlockAmenity.h
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

typedef NS_ENUM (NSUInteger, IXCLParkingBlockAmenityType)
{
    IXCLParkingBlockAmenityTypeUnknown                 = 0,
    IXCLParkingBlockAmenityTypeFree                    = 1,
    IXCLParkingBlockAmenityTypeMeteredParking          = 2,
    IXCLParkingBlockAmenityTypeOvernightParking        = 3,
    IXCLParkingBlockAmenityTypeResidentialParking      = 4,
    IXCLParkingBlockAmenityTypeCommercialVehicle       = 5,
};

/*!
 * @class IXCLParkingBlockAmenity
 *
 * @abstract
 *      Model object which respresents different amenities for a parking lot.
 */
@interface IXCLParkingBlockAmenity : NSObject <NSCopying>

/*!
 * @abstract Id for the type of amenity.
 */
@property (nonatomic, assign, readwrite) int id;

/*!
 * @abstract Enum for the amenity type.
 */
@property (nonatomic, assign, readwrite) IXCLParkingBlockAmenityType type;

/*!
 * @abstract String name for the amenity.
 */
@property (nonatomic, strong, readwrite) NSString * name;

/*!
 * @abstract Numeric value for the amenity.
 */
@property (nonatomic, strong, readwrite) NSNumber * value;

@end
