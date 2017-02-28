/*
 * @header IXCLTrafficTileOptions.h
 * @abstract Represents request parameters for traffic tile calls.
 * @author Gaurav Agarwal
 * @updated 03-16-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */


#import "IXCLBaseOptions.h"
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract The minimum value for latitude.
 * @discussion Value is -85.05112878.
 */
FOUNDATION_EXPORT CLLocationDegrees const IXCLTrafficTileOptionsLatitudeMin;

/*!
 * @abstract The maximum value for latitude.
 * @discussion Value is 85.05112878.
 */
FOUNDATION_EXPORT CLLocationDegrees const IXCLTrafficTileOptionsLatitudeMax;

/*!
 * @abstract The minimum value for longitude.
 * @discussion Value is -180.
 */
FOUNDATION_EXPORT CLLocationDegrees const IXCLTrafficTileOptionsLongitudeMin;

/*!
 * @abstract The maximum value for longitude.
 * @discussion Value is 180.
 */
FOUNDATION_EXPORT CLLocationDegrees const IXCLTrafficTileOptionsLongitudeMax;

/*!
 * @abstract The minimum value for traffic tile opacity.
 * @discussion Value is 0.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTrafficTileOptionsOpacityMin;

/*!
 * @abstract The maximum value for traffic tile opacity.
 * @discussion Value is 100.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTrafficTileOptionsOpacityMax;

/*!
 * @abstract
 *      A value that, when assigned to the opacity property on
 *      IXCLTrafficTileOptions, will indicate that the default value for
 *      traffic tile opacity should be used.
 * @discussion
 *      The default value is stored in the defaultOptionsOpacity property on
 *      IXCLTrafficTilesController.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTrafficTileOptionsOpacityUseDefault;

/*!
 * @abstract
 *      A value that, when assigned tot he penWidth property on
 *      IXCLTrafficTileOptions, will indicate that the default value for
 *      traffic tile penWidth should be used.
 * @discussion
 *      The default value is stored in the defaultOptionsPenWidth property on
 *      IXCLTrafficTilesController.
 */
FOUNDATION_EXPORT NSUInteger const IXCLTrafficTileOptionsPenWidthUseDefault;


//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      The format of the traffic tile to be returned in the server response.
 *
 * @constant IXCLTrafficTileOptionsFormatPNG Return traffic tile as a PNG image.
 * @constant IXCLTrafficTileOptionsFormatGIF Return traffic tile as a GIF image.
 */
typedef NS_ENUM (NSUInteger, IXCLTrafficTileOptionsFormat)
{
    IXCLTrafficTileOptionsFormatUseDefault = -1,

    IXCLTrafficTileOptionsFormatPNG = 0,
    IXCLTrafficTileOptionsFormatGIF
};

/*!
 * @abstract
 *      The Federal Road Classification (FRC) code of the TMCs to report.
 *
 * @constant IXCLTrafficTileOptionsFRCLevelMask1
 *      First class roads, such as national highway network roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMask2
 *      Second class roads, such as state highway network roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMask3
 *      Third class roads, such as state interconnecting network roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMask4
 *      Fourth class roads, such as major connecting roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMask5
 *      Fifth class roads, such as minor roads connecting suburbs.
 * @constant IXCLTrafficTileOptionsFRCLevelMask6
 *      Sixth class roads, such as destination and destination collector roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMask7
 *      Seventh class roads, such as destination dead-end roads.
 * @constant IXCLTrafficTileOptionsFRCLevelMaskAll
 *      Report all road types.
 */
typedef NS_OPTIONS (NSUInteger, IXCLTrafficTileOptionsFRCLevelMask)
{
    IXCLTrafficTileOptionsFRCLevelUseDefault = 0,

    IXCLTrafficTileOptionsFRCLevelMask1   = (1 << 0),
    IXCLTrafficTileOptionsFRCLevelMask2   = (1 << 1),
    IXCLTrafficTileOptionsFRCLevelMask3   = (1 << 2),
    IXCLTrafficTileOptionsFRCLevelMask4   = (1 << 3),
    IXCLTrafficTileOptionsFRCLevelMask5   = (1 << 4),
    IXCLTrafficTileOptionsFRCLevelMask6   = (1 << 5),
    IXCLTrafficTileOptionsFRCLevelMask7   = (1 << 6),
    IXCLTrafficTileOptionsFRCLevelMaskAll = (IXCLTrafficTileOptionsFRCLevelMask1 |
                                             IXCLTrafficTileOptionsFRCLevelMask2 |
                                             IXCLTrafficTileOptionsFRCLevelMask3 |
                                             IXCLTrafficTileOptionsFRCLevelMask4 |
                                             IXCLTrafficTileOptionsFRCLevelMask5 |
                                             IXCLTrafficTileOptionsFRCLevelMask6 |
                                             IXCLTrafficTileOptionsFRCLevelMask7),
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTrafficTileOptions
 * @abstract Represents request parameters for traffic tile calls.
 */
@interface IXCLTrafficTileOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      A valid quadkey representing a geographical area.
 * @discussion
 *      This parameter uses a virtual earth quad key to generate a resulting
 *      width×height tile which represents the described area.
 */
@property (nonatomic, strong, readwrite) NSString * quadkey;

/*!
 * @abstract The opacity, as a value between 0 and 100.
 * @discussion Defaults to IXCLTrafficTileOptionsOpacityUseDefault.
 */
@property (nonatomic, assign, readwrite) NSUInteger opacity;

/*!
 * @abstract The pen width of the traffic overlay, in pixels.
 * @discussion Defaults to IXCLTrafficTileOptionsPenWidthUseDefault.
 */
@property (nonatomic, assign, readwrite) NSUInteger penWidth;

/*!
 * @abstract The format of the traffic tile to be returned.
 * @discussion Defaults to IXCLTrafficTileOptionsFormatGIF.
 */
@property (nonatomic, assign, readwrite) IXCLTrafficTileOptionsFormat format;

/*!
 * @abstract
 *      The Federal Road Classification code of the road segments to report.
 * @discussion
 *      More than one option can be specified.  Defaults to
 *      IXCLTrafficTileOptionsFRCLevelMaskUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLTrafficTileOptionsFRCLevelMask frcLevelMask;

/*!
 * @abstract
 *      Range of speeds or percentages that is used to categorize segment data.
 * @discussion
 *      All speed buckets are identified by a unique number called a
 *      speedbucketID.
 */
@property (nonatomic, strong, readwrite) NSString * speedBucketId;

/*!
 * @abstract
 *      The start time to predict traffic.
 * @discussion
 *      This parameter is an optional date/time field in UTC, used to show
 *      predicted traffic, i.e. “X” number of minutes into the future from now.
 *      Defaults to “now” if not specified.
 */
@property (nonatomic, strong, readwrite) NSDate * startTime;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize the IXCLTrafficTileOptions with specified quadkey.
 *
 * @param quadkey A valid quadkey representing a geographical area.
 *
 * @return Instance of the IXCLTrafficTileOptions class.
 */
- (instancetype) initWithQuadkey: (NSString *) quadkey;

/*!
 * @abstract
 *      Returns IXCLTrafficTileOptionsFormat as a string to be included
 *      in the server request.
 *
 * @return
 *      The traffic tile format as a string.
 */
- (NSString *) formatAsString;

/*!
 * @abstract
 *      Returns IXCLTrafficTileOptionsFRCLevelMask as a string to be included
 *      in the server request.
 *
 * @return
 *      The FRC level(s) as a string.
 */
- (NSString *) frcLevelMaskAsString;

@end
