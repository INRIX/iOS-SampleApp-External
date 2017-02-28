/*
 * @header IXCLIncidentDelayImpact.h
 * @abstract
 *      Model object describing the increase in travel time caused by an
 *      incident relative to the travel time under average and free-flowing
 *      conditions.
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
 * @class IXCLIncidentDelayImpact
 * @abstract
 *      Model object describing the increase in travel time caused by an
 *      incident relative to the travel time under average and free-flowing
 *      conditions.
 */
@interface IXCLIncidentDelayImpact : NSObject <NSCoding, NSCopying>

/*!
 * @abstract
 *      The increase in travel time across the road extent affected by the
 *      incident relative to the travel time under average conditions for the
 *      given day of week and time of day.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval delayFromTypicalInMinutes;

/*!
 * @abstract
 *      The increase in travel time across the road extent affected by the
 *      incident relative to the travel time under free-flowing conditions.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval delayFromFreeFlowInMinutes;

/*!
 * @abstract The length in miles of the road extent affected by the incident.
 */
@property (nonatomic, assign, readwrite) double distance;

@end
