/*
 * @header IXCLItineraryController.h
 * @abstract Controller for managing itineraries.
 * @author Greg Arias
 * @updated 07-08-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

#import "IXCLBaseControllerWithCache.h"
#import "IXCLItineraryOptions.h"
#import "IXCLItinerary.h"
#import "IXCLItineraryEntry.h"

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLItineraryControllerProtocol
 * @abstract
 *      Protocol definition for the Itinerary Controller
 */
@protocol IXCLItineraryControllerProtocol<NSObject>

/*!
 * @abstract Retrieves itineraries for the current user.
 * @param options A description of the itinerary to be retrieved.
 * @param completion The completion block to be invoked when the operation completes.
 */
- (void) requestItineraryWithOptions: (IXCLItineraryOptions *) options
                      completion: (void (^)(IXCLItinerary * itinerary, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLItineraryController
 * @abstract Controller for managing itinerary requests.
 */
@interface IXCLItineraryController : IXCLBaseControllerWithCache<IXCLItineraryControllerProtocol>
@end
