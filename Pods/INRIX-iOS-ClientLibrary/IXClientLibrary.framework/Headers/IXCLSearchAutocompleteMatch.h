/*
 * @header IXCLSearchAutocompleteMatch.h
 * @abstract Model objects which respresent a search autocomplete result.
 * @author Aleksei Zhilin
 * @updated 3-9-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

@class IXCLSearchAutocompleteMatchedString;
@class IXCLSearchAutocompleteTerm;

/*!
 * @abstract
 *      A model object that respresents a single search autocomplete result.
 */
@interface IXCLSearchAutocompleteMatch : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier of a place.
 */
@property (nonatomic, strong, readwrite) NSString * placeId;

/*!
 * @abstract The description of a match.
 */
@property (nonatomic, strong, readwrite) NSString * placeDescription;

/*!
 * @abstract The list of matched strings.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLSearchAutocompleteMatchedString *> * matchedStrings;

/*!
 * @abstract The list of result terms.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLSearchAutocompleteTerm *> * terms;

@end
