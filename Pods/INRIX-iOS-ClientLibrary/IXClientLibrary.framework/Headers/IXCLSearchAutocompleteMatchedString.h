/*
 * @header IXCLSearchAutocompleteMatchedString.h
 * @abstract
 *      Model objects which respresent a single matched string from search
 *      autocomplete results.
 * @author Aleksei Zhilin
 * @updated 3-10-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

@interface IXCLSearchAutocompleteMatchedString : NSObject <NSCopying>

/*!
 * @abstract The matched string's length.
 */
@property (nonatomic, assign, readwrite) NSInteger length;

/*!
 * @abstract The matched string's start offset.
 */
@property (nonatomic, assign, readwrite) NSInteger offset;

@end
