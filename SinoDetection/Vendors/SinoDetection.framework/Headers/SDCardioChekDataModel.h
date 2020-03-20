//
//  SDCardioChekDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/3/13.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import "SDBaseDataModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDCardioChekDataModel : SDBaseDataModel
/// 日期，例如：2020 02 16
@property (nonatomic, strong) NSString *date;
/// 时间，例如：09:06 PM
@property (nonatomic, strong) NSString *time;
/// 格式化的时间，例如：2020-02-16 09:06 PM 或 2020-02-16 19:06
@property (nonatomic, strong, readonly) NSString *formattedTime;
/// 总胆固醇结果
@property (nonatomic, strong) NSString *chol;
/// 总胆固醇结果值
@property (nonatomic, strong, readonly) NSString *cholValue;
/// 总胆固醇单位
@property (nonatomic, strong, readonly) NSString *cholUnit;
/// 高密度脂蛋白胆固醇结果
@property (nonatomic, strong) NSString *hdlChol;
/// 高密度脂蛋白胆固醇结果值
@property (nonatomic, strong, readonly) NSString *hdlCholValue;
/// 高密度脂蛋白胆固醇单位
@property (nonatomic, strong, readonly) NSString *hdlCholUnit;
/// 甘油三酯结果
@property (nonatomic, strong) NSString *trig;
/// 甘油三酯结果值
@property (nonatomic, strong, readonly) NSString *trigValue;
/// 甘油三酯单位
@property (nonatomic, strong, readonly) NSString *trigUnit;
/// 低密度脂蛋白胆固醇结果
@property (nonatomic, strong) NSString *calcLdl;
/// 低密度脂蛋白胆固醇结果值
@property (nonatomic, strong, readonly) NSString *calcLdlValue;
/// 低密度脂蛋白胆固醇单位
@property (nonatomic, strong, readonly) NSString *calcLdlUnit;
/// 总胆固醇结果值与高密度脂蛋白胆固醇结果值比值
@property (nonatomic, strong) NSString *tcHdl;
/// 血糖结果
@property (nonatomic, strong) NSString *glucose;
/// 血糖结果值
@property (nonatomic, strong, readonly) NSString *glucoseValue;
/// 血糖单位
@property (nonatomic, strong, readonly) NSString *glucoseUnit;
@end

NS_ASSUME_NONNULL_END
