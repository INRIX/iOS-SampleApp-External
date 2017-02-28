/*
 * @header IXCLDangerousSlowdownsController.h
 * @abstract Controller requesting dangerous slowdowns.
 * @author Patrick Winchell
 * @created 11-10-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"
@class IXCLDangerousSlowdownsInBoxOptions;
@class IXCLDangerousSlowdownsInRadiusOptions;

@protocol IXCLDangerousSlowdownsControllerProtocol <NSObject>

/*!
 * @abstract Returns the array of IXCLDangerousSlowdown objects in the completion block.
 *
 * @param options
 *      IXCLDangerousSlowdownsInBoxOptions describing the dangerous slowdowns to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLDangerousSlowdown objects, and any errors.
 */
- (void) requestDangerousSlowdownsInBox: (IXCLDangerousSlowdownsInBoxOptions *) options
                                completion: (void (^)(NSArray * slowdowns, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract Returns the array of IXCLDangerousSlowdown objects in the completion block.
 *
 * @param options
 *      IXCLDangerousSlowdownsInRadiusOptions describing the dangerous slowdowns to retrieve from the server.
 * @param completion
 *      Block that returns an array of IXCLDangerousSlowdown objects, and any errors.
 */
- (void) requestDangerousSlowdownsInRadius: (IXCLDangerousSlowdownsInRadiusOptions *) options
                                   completion: (void (^)(NSArray * slowdowns, IXCLCoreResponse * coreResponse)) completion;

@end

@interface IXCLDangerousSlowdownsController : IXCLBaseController<IXCLDangerousSlowdownsControllerProtocol>

@end
