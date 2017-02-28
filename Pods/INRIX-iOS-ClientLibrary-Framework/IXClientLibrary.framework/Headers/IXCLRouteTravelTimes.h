/*
 * @header IXCLRouteTravelTimes.h
 * @abstract
 *      Model object representing information about travel times for a route.
 * @author Gaurav Agarwal
 * @updated 10-28-2014
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
#pragma mark - Class Declaration
/*!
 * @class IXCLRouteTravelTimes
 * @abstract
 *      Model object representing information about travel times for a route.
 */
@interface IXCLRouteTravelTimes : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier of the route.
 */
@property (nonatomic, copy, readwrite) NSString * routeId;

/*!
 * @abstract The travel time, given no traffic congestion.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval uncongestedTravelTimeMinutes;

/*!
 * @abstract Array of travel times represented by IXCLTravelTime.
 */
@property (nonatomic, strong, readwrite) NSArray * travelTimes;

@end
