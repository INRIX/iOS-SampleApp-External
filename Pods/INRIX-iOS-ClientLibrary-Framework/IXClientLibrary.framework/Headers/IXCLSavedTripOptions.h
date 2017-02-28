/*
 * @header IXCLSaveTripOptions.h
 * @abstract The options class for the Trip Controller's saveTrip method.
 * @author Kent Lottis
 * @updated 03-02-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

#import "IXCLSavedTrip.h"

#import "IXCLBaseOptions.h"

/*!
 * @class IXCLSavedTripOptions
 * @abstract
 *      Represents to options to the saveTrip method on the trip controller.
 */
@interface IXCLSavedTripOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract The Saved Trip object to be saved.
 */
@property (nonatomic, strong, readwrite) IXCLSavedTrip * trip;

/*!
 * @abstract Initializes an instance of the IXCLSaveTripOptions class with the SavedTrip object to be saved.
 * @param trip The SavedTrip object to be saved.
 * @return An IXCLSavedTripOptions object with the specific trip value.
 */
- (instancetype) initWithTrip: (IXCLSavedTrip *) trip;

@end
