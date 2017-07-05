/*
 * @header IXCLTrafficQuality.h
 * @abstract Model object for traffic quality.
 * @author David Potter
 * @updated 03-05-2014
 * @copyright Copyright (c) 2015 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>


//-----------------------------------------------------------------------------
#pragma mark Enum Definitions

/*!
 * @abstract Traffic quality bucket representing the range of the traffic.
 *
 * @const IXCLTrafficQualityBucketUnknown  Unknown bucket.
 * @const IXCLTrafficQualityBucketSevere   Severe traffic quality.
 * @const IXCLTrafficQualityBucketHeavy    Heavy traffic quality.
 * @const IXCLTrafficQualityBucketMild     Mild traffic quality.
 * @const IXCLTrafficQualityBucketFreeFlow Free-flow traffic.
 */
typedef NS_ENUM (NSInteger, IXCLTrafficQualityBucket)
{
    IXCLTrafficQualityBucketUnknown  = -1,
    IXCLTrafficQualityBucketSevere   = 0,
    IXCLTrafficQualityBucketHeavy    = 1,
    IXCLTrafficQualityBucketMild     = 2,
    IXCLTrafficQualityBucketFreeFlow = 3,
};


//-----------------------------------------------------------------------------
#pragma mark - Global Exports

/*!
 * @abstract
 *      Minimum value supported for the value property on the
 *      IXCLTrafficQuality class.
 * @discussion
 *      Value is 0.
 */
FOUNDATION_EXPORT NSInteger const IXCLTrafficQualityValueMin;

/*!
 * @abstract
 *      Maximum value supported for the value property on the
 *      IXCLTrafficQuality class.
 * @discussion
 *      Value is 10.
 */
FOUNDATION_EXPORT NSInteger const IXCLTrafficQualityValueMax;


//-----------------------------------------------------------------------------
#pragma mark - Class Declaration

/*!
 * @class IXCLTrafficQuality
 * @abstract Model object for traffic quality.
 */
@interface IXCLTrafficQuality : NSObject

//-----------------------------------------------------------------------------
#pragma mark - Properties

/*!
 * @abstract Traffic quality bucket representing the range of the traffic.
 */
@property (nonatomic, assign, readonly) IXCLTrafficQualityBucket bucket;

/*!
 * @abstract Traffic quality value from 0 to 10.
 */
@property (nonatomic, assign, readonly) NSInteger value;

/*!
 * @abstract Overall delay time represented by the traffic quality.
 */
@property (nonatomic, assign, readonly) NSTimeInterval delayTime;

/*!
 * @abstract Traffic quality description text.
 */
@property (nonatomic, copy, readonly) NSString * text;

/*!
 * @abstract Target location city name.
 */
@property (nonatomic, copy, readonly) NSString * cityName;

/*!
 * @abstract Traffic quality information collection time.
 */
@property (nonatomic, strong, readonly) NSDate * collectionTime;

//-----------------------------------------------------------------------------
#pragma mark - Methods

/*!
 * @abstract Initializes an instance of the IXCLTrafficQuality class.
 *
 * @param bucket         Traffic quality bucket.
 * @param value          Traffic quality value.
 * @param delayTime      Overall delay time.
 * @param text           Traffic quality description text.
 * @param cityName       Target location city name.
 * @param collectionTime Traffic quality information collection time.
 *
 * @return Instance of the IXCLTrafficQuality class.
 */
- (instancetype) initWithBucket: (IXCLTrafficQualityBucket) bucket
                          value: (NSInteger) value
                      delayTime: (NSTimeInterval) delayTime
                           text: (NSString *) text
                       cityName: (NSString *) cityName
                 collectionTime: (NSDate *) collectionTime;

@end
