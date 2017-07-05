/*!
 * @header IXCLSavedLocation.h
 * @abstract
 *      Model object representing a saved location, containing information
 *      about location's type, name, address and coordinates.
 * @author Cheng Cheng
 * @updated 07-20-2015
 * @copyright Copyright (c) 2010-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLLocation.h"

@class IXCLTripSchedule;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract Type of saved location.
 * @discussion Describes categories of locations.
 *
 * @constant IXCLSavedLocationTypeOther      Untyped location.
 * @constant IXCLSavedLocationTypeHome       Home location.
 * @constant IXCLSavedLocationTypeWork       Work location.
 */
typedef NS_ENUM (NSUInteger, IXCLLocationType)
{
    IXCLLocationTypeOther = 0,
    IXCLLocationTypeHome  = 1,
    IXCLLocationTypeWork  = 2,
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration
/*!
 * @class IXCLSavedLocation
 * @abstract
 *      Model object representing a saved location, containing information
 *      about location's type, name, address and coordinates.
 * @discussion
 *      Locations are saved by the user.
 */
@interface IXCLSavedLocation : IXCLLocation

/*!
 * @abstract Type of the location.
 */
@property (nonatomic, assign, readwrite) IXCLLocationType locationType;

/*!
 * @abstract Contacts associated with this location.
 * @discussion NSMutableArray of IXCLContact objects.
 */
@property (nonatomic, strong, readonly) NSMutableArray * associatedContacts;

/*!
 * @abstract Alerts schedule associated with this location.
 */
@property (nonatomic, strong, readonly) IXCLTripSchedule * schedule;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes an IXCLSavedLocation instance from the specified name location type,
 *      address and coordinate.
 *
 * @param name          The location name.
 * @param locationType  Type of the location.
 * @param address       The address of the location.
 * @param coordinate    The location coordinate.
 *
 * @return IXCLSavedLocation
 */
- (instancetype) initWithName: (NSString *) name
                 locationType: (IXCLLocationType) locationType
                      address: (NSString *) address
                   coordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Initializes an IXCLSavedLocation instance from the specified location type,
 *      and using only the source location's name, address and coordinate.
 *
 * @param location      The source location.
 * @param locationType  Type of the location.
 *
 * @return IXCLSavedLocation
 */
- (instancetype) initWithLocation: (IXCLLocation *) location
                     locationType: (IXCLLocationType) locationType;

@end
