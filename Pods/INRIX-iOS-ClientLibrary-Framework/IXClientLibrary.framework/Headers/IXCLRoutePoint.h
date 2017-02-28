/*
 * @header IXCLRoutePoint.h
 * @abstract Model object representing a point along a route.
 * @author Gaurav Agarwal
 * @updated 08-13-2014
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
#pragma mark Class Declaration

/*!
 * @class IXCLRoutePoint
 * @abstract Model object representing a point along a route.
 */
@interface IXCLRoutePoint : IXCLMapPoint <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Maneuver sequence.
 */
@property (nonatomic, assign, readwrite) NSUInteger sequence;

@end
