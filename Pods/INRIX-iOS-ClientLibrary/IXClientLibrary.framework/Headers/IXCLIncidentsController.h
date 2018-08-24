/*
 * @header IXCLIncidentsController.h
 * @abstract Controller for managing incidents.
 * @author Dmitri Fuerle
 * @updated 09-11-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>

#import "IXCLBaseControllerWithCache.h"
#import "IXCLIncident.h"
#import "IXCLXDIncident.h"
#import "IXCLIncidentBaseOptions.h"

@class IXCLCoreResponse;
@class IXCLIncidentDeleteOptions;
@class IXCLIncidentReportOptions;
@class IXCLIncidentReviewOptions;
@class IXCLIncidentsInBoxOptions;
@class IXCLIncidentsInRadiusOptions;
@class IXCLXDIncidentsInBoxOptions;
@class IXCLXDIncidentsInRadiusOptions;
@class IXCLXDIncidentDetailsOptions;

typedef NSComparisonResult (^ IXCLIncidentsComparator)(IXCLIncident * incident1, IXCLIncident * incident2, CLLocation * location);

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract
 *      Specifies the types of incidents to include in the response when
 *      requesting incidents.
 * @discussion
 *      Multiple types can be requested by using the | operator.
 *
 * @constant IXCLIncidentsFilterIncludeNone         No incidents.
 * @constant IXCLIncidentsFilterIncludeAccident     Include accidents.
 * @constant IXCLIncidentsFilterIncludeCongestion   Include congestion incidents.
 * @constant IXCLIncidentsFilterIncludeConstruction Include construction incidents.
 * @constant IXCLIncidentsFilterIncludeEvent        Include events.
 * @constant IXCLIncidentsFilterIncludePolice       Include police incidents.
 * @constant IXCLIncidentsFilterIncludeHazard       Include hazard incidents.
 * @constant IXCLIncidentsFilterIncludeRoadClosure  Include road closures.
 * @constant IXCLIncidetnsFilterIncludeWeather      Include weather incidents.
 * @constant IXCLIncidentsFilterIncludeAll          Include all filters.
 */
typedef NS_OPTIONS (NSInteger, IXCLIncidentsFilter)
{
    IXCLIncidentsFilterIncludeNone         = 0,
    IXCLIncidentsFilterIncludeAccident     = (1 << 0),
    IXCLIncidentsFilterIncludeCongestion   = (1 << 1),
    IXCLIncidentsFilterIncludeConstruction = (1 << 2),
    IXCLIncidentsFilterIncludeEvent        = (1 << 3),
    IXCLIncidentsFilterIncludePolice       = (1 << 4),
    IXCLIncidentsFilterIncludeHazard       = (1 << 5),
    IXCLIncidentsFilterIncludeRoadClosure  = (1 << 6),
    IXCLIncidentsFilterIncludeLaneClosure  = (1 << 7),
    IXCLIncidentsFilterIncludeWeather      = (1 << 8),
    IXCLIncidentsFilterIncludeAll          = -1
};

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLIncidentsControllerProtocol
 * @abstract
 *      Protocol definition for the Incidents Controller
 */
@protocol IXCLIncidentsControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Recommendation Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing a list of incidents.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing a list of incidents, which could include incidents
 *      displayed on a map or displayed in a list.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshListTimeInterval;

/*!
 * @abstract
 *      Recommended time interval for refreshing a single set of incidents
 *      (e.g. incident details).
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing incident details.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshDetailsTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Instance Methods

/*!
 * @abstract Returns the array of IXCLIncident objects in the completion block.
 *
 * @param options
 *      Options describing the incidents to retrieve from the server.
 * @param incidentsFilter
 *      Filter for both cached incidents and requested incidents from the
 *      server.
 * @param completion
 *      Block that returns an array of IXCLIncident objects, and any errors.
 */
