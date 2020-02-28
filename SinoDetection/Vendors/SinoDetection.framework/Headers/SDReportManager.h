//
//  SDReportManager.h
//  SinoDetection
//
//  Created by yangmengqi on 2020/1/6.
//  Copyright © 2020 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const SDRMUid;
extern NSString * const SDRMName;
extern NSString * const SDRMSex;
extern NSString * const SDRMBirthday;
/// 时间代码关键字
extern NSString * const SDRMFoodStatus;
/// 血糖值关键字
extern NSString * const SDRMGlu;
/// 完成代码块
/// @param h5Url h5链接
typedef void(^SDRMCompletion)(NSString * _Nullable h5Url);

@interface SDReportManager : NSObject

/// 生成检测报告
/// @discussion @{@"name": @"ztest", @"sex": @"1", @"birthday": @"1991-02-15", @"uid":"1351244566
///9", @"foodStatus":1, @"heightResult":66, @"weightResult": @"88", @"bmi": @"4", @"glu": @"4"}
///
/// uid，用户手机号码，必需
///
/// name，用户姓名，必需
///
/// sex，性别，1：男，2：女，必需
///
/// birthday，生日，格式：yyyy-MM-dd，必需
///
/// 检测数据，foodStatus、glu等等，按检测项目，可有多项数据，必需有一项数据
///
/// foodStatus，1：空腹，2：餐后，3：随机，0：其他
/// @param params 参数字典
/// @param completion 完成代码块
+ (void)generateReportWithParams:(NSDictionary *)params completion:(SDRMCompletion)completion;
@end

NS_ASSUME_NONNULL_END
