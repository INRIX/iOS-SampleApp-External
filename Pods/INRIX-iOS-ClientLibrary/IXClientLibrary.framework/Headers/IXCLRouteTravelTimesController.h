/*
 * @header IXCLRouteTravelTimesController.h
 * @abstract Controller for managing requests for route travel times.
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

#import "IXCLBaseControllerWithCache.h"
#import <CoreLocation/CoreLocation.h>


@class IXCLCoreResponse;
@class IXCLRouteTravelTimes;
@class IXCLTravelTimesOptions;


//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLRouteTravelTimesControllerProtocol
 * @abstract
 *      Protocol definition for the Route Travel Times Controller
 */
@protocol IXCLRouteTravelTimesControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing route travel times.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing route travel times.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns IXCLRouteTravelTimes object containing list of travel times
 *      based on current and future traffic conditions.
 *
 * @param options
 *      Travel time options for calculating travel times for a route.
 * @param completion
 *      Block that returns an array of travel times and any errors.
 */
- (void) requestRouteTravelTimesWithOptions: (IXCLTravelTimesOptions *) options
                                 completion: (void (^)(IXCLRouteTravelTimes * routeTravelTimes, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRouteTravelTimesController
 * @abstract Controller for managing requests for route travel times.
 */
@interface IXCLRouteTravelTimesController : IXCLBaseControllerWithCache<IXCLRouteTravelTimesControllerProtocol>
@end
