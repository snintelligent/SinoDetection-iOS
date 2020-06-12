//
//  SDEADataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/3/10.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// EA-12型和EA-18型数据模型类
@interface SDEADataModel : SDBaseDataModel
/// 测试项目
/// @note EA-12型和EA-18型支持血糖和尿酸
@property (nonatomic, assign) SDCTestItemType testItemType;
/// 样本类型
@property (nonatomic, assign) SDCSampleType sampleType;
/// 校正码
/// @note 测血糖为免调码；测尿酸有值
@property (nonatomic, assign) NSUInteger correctCode;
/// 年，例如：19
@property (nonatomic, assign) NSUInteger year;
/// 月
@property (nonatomic, assign) NSUInteger month;
/// 日
@property (nonatomic, assign) NSUInteger day;
/// 时
@property (nonatomic, assign) NSUInteger hour;
/// 分
@property (nonatomic, assign) NSUInteger minute;
/// 时间，格式：yyyy-MM-dd HH:mm
@property (nonatomic, strong, readonly) NSString *time;
/// 测试结果，例如：251
@property (nonatomic, assign) NSUInteger result;
/// 格式化的测试结果
/// @discussion 以测试结果251为例，如果是血糖，单位为mmol/L，则为25.1，单位为mg/dL，则为251；
///如果是尿酸，单位为umol/L，则为251，单位为mg/dL，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedResult;
/// 温度，例如：216
@property (nonatomic, assign) NSUInteger temperature;
/// 格式化的温度，例如：“21.6℃”
@property (nonatomic, strong, readonly) NSString *formattedTemperature;
/// 单位类型
@property (nonatomic, assign) SDCUnitType unitType;
/// 单位
@property (nonatomic, strong, readonly) NSString *unit;
/// 是否HI
@property (nonatomic, assign) BOOL isHI;
/// 是否LO
@property (nonatomic, assign) BOOL isLO;
@end

NS_ASSUME_NONNULL_END
