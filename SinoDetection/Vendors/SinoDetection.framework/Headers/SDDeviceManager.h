//
//  SDDeviceManager.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDDeviceModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 已更新扫描到的设备数组代码块
/// @param scannedDevices 扫描到的设备数组
typedef void(^SDDMDidUpdateScannedDevices)(NSArray<SDDeviceModel *> *scannedDevices);

/// 已更新绑定的设备数组代码块
/// @param boundDevices 绑定的设备数组
typedef void(^SDDMDidUpdateBoundDevices)(NSArray<SDDeviceModel *> *boundDevices);

/// 设备管理类
@interface SDDeviceManager : NSObject

/// 构造设备管理单例对象
/// @return 设备管理单例对象
+ (instancetype)sharedDeviceManager;

#pragma mark - Handle Supported Devices
/// 支持的设备数组
@property (nonatomic, strong, readonly) NSArray<SDDeviceModel *> *supportedDevices;

#pragma mark - Handle Scanned Devices
/// 扫描到的设备数组
@property (nonatomic, strong, readonly) NSArray<SDDeviceModel *> *scannedDevices;

/// 已更新扫描到的设备数组代码块
@property (nonatomic, copy) SDDMDidUpdateScannedDevices didUpdateScannedDevices;

/// 删除所有扫描到的设备
- (void)removeScannedDevices;

/// 添加扫描到的设备
/// @param scannedDevice 设备模型对象
- (void)addScannedDevice:(SDDeviceModel *)scannedDevice;

#pragma mark - Handle Bound Devices
/// 绑定的设备数组
@property (nonatomic, strong, readonly) NSArray<SDDeviceModel *> *boundDevices;

/// 已更新绑定的设备数组代码块
@property (nonatomic, copy) SDDMDidUpdateBoundDevices didUpdateBoundDevices;

/// 添加绑定的设备
/// @param boundDevice 设备模型对象
- (void)addBoundDevice:(SDDeviceModel *)boundDevice;

/// 根据索引从绑定的设备数组中删除绑定的设备
/// @param index 索引
- (void)removeBoundDeviceAtIndex:(NSInteger)index;
@end

NS_ASSUME_NONNULL_END
