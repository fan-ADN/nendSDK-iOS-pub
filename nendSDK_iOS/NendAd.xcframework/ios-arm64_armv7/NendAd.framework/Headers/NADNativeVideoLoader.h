//
//  NADNativeVideoLoader.h
//  NendAdFramework
//
//  Copyright © 2018年 FAN Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NADNativeVideo.h"

NS_ASSUME_NONNULL_BEGIN
@interface NADNativeVideoLoader : NSObject

@property (readwrite, nonatomic, copy, nullable) NSString *mediationName;

- (instancetype _Null_unspecified)init NS_UNAVAILABLE;
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey clickAction:(NADNativeVideoClickAction)action;

- (void)setFillerStaticNativeAdID:(NSInteger)spotID apiKey:(NSString *)apiKey;
- (void)loadAdWithCompletionHandler:(void(^)(NADNativeVideo * _Nullable, NSError * _Nullable))handler;

@end
NS_ASSUME_NONNULL_END
