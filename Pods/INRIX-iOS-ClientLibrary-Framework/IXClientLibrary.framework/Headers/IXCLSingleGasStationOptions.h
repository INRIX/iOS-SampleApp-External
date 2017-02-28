/*
 * @header IXCLSingleGasStationOptions.h
 * @abstract Represents request parameters for information about a single gas station.
 * @author Patrick Winchell
 * @updated 02-25-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLGasStationBaseOptions.h"

/*!
 * @class IXCLSingleGasStationOptions
 * @abstract Options for requesting detailed information about a single gas station.
 */
@interface IXCLSingleGasStationOptions : IXCLGasStationBaseOptions <NSCopying>

/*!
 * @abstract A gas station ID from which to return information.
 */
@property (nonatomic, strong, readwrite) NSString * stationId;

@end
