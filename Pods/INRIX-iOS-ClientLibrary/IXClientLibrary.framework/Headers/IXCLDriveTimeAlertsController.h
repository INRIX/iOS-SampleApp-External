/*
 * @header IXCLDriveTimeAlertsController.h
 * @abstract Controller for managing drive time alerts.
 * @author Aleksei Zhilin
 * @updated 07-30-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLRoutesBaseOptions.h"


@class IXCLCore;
@class IXCLDriveTimeAlertsBaseController;
@class IXCLDriveTimeAlertsOptions;
@class IXCLRoute;


//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      State of drive time alerts.
 *
 * @constant IXCLDriveTimeAlertsStateUndefined  Drive time alerts state is not determined.
 * @constant IXCLDriveTimeAlertsStateStopped    Drive time alerts are stopped.
 * @constant IXCLDriveTimeAlertsStateStarted    Drive time alerts are started.
 * @constant IXCLDriveTimeAlertsStatePaused     Drive time alerts are paused.
 */
typedef NS_ENUM (NSUInteger, IXCLDriveTimeAlertsState)
{
    IXCLDriveTimeAlertsStateUndefined = 0,
    IXCLDriveTimeAlertsStateStopped,
    IXCLDriveTimeAlertsStateStarted,
    IXCLDriveTimeAlertsStatePaused,
};

//-----------------------------------------------------------------------------
#pragma mark - Block Type Definitions

typedef void (^ IXCLRouteChangedNotificationBlock) (IXCLRoute * route);

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Specifies the route elements to request from the server.
 * @discussion
 *      Value is IXCLRouteOptionsOutputFieldMaskPoints |
 *               IXCLRouteOptionsOutputFieldMaskIncidents
 */
FOUNDATION_EXPORT IXCLRouteOptionsOutputFieldsMask const IXCLDriveTimeAlertsControllerRequiredOutputFields;

/*!
 * @abstract Route tracking status changed notification message
 */
FOUNDATION_EXPORT NSString * const IXCLRouteTrackingStatusChangedNotification;

/*!
 * @abstract
 *      Incidents-on-route notification message.
 * @discussion
 *      Data passed with the notification is a NSArray containing the incidents.
 */
FOUNDATION_EXPORT NSString * const IXCLDriveTimeAlertsIncidentsOnRouteNotification;

/*!
 * @abstract
 *      Parking-on-route notification message.
 * @discussion
 *      Data passed with the notification is a NSArray containing the parking.
 */
FOUNDATION_EXPORT NSString * const IXCLDriveTimeAlertsParkingOnRouteNotification;

/*!
 * @abstract Key values for the route status changed message dictionary data.
 */
FOUNDATION_EXPORT NSString * const IXCLRouteTrackingStatusRouteKey;
FOUNDATION_EXPORT NSString * const IXCLRouteTrackingStatusLocationKey;
FOUNDATION_EXPORT NSString * const IXCLRouteTrackingStatusStatusKey;

/*!
 * @abstract Key values for the incidents-on-route message dictionary data.
 */
FOUNDATION_EXPORT NSString * const IXCLDriveTimeAlertIncidentOnRouteCurrentRouteKey;
FOUNDATION_EXPORT NSString * const ISCLDriveTimeAlertIncidentOnRouteIncidentsArrayKey;

/*!
 * @abstract Key values for the parking-on-route message dictionary data.
 */
FOUNDATION_EXPORT NSString * const IXCLDriveTimeAlertParkingOnRouteCurrentRouteKey;
FOUNDATION_EXPORT NSString * const IXCLDriveTimeAlertParkingOnRouteParkingArrayKey;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLDriveTimeAlertsControllerProtocol
 * @abstract
 *      Protocol definition for the Drive-Time Alerts Controller
 */
@protocol IXCLDriveTimeAlertsControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Instance of the IXCLCore class to be used by this class.
 */
@property (nonatomic, weak, readonly) IXCLCore * inrixCore;

/*!
 * @abstract Current state of alerting on incidents.
 */
@property (nonatomic, assign, readonly) IXCLDriveTimeAlertsState driveTimeAlertsState;

/*!
 * @abstract
 *      Notification block called when the route has changed.
 * @discussion
 *      This notification block will return the new route. Default is nil 
 *      (no notification required).
 */
@property (nonatomic, copy, readwrite) IXCLRouteChangedNotificationBlock routeChangedNotificationBlock;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes a drive time alerts controller with a given INRIX Client
 *      Library core object.
 *
 * @param inrixCore
 *      The INRIX Client Library core object to be used to alert on incidents.
 *
 * @return
 *      An initialized IXCLDriveTimeAlertsController object or nil if the
 *      object couldn't be initialized.
 */
- (instancetype) initWithInrixCore: (IXCLCore *) inrixCore;

/*!
 * @abstract Starts alerting on incidents with the specified options.
 *
 * @param options Options used to describe how to alert on incidents.
 */
- (void) startAlertingOnIncidentsWithOptions: (IXCLDriveTimeAlertsOptions *) options;

/*!
 * @abstract
 *      Pause alerting on incidents.
 * @discussion
 *      Pausing allows the state of the controller to be maintained while
 *      preventing any notifications from being delivered. Does nothing if
 *      controller is not in the IXCLDriveTimeAlertsStateStarted state.
 */
- (void) pauseAlertingOnIncidents;

/*!
 * @abstract
 *      Resume alerting on incidents.
 * @discussion
 *      The controller will resume notifications. Does nothing if controller
 *      is not in the IXCLDriveTimeAlertsStatePaused state.
 */
- (void) resumeAlertingOnIncidents;

/*!
 * @abstract Stops alerting on incidents.
 */
- (void) stopAlertingOnIncidents;

/*!
 * @abstract Update the route to be alerted on.
 *
 * @param route Route on which drive time alerts need to be tracked.
 */
- (void) updateRouteForAlertingOnIncidents: (IXCLRoute *) route;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLDriveTimeAlertsController
 * @abstract Controller for managing drive time alerts.
 */
@interface IXCLDriveTimeAlertsController : NSObject<IXCLDriveTimeAlertsControllerProtocol>
@end
