/*
 * @header IXCLCore.h
 * @abstract Primary interface for calling INRIX web services.
 * @author Dmitri Fuerle
 * @updated 10-17-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "IXCLCoreOptions.h"
#import "IXCLCurrentLocationManager.h"


@class IXCLAnalyticsController;
@class IXCLAuthController;
@class IXCLCalendarEventController;
@class IXCLCamerasController;
@class IXCLCoreResponse;
@class IXCLDriveTimeAlertsController;
@class IXCLEDustController;
@class IXCLGasStationsController;
@class IXCLGeocodeController;
@class IXCLIncidentsController;
@class IXCLItineraryController;
@class IXCLLocation;
@class IXCLLocationsController;
@class IXCLMobileStatController;
@class IXCLParkingLotsController;
@class IXCLPHSController;
@class IXCLProductsController;
@class IXCLNetworkReachabilityController;
@class IXCLRouteTravelTimesController;
@class IXCLRoutesController;
@class IXCLTripController;
@class IXCLSDKConfigController;
@class IXCLSearchController;
@class IXCLTrafficQualityController;
@class IXCLTrafficTilesController;
@class IXCLTripLibraryController;
@class IXCLUserPropertiesController;
@class IXCLDangerousSlowdownsController;
@class IXCLSpeedLimitController;

//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract The version of this library.
 */
FOUNDATION_EXPORT NSString * const IXCLCoreVersion;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

//-----------------------------------------------------------------------------
#pragma mark - Enums

/*!
 * @abstract iOS System services that require permission dialogs.
 * @discussion Once a permission value is set it can only be changed by the user in
 * the system's privacy settings. Be sure to ask for the correct permission the first time.
 * Especially in the case of what kind of location permission to ask for.
 */
