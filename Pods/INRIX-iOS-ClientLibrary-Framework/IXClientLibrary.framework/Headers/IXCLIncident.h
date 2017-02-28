/*
 * @header IXCLIncident.h
 * @abstract Definitions describing incidents.
 * @author Martin Waldron
 * @updated 02-27-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "IXCLMapPoint.h"


@class IXCLIncidentCommunity;
@class IXCLIncidentDelayImpact;
@class IXCLIncidentDescription;
@class IXCLIncidentParameterizedDescription;
@class IXCLRoutePoint;


//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract
 *      Value identifying the type of an incident that can be provided by the
 *      client library.
 *
 * @constant IXCLIncidentTypeInvalid
 *      Invalid or unrecognized type was assigned to the incident.
 * @constant IXCLIncidentTypeConstruction
 *      Construction incident.
 * @constant IXCLIncidentTypeEvent
 *      Event incident, such as a ball game, concert, etc.
 * @constant IXCLIncidentTypeCongestion
 *      Congestion incident, generated to show the location of congestion.
 * @constant IXCLIncidentTypeAccident
 *      Incident describes an accident but could also describe numerous other
 *      types of incidents, further described by the incident code
 *      (IXCLIncidentEventCode).
 * @constant IXCLIncidentTypePolice
 *      Incident describes the location of police, typically reported by a
 *      user.
 * @constant IXCLIncidentTypeFixedCameraTrap
 *      Fixed camera trap incident.
 * @constant IXCLIncidentTypeHazard
 *      Hazard incident. Type of hazard is further described by the incident
 *      code (IXCLIncidentEventCode).
 * @constant IXCLIncidentTypeRoadClosure
 *      Closure incident. Type of closure is further described by the incident
 *      code (IXCLIncidentEventCode).
 */
typedef NS_ENUM (NSUInteger, IXCLIncidentType)
{
    IXCLIncidentTypeInvalid         = 0,
    IXCLIncidentTypeConstruction    = 1,
    IXCLIncidentTypeEvent           = 2,
    IXCLIncidentTypeCongestion      = 3,
    IXCLIncidentTypeAccident        = 4,
    IXCLIncidentTypePolice          = 6,
    IXCLIncidentTypeFixedCameraTrap = 7,
    IXCLIncidentTypeHazard          = 8,
    IXCLIncidentTypeRoadClosure     = 1001
};

/*!
 * @abstract
 *      Value determining the direction of the incident.
 *
 * @constant IXCLIncidentDirectionEastbound
 *      For incidents on roads heading eastward.
 * @constant IXCLIncidentDirectionNorthbound
 *      For incidents on roads heading northward.
 * @constant IXCLIncidentDirectionSouthbound
 *      For incidents on roads heading southward.
 * @constant IXCLIncidentDirectionWestbound
 *      For incidents on roads heading westward.
 * @constant IXCLIncidentDirectionUnknown
 *      When the direction of the incident is not known.
 * @constant IXCLIncidentDirectionBothWays
 *      If the incident covers both sides of the road.
 */
typedef NS_ENUM (NSUInteger, IXCLIncidentDirection)
{
    IXCLIncidentDirectionEastbound  = 0,
    IXCLIncidentDirectionNorthbound = 1,
    IXCLIncidentDirectionSouthbound = 2,
    IXCLIncidentDirectionWestbound  = 3,
    IXCLIncidentDirectionUnknown    = 4,
    IXCLIncidentDirectionBothWays   = 5

};

