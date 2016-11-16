// Copyright (c) 2014-present, Facebook, Inc. All rights reserved.
//
// You are hereby granted a non-exclusive, worldwide, royalty-free license to use,
// copy, modify, and distribute this software in source code or binary form for use
// in connection with the web services and APIs provided by Facebook.
//
// As with any software that integrates with the Facebook platform, your use of
// this software is subject to the Facebook Developer Principles and Policies
// [http://developers.facebook.com/policy/]. This copyright notice shall be
// included in all copies or substantial portions of the software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

#import "FBAdDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol FBRewardedVideoAdDelegate;

/*!
 @class FBRewardedVideoAd

 @abstract A modal view controller to represent a Facebook rewarded video ad. This
 is a full-screen ad shown in your application.
 */
FB_CLASS_EXPORT FB_SUBCLASSING_RESTRICTED
@interface FBRewardedVideoAd : NSObject

/*!
 @property
 @abstract Typed access to the id of the ad placement.
 */
@property (nonatomic, copy, readonly) NSString *placementID;

/*!
 @property
 @abstract the delegate
 */
@property (nonatomic, weak, nullable) id<FBRewardedVideoAdDelegate> delegate;

/*!
 @property

 @abstract
 Returns true if the rewarded video ad has been successfully loaded.

 @discussion You should check `isAdValid` before trying to show the ad.
 */
@property (nonatomic, getter=isAdValid, readonly) BOOL adValid;

/*!
 @method

 @abstract
 This is a method to initialize an FBRewardedVideoAd matching the given placement id.

 @param placementID The id of the ad placement. You can create your placement id from Facebook developers page.
 */
- (instancetype)initWithPlacementID:(NSString *)placementID;

/*!
 @method

 @abstract
 This is a method to initialize an FBRewardedVideoAd matching the given placement id and allows the publisher to set
 the reward to give to a user.

 @param placementID The id of the ad placement. You can create your placement id from Facebook developers page.
 @param userID the id of the user
 @param currency reward currency type
 @param amount reward amount
 */
- (instancetype)initWithPlacementID:(NSString *)placementID
                         withUserID:(nullable NSString *)userID
                       withCurrency:(nullable NSString *)currency
                         withAmount:(NSInteger)amount;

/*!
 @method

 @abstract
 Begins loading the FBRewardedVideoAd content.

 @discussion You can implement `rewardedVideoAdDidLoad:` and `rewardedVideoAd:didFailWithError:` methods
 of `FBRewardedVideoAdDelegate` if you would like to be notified as loading succeeds or fails.
 */
- (void)loadAd;

/*!
 @method

 @abstract
 Presents the rewarded video ad modally from the specified view controller.

 @param rootViewController The view controller that will be used to present the rewarded video ad.

 @discussion You can implement `rewardedVideoAdDidClick:` and `rewardedVideoAdWillClose:`
 methods of `FBRewardedVideoAdDelegate` if you would like to stay informed for those events.
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController;

/*!
 @method

 @abstract
 Presents the rewarded video ad modally from the specified view controller.

 @param rootViewController The view controller that will be used to present the rewarded video ad.
 @param flag Pass YES to animate the presentation; otherwise, pass NO.

 @discussion You can implement `rewardedVideoAdDidClick:` and `rewardedVideoAdWillClose:`
 methods of `FBRewardedVideoAdDelegate` if you would like to stay informed for those events.
 */
- (BOOL)showAdFromRootViewController:(UIViewController *)rootViewController animated:(BOOL)flag;

@end

/*!
 @protocol

 @abstract
 The methods declared by the FBRewardedVideoAdDelegate protocol allow the adopting delegate to respond
 to messages from the FBRewardedVideoAd class and thus respond to operations such as whether the ad has
 been loaded, the person has clicked the ad or closed video/end card.
 */
@protocol FBRewardedVideoAdDelegate <NSObject>

@optional

/*!
 @method

 @abstract
 Sent after an ad has been clicked by the person.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdDidClick:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent when an ad has been successfully loaded.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdDidLoad:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent after an FBRewardedVideoAd object has been dismissed from the screen, returning control
 to your application.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdDidClose:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent immediately before an FBRewardedVideoAd object will be dismissed from the screen.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdWillClose:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent after an FBRewardedVideoAd fails to load the ad.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 @param error An error object containing details of the error.
 */
- (void)rewardedVideoAd:(FBRewardedVideoAd *)rewardedVideoAd didFailWithError:(NSError *)error;

/*!
 @method

 @abstract
 Sent after the FBRewardedVideoAd object has finished playing the video successfully.
 Reward the user on this callback.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdComplete:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent immediately before the impression of an FBRewardedVideoAd object will be logged.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdWillLogImpression:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent if server call to publisher's reward endpoint returned HTTP status code 200.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdServerSuccess:(FBRewardedVideoAd *)rewardedVideoAd;

/*!
 @method

 @abstract
 Sent if server call to publisher's reward endpoint did not return HTTP status code 200
 or if the endpoint timed out.

 @param rewardedVideoAd An FBRewardedVideoAd object sending the message.
 */
- (void)rewardedVideoAdServerFailed:(FBRewardedVideoAd *)rewardedVideoAd;

@end


NS_ASSUME_NONNULL_END
