/*
 * @header IXCLTimer.h
 * @abstract Custom timer providing pause and resume functionality.
 * @author Cheng Cheng
 * @updated 05-12-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


@class IXCLTimer;

//----------------------------------------------------------------------------
#pragma mark - Global Constants

FOUNDATION_EXPORT NSString * const IXCLTimerNameDefault;

//-----------------------------------------------------------------------------
#pragma mark - Enum Definitions

/*!
 * @abstract The state of the timer.
 *
 * @constant IXCLTimerStateRunning Timer is firing.
 * @constant IXCLTimerStatePaused  Timer is not firing, but is initialzied
 *   and ready to be started or resumed.
 * @constant IXCLTimerStateStopped Timer is not fireing, and may not
 *   be started or resumed.
 */
typedef NS_ENUM (NSUInteger, IXCLTimerState)
{
    IXCLTimerStateRunning = 0,
    IXCLTimerStatePaused,
    IXCLTimerStateStopped
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTimer
 * @abstract Custom timer providing pause and resume functionality.
 */
@interface IXCLTimer : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The number of seconds between firings of the timer.
 */
@property (nonatomic, assign, readonly) NSTimeInterval timeInterval;

/*!
 * @abstract The block to call when the timer fires.
 */
@property (nonatomic, copy, readonly) dispatch_block_t timerBlock;

/*!
 * @abstract The current state of the timer.
 */
@property (nonatomic, assign, readonly) IXCLTimerState state;

/*!
 * @abstract The timer's name, for diagnostic/debugging purposes
 *
 */
@property (nonatomic, strong, readwrite) NSString * name;

/*!
 * @abstract Whether or not the timer will run with the app in the background.
 *
 */
@property (nonatomic, assign, readonly) BOOL runsInBackground;

/*!
 * @abstract The amount of time after the scheduled fire date that the timer may fire.
 *
 */
@property (nonatomic, assign, readwrite) NSTimeInterval tolerance;


//-----------------------------------------------------------------------------
#pragma mark - Methods


/*!
 * @abstract
 *      Allocates an IXCLTimer using a register factory block, if present.
 *      If no factory block is regisered, this is equivalent to alloc.
 *      Using this provides an easy way of mocking IXCLTimer.
 */
+ (id) allocUsingFactory;

/*!
 * @abstract
 *      Registers an allocator block that replaces the normal alloc behid
 *      allocUsingFactory. Used by test code to implement mocking.
 *
 * @param factoryBlock
 *      The block to call to allocate alternal IXCLTimer objects.
 */
+ (void) registerFactory: (id (^)()) factoryBlock;

/*!
 * @abstract
 *      Creates an IXCLTimer with the specified time interval and block to call
 *      when timer fires.
 *
 * @param timeInterval
 *      The number of seconds between firings of the timer.  If timeInterval is
 *      less than or equal to 0.0, this method chooses the nonnegative value of
 *      0.1 milliseconds instead.
 * @param name
 *      A name for the timer for debugging and diagnostic purposes.
 * @param timerBlock
 *      The block to call when the timer fires.
 * @param runsInBackground
 *      If false the timer will be automatically paused when the app enters the background.
 * @param startImmediately
 *      If true, the timer will begin countdown immediately. If false, the timer will not
 *      begin countdown until start is called.
 * @param useWallTime
 *      If true, the timer will use wall time instead of app time.
 *
 * @return
 *      An instance of the IXCLTimer class.
 */
- (instancetype) initWithTimeInterval: (NSTimeInterval) timeInterval
                                 name: (NSString *) name
                     runsInBackground: (BOOL) runsInBackground
                     startImmediately: (BOOL) startImmediately
                          useWallTime: (BOOL) useWallTime
                           timerBlock: (dispatch_block_t) timerBlock;

/*!
 * @abstract
 *      Creates an IXCLTimer with the specified time interval and block to call
 *      when timer fires.
 *
 * @param timeInterval
 *      The number of seconds between firings of the timer.  If timeInterval is
 *      less than or equal to 0.0, this method chooses the nonnegative value of
 *      0.1 milliseconds instead.
 * @param name
 *      A name for the timer for debugging and diagnostic purposes.
 * @param timerBlock
 *      The block to call when the timer fires.
 * @param runsInBackground
 *      If false the timer will be automatically paused when the app enters the background.
 * @param startImmediately
 *      If true, the timer will begin countdown immediately. If false, the timer will not
 *      begin countdown until start is called.
 *
 * @return
 *      An instance of the IXCLTimer class.
 */
- (instancetype) initWithTimeInterval: (NSTimeInterval) timeInterval
                                 name: (NSString *) name
                     runsInBackground: (BOOL) runsInBackground
                     startImmediately: (BOOL) startImmediately
                           timerBlock: (dispatch_block_t) timerBlock;

/*!
 * @abstract
 *      Creates an IXCLTimer with the specified time interval and block to call
 *      when timer fires. The timer will start immediately.
 *
 * @param timeInterval
 *      The number of seconds between firings of the timer.  If timeInterval is
 *      less than or equal to 0.0, this method chooses the nonnegative value of
 *      0.1 milliseconds instead.
 * @param name
 *      A name for the timer for debugging and diagnostic purposes.
 * @param timerBlock
 *      The block to call when the timer fires.
 * @param runsInBackground
 *      If false the timer will be automatically paused when the app enters the background.
 *
 * @return
 *      An instance of the IXCLTimer class.
 */
- (instancetype) initWithTimeInterval: (NSTimeInterval) timeInterval
                                 name: (NSString *) name
                     runsInBackground: (BOOL) runsInBackground
                           timerBlock: (dispatch_block_t) timerBlock;

/*!
 * @abstract
 *      Creates an IXCLTimer with the specified time interval and block to call
 *      when timer fires.
 *
 * @param timeInterval
 *      The number of seconds between firings of the timer.  If timeInterval is
 *      less than or equal to 0.0, this method chooses the nonnegative value of
 *      0.1 milliseconds instead.
 * @param name
 *      A name for the timer for debugging and diagnostic purposes.
 * @param timerBlock
 *      The block to call when the timer fires.
 *
 * @return
 *      An instance of the IXCLTimer class.
 */
- (instancetype) initWithTimeInterval: (NSTimeInterval) timeInterval
                                 name: (NSString *) name
                           timerBlock: (dispatch_block_t) timerBlock;

/*!
 * @abstract
 *      Creates an IXCLTimer with the specified time interval and block to call
 *      when timer fires.
 *
 * @discussion
 *      Timers created with this initializer will be given a default name.
 * @param timeInterval
 *      The number of seconds between firings of the timer.  If timeInterval is
 *      less than or equal to 0.0, this method chooses the nonnegative value of
 *      0.1 milliseconds instead.
 * @param timerBlock
 *      The block to call when the timer fires.
 *
 * @return
 *      An instance of the IXCLTimer class.
 */
- (instancetype) initWithTimeInterval: (NSTimeInterval) timeInterval
                           timerBlock: (dispatch_block_t) timerBlock;

/*!
 * @abstract
 *      Pauses the running timer. A paused timer may be started or resumed.
 * @discussion
 *      If timer is already paused or stopped, then calling this method has no
 *      effect.
 */
- (void) pause;

/*!
 * @abstract
 *      Resumes the paused timer, firing timeInterval from last fire time.
 * @discussion
 *      If timer is already running or stopped, then calling this method has no
 *      effect.
 */
- (void) resume;

/*!
 * @abstract Stops the timer. A stopped timer may not be restarted.
 */
- (void) stop;

/*!
 * @abstract Starts a paused timer, firing timeInterval from now.
 */
- (void) start;

@end
