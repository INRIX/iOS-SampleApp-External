/*
 * @header IXCLTravelTime.h
 * @abstract
 *      Model object representing information about travel time for a route.
 * @author Akvelon
 * @updated 11-16-2009
 * @copyright Copyright (c) 2009-2015 INRIX, Inc.
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
 * @class IXCLTravelTime
 * @abstract
 *      Model object representing information about travel time for a route.
 */
@interface IXCLTravelTime : NSObject <NSCoding, NSCopying>

/*!
 * @abstract
 *      The time of departure along the route. Defaults to the current time.
 */
@property (nonatomic, strong, readwrite) NSDate * departureTime;

/*!
 * @abstract
 *      The time of arrival along the route if available or nil.
 */
@property (nonatomic, strong, readwrite) NSDate * arrivalTime;

/*!
 * @abstract How long it takes to travel the route in minutes.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval travelTimeMinutes;

/*!
 * @abstract The deviation in minutes from the uncongested time.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval abnormalityMinutes;

/*!
 * @abstract The current average speed along the route in miles per hour.
 */
@property (nonatomic, assign, readwrite) CGFloat averageSpeed;

/*!
 * @abstract A Boolean value indicating if the route has closures.
 */
@property (nonatomic, assign, readwrite) BOOL routeHasClosures;

/*!
 * @abstract A Boolean value indicating if the route has travel restrictions.
 */
@property (nonatomic, assign, readwrite) BOOL routeRestricted;

@end
