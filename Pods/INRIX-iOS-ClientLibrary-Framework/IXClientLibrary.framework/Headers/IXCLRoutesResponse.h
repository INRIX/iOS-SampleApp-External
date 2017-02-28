/*
 * @header IXCLRoutesResponse.h
 * @abstract Routes response object passed to completion handlers when making requests.
 * @author Gaurav Agarwal
 * @updated 04-23-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLCoreResponse.h"


@class IXCLRoutesCollection;


//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      The state of routes request made for collecting the routes.
 * @discussion
 *      Defaults to IXCLRoutesStateNone.
 *
 * @constant IXCLRoutesStateNone
 *      The default state.
 * @constant IXCLRoutesStateRequestPending
 *      Request for routes is pending to load from server.
 * @constant IXCLRoutesStateServerUnavailable
 *      Server is unavailable.
 * @constant IXCLRoutesStateNetworkUnavailable
 *      Network is not reachable.
 * @constant IXCLRoutesStateExceedsMaxDistance
 *      Routes distance exceeds maximum routes distance limit.
 * @constant IXCLRoutesStateBelowMinDistance
 *      Routes distance is below minimum routes distance limit.
 * @constant IXCLRoutesStateUnroutableWaypoint
 *      One or more waypoint is not routable.
 * @constant IXCLRoutesStateErrorRequestingRoute
 *      Server error requesting routes.
 * @constant IXCLRoutesStateUnrecoverableErrorRequestingRoute
 *      Unrecoverable server error requesting routes.
 */
typedef NS_ENUM (NSInteger, IXCLRoutesState)
{
    IXCLRoutesStateNone = 0,
    IXCLRoutesStateRequestPending,
    IXCLRoutesStateServerUnavailable,
    IXCLRoutesStateNetworkUnavailable,
    IXCLRoutesStateExceedsMaxDistance,
    IXCLRoutesStateBelowMinDistance,
    IXCLRoutesStateUnroutableWaypoint,
    IXCLRoutesStateErrorRequestingRoute,
    IXCLRoutesStateUnrecoverableErrorRequestingRoute,
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @abstract Represents the status for routes request call.
 */
@interface IXCLRoutesResponse : IXCLCoreResponse <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The collection of routes returned.
 */
@property (nonatomic, strong, readwrite) IXCLRoutesCollection * routesCollection;

//-----------------------------------------------------------------------------
#pragma mark - Class Methods

/// @cond
+ (IXCLRoutesResponse *) routesResponseFromCoreResponse: (IXCLCoreResponse *) coreResponse;

@end
