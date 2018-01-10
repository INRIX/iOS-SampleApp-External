/*
 * @header IXCLParkingLot.h
 * @abstract Definitions describing Parkinglot.
 * @author Cheng Cheng
 * @updated 02-23-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>
#import "IXCLMapPoint.h"
#import "IXCLParkingObjectProtocol.h"

@class IXCLAddress;
@class IXCLParkingLotCurrentCapacity;
@class IXCLParkingLotOpeningHours;
@class IXCLParkingLotReview;
@class IXCLParkingAmenity;
@class IXCLParkingLotPhoto;
@class IXCLParkingLotReview;
@class IXCLParkingStructuredRate;
@class IXCLParkingCalculatedRate;

//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

typedef NS_ENUM (NSUInteger, IXCLParkingLotType)
{
    IXCLParkingLotTypeUnknown           = 0,
    IXCLParkingLotTypeSpecial           = 1,
    IXCLParkingLotTypeOpenSpace         = 2,
    IXCLParkingLotTypeMultiStory        = 3,
    IXCLParkingLotTypeUnderground       = 4,
    IXCLParkingLotTypeCovered           = 5,
    IXCLParkingLotTypeNested            = 6,
    IXCLParkingLotTypeField             = 7,
    IXCLParkingLotTypeRoadSide          = 8,
    IXCLParkingLotTypeDropOffWithValet  = 9,
    IXCLParkingLotTypeDropOffMechanical = 10,
    IXCLParkingLotTypeHighway           = 11,
    IXCLParkingLotTypeParkAndRide       = 12,
    IXCLParkingLotTypeCarpool           = 13,
    IXCLParkingLotTypeCampground        = 14,
    IXCLParkingLotTypeParkingZone       = 15,
    IXCLParkingLotTypeDowntown          = 16,
    IXCLParkingLotTypeTemporary         = 17,
    IXCLParkingLotTypeKissAndRide       = 18
};

typedef NS_OPTIONS (NSUInteger, IXCLParkingPaymentMethodType)
{
    IXCLParkingPaymentMethodTypeUnknown              = 0,
    IXCLParkingPaymentMethodTypeCash                 = (1 << 0),
    IXCLParkingPaymentMethodTypeCreditCard           = (1 << 1),
    IXCLParkingPaymentMethodTypeElectronicSettlement = (1 << 2),
    IXCLParkingPaymentMethodTypeTicket               = (1 << 3),
    IXCLParkingPaymentMethodTypeToken                = (1 << 4),
    IXCLParkingPaymentMethodTypeDirectCashTransfer   = (1 << 5),
    IXCLParkingPaymentMethodTypeRFID                 = (1 << 6),
    IXCLParkingPaymentMethodTypePrepayCard           = (1 << 7),
    IXCLParkingPaymentMethodTypeMobilePhone          = (1 << 8),
    IXCLParkingPaymentMethodTypeSmartCard            = (1 << 9),
};

//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLParkingLot
 * @abstract Model object describing an INRIX parking lot.
 */
@interface IXCLParkingLot : IXCLMapPoint <NSCopying, IXCLParkingObjectProtocol>

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract The unique identifier associated with the parkingLot.
 */
@property (nonatomic, copy, readwrite) NSString * parkingLotId;

/*!
 * @abstract The name of parking lot.
 */
@property (nonatomic, copy, readwrite) NSString * parkingLotName;

/*!
 * @abstract The compressed points to draw parking lot outline.
 */
@property (nonatomic, copy, readwrite) NSString * geometry;

/*!
 * @abstract The address of parking lot.
 */
@property (nonatomic, strong, readwrite) IXCLAddress * address;

/*!
 * @abstract The list of operators of parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray * operators;

/*!
 * @abstract The capacity of parking lot.
 */
@property (nonatomic, assign, readwrite) NSInteger capacity;

/*!
 * @abstract The list of parking lot gate.
 */
@property (nonatomic, strong, readwrite) NSArray * gates;

