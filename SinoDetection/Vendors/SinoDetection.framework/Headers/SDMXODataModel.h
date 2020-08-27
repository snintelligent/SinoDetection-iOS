//
//  SDMXODataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/8/19.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDMXODataModel : SDBaseDataModel
/// 脉率值
@property (nonatomic, assign) NSUInteger pulseRateValue;
/// 脉率单位
@property (nonatomic, strong, readonly) NSString *pulseRateUnit;
/// 血氧饱和度值
@property (nonatomic, assign) NSUInteger spO2Value;
/// 血氧饱和度单位
@property (nonatomic, strong, readonly) NSString *spO2Unit;
/// 温度整数部分
@property (nonatomic, assign) NSUInteger intPartOfTemp;
/// 温度小数部分
@property (nonatomic, assign) NSUInteger decimalPartOfTemp;
/// 温度，四舍五入，保留1位小数，例如：“36.7”
@property (nonatomic, strong, readonly) NSString *temperature;
/// 温度单位，℃
@property (nonatomic, strong, readonly) NSString *temperatureUnit;
@end

NS_ASSUME_NONNULL_END
