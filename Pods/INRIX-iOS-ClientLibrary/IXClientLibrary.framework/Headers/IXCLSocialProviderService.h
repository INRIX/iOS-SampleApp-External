/*!
 * @header   IXCLSocialProviderService
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
#import "IXCLSocialProviderProtocol.h"
#import "IXCLSocialProviderServiceConfig.h"

/*!
 * @abstract Defines a service that manages Social Providers.
 */
@protocol IXCLSocialProviderServiceProtocol<NSObject>

/*!
 * @abstract The active Social Provider.
 */
@property (readwrite, nonatomic, strong) id <IXCLSocialProviderProtocol> activeProvider;

/*!
 * @abstract Adds a new provider to manage. Each provider must have a
 *    unique name.
 *
 * @param socialProvider The Social Provider to set active.
 *
 */
- (void) addProvider: (id <IXCLSocialProviderProtocol> ) socialProvider;


/*!
 * @abstract Removes a Social Provider from management.
 *
 * @param socialProvider The Social Provider to remove.
 */
- (void) removeProvider: (id <IXCLSocialProviderProtocol> ) socialProvider;


/*!
 * @abstract Gets the social provider with the specified name.
 *
 * @param name The name of the provider to get.
 *
 * @return The Social Provider of the given name or nil if not found.
 */
- (id <IXCLSocialProviderProtocol> ) getProvider: (NSString *) name;

@end

@interface IXCLSocialProviderService : NSObject <IXCLSocialProviderServiceProtocol>

@property (readwrite, nonatomic, strong) id <IXCLSocialProviderProtocol> activeProvider;

/*!
 * @abstract Initializes a new IXCLSocialProviderService with the given SocialProviderServiceConfig.
 */
- (instancetype) initWithSocialProviderServiceConfig: (id <IXCLSocialProviderServiceConfigProtocol> ) config;


@end
