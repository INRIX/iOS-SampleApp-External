/*
 * @header IXCLCoreRequest.h
 * @abstract Response object passed to completion handlers when making requests.
 * @author Gaurav Agarwal
 * @updated 05-02-2014
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
#pragma mark - Enum Definitions

/*!
 * @abstract The request type tells the request executor the expected server
 *  response format.
 *
 * @constant IXCLCoreRequestTypeXML Server returns an XML response.
 * @constant IXCLCoreRequestTypeJSON Server returns a JSON response.
 * @constant IXCLCoreRequestTypeImage Server returns an image response.
 * @constant IXCLCoreRequestTypeString Server returns a string response.
 */
typedef NS_ENUM (NSUInteger, IXCLCoreRequestType)
{
    IXCLCoreRequestTypeXML = 0,
    IXCLCoreRequestTypeJSON,
    IXCLCoreRequestTypeImage,
    IXCLCoreRequestTypeString
};

typedef NS_ENUM (NSUInteger, IXCLCoreRequestPriority)
{
    IXCLCoreRequestPriorityDefault = 0,
    IXCLCoreRequestPriorityHigh,
    IXCLCoreRequestPriorityLow
};

typedef NS_ENUM (NSUInteger, IXCLExtendedPHSMode)
{
    IXCLExtendedPHSDisabled = 0,
    IXCLExtendedPHSEnabled,
    IXCLExtendedPHSBreadcrumbs
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLCoreRequest : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract URL request to make the server call.
 */
@property (nonatomic, strong, readwrite) NSMutableURLRequest * urlRequest;

/*!
 * @abstract The request type specifying the expected server response format.
 */
@property (nonatomic, assign, readwrite) IXCLCoreRequestType requestType;

/*!
 * @abstract The request priority specifying the request priority queue to use.
 */
@property (nonatomic, assign, readwrite) IXCLCoreRequestPriority requestPriority;

/*!
 * @abstract Returns whether the request supports extended PHS to send along to the server.
 * @discussion The default value is YES.
 */
@property (nonatomic, assign, readwrite) IXCLExtendedPHSMode extendedPHSMode;

/*!
 * @abstract Returns whether the request should use SSL certificate pinning for
 * additional security.
 * @discussion The default value is NO.
 */
@property (nonatomic, assign, readwrite) BOOL useCertificatePinning;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with a URL string.
 *
 * @param urlRequest URL request used to make the request.
 *
 * @return Instance of the IXCLCoreRequest class.
 */
- (instancetype) initWithURLRequest: (NSMutableURLRequest *) urlRequest;

@end
