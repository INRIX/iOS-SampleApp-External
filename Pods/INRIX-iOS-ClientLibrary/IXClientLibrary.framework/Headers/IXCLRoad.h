/*
 * @header IXCLRoad.h
 * @abstract Model object representing information about a road used in a route.
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
#pragma mark - Enum Definitions

/*!
 * @abstract
 *      The road class.
 *
 * @constant IXCLRoadClassLimitedAccess
 *      Limited connectivity with other roads, usually only by means of ramps.
 * @constant IXCLRoadClassArterial
 *      Connects to all surface streets and to ramps.
 * @constant IXCLRoadClassLocalStreet
 *      Connects to all surface streets and sometimes to ramps.
 * @constant IXCLRoadClassTerminal
 *      Intended to be used only as an origin or destination.
 * @constant IXCLRoadClassRotary
 *      Rotary traffic flows in a single direction around a complete circular
 *      path. Variants such as different shapes or flow are designated as
 *      “special traffic figures”.
 * @constant IXCLRoadClassRamp
 *      Connects surface streets to limited access roads or connects two
 *      limited access roads.
 */
typedef NS_ENUM (NSUInteger, IXCLRoadClass)
{
    IXCLRoadClassLimitedAccess = 1,
    IXCLRoadClassArterial      = 2,
    IXCLRoadClassLocalStreet   = 3,
    IXCLRoadClassTerminal      = 4,
    IXCLRoadClassRotary        = 8,
    IXCLRoadClassRamp          = 9,
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLRoad
 * @abstract Model object representing information about a road used in a route.
 */
@interface IXCLRoad : NSObject <NSCoding, NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The road class.
 */
@property (nonatomic, assign, readwrite) NSUInteger roadClass;

/*!
 * @abstract The name of the road.
 */
@property (nonatomic, copy, readwrite) NSString * name;

@end
