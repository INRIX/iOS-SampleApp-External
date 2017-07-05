/*
 * @header IXCLSharingAddress.h
 * @abstract
 *      Model object for an address used to share traffic information with
 *      others.
 * @author David Potter
 * @updated 03-19-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract Type of sharing address.
 *
 * @constant IXCLSharingAddressTypeText  Address for text messages.
 * @constant IXCLSharingAddressTypeEmail Email address.
 */
typedef NS_ENUM (NSInteger, IXCLSharingAddressType)
{
    IXCLSharingAddressTypeText  = 1,
    IXCLSharingAddressTypeEmail = 2
};


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLSharingAddress
 * @abstract
 *      Model object for an address used to share traffic information with
 *      others.
 */
@interface IXCLSharingAddress : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Type of sharing address (such as text or email).
 */
@property (nonatomic, assign, readwrite) IXCLSharingAddressType type;

/*!
 * @abstract Address to share with.
 */
@property (nonatomic, strong, readwrite) NSString * address;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes an instance of the IXCLSharingAddress class.
 *
 *
 * @param type    Type of sharing address (text or email).
 * @param address Address to share with.
 *
 * @return Instance of the IXCLSharingAddress class.
 */
- (id) initWithType: (IXCLSharingAddressType) type address: (NSString *) address;

@end
