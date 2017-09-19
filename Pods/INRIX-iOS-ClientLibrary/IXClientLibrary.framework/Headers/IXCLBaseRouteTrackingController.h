/*
 * @header IXCLBaseRouteTrackingController.h
 * @abstract Base controller class for tracking a route.
 * @author Gaurav Agarwal
 * @updated 08-18-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLPointQuadTree.h"

@class IXCLCore;
@class IXCLRoute;
@class IXCLRoutePoint;
@class IXCLRouteTrackingSearch;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLBaseRouteTrackingControllerProtocol
 * @abstract
 *      Protocol definition for the Base Route Tracking Controller
 */
@protocol IXCLBaseRouteTrackingControllerProtocol<NSObject>
@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/* @private
 * @class IXCLBaseRouteTrackingController
 * @abstract Base controller class for tracking a route.
 */
@interface IXCLBaseRouteTrackingController : NSObject<IXCLBaseRouteTrackingControllerProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Instance of the IXCLCore class to be used by this controller.
 */
@property (nonatomic, weak, readonly) IXCLCore * inrixCore;

/*!
 * @abstract Route tracked by this controller.
 */
@property (nonatomic, strong, readonly) IXCLRoute * route;

/*!
 * @abstract
 *      Route Tracking Search Controller used to search points along this
 *      controller's route.
 */
@property (nonatomic, strong, readonly) IXCLRouteTrackingSearch * routeTrackingSearch;


//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes a base route tracking controller.
 *
 * @param inrixCore
 *      The INRIX Client Library core object to be used to track the route.
 * @param route
 *      Route tracked by this controller.
 *
 * @return
 *      An initialized IXCLBaseRouteTrackingController object or nil if the
 *      object couldn't be initialized.
 */
- (instancetype) initWithInrixCore: (IXCLCore *) inrixCore
                             route: (IXCLRoute *) route;


/*!
 * @abstract
 *      Starts tracking the route.
 * @discussion
 *      Subclass must call the super implementation before doing any work.
 */
- (void) startRouteTracking;


/*!
 * @abstract
 *      Stops tracking the route.
 * @discussion
 *      Subclass must call the super implementation before doing any work.
 */
- (void) stopRouteTracking;


@end
