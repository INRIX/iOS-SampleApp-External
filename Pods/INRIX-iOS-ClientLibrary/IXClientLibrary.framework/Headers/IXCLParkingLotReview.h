/*
 * @header IXCLParkingLotReview.h
 * @author Patrick Winchell
 * @updated 12-08-2017
 * @copyright Copyright (c) 2017 INRIX, Inc.
 *
 *  INRIX is a registered trademark of INRIX, Inc.  Any copyright, patent and
 *  trademark notice(s) contained herein or in related code, files or
 *  documentation shall not be altered and shall be included in all copies and
 *  substantial portions of the software. This software is "Source Code".
 *  Refer to the License.pdf file for your rights to use this software.
 */

#import <Foundation/Foundation.h>

/*!
 * @class IXCLParkingLotReview
 *
 * @abstract
 *      Model object which respresents a review for the parking lot.
 */
@interface IXCLParkingLotReview : NSObject <NSCopying>

/*!
 * @abstract Integer value of the star rating given for the lot.
 */
@property (nonatomic, assign, readwrite) int stars;

/*!
 * @abstract The text of the review.
 */
@property (nonatomic, strong, readwrite) NSString * review;

/*!
 * @abstract The reviewer's name.
 */
@property (nonatomic, strong, readwrite) NSString * name;

/*!
 * @abstract The date the review was posted.
 */
@property (nonatomic, strong, readwrite) NSDate * date;

@end
