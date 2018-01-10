/*
 * @header CLLocation+IXCL.h
 * @abstract Category on the CLLocation class to add IXCL functionality.
 * @author Maxim Ivanov
 * @updated 07-26-2012
 * @copyright Copyright (c) 2012-2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <CoreLocation/CoreLocation.h>


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract The number of meters per mile.
 */
FOUNDATION_EXPORT double const IXCLMetersPerMile;

/*!
 * @abstract Separator used to build coordinate strings passed to IXCL APIs.
 */
FOUNDATION_EXPORT NSString * const IXCLCoordinateStringSeparator;

CLLocationCoordinate2D CLLocationCoordinate2DFromGeoJsonArray(NSArray * array);


//-----------------------------------------------------------------------------
#pragma mark - Class Cateogry Declaration

/*!
 * @category CLLocation (IXCL)
 * @abstract Adds methods useful for working with locations and traffic.
 */
@interface CLLocation (IXCL)

/*!
 * @abstract Constructs a CLLocation from given coordinate.
 *
 * @param coordinate A coordinate from which CLLocation object is initialized.
 *
 * @return CLLocation.
 */
+ (CLLocation *) ixcl_locationFromCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Constructs a short point-heading-speed string optionally with commas.
 *
 * @param isWithCommas
 *      YES to use a comma as the delimiter; NO to use vertical bar (|) as the
 *      delimiter.
 *
 * @return
 *      PHS string.
 */
- (NSString *) ixcl_phsShortWithCommas: (BOOL) isWithCommas;

/*!
 * @abstract Returns the distance in meters between the location and a point.
 *
 * @param coordinate A coordinate from which distance to be calculated.
 *
 * @return Distance in meters.
 */
- (CLLocationDistance) ixcl_distanceInMetersFromCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract Returns the distance in miles between the location and a point.
 *
 * @param coordinate A coordinate from which distance to be calculated.
 *
 * @return Distance in miles.
 */
- (CLLocationDistance) ixcl_distanceInMilesFromCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract Returns the distance in meters between two coordinates.
 *
 * @param coordinate1 A coordinate from which distance to be calculated.
 * @param coordinate2 A coordinate to which distance to be calculated.
 *
 * @return Distance in meters.
 */
+ (CLLocationDistance) ixcl_distanceInMetersBetweenCoordinate: (CLLocationCoordinate2D) coordinate1
                                                andCoordinate: (CLLocationCoordinate2D) coordinate2;

/*!
 * @abstract Returns the distance in miles between two coordinates.
 *
 * @param coordinate1 A coordinate from which distance to be calculated.
 * @param coordinate2 A coordinate to which distance to be calculated.
 *
 * @return Distance in miles.
 */
+ (CLLocationDistance) ixcl_distanceInMilesBetweenCoordinate: (CLLocationCoordinate2D) coordinate1
                                               andCoordinate: (CLLocationCoordinate2D) coordinate2;

/*!
 * @abstract
 *      Returns whether the values on the CLLocation represent a NULL
 *      coordinate.
 *
 * @return
 *      YES if the coordinate of the location is null (0 latitude and
 *      longitude); otherwise NO.
 */
- (BOOL) ixcl_isNullCoordinate;

/*!
 * @abstract
 *      Returns whether the values represent a NULL coordinate.
 *
 * @param coordinate
 *      Coordinate to check.
 *
 * @return
 *      YES if the coordinate is null (0 latitude and longitude); otherwise NO.
 */
+ (BOOL) ixcl_isNullCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Returns whether the values represent a valid coordinate.
 * @discussion
 *      A coordinate is valid if it passes CLLocationCoordinate2DIsValid()
 *      and ixcl_isNullCoordinate: test.
 *
 * @param coordinate
 *      Coordinate to validate.
 *
 * @return
 *      YES if the coordinate is valid and not null; otherwise NO.
 */
+ (BOOL) ixcl_isValidCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Returns whether the location contains a valid coordinate.
 * @discussion
 *      A coordinate is valid if it passes CLLocationCoordinate2DIsValid()
 *      and ixcl_isNullCoordinate: test.
 *
 * @return
 *      YES if the coordinate is valid and not null; otherwise NO.
 */
- (BOOL) ixcl_isValidLocation;

