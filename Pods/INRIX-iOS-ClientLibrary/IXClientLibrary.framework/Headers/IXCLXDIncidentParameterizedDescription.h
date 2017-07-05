/*
 * @header IXCLXDIncidentParameterizedDescription.h
 * @abstract XD Incident extension to ParameterizedDescription.
 *  associated with an event code.
 * @author Steven Warkentin
 * @updated 04-15-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLIncidentParameterizedDescription.h"

/*!
 * @abstract XD Incident extension to ParameterizedDescription.
 *  associated with an event code.
 */
@interface IXCLXDIncidentParameterizedDescription : IXCLIncidentParameterizedDescription

/*!
 * @abstract TMC of one crossroad where the event occurs.
 */
@property (nonatomic, copy, readwrite) NSString * crossroad1TmcCode;

/*!
 * @abstract TMC of another crossroad where the event occurs.
 */
@property (nonatomic, copy, readwrite) NSString * crossroad2TmcCode;

@end
