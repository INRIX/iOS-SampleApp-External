/*
 * @header IXCLCamerasInBoxOptions.h
 * @abstract
 *      Represents request parameters for retrieving cameras in a rectangular
 *      region.
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

#import "IXCLRequestInBoxOptions.h"


//-----------------------------------------------------------------------------
#pragma mark Class Implementation

/*!
 * @class IXCLCamerasInBoxOptions
 * @abstract
 *      Represents request parameters for retrieving cameras in a rectangular
 *      region.
 */
@interface IXCLCamerasInBoxOptions : IXCLRequestInBoxOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Determines whether the cameras that out of service should be excluded
 *      from the response. Default is NO.
 */
@property (nonatomic, assign, readwrite) BOOL shouldExcludeOutOfServiceCameras;

@end
