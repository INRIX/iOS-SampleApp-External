/*
 * @header IXCLLocationUpdateOptions.h
 * @abstract Represents request parameters for update location calls.
 * @author Aleksei Zhilin
 * @updated 03-06-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLLocationBaseModifyOptions.h"

#import "IXCLSavedLocation.h"


//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLLocationUpdateOptions
 * @abstract Represents request parameters for update location calls.
 */
@interface IXCLLocationUpdateOptions : IXCLLocationBaseModifyOptions <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The locationData to update
 */
@property (nonatomic, strong, readwrite) IXCLSavedLocation * location;

/*!
 * @abstract The ID of the location to update.
 */
@property (nonatomic, strong, readonly) NSString * locationId;

/*!
 * @abstract An unique name of the location.
 */
@property (nonatomic, strong, readwrite) NSString * name;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Initializes the IXCLLocationUpdateOptions with the specified location
 *      ID.
 *
 * @param location
 *      The location data to update.
 *
 * @return
 *      Instance of the IXCLLocationUpdateOptions class.
 */
- (instancetype) initWithLocation: (IXCLSavedLocation *) location;

@end
