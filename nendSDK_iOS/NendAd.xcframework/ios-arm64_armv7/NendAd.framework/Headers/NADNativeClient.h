//
//  NADNativeClient.h
//  NendAd
//
//  Copyright (c) 2015年 FAN Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NADNative.h"
#import "NADNativeError.h"

typedef void (^NADNativeCompletionBlock)(NADNative *ad, NSError *error);

@interface NADNativeClient : NSObject

/**
 * Initializes a client object.
 *
 * @return A NADNativeClient object.
 */
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;

/**
 * Load native ad.
 */
- (void)loadWithCompletionBlock:(NADNativeCompletionBlock)completionBlock;

/**
 * Enable auto reload.
 */
- (void)enableAutoReloadWithInterval:(NSTimeInterval)interval completionBlock:(NADNativeCompletionBlock)completionBlock;

/**
 * Disable auto reload.
 */
- (void)disableAutoReload;

@end
