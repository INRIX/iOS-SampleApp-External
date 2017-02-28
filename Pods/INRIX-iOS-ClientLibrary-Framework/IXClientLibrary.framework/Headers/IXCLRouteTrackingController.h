/*
 * @header IXCLRouteTrackingController.h
 * @abstract
 *      Controller for tracking the progression of current drive along a route.
 * @author Gaurav Agarwal
 * @updated 08-11-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseRouteTrackingController.h"
#import "IXCLRouteTrackingSearch.h"


//-----------------------------------------------------------------------------
#pragma mark - Block Type Definitions

typedef void (^ IXCLRouteTrackingStatusNotificationBlock) (IXCLRouteTrackingStatus status, CLLocation * location);

typedef void (^ IXCLRouteTrackingRecalculateFromLocationBlock) (IXCLRoute * route);

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Distance threshold to route endpoints
 * @discussion Value is 320 meters.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLRouteTrackingYouAreHereThresholdInMeters;

/*!
 * @abstract
 *      Distance threshold to determine if on-route
 * @discussion Value is 300 meters.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLRouteTrackingOnRouteThresholdInMeters;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLRouteTrackingControllerProtocol
 * @abstract
 *      Protocol definition for the Route Tracking Controller
 */
@protocol IXCLRouteTrackingControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Route progression status tracking notification block.
 * @discussion
 *      This notification block will return the route tracking status.
 */
@property (nonatomic, copy, readwrite) IXCLRouteTrackingStatusNotificationBlock notificationBlock;

/*!
 * @abstract Status of progression of current drive along a route.
 */
@property (nonatomic, assign, readonly) IXCLRouteTrackingStatus status;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class
 *      IXCLRouteTrackingController
 * @abstract
 *      Controller for tracking the progression of current drive along a route.
 */
@interface IXCLRouteTrackingController : IXCLBaseRouteTrackingController<IXCLRouteTrackingControllerProtocol>
@end
