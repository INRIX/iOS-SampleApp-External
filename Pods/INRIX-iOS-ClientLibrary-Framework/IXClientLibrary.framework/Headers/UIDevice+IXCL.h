/*
 * @header UIDevice+IXCL.h
 * @abstract Category on the UIDevice class providing functionality useful to the IXCL.
 * @author David Potter
 * @updated 05-16-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <UIKit/UIKit.h>


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @category
 *      UIDevice (IXCL)
 * @abstract
 *      Category on the UIDevice class providing functionality useful to the
 *      IXCL.
 */
@interface UIDevice (IXCL)

/*!
 * @abstract Returns the identifier of the device, e.g. iPhone5,1.
 */
@property (nonatomic, readonly) NSString * ixcl_machine;

@end
