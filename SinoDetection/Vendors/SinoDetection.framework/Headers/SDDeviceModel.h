//
//  SDDeviceModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDConstant.h"

NS_ASSUME_NONNULL_BEGIN

/// 蓝牙类型枚举
typedef NS_ENUM(NSUInteger, SDDMBluetoothType) {
    SDDMBluetoothTypeBLE = 0, ///< 低功耗蓝牙
    SDDMBluetoothTypeClassic ///< 经典蓝牙
};

/// 通知特征标识符关键字
extern NSString * const SDDMNotifyUUID;
/// 写特征标识符关键字
extern NSString * const SDDMWriteUUID;
/// 写命令类型关键字
extern NSString * const SDCWriteCommandType;
/// 写命令描述关键字
extern NSString * const SDCWriteCommandDescription;

/// 设备模型类
@interface SDDeviceModel : NSObject <NSCopying>
/// 设备类型
@property (nonatomic, assign) SDCDeviceType type;
/// 设备名称
@property (nonatomic, strong) NSString *name;
/// 蓝牙类型
@property (nonatomic, assign) SDDMBluetoothType bluetoothType;
/// 蓝牙名称
@property (nonatomic, strong) NSString *bluetoothName;
/// 设备标识符
@property (nonatomic, strong) NSString *uuid;
/// 设备标识名称，如“BDE_WEIXIN_TTM”
@property (nonatomic, strong) NSString *idName;
/// Mac地址，如“00000000”
@property (nonatomic, strong) NSString *mac;
/// 格式化的Mac地址
@property (nonatomic, strong, readonly) NSString *formattedMac;
/// 服务标识符数组
@property (nonatomic, strong, readonly) NSArray *services;
/// 特征字典
@property (nonatomic, strong, readonly) NSDictionary *characteristics;
/// 创建时间
@property (nonatomic, strong) NSString *createTime;
/// 更新时间
@property (nonatomic, strong) NSString *updateTime;
/// 写命令数组
@property (nonatomic, strong, readonly) NSArray *writeCommands;
/// SN号
@property (nonatomic, strong) NSString *sn;

#pragma mark - Public Methods
/// 构造支持的设备模型对象
/// @param type 设备类型
+ (instancetype)supportedDeviceModelWithType:(SDCDeviceType)type;

/// 构造扫描的设备模型对象
/// @param type 设备类型
/// @param uuid 设备标识符
/// @param idName 设备标识名称，如“BDE_WEIXIN_TTM”
/// @param mac Mac地址
+ (instancetype)scannedDeviceModelWithType:(SDCDeviceType)type
                                      uuid:(NSString *)uuid
                                    idName:(NSString *)idName
                                       mac:(nullable NSString *)mac;
@end

NS_ASSUME_NONNULL_END
