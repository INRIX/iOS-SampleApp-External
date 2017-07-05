/*
 * @header IXCLRouteSummary.h
 * @abstract
 *      Model object representing information about the roads used in the route
 *      calculation.
 * @author Akvelon
 * @updated 10-20-2009
 * @copyright Copyright (c) 2009-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLRouteSummary
 * @abstract
 *      Model object representing information about the roads used in the route
 *      calculation.
 */
@interface IXCLRouteSummary : NSObject <NSCoding, NSCopying>

/*!
 * @abstract Information about the roads used in the route.
 */
@property (nonatomic, copy, readwrite) NSString * text;

/*!
 * @abstract List of roads used in the route.
 */
@property (nonatomic, strong, readwrite) NSMutableArray * roads;

/*!
 * @abstract
 *      Returns text about the roads used in the route, constructed from each
 *      IXCLRoad in the roads property.
 */
@property (nonatomic, copy, readonly) NSString * textFromRoads;

@end
