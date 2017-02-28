/*
 * @header IXCLAddress.h
 * @abstract Definitions describing address.
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
 * @class IXCLAddress
 * @abstract Model object describing an INRIX address.
 */
@interface IXCLAddress : NSObject <NSCopying>

/*!
 * @abstract The street info of address.
 */
@property (nonatomic, copy, readwrite) NSString * street;

/*!
 * @abstract The city of address.
 */
@property (nonatomic, copy, readwrite) NSString * city;

/*!
 * @abstract The state of address.
 */
@property (nonatomic, copy, readwrite) NSString * state;

/*!
 * @abstract The zipcode of address.
 */
@property (nonatomic, copy, readwrite) NSString * zipCode;

/*!
 * @abstract The country of address.
 */
@property (nonatomic, copy, readwrite) NSString * country;

/*!
 * @abstract Business name for the address.
 */
@property (nonatomic, copy, readwrite) NSString * name;

/*!
 * @abstract Phone number for the address.
 */
@property (nonatomic, copy, readwrite) NSString * phoneNumber;

@end
