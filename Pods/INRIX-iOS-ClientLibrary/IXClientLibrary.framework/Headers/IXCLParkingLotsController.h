/*
 * @header IXCLParkingLotsController.h
 * @abstract Controller for managing parking lots.
 * @author Cheng Cheng
 * @updated 02-24-2015
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
#import "IXCLParkingLot.h"

@class IXCLParkingLotsInRadiusOptions;
@class IXCLParkingLotsInBoxOptions;
@class IXCLParkingLotByIdOptions;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLParkingLotsControllerProtocol
 * @abstract
 *      Protocol definition for the Parking Lots Controller
 */
@protocol IXCLParkingLotsControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Instance Methods

/*!
 * @abstract Returns the array of IXCLParkingLot objects in the completion block.
 *
 * @param options
 *      Options describing the parking lots in radius to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLParkingLot objects, and any errors.
 */
- (void) requestParkingLotsInRadiusWithOptions: (IXCLParkingLotsInRadiusOptions *) options
                                    completion: (void (^)(NSArray * parkingLots, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLParkingLot objects in the completion block.
 *
 * @param options
 *      Options describing the parking lots in box to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLParkingLot objects, and any errors.
 */
- (void) requestParkingLotsInBoxWithOptions: (IXCLParkingLotsInBoxOptions *) options
                                 completion: (void (^)(NSArray * parkingLots, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLParkingLot objects in the completion block.
 *
 * @param options
 *      Options describing the parking lot Ids to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLParkingLot objects, and any errors.
 */
- (void) requestParkingLotByParkingLotIdOptions: (IXCLParkingLotByIdOptions *) options
                                     completion: (void (^)(NSArray * parkingLots, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingLotsController
 * @abstract Controller for managing parking lots.
 */
@interface IXCLParkingLotsController : IXCLBaseControllerWithCache<IXCLParkingLotsControllerProtocol>
@end
