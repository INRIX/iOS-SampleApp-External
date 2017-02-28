/*
 * @header IXCLLocationsReorderOptions.h
 * @abstract Represents request parameters for reorder locations calls.
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
 * @class IXCLLocationsReorderOptions
 * @abstract Represents request parameters for reorder locations calls.
 */
@interface IXCLLocationsReorderOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract An array of location IDs in the correct order.
 */
@property (nonatomic, strong, readonly) NSArray * locationIds;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes the IXCLLocationReorderOptions with the specified array of
 *      locations.
 *
 * @param locations
 *      A non-empty array of locations.
 *
 * @return
 *      Instance of the IXCLLocationReorderOptions class.
 */
- (instancetype) initWithLocations: (NSArray *) locations;

/*!
 * @abstract
 *      Initializes the IXCLLocationReorderOptions with the specified array of
 *      location IDs.
 *
 * @param locations
 *      A non-empty array of location IDs.
 *
 * @return
 *      Instance of the IXCLLocationReorderOptions class.
 */
- (instancetype) initWithLocationIds: (NSArray *) locations;

@end
