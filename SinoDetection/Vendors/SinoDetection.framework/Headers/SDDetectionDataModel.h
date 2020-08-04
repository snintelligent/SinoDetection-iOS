//
//  SDDetectionDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/5.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDAnWenAirDataModel.h"
#import "SDWLOneDataModel.h"
#import "SDTrue2DataModel.h"
#import "SDEADataModel.h"
#import "SDCardioChekDataModel.h"
#import "SDSLX120DataModel.h"
#import "SDGoldAQDataModel.h"
#import "SDGoldAQAirDataModel.h"
#import "SDUG11DataModel.h"
#import "SDMBBDataModel.h"
#import "SDPCHDataModel.h"
#import "SDAlicnRLFA1DataModel.h"
#import "SDWeighingScaleDataModel.h"
#import "SDBreathHomeDataModel.h"
#import "SDSinoHeartDataModel.h"

NS_ASSUME_NONNULL_BEGIN

/// 检测数据类
@interface SDDetectionDataModel : NSObject
/// 某类仪器检测数据对象
@property (nonatomic, strong) SDBaseDataModel *data;
@end

NS_ASSUME_NONNULL_END
