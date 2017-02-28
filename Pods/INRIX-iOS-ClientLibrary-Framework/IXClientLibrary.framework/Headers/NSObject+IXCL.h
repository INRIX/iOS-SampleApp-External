/*
 * @header NSObject+IXCL.h
 * @abstract
 *      Category on NSObject to add functionality useful to the IXCL library.
 * @author David Potter
 * @updated 05-07-2014
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
#pragma mark Class Declaration

/*!
 * @category
 *      NSObject (IXCL)
 * @abstract
 *      Category on NSObject to add functionality useful to the IXCL library.
 */
@interface NSObject (IXCL)

/*!
 * @abstract Calls the block on the main thread.
 *
 * @param block Block to call.
 */
- (void) ixcl_performBlock: (dispatch_block_t) block;

/*!
 * @abstract
 *      Calls the block on a background thread.
 * @discussion
 *      The block is dispatched on the default-priority dispatch queue
 *      (DISPATCH_QUEUE_PRIORITY_DEFAULT).
 *
 * @param block
 *      Block to call.
 */
- (void) ixcl_performBlockInBackground: (dispatch_block_t) block;

/*!
 * @abstract
 *      Calls the block on the main thread after the specified number of
 *      seconds.
 *
 * @param delay Number of seconds to wait before calling the block.
 * @param block
 *      Block to call.
 */
- (void) ixcl_performAfterDelay: (NSTimeInterval) delay block: (dispatch_block_t) block;

/*!
 * @abstract
 *      Calls the block on a background thread after the specified number of
 *      seconds.
 * @discussion
 *      The block is dispatched on the default-priority dispatch queue
 *      (DISPATCH_QUEUE_PRIORITY_DEFAULT).
 *
 * @param delay Number of seconds to wait before calling the block.
 * @param block Block to call.
 */
- (void) ixcl_performInBackgroundAfterDelay: (NSTimeInterval) delay block: (dispatch_block_t) block;

/*!
 * @abstract Calls the block after the specified number of seconds.
 *
 * @param delay Number of seconds to wait before calling the block.
 * @param queue Dispatch queue on which the block will be called.
 * @param block Block to call.
 */
- (void) ixcl_performAfterDelay: (NSTimeInterval) delay
                        onQueue: (dispatch_queue_t) queue
                          block: (dispatch_block_t) block;

@end
