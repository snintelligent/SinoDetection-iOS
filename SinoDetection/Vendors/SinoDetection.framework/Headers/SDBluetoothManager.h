//
//  SDBluetoothManager.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/25.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "SDConstant.h"
#import "SDBussinessStateModel.h"

NS_ASSUME_NONNULL_BEGIN

@class SDDetectionDataModel;
@class SDDeviceModel;
/// 已接收到数据代码块
/// @param data 检测数据对象
/// @param state 业务状态对象
/// @param boundDevice 绑定的设备
typedef void(^SDBMDidReceiveData)(SDDetectionDataModel * _Nullable data, SDBussinessStateModel * _Nullable state, SDDeviceModel *boundDevice);

/// 已接收到Mac地址
/// @note 针对卡迪克
/// @param mac Mac地址
/// @param boundDevice 绑定的设备
typedef void(^SDBMDidReceiveMac)(NSString * _Nullable mac, SDDeviceModel *boundDevice);

/// 蓝牙管理类
@interface SDBluetoothManager : NSObject

/// 已接收到数据代码块
@property (nonatomic, copy) SDBMDidReceiveData didReceiveData;

/// 已接收到Mac地址
/// @note 针对卡迪克
@property (nonatomic, copy) SDBMDidReceiveMac didReceiveMac;

/// 构造蓝牙管理类单例对象
/// @return 蓝牙管理类单例对象
+ (instancetype)sharedBluetoothManager;

/// 结束扫描
- (void)stopScan;

/// 重新扫描外设
- (void)rescan;

/// 扫描某类外设
/// @param deviceType 设备类型
- (void)scanWithDeviceType:(SDCDeviceType)deviceType;

/// 连接多台设备
- (void)connectDevices;

/// 断开连接多台设备
- (void)disconnectDevices;

/// 写命令到某设备
/// @discussion 当设置时间时，content赋值时间，格式为@"yyyy-MM-dd HH:mm:ss"，年的范围为2000-2
///099，蓝牙WL-1型支持到分
///
/// 当设置校正码时，content赋值校正码，格式为@"23"，校正码有取值范围，蓝牙WL-1型为1-40
/// @param command 命令字
/// @param content 内容数据
/// @param boundDevice 绑定的设备对象
- (void)writeCommand:(SDCCommandType)command content:(NSString * _Nullable)content boundDevice:(SDDeviceModel *)boundDevice;
@end

NS_ASSUME_NONNULL_END
