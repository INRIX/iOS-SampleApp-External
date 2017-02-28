/*
 * @header IXCLBoundingBox.h
 * @abstract
 *      Model object representing coordinates of the boundaries of the route.
 * @author Josh Baxley
 * @updated 11-14-2011
 * @copyright Copyright (c) 2011-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>


//-----------------------------------------------------------------------------
#pragma mark Class Declarations

/*!
 * @class IXCLBoundingBox
 * @abstract
 *      Model object representing coordinates of the boundaries of the route.
 */
@interface IXCLBoundingBox : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Returns top right corner location.
 * @discussion
 *      The name of this parameter is as returned in the server response, and
 *      is same as topRightCorner.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D corner1;

/*!
 * @abstract
 *      Returns bottom left corner location.
 * @discussion
 *      The name of this parameter is as returned in the server response, and
 *      is same as bottomLeftCorner.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D corner2;

/*!
 * @abstract Returns top right corner location.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D topRightCorner;

/*!
 * @abstract Returns bottom left corner location.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D bottomLeftCorner;

/*!
 * @abstract Returns top left corner location.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D topLeftCorner;

/*!
 * @abstract Returns bottom right corner location.
 */
@property (nonatomic, assign, readonly) CLLocationCoordinate2D bottomRightCorner;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes a route's bounding box instance with the specified latitude
 *      and longitude for top left and bottom right corners.
 *
 * @param latitudeTopleft      Top left latitude.
 * @param longitudeTopLeft     Top left longitude.
 * @param latitudeBottomRight  Bottom right latitude.
 * @param longitudeBottomRight Bottom right longitude.
 *
 * @return Instance of the IXCLBoundingBox class.
 */
- (instancetype) initWithLatitudeTopLeft: (CLLocationDegrees) latitudeTopleft
                        longitudeTopLeft: (CLLocationDegrees) longitudeTopLeft
                      latitudBottomRight: (CLLocationDegrees) latitudeBottomRight
                    longitudeBottomRight: (CLLocationDegrees) longitudeBottomRight;

@end
