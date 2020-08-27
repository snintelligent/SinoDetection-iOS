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

/// @"H"
/// @discussion 仪器HI、结果值高于上限
extern NSString * const SDBDMResultH;
/// @"L"
/// @discussion 仪器LO、结果值低于下限
extern NSString * const SDBDMResultL;

@interface SDBaseDataModel : NSObject

/// 配置血糖值
/// @param glu 血糖值
- (void)setupGlu:(NSString * _Nullable * _Nullable)glu;

/// 配置尿酸值
/// @param ua 尿酸值
- (void)setupUa:(NSString * _Nullable * _Nullable)ua;

/// 配置总胆固醇值、高密度脂蛋白胆固醇值、低密度脂蛋白胆固醇值、总胆固醇值与高密度脂蛋白胆固醇值的
///比值和甘油三酯值
/// @param chol 总胆固醇值
/// @param hdlc 高密度脂蛋白胆固醇值
/// @param ldlc 低密度脂蛋白胆固醇值
/// @param tcHdlc 总胆固醇值与高密度脂蛋白胆固醇值的比值
/// @param nonHdlc 非高密度脂蛋白胆固醇值
/// @param ldlcHdlc 低密度脂蛋白胆固醇值与高密度脂蛋白胆固醇值的比值
/// @param tg 甘油三酯值
- (void)setupChol:(NSString * _Nullable * _Nullable)chol
             hdlc:(NSString * _Nullable * _Nullable)hdlc
             ldlc:(NSString * _Nullable * _Nullable)ldlc
           tcHdlc:(NSString * _Nullable * _Nullable)tcHdlc
               tg:(NSString * _Nullable * _Nullable)tg
          nonHdlc:(NSString * _Nullable * _Nullable)nonHdlc
         ldlcHdlc:(NSString * _Nullable * _Nullable)ldlcHdlc;

/// 补零的值
/// @param value 数值
/// @return 补零的值
- (NSString *)zeroValue:(NSUInteger)value;

/// 配置血压值
/// @param bpResult 血压值
- (void)setupBpResult:(NSString * _Nullable * _Nullable)bpResult;

/// 配置糖化血红蛋白值
/// @param hbalc 糖化血红蛋白值
- (void)setupHbalc:(NSString * _Nullable * _Nullable)hbalc;

/// 配置体温值
/// @param t 体温值
- (void)setupT:(double *)t;

/// 配置体重值
/// @param weightResult 体重值
- (void)setupWeightResult:(NSString *_Nullable * _Nullable)weightResult;

/// 配置PEF 值、FEV1 值、FVC 值
/// @param pef PEF 值
/// @param fev1 FEV1 值
/// @param fvc FVC 值
- (void)setupPef:(NSString * _Nullable * _Nullable)pef
            fev1:(NSString * _Nullable * _Nullable)fev1
             fvc:(NSString * _Nullable * _Nullable)fvc;

/// 配置脉搏值
/// @param p 脉搏值
- (void)setupP:(NSUInteger *)p;

/// 配置血氧饱和度值
/// @param spo2 血氧饱和度值
- (void)setupSpo2:(NSUInteger *)spo2;
@end

NS_ASSUME_NONNULL_END
