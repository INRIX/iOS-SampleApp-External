/*
 * @header IXCLSphericalMercatorProjection.h
 * @abstract Projected coordinate system used for rendering maps.
 * @discussion
 *      This class is ported from Google Android Map Utils:
 *      https://github.com/googlemaps/android-maps-utils.git
 * @author Gaurav Agarwal
 * @updated 08-15-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLSphericalMercatorProjection
 * @abstract Projected coordinate system used for rendering maps.
 */
@interface IXCLSphericalMercatorProjection : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties


/*!
 * @abstract
 *      The width of the world.
 */
@property (nonatomic, assign, readonly) CGFloat worldWidth;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize self with given world width.
 *
 * @param worldWidth The specified world width.
 *
 * @return Instance of the IXCLSphericalMercatorProjection class.
 */
- (instancetype) initWithWorldWidth: (CGFloat) worldWidth;

/*!
 * @abstract Returns the point corresponding to the specified point on the map.
 *
 * @param coordinate The coordinate on map.
 *
 * @return The point that corresponds to the map point.
 */
- (CGPoint) pointFromCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract Returns the point on the map that corresponds to the specified point.
 *
 * @param point The point that you want to convert.
 *
 * @return The map point that corresponds to the point.
 */
- (CLLocationCoordinate2D) coordinateFromPoint: (CGPoint) point;

@end
