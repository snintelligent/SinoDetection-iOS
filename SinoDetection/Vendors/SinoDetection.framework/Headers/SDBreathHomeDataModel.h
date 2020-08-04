//
//  SDBreathHomeDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/7/7.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDBreathHomeDataModel : SDBaseDataModel
/// 时间，格式：yyyy-MM-dd HH:mm:ss
@property (nonatomic, strong) NSString *time;
/// PEF 值
@property (nonatomic, strong) NSString *pefValue;
/// PEF 单位，L/min
@property (nonatomic, strong, readonly) NSString *pefUnit;
/// FEV1 值
@property (nonatomic, strong) NSString *fev1Value;
/// FEV1 单位，L
@property (nonatomic, strong, readonly) NSString *fev1Unit;
/// FVC 值
@property (nonatomic, strong) NSString *fvcValue;
/// FVC 单位，L
@property (nonatomic, strong, readonly) NSString *fvcUnit;
@end

NS_ASSUME_NONNULL_END
