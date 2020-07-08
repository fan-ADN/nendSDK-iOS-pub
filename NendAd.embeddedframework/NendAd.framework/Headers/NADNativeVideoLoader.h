//
//  NADNativeVideoLoader.h
//  NendAdFramework
//
//  Copyright © 2018年 FAN Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NADNativeVideo.h"
#import "NADUserFeature.h"

NS_ASSUME_NONNULL_BEGIN
@interface NADNativeVideoLoader : NSObject

@property (readwrite, nonatomic, copy, nullable) NSString *userId;
@property (readwrite, nonatomic, copy, nullable) NSString *mediationName;
@property (readwrite, nonatomic, strong, nullable) NADUserFeature *userFeature;
@property (readwrite, nonatomic) BOOL isLocationEnabled;

- (instancetype _Null_unspecified)init NS_UNAVAILABLE;
- (instancetype)initWithSpotId:(NSString *)spotId apiKey:(NSString *)apiKey __deprecated_msg("This method is deprecated. Use newer one that specified spotID parameter as NSInteger.");
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;
- (instancetype)initWithSpotId:(NSString *)spotId apiKey:(NSString *)apiKey clickAction:(NADNativeVideoClickAction)action __deprecated_msg("This method is deprecated. Use newer one that specified spotID parameter as NSInteger.");
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey clickAction:(NADNativeVideoClickAction)action;

- (void)setFillerStaticNativeAdId:(NSString *)spotId apiKey:(NSString *)apiKey __deprecated_msg("This method is deprecated. Use newer one that specified spotID parameter as NSInteger.");
- (void)setFillerStaticNativeAdID:(NSInteger)spotID apiKey:(NSString *)apiKey;
- (void)loadAdWithCompletionHandler:(void(^)(NADNativeVideo * _Nullable, NSError * _Nullable))handler;

@end
NS_ASSUME_NONNULL_END
