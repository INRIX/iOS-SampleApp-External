/*
 * @header IXCLParkingLotGate.h
 * @abstract Definitions describing parking lot gate.
 * @author Cheng Cheng
 * @updated 02-23-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "IXCLMapPoint.h"

typedef NS_ENUM (NSUInteger, IXCLParkingLotGateType)
{
    IXCLParkingLotGateTypeUnknown            = 0,
    IXCLParkingLotGateTypeVehicleEntrance    = 1,
    IXCLParkingLotGateTypeVehicleExit        = 2,
    IXCLParkingLotGateTypeRentalReturn       = 3,
    IXCLParkingLotGateTypeExitAndEntrance    = 4,
    IXCLParkingLotGateTypePedestrainEntrance = 5,
    IXCLParkingLotGateTypePedestrianExit     = 6,
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingLotGate
 * @abstract Model object describing an INRIX parking lot gate.
 */
@interface IXCLParkingLotGate : IXCLMapPoint <NSCopying>

/*!
 * @abstract The type of parking lot gate.
 */
@property (nonatomic, assign, readwrite) IXCLParkingLotGateType type;

/// @cond
+ (NSArray *) gatesFromDictionaries: (NSArray *) dictionaries;


+ (IXCLParkingLotGateType) gateTypeFromString: (NSString *) typeString;

@end
