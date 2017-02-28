/*
 * @header IXCLLocationBaseModifyOptions.h
 * @abstract
 *      Represents common request parameters for create and update location
 *      calls.
 * @author Aleksei Zhilin
 * @updated 03-06-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLBaseOptions.h"
#import "IXCLLocation.h"
#import "IXCLTripSchedule.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class
 *      IXCLLocationBaseModifyOptions
 * @abstract
 *      Represents common request parameters for create and update location
 *      calls.
 */
@interface IXCLLocationBaseModifyOptions : IXCLBaseOptions

/*!
 * @abstract An address of the location. Must be nil to keep previous value.
 */
@property (nonatomic, strong, readwrite) NSString * address;

/*!
 * @abstract
 *      An alerts schedule for the location. 
 *      Set to nil to remove the alert for this location.
 */
@property (nonatomic, strong, readwrite) IXCLTripSchedule * schedule;

@end
