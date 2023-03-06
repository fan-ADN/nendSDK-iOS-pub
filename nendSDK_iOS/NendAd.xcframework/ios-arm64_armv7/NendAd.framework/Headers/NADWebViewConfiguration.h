//
//  NADWebViewConfiguration.h
//  NendAd
//
//  Copyright © 2022 FAN Communications, Inc. All rights reserved.
//

#ifndef NADWebViewConfiguration_h
#define NADWebViewConfiguration_h

#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface NADWebViewConfiguration : NSObject

@property (nonatomic, nullable) WKProcessPool *processPool;

+ (instancetype _Nonnull)sharedInstance;

@end

#endif /* NADWebViewConfiguration_h */
NS_ASSUME_NONNULL_END
