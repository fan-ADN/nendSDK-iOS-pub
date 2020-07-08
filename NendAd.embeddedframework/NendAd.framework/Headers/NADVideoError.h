//
//  NADVideoError.h
//  NendAd
//

#import <Foundation/Foundation.h>

extern NSString *const kNADVideoErrorDomain;

extern NSInteger const kNADVideoErrorCodeFailedInternal;
extern NSInteger const kNADVideoErrorCodeFailedToAdDownload;
extern NSInteger const kNADVideoErrorCodeFailedToAdFallback;
extern NSInteger const kNADVideoErrorCodeNetworkIsNotActive;
extern NSInteger const kNADVideoErrorCodeFailedToRequest;
extern NSInteger const kNADVideoErrorCodeInvalidResponseData;

@interface NADVideoError : NSError

@end