/*!
 * @abstract
 *      Returns whether two locations are identical
 */
- (BOOL) ixcl_isEqual: (id) object;

/*!
 * @abstract
 *      Returns a coordinate string that can be passed to IXCL APIs using the
 *      standard separator.
 *
 * @param coordinate
 *      Coordinate from which to construct a string.
 *
 * @return
 *      String with the latitude and longitude delimited by the separator
 *      specified in IXCLCoordinateStringSeparator.
 */
+ (NSString *) ixcl_coordinateStringFromCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract
 *      Returns a coordinate string that can be passed to IXCL APIs using the
 *      specified separator.
 *
 * @param coordinate
 *      Coordinate from which to construct a string.
 *
 * @return
 *      String with the latitude and longitude delimited by the specified
 *      separator.
 */
+ (NSString *) ixcl_coordinateStringFromCoordinate: (CLLocationCoordinate2D) coordinate
                                         separator: (NSString *) separator;

/*!
 * @abstract
 *      Returns whether two coordinates are identical.
 *
 * @param coordinate1
 *      First coordinate.
 *
 * @param coordinate2
 *      Second coordinate.
 *
 * @return
 *      A Boolean represents for whether two coordinates are identical.
 */
+ (BOOL) ixcl_isEqualCoordinate: (CLLocationCoordinate2D) coordinate1
                     coordinate: (CLLocationCoordinate2D) coordinate2;

/*!
 * @abstract
 *      Returns an NSError if the string contains an invalid latitude and
 *      longitude using the standard separator.
 *
 * @param coordinateString
 *      Latitude and longitude as string separated by separator specified in
 *      IXCLCoordinateStringSeparator.
 *
 * @return
 *      NSError if the string represents an invalid coordinate; otherwise nil.
 */
+ (NSError *) ixcl_errorIfInvalidLatitudeLongitudeString: (NSString *) coordinateString;

/*!
 * @abstract
 *      Returns an NSError if the string contains an invalid latitude and
 *      longitude using the specified separator.
 *
 * @param coordinateString
 *      Latitude and longitude as string separated by separator.
 * @param separator
 *      String separating latitude and longitude in coordinateString.
 *
 * @return
 *      NSError if the string represents an invalid coordinate; otherwise nil.
 */
+ (NSError *) ixcl_errorIfInvalidLatitudeLongitudeString: (NSString *) coordinateString
                                               separator: (NSString *) separator;

/*!
 * @abstract Returns an NSError if the coordinate is invalid.
 *
 * @param coordinate Coordinate to validate.
 *
 * @return NSError if the coordinate is invalid; otherwise nil.
 */
+ (NSError *) ixcl_errorIfInvalidCoordinate: (CLLocationCoordinate2D) coordinate;

/*!
 * @abstract Returns an NSError if the coordinate is invalid.
 *
 * @param coordinate    Coordinate to validate.
 * @param parameterName Name of parameter containing the coordinate.
 *
 * @return NSError if the coordinate is invalid; otherwise nil.
 */
+ (NSError *) ixcl_errorIfInvalidCoordinate: (CLLocationCoordinate2D) coordinate
                              parameterName: (NSString *) parameterName;

/*!
 * @abstract
 *      Returns a coordinate from latitude and longitude string using the
 *      standard separator.
 *
 * @param coordinateString
 *      Latitude and longitude as string separated by separator.
 *
 * @return
 *      The coordinate as CLLocationCoordinate2D.
 */
+ (CLLocationCoordinate2D) ixcl_coordinateFromLatitudeLongitudeString: (NSString *) coordinateString;

/*!
 * @abstract
 *      Returns a coordinate from latitude and longitude string using the
 *      specified separator.
 *
 * @param coordinateString
 *      Latitude and longitude as string separated by separator specified in
 *      IXCLCoordinateStringSeparator.
 *
 * @return
 *      The coordinate as CLLocationCoordinate2D.
 */
+ (CLLocationCoordinate2D) ixcl_coordinateFromLatitudeLongitudeString: (NSString *) coordinateString
                                                            separator: (NSString *) separator;

/*!
 * @abstract Returns speed in miles per hour.
 *
 * @param speed Speed in meters per second.
 *
 * @return The speed in miles per hour as a double.
 */
