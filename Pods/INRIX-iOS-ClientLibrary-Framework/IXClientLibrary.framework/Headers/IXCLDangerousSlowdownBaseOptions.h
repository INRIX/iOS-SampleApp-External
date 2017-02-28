/*
 * @header IXCLDangerousSlowdownBaseOptions.h
 * @abstract Base class for dangerous slowdown options.
 * @author Patrick Winchell
 * @created 11-10-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLBaseOptions.h"

/*!
 * @abstract
 *      The unit in which distances in incident should be returned in the
 *      server response.
 *
 * @constant
 *      IXCLDangerousSlowdownDistanceUnitsMiles Distances in miles.
 * @constant
 *      IXCLDangerousSlowdownDistanceUnitsKilometers Distances in meters.
 */
typedef NS_ENUM (NSUInteger, IXCLDangerousSlowdownDistanceUnitsType)
{
    IXCLDangerousSlowdownDistanceUnitsMiles  = 0,
    IXCLDangerousSlowdownDistanceUnitsKilometers = 1
};

@interface IXCLDangerousSlowdownBaseOptions : IXCLBaseOptions

/*!
 * @abstract
 *      Describes distance values in this class (e.g. radius) as well as in the
 *      response from the request.
 * @discussion
 *      Defaults to IXCLDangerousSlowdownDistanceUnitsMiles.
 */
@property (nonatomic, assign, readwrite) IXCLDangerousSlowdownDistanceUnitsType distanceUnits;

@end
