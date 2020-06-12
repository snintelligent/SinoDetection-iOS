//
//  SDMBBDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/5/14.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDMBBDataModel : SDBaseDataModel
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
/// 收缩压值
@property (nonatomic, assign) NSUInteger sbpValue;
/// 舒张压值
@property (nonatomic, assign) NSUInteger dbpValue;
/// 血压单位
@property (nonatomic, strong, readonly) NSString *bpUnit;
/// 脉搏值
@property (nonatomic, assign) NSUInteger pulseValue;
/// 脉搏单位
@property (nonatomic, strong, readonly) NSString *pulseUnit;
@end

NS_ASSUME_NONNULL_END