+ (double) ixcl_speedInMilesPerHour: (CLLocationSpeed) speed;

/*!
 * @abstract
 *      Returns the course from one coordinate to another coordinate.
 * @discussion
 *      Course is expressed in degrees clockwise from North within the
 *      range [-180,180).
 *
 * @param fromCoordinate
 *      Start coordinate to calculate course.
 * @param toCoordinate
 *      End coordinate to calculate course.
 *
 * @return
 *      The course in degrees clockwise from north.
 */
+ (CLLocationDirection) ixcl_courseFromCoordinate: (CLLocationCoordinate2D) fromCoordinate
                                     toCoordinate: (CLLocationCoordinate2D) toCoordinate;

/*!
 * @abstract
 *      Returns the coordinate resulting from moving a distance from an origin
 *      in the specified course (expressed in degrees clockwise from north).
 *
 * @param fromCoordinate
 *      The coordinate from which to start.
 * @param distance
 *      The distance to travel in meters.
 * @param course
 *      The course in degrees clockwise from north.
 *
 * @return
 *      The computed coordinate.
 */
+ (CLLocationCoordinate2D) ixcl_offsetCoordinateFromCoordinate: (CLLocationCoordinate2D) fromCoordinate
                                                      distance: (CLLocationDistance) distance
                                                        course: (CLLocationDirection) course;

/*!
 * @abstract
 *      Returns the coordinate which lies the given fraction of the way between the
 *      origin coordinate and the destination coordinate.
 *
 * @param coordinate1
 *      The CLLocationCoordinate2D from which to start.
 * @param coordinate2
 *      The CLLocationCoordinate2D toward which to travel.
 * @param fraction
 *      A fraction of the distance to travel.
 *
 * @return
 *      The interpolated coordinate.
 */
+ (CLLocationCoordinate2D) ixcl_interpolatedCoordinateBetweenCoordinate: (CLLocationCoordinate2D) coordinate1
                                                          andCoordinate: (CLLocationCoordinate2D) coordinate2
                                                             atFraction: (double) fraction;

/*!
 * @abstract
 *      Returns the decoded locations from encoded polyline.
 *
 * @param encodedPolyline
 *      Encoded polyline to decode.
 * @param error
 *      Value is set if there is an error decoding polyline.
 *
 * @return
 *      The decoded locations from encoded polyline.
 */
+ (NSArray *) ixcl_locationsFromPolyline: (NSString *) encodedPolyline
                                   error: (NSError **) error;

/*!
 * @abstract
 *      Returns the encoded polyline from locations.
 *
 * @param locations
 *      Locations to encode.
 * @param error
 *      Value is set if there is an error encoding polyline.
 *
 * @return
 *      The encoded polyline from locations.
 */
+ (NSString *) ixcl_polylineFromLocations: (NSArray *) locations
                                    error: (NSError **) error;

/*!
 * @abstract
 *      Returns the decoded locations with timestamp from encoded polyline.
 *
 * @param encodedPolyline
 *      Encoded polyline to decode.
 * @param error
 *      Value is set if there is an error decoding polyline.
 *
 * @return
 *      The decoded locations with timestamp represented by an array of
 *      CLLocation objects.
 */
+ (NSArray *) ixcl_locationsWithTimestampFromPolyline: (NSString *) encodedPolyline
                                                error: (NSError **) error;

/*!
 * @abstract
 *      Returns the encoded polyline from locations with timestamp.
 *
 * @param locations
 *      Locations with timestamp to encode represented by an array of
 *      CLLocation objects.
 * @param error
 *      Value is set if there is an error encoding polyline.
 *
 * @return
 *      The encoded polyline.
 */
+ (NSString *) ixcl_polylineFromLocationsWithTimestamp: (NSArray *) locations
                                                 error: (NSError **) error;
/*!
 * @abstract
 *      Returns the quadkey for a coordinate.
 *
 * @param coordinate
 *      Coordinate to encode.
 * @param zoomLevel
 *      Zoom level to encode at.
 *
 * @return
 *      The encoded quadkey.
 */
+ (NSString *) ixcl_quadkeyForCoordinate: (CLLocationCoordinate2D) coordinate
                               zoomLevel: (uint) zoomLevel;

@end
