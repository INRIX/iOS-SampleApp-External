/*
 * @header IXCLCoreOptions.h
 * @abstract Represents parameters for initializing INRIX Core.
 * @author Cheng Cheng
 * @updated 08-03-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

@class IXCLCurrentLocationManager;

/*!
 * @enum IXCLServerEnvironmentType
 *
 * @abstract
 *      Describes which server environment the client application will run against.
 */
typedef NS_ENUM (NSUInteger, IXCLServerEnvironmentType)
{
    IXCLServerEnvironmentTypeProduction = 0,
    IXCLServerEnvironmentTypeBeta,
    IXCLServerEnvironmentTypeQA
};

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLCoreOptions
 * @abstract Represents parameters for creating an @ref InrixCore refeference.
 */
@interface IXCLCoreOptions : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The name of the application.
 * @discussion This value is provided when initializing the IXCLCore instance.
 */
@property (nonatomic, copy, readonly) NSString * applicationName;

/*!
 * @abstract The version number of the application.
 * @discussion This value is provided when initializing the IXCLCore instance.
 */
@property (nonatomic, copy, readonly) NSString * applicationVersion;

/*!
 * @abstract
 *      The ID of the application.
 * @discussion
 *      An application ID is assigned by INRIX.  This value is provided when
 *      initializing the IXCLCore instance.
 */
@property (nonatomic, copy, readonly) NSString * applicationId;

/*!
 * @abstract
 *      The API key of the application.
 * @discussion
 *      An application key is assigned by INRIX.  This value is provided when
 *      initializing the IXCLCore instance.
 */
@property (nonatomic, copy, readonly) NSString * applicationKey;

/*!
 * Return the current trip recording configuration state.
 */
@property (nonatomic, assign, readwrite) BOOL tripRecordingEnabled;

/*!
 * Return the current calendar syncing configuration state.
 */
@property (nonatomic, assign, readwrite) BOOL calendarSyncingEnabled;

/*!
 * A Boolean value indicating whether the core location
 * manager should get updates in the background.
 */
@property (nonatomic, assign, readwrite) BOOL backgroundLocationUpdates;

/*!
 * A Boolean value indicating whether user location service
 * should be automatically updated.
 */
@property (nonatomic, assign, readwrite) BOOL userLocationUpdatesEnabled;

/*!
 * Default coordinates for the currentLocationManager
 * to report when the user's current location is not
 * available.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D defaultCoordinates;

/*!
 * Default value, in minutes, of the pre-drive alert interval for uploaded calendar events.
 * If set to nil, the internal SDK default will be used.
 */
@property (nonatomic, strong, readwrite) NSNumber * calendarEventDefaultAlertInterval;

/*!
 * A flag indicating whether or not to automatically create pre-drive alerts for uploaded
 * calendar events. When set to NO, calendar events are created without
 * pre-drive alerts. When set to YES, calendar events are created with pre-drive alerts
 * using the interval specified in calendarEventDefaultAlertInterval, if defined, or an
 * internal default otherwise.
 */
@property (nonatomic, assign, readwrite) BOOL calendarEventDefaultAlertsEnabled;

/*!
 * @abstract
 *      Specifies which INRIX Server environment to connect with.
 *
 * @discussion
 *      Must be set before initialiazing IXCLCore. Once IXLCore has been initialized,
 *      further changes to this property will have no effect.
 *
 *      This should always be set to IXCLServerEnvironmentTypeProduction, with the
 *      exception of developer-internal builds that are targeting the INRIX Beta
 *      environment.
 */
@property (nonatomic, assign, readwrite) IXCLServerEnvironmentType serverEnvironment;

/*!
 * @abstract
 *       The current location manager to be used.
 * @discussion
 *      This flag allows tests to inject a mock IXCLCurrentLocationManager
 *      into IXCLCore for unit tests.
 *      During normal operation, this property should be left nil. This instructs
 *      IXCLCore to use the default IXCLCurrentLocationManager.
 *
 *      The backgroundUpdates flag will be ignored if currentLocation is set.
 */
@property (nonatomic, strong, readwrite) IXCLCurrentLocationManager * currentLocationManager;

/*!
 * @abstract
 *       If set to YES the SDK will wait for the app to initiate privacy permision dialogs.
 * @discussion
 *       Defaults to NO.
 */
@property (nonatomic, assign, readwrite) BOOL deferPermissionsDialogs;

//-----------------------------------------------------------------------------
#pragma mark - Instance Methods

/*!
 * @abstract
 *      Initialize the IXCLCoreOptions with the specified parameters.
 *
 * @param applicationId
 *      The ID of the application.
 * @param applicationKey
 *      The API key of the application.
 * @param applicationName
 *      The name of the application.
 * @param applicationVersion
 *      The version number of the application.
 *
 * @return
 *      An initialized IXCLCoreOptions object or nil if the object couldn't be
 *      initialized.
 */
- (instancetype) initWithApplicationId: (NSString *) applicationId
                        applicationKey: (NSString *) applicationKey
                       applicationName: (NSString *) applicationName
                    applicationVersion: (NSString *) applicationVersion;

@end
