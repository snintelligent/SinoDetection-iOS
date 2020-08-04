//
//  SDAlicnRLFA1DataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/6/15.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDAlicnRLFA1DataModel : SDBaseDataModel
/// 温度整数部分
@property (nonatomic, strong) NSString *intPartOfTemp;
/// 温度小数部分
@property (nonatomic, strong) NSString *decimalPartOfTemp;
/// 月
@property (nonatomic, strong) NSString *month;
/// 日
@property (nonatomic, strong) NSString *day;
/// 小时
@property (nonatomic, strong) NSString *hour;
/// 分钟
@property (nonatomic, strong) NSString *minute;
/// 温度，四舍五入，保留1位小数，例如：“36.7”
@property (nonatomic, strong, readonly) NSString *temperature;
/// 时间，格式：MM-dd HH:mm
@property (nonatomic, strong, readonly) NSString *time;
@end

NS_ASSUME_NONNULL_END
