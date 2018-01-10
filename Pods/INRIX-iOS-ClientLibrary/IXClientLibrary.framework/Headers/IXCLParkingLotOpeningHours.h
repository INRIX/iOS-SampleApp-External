/*
 * @header IXCLParkingLotOpeningHours.h
 * @abstract Definitions describing openning hours for a parking lot.
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

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingLotOpeningHours
 * @abstract Model object describing an INRIX parking lot openning hours.
 */
@interface IXCLParkingLotOpeningHours : NSObject <NSCopying>

/*!
 * @abstract The parking lot opening hours description of parking lot.
 */
@property (nonatomic, copy, readwrite) NSString * notes;

@end
