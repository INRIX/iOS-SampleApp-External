/*
 * @header IXCLRoutePointQuadTreeItem.h
 * @abstract Wrapper for IXCLRoutePoint to be stored in this point quad tree
 *  item.
 * @author Gaurav Agarwal
 * @updated 08-18-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLPointQuadTree.h"


@class IXCLRoutePoint;
@class IXCLSphericalMercatorProjection;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoutePointQuadTreeItem
 * @abstract Wrapper for IXCLRoutePoint to be stored in this point quad tree
 *  item.
 */
@interface IXCLRoutePointQuadTreeItem : NSObject <IXCLPointQuadTreeItem>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Route point managed by this point quad tree item.
 */
@property (nonatomic, strong, readonly) IXCLRoutePoint * routePoint;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize self with route point and map projection.
 *
 * @param routePoint
 *      IXCLRoutePoint to be stored in this point quad tree item.
 * @param projection
 *      Map projection used by this class.
 *
 * @return Instance of the IXCLRoutePointQuadTreeItem class.
 */
- (instancetype) initWithRoutePoint: (IXCLRoutePoint *) routePoint
                         projection: (IXCLSphericalMercatorProjection *) projection;

@end
