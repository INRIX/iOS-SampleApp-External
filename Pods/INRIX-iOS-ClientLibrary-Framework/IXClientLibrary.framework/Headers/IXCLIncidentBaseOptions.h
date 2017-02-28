/*
 * @header IXCLIncidentBaseOptions.h
 * @abstract Represents request parameters for incidents in box and radius calls.
 * @author Gaurav Agarwal
 * @updated 03-11-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

#import "IXCLBaseOptions.h"
#import "IXCLIncident.h"


//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract
 *      The type(s) of incident requested.
 * @discussion
 *      Multiple types can be requested by using the | operator.
 *
 * @constant IXCLIncidentOptionsTypeUseDefault
 *      Return default types.  Default types are specified by the
 *      defaultOptionsTypeMask property on IXCLIncidentsController.
 * @constant IXCLIncidentOptionsTypeMaskIncidents
 *      Return all unusual incidents that may slow down traffic such as a car
 *      accident.
 * @constant IXCLIncidentOptionsTypeMaskConstruction
 *      Return only construction incidents.
 * @constant IXCLIncidentOptionsTypeMaskEvents
 *      Return unusual events slated for the area such as a major sporting
 *      event.
 * @constant IXCLIncidentOptionsTypeMaskPolice
 *      Return only police incident.
 * @constant IXCLIncidentOptionsTypeMaskFlow
 *      Return reports about the slowing down of traffic on your route.
 * @constant IXCLIncidentOptionsTypeMaskWeather
 *      Return unusual weather incidents that could alter traffic speed.
 * @constant IXCLIncidentOptionsTypeMaskAll
 *      Return all incidents.
 */
typedef NS_OPTIONS (NSUInteger, IXCLIncidentOptionsTypeMask)
{
    IXCLIncidentOptionsTypeUseDefault = 0,

    IXCLIncidentOptionsTypeMaskIncidents    = (1 << 0),
    IXCLIncidentOptionsTypeMaskConstruction = (1 << 1),
    IXCLIncidentOptionsTypeMaskEvents       = (1 << 2),
    IXCLIncidentOptionsTypeMaskFlow         = (1 << 3),
    IXCLIncidentOptionsTypeMaskPolice       = (1 << 4),
    IXCLIncidentOptionsTypeMaskWeather      = (1 << 5),
    IXCLIncidentOptionsTypeMaskHazard       = (1 << 6),
    IXCLIncidentOptionsTypeMaskAll          = (IXCLIncidentOptionsTypeMaskIncidents |
                                               IXCLIncidentOptionsTypeMaskConstruction |
                                               IXCLIncidentOptionsTypeMaskEvents |
                                               IXCLIncidentOptionsTypeMaskFlow |
                                               IXCLIncidentOptionsTypeMaskPolice |
                                               IXCLIncidentOptionsTypeMaskWeather |
                                               IXCLIncidentOptionsTypeMaskHazard),

    // TODO: gagarwal - Check for Weather, Hazard and Police?
};

/*!
 * @abstract
 *      The sources from which incidents should be returned in the server
 *      response.
 *
 * @constant IXCLIncidentOptionsSourceUseDefault
 *      Return incidents from the default sources specified by the
 *      defaultOptionsSource on IXCLIncidentsController.
 * @constant IXCLIncidentOptionsSourceINRIXOnly
 *      Return incidents from non-commercial sources.
 * @constant IXCLIncidentOptionsSourceCommunity
 *      Return incidents from community sources.
 * @constant IXCLIncidentOptionsSourceAll
 *      Return incidents from all sources.
 */
typedef NS_ENUM (NSUInteger, IXCLIncidentOptionsSource)
{
    IXCLIncidentOptionsSourceUseDefault = 0,

    IXCLIncidentOptionsSourceINRIXOnly,
    IXCLIncidentOptionsSourceCommunity,

    IXCLIncidentOptionsSourceAll = 255
};


/*!
 * @abstract
 *      Incident severity level.
 * @discussion
 *      This value can be in the range of 0-4, with 4 indicating the highest
 *      severity.
 *
 * @constant IXCLIncidentOptionsSeverityUseDefault
 *      Default incident severities specified by the
 *      defaultOptionsSeverityMask on IXCLIncidentsController.
 * @constant IXCLIncidentOptionsSeverityMask0
 *      Incident severity 0. Lowest severity.
 * @constant IXCLIncidentOptionsSeverityMask1
 *      Incident severity 1.
 * @constant IXCLIncidentOptionsSeverityMask2
 *      Incident severity 2.
 * @constant IXCLIncidentOptionsSeverityMask3
 *      Incident severity 3.
 * @constant IXCLIncidentOptionsSeverityMask4
 *      Incident severity 4. Highest severity.
 */
