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

NS_ASSUME_NONNULL_BEGIN

/// 检测数据类
@interface SDDetectionDataModel : NSObject
/// 某类仪器检测数据对象
@property (nonatomic, strong) SDBaseDataModel *data;
@end

NS_ASSUME_NONNULL_END
