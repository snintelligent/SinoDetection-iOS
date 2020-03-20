//
//  SDConstant.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/27.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 设备类型枚举
typedef NS_ENUM(NSUInteger, SDCDeviceType) {
    /// 未知
    SDCDeviceTypeUnknown = 0,
    /// 安稳+Air血糖仪
    SDCDeviceTypeAnWenAir = 1,
    /// 蓝牙WL-1型血糖仪
    SDCDeviceTypeWLOne = 2,
    /// 真睿2代血糖仪
    SDCDeviceTypeTrue2 = 30,
    /// EA-12型血糖尿酸测试仪
    SDCDeviceTypeEA12 = 25,
    /// EA-18型血糖尿酸测试仪
    SDCDeviceTypeEA18 = 31,
    /// 卡迪克干式生化分析仪
    SDCDeviceTypeCardioChek = 3,
    /// 掌越血脂血糖仪
    SDCDeviceTypeSLX120 = 13
};

/// 命令字枚举
typedef NS_ENUM(NSUInteger, SDCCommandType) {
    /// 未知
    SDCCommandTypeUnknown = 0x00,
    /// 测试连接
    SDCCommandTypeTestConnect = 0x01,
    /// 错误状态
    SDCCommandTypeErrorState = 0x02,
    /// 滴血闪烁
    SDCCommandTypeDripBloodBlink = 0x03,
    /// 当前测试值
    SDCCommandTypeCurrentTestValue = 0x04,
    /// 读历史数据
    SDCCommandTypeReadHistoryData = 0x05,
    /// 设置时间
    SDCCommandTypeSetTime = 0x06,
    /// 读仪器ID号
    SDCCommandTypeReadDeviceId = 0x07,
    /// 清历史数据
    SDCCommandTypeClearHistoryData = 0x08,
    /// 设置校正码
    SDCCommandTypeSetCorrectCode = 0x09,
    /// 开始测试
    SDCCommandTypeStartTest = 0x0A,
    /// 仪器关机
    SDCCommandTypeShutDown = 0x0B,
    /// 仪器关蓝牙
    SDCCommandTypeTurnOffBluetooth = 0x0C,
    /// 读仪器SN号
    /// @note 真睿2代的命令字
    SDCCommandTypeReadDeviceSN = SDCCommandTypeReadDeviceId,
    /// 历史数据补发
    /// @note 真睿2代和掌越的命令字
    SDCCommandTypeHistoryDataReissue = 0x0E,
    /// 数据上传
    /// @note EA-12型和EA-18型的命令字
    SDCCommandTypeDataUpload = SDCCommandTypeClearHistoryData
};

/// 数据类型（测试项目）枚举
typedef NS_ENUM(NSUInteger, SDCDataType) {
    /// 血糖
    SDCDataTypeBloodSugar,
    /// 尿酸
    SDCDataTypeUricAcid,
    /// 血酮
    SDCDataTypeBloodKetone,
    /// 总胆固醇
    SDCDataTypeTc,
    /// 高密度脂蛋白胆固醇
    SDCDataTypeHdl,
    /// 甘油三酯
    SDCDataTypeTg,
    /// 低密度脂蛋白胆固醇
    SDCDataTypeLdl,
    /// 非高密度脂蛋白胆固醇
    SDCDataTypeNonHdl,
    /// 总胆固醇与高密度脂蛋白胆固醇比
    SDCDataTypeTcHdl,
    /// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比
    SDCDataTypeLdlHdl
};

/// 样本类型枚举
typedef NS_ENUM(NSUInteger, SDCSampleType) {
    /// 未知
    SDCSampleTypeUnknown,
    /// 血液
    SDCSampleTypeBlood,
    /// 电阻条
    /// @note 安稳+Air的样本类型
    SDCSampleTypeResistanceStripe,
    /// 质控液
    /// @note 真睿2代、EA-12型和EA-18型的样本类型
    SDCSampleTypeQCSolution = SDCSampleTypeResistanceStripe,
    /// 室间质评质控液
    /// @note 真睿2代的样本类型
    SDCSampleTypeEQAQCSolution,
    /// 尿液
    /// @note 真睿2代的样本类型
    SDCSampleTypeUrine
};

/// 单位类型枚举
typedef NS_ENUM(NSUInteger, SDCUnitType) {
    /// 未知
    SDCUnitTypeUnknown = 0,
    /// mmol/L
    SDCUnitTypeMmol_L,
    /// mg/dL
    SDCUnitTypeMg_dL,
    /// umol/L
    /// @note 真睿2代、EA-12型和EA-18型的单位类型
    SDCUnitTypeUmol_L,
    /// mg/L
    /// @note 真睿2代单位类型
    SDCUnitTypeMg_L,
    /// mg/g
    /// @note 真睿2代单位类型
    SDCUnitTypeMg_g,
    /// mg/mol
    /// @note 真睿2代单位类型
    SDCUnitTypeMg_mol,
    /// 无单位
    /// @note 掌越单位类型
    SDCUnitTypeNo = 256
};

/// 采血部位枚举
typedef NS_ENUM(NSUInteger, SDCBldCollSite) {
    /// 未知
    SDCBldCollSiteUnknown,
    /// 手指指尖血
    SDCBldCollSiteFingertip,
    /// 多部位采血
    SDCBldCollSiteMulti,
};

/// 营养状态枚举
typedef NS_ENUM(NSUInteger, SDCNutritionStatus) {
    /// 未知
    SDCNutritionStatusUnknown,
    /// 随机
    SDCNutritionStatusRandom,
    /// 餐前（空腹）
    SDCNutritionStatusBeforeMeal,
    /// 餐后（非空腹）
    SDCNutritionStatusAfterMeal,
    /// 运动
    SDCNutritionStatusSport,
    /// 生病
    SDCNutritionStatusSick,
    /// 服药
    SDCNutritionStatusTakeMedicine,
    /// 其他
    SDCNutritionStatusOther
};

/// 测试连接
extern NSString * const SDCWriteCommandTestConnectDescription;
/// 当前测试值
extern NSString * const SDCWriteCommandCurrentTestValueDescription;
/// 读历史数据
extern NSString * const SDCWriteCommandReadHistoryDataDescription;
/// 设置时间
extern NSString * const SDCWriteCommandSetTimeDescription;
/// 读仪器ID号
extern NSString * const SDCWriteCommandReadDeviceIdDescription;
/// 清历史数据
extern NSString * const SDCWriteCommandClearHistoryDataDescription;
/// 设置校正码
extern NSString * const SDCWriteCommandSetCorrectCodeDescription;
/// 仪器关机
extern NSString * const SDCWriteCommandShutDownDescription;
/// 仪器关蓝牙
extern NSString * const SDCWriteCommandTurnOffBluetoothDescription;
/// 读仪器SN号
extern NSString * const SDCWriteCommandReadDeviceSNDescription;

/// 年基数
extern const NSUInteger SDCBaseYear;

@interface SDConstant : NSObject

@end

NS_ASSUME_NONNULL_END
