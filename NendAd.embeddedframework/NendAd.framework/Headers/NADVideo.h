//
//  NADVideo.h
//  NendAd
//

#import <UIKit/UIKit.h>

#import "NADUserFeature.h"
#import "NADLogger.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, NADVideoAdType) {
    NADVideoAdTypeUnknown,
    NADVideoAdTypeNormal,
    NADVideoAdTypePlayable
};

@protocol NADVideoConsoleLogDelegate <NSObject>
@optional
- (void)mraidConsoleLogMessage:(NSString *)message logLevel:(NADLogLevel)logLevel;
@end

@interface NADVideo : NSObject

@property (nonatomic, copy, nullable) NSString *mediationName;
@property (nonatomic, copy, nullable) NSString *userId;
@property (nonatomic) NADUserFeature *userFeature;

@property (nonatomic, readonly, getter=isReady) BOOL ready;
@property (nonatomic) BOOL isLocationEnabled;
@property (nonatomic) BOOL isOutputLog __deprecated_msg("This method is deprecated. Use setLogLevel: method of NADLogger instead.");
@property (nonatomic, readonly) NADVideoAdType adType;

- (instancetype)initWithSpotId:(NSString *)spotId apiKey:(NSString *)apiKey __deprecated_msg("This method is deprecated. Use newer one that specified spotID parameter as NSInteger.");
- (instancetype)initWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey NS_DESIGNATED_INITIALIZER;
- (void)loadAd;
- (void)showAdFromViewController:(UIViewController *)viewController;
- (void)releaseVideoAd;


#ifdef FANCS_APP
@property (nonatomic) BOOL isMuteStartPlaying;
@property (nonatomic, weak) id<NADVideoConsoleLogDelegate> consoleLogDelegate;
- (void)showMraid:(NSString *)html url:(NSString *)url viewController:(UIViewController *)viewController orientation:(UIInterfaceOrientation)orientation;
#endif //FANCS_APP

@end

NS_ASSUME_NONNULL_END
