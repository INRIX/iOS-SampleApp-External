/*
 * @header IXCLLearnedLocation.h
 * @abstract Model object representing the location of a learned trip.
 * @author Aleksei Zhilin
 * @updated 12-15-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLLocation.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLLearnedLocation
 *
 * @abstract
 *      Model object representing a learned location of a learned trip.
 */
@interface IXCLLearnedLocation : IXCLLocation

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The probability or priority of using the location.
 */
@property (nonatomic, assign, readwrite) double priority;

/*!
 * @abstract
 *      A boolean flag indicating whether or not the learned location is to be hidden from users.
 */
@property (nonatomic, assign, readwrite) BOOL isHidden;

/*!
 * @abstract The probability or priority of using the location by hours.
 */
@property (nonatomic, strong, readwrite) NSMutableDictionary * hourConditionalLikelihoods;

/*!
 * @abstract The probability or priority of using the location by days of week.
 */
@property (nonatomic, strong, readwrite) NSMutableDictionary * dayConditionalLikelihoods;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes an IXCLLearnedLocation instance from the specified location id
 *      and coordinate.
 *
 * @param locationId  The location id.
 * @param coordinate  The location coordinate.
 *
 * @return IXCLLearnedLocation
 */
- (instancetype) initWithLocationId: (NSString *) locationId
                         coordinate: (CLLocationCoordinate2D) coordinate;

@end
