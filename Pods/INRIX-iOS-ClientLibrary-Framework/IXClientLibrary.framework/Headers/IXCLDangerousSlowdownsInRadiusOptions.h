/*
 * @header IXCLDangerousSlowdownsInRadiusOptions.h
 * @abstract Options for requesting slowdowns within a radius.
 * @author Patrick Winchell
 * @created 11-10-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLDangerousSlowdownBaseOptions.h"

@interface IXCLDangerousSlowdownsInRadiusOptions : IXCLDangerousSlowdownBaseOptions

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
@property (nonatomic, assign, readwrite) CLLocationDistance radius;

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
 *      IXCLIncidentsInRadiusOptionsDistanceUnitType.
 *
 * @return Instance of the IXCLIncidentsInRadiusOptions class.
 */
- (instancetype) initWithCenter: (CLLocationCoordinate2D) center
                         radius: (double) radius;

@end
