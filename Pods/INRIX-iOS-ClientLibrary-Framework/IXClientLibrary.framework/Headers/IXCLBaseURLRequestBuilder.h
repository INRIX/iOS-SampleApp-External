/*
 * @header IXCLBaseURLRequestBuilder.h
 * @abstract Base class for IXCLCSURLRequestBuilder and IXCLMoSIURLRequestBuilder
 * @author Cheng Cheng
 * @updated 10-21-2014
 * @copyright Copyright (c) 2013-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

#import "IXCLCore.h"
#import "IXCLCoreRequest.h"

/*!
 * @abstract Maximum length for url request.
 * @discussion Its value is 2000.
 */
FOUNDATION_EXPORT NSUInteger const IXCLURLRequestMaxLength;


@class IXCLCoreRequest;

@interface IXCLBaseURLRequestBuilder : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Instance of the IXCLCore class to be used by this class.
 */
@property (nonatomic, weak, readwrite) IXCLCore * inrixCore;

/*!
 * @abstract
 *      Default value to use for the extendedPhsMode property of new requests
 */
@property (nonatomic, assign, readwrite) IXCLExtendedPHSMode defaultExtendedPhsMode;

/*!
 * @abstract
 *      The name of the parameter used to pass the lanaguage identifier
 *      to the web services API calls the accept one as part of the URL.
 * @discussion
 *      Assign the appropriate parameter name in each derived class.
 *      The first preferred language from the current Locale, which
 *      is the default language identifier stored in InrixCore, is
 *      used with this parameter name.
 */
@property (nonatomic, strong, readwrite) NSString * languageParameterInURLName;


//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Builds a core request.
 *
 * @param serverURLString
 *      Server path used as the base of the URL.
 * @param actionName
 *      Action name to append to the URL.
 * @param parameters
 *      Parameters to append to the URL.
 * @param includeLanguageIdentifier
 *      Flag to indicate if InrixCore language identifier is included as a parameter.
 *
 * @return
 *      Core request (IXCLCoreRequest).
 */
- (IXCLCoreRequest *) coreRequestForServer: (NSString *) serverURLString
                                actionName: (NSString *) actionName
                                parameters: (NSDictionary *) parameters
                 includeLanguageIdentifier: (BOOL) includeLanguageIdentifier;

/*!
 * @abstract
 *      Builds a core request.
 *
 * @param serverURLString
 *      Server path used as the base of the URL.
 * @param actionName
 *      Action name to append to the URL.
 * @param parameters
 *      Parameters to append to the URL.
 *
 * @return
 *      Core request (IXCLCoreRequest).
 */
- (IXCLCoreRequest *) coreRequestForServer: (NSString *) serverURLString
                                actionName: (NSString *) actionName
                                parameters: (NSDictionary *) parameters;

/*!
 * @abstract
 *      Builds a core request.
 *
 * @param serverURLString
 *      Server path used as the base of the URL.
 * @param parameters
 *      Parameters to append to the URL.
 * @param includeLanguageIdentifier
 *      Flag to indicate if InrixCore language identifier is included as a parameter.
 *
 * @return
 *      Core request (IXCLCoreRequest).
 */
- (IXCLCoreRequest *) coreRequestForServer: (NSString *) serverURLString
                                parameters: (NSDictionary *) parameters
                 includeLanguageIdentifier: (BOOL) includeLanguageIdentifier;

/*!
 * @abstract
 *      Builds a core request.
 *
 * @param serverURLString
 *      Server path used as the base of the URL.
 * @param parameters
 *      Parameters to append to the URL.
 *
 * @return
 *      Core request (IXCLCoreRequest).
 */
- (IXCLCoreRequest *) coreRequestForServer: (NSString *) serverURLString
                                parameters: (NSDictionary *) parameters;

@end
