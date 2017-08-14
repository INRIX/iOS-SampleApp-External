/*
 * @header IXCLSpeedLimitOptions.h
 * @abstract Options for requesting speed limit.
 * @author Aleksei Zhilin
 * @created 05-08-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLBaseOptions.h"
#import "IXCLSegment.h"

/*!
 * @abstract
 *      The speed limit fields to output.
 *
 * @constant IXCLSpeedLimitOutputFieldsMaskPostedSpeed
 *      The posted speed.
 * @constant IXCLSpeedLimitOutputFieldsMaskFRC
 *      The FRC level.
 * @constant IXCLSpeedLimitOutputFieldsMaskRoadName
 *      The road name.
 * @constant IXCLSpeedLimitOutputFieldsMaskAll
 *      All fields.
 */
typedef NS_OPTIONS (NSUInteger, IXCLSpeedLimitOutputFieldsMask)
{
    IXCLSpeedLimitOutputFieldsUseDefault       = 0,

    IXCLSpeedLimitOutputFieldsMaskPostedSpeed  = (1 << 0),
    IXCLSpeedLimitOutputFieldsMaskFRC          = (1 << 1),
    IXCLSpeedLimitOutputFieldsMaskRoadName     = (1 << 2),
    IXCLSpeedLimitOutputFieldsMaskAll          = (IXCLSpeedLimitOutputFieldsMaskPostedSpeed |
                                                  IXCLSpeedLimitOutputFieldsMaskFRC |
                                                  IXCLSpeedLimitOutputFieldsMaskRoadName),
};

/*!
 * @class IXCLSpeedLimitOptions
 * @abstract Options object to get the posted speed limit at a point.
 */
@interface IXCLSpeedLimitOptions : IXCLBaseOptions

/*!
 * @abstract
 *      The coordinate of a point where to get speed limit.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D point;

/*!
 * @abstract
 *      The heading at a point where to get speed limit.
 */
@property (nonatomic, assign, readwrite) NSUInteger heading;

/*!
 * @abstract
 *      Describes speed limit value in this class as well as in the response
 *      from the request.
 * @discussion
 *      Defaults to IXCLSpeedLimitUnitsMiles.
 */
@property (nonatomic, assign, readwrite) IXCLSegmentSpeedLimitUnitsType units;

/*!
 * @abstract
 *      The speed limit parameters that are requested.
 * @discussion
 *      More than one option can be specified by using the | operator.
 *      Defaults to IXCLSpeedLimitOutputFieldsUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLSpeedLimitOutputFieldsMask outputFieldsMask;

/*!
 * @abstract
 *      Returns IXCLSpeedLimitOutputFieldsMask as string to be passed into the
 *      server request.
 *
 * @return
 *      NSString.
 */
- (NSString *) outputFieldsMaskAsString;

@end
