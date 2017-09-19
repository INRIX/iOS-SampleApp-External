/*
 * @header IXCLGeocodeController.h
 * @abstract Controller for serializing access to Apple's geocoder.
 * @discussion This avoids failures due to overuse of the geocoder.
 * @author Dmitri Fuerle
 * @updated 09-26-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLBaseController.h"
@import CoreLocation;

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLGeocodeControllerProtocol
 * @abstract
 *      Protocol definition for the Geocode Controller
 */
@protocol IXCLGeocodeControllerProtocol<NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Requests address information for a location (reverse geocode).
 *
 * @param location
 *      The location to reverse geocode.
 * @param completionHandler
 *      The completion handler returns the placemarks for the location.
 */
- (void) reverseGeocodeLocation: (CLLocation *) location
                     completion: (CLGeocodeCompletionHandler) completionHandler;

/*!
 * @abstract
 *      Requests location information for an address string (forward geocode).
 *
 * @param addressString
 *      The address to geocode.
 * @param completionHandler
 *      The completion handler returns the placemarks for the location.
 */
- (void) geocodeAddressString: (NSString *) addressString
                   completion: (CLGeocodeCompletionHandler) completionHandler;

/*!
 * @abstract
 *      Requests location information for an address string (forward geocode).
 *
 * @param addressDictionary
 *      The address to geocode.
 * @param completionHandler
 *      The completion handler returns the placemarks for the location.
 */
- (void) geocodeAddressDictionary: (NSDictionary *) addressDictionary
                       completion: (CLGeocodeCompletionHandler) completionHandler;

/*!
 * @abstract Reverse geocode location inside a queue and caches the response.
 *
 * @param location The location to reverse geocode.
 *
 * @return Cached reverse geocode placemarks for location.
 */
- (NSArray *) cachedReverseGeocodeLocation: (CLLocation *) location;

@end

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

@interface IXCLGeocodeController : IXCLBaseController <IXCLGeocodeControllerProtocol>
@end
