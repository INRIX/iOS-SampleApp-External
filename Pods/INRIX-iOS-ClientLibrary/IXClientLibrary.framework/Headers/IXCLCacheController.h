/*
 * @header IXCLCacheController.h
 * @abstract Controller for managing a cache.
 * @author Dmitri Fuerle
 * @updated 10-08-2013
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
 * @abstract Default cache size limit for cached. The value is 50.
 */
FOUNDATION_EXPORT NSUInteger const IXCLCacheControllerDefaultLimit;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLCacheControllerProtocol
 * @abstract
 *      Protocol definition for Cache-Enabled Controllers
 */
@protocol IXCLCacheControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The cache used to store the objects.
 */
@property (nonatomic, strong, readonly) NSMutableDictionary * cache;

/*!
 * @abstract Returns the number of entries in the cache.
 */
@property (nonatomic, assign, readonly) NSUInteger count;

/*!
 * @abstract
 *      Size of the cache.
 * @discussion
 *      This represents the maximum number of objects that can reside in the
 *      cache at given point of time. The default value is 50.
 */
@property (nonatomic, assign, readwrite) NSUInteger cacheLimit;

/*!
 * @abstract
 *      Expiry time for the objects cached in the cache.
 * @discussion
 *      Objects are expired after this time.  The expired objects are not
 *      removed immediately at expiry but are eligible to removed if cacheLimit
 *      is reached and cache need to be trimmed.  Defaults to 0 seconds.
 *      Subclasses must specify this.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval cacheExpiryTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Returns the cached object ignoring the expiry date for a key.
 *
 * @param key The key used to store the object.
 *
 * @return Cached object.
 */
- (id) cachedObjectIgnoringExpiryForKey: (NSString *) key;

/*!
 * @abstract
 *      Returns the cached object for a key if it is not expired, otherwise
 *      returns nil.
 *
 * @param key
 *      The key used to store the object.
 *
 * @return
 *      Cached object with specified key.
 */
- (id) objectForKeyedSubscript: (NSString *) key;

/*!
 * @abstract
 *      Set cached object with given key.
 * @discussion
 *      The expiration date is automatically set by adding
 *      cacheExpiryTimeInterval to the current date.
 *
 * @param key   The key used to store the object.
 * @param value The object to cache.
 */
- (void) setObject: (id) value forKeyedSubscript: (NSString *) key;

/*!
 * @abstract Set cached object with given key and expiration date.
 *
 * @param value      The object to cache.
 * @param key        The key used to store the object.
 * @param expiryDate The date the object will expire.
 */
- (void) setObject: (id) value forKey: (NSString *) key expiryDate: (NSDate *) expiryDate;

/*!
 * @abstract Adds completion block to existing server request.
 *
 * @param key        The key used to store the object.
 * @param completion The completion block to add.
 *
 * @return If server request exists returns YES; otherwise NO.
 */
- (BOOL) addCompletionBlockToKeyIfPossible: (NSString *) key completion: (id) completion;

/*!
 * @abstract Sets a new server request.
 *
 * @param key The key used to store the server request.
 */
- (void) setStartRequestForKey: (NSString *) key;

/*!
 * @abstract Sets the completion block to a new server request.
 *
 * @param key        The key used to store the object.
 * @param completion The completion block to add.
 */
- (void) setStartRequestForKey: (NSString *) key completion: (id) completion;

/*!
 * @abstract
 *      Set object in cache.
 * @discussion
 *      The expiration date is automatically set by adding
 *      cacheExpiryTimeInterval to the current date.
 *
 * @param key The key used to store the object.
 * @param value The object to cache.
 *
 * @return The completion blocks to fire.
 */
- (NSArray *) completeRequestAtKey: (NSString *) key withValue: (id) value;

/*!
 * @abstract Set object in cache and set an expiration date.
 *
 * @param key        The key used to store the object.
 * @param value      The object to cache.
 * @param expiryDate The date the object will expire.
 *
 * @return The completion blocks to fire.
 */
- (NSArray *) completeRequestAtKey: (NSString *) key withValue: (id) value expiryDate: (NSDate *) expiryDate;

/*!
 * @abstract Checks if with the specified key is expired.
 *
 * @param key The key used to identify the server request.
 *
 * @return If object is expired returns YES; otherwise NO.
 */
- (BOOL) isObjectWithKeyExpired: (NSString *) key;

/*!
 * @abstract Checks if there is existing server request with the specified key.
 *
 * @param key The key used to identify the server request.
 *
 * @return If server request exists returns YES; otherwise NO.
 */
- (BOOL) isRequestWithKeyPending: (NSString *) key;

/*!
 * @abstract Purge the expired entries from the cache.
 */
- (void) purgeExpiredEntries;

/*!
 * @abstract Purge all entries from the cache.
 */
- (void) purgeCache;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/* @private
 * @class IXCLCacheController
 * @abstract Controller for managing a cache.
 */
@interface IXCLCacheController : NSObject<IXCLCacheControllerProtocol>
@end
