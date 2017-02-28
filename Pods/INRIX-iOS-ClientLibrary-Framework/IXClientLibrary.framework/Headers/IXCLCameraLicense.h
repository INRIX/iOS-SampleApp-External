/*
 * @header IXCLCameraLicense.h
 * @abstract Model object representing license data for traffic camera images.
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
 * @class IXCLCameraLicense
 * @abstract Model object representing license data for traffic camera images.
 */
@interface IXCLCameraLicense : NSObject <NSCopying>

/*!
 * @abstract Determines whether the camera can be used while driving.
 */
@property (nonatomic, assign, readwrite) BOOL isUseWhileDrivingEnabled;

/*!
 * @abstract Copyright information for the traffic camera images.
 */
@property (nonatomic, copy, readwrite) NSString * copyrightNotice;

/*!
 * @abstract Region id for the traffic camera.
 */
@property (nonatomic, copy, readwrite) NSString * regionId;

/*!
 * @abstract
 *      Determines whether it is prohibited to get fee when show the camera
 *      image to end users.
 */
@property (nonatomic, assign, readwrite) BOOL isFeeToEndUserProhibited;

/*!
 * @abstract
 *      Determines whether it is prohibited to sublicense the camera image.
 */
@property (nonatomic, assign, readwrite) BOOL isSublicenseProhibited;

@end
