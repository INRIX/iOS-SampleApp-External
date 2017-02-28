/*
 * @header IXCLParkingLotByIdOptions.h
 * @abstract Represents request parameters for retrieving parking lots by list of Ids
 * @author Cheng Cheng
 * @updated 02-26-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLParkingLotBaseOptions.h"

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLParkingLotByIdOptions
 * @abstract
 *      Represents request parameters for retrieving parking lots by list of Ids
 */
@interface IXCLParkingLotByIdOptions : IXCLParkingLotBaseOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The list of parking lot ids to get.
 */
@property (nonatomic, copy, readwrite) NSString * parkingLotId;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initialize with a list of parking lot Ids.
 *
 * @param parkingLotId Id of parking lot to retrieve.
 *
 * @return Instance of the IXCLParkingLotByIdOptions class.
 */
- (instancetype) initWithParkingLotId: (NSString *) parkingLotId;

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

@end
