/*
 * @header IXCLRouteUpdateController.h
 * @abstract
 *      Object to encapsulate logic to request routes to a single destination
 *      and then publish them to subscribers.
 * @author David Potter
 * @updated 12-17-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLRoutesController.h"


@class IXCLCore;
@class IXCLRoutesCollection;
@class IXCLRoutesFromPointsOptions;
@class IXCLRouteUpdateController;


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract Primary index when no primary route is selected.
 */
FOUNDATION_EXPORT NSInteger const IXCLRouteUpdateControllerPrimaryIndexNone;

/*!
 * @abstract
 *      Default primary index.  Specifying this value will cause the fastest
 *      route to be set as the primary index whenever routes are updated from
 *      the server.
 */
FOUNDATION_EXPORT NSInteger const IXCLRouteUpdateControllerPrimaryIndexDefault;

/*!
 * @abstract Route has changed notification message
 */
FOUNDATION_EXPORT NSString * const IXCLRouteUpdateRouteChangedNotification;

/*!
 * @abstract Route has a faster alternative route notification message
 */
FOUNDATION_EXPORT NSString * const IXCLRouteUpdateFasterRouteAvailableNotification;

/*!
 * @abstract
 *      Key values for the dictionary sent with the faster route notification.
 */
FOUNDATION_EXPORT NSString * const IXCLRouteUpdateCurrentRouteKey;
FOUNDATION_EXPORT NSString * const IXCLRouteUpdateFasterRouteKey;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Definition

/*!
 * @abstract
 *  Classes wishing to subscribe to route updates can implement this protocol and receive
 *  callbacks on important changes.
 */
@protocol IXCLRouteUpdateSubscriber <NSObject>

/*!
 * @abstract
 *      The route output fields to be included in a request for routes required
 *      by this subscriber.
 */
@property (nonatomic, assign, readonly) IXCLRouteOptionsOutputFieldsMask requiredRouteOptionsOutputFields;

/*!
 * @abstract
 *      A Boolean value indicating whether speed buckets are enabled in the
 *      request for route.
 */
@property (nonatomic, assign, readonly) BOOL includeSpeedBuckets;

/*!
 * @abstract
 *      Updates the routes collection retrieved using the specified options.
 *
 * @param routeUpdateController
 *      The route update controller providing the updated routes collection.
 * @param routesCollection
 *      The updated routes collection.
 * @param primaryRouteIndex
 *      The index of the primary route as specified by the application,
 *      or IXCLRouteUpdateControllerPrimaryIndexNone if the route collection
 *      contains no routes.
 */
- (void) routeUpdateController: (IXCLRouteUpdateController *) routeUpdateController
       updatedRoutesCollection: (IXCLRoutesCollection *) routesCollection
             primaryRouteIndex: (NSInteger) primaryRouteIndex;

@end

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLRouteUpdateControllerProtocol
 * @abstract
 *      Protocol definition for the Route Update Controller
 */
@protocol IXCLRouteUpdateControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Instance of the IXCLCore class to be used by this class.
 */
@property (nonatomic, weak, readonly) IXCLCore * inrixCore;

/*!
 * @abstract Route options used as a base for requesting routes.
 */
@property (nonatomic, copy, readonly) IXCLRoutesFromPointsOptions * baseRouteOptions;

/*!
 * @abstract
 *      The preferred index of the primary route.
 * @discussion
 *      This index specifies a preference for the primary route.  Valid values
 *      are between 0 and one less than the count of routes that were most
 *      recently published, IXCLRouteUpdateControllerPrimaryIndexDefault
 *      indicating that the fastest route is the preferred primary route, or
 *      IXCLRouteUpdateControllerPrimaryIndexNone indicating that there is no
 *      primary route.  Examples of how this could be used include drawing the
 *      primary route differently or using only the primary route for
 *      processing.
 *
 *      When routes are requested and then published to the subscribers, the
 *      actual value passed to the subscribers could be different based on the
 *      number of routes received from the server.  For example, if the value
 *      set is 1 and only one route is received from the server, a value of 0
 *      will be passed to subscribers.
 *
 *      When setting, subscribers will be updated with the new value.
 *
 *      Defaults to IXCLRouteUpdateControllerPrimaryIndexDefault.
 *
 * @exception IXCLExceptionDomain
 *      The specified value is not in the range of valid values.
 */
