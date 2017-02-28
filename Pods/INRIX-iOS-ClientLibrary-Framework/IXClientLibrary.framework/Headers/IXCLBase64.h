/*
 * @header IXCLBase64.h
 * @abstract Categories on NSString and NSData to add base64 support.
 * @discussion From the QSStrings class in the QSUtilities Library - https://github.com/mikeho/QSUtilities
 * @author David Potter
 * @updated 10-04-2011
 * @copyright Copyright (c) 2011-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

// TODO: (David 3/19/2014) Rename this file as NSString+IXCLBase64

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark NSString Class Category Declaration

/*!
 * @category NSString (IXCLBase64)
 * @abstract Base64 methods on NSStrings.
 */
@interface NSString (IXCLBase64)

/*!
 * @abstract Decodes a base64-encoded string
 *
 * @return Decoded data.
 */
- (NSData *) ixcl_decodeBase64;


/*!
 * @abstract Encodes a string as base64.
 *
 * @return Encoded string.
 */
- (NSString *) ixcl_encodeBase64;

@end


//-----------------------------------------------------------------------------
#pragma mark - NSData Class Category Declaration

/*!
 * @category NSData (IXCLBase64)
 * @abstract Base64 methods on NSData objects.
 */
@interface NSData (IXCLBase64)

/*!
 * @abstract Encodes data as base64.
 *
 * @return Encoded data.
 */
- (NSString *) ixcl_encodeBase64;

@end