/*!
 * @abstract The opening hours of parking lot.
 */
@property (nonatomic, strong, readwrite) IXCLParkingLotOpeningHours * openingHours;

/*!
 * @abstract The parking lot type of parking lot.
 */
@property (nonatomic, assign, readwrite) IXCLParkingLotType parkingType;

/*!
 * @abstract The list of photos of parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray * photos;

/*!
 * @abstract The list of payment methods of parking lot.
 */
@property (nonatomic, assign, readwrite) IXCLParkingPaymentMethodType paymentMethods;

/*!
 * @abstract The list of pricing payments of parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray * pricingPayments;

/*!
 * @abstract The object to describe current capacity of parking lot.
 */
@property (nonatomic, strong, readwrite) IXCLParkingLotCurrentCapacity * currentCapacity;

/*!
 * @abstract Array of reviews for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLParkingLotReview *> * reviews;

/*!
 * @abstract Average review score for the parking lot.
 */
@property (nonatomic, assign, readwrite) int reviewScore;

/*!
 * @abstract Total number of reviews for the parking lot.
 */
@property (nonatomic, assign, readwrite) int reviewCount;

/*!
 * @abstract Array of reservation objects for the lot.
 */
@property (nonatomic, strong, readwrite) NSArray * reservations;

/*!
 * @abstract The address of the lot for navigation purposes.
 */
@property (nonatomic, strong, readwrite) IXCLAddress * navigationAddress;

/*!
 * @abstract The street address for the lot.
 */
@property (nonatomic, strong, readwrite) IXCLAddress * buildingAddress;

/*!
 * @abstract A number corresponding to the relative cost of the lot.
 */
@property (nonatomic, assign, readwrite) int costIndex;

/*!
 * @abstract The currency symbol for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSString * currency;

/*!
 * @abstract The ISO currency for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSString * currencyISO;

/*!
 * @abstract Notes for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSString * note;

/*!
 * @abstract An array of strings describing the hours of operation for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <NSString *> * hours;

/*!
 * @abstract A string describing the type of parking lot.
 */
@property (nonatomic, strong, readwrite) NSString * type;

/*!
 * @abstract A string describing the format of the parking lot.
 */
@property (nonatomic, strong, readwrite) NSString * format;

/*!
 * @abstract An array of rates for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLParkingStructuredRate *> * structuredRates;

/*!
 * @abstract An array of current calculated rates for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLParkingCalculatedRate *> * calculatedRates;

/*!
 * @abstract An array of strings describing the rates for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <NSString *> * rateCard;

/*!
 * @abstract An array of strings for the phone numbers of the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <NSString *> * phones;

/*!
 * @abstract An array of strings for the types of payment for the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <NSString *> * paymentTypes;

/*!
 * @abstract An url for more information about the lot.
 */
@property (nonatomic, strong, readwrite) NSURL * url;

/*!
 * @abstract An bool describing if the lot is currently open.
 */
@property (nonatomic, assign, readwrite) BOOL isOpen;

/*!
 * @abstract An array describing the amenities at the parking lot.
 */
@property (nonatomic, strong, readwrite) NSArray <IXCLParkingAmenity *> * amenities;

/*!
 * TODO-DOCUMENT-METHOD
 * @param typeString
 *      The string representation of the parking lot type.
 * @return TODO-DOCUMENT-RETURN
 */
+ (IXCLParkingLotType) parkingLotTypeFromString: (NSString *) typeString;

/*!
 * TODO-DOCUMENT-METHOD
 * @param stringArray
 *      An array of strings representing payment methods.
 * @return TODO-DOCUMENT-RETURN
 */
+ (IXCLParkingPaymentMethodType) parkingLotPaymentMethodTypesFromStringArray: (NSArray *) stringArray;

/*!
 * TODO-DOCUMENT-METHOD
 * @param string A string representing one payment method.
 * @return TODO-DOCUMENT-RETURN
 */
+ (IXCLParkingPaymentMethodType) paymentMethodTypeFromString: (NSString *) string;

@end
