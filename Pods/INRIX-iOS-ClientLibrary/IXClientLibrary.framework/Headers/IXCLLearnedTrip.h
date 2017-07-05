/*
 * @header IXCLLearnedTrip.h
 * @abstract The learned itinerary model object.
 * @author Cheng Cheng
 * @updated 06-11-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLTrip.h"
#import "IXCLLearnedLocation.h"
#import "IXCLRoute.h"

/*!
 * @class IXCLLearnedTrip
 * @abstract
 *      Represents a trip that the user has repeated multiple times and which
 *      has been learned by AutoTelligent.
 */
@interface IXCLLearnedTrip : IXCLTrip

/*!
 * @abstract The starting location of the learned trip.
 */
@property (nonatomic, strong, readonly) IXCLLearnedLocation * origin;

/*!
 * @abstract The destination location of the learned trip.
 */
@property (nonatomic, strong, readonly) IXCLLearnedLocation * destination;

/*!
 * @abstract The arrival time of the learned trip.
 */
@property (nonatomic, copy, readonly) NSDate * dateTime;

/*!
 * @abstract The route id of the learned trip.
 */
@property (nonatomic, strong, readonly) NSString * routeId;

/*!
 * @abstract The relative weight of the learned trip.
 * @discussion
 *      Higher values indicate higher likelihood of
 *      taking this learned trip over other learned trips at the same time.
 */
@property (nonatomic, assign, readonly) double weight;

@end
