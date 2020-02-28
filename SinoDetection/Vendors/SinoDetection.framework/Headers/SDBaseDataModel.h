//
//  SDBaseDataModel.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/24.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SDConstant.h"

NS_ASSUME_NONNULL_BEGIN

@interface SDBaseDataModel : NSObject

/// 补零的值
/// @param value 数值
/// @return 补零的值
- (NSString *)zeroValue:(NSUInteger)value;

@end

NS_ASSUME_NONNULL_END
