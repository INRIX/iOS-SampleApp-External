/*
 * @header IXCLLocation.h
 * @abstract
 *      Model object representing a saved location, containing information
 *      about location's type, name, address and coordinates.
 * @author David Potter
 * @updated 10-12-2010
 * @copyright Copyright (c) 2010-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "IXCLMapPoint.h"
#import "IXCLSharingAddress.h"


//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract Represents the name of a Home location.
 * @discussion Value is always 'Home' regardless of used locale.
 */
FOUNDATION_EXPORT NSString * const IXCLLocationNameHome;

/*!
 * @abstract Represents the name of a Work location.
 * @discussion Value is always 'Work' regardless of used locale.
 */
FOUNDATION_EXPORT NSString * const IXCLLocationNameWork;

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLLocation
 * @abstract
 *      Model object representing a saved location, containing information
 *      about location's type, name, address and coordinates.
 * @discussion
 *      Locations are saved by the user.
 */
@interface IXCLLocation : IXCLMapPoint <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The location's unique identifier.
 */
@property (nonatomic, copy, readonly) NSString * locationId;

/*!
 * @abstract
 *      Name of the location.
 */
@property (nonatomic, copy, readwrite) NSString * name;

/*!
 * @abstract Address of the location.
 */
@property (nonatomic, copy, readwrite) NSString * address;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes an IXCLLocation instance from the specified name and
 *      coordinate.
 *
 * @param name       The location name.
 * @param coordinate The location coordinate.
 *
 * @return IXCLLocation
 */
- (id) initWithName: (NSString *) name
         coordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Initializes an IXCLLocation instance from the specified ID, name and
 *      coordinate.
 *
 * @param locationId The location ID.
 * @param name       The location name.
 * @param coordinate The location coordinate.
 *
 * @return IXCLLocation
 */
- (id) initWithLocationId: (NSString *) locationId
                     name: (NSString *) name
               coordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Obtain the hash value of self.
 *
 * @discussion
 *      This method returns the hash of the locationId.
 *
 * @return
 *      The hash value of this object.
 */
- (NSUInteger) hash;

/*!
 * @abstract
 *      Check for equality with another object.
 *
 * @param object
 *      The object to test for equality.
 *
 * @return YES if the objects are equal, NO otherwise.
 */
- (BOOL) isEqual: (id) object;

@end
