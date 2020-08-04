//
//  SDSinoHeartDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/7/30.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDSinoHeartDataModel : SDBaseDataModel
/// 测量过程数据的有无心跳
@property (nonatomic, assign) BOOL hasHeartbeat;
/// 测量过程数据的气压值
@property (nonatomic, assign) NSUInteger bpValue;
/// 压力单位
@property (nonatomic, strong, readonly) NSString *pUnit;
/// 测量结果的是否心率不齐
@property (nonatomic, assign) BOOL isArrhythmia;
/// 测量结果的收缩压值
@property (nonatomic, assign) NSUInteger sbpValue;
/// 测量结果的舒张压值
@property (nonatomic, assign) NSUInteger dbpValue;
/// 测量结果的心率值
@property (nonatomic, assign) NSUInteger heartRateValue;
/// 心率单位
@property (nonatomic, strong, readonly) NSString *heartRateUnit;
@end

NS_ASSUME_NONNULL_END
