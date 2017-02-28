/*
 * @header IXCLPointQuadTree.h
 * @abstract The quad tree implementation managing the points.
 * @author Gaurav Agarwal
 * @updated 08-17-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>

#import "IXCLPointQuadTree.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLPointQuadTreeNode
 * @abstract Represents IXCLPointQuadTree node.
 */
@interface IXCLPointQuadTreeNode : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The bounds of this sub quad tree represented by this node.
 */
@property (nonatomic, assign, readonly) IXCLPointQuadTreeBounds bounds;

/*!
 * @abstract
 *      The maximum number of items this node can hold before being split
 *      into child nodes.
 */
@property (nonatomic, assign, readonly) NSUInteger maximumItemsCount;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Create a quad tree node with bounds.
 *
 * @param bounds
 *      The bounds of this quad tree node.
 * @param maximumItemsCount
 *      The maximum number of items this node can hold before being split
 *      into child nodes.
 *
 * @return Instance of the IXCLPointQuadTreeNode class.
 */
- (instancetype) initWithBounds: (IXCLPointQuadTreeBounds) bounds
              maximumItemsCount: (NSUInteger) maximumItemsCount;

/*!
 * @abstract Insert an item into this node.
 *
 * @param item The item to insert. Must not be nil.
 */
- (void) addItem: (id <IXCLPointQuadTreeItem> ) item;

/*!
 * @abstract Delete an item from this node.
 *
 * @param item The item to delete.
 *
 * @return NO if the items was not found in the tree, YES otherwise.
 */
- (BOOL) removeItem: (id <IXCLPointQuadTreeItem> ) item;

/*!
 * @abstract Retreive all items in this node within a bounding box.
 *
 * @param searchBounds The bounds of the search box.
 * @param accumulator The results of the search.
 */
- (void) searchWithBounds: (IXCLPointQuadTreeBounds) searchBounds
                  results: (NSMutableArray *) accumulator;

/*!
 * @abstract Split the contents of this node over four child quads.
 */
- (void) split;

@end
