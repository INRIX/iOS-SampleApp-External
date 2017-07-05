/*
 * @header IXCLSpeedBucket.h
 * @abstract Model object representing speed bucket associated with route.
 * @author Gaurav Agarwal
 * @updated 10-29-2014
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
 * @class IXCLSpeedBucket
 * @abstract Model object representing speed bucket associated with route.
 */
@interface IXCLSpeedBucket : NSObject <NSCoding, NSCopying>

/*!
 * @abstract Speed bucket unique id.
 */
@property (nonatomic, assign, readwrite) NSUInteger speedBucketID;

/*!
 * @abstract Speed bucket start offset.
 */
@property (nonatomic, assign, readwrite) double startOffset;

/*!
 * @abstract Speed bucket end offset.
 */
@property (nonatomic, assign, readwrite) double endOffset;

/*!
 * @abstract Speed bucket points encoded as polyline.
 */
@property (nonatomic, strong, readwrite) NSString * compressionPoints;

/*!
 * @abstract Decoded speed bucket points.
 */
@property (nonatomic, strong, readwrite) NSArray * decodedPoints;

/*!
 * @abstract The points in the speed bucket.
 */
@property (nonatomic, strong, readonly) NSArray * points;

@end
