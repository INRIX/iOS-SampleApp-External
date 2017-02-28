/*
 * @header IXCLCameraImageOptions.h
 * @abstract Options class for requesting a camera image.
 * @author David Potter
 * @updated 04-25-2014
 * @copyright Copyright (c) 2014-2015 INRIX. All rights reserved.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @abstract Options class for requesting a camera image.
 */
@interface IXCLCameraImageOptions : IXCLBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract ID of the camera image to retrieve.
 */
@property (nonatomic, copy, readwrite) NSString * cameraId;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a camera ID.
 *
 * @param cameraId ID of the camera image to retrieve.
 *
 * @return Instance of the IXCLCameraImageOptions class.
 */
- (instancetype) initWithCameraId: (NSString *) cameraId;

@end
