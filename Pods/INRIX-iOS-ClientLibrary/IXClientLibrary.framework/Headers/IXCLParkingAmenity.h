/*
 * @header IXCLParkingAmenity.h
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

typedef NS_ENUM (NSUInteger, IXCLAmenityType)
{
    IXCLAmenityTypeUnknown                  = 0,
    IXCLAmenityTypeMaxWeight                = 1,
    IXCLAmenityTypeMaxHeight                = 2,
    IXCLAmenityTypeZipCarStations           = 3,
    IXCLAmenityTypeEVChargers               = 4,
    IXCLAmenityTypeCarWash                  = 5,
    IXCLAmenityTypeAirportShuttle           = 6,
    IXCLAmenityTypeHandicapSpaces           = 7,
    IXCLAmenityTypeValidationAvailable      = 8,
    IXCLAmenityTypeCoveredParkingAvailable  = 9,
    IXCLAmenityTypeOpen24_7                 = 10,
    IXCLAmenityTypeInAndOutAllowed          = 11,
    IXCLAmenityTypePrintedPassRequired      = 12,
    IXCLAmenityTypeUnobstructedParking      = 13,
    IXCLAmenityTypeRVParking                = 14,
    IXCLAmenityTypeTailgatingPermitted      = 15,
    IXCLAmenityTypeRestrooms                = 16,
    IXCLAmenityTypeAirportVenueOfficial     = 17,
    IXCLAmenityTypeCreditCardsAccepted      = 18,
    IXCLAmenityType7ftClearance             = 19,
    IXCLAmenityTypeWomenAndFamilyParking    = 20,
};

/*!
 * @class IXCLParkingAmenity
 *
 * @abstract
 *      Model object which respresents different amenities for a parking lot.
 */
@interface IXCLParkingAmenity : NSObject <NSCopying>

/*!
 * @abstract Id for the type of amenity.
 */
@property (nonatomic, assign, readwrite) int id;

/*!
 * @abstract Enum for the amenity type.
 */
@property (nonatomic, assign, readwrite) IXCLAmenityType type;

/*!
 * @abstract String name for the amenity.
 */
@property (nonatomic, strong, readwrite) NSString * name;

/*!
 * @abstract Numeric value for the amenity.
 */
@property (nonatomic, strong, readwrite) NSNumber * value;

/*!
 * @abstract Metric numeric value for the amenity if applicable.
 */
@property (nonatomic, strong, readwrite) NSNumber * metricValue;

@end
