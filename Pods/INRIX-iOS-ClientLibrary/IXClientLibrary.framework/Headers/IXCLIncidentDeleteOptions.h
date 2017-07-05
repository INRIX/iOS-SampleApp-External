/*
 * @header IXCLIncidentDeleteOptions.h
 * @abstract Represents request parameters for deleting an incident.
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


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentDeleteOptions
 * @abstract Represents request parameters for deleting an incident.
 */
@interface IXCLIncidentDeleteOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract ID of incident to delete.
 */
@property (nonatomic, copy, readwrite) IXCLIncident * incident;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize with an IXCLIncident.
 *
 * @param incident Incident to delete.
 *
 * @return Instance of the IXCLIncidentDeleteOptions class.
 */
- (instancetype) initWithIncident: (IXCLIncident *) incident;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
