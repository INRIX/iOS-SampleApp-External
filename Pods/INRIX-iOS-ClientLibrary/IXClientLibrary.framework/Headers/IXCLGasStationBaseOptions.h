/*
 * @header IXCLGasStationBaseOptions.h
 * @abstract Represents request parameters for gas stations.
 * @author Patrick Winchell
 * @updated 02-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "IXCLBaseOptions.h"
#import "IXCLGasStationBrand.h"

/*!
 * @abstract
 *      The unit of a distance to gas station.
 *
 * @constant
 *      IXCLGasStationsOptionsDistanceUnitsMiles Distances in miles.
 * @constant
 *      IXCLGasStationsOptionsDistanceUnitsMeters Distances in meters.
 */
typedef NS_ENUM (NSUInteger, IXCLGasStationsOptionsDistanceUnitsType)
{
    IXCLGasStationsOptionsDistanceUnitsMiles  = 0,
    IXCLGasStationsOptionsDistanceUnitsMeters = 1
};

/*!
 * @abstract
 *      Specifies the fields to get back from the server
 * @discussion
 *      Multiple types can be requested by using the | operator.
 *
 * @constant IXCLGasStationOptionsOutputFieldMaskBrand          Return station brands.
 * @constant IXCLGasStationOptionsOutputFieldMaskLocation       Return station location.
 * @constant IXCLGasStationOptionsOutputFieldMaskAddress        Return station address.
 * @constant IXCLGasStationOptionsOutputFieldMaskProducts       Return station fuel products.
 * @constant IXCLGasStationOptionsOutputFieldMaskCurrencyCode   Return the currency code for the station.
 * @constant IXCLGasStationOptionsOutputFieldMaskAll            Return all information on the station.
 */

typedef NS_OPTIONS (NSUInteger, IXCLGasStationOptionsOutputFieldMask)
{
    IXCLGasStationOptionsOutputFieldUseDefault = 0,

    IXCLGasStationOptionsOutputFieldMaskBrand        = (1 << 0),
    IXCLGasStationOptionsOutputFieldMaskLocation     = (1 << 1),
    IXCLGasStationOptionsOutputFieldMaskAddress      = (1 << 2),
    IXCLGasStationOptionsOutputFieldMaskProducts     = (1 << 3),
    IXCLGasStationOptionsOutputFieldMaskCurrencyCode = (1 << 4),
    IXCLGasStationOptionsOutputFieldMaskAll          = (IXCLGasStationOptionsOutputFieldMaskBrand |
                                                        IXCLGasStationOptionsOutputFieldMaskLocation |
                                                        IXCLGasStationOptionsOutputFieldMaskAddress |
                                                        IXCLGasStationOptionsOutputFieldMaskProducts |
                                                        IXCLGasStationOptionsOutputFieldMaskCurrencyCode),
};

/*!
 * @abstract
 *      Specifies the gas types to get from the server.
 * @discussion
 *      Multiple types can be requested by using the | operator.
 *
 * @constant IXCLGasStationProductTypeMaskBiodiesel     Biodiesel
 * @constant IXCLGasStationProductTypeMaskDiesel        Diesel
 * @constant IXCLGasStationProductTypeMaskDieselPlus    Diesel plus
 * @constant IXCLGasStationProductTypeMaskDieselTruck   Truck diesel
 * @constant IXCLGasStationProductTypeMaskLPG           Liquid petroleum gas
 * @constant IXCLGasStationProductTypeMaskMethane       Methane
 * @constant IXCLGasStationProductTypeMaskRegular       Regular grade gasoline
 * @constant IXCLGasStationProductTypeMaskMidgrade      Middle grade gasoline
 * @constant IXCLGasStationProductTypeMaskPremium       Premium grade gasoline
 * @constant IXCLGasStationProductTypeMaskE85           E85 Ethanol/gasoline mixture
 * @constant IXCLGasStationProductTypeMaskNormal        Leaded gasoline
 * @constant IXCLGasStationProductTypeMaskSP92          Unleaded gasoline, with a 92 octane rating
 * @constant IXCLGasStationProductTypeMaskSP95          Unleaded gasoline, with a 95 octane rating
 * @constant IXCLGasStationProductTypeMaskSP95_E10      Unleaded gasoline, with a 95 octane rating and 10% ethanol
 * @constant IXCLGasStationProductTypeMaskSP98          Unleaded gasoline, with a 98 octane rating
 * @constant IXCLGasStationProductTypeMaskAll           Return all gas types.
 */