typedef NS_OPTIONS (NSUInteger, IXCLIncidentOptionsSeverityMask)
{
    IXCLIncidentOptionsSeverityUseDefault = 0,

    IXCLIncidentOptionsSeverityMask0   = (1 << IXCLIncidentSeverity0),
    IXCLIncidentOptionsSeverityMask1   = (1 << IXCLIncidentSeverity1),
    IXCLIncidentOptionsSeverityMask2   = (1 << IXCLIncidentSeverity2),
    IXCLIncidentOptionsSeverityMask3   = (1 << IXCLIncidentSeverity3),
    IXCLIncidentOptionsSeverityMask4   = (1 << IXCLIncidentSeverity4),
    IXCLIncidentOptionsSeverityMaskAll = (IXCLIncidentOptionsSeverityMask0 |
                                          IXCLIncidentOptionsSeverityMask1 |
                                          IXCLIncidentOptionsSeverityMask2 |
                                          IXCLIncidentOptionsSeverityMask3 |
                                          IXCLIncidentOptionsSeverityMask4),
};


/*!
 * @abstract
 *      The incident fields to output.
 *
 * @constant IXCLIncidentOutputFieldsMaskID
 *      The unique identifier of an incident.
 * @constant IXCLIncidentOutputFieldsMaskVersion
 *      The version number of the incident report, incremented each time an incident report is updated.
 * @constant IXCLIncidentOutputFieldsMaskType
 *      The type of the incident.
 * @constant IXCLIncidentOutputFieldsMaskSeverity
 *      The severity of the incident.
 * @constant IXCLIncidentOutputFieldsMaskEventCode
 *      The event code of the incident. These are standard Alert-C event codes.
 * @constant IXCLIncidentOutputFieldsMaskLatLong
 *      The latitude and longitude of the incident.
 * @constant IXCLIncidentOutputFieldsMaskImpacting
 *      Whether the incident impacts traffic flow.
 * @constant IXCLIncidentOutputFieldsMaskStartTime
 *      The starting time of the incident.
 * @constant IXCLIncidentOutputFieldsMaskEndTime
 *      The end time of the incident.
 * @constant IXCLIncidentOutputFieldsMaskDelayImpact
 *      Provide the delay in minutes versus typical conditions and versus free flow conditions.
 * @constant IXCLIncidentOutputFieldsMaskArea
 *      The points in a polygon that describes a weather incident that is returned.
 * @constant IXCLIncidentOutputFieldsMaskTMCs
 *      The list of TMC segments affected by this incident.
 * @constant IXCLIncidentOutputFieldsMaskParameterizedDescription
 *      The description separated into parameters.
 * @constant IXCLIncidentOutputFieldsMaskRDS
 *      The Radio Data System data. See the RDS element for more information.
 * @constant IXCLIncidentOutputFieldsMaskShortDescription
 *      Short textual description of the incident including language code.
 * @constant IXCLIncidentOutputFieldsMaskFullDescription
 *      Longer textual description of the incident including language code.
 * @constant IXCLIncidentOutputFieldsMaskTTSDescription
 *      The incident is described as if a human were reading the incident. XDIncident only.
 * @constant IXCLIncidentOutputFieldsMaskHeadTail
 *      The location of the start and end of the incident.
 * @constant IXCLIncidentOutputFieldsMaskAll
 *      All fields.
 */
