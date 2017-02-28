/*
 * @header IXCLProductsController.h
 * @abstract Controller for managing product requests.
 * @author Aleksei Zhilin
 * @updated 04-14-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import "IXCLBaseController.h"

@class IXCLCoreResponse;

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract
 *      Value identifying the type of a product that can be provided by the
 *      client library.
 *
 * @constant IXCLProductTypeTraffic
 *      Client library provides traffic information.
 *      Either traffic tiles or speed.
 * @constant IXCLProductTypeIncidents
 *      Client library provides incidents information.
 * @constant IXCLProductTypeRouting
 *      Client library provides routing information.
 * @constant IXCLProductTypeParking
 *      Client library provides information about parking lots.
 * @constant IXCLProductTypeGasStations
 *      Client library provides information about gas stations.
 * @constant IXCLProductTypeTrafficCameras
 *      Client library provides information about traffic cameras.
 * @constant IXCLProductTypeEVStations
 *      Client library provides information about EV stations.
 * @constant IXCLProductTypeWeather
 *      Client library provides weather information.
 * @constant IXCLProductTypeKeyRoutes
 *      Client library provides information about key routes.
 */
typedef NS_OPTIONS (NSUInteger, IXCLProductType)
{
    IXCLProductTypeTraffic        = (1 << 0),
    IXCLProductTypeIncidents      = (1 << 1),
    IXCLProductTypeRouting        = (1 << 2),
    IXCLProductTypeParking        = (1 << 3),
    IXCLProductTypeGasStations    = (1 << 4),
    IXCLProductTypeTrafficCameras = (1 << 5),
    IXCLProductTypeEVStations     = (1 << 6),
    IXCLProductTypeWeather        = (1 << 7),
    IXCLProductTypeKeyRoutes      = (1 << 8),
};

//-----------------------------------------------------------------------------
#pragma mark - Protocol Declaration

/*!
 * @protocol IXCLProductsControllerProtocol
 * @abstract
 *      Protocol definition for the Products Controller
 */
@protocol IXCLProductsControllerProtocol <NSObject>

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract
 *      Retrieves products available for a country from the server.
 *
 * @param countryCode Country code to request available products for.
 * @param completion  Block that returns available products, and any errors.
 */
- (void) requestProductsWithCountryCode: (NSString *) countryCode
                             completion: (void (^)(IXCLProductType products, IXCLCoreResponse * coreResponse)) completion;

@end

//-----------------------------------------------------------------------------
#pragma mark Class Declaration

/*!
 * @class IXCLProductsController
 * @abstract Controller for managing product requests.
 */
@interface IXCLProductsController : IXCLBaseController<IXCLProductsControllerProtocol>
@end
