/*
 * @header IXCLMotionActivityManager.h
 * @abstract
 *      Override class for CMMotionActivityManager to allow class methods to be
 *      replaced for test purposes.
 * @author David Potter
 * @updated 01-06-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import CoreMotion;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class
 *      IXCLMotionActivityManager
 * @abstract
 *      Override class for CMMotionActivityManager to allow class methods to be
 *      replaced for test purposes.
 */
@interface IXCLMotionActivityManager : CMMotionActivityManager

/*!
 * @abstract
 *      A Boolean value indicating whether motion data is available on the
 *      device.  Equivalent to
 *      +[CMMotionActivityManager isMotionActivityAvailable].
 */
@property (nonatomic, assign, readonly) BOOL isMotionActivityAvailable;

@end
