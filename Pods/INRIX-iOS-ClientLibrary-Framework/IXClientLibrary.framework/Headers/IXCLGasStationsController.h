/*
 * @header IXCLGasStationsController.h
 * @abstract Controller for managing gas stations.
 * @author Patrick Winchell
 * @updated 02-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"

@class IXCLGasStationsInBoxOptions;
@class IXCLGasStationsInRadiusOptions;
@class IXCLGasStationsOnRouteOptions;
@class IXCLSingleGasStationOptions;
@class IXCLGasStation;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLGasStationsControllerProtocol
 * @abstract
 *      Protocol definition for the Gas Stations Controller
 */
@protocol IXCLGasStationsControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Returns the array of IXCLGasStation objects in the completion block.
 *
 * @param options
 *      Options describing the stations to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLGasStation objects, and any errors.
 */
- (void) requestGasStationsInRadiusWithOptions: (IXCLGasStationsInRadiusOptions *) options
                                    completion: (void (^)(NSArray * GasStations, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the array of IXCLGasStation objects in the completion block.
 *
 * @param options
 *      Options describing the stations to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLGasStation objects, and any errors.
 */
- (void) requestGasStationsInBoxWithOptions: (IXCLGasStationsInBoxOptions *) options
                                 completion: (void (^)(NSArray * GasStations, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the array of IXCLGasStation objects in the completion block.
 *
 * @param options
 *      Options describing the stations to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLGasStation objects, and any errors.
 */
- (void) requestGasStationsOnRouteWithOptions: (IXCLGasStationsOnRouteOptions *) options
                                   completion: (void (^)(NSArray * GasStations, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Returns the a single IXCLGasStation object in the completion block.
 *
 * @param options
 *      Options describing the stations to retrieve from the server.
 * @param completion
 *      Block that returns an IXCLGasStation object, and any errors.
 */
- (void) requestSingleGasStationInformation: (IXCLSingleGasStationOptions *) options
                                 completion: (void (^)(IXCLGasStation * GasStation, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLGasStationsController
 * @abstract Gas Stations Controller
 */
@interface IXCLGasStationsController : IXCLBaseController <IXCLGasStationsControllerProtocol>
@end
