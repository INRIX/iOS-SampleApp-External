/*
 * @header IXCLParkingLotBaseOptions.h
 * @abstract Represents request parameters for parking lots calls.
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

#import "IXCLBaseOptions.h"

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

typedef NS_OPTIONS (NSUInteger, IXCLParkingLotOptionsOutputField)
{
    IXCLParkingLotOptionsOutputFieldBasic    = (1 << 0),
    IXCLParkingLotOptionsOutputFieldPricing  = (1 << 1),
    IXCLParkingLotOptionsOutputFieldGeometry = (1 << 2),
    IXCLParkingLotOptionsOutputFieldDynamic  = (1 << 3),
    IXCLParkingLotOptionsOutputFieldStatic   = (1 << 4),
    IXCLParkingLotOptionsOutputFieldAll      = (IXCLParkingLotOptionsOutputFieldBasic |
                                                IXCLParkingLotOptionsOutputFieldGeometry |
                                                IXCLParkingLotOptionsOutputFieldDynamic |
                                                IXCLParkingLotOptionsOutputFieldStatic),
};

typedef NS_OPTIONS (NSUInteger, IXCLParkingLotOptionsParkingType)
{
    IXCLParkingLotOptionsParkingTypeParkingLots   = (1 << 0),
    IXCLParkingLotOptionsParkingTypeParkingBlocks = (1 << 1),
    IXCLParkingLotOptionsParkingTypeAll           = (IXCLParkingLotOptionsParkingTypeParkingLots |
                                                     IXCLParkingLotOptionsParkingTypeParkingBlocks),
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class
 *      IXCLParkingLotBaseOptions
 * @abstract
 *     Represents request parameters for parking lots calls.
 */
@interface IXCLParkingLotBaseOptions : IXCLBaseOptions <NSCopying>

@property (nonatomic, strong, readwrite) NSDate * arrivalDate;
@property (nonatomic, assign, readwrite) NSInteger duration;
@property (nonatomic, assign, readwrite) IXCLParkingLotOptionsParkingType parkingType;
@property (nonatomic, assign, readwrite) IXCLParkingLotOptionsOutputField outputField;

- (NSString *) parkingTypeAsString;

- (NSString *) parkingOutputFieldAsString;

@end
