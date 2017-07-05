/*
 * @header IXCLXDIncidentDetailsOptions.h
 * @abstract
 *      Describes the details to retrieve for an IXCLXDIncident details request.
 * @author Nathan Clark
 * @updated 02-02-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */


#import <Foundation/Foundation.h>

#import "IXCLIncidentBaseOptions.h"

@interface IXCLXDIncidentDetailsOptions : IXCLIncidentBaseOptions

/*!
 * Contains a list of incident Ids to fetch details for.
 */
@property (nonatomic, readwrite, strong) NSArray<NSString *> * incidentIds;

/*!
 * Creates an `IXCLXDIncidentDetailsOptions` with a list of `IXCLIncident` ids to query.
 *
 * @param incidentIds List of `IXCLIncident` IDs to query.
 * @return The newly created `IXCLXDIncidentDetailsOptions`.
 */
- (instancetype) initWithIncidentIds: (NSArray<NSString *> *) incidentIds;

@end
