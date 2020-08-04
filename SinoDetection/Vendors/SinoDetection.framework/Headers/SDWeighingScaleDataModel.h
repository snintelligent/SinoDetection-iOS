//
//  SDWeighingScaleDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/6/18.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDWeighingScaleDataModel : SDBaseDataModel
/// 单位类型
@property (nonatomic, assign) SDCUnitType unitType;
/// 单位
@property (nonatomic, strong, readonly) NSString *unit;
/// 体重值小数位数，范围为0-2
@property (nonatomic, assign) NSUInteger decimalPlace;
/// 体重
@property (nonatomic, assign) NSUInteger weight;
/// 格式化的体重，如果体重值小数位数为2，则为66.80
@property (nonatomic, strong, readonly) NSString *formattedWeight;
@end

NS_ASSUME_NONNULL_END
