/*
 * @header IXCLCacheEntry.h
 * @abstract Object stored in an IXCLCacheController cache.
 * @author Dmitri Fuerle
 * @updated 10-07-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract
 *      Expiry time threshold for this cached entry.
 * @discussion
 *      This cached object is considered expired if the expiryDate minus this
 *      threshold is less than the current date/time.  The value is 5 seconds.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLCacheEntryExpiryThreshold;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/* @private
 * @class IXCLCacheEntry
 * @abstract Object stored in an IXCLCacheController cache.
 */
@interface IXCLCacheEntry : NSObject

/*!
 * @abstract Value that this cached entry holds.
 */
@property (nonatomic, strong, readwrite) id value;

/*!
 * @abstract Created date for this cached entry.
 * @discussion Created date is set when this cached entry is allocated.
 */
@property (nonatomic, strong, readonly) NSDate * createdDate;

/*!
 * @abstract
 *      Expiry date for this cached entry.
 * @discussion
 *      The default value for expiry date is same as created date. User can set
 *      this explicitly.
 */
@property (nonatomic, strong, readwrite) NSDate * expiryDate;

/*!
 * @abstract
 *      Last accessed date/time for this cached entry.
 * @discussion
 *      This is updated to the current date/time when this cached entry is
 *      accessed.
 */
@property (nonatomic, strong, readwrite) NSDate * lastAccessDate;

@end
