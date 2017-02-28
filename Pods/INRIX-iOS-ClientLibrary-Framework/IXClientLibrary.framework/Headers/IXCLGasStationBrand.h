/*
 * @header IXCLGasStationBrand.h
 * @abstract Represents brands for gas stations
 * @author Patrick Winchell
 * @updated 08-24-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLGasStationBrandType.h"

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLGasStationBrand : NSObject
/*!
 * @abstract
 *      The IXCLGasStationBrandType value.
 */
@property (nonatomic, assign, readonly) IXCLGasStationBrandType brandType;
/*!
 * @abstract
 *      The NSString name of the brand, returns nil if there is not a string name.
 */
@property (nonatomic, assign, readonly) NSString * brandName;

//-----------------------------------------------------------------------------
#pragma mark - Init Methods
/*!
 * @abstract Initializes with a brandType.
 *
 * @param brandType A valid IXCLGasStationBrandType.
 *
 * @return Instance of the IXCLGasStationBrand class.
 */
- (instancetype) initBrandType: (IXCLGasStationBrandType) brandType;

@end
