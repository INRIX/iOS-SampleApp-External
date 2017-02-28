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

@end
