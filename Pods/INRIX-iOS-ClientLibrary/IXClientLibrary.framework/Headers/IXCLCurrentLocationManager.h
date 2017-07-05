/*
 * @header IXCLCurrentLocationManager.h
 * @abstract
 *      Definitions for managing data related to the device's current location.
 * @author Jason Olson
 * @updated 05-10-2009
 * @copyright Copyright (c) 2009-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark Global Exports

FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerLocationDidChangeNotification;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerAuthChangedNotification;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerFailedNotification;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerLocationDidChangeInBackgroundNotification;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerEnteringBackgroundMode;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerLeavingBackgroundMode;
FOUNDATION_EXPORT NSString * const IXCLCurrentLocationManagerStoppingUpdates;

/*!
 * @abstract
 *      Invalid coordinate to return if region coordinate call fails.
 */
FOUNDATION_EXPORT CLLocationCoordinate2D const IXCLInvalidCoordinate;

/*!
 * @abstract
 *      The states used by the CurrentLocationManager for trip status.
 * @discussion
 *      Note that TripEnding indicates a possible end to the trip.
 *      TripEnding may transition to NotOnTrip or may return to OnTrip.
 */
typedef NS_ENUM (NSUInteger, IXCLCurrentLocationManagerTripStatus)
{
    // This status is currently unused.
    IXCLCurrentLocationManagerTripStatusStarting = 0,
    // These three statuses are set by the TripTrackingController.
    IXCLCurrentLocationManagerTripStatusEnding,
    IXCLCurrentLocationManagerTripStatusOnTrip,
    IXCLCurrentLocationManagerTripStatusNotOnTrip,
};

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration
/*!
 * @protocol IXCLCurrentLocationManagerProtocol
 *  @abstract
 *      Protocol declaration for the Current Location Manager
 */
@protocol IXCLCurrentLocationManagerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Last recorded location.
 */
@property (atomic, strong, readonly) CLLocation * currentUserLocation;

/*!
 * @abstract
 *      A Boolean value indicating whether regular location updates have been
 *      started.
 * @discussion
 *      Location services are started by calling startUpdatingLocation.  Location
 *      services are stopped by calling stopUpdatingLocation. The starting and
 *      stopping of regular location updates is affected by foreground/background
 *      state, location services permissions, and tripStatus.
 */
@property (atomic, readonly) BOOL isStarted;

/*!
 * @abstract
 *      A Boolean value indicating whether the core location manager should attempt
 *      to get updates in the background.
 */
@property (nonatomic, assign, readwrite) BOOL supportsBackgroundUpdates;

/*!
 * @abstract
 *      A Boolean value indicating whether the core location manager should get high
 *      quality location updates in the background.
 * @discussion
 *      This setting is used as one indication that the user is driving.
 */
@property (nonatomic, assign, readwrite) BOOL isInNavigationMode;

/*!
 * @abstract
 *      An enumerated value that indicates the current status of a trip.
 * @discussion
 *      The setting of this property affects the desiredAccuracy and starting
 *      or stopping of regular location updates. This setting is used as one
 *      indication of whether the use is driving.
 */
@property (nonatomic, assign, readonly) IXCLCurrentLocationManagerTripStatus tripStatus;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns whether location services are enabled for the device and they
 *      are authorized for the app.
 *
 * @returns
 *      YES if location services are enabled on the device and they are
 *      authorized for the app; otherwise NO.
 */
- (BOOL) locationServicesEnabledAndAuthorized;

/*!
 * @abstract Starts listening to location changes.
 */
- (void) startUpdatingLocation;

/*!
 * @abstract Stops listening to location changes.
 */
- (void) stopUpdatingLocation;

/*!
 * @abstract
 *      Returns the last known location, e.g. from the last run of the app.
 */
- (CLLocation *) lastKnownLocation;

/*!
 * @abstract
 *      Returns the current location if available; otherwise returns the
 *      last known location.
 */
- (CLLocation *) currentOrLastKnownLocation;

/*!
 * @abstract
 *      Returns the current instance of the location manager, for use outside
 *      the INRIX core.
 */
+ (id <IXCLCurrentLocationManagerProtocol> ) defaultManager;

/*!
 * @abstract
 *      Returns the current instance of the location manager, for use outside
 *      the INRIX core.
 */
+ (CLLocationCoordinate2D) currentOrLastKnownCoordinate;

#ifdef DEBUG
+ (NSString *) classDescription;
#endif

@end

//-----------------------------------------------------------------------------
#pragma mark - IXCLCurrentLocationManager Class Declaration

/*!
 * @class
 *      IXCLCurrentLocationManager
 * @abstract
 *      Implementation of the IXCLCurrentLocationManager protocol with default
 *      behavior.
 */

@interface IXCLCurrentLocationManager : NSObject <IXCLCurrentLocationManagerProtocol>
@end
