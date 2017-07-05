/*
 * @header IXCLRoutesCollection.h
 * @abstract
 *      Model object for managing the routes collection along with its state.
 * @author Gaurav Agarwal
 * @updated 04-21-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLRoutesBaseOptions.h"
#import "IXCLRoutesResponse.h"


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class
 *      IXCLRoutesCollection
 * @abstract
 *      Model object for managing the routes collection along with its state.
 */
@interface IXCLRoutesCollection : NSObject <NSCopying>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Unique ID for this routes collection.
 */
@property (nonatomic, copy, readwrite) NSString * routesCollectionId;

/*!
 * @abstract Route options used for calculating the routes.
 */
@property (nonatomic, copy, readwrite) IXCLRoutesBaseOptions * options;

/*!
 * @abstract Routes associated with this routes collection.
 */
@property (nonatomic, strong, readwrite) NSArray * routes;

/*!
 * @abstract The state of the routes collection.
 */
@property (nonatomic, assign, readwrite) IXCLRoutesState state;

@end
