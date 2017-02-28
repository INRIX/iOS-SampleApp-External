/*
 * @header IXCLContact.h
 * @abstract Represents an contact.
 * @author Steven Warkentin
 * @updated 07-14-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import UIKit;

@interface IXCLContact : NSObject <NSCopying, NSCoding>

//-----------------------------------------------------------------------------
#pragma mark - Properties

// The phone number for the contact.
@property (nonatomic, strong, readwrite) NSString * phoneNumber;

// The complete name for the contact.
@property (nonatomic, strong, readwrite) NSString * fullName;

- (id) initWithPhoneNumber: (NSString *)phoneNumber fullName: (NSString *) fullName;

@end