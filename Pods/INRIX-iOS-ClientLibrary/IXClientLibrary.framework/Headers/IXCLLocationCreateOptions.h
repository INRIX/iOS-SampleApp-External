/*
 * @header IXCLLocationCreateOptions.h
 * @abstract Represents request parameters for create location calls.
 * @author Aleksei Zhilin
 * @updated 03-06-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLLocationBaseModifyOptions.h"

#import "IXCLSavedLocation.h"

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLLocationCreateOptions
 * @abstract Represents request parameters for create location calls.
 */
@interface IXCLLocationCreateOptions : IXCLLocationBaseModifyOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The type of the location.
 */
@property (nonatomic, assign, readwrite) IXCLLocationType locationType;

/*!
 * @abstract
 *      An unique name of the location.
 * @discussion
 *      Names of locations with type IXCLLocationTypeHome and
 *      IXCLLocationTypeWork always must be 'Home' and 'Work' respectively,
 *      regardless of used locale.  No other locations can use the 'Home' and
 *      'Work' names.
 */
@property (nonatomic, strong, readwrite) NSString * name;

/*!
 * @abstract The coordinate of the location.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D coordinate;

/*!
 * @abstract Contacts associated with this location.
 * @discussion NSMutableArray of IXCLContact objects.
 */
@property (nonatomic, strong, readonly) NSMutableArray * contacts;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLLocationCreateOptions with the specified location
 *      type and coordinate.
 *
 * @param locationType The type of the location.
 * @param name         The unique name of the location.
 * @param coordinate   The coordinate of the location.
 *
 * @return Instance of the IXCLLocationCreateOptions class.
 */
- (instancetype) initWithLocationType: (IXCLLocationType) locationType
                                 name: (NSString *) name
                           coordinate: (CLLocationCoordinate2D) coordinate;

@end
