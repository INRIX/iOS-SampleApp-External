/*
 * @header IXCLIncidentParameterizedDescription.h
 * @abstract
 *      Model object providing information on a type of traffic event
 *      associated with an event code.
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
#import "IXCLIncident.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentParameterizedDescription
 * @abstract
 *      Model object providing information on a type of traffic event
 *      associated with an event code.
 */
@interface IXCLIncidentParameterizedDescription : NSObject <NSCoding, NSCopying>

/*!
 * @abstract Identifies the type of event.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentEventCode eventCode;

/*!
 * @abstract Name and TMC of one crossroad where the event occurs.
 */
@property (nonatomic, copy, readwrite) NSString * crossroad1;

/*!
 * @abstract Name and TMC of another crossroad where the event occurs.
 */
@property (nonatomic, copy, readwrite) NSString * crossroad2;

/*!
 * @abstract Direction of travel on road for which event occurs.
 */
@property (nonatomic, assign, readwrite) IXCLIncidentDirection direction;

/*!
 * @abstract Textual description of the type of event.
 */
@property (nonatomic, copy, readwrite) NSString * eventText;

/*!
 * @abstract The city that the road is going from.
 */
@property (nonatomic, copy, readwrite) NSString * fromLocation;

/*!
 * @abstract Positional relationship between roadName and crossroad1.
 */
@property (nonatomic, copy, readwrite) NSString * position1;

/*!
 * @abstract Positional relationship between roadName and crossroad2.
 */
@property (nonatomic, copy, readwrite) NSString * position2;

/*!
 * @abstract Name of the road or venue where the event occurs.
 */
@property (nonatomic, copy, readwrite) NSString * roadName;

/*!
 * @abstract The city that the road is going towards.
 */
@property (nonatomic, copy, readwrite) NSString * toLocation;

@end
