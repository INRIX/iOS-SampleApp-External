/*
 * @header NSError+IXCL.h
 * @abstract
 *      Category on the NSError class to provide methods useful for working
 *      with the IXCL.
 * @author David Potter
 * @updated 03-14-2014
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
#import "IXCLErrors.h"


//-----------------------------------------------------------------------------
#pragma mark Class Category Declaration

/*!
 * @category
 *      NSError (IXCL)
 * @abstract
 *      Category on the NSError class to provide methods useful for working
 *      with the IXCL.
 */
@interface NSError (IXCL)

//-----------------------------------------------------------------------------
#pragma mark - INRIX Server Error Helpers

/*!
 * @abstract
 *      Returns an NSError with the INRIX Server error domain.
 *
 * @param code
 *      The error code for the error.
 *
 * @return
 *      NSError with the INRIX Server error domain and the specified code and
 *      user info.
 */
+ (NSError *) ixcl_serverErrorWithCode: (NSInteger) code userInfo: (NSDictionary *) userInfo;

/*!
 * @abstract
 *      Returns an INRIX NSError with the code set to
 *      IXCLClientErrorInvalidResponse.
 *
 * @return
 *      NSError with the INRIX Server error domain and with the code set to
 *      IXCLClientErrorInvalidResponse.
 */
+ (NSError *) ixcl_invalidResponseServerError;

//-----------------------------------------------------------------------------
#pragma mark - INRIX Client Error Helpers

/*!
 * @abstract
 *      Returns an NSError with the INRIX Client error domain.
 *
 * @param code
 *      The error code for the error.
 * @param userInfo
 *      Error information passed as dictionry.
 *
 * @return
 *      NSError with the INRIX Client error domain and the specified code and
 *      user info.
 */
+ (NSError *) ixcl_clientErrorWithCode: (IXCLClientErrorCode) code
                              userInfo: (NSDictionary *) userInfo;

/*!
 * @abstract
 *      Returns an NSError with the INRIX Client error domain.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param code
 *      The error code for the error.
 * @param value
 *      The value causing the error; used as a parameter to format the message.
 *
 * @return
 *      NSError with the INRIX Client error domain and the specified code and
 *      user info.
 */
+ (NSError *) ixcl_clientErrorWithCode: (IXCLClientErrorCode) code
                                 value: (id) value;

/*!
 * @abstract
 *      Returns an NSError with the INRIX Client error domain.
 *
 * @param code
 *      The error code for the error.
 * @param message
 *      The error message.
 *
 * @return
 *      NSError with the INRIX Client error domain and the specified code and
 *      user info.
 */
+ (NSError *) ixcl_clientErrorWithCode: (IXCLClientErrorCode) code
                               message: (NSString *) message;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorInvalidCoordinate.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param coordinate
 *      Coordinate that is invalid.
 * @param parameterName
 *      Name of the parameter in which the coordinate was specified.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorInvalidCoordinate.
 */
+ (NSError *) ixcl_invalidCoordinateClientErrorWithCoordinate: (CLLocationCoordinate2D) coordinate
                                                parameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorOptionsRequired.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameterName
 *      Name of the parameter in which the coordinate was specified.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorOptionsRequired.
 */
+ (NSError *) ixcl_nilOptionsParameterClientErrorWithParameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorNilParameter.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameterName Name of the parameter.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorNilParameter.
 */
+ (NSError *) ixcl_nilParameterClientErrorWithParameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorRangeException.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameterName Name of the parameter.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorRangeException.
 */
+ (NSError *) ixcl_rangeExceptionClientErrorWithParameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorEmptyParameter.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameterName Name of the parameter.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorEmptyParameter.
 */
+ (NSError *) ixcl_emptyParameterClientErrorWithParameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorMissingMethod.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLClientErrorMissingMethod - The method name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param methodName
 *      Name of the parameter in which the coordinate was specified.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorMissingMethod.
 */
+ (NSError *) ixcl_missingMethodImplementationErrorWithMethodName: (NSString *) methodName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorInvalidKeyTypeForKey.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param keyName      Name of the key.
 * @param requiredType Required type of key value
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorInvalidKeyTypeForKey.
 */
+ (NSError *) ixcl_valueTypeForKeyClientErrorWithKeyName: (NSString *) keyName
                                            requiredType: (NSString *) requiredType;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorMissingKey.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param keyName Name of the key.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to IXCLClientErrorMissingKey.
 */
+ (NSError *) ixcl_missingKeyClientErrorForKeyName: (NSString *) keyName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorInvalidLengthForKey.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name.
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param keyName   Name of the key.
 * @param maxLength Maximum length of string for the key value.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorInvalidLengthForKey.
 */
+ (NSError *) ixcl_stringLengthOutOfRangeClientErrorForKeyName: (NSString *) keyName
                                                     maxLength: (NSUInteger) maxLength;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorInvalidParameter.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoParameterNameKey - The parameter name.
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameter Name of the parameter.
 * @param maxLength Minimum length of string for the parameter.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorInvalidParameter.
 */
+ (NSError *) ixcl_stringTooShortClientErrorForParameter: (NSString *) parameter
                                               minLength: (NSUInteger) maxLength;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorInvalidLengthForKey.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param keyName Name of the key.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorInvalidLengthForKey.
 */
+ (NSError *) ixcl_valueEmptyClientErrorForKeyName: (NSString *) keyName;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorAPINotAvailable.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param unsupportedAPI The unsupported API.
 * @param supportedAPI   The proper API to use.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorAPINotAvailable.
 */
+ (NSError *) ixcl_clientErrorForUnsupportedAPI: (SEL) unsupportedAPI insteadUse: (SEL) supportedAPI;

/*!
 * @abstract
 *      Returns an INRIX Client NSError with the code set to
 *      IXCLClientErrorCompletionHandlerRequired.
 * @discussion
 *      The following entries will be added to the userInfo dictionary:
 *      - IXCLErrorInfoKeyNameKey - The key name..
 *      - NSLocalizedDescriptionKey - Describes the error in text.
 *
 * @param parameterName The parameter that was nil.
 *
 * @return
 *      NSError with the INRIX Client error domain and with the code set to
 *      IXCLClientErrorCompletionHandlerRequired.
 */
+ (NSError *) ixcl_clientErrorForNilCompletionHandlerWithParameterName: (NSString *) parameterName;

@end
