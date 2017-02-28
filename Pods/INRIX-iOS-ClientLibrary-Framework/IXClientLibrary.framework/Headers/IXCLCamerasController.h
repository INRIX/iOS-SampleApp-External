/*
 * @header IXCLCamerasController.h
 * @abstract Controller for managing camera requests.
 * @author Dmitri Fuerle
 * @updated 03-12-2015
 * @copyright Copyright (c) 2013-2015 INRIX. All rights reserved.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

#import "IXCLBaseControllerWithCache.h"

@class IXCLCameraImageOptions;
@class IXCLCamerasInBoxOptions;
@class IXCLCamerasInRadiusOptions;
@class IXCLCamerasOnRouteOptions;
@class IXCLCoreResponse;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLCamerasControllerProtocol
 * @abstract
 *      Protocol definition for the Cameras Controller
 */
@protocol IXCLCamerasControllerProtocol <NSObject>

/*!
 * @abstract
 *      Returns the array of IXCLServerCamera objects in the completion block.
 *
 * @param options
 *      Options describing the cameras to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLServerCamera objects, and any errors.
 */
- (void) requestCamerasInRadiusWithOptions: (IXCLCamerasInRadiusOptions *) options
                                completion: (void (^)(NSArray * cameras, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the array of IXCLServerCamera objects in the completion block.
 *
 * @param options
 *      Options describing the cameras to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLServerCamera objects, and any errors.
 */
- (void) requestCamerasInBoxWithOptions: (IXCLCamerasInBoxOptions *) options
                             completion: (void (^)(NSArray * cameras, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns a camera image by camera ID in the completion block.
 *
 * @param options
 *      Options describing the camera image to retrieve from the server.
 * @param completion
 *      Block that returns an UIImage camera image, and any errors.
 */
- (void) requestCameraImageWithOptions: (IXCLCameraImageOptions *) options
                            completion: (void (^)(UIImage * cameraImage, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the array of IXCLServerCamera objects in the completion block.
 *
 * @param options
 *      Options describing the cameras to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLServerCamera objects, and any errors.
 */
- (void) requestCamerasOnRouteWithOptions: (IXCLCamerasOnRouteOptions *) options
                               completion: (void (^)(NSArray * cameras, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLCamerasController
 * @abstract Controller for managing camera requests.
 */
@interface IXCLCamerasController : IXCLBaseControllerWithCache<IXCLCamerasControllerProtocol>
@end
