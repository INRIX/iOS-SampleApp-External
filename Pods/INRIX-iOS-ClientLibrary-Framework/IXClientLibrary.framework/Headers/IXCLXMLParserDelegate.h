/*
 * @header IXCLXMLParserDelegate.h
 * @abstract Delegate for parsing XML responses from INRIX web services.
 * @discussion Based on http://troybrant.net/blog/2010/09/simple-xml-to-nsdictionary-converter/
 * @author Dmitri Fuerle
 * @updated 08-23-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

/// @cond

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLXMLParserDelegate
 * @abstract Delegate for parsing XML responses from INRIX web services.
 */
@interface IXCLXMLParserDelegate : NSObject <NSXMLParserDelegate>

@property (nonatomic, strong, readonly) NSDictionary * resultsDictionary;

@property (nonatomic, strong, readonly) NSError * error;

@end
