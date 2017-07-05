/*
 * @header IXCLIncidentCommunity.h
 * @abstract Model object describing contributor and level of accuracy.
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


@class IXCLIncidentContributor;


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentCommunity
 * @abstract Model object describing incident contributor and level of accuracy.
 */
@interface IXCLIncidentCommunity : NSObject <NSCoding, NSCopying>

/*!
 * @abstract accuracy
 *      Community accuracy, i.e. how trustworthy the reporter/contributor of
 *      an incident is in the community.
 */
@property (nonatomic, copy, readwrite) NSString * accuracy;

/*!
 * @abstract Information about an incident reporter.
 */
@property (nonatomic, strong, readwrite) IXCLIncidentContributor * contributor;

@end
