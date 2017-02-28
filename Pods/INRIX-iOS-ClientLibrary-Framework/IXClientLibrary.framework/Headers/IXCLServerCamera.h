/*
 * @header IXCLServerCamera.h
 * @abstract Model object representing a camera.
 * @author Alex Rudyk
 * @updated 08-24-2012
 * @copyright Copyright (c) 2012-2015 INRIX. All rights reserved.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLMapPoint.h"

@class IXCLCameraLicense;
@class IXCLCameraStatus;

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLServerCamera
 * @abstract Model object representing a traffic camera.
 */
@interface IXCLServerCamera : IXCLMapPoint <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      The camera's unique identifier.
 */
@property (nonatomic, copy, readwrite) NSString * cameraId;

/*!
 * @abstract
 *      The camera's name.
 */
@property (nonatomic, copy, readwrite) NSString * name;

/*!
 * @abstract
 *      A description of the camera's view.
 */
@property (nonatomic, copy, readwrite) NSString * view;

/*!
 * @abstract
 *      The camera's current status.
 */
@property (nonatomic, strong, readwrite) IXCLCameraStatus * status;

/*!
 * @abstract
 *      The license terms of the camera.
 */
@property (nonatomic, strong, readwrite) IXCLCameraLicense * license;

/*!
 * @abstract
 *      Obtain the hash value of self.
 *
 * @discussion
 *      This method returns the hash of the cameraId.
 *
 * @return
 *      The hash value of this object.
 */
- (NSUInteger) hash;

/*!
 * @abstract
 *      Check for equality with another object.
 *
 * @discussion
 *      The objects is considered equal if they are of the same type with
 *      matching cameraIds.
 *
 * @param object
 *      The object to test for equality.
 *
 * @return YES if the objects are equal, NO otherwise.
 */
- (BOOL) isEqual: (id) object;


@end
