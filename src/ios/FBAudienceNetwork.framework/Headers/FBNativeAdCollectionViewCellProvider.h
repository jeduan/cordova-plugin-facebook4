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
#import <UIKit/UIKit.h>

#import "FBAdDefines.h"
#import "FBNativeAd.h"
#import "FBNativeAdCollectionViewAdProvider.h"
#import "FBNativeAdView.h"
#import "FBNativeAdsManager.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @class FBNativeAdCollectionViewCellProvider

 @abstract Class which assists in putting FBNativeAdViews into UICollectionViews. This class manages the creation of UICollectionViewCells which host native ad views. Functionality is provided to create UICollectionCellViews as needed for a given indexPath as well as computing the height of the cells.
 */
FB_CLASS_EXPORT FB_SUBCLASSING_RESTRICTED
@interface FBNativeAdCollectionViewCellProvider : FBNativeAdCollectionViewAdProvider

/*!
 @method

 @abstract Method to create a FBNativeAdCollectionViewCellProvider.

 @param manager The naitve ad manager consumed by this provider
 @param type The type of this native ad template. For more information, consult FBNativeAdViewType.
 */
- (instancetype)initWithManager:(FBNativeAdsManager *)manager forType:(FBNativeAdViewType)type;

/*!
 @method

 @abstract Method to create a FBNativeAdCollectionViewCellProvider.

 @param manager The naitve ad manager consumed by this provider
 @param type The type of this native ad template. For more information, consult FBNativeAdViewType.
 @param attributes The layout of this native ad template. For more information, consult FBNativeAdViewLayout.
 */
- (instancetype)initWithManager:(FBNativeAdsManager *)manager forType:(FBNativeAdViewType)type forAttributes:(FBNativeAdViewAttributes *)attributes NS_DESIGNATED_INITIALIZER;

/*!
 @method

 @abstract Helper method for implementors of UICollectionViewDataSource who would like to host native ad UICollectionViewCells in their collection view.
 */
- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath;

/*!
 @method

 @abstract Helper method for implementors of UICollectionViewDelegate who would like to host native ad UICollectionViewCells in their collection view.
 */
- (CGFloat)collectionView:(nonnull UICollectionView *)collectionView heightForRowAtIndexPath:(nonnull NSIndexPath *)indexPath;

@end

NS_ASSUME_NONNULL_END
