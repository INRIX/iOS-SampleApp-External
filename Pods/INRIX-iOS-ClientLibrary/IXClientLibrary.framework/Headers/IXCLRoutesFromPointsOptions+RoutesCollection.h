/*
 * @header IXCLRoutesFromPointsOptions+RoutesCollection.h
 * @abstract Class category on IXCLRoutesFromPointsOptions.
 * @author Gaurav Agarwal
 * @updated 04-23-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLRoutesFromPointsOptions.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Category Declaration

@interface IXCLRoutesFromPointsOptions (RoutesCollection)

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Returns an unique key from the routes options.
 *
 * @return NSString
 */
- (NSString *) keyForRoutesCollection;

@end
