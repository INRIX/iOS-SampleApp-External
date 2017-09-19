/*
 * @header IXCLSavedTripControler.h
 * @abstract Controller for managing saved trips.
 * @author Kent Lottis
 * @updated 03-02-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

FOUNDATION_EXPORT NSString * const IXCLSavedTripPropertiesKey;
FOUNDATION_EXPORT NSString * const IXCLSavedTripRouteCriteriaKey;
FOUNDATION_EXPORT NSString * const IXCLSavedTripRoutePreferenceKey;

@import Foundation;

#import "IXCLBaseController.h"
#import "IXCLSavedTripOptions.h"
#import "IXCLUpdateNotificationOptions.h"
#import "IXCLGetSavedTripsResponse.h"


/*!
 * @abstract
 *      The largest number of waypoints allowed on a saved trip.
 */
extern const int IXCLSavedTripMaxPaypoints;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLTripControllerProtocol
 * @abstract
 *      Protocol definition for the Trips Controller
 */
@protocol IXCLTripControllerProtocol<NSObject>

/*!
 * @abstract Saves a trip to the server.
 * @param options A description of the trip to be saved.
 * @param completion The completion block to be invoked when the save operation comletes.
 * @discussion
 *      On a succesful save or update operation, the completion handler received an updated
 *      instance of the saved trip object that reflects the state of the trip on the server.
 *      The caller should replace any references to the trip with the new instance.
 */
- (void) saveTripWithOptions: (IXCLSavedTripOptions *) options
                  completion: (void (^)(IXCLSavedTrip * updatedTrip, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Deletes a saved trip from the server.
 * @param options A description of the trip to be deleted.
 * @param completion The completion block to be invoked when the delete operation completes.
 */
- (void) deleteTripWithOptions: (IXCLSavedTripOptions *) options
                    completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Retrieves all the saved trips for the current user.
 * @param options Reserved. Must be nil.
 * @param completion The completion block to be invoked when the operation completes.
 */
- (void) getTripsWithOptions: (IXCLSavedTripOptions *) options
                  completion: (void (^)(IXCLGetSavedTripsResponse * getSavedTripsResponse, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Update pre-drive notification settings for a user calendar.
 * @param options A description of the notification settings to be updated.
 * @param completion The completion block to be invoked when the operation completes.
 */
- (void) updatePreDriveNotification: (IXCLUpdateNotificationOptions *) options
                         completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTripController
 *
 * @abstract
 *      The Trip Controller is responsible for saving, deleting and querying for
 *      user-defined trips.
 */
@interface IXCLTripController : IXCLBaseController<IXCLTripControllerProtocol>
@end
