/*
 * @header IXCLXDIncident.h
 * @abstract Model class for XD incidents.
 * @author Steven Warkentin
 * @updated 04-08-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLIncident.h"
#import "IXCLXDIncidentReoccurringSchedule.h"

@class IXCLIncidentDescription;

/*!
 * @abstract Model class for XD incidents.
 */
@interface IXCLXDIncident : IXCLIncident <NSCoding, NSCopying>

/*!
 * @abstract An array of IXCLXDIncidentMessage objects representing
 *      Inrix incident codes associated with the incident.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * messages;

/*!
 * @abstract
 *      The reoccurrence schedule for the incident.
 * @discussion
 *      Contains various properties to describe when the incident
 *      reoccurs, for example road work that takes place each
 *      night from 9pm to 5am.
 */
@property (nonatomic, strong, readwrite) IXCLXDIncidentReoccurringSchedule * reoccuringSchedule;

/*!
 * @abstract
 *      The country code for the country the incident is in.
 */
@property (nonatomic, assign, readwrite) NSInteger countryCode;

/*!
 * @abstract
 *      The direction of traffic on the road the incident is on.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentDirection incidentDirection;

/*!
 * @abstract
 *      True if the incident occurs on both sides of the road.
 */
@property (nonatomic, assign, readwrite) BOOL isBiDirectional;

/*!
 * @abstract Text description of the incident intended to be spoken by a text to speech engine.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentDescription * ttsDescription;

@end
