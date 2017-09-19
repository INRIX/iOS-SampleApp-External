/*
 * @header IXCLNetworkReachabilityController.h
 * @abstract Controller for monitoring the network reachability.
 * @author Gaurav Agarwal
 * @updated 05-21-2014
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
#pragma mark - Global Exports

/*!
 * @abstract
 *      An NSNotification name posted by NSNotificationCenter when the network
 *      reachability changes.
 * @discussion
 *      NSNotification 'object' will return NSNumber with BOOL set to YES if
 *      network is currently reachable, otherwise set to NO.
 */
FOUNDATION_EXPORT NSString * const IXCLNetworkReachabilityControllerReachabilityDidChangeNotification;


//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLNetworkReachabilityControllerProtocol
 * @abstract
 *      Protocol definition for the Network Reachability Controller
 */
@protocol IXCLNetworkReachabilityControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract A Boolean value indicating if the network is currently reachable.
 */
@property (nonatomic, assign, readonly) BOOL isNetworkReachable;

/*!
 * @abstract
 *      Indicates whether or not the network is reachable via Wi-Fi.
 */
@property (nonatomic, assign, readonly) BOOL isNetworkReachableViaWiFi;

/*!
 * @abstract
 *      Indicates whether or not the network is reachable via
 *      cellular connection.
 */
@property (nonatomic, assign, readonly) BOOL isNetworkReachableViaWWAN;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLNetworkReachabilityController
 * @abstract Controller for monitoring the network reachability.
 */
@interface IXCLNetworkReachabilityController : NSObject<IXCLNetworkReachabilityControllerProtocol>
@end
