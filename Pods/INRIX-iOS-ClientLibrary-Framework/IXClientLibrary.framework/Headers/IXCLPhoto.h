/*
 * @header IXCLPhoto.h
 * @abstract Definitions describing photo.
 * @author Cheng Cheng
 * @updated 02-23-2015
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
 * @class IXCLPhoto
 * @abstract Model object describing an INRIX photo.
 */
@interface IXCLPhoto : NSObject <NSCopying>

/*!
 * @abstract The mime type of photo.
 */
@property (nonatomic, copy, readwrite) NSString * mimeType;

/*!
 * @abstract The image url string of photo.
 */
@property (nonatomic, copy, readwrite) NSString * imageURLString;

/// @cond
+ (NSArray *) photosFromDictionaries: (NSArray *) dictionaries;

@end
