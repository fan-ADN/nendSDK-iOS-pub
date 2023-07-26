//
//  NADFullBoardLoader.h
//  NendAd
//
//  Copyright © 2016年 FAN Communications, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NADFullBoard.h"

typedef NS_ENUM(NSInteger, NADFullBoardLoaderError) {
    NADFullBoardLoaderErrorNone,
    NADFullBoardLoaderErrorFailedAdRequest,
    NADFullBoardLoaderErrorInvalidAdSpaces,
    NADFullBoardLoaderErrorFailedDownloadImage
};

typedef void(^NADFullBoardLoaderCompletionHandler)(NADFullBoard *ad, NADFullBoardLoaderError error);

@interface NADFullBoardLoader : NSObject

- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;
- (void)loadAdWithCompletionHandler:(NADFullBoardLoaderCompletionHandler)handler;

@end
