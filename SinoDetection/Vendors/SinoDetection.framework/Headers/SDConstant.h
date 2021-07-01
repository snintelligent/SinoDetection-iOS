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
    SDCDeviceTypeSLX120 = 13,
    /// 金准+血糖仪
    SDCDeviceTypeGoldAQ = 9,
    /// 金准+Air血糖仪
    SDCDeviceTypeGoldAQAir = 33,
    /// UG-11 Code血糖尿酸测试仪
    SDCDeviceTypeUG11 = 26,
    /// 脉搏波臂式血压计
    SDCDeviceTypeMBBArm = 6,
    /// PCH-100便携式糖化血红蛋白分析仪
    SDCDeviceTypePCH = 34,
    /// PCH-50
    SDCDeviceTypePCH50 = 100,
    /// 脉搏波台式血压计
    SDCDeviceTypeMBBDesktop = 5,
    /// 爱立康RLF-A1红外额温计
    SDCDeviceTypeAlicnRLFA1 = 28,
    /// 体重秤
    SDCDeviceTypeWeighingScale = 16,
    /// 呼吸家
    SDCDeviceTypeBreathHome = 18,
    /// 安诺心血压计
    SDCDeviceTypeSinoHeart = 7,
    /// 美心温度和脉搏血氧仪
    SDCDeviceTypeMedXingOximeter = 39,
    /// 蓝牙WL-1型血糖仪（微信版）
    SDCDeviceTypeWL1WeChat = 44,
    /// 脉搏波血压计（RBP-9804）
    SDCDeviceTypeMBB9804 = 32,
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
    SDCCommandTypeHistoryDataReissue = 0x0E,
    /// 数据上传
    /// @note EA-12型、EA-18型和PCH-100的命令字
    SDCCommandTypeDataUpload = SDCCommandTypeClearHistoryData,
    /// 终端同步APP时间
    /// @note 爱立康RLF-A1的命令码
    SDCCommandTypeSyncTime = 0x30,
    /// 在线测量结果
    /// @note 爱立康RLF-A1的命令码
    SDCCommandTypeOnlineMeasResult = 0x31,
    /// 读取终端记忆温度数据
    /// @note 爱立康RLF-A1的命令码
    SDCCommandTypeReadMemTempData = 0x32,
    /// 删除记忆数据
    /// @note 爱立康RLF-A1的命令码
    SDCCommandTypeDeleteMemData = 0x33,
    /// 应用层回复血压计已经连接
    /// @note 安诺心的命令
    SDCCommandTypeConnected = 0xA0,
    /// 血压计通知开始测量
    /// @note 安诺心的命令
    SDCCommandTypeStartMeasuring = 0xB1,
    /// 血压计通知正在归零
    /// @note 安诺心的命令
    SDCCommandTypeZeroing = 0xB3,
    /// 血压计通知归零结束
    /// @note 安诺心的命令
    SDCCommandTypeZeroEnd = 0xB4,
    /// 血压计发送测量过程数据
    /// @note 安诺心的命令
    SDCCommandTypeMeasProcessData = 0xB7,
    /// 血压计发送测量结果
    /// @note 安诺心的命令
    SDCCommandTypeMeasurementResult = 0xB8,
    /// 应用层要求血压计开始测量
    /// @note 安诺心的命令
    SDCCommandTypeRequestToStartMeasuring = 0xA1,
    /// 应用层要求血压计停止测量
    /// @note 安诺心的命令
    SDCCommandTypeRequestToStopMeasuring = 0xA2,
    /// 应用层要求血压计关机
    /// @note 安诺心的命令
    SDCCommandTypeRequestToShutDown = 0xA6,
    /// 应用层设置血压计日期
    /// @note 安诺心的命令
    SDCCommandTypeSetDate = 0xA8,
    /// 应用层设置血压计时间
    /// @note 安诺心的命令
    SDCCommandTypeSinoHeartSetTime = 0xA9,
    /// 应用层读取血压计历史记录
    /// @note 安诺心的命令
    SDCCommandTypeReadHistoryRecords = 0xAC,
    /// 连接血压计
    /// @note 脉搏波血压计（RBP-9804）的命令
    SDCCommandTypeConnectBPMeter = 0x0101,
};

/// 测试项目枚举
typedef NS_ENUM(NSUInteger, SDCTestItemType) {
    /// 未知
    SDCTestItemTypeUnknown,
    /// 血糖
    SDCTestItemTypeBloodSugar,
    /// 尿酸
    SDCTestItemTypeUricAcid,
    /// 血酮
    SDCTestItemTypeBloodKetone,
    /// 总胆固醇
    SDCTestItemTypeTc,
    /// 高密度脂蛋白胆固醇
    SDCTestItemTypeHdl,
    /// 甘油三酯
    SDCTestItemTypeTg,
    /// 低密度脂蛋白胆固醇
    SDCTestItemTypeLdl,
    /// 非高密度脂蛋白胆固醇
    SDCTestItemTypeNonHdl,
    /// 总胆固醇与高密度脂蛋白胆固醇比
    SDCTestItemTypeTcHdl,
    /// 低密度脂蛋白胆固醇与高密度脂蛋白胆固醇比
    SDCTestItemTypeLdlHdl,
    ///  糖化血红蛋白
    SDcTestItemTypeTHXHDB
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
    SDCSampleTypeQCSolution = SDCSampleTypeResistanceStripe,
    /// 室间质评质控液
    SDCSampleTypeEQAQCSolution,
    /// 尿液
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
    SDCUnitTypeUmol_L,
    /// mg/L
    SDCUnitTypeMg_L,
    /// mg/g
    SDCUnitTypeMg_g,
    /// mg/mol
    SDCUnitTypeMg_mol,
    /// KG
    /// @note 体重秤单位类型
    SDCUnitTypeKG,
    /// 斤
    /// @note 体重秤单位类型
    SDCUnitTypeCatty,
    /// LB
    /// @note 体重秤单位类型
    SDCUnitTypeLB,
    /// ST:LB
    /// @note 体重秤单位类型
    SDCUnitTypeSTLB,
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

/// 数据类型枚举
typedef NS_ENUM(NSUInteger, SDCDataType) {
    /// 未知
    SDCDataTypeUnknown,
    /// 血糖
    SDCDataTypeBloodSugar,
    /// 血糖质控
    SDCDataTypeBloodSugarQC,
    /// 尿酸
    SDCDataTypeUricAcid,
    /// 尿酸质控
    SDCDataTypeUricAcidQC,
    /// 所有
    SDCDataTypeAll = 0xFFFF + 1
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
/// 读取终端记忆温度数据
extern NSString * const SDCWriteCommandReadMemTempDataDescription;
/// 删除记忆数据
extern NSString * const SDCWriteCommandDeleteMemDataDescription;
/// 开始测量
extern NSString * const SDCWriteCommandStartMeasuringDescription;
/// 停止测量
extern NSString * const SDCWriteCommandStopMeasuringDescription;
/// 年基数
extern const NSUInteger SDCBaseYear;

@interface SDConstant : NSObject

@end

NS_ASSUME_NONNULL_END
