/*
 * @header IXCLGasStation.h
 * @abstract Gas station data object.
 * @author Patrick Winchell
 * @updated 02-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLMapPoint.h"

#import "IXCLAddress.h"
#import "IXCLFuelProduct.h"

/*!
 * @class IXCLGasStation
 * @abstract
 *          The data model object representing a Gas Station.
 */
@interface IXCLGasStation : IXCLMapPoint <NSCoding, NSCopying>

/*!
 * @abstract The unique identifier associated with the gas station.
 */
@property (nonatomic, copy, readwrite) NSString * stationId;

/*!
 * @abstract The brandname associated with the gas station.
 */
@property (nonatomic, copy, readwrite) NSString * brand;

/*!
 * @abstract An array of IXCLFuelProducts describing the types of fuel sold
 * at this gas station.
 */
@property (nonatomic, copy, readwrite) NSArray * products;

/*!
 * @abstract The address of the gas station.
 */
@property (nonatomic, copy, readwrite) IXCLAddress * address;

/*!
 * @abstract The gas station was of the preferred brand that was requested.
 */
@property (nonatomic, assign, readwrite) BOOL preferred;

/*!
 * @abstract
 *      Obtain the hash value of self.
 *
 * @discussion
 *      This method returns the hash of the stationId.
 *
 * @return
 *      The hash value of this object.
 */
- (NSUInteger) hash;

/*!
 * @abstract
 *      Check for equality with another object.
 *
 * @discussion
 *      The objects is considered equal if they are of the same type with
 *      matching stationIds.
 *
 * @param object
 *      The object to test for equality.
 *
 * @return YES if the objects are equal, NO otherwise.
 */
- (BOOL) isEqual: (id) object;

@end
