/*
 * @header IXCLBaseOptions.h
 * @abstract Represents base request parameters for server calls.
 * @author Gaurav Agarwal
 * @updated 04-18-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

@class IXCLCoreResponse;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLBaseOptions
 * @abstract Represents base request parameters for server calls.
 */
@interface IXCLBaseOptions : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract
 *      A Boolean value indicating if should controllers use cached data if
 *      available.
 * @discussion
 *      While requesting data from controllers, if cached data is not available
 *      or is expired, it makes a server request and cache response for future
 *      use. Default value is YES.
 */
@property (nonatomic, assign, readwrite) BOOL useCache;

/*!
 * @abstract
 *      Block called for intermediate updates of the request, such as when the
 *      request is being made to the server.
 */
@property (nonatomic, strong, readwrite) void (^ requestUpdateBlock)(IXCLCoreResponse * coreResponse);

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Determines whether the combination of properties are valid.
 *
 * @return NSError object if invalid; otherwise nil.
 */
- (NSError *) errorIfInvalid;

/*!
 * @abstract
 *      Returns the coordinate this options object uses for its region.
 * @discussion
 *      The base version of the class returns the device's current location, 
 *      or an invalid coordinate if error.
 *
 * @return The region coordinate.
 */
- (CLLocationCoordinate2D) regionCoordinate;

@end
