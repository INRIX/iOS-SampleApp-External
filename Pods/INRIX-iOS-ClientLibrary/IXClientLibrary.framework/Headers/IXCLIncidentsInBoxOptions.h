/*
 * @header IXCLIncidentsInBoxOptions.h
 * @abstract
 *      Represents request parameters for retrieving incidents in a rectangular
 *      region.
 * @author Gaurav Agarwal
 * @updated 03-11-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */


#import "IXCLIncidentBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentsInBoxOptions
 * @abstract
 *      Represents request parameters for retrieving incidents in a rectangular
 *      region.
 */
@interface IXCLIncidentsInBoxOptions : IXCLIncidentBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The first corner of the region in which to get data.
 * @discussion
 *      The latitude and longitude values are expressed using the WGS 84 datum.
 *      Northern latitudes are positive and southern latitudes are negative.
 *      Eastern hemisphere longitudes are positive and western hemisphere
 *      longitudes are negative.  Longitudes in North America are negative.
 *      The corner specified by the corner1 parameter can be any of the four
 *      corners of the bounding rectangle.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D corner1;

/*!
 * @abstract The second corner of the region in which to get data.
 * @discussion The corner2 parameter is diagonally opposite of corner1.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D corner2;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with specified corner1 and corner2 points.
 *
 * @param corner1 The first corner of the region in which to get data.
 * @param corner2 The second corner of the region in which to get data.
 *
 * @return Instance of the IXCLIncidentsInBoxOptions class.
 */
- (instancetype) initWithCorner1: (CLLocationCoordinate2D) corner1
                         corner2: (CLLocationCoordinate2D) corner2;

@end
