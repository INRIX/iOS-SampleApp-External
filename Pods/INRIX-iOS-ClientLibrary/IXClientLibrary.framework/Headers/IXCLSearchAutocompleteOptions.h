/*
 * @header IXCLSearchAutocompleteOptions.h
 * @abstract Options class for performing a search autocomplete request.
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

@import Foundation;
@import CoreLocation;

#import "IXCLSearchOptions.h"

/*!
 * @abstract
 *      Options class for performing a search autocomplete request.
 */
@interface IXCLSearchAutocompleteOptions : IXCLSearchOptions <NSCopying>

/*!
 * @abstract
 *      Determines whether the learned cocations will be included in response.
 */
@property (nonatomic, assign, readwrite) BOOL includeLearnedLocations;

@end
