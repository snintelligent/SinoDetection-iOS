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
    SDCDeviceTypeUnknown = 0, ///< 未知
    SDCDeviceTypeAnWenAir, ///< 安稳+Air
    SDCDeviceTypeWLOne, ///< 蓝牙WL-1型
    SDCDeviceTypeTrue2 = 30, ///< 真睿2代
};

/// 命令字枚举
typedef NS_ENUM(NSUInteger, SDCCommandType) {
    SDCCommandTypeUnknown = 0x00, ///< 未知
    SDCCommandTypeTestConnect = 0x01, ///< 测试连接
    SDCCommandTypeErrorState = 0x02, ///< 错误状态
    SDCCommandTypeDripBloodBlink = 0x03, ///< 滴血闪烁
    SDCCommandTypeCurrentTestValue = 0x04, ///< 当前测试值
    SDCCommandTypeReadHistoryData = 0x05, ///< 读历史数据
    SDCCommandTypeSetTime = 0x06, ///< 设置时间
    SDCCommandTypeReadDeviceId = 0x07, ///< 读仪器ID号
    SDCCommandTypeClearHistoryData = 0x08, ///< 清历史数据
    SDCCommandTypeSetCorrectCode = 0x09, ///< 设置校正码
    SDCCommandTypeStartTest = 0x0A, ///< 开始测试
    SDCCommandTypeShutDown = 0x0B, ///< 仪器关机
    SDCCommandTypeTurnOffBluetooth = 0x0C, ///< 仪器关蓝牙
    // 真睿2代的命令字
    SDCCommandTypeReadDeviceSN = SDCCommandTypeReadDeviceId, ///< 读仪器SN号
    SDCCommandTypeHistoryDataReissue = 0x0E ///< 历史数据补发
};

/// 数据类型（测试项目）枚举
typedef NS_ENUM(NSUInteger, SDCDataType) {
    SDCDataTypeBloodSugar = 0, ///< 血糖
    SDCDataTypeUricAcid, ///< 尿酸
    SDCDataTypeBloodKetone, ///< 血酮
    SDCDataTypeLipidTC, ///< 血脂TC
    SDCDataTypeLipidHDL, ///< 血脂HDL
    SDCDataTypeLipidTG ///< 血脂TG
};

/// 样本类型枚举
typedef NS_ENUM(NSUInteger, SDCSampleType) {
    SDCSampleTypeUnknown, ///< 未知
    SDCSampleTypeBlood, ///< 血液
    SDCSampleTypeResistanceStripe, ///< 电阻条
    // 真睿2代的样本类型
    SDCSampleTypeQCSolution = SDCSampleTypeResistanceStripe, ///< 质控液
    SDCSampleTypeEQAQCSolution, ///< 室间质评质控液
    SDCSampleTypeUrine ///< 尿液
};

/// 单位类型枚举
typedef NS_ENUM(NSUInteger, SDCUnitType) {
    SDCUnitTypeUnknown, ///< 未知
    SDCUnitTypeMmol_L, ///< mmol/L
    SDCUnitTypeMg_dL, ///< mg/dL
    // 真睿2代的单位类型
    SDCUnitTypeUmol_L, ///< umol/L
    SDCUnitTypeMg_L, ///< mg/L
    SDCUnitTypeMg_g, ///< mg/g
    SDCUnitTypeMg_mol ///< mg/mol
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
