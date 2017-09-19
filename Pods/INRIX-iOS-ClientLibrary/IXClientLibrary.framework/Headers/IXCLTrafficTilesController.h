/*
 * @header IXCLTrafficTilesController.h
 * @abstract Controller for managing requests for traffic tiles.
 * @author Dmitri Fuerle
 * @updated 11-04-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

#import "IXCLBaseControllerWithCache.h"
#import "IXCLTrafficTileOptions.h"


@class IXCLCoreResponse;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLTrafficTilesControllerProtocol
 * @abstract
 *      Protocol definition for the Traffic Tiles Controller
 */
@protocol IXCLTrafficTilesControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - App Recommendation Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing traffic tiles.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing traffic tiles.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshTimeInterval;


/*!
 * @abstract The default opacity for requesting traffic tiles.
 */
@property (nonatomic, assign, readonly) NSUInteger defaultOptionsOpacity;

//-----------------------------------------------------------------------------
#pragma mark - Caching Properties

/*!
 * @abstract The refresh interval in seconds.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval refreshInterval;

//-----------------------------------------------------------------------------
#pragma mark Global Exports - Quad-Key

/*!
 * @abstract Pixel width and height of a traffic tile.
 */
FOUNDATION_EXPORT CGFloat const IXCLTrafficTilesTileSize;

//-----------------------------------------------------------------------------
#pragma mark - Methods


/*!
 * @abstract Retrieves an URL for traffic tile.
 *
 * @param options    Traffic tile options used for generating the traffic tile.
 *
 * @return The URL for the requested traffic tile.
 */
- (NSURL *) getUrlForTrafficTileWithOptions: (IXCLTrafficTileOptions *) options;

/*!
 * @abstract Retrieves a traffic tile, requesting from the server if necessary.
 *
 * @param options    Traffic tile options used for generating the traffic tile.
 * @param completion Block that returns traffic tile image and any errors.
 */
- (void) requestTrafficTileWithOptions: (IXCLTrafficTileOptions *) options
                            completion: (void (^)(UIImage * tileImage, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Retrieves a cached traffic tile matching specified options even if it
 *      is expired.
 * @discussion
 *      The 'useCache' property specified in 'options' is ignored.
 *
 * @param options
 *      Traffic tile options used for calculating the traffic tile.
 * @param error
 *      If an error occurs, the error parameter will be set and the return
 *      value will be nil.
 *
 * @return
 *      If no errors returns the cached traffic tile, otherwise returns nil.
 */
- (UIImage *) cachedTrafficTileWithOptions: (IXCLTrafficTileOptions *) options error: (NSError **) error;

/*!
 * @abstract
 *      Checks the cache to determine if the cached traffic tile matching
 *      specified options is expired.
 * @discussion
 *      The 'useCache' property specified in 'options' is ignored.
 *
 * @param options
 *      Traffic tile options used for calculating the traffic tile.
 * @param error
 *      If an error occurs, the error parameter will be set and the return
 *      value will be nil.
 *
 * @return
 *      If the traffic tile is expired returns YES; otherwise NO.
 */
- (BOOL) isExpiredTrafficTileWithOptions: (IXCLTrafficTileOptions *) options error: (NSError **) error;

/*!
 * @abstract
 *      Replaces values in properties specified to use default values with the
 *      default values stored in the controller.
 * @param options
 *      The options to replace the defaults with.
 */
- (void) replaceDefaultsInRequestOptions: (IXCLTrafficTileOptions *) options;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTrafficTilesController
 * @abstract Controller for managing requests for traffic tiles.
 */
@interface IXCLTrafficTilesController : IXCLBaseControllerWithCache<IXCLTrafficTilesControllerProtocol>
@end
