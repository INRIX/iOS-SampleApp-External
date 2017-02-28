/*
 * @header IXCLLogging.h
 * @abstract Definitions used for debug logging.
 * @author Dmitri Fuerle
 * @updated 10-22-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

#define IXCLLogLevelDebug   0
#define IXCLLogLevelInfo    1
#define IXCLLogLevelWarning 2
#define IXCLLogLevelError   3

void ixclNSlog(NSString * fmt, ...);
void ixclLogDebug(NSString * fmt, ...);
void ixclLogLevel(int logLevel, NSString * fmt, ...);

#define IXCLFileLineAndFunc [NSString stringWithFormat: @"%@:%d : %s", [[NSString stringWithUTF8String: __FILE__] lastPathComponent], __LINE__, __FUNCTION__]

#define IXCLDebugLog(s, ...) ixclLogDebug(@"%@ " s, IXCLFileLineAndFunc, ## __VA_ARGS__)

#define IXCLDebugLogLevel(errorLevel, s, ...) ixclLogLevel(errorLevel, @"%@ " s, IXCLFileLineAndFunc, ## __VA_ARGS__)