typedef NS_OPTIONS (NSUInteger, IXCLIncidentOutputFieldsMask)
{
    IXCLIncidentOutputFieldsUseDefault = 0,

    IXCLIncidentOutputFieldsMaskID                       = (1 << 0),
    IXCLIncidentOutputFieldsMaskVersion                  = (1 << 1),
    IXCLIncidentOutputFieldsMaskType                     = (1 << 2),
    IXCLIncidentOutputFieldsMaskSeverity                 = (1 << 3),
    IXCLIncidentOutputFieldsMaskEventCode                = (1 << 4),
    IXCLIncidentOutputFieldsMaskLatLong                  = (1 << 5),
    IXCLIncidentOutputFieldsMaskImpacting                = (1 << 6),
    IXCLIncidentOutputFieldsMaskStartTime                = (1 << 7),
    IXCLIncidentOutputFieldsMaskEndTime                  = (1 << 8),
    IXCLIncidentOutputFieldsMaskDelayImpact              = (1 << 9),
    IXCLIncidentOutputFieldsMaskArea                     = (1 << 10),
    IXCLIncidentOutputFieldsMaskTMCs                     = (1 << 11),
    IXCLIncidentOutputFieldsMaskParameterizedDescription = (1 << 12),
    IXCLIncidentOutputFieldsMaskRDS                      = (1 << 13),
    IXCLIncidentOutputFieldsMaskShortDescription         = (1 << 14),
    IXCLIncidentOutputFieldsMaskFullDescription          = (1 << 15),
    IXCLIncidentOutputFieldsMaskTTSDescription           = (1 << 16),
    IXCLIncidentOutputFieldsMaskHeadTail                 = (1 << 17),
    IXCLIncidentOutputFieldsMaskAll                      = (IXCLIncidentOutputFieldsMaskID |
                                                            IXCLIncidentOutputFieldsMaskVersion |
                                                            IXCLIncidentOutputFieldsMaskType |
                                                            IXCLIncidentOutputFieldsMaskSeverity |
                                                            IXCLIncidentOutputFieldsMaskEventCode |
                                                            IXCLIncidentOutputFieldsMaskLatLong |
                                                            IXCLIncidentOutputFieldsMaskImpacting |
                                                            IXCLIncidentOutputFieldsMaskStartTime |
                                                            IXCLIncidentOutputFieldsMaskEndTime |
                                                            IXCLIncidentOutputFieldsMaskDelayImpact |
                                                            IXCLIncidentOutputFieldsMaskArea |
                                                            IXCLIncidentOutputFieldsMaskTMCs |
                                                            IXCLIncidentOutputFieldsMaskParameterizedDescription |
                                                            IXCLIncidentOutputFieldsMaskRDS |
                                                            IXCLIncidentOutputFieldsMaskShortDescription |
                                                            IXCLIncidentOutputFieldsMaskFullDescription |
                                                            IXCLIncidentOutputFieldsMaskTTSDescription |
                                                            IXCLIncidentOutputFieldsMaskHeadTail),
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class
 *      IXCLIncidentBaseOptions
 * @abstract
 *      Represents request parameters for incidents in box and radius calls.
 */
@interface IXCLIncidentBaseOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The type(s) of incident requested.
 * @discussion
 *      More than one option can be specified by using the | operator.
 *      Defaults to IXCLIncidentOptionsTypeUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentOptionsTypeMask typeMask;

/*!
 * @abstract
 *      The sources from which incidents should be returned in the server
 *      response.
 * @discussion
 *      A value of IXCLIncidentOptionSourceINRIXOnly specifies that incidents
 *      are compiled from non-commercial sources, such as flow incidents that
 *      are generated programmatically from INRIX traffic information or
 *      planned construction incidents.  A value of
 *      IXCLIncidentOptionSourceCommunity specifies that incidents come from
 *      community sources, such as incidents submitted through mobile devices.
 *      The default is IXCLIncidentOptionsSourceUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentOptionsSource source;

/*!
 * @abstract
 *      Incident severity level.
 * @discussion
 *      This value can be in the range of 0-4, with 4 indicating the highest
 *      severity.  Defaults to IXCLIncidentOptionSeverityUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentOptionsSeverityMask severityMask;

/*!
 * @abstract
 *      The incident parameters that are requested.
 * @discussion
 *      More than one option can be specified by using the | operator.
 *      Defaults to IXCLIncidentOutputFieldsUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentOutputFieldsMask outputFieldsMask;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns IXCLIncidentOptionTypeMask as a string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) typeMaskAsString;

/*!
 * @abstract
 *      Returns IXCLIncidentOptionTypeMask as a string to be passed into the
 *      server request for XD Incidents.
 *
 * @return
 *      NSString.
 */
- (NSString *) XDTypeMaskAsString;

/*!
 * @abstract
 *      Returns IXCLIncidentOptionSource as a string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) sourceAsString;

/*!
 * @abstract
 *      Returns IXCLIncidentOptionSeverityMask as string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) severityMaskAsString;

/*!
 * @abstract
 *      Returns IXCLIncidentOutputFieldsMask as string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) outputFieldsMaskAsString;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
