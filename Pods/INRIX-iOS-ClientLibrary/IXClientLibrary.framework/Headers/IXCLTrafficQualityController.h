/*
 * @header IXCLTrafficQualityController.h
 * @abstract Controller for managing traffic quality requests.
 * @author Dmitri Fuerle
 * @updated 04-22-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>
#import "IXCLBaseControllerWithCache.h"

@class IXCLCoreResponse;
@class IXCLTrafficQuality;
@class IXCLTrafficQualityOptions;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLTrafficQualityControllerProtocol
 * @abstract
 *      Protocol definition for the Traffic Quality Controller
 */
@protocol IXCLTrafficQualityControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      Recommended time interval for refreshing traffic quality.
 * @discussion
 *      This value is a recommended time interval to be used by an application
 *      for refreshing traffic quality.
 */
@property (nonatomic, assign, readonly) NSTimeInterval recommendedRefreshTimeInterval;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Returns the traffic quality around a coordinate.
 *
 * @param options    Options for getting traffic quality data.
 * @param completion Block that returns traffic quality, and any errors.
 */
- (void) requestTrafficQualityWithOptions: (IXCLTrafficQualityOptions *) options
                               completion: (void (^)(IXCLTrafficQuality * trafficQuality, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLTrafficQualityController
 * @abstract Controller for managing traffic quality requests.
 */
@interface IXCLTrafficQualityController : IXCLBaseControllerWithCache<IXCLTrafficQualityControllerProtocol>
@end
