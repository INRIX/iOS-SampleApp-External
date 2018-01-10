/*
 * @header IXCLParkingLotPhoto.h
 * @author Patrick Winchell
 * @updated 12-08-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

/*!
 * @class IXCLParkingLotPhoto
 *
 * @abstract
 *      Model object which respresents a photo object for the parking lot.
 */
@interface IXCLParkingLotPhoto : NSObject <NSCopying>

/*!
 * @abstract Array of strings representing the type of photo.
 */
@property (nonatomic, strong, readwrite) NSArray * assetTypes;

/*!
 * @abstract Url for the medium quality version of the photo.
 */
@property (nonatomic, strong, readwrite) NSURL * medium;

/*!
 * @abstract Url for the full quality version of the photo.
 */
@property (nonatomic, strong, readwrite) NSURL * full;

/*!
 * @abstract Url for the thumbnail of the photo.
 */
@property (nonatomic, strong, readwrite) NSURL * thumbnail;

@end
