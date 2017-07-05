/*
 * @header IXCLLearnedLocationUpdateOptions.h
 * @abstract Represents parameters for updating learned locations.
 * @author Kent Lottis
 * @updated 08-27-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseOptions.h"

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLLearnedLocationUpdateOptions
 * @abstract Represents parameters for updating learned locations
 */
@interface IXCLLearnedLocationUpdateOptions : IXCLBaseOptions <NSCopying>
//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes an instance of the IXCLLearnedLocationUpdateOptions class with
 *      an array of IXCLLearnedLocations and the new desired state for the isHidden
 *      property.
 *
 * @param hidden
 *      The new value for the isHidden property of the locatiosn being updated.
 *
 * @param locations
 *      An array of IXCLLearnedLocation objects to update.
 *
 * @return
 *      Instance of the IXCLLearnedLocationUpdateOptions class.
 */
- (instancetype) initWithHiddenFlag: (BOOL) hidden
                          locations: (NSArray *) locations;

@end