typedef NS_ENUM (NSInteger, IXCLCoreServiceType)
{
    IXCLCoreServiceTypeLocationWhenInUse,
    IXCLCoreServiceTypeLocationAlways,
    IXCLCoreServiceTypeCalendar,
    IXCLCoreServiceTypeMotion
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration
/*!
 * @abstract Primary interface for calling INRIX web services.
 */
@interface IXCLCore : NSObject
//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The name of the application.
 * @discussion This value is provided when initializing the IXCLCore instance.
 */
@property (nonatomic, readonly) NSString * applicationName;

/*!
 * @abstract The version number of the application.
 * @discussion This value is provided when initializing the IXCLCore instance.
 */
@property (nonatomic, readonly) NSString * applicationVersion;

/*!
 * @abstract
 *      The ID of the application.
 * @discussion
 *      An application ID is assigned by INRIX.  This value is provided when
 *      initializing the IXCLCore instance.
 */
@property (nonatomic, readonly) NSString * applicationId;

/*!
 * @abstract
 *      The API key of the application.
 * @discussion
 *      An application key is assigned by INRIX.  This value is provided when
 *      initializing the IXCLCore instance.
 */
@property (nonatomic, readonly) NSString * applicationKey;

/*!
 * @abstract
 *      The language identifier to use for the INRIX web service API calls
 *      that support a language or locale parameter.
 * @discussion
 *      This property defaults to the first language in the user's language
 *      preference setting. If this property is set to nil, no language
 *      parameter is passed to the INRIX web service calls. The identifier
 *      is expected to be a two character ISO 639-1 code (called a language
 *      designator by Apple) with an optional region code (called a region
 *      designator by Apple). For example, "en" for english or "en-US" for
 *      english with US as a region.
 *
 *      Defaults to [[NSBundle mainBundle] preferredLocalizations].firstObject.
 */
@property (nonatomic, readwrite) NSString * languageIdentifier;

/*!
 * @abstract
 *      A Boolean value indicating whether the INRIX Core infrastructure has
 *      been shut down or not.
 * @discussion
 *      If shut down, any action (whether requested or asynchronous) will fail
 *      or be ignored.  Effectively, any pending actions will be canceled.
 */
@property (atomic, assign, readonly) BOOL isShutDown;

//-----------------------------------------------------------------------------
#pragma mark Controller Properties

/*!
 * @abstract The current location manager to be used.
 * @discussion This value is provided when initializing the IXCLCore instance.
 */
@property (nonatomic, strong, readonly) IXCLCurrentLocationManager * currentLocationManager;

/*!
 * @abstract
 *      The drive time alerts controller to be used.
 * @discussion
 *      The drive time alerts controller provides functionality for drive time
 *      alerts. This controller is created the first time this property is
 *      referenced.
 */
@property (nonatomic, strong, readonly) IXCLDriveTimeAlertsController * driveTimeAlertsController;

/*!
 * @abstract
 *      The auth controller to be used.
 * @discussion
 *      The auth controller is used internally to authenticate access to INRIX
 *      web services.  In most cases, clients of this library will never need
 *      to reference this controller directly.  This controller is created the
 *      first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLAuthController * authController;

/*!
 * @abstract
 *      The cameras controller to be used.
 * @discussion
 *      The cameras controller provides functionality for requesting
 *      information about traffic cameras. This controller is created the first
 *      time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLCamerasController * camerasController;

/*!
 * @abstract
 *      The gas stations controller to be used.
 * @discussion
 *      The gas stations controller provides functionality for requesting,
 *      information on gas stations  This controller is created the first
 *      time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLGasStationsController * gasStationsController;

/*!
 * @abstract
 *      The geocode controller to be used.
 * @discussion
 *      The geocode controller provide forward and reverse geocoding functionality.
 */
@property (nonatomic, strong, readonly) IXCLGeocodeController * geocodeController;

/*!
 * @abstract
 *      The incidents controller to be used.
 * @discussion
 *      The incidents controller provides functionality for requesting,
 *      reporting, reviewing, and deleting incidents.  It also supports
 *      caching requested incidents.  This controller is created the first time
 *      this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLIncidentsController * incidentsController;

/*!
 * @abstract
 *      The itineraries controller to be used.
 * @discussion
 *      The itineraries controller provides functionality for requesting itinerary
 *      from server. This controller is created the first time this property is
 *      referenced.
 */
@property (nonatomic, strong, readonly) IXCLItineraryController * itineraryController;

/*!
 * @abstract
 *      The locations controller to be used.
 * @discussion
 *      The locations controller provides functionality for requesting,
 *      creating, updating, and deleting saved locations.  It also supports
 *      caching requested locations.  This controller is created the first time
 *      this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLLocationsController * locationsController;

/*!
 * @abstract
 *      The network reachability controller to be used.
 * @discussion
 *      The network reachability controller provides functionality for
 *      requesting and being notified of changes in the reachability of data
 *      network resources.  This controller is created when initializing the
 *      IXCLCore instance.
 */
@property (nonatomic, strong, readonly) IXCLNetworkReachabilityController * networkReachabilityController;

/*!
 * @abstract
 *      The parking lots controller to be used.
 * @discussion
 *      The parking lots controller provides functionality for request parking lots
 *      in radius, in box, or retrieve parking lots by a list of parking lot ids.
 *      This controller is created when initializing the IXCLCore
 */
@property (nonatomic, strong, readonly) IXCLParkingLotsController * parkingLotsController;

/*!
 * @abstract
 *      The products controller to be used.
 * @discussion
 *      The products controller provides functionality for requesting products
 *      available in a specified country. This controller is created when
 *      initializing the IXCLCore instance.
 */
@property (nonatomic, strong, readonly) IXCLProductsController * productsController;

/*!
 * @abstract
 *      The routes controller to be used.
 * @discussion
 *      The routes controller provides functionality for request routes between
 *      two points or along a path described by intermediate waypoints.  It
 *      also supports caching requested routes.  This controller is created the
 *      first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLRoutesController * routesController;

/*!
 * @abstract
 *      The route travel times controller to be used.
 * @discussion
 *      The route travel times controller provides functionality for requesting
 *      travel times along a route, e.g. for consecutive time intervals.  It
 *      also supports caching requested route travel times.  This controller is
 *      created the first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLRouteTravelTimesController * routeTravelTimesController;

/*!
 * @abstract
 *      The search controller to be used.
 * @discussion
 *      The search controller provides functionality for managing search data
 *      sources and performing searches on them.  This controller is
 *      created the first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLSearchController * searchController;

/*!
 * @abstract
 *      The trip controller to be used.
 * @discussion
 *      The trip controller provides functionality for requesting the trips
 *      library and get itinerary from server.
 *      This controller is created the first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLTripController * tripController;


/*!
 * @abstract
 *      The traffic quality controller to be used.
 * @discussion
 *      The traffic quality controller provides functionality for requesting
 *      a summarized traffic quality for a region surrounding a particular
 *      point.  It also supports caching requested traffic quality data.  This
 *      controller is created the first time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLTrafficQualityController * trafficQualityController;

/*!
 * @abstract
 *      The traffic tiles controller to be used.
 * @discussion
 *      The traffic tiles controller provides functionality for requesting
 *      traffic tiles for a specific quad key.  A quad key defines a 256x256
 *      pixel region of the map at a specific zoom level.  It also supports
 *      caching traffic tile requests.  This controller is created the first
 *      time this property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLTrafficTilesController * trafficTilesController;

/*!
 * @abstract
 *      The user properties controller to be used.
 * @discussion
 *      The user properties controller provides a mechanism for saving
 *      and retrieving properties associated with the currently logged-in user.
 *      This controller is created the first time the property is referenced.
 */
@property (nonatomic, strong, readonly) IXCLUserPropertiesController * userPropertiesController;

/*!
 * @abstract
 *      The dangerous slowdowns controller.
 * @discussion
 *      The dangerous slowdowns controller provides a mechanism for requesting
 *      dangerous slowdown information.
 */
@property (nonatomic, strong, readonly) IXCLDangerousSlowdownsController * dangerousSlowdownsController;

/*!
 * @abstract
 *      The speed limit controller.
 * @discussion
 *      The speed limit controller provides a mechanism for requesting
 *      speed limit information.
 */
@property (nonatomic, strong, readonly) IXCLSpeedLimitController * speedLimitController;

//-----------------------------------------------------------------------------
#pragma mark - Instance Methods

/*!
 * @abstract
 *      Initialize the INRIX core with the specified options.
 * @discussion
 *      The current location manager will be started for location updates if
 *      not already started.
 *
 * @param options
 *      The options to create IXCLCore.
 *
 * @return
 *      An initialized IXCLCore object or nil if the object couldn't be
 *      initialized.
 */
- (instancetype) initWithOptions: (IXCLCoreOptions *) options;


/*!
 * @abstract
 *      Shuts down the INRIX Core infrastructure.
 * @discussion
 *      If shut down, any action (whether requested or asynchronous) will fail
 *      or be ignored.  Effectively, any pending actions will be canceled.
 */
- (void) shutDown;

/*!
 * @abstract
 *      Asynchronously invoke a CS service directly.
 * @discussion
 *      This method allows the caller to invoke a CS service directly through
 *      a GET request. This method will automatically include the current access
 *      token. Results are returned through a completion block.
 *      This method defaults to the North American region. This method is also
 *      available in a form accepting a `regionParameter` for use outside North
 *      America.
 * @param actionName
 *      CS Action to query.
 * @param queryParameters
 *      Dictionary of NSString query parameters for the named action. This
 *      dictionary should not contain the current access token or the action name.
 * @param completion
 *      Completion block that will be called with the server's response.
 */
- (void) invokeService: (NSString *) actionName
       queryParameters: (NSDictionary *) queryParameters
            completion: (void (^)(NSString * result, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Asynchronously invoke a CS service directly.
 * @discussion
 *      This method allows the caller to invoke a CS service directly through
 *      a GET request. This method will automatically include the current access
 *      token. Results are returned through a completion block.
 * @param actionName
 *      CS Action to query.
 * @param queryParameters
 *      Dictionary of NSString query parameters for the named action. This
 *      dictionary should not contain the current access token or the action name.
 * @param regionParameter
 *      A `CLLocationCoordinate2D` used to determine the region for the call.
 @param completion
 *      Completion block that will be called with the server's response.
 */
- (void) invokeService: (NSString *)actionName
       queryParameters: (NSDictionary *)queryParameters
       regionParameter: (CLLocationCoordinate2D) regionParameter
            completion: (void (^)(NSString *, IXCLCoreResponse *))completion;

/*!
 * @abstract
 *      Presents a permission dialog for specified service. Will do nothing if
 *      the permission setting has already been set.
 *
 * @param serviceType
 *      Service to get permission for.
 */
- (void) requestPermissionForService: (IXCLCoreServiceType) serviceType;


//-----------------------------------------------------------------------------
#pragma mark - Class Methods

/*!
 * @abstract
 *      Returns the version of the INRIX Client Library.
 * @discussion
 *      The version consists of a major version, a minor version, a maintenance
 *      release number, and a build number.  The build number consists of a
 *      date and a time.  Example: 1.0.0.1406181422.
 *
 * @return
 *      A string representation of the version of the library.
 */
+ (NSString *) libraryVersion;

/*!
 * @abstract
 *      Returns the build date of the INRIX Client Library.
 * @discussion
 *      The build date is also incorporated into the version.
 *
 * @return
 *      The date the library was built.
 */
+ (NSDate *) libraryBuildDate;

@end
