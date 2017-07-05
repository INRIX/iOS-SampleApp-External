/*
 * @header IXCLMapPoint.h
 * @abstract
 *      Base class for items that can be displayed on the map (e.g. incidents).
 * @author Dmitri Fuerle
 * @updated 11-13-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class
 *      IXCLMapPoint
 * @abstract
 *      Base class for items that can be displayed on the map (e.g. incidents).
 */
@interface IXCLMapPoint : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Coordinate of the map item.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D coordinate;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a coordinate.
 *
 * @param coordinate The coordinate
 *
 * @return Instance of the IXCLRoutePoint class.
 */
- (instancetype) initWithCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract Initializes with a latitude and longitude.
 *
 * @param latitude  The latitude.
 * @param longitude The longitude.
 *
 * @return Instance of the IXCLRoutePoint class.
 */
- (instancetype) initWithLatitude: (CLLocationDegrees) latitude longitude: (CLLocationDegrees) longitude;

@end
