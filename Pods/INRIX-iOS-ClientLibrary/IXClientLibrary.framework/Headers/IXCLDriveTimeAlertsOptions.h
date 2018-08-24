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
#import "IXCLIncidentsController.h"
#import "IXCLDriveTimeAlert.h"

@class IXCLIncident;
@class IXCLParkingLot;
@class IXCLRoute;

typedef BOOL (^ IXCLDriveTimeAlertsFilter) (IXCLDriveTimeAlert * alert);
typedef void (^ IXCLDriveTimeAlertsNotificationBlock) (NSArray <IXCLDriveTimeAlert *> * alerts, NSError * error);
typedef NSComparisonResult (^ IXCLDriveTimeAlertsComparator)(IXCLDriveTimeAlert *alert1, IXCLDriveTimeAlert *alert2);

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

/*!
 * @abstract
 *      Value which indicates the angle relative to current course to filter out irrelevant alerts.
 */
FOUNDATION_EXPORT CGFloat const IXCLDriveTimeAlertConeAheadDefaultAngle;

/*!
 * @abstract
 *      Represents invalid angle for Direction Cone.
 * @discussion
 *      Specify None Angle for cone to include any direction.
 */
FOUNDATION_EXPORT CGFloat const IXCLDirectionConeAngleNone;

/*!
 * @abstract
 *      Specifies default initial distance requirement for alerting to start.
 *      Alerts will be suppresed until user moves far enough from DTA start
 *      location.
 *      Value is 100 meters.
 */
FOUNDATION_EXPORT CLLocationDistance const IXCLDefaultAlertingStartDistance;

/*!
 * @abstract
 *      Specifies default minimum time interval for alert to be shown again.
 *      Value is 10 minutes.
 */
FOUNDATION_EXPORT NSTimeInterval const IXCLDefaultAlertsResetInterval;

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
 * @abstract Filter to filter out alerts.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsFilter isAlertAllowedFilter;

/*!
 * @abstract
 *      Alerts comparator which will be used to sort alerts before
 *      returning a set of alerst.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsComparator comparator;

/*!
 * @abstract
 *      Alerts notification block.
 * @discussion
 *      This notification block will return the list of alerts to be
 *      sent, or error if any.
 */
@property (nonatomic, copy, readwrite) IXCLDriveTimeAlertsNotificationBlock notificationBlock;

/*!
 * @abstract
 *      Angle relative to current course which determines whether
 *      some point of interest should trigger an alert.
 * @discussion
 *      Alerts outside the angle will be ignored.
 *      Defaults to IXCLDriveTimeAlertConeAheadDefaultAngle.
 */
@property (nonatomic, assign, readwrite) CGFloat coneAheadAngle;

/*!
 * @abstract
 *      Specifies initial distance requirement for alerting to start.
 *      Alerts will be suppresed until user moves far enough from DTA start
 *      location.
 *      Default value is IXCLDefaultAlertingStartDistance.
 */
@property (nonatomic, assign, readwrite) CLLocationDistance alertsStartDistance;

/*!
 * @abstract
 *      Specifies minimum time interval for alert to be shown again.
 *      Default value is IXCLDefaultAlertsResetInterval.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval alertsResetInterval;

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
