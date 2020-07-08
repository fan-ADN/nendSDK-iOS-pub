//
//  NADInterstitialVideo.h
//  NendAd
//

#import "NADVideo.h"

@class NADInterstitialVideo;

@protocol NADInterstitialVideoDelegate <NSObject>

@optional

- (void)nadInterstitialVideoAdDidReceiveAd:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAd:(NADInterstitialVideo *)nadInterstitialVideoAd didFailToLoadWithError:(NSError *)error;
- (void)nadInterstitialVideoAdDidFailedToPlay:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidOpen:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidClose:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidStartPlaying:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidStopPlaying:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidCompletePlaying:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidClickAd:(NADInterstitialVideo *)nadInterstitialVideoAd;
- (void)nadInterstitialVideoAdDidClickInformation:(NADInterstitialVideo *)nadInterstitialVideoAd;

@end

@interface NADInterstitialVideo : NADVideo

@property (nonatomic, weak, readwrite) id<NADInterstitialVideoDelegate> delegate;
@property (nonatomic, copy) UIColor *fallbackFullboardBackgroundColor;
#ifndef FANCS_APP
@property (nonatomic) BOOL isMuteStartPlaying;
#endif//FANCS_APP
#ifdef TRIAL_NEW_FEATURES
@property (nonatomic) BOOL isSkipButtonMoveToRightBottom;
@property (nonatomic) NSInteger fadeOutSkipButtonSecond;
#endif//TRIAL_NEW_FEATURES

- (void)addFallbackFullboardWithSpotId:(NSString *)spotId apiKey:(NSString *)apiKey __deprecated_msg("This method is deprecated. Use newer one that specified spotID parameter as NSInteger.");
- (void)addFallbackFullboardWithSpotID:(NSInteger)spotID apiKey:(NSString *)apiKey;

@end