/*!
 * @abstract
 *      Incident event code.
 * @discussion
 *      Event code further describing an incident beyond the type.  These are
 *      used to define what event code to use when reporting an incident or
 *      when determining whether an "Accident" is actually a road closure.
 *
 * @constant IXCLIncidentEventCodeInvalid
 *      Invalid or unrecognized code was assigned to the incident.
 * @constant IXCLIncidentEventCodeAccident
 *      Type of accident to report.
 * @constant IXCLIncidentEventCodeConstruction
 *      Type of construction to report.
 * @constant IXCLIncidentEventCodeEvent
 *      Type of event to report.
 * @constant IXCLIncidentEventCodeHazard
 *      Type of hazard to report.
 * @constant IXCLIncidentEventCodePolice
 *      Type of police incident to report.
 * @constant IXCLIncidentEventCodeFixedCameraTrap
 *      Type of fixed camera trap to report.
 * @constant IXCLIncidentEventCodeRoadClosureRescueAndRecoveryWorkInProgress
 *      Road closure due to rescue and recovery work in progress.
 * @constant IXCLIncidentEventCodeRoadClosureBridgeClosed
 *      Road closure due to bridge closure.
 * @constant IXCLIncidentEventCodeRoadClosureTunnelClosed
 *      Road closure due to tunnel closure.
 * @constant IXCLIncidentEventCodeRoadClosureIntermittentlyClosed
 *      Intermittent road closure.
 * @constant IXCLIncidentEventCodeRoadClosureDueToAccident
 *      Road closure due to accident.
 * @constant IXCLIncidentEventCodeRoadClosureThreeLanesBlocked
 *      Road closure with three lanes blocked.
 * @constant IXCLIncidentEventCodeRoadClosureClosed
 *      Road closure, no further details provided.
 * @constant IXCLIncidentEventCodeRoadClosureDueToRoadworks
 *      Road closure due to construction.
 * @constant IXCLIncidentEventCodeRoadClosureDueToLandslips
 *      Road closure due to landslips (?).
 * @constant IXCLIncidentEventCodeRoadClosureDueToBurstWaterMain
 *      Road closure due to a burst water main.
 */
typedef NS_ENUM (NSInteger, IXCLIncidentEventCode)
{
    IXCLIncidentEventCodeInvalid         = -1,
    IXCLIncidentEventCodeAccident        = 201,
    IXCLIncidentEventCodeConstruction    = 701,
    IXCLIncidentEventCodeEvent           = 1501,
    IXCLIncidentEventCodeHazard          = 901,
    IXCLIncidentEventCodePolice          = 1477,
    IXCLIncidentEventCodeFixedCameraTrap = 1971,

    IXCLIncidentEventCodeRoadClosureRescueAndRecoveryWorkInProgress = 16,
    IXCLIncidentEventCodeRoadClosureBridgeClosed                    = 24,
    IXCLIncidentEventCodeRoadClosureTunnelClosed                    = 25,
    IXCLIncidentEventCodeRoadClosureIntermittentlyClosed            = 240,
    IXCLIncidentEventCodeRoadClosureDueToAccident                   = 241,
    IXCLIncidentEventCodeRoadClosureThreeLanesBlocked               = 246,
    IXCLIncidentEventCodeRoadClosureClosed                          = 401,
    IXCLIncidentEventCodeRoadClosureDueToRoadworks                  = 735,
    IXCLIncidentEventCodeRoadClosureDueToLandslips                  = 947,
    IXCLIncidentEventCodeRoadClosureDueToBurstWaterMain             = 957,

    // TODO: gagarwal - Fix the names of above codes to what is in CS.
    //                  Create Reporting ENUM corresponding to above code.
};

/*!
 * @abstract
 *      Incident severity level.
 * @discussion
 *      This value can be in the range of 0-4, with 4 indicating the highest severity.
 *
 * @constant IXCLIncidentSeverity0 Incident severity 0. Lowest severity.
 * @constant IXCLIncidentSeverity1 Incident severity 1.
 * @constant IXCLIncidentSeverity2 Incident severity 2.
 * @constant IXCLIncidentSeverity3 Incident severity 3.
 * @constant IXCLIncidentSeverity4 Incident severity 4. Highest severity.
 */
typedef NS_ENUM (NSUInteger, IXCLIncidentSeverity)
{
    IXCLIncidentSeverity0 = 0,
    IXCLIncidentSeverity1,
    IXCLIncidentSeverity2,
    IXCLIncidentSeverity3,
    IXCLIncidentSeverity4,
};

/*!
 * @abstract
 *      Side of road indicator.
 * @discussion
 *      Value specifying the side of the road on which an incident is to be
 *      reported.
 *
 * @constant IXCLIncidentSideOfRoadInvalid
 *      Invalid or unrecognized side of road indicator.
 * @constant IXCLIncidentSideOfRoadThisSide
 *      Reporting incident on the same side of the road as user is driving.
 * @constant IXCLIncidentSideOfRoadOtherSide
 *      Reporting incident on the other side of the road as user is driving.
 * @constant IXCLIncidentSideOfRoadCrossStreetLeft
 *      Unknown.
 * @constant IXCLIncidentSideOfRoadCrossStreetRight
 *      Unknown.
 */
