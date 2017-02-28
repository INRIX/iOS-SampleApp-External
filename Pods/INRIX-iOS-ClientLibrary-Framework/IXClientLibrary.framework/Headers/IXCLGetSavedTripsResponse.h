/*
 * @header IXCLGetSavedTripsResponse.h
 * @abstract The response object for the SavedTripsController getTrips method.
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

/*!
 * @class IXCLGetSavedTripsResponse
 *
 * @abstract
 *      Represents the response from the getSavedTrip method on the SavedTrip Controller.
 */
@interface IXCLGetSavedTripsResponse : NSObject

/*!
 * @abstract An array of IXCLSavedTrip objects.
 *
 */
@property (nonatomic, strong, readonly) NSArray * trips;

/*!
 * @abstract Initializes an IXCLGetSavedTripsResponse with an array of IXCLSavedTrip objects.
 * @param trips An array of IXCLSavedTrip objects.
 * @return An intitialized instance of the class.
 */
- (instancetype) initWithTrips: (NSArray *) trips;

@end
