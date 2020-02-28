//
//  SDScanDeviceController.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SinoDetection/SDConstant.h>

NS_ASSUME_NONNULL_BEGIN

@interface SDScanDeviceController : UIViewController
/// 扫描的设备类型
@property (nonatomic, assign) SDCDeviceType scannedType;
@end

NS_ASSUME_NONNULL_END
