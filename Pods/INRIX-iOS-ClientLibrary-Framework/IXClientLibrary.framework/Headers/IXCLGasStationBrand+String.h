/*
 * @header IXCLGasStationBrand+String.h
 * @generated 8-25-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLGasStationBrand.h"

@interface IXCLGasStationBrand (String)

/*
 * @abstract
 *      Convert IXCLGasStationBrandType to string.
 *
 * @param brand
 *      IXCLGasStationBrandType to convert.
 *
 * @return The string version of the brand, nil if unknown.
 */
+ (NSString *) IXCLGasStationBrandToString: (IXCLGasStationBrandType) brand;

@end
