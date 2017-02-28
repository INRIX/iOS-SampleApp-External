/*
 * @header IXCLSavedTrip.h
 * @abstract The SavedTrip model object.
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

#import "IXCLTrip.h"
#import "IXCLTripSchedule.h"
#import "IXCLLearnedTrip.h"

/*!
 * @class IXCLSavedTrip
 *
 * @abstract
 *      Represents the geometry and scheduling properties of a trip.
 */
@interface IXCLSavedTrip : IXCLTrip

/*!
 * @abstract The scheduling information for a saved trip.
 *
 */
@property (nonatomic, strong, readwrite) IXCLTripSchedule * schedule;

/*!
 * @abstract The server identifier for this saved trip.
 *
 */
@property (nonatomic, strong, readonly) NSString * tripId;

/*!
 * @abstract The starting point of the trip.
 *
 */
@property (nonatomic, strong, readwrite) IXCLTripPoint * origin;

/*!
 * @abstract The ending point of the trip.
 *
 */
@property (nonatomic, strong, readwrite) IXCLTripPoint * destination;

/*!
 * @abstract An array of IXCLTripPoint objects representing the intermediate waypoints of a trip.
 *
 * @discussion
 *      Can be nil or empty to represent a trip with no waypoints.
 */
@property (nonatomic, strong, readwrite) NSArray * waypoints;

/*!
 * @abstract The criteria for this route find request.
 * @discussion Defaults to IXCLRouteOptionsCriteriaUseDefault.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsCriteriaMask criteriaMask;

/*!
 * @abstract
 *      The type of route to return.
 * @discussion
 *      Defaults to IXCLRouteOptionsTypeFastest. IXCLRouteOptionsTypeUseDefault is not allowed.
 */
@property (nonatomic, assign, readwrite) IXCLRouteOptionsType routeType;

/*!
 * @abstract
 *      Contacts associated with this trip.
 * @discussion
 *      NSMutableArray of IXCLContact objects.
 */
@property (nonatomic, strong, readonly) NSMutableArray * associatedContacts;

/*!
 * @abstract Initializes an instance of the IXCLSavedTrip class with points and scheduling information.
 * @param origin The starting point of the trip.
 * @param destination The ending point of the trip.
 * @param waypoints The intermediate waypoints of the trip. Can be nil or empty for trips with no waypoints.
 * @param schedule The scheduling information for the trip.
 * @return An initialized SavedTrip object.
 */
- (instancetype) initWithPointsAndSchedule: (IXCLTripPoint *) origin
                               destination: (IXCLTripPoint *) destination
                                 waypoints: (NSArray *) waypoints
                                  schedule: (IXCLTripSchedule *) schedule;

/*!
 * @abstract Initializes an instance of the SavedTrip class with a learned trip.
 * @param learnedTrip A learned trip that the system has created for the user.
 * @return An initialized SavedTrip object.
 */
- (instancetype) initWithLearnedTrip: (IXCLLearnedTrip *) learnedTrip;

@end