typedef NS_ENUM (NSInteger, IXCLIncidentSideOfRoad)
{
    IXCLIncidentSideOfRoadInvalid          = -1,
    IXCLIncidentSideOfRoadThisSide         = 0,
    IXCLIncidentSideOfRoadOtherSide        = 1,
    IXCLIncidentSideOfRoadCrossStreetLeft  = 2,
    IXCLIncidentSideOfRoadCrossStreetRight = 3,
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLIncident
 * @abstract Model object describing an INRIX incident.
 */
@interface IXCLIncident : IXCLMapPoint <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier associated with the incident.
 */
@property (nonatomic, copy, readwrite) NSString * incidentId;

/*!
 * @abstract The version of the incident report.
 */
@property (nonatomic, copy, readwrite) NSString * version;

/*!
 * @abstract The type of incident.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentType type;

/*!
 * @abstract
 *      The severity of the incident.
 * @discussion
 *      This value can be in the range of 0-4, with 4 indicating the highest
 *      severity.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentSeverity severity;

/*!
 * @abstract The event code associated with the incident.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentEventCode eventCode;

/*!
 * @abstract A Boolean value indicating if the incident is impacting traffic.
 */
@property (nonatomic, assign, readwrite) BOOL isImpactingTraffic;

/*!
 * @abstract Indicates when the incident starts.
 */
@property (nonatomic, strong, readwrite) NSDate * startTime;

/*!
 * @abstract Indicates when the incident ends.
 */
@property (nonatomic, strong, readwrite) NSDate * endTime;

/*!
 * @abstract Short textual description of the incident.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentDescription * shortDescription;

/*!
 * @abstract Longer textual description of the incident.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentDescription * fullDescription;

/*!
 * @abstract Detailed information about the delay caused by the event.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentDelayImpact * delayImpact;

/*!
 * @abstract
 *      Detailed information about the incident specified in the eventCode
 *      attribute.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentParameterizedDescription * parameterizedDescription;

/*!
 * @abstract Source from which incident is compiled.
 */
@property (nonatomic, copy, readwrite) NSString * source;

/*!
 * @abstract Incident community information.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentCommunity * community;

/*!
 * @abstract Location of the furthest point on the road where the incident starts.
 */
@property (nonatomic, strong, readwrite) IXCLRoutePoint * head;

/*!
 * @abstract Location of the points behind the head where the incident ends.
 * @discussion Elements must be of type IXCLRoutePoint.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * tails;

/*!
 * @abstract Location of the last detour points to avoid the incident.
 * @discussion Elements must be of type IXCLRoutePoint.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * lastDetourPoints;

/*!
 * @abstract
 *      Value specifying the side of the road on which an incident is to be
 *      reported.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentSideOfRoad sideOfRoad;

/*!
 * @abstract
 *      A Boolean value indicating whether the incident is votable.
 * @discussion
 *      Some incidents cannot be reviewed.  This property specifies whether
 *      this incident can be reviewed or not.
 */
@property (nonatomic, assign, readwrite) BOOL isVotable;

/*!
 * @abstract
 *      A Boolean value indicating whether the incident is approved on server
 *      after reporting.
 */
@property (nonatomic, assign, readwrite) BOOL isApprovedOnServer;

/*!
 * @abstract
 *      An array of IXCLSegment objects representing TMC segments for this incident.
 */
@property (nonatomic, strong, readwrite) NSArray * segments;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with the specified incident type and coordinate.
 *
 * @param incidentType The type of incident.
 * @param coordinate   The latitude and longitude of incident.
 *
 * @return Instance of the IXCLIncident class.
 */
- (instancetype) initWithType: (IXCLIncidentType) incidentType
                   coordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Obtain the hash value of self.
 *
 * @discussion
 *      This method returns the hash of the incidentId.
 *
 * @return
 *      The hash value of this object.
 */
- (NSUInteger) hash;

/*!
 * @abstract
 *      Check for equality with another object.
 *
 * @discussion
 *      The objects is considered equal if they are of the same type with
 *      matching incidentIds.
 *
 * @param object
 *      The object to test for equality.
 *
 * @return YES if the objects are equal, NO otherwise.
 */
- (BOOL) isEqual: (id) object;

@end
