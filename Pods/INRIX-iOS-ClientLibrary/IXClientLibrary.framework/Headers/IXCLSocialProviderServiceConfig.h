/*!
 * @header   IXCLSocialProviderServiceConfig.h
 *
 * @author   Nathan Clark
 *
 * @date  Sept 1, 2016
 *
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

//-----------------------------------------------------------------------------
#pragma mark - IXCLSocialProviderServiceConfigProtocol

@protocol IXCLSocialProviderServiceConfigProtocol<NSObject>

/*!
 * @abstract The collection of Social Providers.
 */
@property (nonatomic, strong, readwrite) NSArray * socialProviders;

@end

//-----------------------------------------------------------------------------
#pragma mark - IXCLSocialProviderServiceConfig

@interface IXCLSocialProviderServiceConfig : NSObject <IXCLSocialProviderServiceConfigProtocol>

/*!
 * @abstract The collection of Social Providers.
 */
@property (nonatomic, strong, readwrite) NSArray * socialProviders;

/*!
 * @abstract
 *      Initializes a new IXCLSocialProviderServiceConfig with the given
 *      collection of Social Providers.
 */
- (instancetype) initWithSocialProviders: (NSArray *) socialProviders;

@end
