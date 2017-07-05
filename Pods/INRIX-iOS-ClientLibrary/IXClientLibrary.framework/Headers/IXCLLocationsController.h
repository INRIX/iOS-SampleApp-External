/*
 * @header IXCLLocationsController.h
 * @abstract Controller for managing location requests.
 * @author Dmitri Fuerle
 * @updated 08-26-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseControllerWithCache.h"

#import "IXCLSavedLocation.h"

@class IXCLCoreResponse;
@class IXCLLocation;
@class IXCLLocationCreateOptions;
@class IXCLLocationsDeleteOptions;
@class IXCLLocationsRequestOptions;
@class IXCLLocationsReorderOptions;
@class IXCLLocationUpdateOptions;
@class IXCLLearnedLocationUpdateOptions;

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Notification name to subscribe to location controller updates.
 * @discussion
 *      This string can be used as the name property when adding an observer to
 *      NSNotificationCenter.
 */
FOUNDATION_EXPORT NSString * const IXCLLocationsControllerLocationsDidUpdateNotification;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLLocationsControllerProtocol
 * @abstract
 *      Protocol definition for the Locations Controller
 */
@protocol IXCLLocationsControllerProtocol <IXCLBaseControllerWithCacheProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Recommendation Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing locations.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing locations.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Public Properties

/*!
 * @abstract
 *      The collection of the cached trips.
 * @discussion
 *      Loads trips from server if they are expired. Expiry time is based
 *      on the IXCLTripsControllerDefaultExpiryTimeInterval constant.
 */
@property (nonatomic, assign, readonly) NSArray * learnedLocations;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Retrieves an array of IXCLSavedLocation objects, requesting from the server
 *      if necessary.
 *
 * @param options    Options to request locations.
 * @param completion Block that returns an array of IXCLSavedLocation objects, and any errors.
 */
- (void) requestSavedLocationsWithOptions: (IXCLLocationsRequestOptions *) options
                               completion: (void (^)(NSArray * savedLocations, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Retrieves an array of IXCLLearnedLocation objects, requesting from the server
 *      if necessary.
 *
 * @param options
 *      Options to request trips.
 * @param completion
 *      Block that returns an array of IXCLLearnedLocation objects, and any errors.
 */
- (void) requestLearnedLocationsWithOptions: (IXCLLocationsRequestOptions *) options
                                 completion: (void (^)(NSArray * learnedLocations, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Updates a collection of LearnedLocations on the server with the changes specified in the
 *      options object.
 *
 * @param options
 *      Options object describing the changes to apply to the Learned Locations
 *
 * @param completion
 *      Block that returns success, and any errors.
 */
- (void) updateLearnedLocationsWithOptions: (IXCLLearnedLocationUpdateOptions *) options
                                completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Saves a location on the server.
 *
 * @param options    Options for creating new location.
 * @param completion Block that returns success, and any errors.
 */
- (void) createSavedLocationWithOptions: (IXCLLocationCreateOptions *) options
                             completion: (void (^)(IXCLSavedLocation * savedLocation, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Deletes saved locations on the server.
 *
 * @param options    Options for deleting locations.
 * @param completion Block that returns success, and any errors.
 */
- (void) deleteSavedLocationsWithOptions: (IXCLLocationsDeleteOptions *) options
                              completion: (void (^)(NSArray * deletedLocationIds, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Updates a saved location on the server.
 *
 * @param options    Options for updating location.
 * @param completion Block returns success, and any errors.
 */
- (void) updateSavedLocationWithOptions: (IXCLLocationUpdateOptions *) options
                             completion: (void (^)(IXCLSavedLocation * updatedLocation, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Reorders the list of IXCLSavedLocation objects on the server.
 *
 * @param options    Options for reordering saved locations.
 * @param completion Block that returns success, and any errors.
 */
- (void) reorderSavedLocationsWithOptions: (IXCLLocationsReorderOptions *) options
                               completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Moves a saved location from one position to another.
 * @discussion
 *      Locations between the two positions will be reordered to reflect their
 *      new position.
 *
 * @param sourceIndex      Position of the saved location to move.
 * @param destinationIndex New position for the saved location.
 * @param completion       Block to execute on completion.
 */
- (void) moveSavedLocationFromIndex: (NSUInteger) sourceIndex
                            toIndex: (NSUInteger) destinationIndex
                         completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the cached user saved locations.
 * @discussion
 *      Loads locations from server if they are expired.  Expiry time is based
 *      on the IXCLLocationsControllerDefaultExpiryTimeInterval constant.
 *      Defaults to IXCLLocationsControllerDefaultExpiryTimeInterval.
 * @return
 *      An array of IXCLSavedLocations.
 */
- (NSArray *) savedLocations;

/*!
 * @abstract
 *      Returns the IXCLLocation object for the specified location ID from the
 *      cache.
 *
 * @param locationId
 *      ID of location to be returned.
 *
 * @return
 *      IXCLLocation for specified location ID, or nil if not found in the
 *      cache.
 */
- (IXCLLocation *) locationForLocationId: (NSString *) locationId;

/*!
 * @abstract
 *      Returns the IXCLSavedLocation object for specified savedLocationType from the
 *      cache.
 * @discussion
 *      If multiple saved locations match, the first one found will be returned.
 *
 * @param locationType
 *      IXCLLocationType for IXCLSavedLocation to be returned.
 *
 * @return
 *      IXCLSavedLocation for specified location type, or nil if not found in the
 *      cache.
 */
- (IXCLSavedLocation *) locationForLocationType: (IXCLLocationType) locationType;

/*!
 * @abstract Forces a fetch of the saved locations from the server.
 */
- (void) syncLocations;

/*!
 * @abstract Fetches the saved locations from the server if they are expired.
 * @discussion Expiry time is determined by cacheExpiryTimeInterval.
 */
- (void) syncLocationsIfNeeded;

@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLLocationsController
 * @abstract Controller for managing location requests.
 */
@interface IXCLLocationsController : IXCLBaseControllerWithCache<IXCLLocationsControllerProtocol>
@end
