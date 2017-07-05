/*
 * @header IXCLSearchOptions.h
 * @abstract Options class for performing a location search.
 * @author Kent Lottis
 * @updated 3-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;
#import "IXCLBaseOptions.h"

// Search radius in meters, aka 150m.
FOUNDATION_EXPORT const float IXCLDefaultSearchRadius;

/*!
 * @abstract
 *      Options class for performing a location lookup.
 */
@interface IXCLSearchOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract
 *      Initializes an instance of the IXCLSearchOptions class
 *      with a query string that describes the types of locations to search for.
 *
 * @param query
 *      The search string to use in the search.
 *
 * @return
 *      An initialized search options object.
 */
- (instancetype) initWithQuery: (NSString *) query;

/*!
 * @abstract
 *      The search string describing the types of locations to find.
 */
@property (nonatomic, strong, readwrite) NSString * query;

/*!
 * @abstract
 *      The location around which to search for points of interest.
 *
 * @discussion
 *      This property is optional. If nil, the search will center around
 *      the user's current location.
 */
@property (nonatomic, strong, readwrite) CLLocation * location;

/*!
 * @abstract
 *      Limit search results to locations within this distance
 *      from the specified location.
 *
 * @discussion
 *      Defaults to zero, which instructs the search engine to use
 *      a useful internal default.
 */
@property (nonatomic, assign, readwrite) double rangeInMeters;

@end
