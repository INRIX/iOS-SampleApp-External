/*
 * @header IXCLGasStationsOnRouteOptions.h
 * @abstract Represents request parameters for gas stations on a route.
 * @author Aleksei Zhilin
 * @updated 08-23-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLGasStationBaseOptions.h"

@class IXCLRoute;

//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract
 *      Represents the default radius value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteRadiusInMilesDefault;

/*!
 * @abstract
 *      Represents the minimum radius value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteRadiusInMilesMin;

/*!
 * @abstract
 *      Represents the maximum radius value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteRadiusInMilesMax;

/*!
 * @abstract
 *      Represents the default distance value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteDistanceInMilesDefault;

/*!
 * @abstract
 *      Represents the minimum distance value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteDistanceInMilesMin;

/*!
 * @abstract
 *      Represents the maximum distance value in miles to request gas stations.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLGasStationsOnRouteDistanceInMilesMax;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @class IXCLGasStationsOnRouteOptions
 * @abstract Options for requesting gas stations on a route.
 */
@interface IXCLGasStationsOnRouteOptions : IXCLGasStationBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Route ID from which to return gas stations.
 */
@property (nonatomic, strong, readonly) NSString * routeId;

/*!
 * The current location. Used to define search region along the route.
 */
@property (nonatomic, strong, readwrite) CLLocation * currentLocation;

/*!
 * @abstract
 *      Maximum distance from route to a gas stations. Also can be represented
 *      as a half width of a corridor where to search for gas stations.
 * @discussion
 *      If Units parameter is set to Metric, the radius is measured in meters;
 *      if Units is set to US (the default), the radius is measured in miles.
 */
@property (nonatomic, assign, readwrite) double radius;

/*!
 * @abstract
 *      Look ahead distance along the route.
 * @discussion
 *      If Units parameter is set to Metric, the radius is measured in meters;
 *      if Units is set to US (the default), the radius is measured in miles.
 */
@property (nonatomic, assign, readwrite) double distance;

/*!
 * @abstract
 *      Describes distance values in this class (e.g. radius, distance)
 *      as well as in the response from the request.
 * @discussion
 *      Defaults to IXCLGasStationsOptionsDistanceUnitsMiles.
 */
@property (nonatomic, assign, readwrite) IXCLGasStationsOptionsDistanceUnitsType distanceUnits;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLGasStationsOnRouteOptions from an existing route.
 *
 * @param route
 *      The route to update.
 *
 * @return
 *      Instance of the IXCLGasStationsOnRouteOptions class.
 */
- (instancetype) initWithRoute: (IXCLRoute *) route;

@end
