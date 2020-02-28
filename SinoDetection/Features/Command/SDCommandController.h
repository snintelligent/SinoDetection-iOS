//
//  SDCommandController.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/24.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SinoDetection/SDConstant.h>

NS_ASSUME_NONNULL_BEGIN
@class SDDeviceModel;
typedef void(^SDCCWriteCommand)(SDCCommandType command, NSString * _Nullable content, SDDeviceModel *boundDevice);

@interface SDCommandController : UIViewController
@property (nonatomic, copy) SDCCWriteCommand writeCommand;
@end

NS_ASSUME_NONNULL_END
