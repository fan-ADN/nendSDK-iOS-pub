//
//  NADNativeLogger.h
//  NendAd
//
//  Copyright © 2015年 FAN Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NADNativeLogLevel) {
    NADNativeLogLevelDebug = 1,
    NADNativeLogLevelInfo = 2,
    NADNativeLogLevelWarn = 3,
    NADNativeLogLevelError = 4,
    NADNativeLogLevelNone = INT_MAX,
};

__deprecated_msg("NADNativeLogger is deprecated. Use NADLogger instead.")
@interface NADNativeLogger : NSObject

+ (void)setLogLevel:(NADNativeLogLevel)level;

@end
