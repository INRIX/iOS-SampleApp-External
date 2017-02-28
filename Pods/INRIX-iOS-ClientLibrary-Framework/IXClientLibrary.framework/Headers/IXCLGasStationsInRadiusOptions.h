/*
 * @header IXCLGasStationsInRadiusOptions.h
 * @abstract Represents request parameters for gas stations in a radius.
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

#import "IXCLGasStationBaseOptions.h"

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @class IXCLGasStationsInRadiusOptions
 * @abstract Options for requesting gas stations within a radius.
 */
@interface IXCLGasStationsInRadiusOptions : IXCLGasStationBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The center of the region in which to get data.
 * @discussion
 *      Northern latitudes are positive and southern latitudes are negative.
 *      Eastern hemisphere longitudes are positive and western hemisphere
 *      longitudes are negative.  Longitudes in North America are negative.
 *      The latitude and longitude values are expressed using the WGS 84 datum.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D center;

/*!
 * @abstract
 *      The radius of the circular bounding area from which to return data.
 * @discussion
 *      Any features that are fully or partially enclosed within the bounding
 *      area are selected.  If the Units parameter is set to Metric, the radius
 *      is measured in meters; if Units is set to US (the default), the radius
 *      is measured in miles.
 */
@property (nonatomic, assign, readwrite) double radius;

/*!
 * @abstract
 *      Describes distance values in this class (e.g. radius) as well as in the
 *      response from the request.
 * @discussion
 *      Defaults to IXCLGasStationsOptionsDistanceUnitsMiles.
 */
@property (nonatomic, assign, readwrite) IXCLGasStationsOptionsDistanceUnitsType distanceUnits;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes with specified center and radius.
 *
 * @param center
 *      A valid center coordinate.
 * @param radius
 *      A valid radius in units defined by
 *      IXCLGasStationsOptionsDistanceUnitsType.
 *
 * @return Instance of the IXCLGasStationsInRadiusOptions class.
 */
- (instancetype) initWithCenter: (CLLocationCoordinate2D) center
                         radius: (double) radius;

/*!
 * @abstract
 *      Initializes with specified center, radius, outputFields and productTypes.
 *
 * @param center
 *      A valid center coordinate.
 * @param radius
 *      A valid radius in units defined by
 *      IXCLGasStationsOptionsDistanceUnitsType.
 * @param outputFields
 *      A valid IXCLGasStationOptionsOutputFieldMask.
 * @param productTypes
 *      A valid IXCLGasStationProductTypeMask.
 *
 * @return Instance of the IXCLGasStationsInRadiusOptions class.
 */
- (instancetype) initWithCenter: (CLLocationCoordinate2D) center
                         radius: (double) radius
                   outputFields: (IXCLGasStationOptionsOutputFieldMask) outputFields
                   productTypes: (IXCLGasStationProductTypeMask) productTypes;

@end
