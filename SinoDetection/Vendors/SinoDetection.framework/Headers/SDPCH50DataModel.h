//
//  SDPCH50DataModel.h
//  SinoDetection
//
//  Created by rate on 2021/6/30.
//  Copyright © 2021 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDPCH50DataModel : SDBaseDataModel

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
/// 测试项目
@property (nonatomic, assign) SDCTestItemType testItemType;
/// 小数点个数
@property (nonatomic, assign) NSInteger dezimalCount;



@end

NS_ASSUME_NONNULL_END
