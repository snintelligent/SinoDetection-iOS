//
//  SDTrue2DataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/1/16.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 采血部位枚举
typedef NS_ENUM(NSUInteger, SDTDMBldCollSite) {
    SDTDMBldCollSiteUnknown, ///< 未知
    SDTDMBldCollSiteFingertip, ///< 手指指尖血
    SDTDMBldCollSiteMulti, ///< 多部位采血
};

/// 营养状态枚举
typedef NS_ENUM(NSUInteger, SDTDMNutritionStatus) {
    SDTDMNutritionStatusUnknown, ///< 未知
    SDTDMNutritionStatusRandom, ///< 随机
    SDTDMNutritionStatusBeforeMeal, ///< 餐前（空腹）
    SDTDMNutritionStatusAfterMeal, ///< 餐后（非空腹）
    SDTDMNutritionStatusSport, ///< 运动
    SDTDMNutritionStatusSick, ///< 生病
    SDTDMNutritionStatusTakeMedicine, ///< 服药
    SDTDMNutritionStatusOther ///< 其他
};

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
/// 数据类型（测试项目）
/// @note 真睿2代仅支持血糖
@property (nonatomic, assign) SDCDataType dataType;
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
@property (nonatomic, assign) SDTDMBldCollSite bldCollSite;
/// 营养状态
@property (nonatomic, assign) SDTDMNutritionStatus nutritionStatus;
/// 血细胞压积，正常范围应为0-100
@property (nonatomic, assign) NSUInteger hematocrit;
@end

NS_ASSUME_NONNULL_END
