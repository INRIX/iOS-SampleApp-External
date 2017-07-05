/*
 * @header IXCLCoreResponse.h
 * @abstract Response object passed to completion handlers when making requests.
 * @author David Potter
 * @updated 04-17-2014
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
 * @abstract Response object passed to completion handlers when making requests.
 */
@interface IXCLCoreResponse : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Error if the request failed, otherwise nil.
 */
@property (nonatomic, strong, readwrite) NSError * error;

/*!
 * @abstract URL request used to make the request.
 */
@property (nonatomic, strong, readwrite) NSURLRequest * urlRequest;

/*!
 * @abstract
 *      A Boolean value indicating whether a response was retrieved from the
 *      cache or not.
 * @discussion
 *      YES if response returned in the completion block is from the local cache.
 *      NO if request failed due to error, or data is loaded from the server.
 */
@property (nonatomic, assign, readwrite) BOOL isCachedResponse;

/*!
 * @abstract
 *      A Boolean value indicating whether a response was created from auth request.
 * @discussion
 *      YES if response returned from an auth request.
 *      NO if response returned from non-auth request.
 */
@property (nonatomic, assign, readwrite) BOOL isAuthResponse;

/*!
 * @abstract
 *      A Boolean value indicating whether a request is currently being made to
 *      the server.
 */
@property (nonatomic, assign, readwrite) BOOL isServerRequestBeingMade;

/*!
 * @abstract
 *      The timestamp when the server request is being made.
 */
@property (nonatomic, strong, readwrite) NSDate * requestTimestamp;

/*!
 * @abstract
 *      The timestamp when the response from server is received.
 */
@property (nonatomic, strong, readwrite) NSDate * responseTimestamp;

/*!
 * @abstract
 *      A dictionary holds value in response header fields.
 */
@property (nonatomic, strong, readwrite) NSDictionary * headerFields;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes with an NSError.
 *
 * @param error Error to use if the request failed.
 *
 * @return Instance of the IXCLCoreResponse class.
 */
- (instancetype) initWithError: (NSError *) error;

/*!
 * @abstract Initializes with a URL string.
 *
 * @param urlRequest URL request used to make the request.
 *
 * @return Instance of the IXCLCoreResponse class.
 */
- (instancetype) initWithURLRequest: (NSURLRequest *) urlRequest;

@end
