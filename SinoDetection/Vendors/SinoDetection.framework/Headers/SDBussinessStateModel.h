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
    SDBSMBussinessStateUnconnect = 0, ///< 未连接
    SDBSMBussinessStateConnected, ///< 已连接
    SDBSMBussinessStateDripBloodBlink, ///< 滴血闪烁
    SDBSMBussinessStateStartTest, ///< 开始测试
    SDBSMBussinessStateShutDown, ///< 仪器关机
    SDBSMBussinessStateTestConnectSuccess, ///< 测试连接成功
    SDBSMBussinessStateSetTimeSuccess, ///< 设置时间成功
    SDBSMBussinessStateClearHistoryDataSuccess, ///< 清历史数据成功
    SDBSMBussinessStateClearHistoryDataFail, ///< 清历史数据失败
    SDBSMBussinessStateNoHistroyData, ///< 无历史数据
    SDBSMBussinessStateReadDeviceSNSuccess, ///< 读仪器SN号成功
};

@interface SDBussinessStateModel : NSObject
@property (nonatomic, assign) SDBSMBussinessState state;
@property (nonatomic, strong, readonly) NSString *desc;
@end

NS_ASSUME_NONNULL_END
