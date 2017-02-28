/*
 * @header IXCLParkingBlockRestriction.h
 * @abstract
 *      Model object which respresents restrictions in an on-street
 *      parking block.
 * @author Aleksei Zhilin
 * @updated 3-17-2016
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLParkingBlockSection.h"

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingBlockRestriction
 *
 * @abstract
 *      Model object which respresents restrictions in an on-street
 *      parking block.
 */
@interface IXCLParkingBlockRestriction : NSObject <NSCopying>

/*!
 * @abstract The duration units of a parking restriction.
 */
@property (nonatomic, assign, readwrite) IXCLParkingSectionDurationUnits durationUnits;

/*!
 * @abstract
 *      The duration of parking restriction specified in units from
 *      durationUnits property.
 */
@property (nonatomic, assign, readwrite) NSInteger duration;

/*!
 * @abstract The type of a parking restriction.
 */
@property (nonatomic, copy, readwrite) NSString * type;

@end
