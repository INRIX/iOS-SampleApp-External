/*
 * @header IXCLCameraStatus.h
 * @abstract Model object representing the status of a traffic camera.
 * @author Aleksei Zhilin
 * @updated 03-12-2015
 * @copyright Copyright (c) 2015 INRIX. All rights reserved.
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
 * @class IXCLCameraStatus
 * @abstract Model object representing the status of a traffic camera.
 */
@interface IXCLCameraStatus : NSObject <NSCopying>

/*!
 * @abstract Determines whether the traffic camera is out of service.
 */
@property (nonatomic, assign, readwrite) BOOL outOfService;

/*!
 * @abstract Camera update frequency.
 */
@property (nonatomic, assign, readwrite) NSTimeInterval updateFrequency;

@end
