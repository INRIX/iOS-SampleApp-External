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

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      The default value for maximum number of items a quad tree node
 *      can contain before it is split into child quad nodes.
 * @discussion
 *      Value is 50.
 */
FOUNDATION_EXPORT NSUInteger const IXCLPointQuadTreeDefaultMaximumItemsPerNode;


//-----------------------------------------------------------------------------
#pragma mark - IXCLPointQuadTreeBounds Declaration

/*
 * @abstract Represents the bounding box for point quad tree.
 */
typedef struct IXCLPointQuadTreeBounds
{
    CGPoint min;
    CGPoint max;
} IXCLPointQuadTreeBounds;

static inline IXCLPointQuadTreeBounds IXCLPointQuadTreeBoundsMake(CGFloat minX, CGFloat minY, CGFloat maxX, CGFloat maxY)
{
    IXCLPointQuadTreeBounds bounds;
    bounds.min.x = minX;
    bounds.min.y = minY;
    bounds.max.x = maxX;
    bounds.max.y = maxY;

    return bounds;
}

//-----------------------------------------------------------------------------
#pragma mark - IXCLPointQuadTreeItem Protocol Declaration

/*!
 * @protocol IXCLPointQuadTreeItem
 * @abstract Items in the IXCLPointQuadTreeNode must follow this protocol.
 */
@protocol IXCLPointQuadTreeItem <NSObject>

/*!
 * @abstract The point representing the item.
 *
 * @return The item CGPoint.
 */
- (CGPoint) point;

@end


//-----------------------------------------------------------------------------
#pragma mark - IXCLPointQuadTree Class Declaration

/*!
 * @class IXCLPointQuadTree
 * @abstract The quad tree implementation managing the points.
 */
@interface IXCLPointQuadTree : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The bounds of this quad tree.
 */
@property (nonatomic, assign, readonly) IXCLPointQuadTreeBounds bounds;

/*!
 * @abstract The number of items in this entire quad tree.
 */
@property (nonatomic, assign, readonly) NSUInteger count;

/*!
 * @abstract
 *      The maximum number of items a tree node can contain before it is split
 *      into child quad nodes.
 * @discussion
 *      Default value is IXCLPointQuadTreeDefaultMaximumItemsPerNode.
 */
@property (nonatomic, assign, readwrite) NSUInteger maximumItemsPerNode;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Create a quad tree with bounds.
 *
 * @param bounds
 *      The bounds of this quad tree. The tree will only accept items
 *      that fall within the bounds. The bounds are inclusive.
 *
 * @return Instance of the IXCLPointQuadTree class.
 */
- (instancetype) initWithBounds: (IXCLPointQuadTreeBounds) bounds;

/*!
 * @abstract Insert an item into this quad tree.
 *
 * @param item The item to insert. Must not be nil.
 *
 * @return
 *      NO if the item is not contained within the bounds of this tree.
 *      Otherwise adds the item and returns YES.
 */
- (BOOL) addItem: (id <IXCLPointQuadTreeItem> ) item;

/*!
 * @abstract Delete an item from this quad tree.
 *
 * @param item The item to delete.
 *
 * @return NO if the items was not found in the tree, YES otherwise.
 */
- (BOOL) removeItem: (id <IXCLPointQuadTreeItem> ) item;

/*!
 * @abstract Delete all items from this quad tree.
 */
- (void) clear;

/*!
 * @abstract Retrieve all items in this quad tree within a bounding box.
 *
 * @param bounds The bounds of the search box.
 *
 * @return
 *      The collection of items within bounds, returned as an NSArray
 *      of id<IXCLPointQuadTreeItem>.
 */
- (NSArray *) searchWithBounds: (IXCLPointQuadTreeBounds) bounds;

@end
