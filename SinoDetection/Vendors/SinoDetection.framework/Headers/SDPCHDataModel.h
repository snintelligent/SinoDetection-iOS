//
//  SDPCHDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/5/15.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDPCHDataModel : SDBaseDataModel
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
/// 时间，格式：yyyy-MM-dd HH:mm
@property (nonatomic, strong, readonly) NSString *time;
/// 测试结果，例如：117
@property (nonatomic, assign) NSUInteger result;
/// 测试结果，例如：“11.7”
@property (nonatomic, strong, readonly) NSString *formattedResult;
/// 单位
@property (nonatomic, strong, readonly) NSString *unit;
@end

NS_ASSUME_NONNULL_END
