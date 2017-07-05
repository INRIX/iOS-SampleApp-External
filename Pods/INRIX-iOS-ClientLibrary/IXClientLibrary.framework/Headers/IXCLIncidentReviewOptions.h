/*
 * @header IXCLIncidentReviewOptions.h
 * @abstract Represents request parameters for reviewing an incident.
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

#import "IXCLBaseOptions.h"
#import "IXCLIncident.h"


@class IXCLIncident;


//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract
 *      Value specifying how an incident is being reviewed.
 *
 * @constant
 *      IXCLIncidentReviewOptionsStateAllClear  Incident is no longer there.
 * @constant
 *      IXCLIncidentReviewOptionsStateConfirmed Incident is still there.
 */
typedef NS_ENUM (NSUInteger, IXCLIncidentReviewOptionsState)
{
    IXCLIncidentReviewOptionsStateAllClear  = 0,
    IXCLIncidentReviewOptionsStateConfirmed = 1,
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLIncidentReviewOptions
 * @abstract Represents request parameters for reviewing an incident.
 */
@interface IXCLIncidentReviewOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract ID of incident to review.
 */
@property (nonatomic, copy, readwrite) IXCLIncident * incident;

/*!
 * @abstract How the incident is being reviewed.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentReviewOptionsState reviewState;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize with an IXCLIncident.
 *
 * @param incident    Incident to review.
 * @param reviewState How the incident is being reviewed.
 *
 * @return Instance of the IXCLIncidentReviewOptions class.
 */
- (instancetype) initWithIncident: (IXCLIncident *) incident reviewState: (IXCLIncidentReviewOptionsState) reviewState;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
