//
//  NSDate+SDAddition.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/2.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (SDAddition)
/**
Returns a formatted string representing this date.
see http://www.unicode.org/reports/tr35/tr35-31/tr35-dates.html#Date_Format_Patterns
for format description.

@param format   String representing the desired date format.
e.g. @"yyyy-MM-dd HH:mm:ss"

@return NSString representing the formatted date string.
*/
- (nullable NSString *)stringWithFormat:(NSString *)format;

/**
 Returns a date parsed from given string interpreted using the format.
 
 @param dateString The string to parse.
 @param format     The string's date format.
 
 @return A date representation of string interpreted using the format.
 If can not parse the string, returns nil.
 */
+ (nullable NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format;
@end

NS_ASSUME_NONNULL_END
