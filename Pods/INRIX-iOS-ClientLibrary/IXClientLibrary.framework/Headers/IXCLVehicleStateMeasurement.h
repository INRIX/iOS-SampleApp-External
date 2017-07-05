/*
 * @header IXCLVehicleStateMeasurement.h
 * @abstract The Vehicle State Measurement class.
 * @author Kent Lottis
 * @updated 05-27-2015
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

@import Foundation;
@import CoreLocation;

/*!
 * @abstract
 *      Represents a snapshot of vehicle state measurements at a specific
 *      time and location.
 */
@interface IXCLVehicleStateMeasurement : NSObject <NSCopying>

/*!
 * @abstract
 *      The location where the measurements were collected.
 *      If left nil, the current location is used.
 */
@property (nonatomic, strong, readwrite) CLLocation * location;

/*!
 *  @abstract
 *      The time at which the measurements were collected.
 *      If left nil, the current time is used.
 */
@property (nonatomic, strong, readwrite) NSDate * timeStamp;

/*!
 * @abstract
 *      The ambient temperature.
 *
 *      Type: integer\n
 *      Units: Degrees (Celsius)\n
 */
@property (nonatomic, strong, readwrite) NSNumber * ambientTemp;

/*!
 * @abstract
 *      The road surface temperature.
 *
 *      Type: integer\n
 *      Units: Degrees Celsius\n
 */
@property (nonatomic, strong, readwrite) NSNumber * roadTemp;

/*!
 * @abstract
 *      The intensity of current rainfall.
 *
 *      Type: integer\n
 *      Values:\n
 *      0 - None\n
 *      1 - Low\n
 *      2 - Medium\n
 *      3 - High\n
 *
 */
@property (nonatomic, strong, readwrite) NSNumber * rainIntensity;

/*!
 * @abstract
 *      The atmospheric humidity.
 *
 *      Type: integer\n
 *      Units: Percentage\n
 */
@property (nonatomic, strong, readwrite) NSNumber * humidity;

/*!
 * @abstract
 *      The light level.
 *
 *      Type: integer\n
 *      Units: Lux\n
 */
@property (nonatomic, strong, readwrite) NSNumber * lightLevel;

/*!
 * @abstract
 *      The atmospheric pressure.
 *
 *      Type: integer\n
 *      Units: mbar\n
 */
@property (nonatomic, strong, readwrite) NSNumber * pressure;

/*!
 * @abstract
 *      The ozone level.
 *
 *      Type: integer\n
 *      Units: PPM\n
 */
@property (nonatomic, strong, readwrite) NSNumber * ozoneLevel;

/*!
 * @abstract
 *      The dew point temperature.
 *
 *      Type: integer\n
 *      Units: Degrees Celsius\n
 */
@property (nonatomic, strong, readwrite) NSNumber * dewPoint;

/*!
 * @abstract
 *      The vehicle engine RPM.
 *
 *      Type: integer\n
 *      Units: RPM\n
 */
@property (nonatomic, strong, readwrite) NSNumber * rpm;

/*!
 * @abstract
 *      The percentage of full throttle being applied.
 *
 *      Type: integer\n
 *      Units: Percent\n
 */
@property (nonatomic, strong, readwrite) NSNumber * throttle;

/*!
 * @abstract
 *      The wiper status.
 *
 *      Type: integer\n
 *      Values:\n
 *      0 – Not active\n
 *      1 – Low\n
 *      2 – Medium\n
 *      3 - High\n
 */
@property (nonatomic, strong, readwrite) NSNumber * wiperStatus;

/*!
 * @abstract
 *      The brake status.
 *
 *      Type: boolean\n
 *      Values:\n
 *      0 – Not Applied\n
 *      1 - Applied\n
 */
@property (nonatomic, strong, readwrite) NSNumber * brakes;

/*!
 * @abstract
 *      The anti-lock braking system status.
 *
 *      Type: boolean\n
 *      Values:\n
 *      0 – Not Applied\n
 *      1 - Applied\n
 */
@property (nonatomic, strong, readwrite) NSNumber * abs;

/*!
 * @abstract
 *      The electronic stability control status.
 *
 *      Type: boolean\n
 *      Values:\n
 *      0 – Not Applied\n
 *      1 - Applied\n
 */
@property (nonatomic, strong, readwrite) NSNumber * esc;

/*!
 * @abstract
 *      The traction control engine event.
 *
 *      Type: boolean\n
 *      Values:\n
 *      0 – Not Applied\n
 *      1 - Applied\n
 */
@property (nonatomic, strong, readwrite) NSNumber * tcse;

/*!
 * @abstract
 *      The traction control brake event.
 *
 *      Type: boolean\n
 *      Values:\n
 *      0 – Not Applied\n
 *      1 - Applied\n
 */
@property (nonatomic, strong, readwrite) NSNumber * tcsb;

/*!
 * @abstract
 *      The maximum value for air flow rate from mass air flow sensor.
 *
 *      Type: integer\n
 *      Units: grams per second\n
 */
@property (nonatomic, strong, readwrite) NSNumber * mafs;

/*!
 * @abstract
 *      The intake manifold absolute pressure.
 *
 *      Type: integer\n
 *      Units: kPa (absolute)\n
 */
@property (nonatomic, strong, readwrite) NSNumber * imap;

/*!
 * @abstract
 *      The engine coolant temperature.
 *
 *      Type: integer\n
 *      Units: Degrees Celsius\n
 */
@property (nonatomic, strong, readwrite) NSNumber * coolantTemp;

/*!
 * @abstract
 *      The fuel level.
 *
 *      Type: integer\n
 *      Units: Percent\n
 */
@property (nonatomic, strong, readwrite) NSNumber * fuelLevel;

/*!
 * @abstract
 *      The fuel tank capacity.
 *
 *      Type: double\n
 *      Units: Gallons\n
 */
@property (nonatomic, strong, readwrite) NSNumber * fuelTankSizeInGallon;

/*!
 * @abstract
 *      The estimated mileage.
 *
 *      Type: double\n
 *      Units: Miles per Gallon\n
 *
 */
@property (nonatomic, strong, readwrite) NSNumber * averageMpg;

@end