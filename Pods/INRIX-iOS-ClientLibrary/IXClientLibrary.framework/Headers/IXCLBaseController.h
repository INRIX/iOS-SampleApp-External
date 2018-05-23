/*
 * @header IXCLBaseController.h
 * @abstract Base class for controllers managing the server requests behavior.
 * @author Gaurav Agarwal
 * @updated 04-21-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


@class IXCLAuthResponse;
@class IXCLBaseOptions;
@class IXCLCore;
@class IXCLCoreRequest;
@class IXCLCoreResponse;


typedef IXCLCoreRequest * (^ IXCLBaseControllerRequestBlock) (IXCLAuthResponse * authResponse);
typedef void (^ IXCLBaseControllerResponseBlock) (id result, IXCLCoreResponse * coreResponse);
typedef BOOL (^ IXCLBaseControllerShouldRetryBlock) (NSError * error);

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/* @private
 * @class IXCLBaseController
 * @abstract Base class for controllers managing the server requests behavior.
 */
@interface IXCLBaseController : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Instance of the IXCLCore class to be used by this class.
 */
@property (nonatomic, weak, readonly) IXCLCore * inrixCore;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize self with an IXCLCore object.
 *
 * @param inrixCore Instance of the IXCLCore class to be used by this class.
 *
 * @return Instance of the IXCLBaseController class.
 */
- (instancetype) initWithInrixCore: (IXCLCore *) inrixCore;

/*!
 * @abstract Determines whether the combination of properties are valid.
 * @param options The options-class object to validate.
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalidOptions: (IXCLBaseOptions *) options;

/*!
 * @abstract
 *      Helper method that handles invalid parameters passed to a controller
 *      public method.
 * @discussion
 *      An exception will be thrown if the completion block is not specified.
 *      If the options are not specified or are invalid, an instance of
 *      IXCLCoreResponse will be returned.
 *
 * @param options    Options to validate.
 * @param completion Completion block to validate.
 *
 * @return
 *      An instance of IXCLCoreResponse if an error occurs, otherwise nil.
 *
 * @throws
 *      IXCLNilParameterException if the completion block is not specified.
 */
- (IXCLCoreResponse *) responseIfInvalidOptions: (IXCLBaseOptions *) options
                                     completion: (id) completion;

/*!
 * @abstract Returns an IXCLCoreResponse if IXCLCore is shut down.
 *
 * @return IXCLCoreResponse if IXCLCore is shut down, otherwise nil.
 */
- (IXCLCoreResponse *) responseIfCoreShutDown;

/*!
 * @abstract
 *      Helper method to call the request update block if available in the
 *      options to indicate that a server request is being made.
 *
 * @param options Options containing the request update block.
 * @param async   YES if the block should be called asynchronously, otherwise NO.
 */
- (void) sendServerRequestBeingMadeWithOptions: (IXCLBaseOptions *) options async: (BOOL) async;

/*!
 * @abstract
 *      Helper method for all the IXCL controllers for executing the server
 *      request with retry logic. It performs the MoSI Auth first and then
 *      executes the request specified by 'requestBlock'.
 *
 * @param requestBlock
 *      The block providing the request to execute.
 * @param responseBlock
 *      The response block to be called after the request is executed.
 * @param shouldRetryBlock
 *      The block providing information on whether the API should retry
 *      executing the request after an error.
 * @param isAuthRequired
 *      Whether auth is needed before executing the request.
 */
- (void) executeRequestWithBlock: (IXCLBaseControllerRequestBlock) requestBlock
                   responseBlock: (IXCLBaseControllerResponseBlock) responseBlock
                shouldRetryBlock: (IXCLBaseControllerShouldRetryBlock) shouldRetryBlock
                  isAuthRequired: (BOOL) isAuthRequired;

/*!
 * @abstract
 *      Helper method for all the IXCL controllers for executing the server
 *      request with retry logic. It performs the MoSI Auth first and then
 *      executes the request specified by 'requestBlock'.
 *
 * @param requestBlock
 *      The block providing the request to execute.
 * @param responseBlock
 *      The response block to be called after the request is executed.
 * @param shouldRetryBlock
 *      The block providing information on whether the API should retry
 *      executing the request after an error.
 */
- (void) executeRequestWithBlock: (IXCLBaseControllerRequestBlock) requestBlock
                   responseBlock: (IXCLBaseControllerResponseBlock) responseBlock
                shouldRetryBlock: (IXCLBaseControllerShouldRetryBlock) shouldRetryBlock;

/*!
 * @abstract Determines if retry is allowed for the given error
 * @discussion
 *      Defaults to NO if error is not in the subclass managed
 *      controllerSpecificAbortErrorCodes.
 *
 * @param error The error to be looked up.
 * @param abortErrorCodes The set of error codes to compare against.
 *
 * @return YES if retry should be aborted, NO otherwise.
 */
- (BOOL) shouldAbortRetryForError: (NSError *) error
                  abortErrorCodes: (NSSet *) abortErrorCodes;

@end
