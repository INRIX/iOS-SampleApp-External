/*
 * @header IXCLUserPropertiesController.h
 * @abstract The User Properties Controller Class
 * @author Kent Lottis
 * @updated 05-19-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

#import "IXCLBaseController.h"
#import "IXCLUserPropertiesOptions.h"
#import "IXCLGetUserPropertiesResponse.h"

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLUserPropertiesControllerProtocol
 * @abstract
 *      Protocol definition for the User Properties Controller
 */
@protocol IXCLUserPropertiesControllerProtocol<NSObject>

/*!
 * @abstract
 *      Gets user properties from the server.
 * @param options
 *      The options object to control how the Get operation behaves
 * @param completion
 *      A block to execute when the Get operation completes.
 */
- (void) getUserPropertiesWithOptions: (IXCLGetUserPropertiesOptions *) options
                           completion: (void (^)(IXCLGetUserPropertiesResponse * getUserPropertiesResponse, IXCLCoreResponse * coreResponse)) completion;

/*!
 * @abstract
 *      Saves user properties to the server.
 * @param options
 *      The options object to control how the Save operation behaves
 * @param completion
 *      A block to execute when the Save operation completes.
 */
- (void) saveUserPropertiesWithOptions: (IXCLSaveUserPropertiesOptions *) options
                            completion: (void (^)(IXCLCoreResponse * coreResponse)) completion;
@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 *  @abstract
 *      The User Properties Controller allows applications to save and restore
 *      user-specific settings on the INRIX server.
 */
@interface IXCLUserPropertiesController : IXCLBaseController<IXCLUserPropertiesControllerProtocol>
@end
