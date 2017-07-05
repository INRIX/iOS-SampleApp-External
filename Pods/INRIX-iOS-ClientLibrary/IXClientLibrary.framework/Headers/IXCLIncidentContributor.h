/*
 * @header IXCLIncidentContributor.h
 * @abstract
 *      Model object representing a User-Generated Incident (UGI) contributor.
 * @author Gaurav Agarwal
 * @updated 03-10-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentContributor
 * @abstract 
 *      Model object representing a User-Generated Incident (UGI) contributor.
 */
@interface IXCLIncidentContributor : NSObject <NSCoding, NSCopying>

/*!
 * @abstract Contributor display name.
 */
@property (nonatomic, copy, readwrite) NSString * displayName;

/*!
 * @abstract Contributor trust level.
 */
@property (nonatomic, copy, readwrite) NSString * trustLevel;

/*!
 * @abstract
 *      A Boolean value indicating if the user is the reporter of incident.
 */
@property (nonatomic, assign, readwrite) BOOL isReporter;

/*!
 * @abstract Total number of incident submissions.
 */
@property (nonatomic, assign, readwrite) NSUInteger submissionCount;

/*!
 * @abstract Contributor rank.
 * @discussion
 *      The ranking describes how a user compares with other users who report
 *      incidents.
 */
@property (nonatomic, assign, readwrite) NSUInteger ranking;

/*!
 * @abstract
 *      Contributor's score.
 * @discussion
 *      The score is related to how many times the user has reported an
 *      incident.
 */
@property (nonatomic, assign, readwrite) NSUInteger score;

@end
