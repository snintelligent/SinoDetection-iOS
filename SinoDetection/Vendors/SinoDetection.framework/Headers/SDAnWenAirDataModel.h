//
//  SDAnWenAirDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/24.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"
#import "SDConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDAnWenAirDataModel : SDBaseDataModel
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
/// 秒
@property (nonatomic, assign) NSUInteger second;
/// 时间，格式：yyyy-MM-dd HH:mm:ss
@property (nonatomic, strong, readonly) NSString *time;
/// 测试结果，例如：251
@property (nonatomic, assign) NSUInteger result;
/// 格式化的测试结果，例如：“25.1”
@property (nonatomic, strong, readonly) NSString *formattedResult;
/// 样本类型
@property (nonatomic, assign) SDCSampleType sampleType;
/// 温度，例如：216
@property (nonatomic, assign) NSUInteger temperature;
/// 格式化的温度，例如：“21.6℃”
@property (nonatomic, strong, readonly) NSString *formattedTemperature;
/// 校正码，数值范围：0-99
@property (nonatomic, assign) NSUInteger correctCode;
/// 测试项目
/// @note 安稳+Air仅支持血糖
@property (nonatomic, assign) SDCTestItemType testItemType;
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
