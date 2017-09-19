/*!
 * @header    IXCLSocialProviderProtocol.h
 *
 * @author    Nathan Clark
 *
 * @created   Sept 1, 2026
 *
 * @copyright Copyright (c) 2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@class IXCLOAuthInfo;


/*!
 * @abstract Defines a third party OAuth provider.
 */
@protocol IXCLSocialProviderProtocol<NSObject>

/*!
 * @abstract The name of the Social Provider.
 */
@property (readonly, nonatomic, copy) NSString * name;

/*!
 * @abstract Indicates whether the user is currently logged into the Social Provider.
 */
@property (readonly, nonatomic, assign) BOOL isSignedIn;

/*!
 * @abstract Gets the OAuthInfo about the current user from the Social Provider.
 * @param completion
 *          The completion handler for the IXCLOAuthInfo.
 */
- (void) getOAuthInfo: (void (^)(IXCLOAuthInfo * oAuthInfo, NSError * error)) completion;

/*!
 * @abstract Signs the current user out of the Social Provider.
 */
- (void) signOut;

@end
