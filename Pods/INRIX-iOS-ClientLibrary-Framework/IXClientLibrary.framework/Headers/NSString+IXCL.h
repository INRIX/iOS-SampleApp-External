/*
 * @header NSString+IXCL.h
 * @abstract Category on the NSString class to provide methods useful for working with the IXCL.
 * @author David Potter
 * @updated 10-18-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Class Category Declaration

/*!
 * @category
 *      NSString (IXCL)
 * @abstract
 *      Category on the NSString class to provide methods useful for working
 *      with the IXCL.
 */
@interface NSString (IXCL)

/*!
 * @abstract Generates a string from a random UUID.
 * @return String form of a UUID.
 */
+ (NSString *) ixcl_stringFromRandomUUID;

/*!
 * @abstract Converts an NSInteger to a string.
 *
 * @param intValue The integer to convert.
 *
 * @return String form of an NSInteger.
 */
+ (NSString *) ixcl_stringFromInt: (NSInteger) intValue;

/*!
 * @abstract Converts a CGFloat to a string.
 *
 * @param floatValue The float to convert.
 *
 * @return String form of a CGFloat.
 */
+ (NSString *) ixcl_stringFromFloat: (CGFloat) floatValue;

/*!
 * @abstract Checks if email address is valid.
 *
 * @param email Email address to validate.
 *
 * @return YES if email is valid, otherwise NO.
 */
+ (BOOL) ixcl_isValidEmailFormat: (NSString *) email;

@end
