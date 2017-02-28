/*
 * @header IXCLLocationsDeleteOptions.h
 * @abstract Represents request parameters for delete locations calls.
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

#import <Foundation/Foundation.h>
#import "IXCLBaseOptions.h"
#import "IXCLLocation.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLLocationsDeleteOptions
 * @abstract Represents request parameters for delete locations calls.
 */
@interface IXCLLocationsDeleteOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The array of IDs of locations to delete.
 */
@property (nonatomic, strong, readonly) NSArray * locationIds;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initialize the IXCLLocationsDeleteOptions with the specified array of
 *      location IDs.
 *
 * @param locations
 *      A non-empty array of location IDs. The number of IDs is limited to 30.
 *
 * @return
 *      Instance of the IXCLLocationsDeleteOptions class.
 */
- (instancetype) initWithLocationIds: (NSArray *) locations;

/*!
 * @abstract
 *      Initializes the IXCLLocationsDeleteOptions with the specified array of
 *      locations.
 *
 * @param locations
 *      A non-empty array of locations. The number of locations is limited to 30.
 *
 * @return
 *      Instance of the IXCLLocationDeleteOptions class.
 */
- (instancetype) initWithLocations: (NSArray *) locations;

@end