typedef NS_OPTIONS (NSUInteger, IXCLGasStationProductTypeMask)
{
    IXCLGasStationProductTypeUseDefault = 0,

    IXCLGasStationProductTypeMaskBiodiesel        = (1 << 0),
    IXCLGasStationProductTypeMaskDiesel           = (1 << 1),
    IXCLGasStationProductTypeMaskDieselPlus       = (1 << 2),
    IXCLGasStationProductTypeMaskDieselTruck      = (1 << 3),
    IXCLGasStationProductTypeMaskLPG              = (1 << 4),
    IXCLGasStationProductTypeMaskMethane          = (1 << 5),
    IXCLGasStationProductTypeMaskGasolineRegular  = (1 << 6),
    IXCLGasStationProductTypeMaskGasolineMidgrade = (1 << 7),
    IXCLGasStationProductTypeMaskGasolinePremium  = (1 << 8),
    IXCLGasStationProductTypeMaskGasolineE85      = (1 << 9),
    IXCLGasStationProductTypeMaskGasolineNormal   = (1 << 10),
    IXCLGasStationProductTypeMaskGasolineSP92     = (1 << 11),
    IXCLGasStationProductTypeMaskGasolineSP95     = (1 << 12),
    IXCLGasStationProductTypeMaskGasolineSP95_E10 = (1 << 13),
    IXCLGasStationProductTypeMaskGasolineSP98     = (1 << 14),
    IXCLGasStationProductTypeMaskAll              = (IXCLGasStationProductTypeMaskBiodiesel |
                                                     IXCLGasStationProductTypeMaskDiesel |
                                                     IXCLGasStationProductTypeMaskDieselPlus |
                                                     IXCLGasStationProductTypeMaskDieselTruck |
                                                     IXCLGasStationProductTypeMaskLPG |
                                                     IXCLGasStationProductTypeMaskMethane |
                                                     IXCLGasStationProductTypeMaskGasolineRegular |
                                                     IXCLGasStationProductTypeMaskGasolineMidgrade |
                                                     IXCLGasStationProductTypeMaskGasolinePremium |
                                                     IXCLGasStationProductTypeMaskGasolineE85 |
                                                     IXCLGasStationProductTypeMaskGasolineNormal |
                                                     IXCLGasStationProductTypeMaskGasolineSP92 |
                                                     IXCLGasStationProductTypeMaskGasolineSP95 |
                                                     IXCLGasStationProductTypeMaskGasolineSP95_E10 |
                                                     IXCLGasStationProductTypeMaskGasolineSP98)
};

/*!
 * @abstract
 *      Style to sort the returned gas stations by.
 *
 * @constant IXCLGasStationSortDistance  Gas stations are sorted by distance.
 * @constant IXCLGasStationSortPreference    Gas stations are sorted by preference.
 * @constant IXCLGasStationSortPreferenceDistance    Gas stations are sorted by preference and then by distance.
 */
typedef NS_ENUM (NSInteger, IXCLGasStationSortStyle)
{
    IXCLGasStationSortDistance           = 1,
    IXCLGasStationSortPreference         = 2,
    IXCLGasStationSortPreferenceDistance = 3
};

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract The largest area in square miles that can be used for fuel requests.
 */
FOUNDATION_EXPORT double const IXCLMaximumFuelRequestAreaSquareMiles;

/*!
 * @abstract The largest area in square meters that can be used for fuel requests.
 */
FOUNDATION_EXPORT double const IXCLMaximumFuelRequestAreaSquareMeters;

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLGasStationBaseOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract
 *      A bitmask of the data fields to get from the server.
 */
@property (nonatomic, assign, readwrite) IXCLGasStationOptionsOutputFieldMask outputFieldMask;


/*!
 * @abstract
 *      A bitmask of the fuel product types to get from the server.
 */
@property (nonatomic, assign, readwrite) IXCLGasStationProductTypeMask productTypeMask;

/*!
 * @abstract
 *      Style to sort the returned gas stations by. Defaults to IXCLGasStationSortDistance.
 */
@property (nonatomic, assign, readwrite) IXCLGasStationSortStyle sort;

/*!
 * @abstract
 *      Array of preferred IXCLGasStationBrand objects.
 */
@property (nonatomic, strong, readwrite) NSArray * brands;

//-----------------------------------------------------------------------------
#pragma mark - Init Methods
/*!
 * @abstract Initializes with outputFields and productTypes.
 *
 * @param outputFields A valid IXCLGasStationOptionsOutputFieldMask.
 * @param productTypes A valid IXCLGasStationProductTypeMask.
 *
 * @return Instance of the IXCLGasStationBaseOptions class.
 */
- (instancetype) initWithOutputFields: (IXCLGasStationOptionsOutputFieldMask) outputFields
                         productTypes: (IXCLGasStationProductTypeMask) productTypes;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns IXCLGasStationOptionsOutputFieldMask as a string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) outputFieldsAsString;

/*!
 * @abstract
 *      Returns IXCLGasStationProductTypeMask as a string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) productTypeMaskAsString;

/*!
 * @abstract
 *      Returns IXCLGasStationProductTypeMask as a string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) brandsAsString;

@end
