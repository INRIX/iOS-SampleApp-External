/*
 * @header IXCLParkingLotsInRadiusOptions.h
 * @abstract Represents request parameters for retrieving parking lots in a circular
 *      region.
 * @author Cheng Cheng
 * @updated 02-24-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>
#import "IXCLParkingLotBaseOptions.h"

/*!
 * @abstract Represents request parameters for retrieving parking lots in a circular
 *      region.
 */
@interface IXCLParkingLotsInRadiusOptions : IXCLParkingLotBaseOptions <NSCopying>

/*!
 * The center of the search area.
 */
@property (nonatomic, assign, readwrite) CLLocationCoordinate2D center;

/*!
 * The radius of the search area.
 */
@property (nonatomic, assign, readwrite) double radius;

/*!
 * Initializes the search options with a center and radius.
 * @param center
 *      The center of the search area.
 * @param radius
 *      The radius of the search area.
 * @return
 *      An initialized instance of the search options class.
 */
- (instancetype) initWithCenter: (CLLocationCoordinate2D) center
                         radius: (double) radius;

@end
