/*
 * @header IXCLItinerary.h
 * @abstract The Itinerary model object.
 * @author Cheng Cheng
 * @updated 04-13-2015
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
 * @class IXCLItinerary
 *
 * @abstract
 *      An Itinerary is a collection of scheduled trips. A scheduled trip is an
 *      instance of a trip at a specified date and time. For a one-time trip this
 *      may be only one instance, but for a recurring trip there may be many
 *      instances that occur between the itinerary start and end dates.
 */
@interface IXCLItinerary : NSObject <NSCopying>

/*!
 * @abstract
 *      The start time of the trip collection, in UTC.
 */
@property (nonatomic, strong, readonly) NSDate * startDate;

/*!
 * @abstract
 *      The start time of the trip collection, in UTC.
 */
@property (nonatomic, strong, readonly) NSDate * endDate;

/*!
 * @abstract
 *      An array of @ref IXCLItineraryEntry items representing instances
 *      of trips that occur between the start and end dates.
 */
@property (nonatomic, strong, readonly) NSArray * itineraryEntries;
@end