- (void) requestIncidentsInRadiusWithOptions: (IXCLIncidentsInRadiusOptions *) options
                             incidentsFilter: (IXCLIncidentsFilter) incidentsFilter
                                  completion: (void (^)(NSArray * incidents, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLIncident objects in completion block
 *
 * @param options
 *      Options describing the incidents to retrieve from the server.
 * @param incidentsFilter
 *      Filter for both cached incidents and requested incidents from server.
 * @param completion
 *      Block that returns array of IXCLIncident objects, and any errors.
 */
- (void) requestIncidentsInBoxWithOptions: (IXCLIncidentsInBoxOptions *) options
                          incidentsFilter: (IXCLIncidentsFilter) incidentsFilter
                               completion: (void (^)(NSArray * incidents, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLXDIncident objects in the completion block.
 *
 * @param options
 *      Options describing the XD incidents to retrieve from the server.
 * @param incidentsFilter
 *      Filter for both cached incidents and requested incidents from the
 *      server.
 * @param completion
 *      Block that returns an array of IXCLXDIncident objects, and any errors.
 */
- (void) requestXDIncidentsInRadiusWithOptions: (IXCLXDIncidentsInRadiusOptions *) options
                               incidentsFilter: (IXCLIncidentsFilter) incidentsFilter
                                    completion: (void (^)(NSArray * incidents, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLXDIncident objects in completion block
 *
 * @param options
 *      Options describing the XD incidents to retrieve from the server.
 * @param incidentsFilter
 *      Filter for both cached incidents and requested incidents from server.
 * @param completion
 *      Block that returns array of IXCLXDIncident objects, and any errors.
 */
- (void) requestXDIncidentsInBoxWithOptions: (IXCLXDIncidentsInBoxOptions *) options
                            incidentsFilter: (IXCLIncidentsFilter) incidentsFilter
                                 completion: (void (^)(NSArray * incidents, IXCLCoreResponse * coreResponse)) completion;



/*!
 * @abstract Requests details for an array of `IXCLXDIncident` Ids.
 *
 * @param options Describes the incident details to request.
 * @param completion Completion block returning an array of `IXCLXDIncident`s with the requested details.
 */
- (void) requestDetailsForXDIncidentsWithOptions: (IXCLXDIncidentDetailsOptions *) options
                           completion: (void (^)(NSArray<IXCLXDIncident *> * incidents, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Reports an incident to the server.
 *
 * @param options    Options describing the incident to report.
 * @param completion Block that returns created IXCLIncident object, and any errors.
 */

- (void) reportIncidentWithOptions: (IXCLIncidentReportOptions *) options
                        completion: (void (^)(IXCLIncident * reportedIncident, IXCLCoreResponse * coreResponse)) completion;
/*!
 * @abstract Reviews an incident by confirming it or declaring it cleared.
 *
 * @param options    Options describing the incident to review.
 * @param completion Block that returns any errors.
 */

- (void) reviewIncidentWithOptions: (IXCLIncidentReviewOptions *) options
                        completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Deletes an incident.
 *
 * @param options    Options describing the incident to delete.
 * @param completion Block that returns any errors.
 */
- (void) deleteIncidentWithOptions: (IXCLIncidentDeleteOptions *) options
                        completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Creates a new IXCLIncident object parsed from dictionary.
 *
 * @param dictionary Incident dictionary to be parsed.
 *
 * @return Newly created IXCLIncident.
 */
- (IXCLIncident *) incidentFromDictionary: (NSDictionary *) dictionary;

/*!
 * @abstract Returns whether the incident was reported locally.
 *
 * @param incident Incident to check.
 *
 * @return YES if the incident was reported locally, otherwise NO.
 */
- (BOOL) isLocallyReportedIncident: (IXCLIncident *) incident;

/*!
 * @abstract Returns whether the incident has been voted on by the app.
 *
 * @param incident Incident to check.
 *
 * @return YES if the incident was voted on by the app; otherwise NO.
 */
- (BOOL) isVotedOnIncident: (IXCLIncident *) incident;

/*!
 * @abstract Removes all entries from the cache.
 */
- (void) purgeCache;

/*!
 * @abstract Removes all locally reported incidents from local store.
 */
- (void) purgeLocallyReportedIncidentIds;

/*!
 * @abstract
 *      Removes the record of all incidents that have been voted on from local store.
 */
- (void) purgeVotedOnIncidentIds;

/*!
 * @abstract Removes all unconfirmed reported incidents from local store.
 */
- (void) purgeUnconfirmedIncidents;

/*!
 * @abstract Sorts incidents by distance from location using provided comparator.
 *
 * @param incidents  Array of incidents to sort.
 * @param location   Base location
 * @param comparator Comparator used to sort incidents.
 *
 * @return Mutable array of sorted incidents.
 */
- (NSMutableArray *) sortIncidents: (NSMutableArray *) incidents
            byDistanceFromLocation: (CLLocation *) location
                   usingComparator: (IXCLIncidentsComparator) comparator;

/*!
 * @abstract Sorts incidents by distance from location.
 *
 * @param incidents Array of incidents to sort.
 * @param location  Base location
 *
 * @return Mutable array of sorted incidents.
 */
- (NSMutableArray *) sortIncidents: (NSMutableArray *) incidents byDistanceFromLocation: (CLLocation *) location;

/*!
 * @abstract
 *      Replaces values in properties specified to use default values with the
 *      default values stored in the controller.
 * @param options
 *      Options to replace the defaults with.
 */
- (void) replaceDefaultsInRequestOptions: (IXCLIncidentBaseOptions *) options;

//-----------------------------------------------------------------------------
#pragma mark - Class Methods

/*!
 * @abstract Filters out incidents that don't match the specified criteria.
 *
 * @param incidents       Array of incidents to filter.
 * @param incidentsFilter Filter criteria.
 *
 * @return Mutable array of filtered incidents.
 */
+ (NSMutableArray *) filterIncidents: (NSArray *) incidents withFilter: (IXCLIncidentsFilter) incidentsFilter;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLIncidentsController
 * @abstract Controller for managing incidents.
 */
@interface IXCLIncidentsController : IXCLBaseControllerWithCache<IXCLIncidentsControllerProtocol>
@end
