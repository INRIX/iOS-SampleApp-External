/*
 * @header IXCLIncidentsOnRouteTrackingController.h
 * @abstract Controller for tracking the incidents along a route.
 * @author Gaurav Agarwal
 * @updated 08-13-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseRouteTrackingController.h"


@class IXCLDriveTimeAlertsOptions;


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Minimum allowed driving speed in miles per hour to filter incidents.
 * @discussion
 *      Value is 10 mph.
 */
FOUNDATION_EXPORT CGFloat const IXCLIncidentsOnRouteTrackingDefaultMinimumSpeedInMilesPerHour;

/*!
 * @abstract
 *      Maximum allowed distance between incidents to included them to a
 *      single cluster.
 * @discussion
 *      Value is 150 feet.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLIncidentsOnRouteTrackingDefaultClusterRadiusInMeters;

/*!
 * @abstract
 *      Incidents are on route if distance between them and route is greate
 *      than this threshold.
 * @discussion
 *      Value is 300 meters.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLIncidentsOnRouteTrackingDefaultThresholdInMeters;


//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLIncidentsOnRouteTrackingControllerProtocol
 * @abstract
 *      Protocol definition for the Incidents-On-Route Tracking Controller
 */
@protocol IXCLIncidentsOnRouteTrackingControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The list of incident IDs we already sent alerts on.
 */
@property (nonatomic, strong, readwrite) NSMutableSet * incidentsAlerted;

/*!
 * @abstract Options for configuring the drive time alerts.
 */
@property (nonatomic, strong, readwrite) IXCLDriveTimeAlertsOptions * options;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns cluster of incidents closest to the current location.
 * @param location
 *      The location on route used to determine incidents to alert.
 * @return An NSArray of IXCLIncidents.
 */
- (NSArray *) incidentsClusterToAlertForLocation: (CLLocation *) location;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLIncidentsOnRouteTrackingController
 * @abstract Controller for tracking the incidents along a route.
 */
@interface IXCLIncidentsOnRouteTrackingController : IXCLBaseRouteTrackingController<IXCLIncidentsOnRouteTrackingControllerProtocol>
@end
