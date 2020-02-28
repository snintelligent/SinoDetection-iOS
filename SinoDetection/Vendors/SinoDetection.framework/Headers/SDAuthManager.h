//
//  SDAuthManager.h
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/22.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SDAuthManager : NSObject

/// 是否已鉴权
@property (nonatomic, assign, readonly) BOOL authed;

/// 访问令牌
@property (nonatomic, strong, readonly) NSString *accessToken;

+ (instancetype)sharedAuthManager;

/// 鉴权
/// @param appKey 应用Key
/// @param bundleId Bundle Id
- (void)authWithAppKey:(nonnull NSString *)appKey
              bundleId:(nonnull NSString *)bundleId;
@end

NS_ASSUME_NONNULL_END
