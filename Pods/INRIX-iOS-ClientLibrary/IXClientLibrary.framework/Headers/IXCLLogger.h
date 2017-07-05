/*
 * @header IXCLLogger.h
 * @abstract Class for controlling debug logging in the SDK
 * @author Kent Lottis
 * @updated 2-11-2014
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

/*!
 * @abstract:
 *   Represents the function type for listening to debug logging.
 */
typedef void (^ IXCLLogListenerMethod)(NSString * message);

/*!
 * @class IXCLLogger
 * @abstract Controls how debug logging is handled in the SDK.
 */
@interface IXCLLogger : NSObject

/*!
 * @abstract Sets the listener method that gets invoked by the IXCLDebugLog macro.
 *
 * @param listenerMethod The method to invoke when the IXCLDebugLog macro is invoked.
 *
 * @return The previous debug log listener, which can be used to either restore
 * state after the caller is done, or chain calls should he caller so choose.
 */
+ (IXCLLogListenerMethod) setListener: (IXCLLogListenerMethod) listenerMethod;

/*!
 * @abstract Sets the logging level to be observed for IXCLDebugLogLevel.
 *
 * @param logLevel The new debug log level to be used.
 *
 * @return The previous debug log level.
 */
+ (int) setLogLevel: (int) logLevel;
@end
