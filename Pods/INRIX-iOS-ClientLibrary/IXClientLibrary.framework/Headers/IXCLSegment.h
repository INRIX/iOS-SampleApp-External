/*
 * @header IXCLSegment.h
 * @abstract Definitions describing TMC Segments.
 * @author Kent Lottis
 * @updated 08-28-2015
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

/*!
 * @abstract
 *      The units of a speed limit.
 *
 * @constant
 *      IXCLSpeedLimitUnitsMiles Speed limit in miles per hour.
 * @constant
 *      IXCLSpeedLimitUnitsKilometers Speed limit in kilometers per hour.
 */
typedef NS_ENUM (NSUInteger, IXCLSegmentSpeedLimitUnitsType)
{
    IXCLSegmentSpeedLimitUnitsMiles  = 0,
    IXCLSegmentSpeedLimitUnitsKilometers = 1
};

/*!
 * @abstract
 *      Describes a TMC Segment for incidents.
 */
@interface IXCLSegment : NSObject <NSCoding, NSCopying>

/*!
 * @abstract
 *      Describes the type of segment ("TMC", "XDS", etc.)
 */
@property (nonatomic, strong, readwrite) NSString * type;

/*!
 * @abstract
 *      The TMC code for the segment.
 */
@property (nonatomic, strong, readwrite) NSString * code;

/*!
 * @abstract
 *      The TMC offset for the segment.
 */
@property (nonatomic, strong, readwrite) NSString * offset;

/*!
 * @abstract
 *      The snap precision for the segment.
 */
@property (nonatomic, assign, readwrite) NSInteger snapPrecision;

/*!
 * @abstract
 *      The road name for the segment.
 */
@property (nonatomic, strong, readwrite) NSString * roadName;

/*!
 * @abstract
 *      The FRC level for the segment.
 */
@property (nonatomic, assign, readwrite) NSInteger frcLevel;

/*!
 * @abstract
 *      The posted speed limit for the segment.
 */
@property (nonatomic, assign, readwrite) NSInteger postedSpeedLimit;

/*!
 * @abstract
 *      The posted speed limit units type for the segment.
 */
@property (nonatomic, assign, readwrite) IXCLSegmentSpeedLimitUnitsType postedSpeedLimitUnitsType;

@end
