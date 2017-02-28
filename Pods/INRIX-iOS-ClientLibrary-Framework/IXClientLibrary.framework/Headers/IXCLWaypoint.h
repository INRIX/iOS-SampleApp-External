/*
 * @header IXCLWaypoint.h
 * @abstract Model object representing a waypoint along the route.
 * @author David Potter
 * @updated 09-25-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
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
 * @class IXCLWaypoint
 * @abstract Model object representing a waypoint along the route.
 */
@interface IXCLWaypoint : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier of the waypoint.
 */
@property (nonatomic, copy, readwrite) NSString * waypointId;

/*!
 * @abstract The waypoint name. This is optional.
 */
@property (nonatomic, copy, readwrite) NSString * name;

/*!
 * @abstract The waypoint address. This is optional.
 */
@property (nonatomic, copy, readwrite) NSString * address;

/*!
 * @abstract The waypoint location coordinate.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D coordinate;

/*!
 * @abstract The latitude and longitude pair representing a waypoint.
 */
@property (nonatomic, copy, readwrite) NSString * point;

/*!
 * @abstract The waypoint destination location id. This is optional.
 */
@property (nonatomic, copy, readwrite) NSString * locationId;

/*!
 * @abstract A Boolean value indicating if the waypoint is routable.
 */
@property (nonatomic, assign, readwrite) BOOL isRoutable;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes an IXCLWaypoint instance from the specified name, address
 *      and coordinate.
 *
 * @param name       The waypoint name.
 * @param address    The waypoint address.
 * @param coordinate The waypoint location coordinate.
 *
 * @return Instance of the IXCLWaypoint class.
 */
- (instancetype) initWithName: (NSString *) name
                      address: (NSString *) address
                   coordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Initializes an IXCLWaypoint instance from the specified name, address
 *      and coordinate.
 *
 * @param name       The waypoint name.
 * @param address    The waypoint address.
 * @param latitude   The waypoint location latitude.
 * @param longitude  The waypoint location longitude.
 *
 * @return Instance of the IXCLWaypoint class.
 */
- (instancetype) initWithName: (NSString *) name
                      address: (NSString *) address
                     latitude: (CLLocationDegrees) latitude
                    longitude: (CLLocationDegrees) longitude;

/*!
 * @abstract
 *      Initializes an IXCLWaypoint instance from the specified unarchiver.
 *
 * @param decoder   The unarchiver object used to load the waypoint.
 * @param keyPrefix The key prefix for IXCLWaypoint member(s) keys.
 *
 * @return Instance of the IXCLWaypoint class.
 */
- (instancetype) initWithCoder: (NSCoder *) decoder keyPrefix: (NSString *) keyPrefix;

/*!
 * @abstract Archives IXCLWaypoint using the specified archiver.
 *
 * @param encoder   The archiver object used to archive the waypoint.
 * @param keyPrefix The key prefix for IXCLWaypoint member(s) keys.
 */
- (void) encodeWithCoder: (NSCoder *) encoder keyPrefix: (NSString *) keyPrefix;

/*!
 * @abstract
 *      Checks if the IXCLWaypoint with specified key prefix can be loaded from
 *      given unarchiver.
 *
 * @param decoder   The unarchiver object used to load the waypoint.
 * @param keyPrefix The key prefix for IXCLWaypoint member(s) keys.
 *
 * @return
 *      YES if the IXCLWaypoint with specified key prefix can be
 *      loaded; otherwise NO.
 */
+ (BOOL) decoder: (NSCoder *) decoder containsValueForKeyPrefix: (NSString *) keyPrefix;

@end
