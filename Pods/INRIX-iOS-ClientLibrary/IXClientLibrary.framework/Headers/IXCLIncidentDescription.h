/*
 * @header IXCLIncidentDescription.h
 * @abstract Model object providing incident description.
 * @author Gaurav Agarwal
 * @updated 03-10-2014
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
#pragma mark Class Declaration

/*!
 * @class IXCLIncidentDescription
 * @abstract Model object providing incident description.
 */
@interface IXCLIncidentDescription : NSObject <NSCoding, NSCopying>

/*!
 * @abstract Language of the description.
 */
@property (nonatomic, copy, readwrite) NSString * language;

/*!
 * @abstract Text of the description.
 */
@property (nonatomic, copy, readwrite) NSString * text;

@end
