/*
 * @header IXCLSearchController.h
 * @abstract Search controller which manages search data sources and performs searches on them.
 * @author Steven Warkentin
 * @updated 12-02-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "IXCLBaseController.h"
#import "IXCLSearchAutocompleteOptions.h"
#import "IXCLSearchOptions.h"

/*!
 * @abstract
 *      Describes the completion block signature for the search methods.
 * @param results
 *      The array with search results.
 * @param error
 *      The error describing the server response, or nil if successful.
 */
typedef void (^ IXCLSearchControllerResultBlock)(NSArray * results, NSError * error);

/*!
 * @abstract
 *      Describes the completion block signature for the nearest access point
 *      search methods.
 * @param result
 *      The coordinate of the nearest access point.
 * @param error
 *      The error describing the server response, or nil if successful.
 */
typedef void (^ IXCLAccessPointResultsBlock)(CLLocationCoordinate2D result, NSError * error);

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLSearchControllerProtocol
 * @abstract Protocol definition for the Search Controller.
 */
@protocol IXCLSearchControllerProtocol <NSObject>

/*!
 * @abstract
 *      Passes the search string and collects the search results.
 *
 * @param options
 *      The parameters for the search, including the query string
 *      and search center.
 * @param completionBlock
 *      Block to return the search results and a (possible) error.
 */
- (void) searchWithOptions: (IXCLSearchOptions *) options
           completionBlock: (IXCLSearchControllerResultBlock) completionBlock;

/*!
 * @abstract
 *      Passes the search string and collects the search autocomplete results.
 *
 * @param options
 *      The parameters for the search, including the query string
 *      and search center.
 * @param completionBlock
 *      Block to return the search autocomplete results and a (possible) error.
 */
- (void) searchAutocompleteWithOptions: (IXCLSearchAutocompleteOptions *) options
                       completionBlock: (IXCLSearchControllerResultBlock) completionBlock;

/*!
 * @abstract
 *      Passes the search string and collects the returned cities.
 *
 * @param query
 *      The query string for the city search.
 * @param completionBlock
 *      Block to return the search results and a (possible) error.
 */
- (void) requestCitySearchWithQuery: (NSString *) query
                    completionBlock: (IXCLSearchControllerResultBlock) completionBlock;

/*!
 * @abstract
 *      Returns the city details for a given place id.
 *
 * @param placeId
 *      Place Id returned in response to a city search request.
 * @param completionBlock
 *      The block which returns a city details and a (possible) error.
 */
- (void) requestCityDetailsWithPlaceId: (NSString *) placeId
                       completionBlock: (IXCLSearchControllerResultBlock) completionBlock;

/*!
 * @abstract
 *      Returns a routable access point for a given location.
 *
 * @param coordinate
 *      Coordinate to search at.
 * @param completionBlock
 *      The block which returns a routable coordinate or possible error.
 */
- (void) requestAccessPointWithCoordinate: (CLLocationCoordinate2D) coordinate
                          completionBlock: (IXCLAccessPointResultsBlock) completionBlock;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLSearchController
 * @abstract
 *      The IXCLSearchController manages all search requests for locations
 *      and points of interest on a map.
 */
@interface IXCLSearchController : IXCLBaseController <IXCLSearchControllerProtocol>
@end
