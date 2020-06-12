//
//  SDTrue2DataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/1/16.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDTrue2DataModel : SDBaseDataModel
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
/// 测试项目
/// @note 真睿2代仅支持血糖
@property (nonatomic, assign) SDCTestItemType testItemType;
/// 测试结果，例如：251
@property (nonatomic, assign) NSUInteger result;
/// 结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger decimalPlace;
/// 格式化的测试结果，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedResult;
/// 样本类型
@property (nonatomic, assign) SDCSampleType sampleType;
/// 单位类型
@property (nonatomic, assign) SDCUnitType unitType;
/// 单位
@property (nonatomic, strong, readonly) NSString *unit;
/// 采血部位
@property (nonatomic, assign) SDCBldCollSite bldCollSite;
/// 营养状态
@property (nonatomic, assign) SDCNutritionStatus nutritionStatus;
/// 血细胞压积，正常范围应为0-100
@property (nonatomic, assign) NSUInteger hematocrit;
@end

NS_ASSUME_NONNULL_END
