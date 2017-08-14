/*
 * @header IXCLDangerousSlowdown.h
 * @abstract Model objects for dangerous slowdowns.
 * @author Patrick Winchell
 * @created 11-10-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "IXCLSegment.h"
#import "IXCLMapPoint.h"

@class IXCLDangerousSlowdownDescription;

/*!
 * @abstract
 *      Specifies the severity of the slowdown
 *
 * @constant
 *      IXCLDangerousSlowdownSeverityUnknown Unknown severity.
 * @constant
 *      IXCLDangerousSlowdownSeverity1 A slowdown with 15mph (35km/h) - 25mph (40km/h) delta.
 * @constant
 *      IXCLDangerousSlowdownSeverity2 A slowdown with > 25mph (40km/h) - 35mph (56km/h) delta.
 * @constant
 *      IXCLDangerousSlowdownSeverity3 A slowdown with > 35mph (56km/h) - 45mph (72km/h) delta.
 * @constant
 *      IXCLDangerousSlowdownSeverity4 A slowdown with > 45mph (72km/h) - 60mph (96km/h) delta.
 * @constant
 *      IXCLDangerousSlowdownSeverity5 A slowdown with delta over 60mph (96km/h).
 */
typedef NS_ENUM (NSUInteger, IXCLDangerousSlowdownSeverity)
{
    IXCLDangerousSlowdownSeverityUnknown  = 0,
    IXCLDangerousSlowdownSeverity1  = 1,
    IXCLDangerousSlowdownSeverity2  = 2,
    IXCLDangerousSlowdownSeverity3  = 3,
    IXCLDangerousSlowdownSeverity4  = 4,
    IXCLDangerousSlowdownSeverity5  = 5,
};

/*!
 * @abstract
 *      Specifies the directionality of the slowdown
 *
 * @constant
 *      IXCLDangerousSlowdownDirectionUnknown Unknown direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionNorthbound Northbound direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionSouthbound Southbound direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionEastbound Eastbound direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionWestbound Westbound direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionClockwise Clockwise direction.
 * @constant
 *      IXCLDangerousSlowdownDirectionCounterClockwise Counter-clockwise direction.
 */
typedef NS_ENUM (NSUInteger, IXCLDangerousSlowdownDirection)
{
    IXCLDangerousSlowdownDirectionUnknown = 0,
    IXCLDangerousSlowdownDirectionNorthbound = 1,
    IXCLDangerousSlowdownDirectionSouthbound = 2,
    IXCLDangerousSlowdownDirectionEastbound = 3,
    IXCLDangerousSlowdownDirectionWestbound = 4,
    IXCLDangerousSlowdownDirectionClockwise = 5,
    IXCLDangerousSlowdownDirectionCounterClockwise = 6,
};

/*!
 * @class IXCLDangerousSlowdown
 * @abstract Model object describing an INRIX dangerous slowdown.
 */
@interface IXCLDangerousSlowdown : IXCLMapPoint

/*!
 * @abstract Segment information for the slowdown.
 */
@property (nonatomic, strong, readonly) IXCLSegment * segment;

/*!
 * @abstract Array of NSNumber geoids for the slowdown.
 */
@property (nonatomic, strong, readonly) NSArray* geoIds;

/*!
 * @abstract Time the slowdown started.
 */
@property (nonatomic, strong, readonly) NSDate * occurrenceStartTime;

/*!
 * @abstract Description object for the slowdown.
 */
@property (nonatomic, strong, readonly) IXCLDangerousSlowdownDescription * slowdownDescription;

/*!
 * @abstract Unique identifier for the slowdown.
 */
@property (nonatomic, strong, readonly) NSString * slowdownId;

/*!
 * @abstract Versioning information for the slowdown.
 */
@property (nonatomic, assign, readonly) NSInteger version;

/*!
 * @abstract Severity of the slowdown.
 */
@property (nonatomic, assign, readonly) IXCLDangerousSlowdownSeverity severity;

/*!
 * @abstract Speed of the slowdown.
 */
@property (nonatomic, assign, readonly) double speedAt;

/*!
 * @abstract Speed just before the slowdown.
 */
@property (nonatomic, assign, readonly) double speedBefore;

/*!
 * @abstract Delta between speedBefore and speedAt.
 */
@property (nonatomic, assign, readonly) double speedDelta;

@end

/*!
 * @class IXCLDangerousSlowdownDescription
 * @abstract Model object describing the description information for an slowdown.
 */
@interface IXCLDangerousSlowdownDescription : NSObject<NSCopying, NSCoding>

/*!
 * @abstract Directionality of the slowdown.
 */
@property (nonatomic, assign, readonly) IXCLDangerousSlowdownDirection direction;

/*!
 * @abstract Mile marker.
 */
@property (nonatomic, strong, readonly) NSString * mileMarker;

/*!
 * @abstract Array of roadnames at the slowdown. May be empty.
 */
@property (nonatomic, strong, readonly) NSArray * roadNames;

@end
