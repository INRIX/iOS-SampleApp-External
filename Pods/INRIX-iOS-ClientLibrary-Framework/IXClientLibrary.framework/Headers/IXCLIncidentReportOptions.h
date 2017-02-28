/*
 * @header IXCLIncidentReportOptions.h
 * @abstract Represents request parameters for reporting an incident.
 * @author David Potter
 * @updated 04-11-2014
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
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentReportOptions
 * @abstract Represents request parameters for reporting an incident.
 */
@interface IXCLIncidentReportOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Location of the incident being reported.
 */
@property (nonatomic, strong, readwrite) CLLocation * location;

/*!
 * @abstract Type of incident being reported.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentType incidentType;

/*!
 * @abstract ALERT-C code providing more details about the incident.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentEventCode eventCode;

/*!
 * @abstract Side of the road of the incident being reported.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentSideOfRoad sideOfRoad;

/*!
 * @abstract Description of the incident.
 */
@property (nonatomic, copy, readwrite) NSString * incidentDescription;

/*!
 * @abstract ID of the incident to report.
 */
@property (nonatomic, copy, readwrite) NSString * incidentId;

/*!
 * @abstract Version of the incident to report.
 */
@property (nonatomic, copy, readwrite) NSString * incidentVersion;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