@property (atomic, assign, readwrite) NSInteger preferredPrimaryRouteIndex;

/*!
 * @abstract
 *      When preserveRoutes is YES, performing GetRoute will only update the current
 *      route collection. Faster routes will be ignored in the case of current location
 *      changing or driving state detected. Defaults to NO.
 */
@property (atomic, assign, readwrite) BOOL preserveRoutes;

/*!
 * @abstract
 *      The routes collection that will be broadcast to any subscribers
 *      when route update requestes are turned on, or at the next timer tick.
 */
@property (atomic, strong, readwrite) IXCLRoutesCollection * currentRoutesCollection;

/*!
 * @abstract
 *      The time interval between route requests.
 * @discussion
 *      Routes will be requested periodically based on this interval.  Defaults
 *      to IXCLRoutesControllerDefaultRecommendedRefreshTimeInterval.
 *
 * @exception IXCLExceptionDomain
 *      The specified value is not in the range of value values.
 */
@property (atomic, assign, readwrite) NSTimeInterval routeRequestTimeInterval;

/*!
 * @abstract
 *      A Boolean value indicating whether route requests have been started.
 */
@property (atomic, readonly) BOOL isStarted;

/*!
 * @abstract
 *      The currently selected route from the currentRoutesCollection.
 * @discussion
 *      Returns the route if it exists. Returns nil if there is no route.
 */
@property (atomic, strong, readonly) IXCLRoute * currentSelectedRoute;

//-----------------------------------------------------------------------------
#pragma mark - Lifecycle

/*!
 * @abstract
 *      Designated initializer.
 *
 * @param inrixCore
 *      Instance of the IXCLCore class to be used by this class.
 * @param baseRouteOptions
 *      Route options used as a base for requesting routes.  The start point
 *      will be replaced with the current location retrieved from the current
 *      location manager (IXCLCurrentLocationManager).
 *
 * @return
 *      Instance of the IXCLRouteUpdateController class.
 */
- (instancetype) initWithInrixCore: (IXCLCore *) inrixCore
                  baseRouteOptions: (IXCLRoutesFromPointsOptions *) baseRouteOptions;

//-----------------------------------------------------------------------------
#pragma mark - Subscribers

/*!
 * @abstract Adds a subscriber to receive route updates.
 *
 * @param subscriber
 *      A subscriber conforming to the IXCLRouteUpdateControllerSubscriber
 *      protocol.
 *
 * @exception
 *      Subscriber does not conform to the IXCLRouteUpdateControllerSubscriber
 *      protocol.
 */
- (void) addSubscriber: (id <IXCLRouteUpdateSubscriber> ) subscriber;

/*!
 * @abstract
 *      Removes a subscriber so that it will no longer receive route updates.
 *
 * @param subscriber
 *      A subscriber conforming to the IXCLRouteUpdateControllerSubscriber
 *      protocol.
 */
- (void) removeSubscriber: (id <IXCLRouteUpdateSubscriber> ) subscriber;

//-----------------------------------------------------------------------------
#pragma mark - Route Request Management

/*!
 * @abstract
 *      Starts requesting routes to be published to subscribers.
 * @discussion
 *      Route requests that occur due to the timer interval expiring will
 *      retrieve routes from the cache if available.
 */
- (void) startRequestingRoutes;

/*!
 * @abstract
 *      Stops requesting and publishing routes.
 * @discussion
 *      An in-flight request, if any, will not be published, although the
 *      request will be allowed to complete.
 */
- (void) stopRequestingRoutes;

/*!
 * @abstract
 *      Forces routes be requested from the server.
 * @discussion
 *      Routes will not be returned from the cache even if they are available.
 *      The route request timer is restarted so that the next request will be
 *      after the interval specified in the routeRequestTimeInterval property.
 */
- (void) updateRoutesFromServer;

/*!
 * @abstract
 *      Update with new route options.
 * @param routeOptions
 *      The route options to update with.
 * @discussion
 *      Will clear any current route and request new routes using the new
 *      options. For use when changing the current destination or adding
 *      waypoints.
 */
- (void) updateBaseRouteOptions: (IXCLRoutesFromPointsOptions *) routeOptions;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRouteUpdateController
 * @abstract
 *      Object to encapsulate logic to request routes to a single destination
 *      and then publish them to subscribers.
 */
@interface IXCLRouteUpdateController : NSObject<IXCLRouteUpdateControllerProtocol>
@end
