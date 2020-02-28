//
//  SDWLOneDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/24.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDWLOneDataModel : SDBaseDataModel
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
/// 测试结果，例如：251
@property (nonatomic, assign) NSUInteger result;
/// 测试结果，例如：“25.1”
@property (nonatomic, strong, readonly) NSString *formattedResult;
/// 单位，mmol/L
@property (nonatomic, strong, readonly) NSString *unit;
/// 是否HI
@property (nonatomic, assign) BOOL isHI;
/// 是否LO
@property (nonatomic, assign) BOOL isLO;
@end

NS_ASSUME_NONNULL_END
