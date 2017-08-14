/*
 * @header IXCLSpeedLimitController.h
 * @abstract Controller requesting speed limits.
 * @author Aleksei Zhilin
 * @created 05-08-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"

@class IXCLSegment;
@class IXCLSpeedLimitOptions;

/*!
 * @protocol IXCLSpeedLimitControllerProtocol
 * @abstract
 *      Protocol definition for the speed limits controller.
 */
@protocol IXCLSpeedLimitControllerProtocol <NSObject>

/*!
 * @abstract Returns the IXCLSpeedLimit objects in the completion block.
 *
 * @param options
 *      IXCLSpeedLimitOptions describing the coordinate and parameters of the
 *      requested road segment with speed limit to retrieve from the server.
 * @param completion
 *      Block that returns an IXCLSegment object, and any errors.
 */
- (void) requestSpeedLimit: (IXCLSpeedLimitOptions *) options
                completion: (void (^)(IXCLSegment * speedLimit, IXCLCoreResponse * coreResponse)) completion;

@end

/*!
 * @class IXCLSpeedLimitController
 * @abstract The speed limit controller.
 */
@interface IXCLSpeedLimitController : IXCLBaseController<IXCLSpeedLimitControllerProtocol>

@end
