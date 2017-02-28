/*
 * @header IXCLItineraryOptions.h
 * @abstract The options class for getting itinerary from server.
 * @author Cheng Cheng
 * @updated 04-14-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

#import "IXCLBaseOptions.h"

/*!
 * @class IXCLItineraryOptions
 *
 * @abstract
 *      Represents to options to the getItinerary method on the trip controller.
 */
@interface IXCLItineraryOptions : IXCLBaseOptions <NSCopying>

/*!
 * @abstract The start date of the itineraries to be retrieved.
 * @discussion  The start date in the past is not supported. 
 *              Server may send back unreliable data 
 *              if the start date is in the past.
 */
@property (nonatomic, strong, readwrite) NSDate * startDate;

/*!
 * @abstract The end date of the itineraries to be retrieved.
 */
@property (nonatomic, strong, readwrite) NSDate * endDate;

/*!
 * @abstract The coordinate related to the itineraries to be retrieved.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D currentCoord;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
