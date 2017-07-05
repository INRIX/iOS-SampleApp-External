/*
 * @header IXCLAggregateMapPoint.h
 * @abstract Class for managing the aggregation of map items.
 * @author Gaurav Agarwal
 * @updated 05-21-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLMapPoint.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLAggregateMapPoint
 * @abstract Class for managing the aggregation of map items.
 */
@interface IXCLAggregateMapPoint : IXCLMapPoint <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with an array of map items.
 *
 * @param mapItems Map items to be aggregated.
 *
 * @return Instance of the IXCLAggregateMapPoint class.
 */
- (instancetype) initWithMapItems: (NSArray *) mapItems;

/*!
 * @abstract Returns the list of map items in the aggregate.
 *
 * @return NSArray of aggregated map items.
 */
- (NSArray *) mapItems;

/*!
 * @abstract
 *      Adds the map items to the aggregate.
 * @discussion
 *      Calling this method will modify the 'coordinate' property which is set
 *      to average of coordinates of map items.
 *
 * @param mapItem
 *      IXCLMapPoint instance to add to the list of aggregated map items.
 */
- (void) addMapItem: (IXCLMapPoint *) mapItem;

/*!
 * @abstract
 *      Removes the map items from the aggregate.
 * @discussion
 *      Calling this method will modify the 'coordinate' property which is set
 *      to average of coordinates of map items.
 *
 * @param mapItem
 *      IXCLMapPoint instance to add from the list of aggregated map items.
 */
- (void) removeMapItem: (IXCLMapPoint *) mapItem;

/*!
 * @abstract
 *      Obtain the hash value of self.
 *
 * @discussion
 *      The hash is computed from the hash of IXCLMapPoints represented
 *      by self. To minimize computation time, only the first 100 mapItems
 *      are considered.
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
 *      matching aggregatedMapItems properties. The order of elements in
 *      aggregatdMapItems must be the same for the objects to be equal.
 *
 * @param object
 *      The object to test for equality.
 *
 * @return YES if the objects are equal, NO otherwise.
 */
- (BOOL) isEqual: (id) object;

@end
