/*
 * @header IXCLDriveTimeAlertsOptions.h
 * @abstract Drive time alerts options.
 * @author Gaurav Agarwal
 * @updated 08-05-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLRouteTrackingController.h"


@class IXCLIncident;
@class IXCLParkingLot;
@class IXCLRoute;

typedef BOOL (^ IXCLDriveTimeAlertsIncidentFilterBlock) (IXCLIncident * incident);
typedef void (^ IXCLDriveTimeAlertsNotificationBlock) (NSArray * incidents, NSError * error);
typedef BOOL (^ IXCLDriveTimeAlertsParkingFilterBlock) (IXCLParkingLot * parking);
typedef void (^ IXCLDriveTimeAlertsParkingNotificationBlock) (NSArray * parking, NSError * error);


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Value which indicates that the default value stored in the
 *      notificationInterval property should be used.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLDriveTimeAlertsOptionsNotificationIntervalUseDefault;

/*!
 * @abstract
 *      Value which indicates that the default value stored in the
 *      speedFactor property should be used.
 */
FOUNDATION_EXPORT CGFloat const IXCLDriveTimeAlertsOptionsSpeedFactorUseDefault;

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLDriveTimeAlertsOptions
 * @abstract Represents parameters for creating drive time alerts.
 */
@interface IXCLDriveTimeAlertsOptions : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Route on which drive time alerts need to be tracked.
 */
@property (nonatomic, strong, readwrite) IXCLRoute * route;

/*!
 * @abstract
 *      Desired notification interval in seconds.
 * @discussion
 *      Defaults to IXCLDriveTimeAlertsOptionsNotificationIntervalUseDefault.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval notificationInterval;

/*!
 * @abstract
 *      This value is used to dynamically determine incident distance
 *      depending on current speed.
 * @discussion
 *      For example, if the speedFactor property is set to 10 and the user's
 *      current speed is 60 mph, a request will be made for incidents in a 6
 *      mile radius (60 / 10 = 6). A higher speed will result in a bigger
 *      radius. Defaults to IXCLDriveTimeAlertsOptionsSpeedFactorUseDefault.
 */
@property (nonatomic, assign, readwrite) CGFloat speedFactor;

/*!
 * @abstract Filter to filter out incidents.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsIncidentFilterBlock isIncidentAllowedFilter;

/*!
 * @abstract
 *      Incident comparator which will be used to sort incidents before
 *      returning a set of incidents.
 */
@property (nonatomic, copy, readwrite) NSComparator comparator;

/*!
 * @abstract
 *      Incidents alerts notification block.
 * @discussion
 *      This notification block will return the list of incidents to be
 *      alerted, or error if any.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsNotificationBlock notificationBlock;

/*!
 * @abstract
 *      Parking alerts notification block.
 * @discussion
 *      This notification block will return the list of parking to be
 *      alerted, or error if any.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsParkingNotificationBlock parkingNotificationBlock;

/*!
 * @abstract
 *      Route progression status tracking notification block.
 * @discussion
 *      This notification block will return the route tracking status.
 */
@property (nonatomic, copy, readwrite) IXCLRouteTrackingStatusNotificationBlock routeTrackingStatusNotificationBlock;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Determines whether the combination of properties are valid.
 *
 * @return
 *      NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
