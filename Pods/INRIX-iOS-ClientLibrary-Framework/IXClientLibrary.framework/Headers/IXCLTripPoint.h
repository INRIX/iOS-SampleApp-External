/*
 * @header IXCLTripPoint.h
 * @abstract The TripPoint model object.
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

@class IXCLLocation;

/*!
 * @class IXCLTripPoint
 *
 * @abstract Represents a waypoint on a trip, with a possible stop time.
 */
@interface IXCLTripPoint : NSObject <NSCopying>

/*!
 * @abstract The location information for the trip point.
 */
@property (nonatomic, strong, readwrite) IXCLLocation * location;

/*!
 * @abstract
 *      The duration, in minutes, of a stop at the point. A value of zero means
 *      that the trip simply passes through the point without stopping.
 */
@property (nonatomic, assign, readwrite) int duration;

/*!
 * @abstract
 *      If an IXCLTripPoint was created with a IXCLLocation and this
 *      IXCLLocation was subsequently deleted this value will be true.
 * @discussion
 *      This is an indication that the locationId is no longer valid and
 *      that there will be no updates to the IXCLTripPoint details from
 *      the associated IXCLLocation.
 */
@property (nonatomic, assign, readwrite) bool isDeleted;

/*!
 * @abstract The timezone used for the trip point.
 */
@property (nonatomic, strong, readwrite) NSTimeZone * timeZone;

/*!
 * @abstract
 *      Initializes an instance of the IXCLTripPoint class with location and
 *      stop information.
 * @param location
 *      The locattion information for the trip point.
 * @param duration
 *      The duration of an optional stop at the trip point. A value of zero
 *      means the trip proceeds through the trip point without stopping.
 * @return
 *      An initialized Trip Point object.
 */
- (instancetype) initWithLocation: (IXCLLocation *) location
                         duration: (int) duration;

@end
