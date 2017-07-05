/*
 * @header IXCLXDIncidentMessage.h
 * @abstract Definitions describing XD incident message.
 * @author Aleksei Zhilin
 * @updated 05-24-2016
 * @copyright Copyright (c) 2012-2016 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;

typedef NS_ENUM (NSInteger, IXCLXDIncidentInrixCode)
{
    IXCLXDIncidentInrixCodeInvalid = -1,

    IXCLXDIncidentInrixCodeAccidentSingleAccident                         = 2,
    IXCLXDIncidentInrixCodeAccidentSeriousAccident                        = 3,
    IXCLXDIncidentInrixCodeAccidentEarlierAccident                        = 152,
    IXCLXDIncidentInrixCodeAccidentMultiVehicleAccident                   = 153,
    IXCLXDIncidentInrixCodeAccidentSeriousMultiVehicleAccident            = 154,
    IXCLXDIncidentInrixCodeAccidentJackknifedTrailer                      = 208,
    IXCLXDIncidentInrixCodeAccidentJackknifedCaravan                      = 209,
    IXCLXDIncidentInrixCodeAccidentJackknifedLorry                        = 210,
    IXCLXDIncidentInrixCodeAccidentOverturnedCaravan                      = 211,
    IXCLXDIncidentInrixCodeAccidentOverturnedCar                          = 212,
    IXCLXDIncidentInrixCodeAccidentOverturnedLorry                        = 213,
    IXCLXDIncidentInrixCodeAccidentPeopleSlowingToLookAtAccident          = 295,
    IXCLXDIncidentInrixCodeAccidentAccident                               = 418,
    IXCLXDIncidentInrixCodeAccidentOverturnedVehicle                      = 615,
    IXCLXDIncidentInrixCodeAccidentAccidentNowOnHardShoulder              = 670,
    IXCLXDIncidentInrixCodeAccidentEarlierOverturnedVehicle               = 674,
    IXCLXDIncidentInrixCodeAccidentEarlierAccidentOnExitSlipRoad          = 708,
    IXCLXDIncidentInrixCodeAccidentEarlierAccidentOnEntrySlipRoad         = 709,
    IXCLXDIncidentInrixCodeAccidentAccidentInvestigationWork              = 722,
    IXCLXDIncidentInrixCodeAccidentAccidentInvolving                      = 771,
    IXCLXDIncidentInrixCodeAccidentSeriousAccidentInvolving               = 772,
    IXCLXDIncidentInrixCodeAccidentEarlierAccidentInvolving               = 777,
    IXCLXDIncidentInrixCodeAccidentJackknifedVehicle                      = 780,
    IXCLXDIncidentInrixCodeAccidentAccidentInRoadworksArea                = 1010,
    IXCLXDIncidentInrixCodeAccidentAccidentInOppositeDirection            = 1011,
    IXCLXDIncidentInrixCodeAccidentSecondaryAccident                      = 1166,
    IXCLXDIncidentInrixCodeAccidentTrafficBeingDirectedAroundAccident     = 1225,
    IXCLXDIncidentInrixCodeAccidentTrafficBeingDirectedAroundAccidentArea = 1494,

    IXCLXDIncidentInrixCodeRoadClosureRoadClosed                         = 8,
    IXCLXDIncidentInrixCodeRoadClosureBridgeClosed                       = 223,
    IXCLXDIncidentInrixCodeRoadClosureTunnelClosed                       = 224,
    IXCLXDIncidentInrixCodeRoadClosureEntrySlipRoadClosed                = 262,
    IXCLXDIncidentInrixCodeRoadClosureExitSlipRoadClosed                 = 263,
    IXCLXDIncidentInrixCodeRoadClosureSlipRoadOntoMotorwayClosed         = 592,
    IXCLXDIncidentInrixCodeRoadClosureSlipRoadClosed                     = 632,
    IXCLXDIncidentInrixCodeRoadClosureMainCarriagewayClosed              = 669,
    IXCLXDIncidentInrixCodeRoadClosureUnderpassClosed                    = 677,
    IXCLXDIncidentInrixCodeRoadClosureFlyoverClosed                      = 678,
    IXCLXDIncidentInrixCodeRoadClosureHardShoulderClosedOnEntrySlipRoad  = 704,
    IXCLXDIncidentInrixCodeRoadClosureHardShoulderClosedOnExitSlipRoad   = 705,
    IXCLXDIncidentInrixCodeRoadClosureNamedRoadClosed                    = 845,
    IXCLXDIncidentInrixCodeRoadClosureRoadPermanentlyClosed              = 848,
    IXCLXDIncidentInrixCodeRoadClosureEntryRampPermanentlyClosed         = 849,
    IXCLXDIncidentInrixCodeRoadClosureExitRampPermanentlyClosed          = 850,
    IXCLXDIncidentInrixCodeRoadClosureConnectingCarriagewayClosed        = 1035,
    IXCLXDIncidentInrixCodeRoadClosureLocalLaneClosed                    = 1097,
    IXCLXDIncidentInrixCodeRoadClosureParallelCarriagewayClosed          = 1129,
    IXCLXDIncidentInrixCodeRoadClosureRoadClosedIntermittently           = 1158,
    IXCLXDIncidentInrixCodeRoadClosureThroughTrafficLaneClosed           = 1200,
    IXCLXDIncidentInrixCodeRoadClosureTurningLaneClosed                  = 1209,
    
    IXCLXDIncidentInrixCodeLaneClosureHardShoulderClosed                 = 9,
    IXCLXDIncidentInrixCodeRoadClosureLaneClosed                         = 10,
    IXCLXDIncidentInrixCodeRoadClosureOvertakingLaneClosed               = 265,
    IXCLXDIncidentInrixCodeRoadClosureLaneClosedOnExitSlipRoad           = 620,
    IXCLXDIncidentInrixCodeRoadClosureLaneClosedOnEntrySlipRoad          = 621,
    IXCLXDIncidentInrixCodeRoadClosureLeftHandShoulderClosed             = 829,
    IXCLXDIncidentInrixCodeRoadClosureNamedLaneClosed                    = 830,
    IXCLXDIncidentInrixCodeRoadClosureRightHandShoulderClosed            = 832,
    IXCLXDIncidentInrixCodeRoadClosureCrawlerLaneClosed                  = 1041,
    IXCLXDIncidentInrixCodeLaneClosureExpressLanesClosed                 = 1062,
    IXCLXDIncidentInrixCodeLaneClosureHeavyVehicleLaneClosed             = 1083,
    IXCLXDIncidentInrixCodeLaneClosureLeftHandParallelCarriagewayClosed  = 1093,
    IXCLXDIncidentInrixCodeRoadClosurePersonCarpoolLaneClosed            = 1135,
    IXCLXDIncidentInrixCodeRoadClosureRightHandParallelCarriagewayClosed = 1157,
    IXCLXDIncidentInrixCodeRoadClosureSlowVehicleLaneClosed              = 1184,
    IXCLXDIncidentInrixCodeRoadClosureConnectingLaneClosed               = 1532,
};

/*!
 * @abstract Describes a message for XD incidents.
 */
@interface IXCLXDIncidentMessage : NSObject <NSCoding, NSCopying>

/*!
 * @abstract The XD incident Inrix code.
 */
@property (nonatomic, assign, readwrite) IXCLXDIncidentInrixCode inrixCode;

/*!
 * @abstract The XD incident type.
 */
@property (nonatomic, copy, readwrite) NSString * type;

/*!
 * @abstract The XD incident quantifier type.
 */
@property (nonatomic, copy, readwrite) NSString * quantifierType;

/*!
 * @abstract The XD incident quantifier data.
 */
@property (nonatomic, copy, readwrite) NSString * quantifierData;

@end
