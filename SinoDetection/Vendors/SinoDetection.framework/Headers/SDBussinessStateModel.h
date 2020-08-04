//
//  SDBussinessStateModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/30.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 业务状态枚举
typedef NS_ENUM(NSUInteger, SDBSMBussinessState) {
    /// 未连接
    SDBSMBussinessStateUnconnect = 0,
    /// 已连接
    SDBSMBussinessStateConnected,
    /// 滴血闪烁
    SDBSMBussinessStateDripBloodBlink,
    /// 开始测试
    SDBSMBussinessStateStartTest,
    /// 仪器关机
    SDBSMBussinessStateShutDown,
    /// 测试连接成功
    SDBSMBussinessStateTestConnectSuccess,
    /// 设置时间成功
    SDBSMBussinessStateSetTimeSuccess,
    /// 清历史数据成功
    SDBSMBussinessStateClearHistoryDataSuccess,
    /// 清历史数据失败
    SDBSMBussinessStateClearHistoryDataFail,
    /// 无历史数据
    SDBSMBussinessStateNoHistroyData,
    /// 读仪器SN号成功
    SDBSMBussinessStateReadDeviceSNSuccess,
    /// 清血糖历史数据成功，针对金准+、UG-11 Code
    SDBSMBussinessStateClearBloodSugarHistoryDataSuccess,
    /// 清血糖历史数据失败，针对金准+、UG-11 Code
    SDBSMBussinessStateClearBloodSugarHistoryDataFail,
    /// 无血糖历史数据，针对金准+、UG-11 Code
    SDBSMBussinessStateNoBloodSugarHistroyData,
    /// 清血糖质控历史数据成功，针对金准+、UG-11 Code
    SDBSMBussinessStateClearBloodSugarQCHistoryDataSuccess,
    /// 清血糖质控历史数据失败，针对金准+、UG-11 Code
    SDBSMBussinessStateClearBloodSugarQCHistoryDataFail,
    /// 无血糖质控历史数据，针对金准+、UG-11 Code
    SDBSMBussinessStateNoBloodSugarQCHistroyData,
    /// 清尿酸历史数据成功，针对UG-11 Code
    SDBSMBussinessStateClearUricAcidHistoryDataSuccess,
    /// 清尿酸历史数据失败，针对UG-11 Code
    SDBSMBussinessStateClearUricAcidHistoryDataFail,
    /// 无尿酸历史数据，针对UG-11 Code
    SDBSMBussinessStateNoUricAcidHistroyData,
    /// 清尿酸质控历史数据成功，针对UG-11 Code
    SDBSMBussinessStateClearUricAcidQCHistoryDataSuccess,
    /// 清尿酸质控历史数据失败，针对UG-11 Code
    SDBSMBussinessStateClearUricAcidQCHistoryDataFail,
    /// 无尿酸质控历史数据，针对UG-11 Code
    SDBSMBussinessStateNoUricAcidQCHistroyData,
    /// 清所有历史数据成功，针对UG-11 Code
    SDBSMBussinessStateClearAllHistoryDataSuccess,
    /// 清所有历史数据失败，针对UG-11 Code
    SDBSMBussinessStateClearAllHistoryDataFail,
    /// 终端同步APP时间成功，针对爱立康RLF-A1
    SDBSMBussinessStateSyncTimeSuccess,
    /// 删除记忆数据成功，针对爱立康RLF-A1
    SDBSMBussinessStateDeleteMemDataSuccess,
    /// 开始测量，针对安诺心
    SDBSMBussinessStateStartMeasuring,
    /// 正在归零，针对安诺心
    SDBSMBussinessStateZeroing,
    /// 归零结束，针对安诺心
    SDBSMBussinessStateZeroEnd,
    /// 收到测量过程数据，针对安诺心
    SDBSMBussinessStateDidReceiveMeasProcessData,
    /// 收到测量结果，针对安诺心
    SDBSMBussinessStateDidReceiveMeasurementResult,
};

@interface SDBussinessStateModel : NSObject
@property (nonatomic, assign) SDBSMBussinessState state;
@property (nonatomic, strong, readonly) NSString *desc;
@end

NS_ASSUME_NONNULL_END
