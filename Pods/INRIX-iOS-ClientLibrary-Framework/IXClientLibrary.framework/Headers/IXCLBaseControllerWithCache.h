/*
 * @header IXCLBaseControllerWithCache.h
 * @abstract Base class for controllers that provide cached data.
 * @author Gaurav Agarwal
 * @updated 01-30-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"


@class IXCLCacheController;

/*!
 * @protocol IXCLBaseControllerWithCacheProtocol
 * @abstract 
 *      Controllers that support caching expose this protocol.
 */
@protocol IXCLBaseControllerWithCacheProtocol <NSObject>
/*!
 * @abstract Removes all entries from the cache.
 */
- (void) purgeCache;
@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/* @private
 * @class IXCLBaseCacheController
 * @abstract Base class for controllers that provide cached data.
 */
@interface IXCLBaseControllerWithCache : IXCLBaseController<IXCLBaseControllerWithCacheProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Instance of the IXCLCacheController class to be used by this class.
 */
@property (nonatomic, strong, readwrite) IXCLCacheController * cacheController;

/*!
 * @abstract
 *      A Boolean value indicating whether to purge expired entries in the
 *      cache when application will enter foreground.
 * @discussion
 *      If set to YES, the expired entries in the cache are flushed
 *      automatically when application will enter foreground.  Defaults to NO.
 */
@property (nonatomic, assign, readwrite) BOOL purgeExpiredEntriesOnApplicationWillEnterForeground;

/*!
 * @abstract
 *      A Boolean value indicating whether to purge the cache when low memory
 *      warnings are received and application is in background.
 * @discussion
 *      If set to YES, the cache is purged when low memory warnings are
 *      received and application is in background.  Defaults to NO.
 */
@property (nonatomic, assign, readwrite) BOOL purgeCacheOnMemoryWarningsWhenApplicationInBackground;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Removes all entries from the cache.
 */
- (void) purgeCache;

@end
