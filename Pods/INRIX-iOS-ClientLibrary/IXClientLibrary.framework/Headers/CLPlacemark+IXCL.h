/*
 * @header CLPlacemark+IXCL.h
 * @abstract Category on the CLPlacemark class to add IXCL functionality.
 * @author Dmitri Fuerle
 * @updated 08-08-2013
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <MapKit/MapKit.h>


//-----------------------------------------------------------------------------
#pragma mark Class Category Declaration

/*!
 * @category CLPlacemark (IXCL)
 * @abstract Adds methods useful for working with INRIX web services.
 */
@interface CLPlacemark (IXCL)

/*!
 * @abstract
 *      Constructs an address string using the five-comma format supported by
 *      INRIX web service APIs.
 *
 * @return
 *       Address string in five-comma format.
 */
- (NSString *) ixcl_fiveCommaAddressString;

/*!
 * @abstract Constructs a short, single-line address string.
 *
 * @return
 *       Short, single-line address string.
 */
- (NSString *) ixcl_addressString;

/*!
 * @abstract
 *      Constructs a short single-line address string from five-comma format
 *      supported by INRIX web service APIs.
 *
 * @param address
 *      Address string in five-comma format.
 *
 * @return
 *      Single-line address string.
 */
+ (NSString *) ixcl_displayableAddressFromFiveCommaAddressString: (NSString *) address;

/*!
 * @abstract
 *      Determines whether a country with provided country code is in Europe.
 *
 * @param countryCode
 *      ISO country code.
 *
 * @return
 *      YES if country with provided country code is in Europe, otherwise it
 *      returns NO.
 */
+ (BOOL) ixcl_isEuropeanCountryCode: (NSString *) countryCode;

/*!
 * @abstract
 *      Determines whether a country with provided country code is in
 *      North America.
 *
 * @param countryCode
 *      ISO country code.
 *
 * @return
 *      YES if country with provided country code is in North America,
 *      otherwise it returns NO.
 */
+ (BOOL) ixcl_isNorthAmericanCountryCode: (NSString *) countryCode;

/*!
 * @abstract
 *      Determines whether a country with provided country code is in
 *      South America.
 *
 * @param countryCode
 *      ISO country code.
 *
 * @return
 *      YES if country with provided country code is in South America,
 *      otherwise it returns NO.
 */
+ (BOOL) ixcl_isSouthAmericanCountryCode: (NSString *) countryCode;

@end
