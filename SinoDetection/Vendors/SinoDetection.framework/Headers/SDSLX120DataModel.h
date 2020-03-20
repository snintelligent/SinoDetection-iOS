//
//  SDSLX120DataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/3/16.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 结果值状态
typedef NS_ENUM(NSUInteger, SDSLXDMValueStatus) {
    /// 未知
    SDSLXDMValueStatusUnknown,
    /// 值错误
    SDSLXDMValueStatusError,
    /// 大于
    /// @note 血糖值大于33.3mmol/L，仪器显示HI
    SDSLXDMValueStatusMore,
    /// 小于
    /// @note 血糖值小于1.1mmol/L，仪器显示LO
    SDSLXDMValueStatusLess,
    /// 正常
    SDSLXDMValueStatusNormal
};

@interface SDSLX120DataModel : SDBaseDataModel
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
/// 总胆固醇结果值，例如：251
@property (nonatomic, assign) NSUInteger tcValue;
/// 总胆固醇结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger tcDecimalPlace;
/// 格式化的总胆固醇结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedTcValue;
/// 样本类型
@property (nonatomic, assign) SDCSampleType sampleType;
/// 总胆固醇单位类型
@property (nonatomic, assign) SDCUnitType tcUnitType;
/// 总胆固醇单位
@property (nonatomic, strong, readonly) NSString *tcUnit;
/// 采血部位
@property (nonatomic, assign) SDCBldCollSite bldCollSite;
/// 营养状态
@property (nonatomic, assign) SDCNutritionStatus nutritionStatus;
/// 血细胞压积，正常范围应为0-100
@property (nonatomic, assign) NSUInteger hematocrit;
/// 总胆固醇结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus tcValueStatus;
/// 高密度脂蛋白胆固醇结果值，例如：251
@property (nonatomic, assign) NSUInteger hdlValue;
/// 高密度脂蛋白胆固醇结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger hdlDecimalPlace;
/// 格式化的高密度脂蛋白胆固醇结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedHdlValue;
/// 高密度脂蛋白胆固醇单位类型
@property (nonatomic, assign) SDCUnitType hdlUnitType;
/// 高密度脂蛋白胆固醇单位
@property (nonatomic, strong, readonly) NSString *hdlUnit;
/// 高密度脂蛋白胆固醇结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus hdlValueStatus;
/// 甘油三酯结果值，例如：251
@property (nonatomic, assign) NSUInteger tgValue;
/// 甘油三酯结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger tgDecimalPlace;
/// 格式化的甘油三酯结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedTgValue;
/// 甘油三酯单位类型
@property (nonatomic, assign) SDCUnitType tgUnitType;
/// 甘油三酯单位
@property (nonatomic, strong, readonly) NSString *tgUnit;
/// 甘油三酯结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus tgValueStatus;
/// 低密度脂蛋白胆固醇结果值，例如：251
@property (nonatomic, assign) NSUInteger ldlValue;
/// 低密度脂蛋白胆固醇结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger ldlDecimalPlace;
/// 格式化的低密度脂蛋白胆固醇结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedLdlValue;
/// 低密度脂蛋白胆固醇单位类型
@property (nonatomic, assign) SDCUnitType ldlUnitType;
/// 低密度脂蛋白胆固醇单位
@property (nonatomic, strong, readonly) NSString *ldlUnit;
/// 低密度脂蛋白胆固醇结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus ldlValueStatus;
/// 非高密度脂蛋白胆固醇结果值，例如：251
@property (nonatomic, assign) NSUInteger nonHdlValue;
/// 非高密度脂蛋白胆固醇结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger nonHdlDecimalPlace;
/// 格式化的非高密度脂蛋白胆固醇结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedNonHdlValue;
/// 非高密度脂蛋白胆固醇单位类型
@property (nonatomic, assign) SDCUnitType nonHdlUnitType;
/// 非高密度脂蛋白胆固醇单位
@property (nonatomic, strong, readonly) NSString *nonHdlUnit;
/// 非高密度脂蛋白胆固醇结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus nonHdlValueStatus;
/// 总胆固醇与高密度脂蛋白胆固醇比值结果值，例如：251
@property (nonatomic, assign) NSUInteger tcHdlValue;
/// 总胆固醇与高密度脂蛋白胆固醇比值结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger tcHdlDecimalPlace;
/// 格式化的总胆固醇与高密度脂蛋白胆固醇比值结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedTcHdlValue;
/// 总胆固醇与高密度脂蛋白胆固醇比值单位类型
@property (nonatomic, assign) SDCUnitType tcHdlUnitType;
/// 总胆固醇与高密度脂蛋白胆固醇比值单位
@property (nonatomic, strong, readonly) NSString *tcHdlUnit;
/// 总胆固醇与高密度脂蛋白胆固醇比值结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus tcHdlValueStatus;
/// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值结果值，例如：251
@property (nonatomic, assign) NSUInteger ldlHdlValue;
/// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger ldlHdlDecimalPlace;
/// 格式化的低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedLdlHdlValue;
/// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值单位类型
@property (nonatomic, assign) SDCUnitType ldlHdlUnitType;
/// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值单位
@property (nonatomic, strong, readonly) NSString *ldlHdlUnit;
/// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比值结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus ldlHdlValueStatus;
/// 血糖结果值，例如：251
@property (nonatomic, assign) NSUInteger gluValue;
/// 血糖结果值小数位数，范围为0-15
@property (nonatomic, assign) NSUInteger gluDecimalPlace;
/// 格式化的血糖结果值，如果结果值小数位数为1，则为25.1
@property (nonatomic, strong, readonly) NSString *formattedGluValue;
/// 血糖单位类型
@property (nonatomic, assign) SDCUnitType gluUnitType;
/// 血糖单位
@property (nonatomic, strong, readonly) NSString *gluUnit;
/// 血糖结果值状态
@property (nonatomic, assign) SDSLXDMValueStatus gluValueStatus;
@end

NS_ASSUME_NONNULL_END
