/*
 * @header NSException+IXCL.h
 * @abstract This class category represents exception thrown by IXCL.
 * @author Gaurav Agarwal
 * @updated 03-04-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

// TODO: (David 3/19/2014) Make this a category on NSException and expose only the exports, not any of the methods.


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark Global Exports

/*!
 * @abstract Exception domain for IXCL exceptions.
 */
// This should be in the Public API
FOUNDATION_EXPORT NSString * const IXCLExceptionDomain;

/*!
 * @abstract Indicates a string is empty when it should not be.
 */
FOUNDATION_EXPORT NSString * const IXCLEmptyStringException;

/*!
 * @abstract Indicates an internal inconsistency.
 */
FOUNDATION_EXPORT NSString * const IXCLInternalInconsistencyException;

/*!
 * @abstract Indicates one or more arguments are invalid.
 */
FOUNDATION_EXPORT NSString * const IXCLInvalidArgumentException;


/*!
 * @abstract Indicates the center point of a circular region is invalid.
 */
FOUNDATION_EXPORT NSString * const IXCLInvalidCenterPointException;

/*!
 * @abstract Indicates a coordinate is invalid.
 */
FOUNDATION_EXPORT NSString * const IXCLInvalidCoordinateException;

/*!
 * @abstract Indicates an invalid type for key/value pairs.
 */
FOUNDATION_EXPORT NSString * const IXCLInvalidKeyValueTypeException;

/*!
 * @abstract Indicates that a method that should be implemented
 *      is missing.
 */
FOUNDATION_EXPORT NSString * const IXCLMissingMethodImplementationException;


/*!
 * @abstract Indicates that a key is missing.
 */
FOUNDATION_EXPORT NSString * const IXCLMissingKeyException;


/*!
 * @abstract Indicates that an options parameter is nil.
 */
FOUNDATION_EXPORT NSString * const IXCLNilOptionsParameterException;


/*!
 * @abstract Indicates that a parameter is nil that should not be.
 */
FOUNDATION_EXPORT NSString * const IXCLNilParameterException;


/*!
 * @abstract Indicates that a value is out of range.
 */
FOUNDATION_EXPORT NSString * const IXCLRangeException;


/*!
 * @abstract Indicates that the API request that is used is
 *      not supported.
 */
FOUNDATION_EXPORT NSString * const IXCLUnsupportedAPIException;

/*!
 * @abstract Indicates that a required completion handler was nil
 */
FOUNDATION_EXPORT NSString * const IXCLNilCompletionHandlerException;


//-----------------------------------------------------------------------------
#pragma mark - Class Category Declaration

/*!
 * @category NSException (IXCL)
 * @abstract This class represents exception thrown by IXCL.
 */
@interface NSException (IXCL)

/*!
 * @abstract
 *      A convenience method that creates and raises an exception with the
 *      specified reason.
 *
 * @param format
 *      A human-readable message string (that is, the exception reason) with
 *      conversion specifications for the variable arguments in argList.
 */
+ (void) ixcl_raiseWithFormat: (NSString *) format, ...;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLNilOptionsArgumentException.
 *
 * @param parameterName
 *      A string value that names the parameter that is nil.
 */
+ (void) ixcl_raiseNilOptionsParameter: (NSString *) parameterName;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLInvalidArgumentException.
 *
 * @param parameterName
 *      A string value that names the parameter that is nil.
 */
+ (void) ixcl_raiseNilParameter: (NSString *) parameterName;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLInvalidRangeException.
 *
 * @param parameterName
 *      A string value that names the parameter that is out of the range.
 */
+ (void) ixcl_raiseRangeException: (NSString *) parameterName;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLNilOptionsParameterException if completion handler is nil
 *
 * @param options The options parameter.
 */
+ (void) ixcl_raiseIfNilOptionsParameter: (id) options;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLInvalidArgumentException if completion handler is nil
 *
 * @param completion
 *      The completion handler.
 */
+ (void) ixcl_raiseIfNilCompletionHandler: (id) completion;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLUnsupportedAPIException.
 *
 * @param unsupportedAPI A selector identifying the unsupported API.
 * @param supportedAPI   A selector identifying the supported API.
 */
+ (void) ixcl_raiseUnsupportedAPI: (SEL) unsupportedAPI insteadUse: (SEL) supportedAPI;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLInvalidCoordinateException.
 *
 * @param parameterName A string value that names the parameter that is nil.
 */
+ (void) ixcl_raiseInvalidCoordinate: (CLLocationCoordinate2D) coordinate parameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      A convenience method that creates and raises an
 *      IXCLMissingMethodImplementationException method is not overridden.
 *
 * @param methodName
 *      The completion handler.
 */
+ (void) ixcl_raiseMissingMethodImplementation: (NSString *) methodName;

/*!
 * @abstract
 *      Raises an exception with the specified error object.
 * @discussion
 *      Sets the message to the NSLocalizedDescriptionKey on the userInfo on
 *      the error.
 *
 * @param exceptionName
 *      Name of the exception.
 * @param error
 *      NSError with a userInfo property containing an entry for
 *      NSLocalizedDescriptionKey.
 */
+ (void) ixcl_raise: (NSString *) exceptionName withError: (NSError *) error;

@end
