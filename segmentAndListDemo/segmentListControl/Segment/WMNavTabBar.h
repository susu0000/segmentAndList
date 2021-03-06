//
//  WMNavTabBar.h
//
//  Created by zwm on 15-5-26.
//  Copyright (c) 2015年 zwm. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kRed 39
#define kGreen 72
#define kBlue 249
#define kLineColor [UIColor colorWithRed:kRed/255.0 green:kGreen/255.0 blue:kBlue/255.0 alpha:1.0]

#define kShadeLeft [UIImage imageNamed:@"Shade_Left"]
#define kShadeRight [UIImage imageNamed:@"Shade_Right"]

#define kShadeW 40

#define kBarFont 16.0
#define kBarFontScale 0.9

// 回调当前选项索引以及是否重复选择
typedef void (^WMNavTabBarBlock)(NSInteger index, NSInteger isRepeat);

@class WMNavTabBar;
@protocol WMNavTabBarDelegate <NSObject>
@required
// 回调当前选项索引以及是否重复选择
- (void)itemDidSelected:(WMNavTabBar *)tabBar withIndex:(NSInteger)index isRepeat:(BOOL)isRepeat;
@end

@interface WMNavTabBar : UIView

@property (nonatomic, weak) id <WMNavTabBarDelegate>delegate;   /**< 回调 */
@property (nonatomic, assign) NSInteger currentItemIndex;       /**< 当前选项索引 */
@property (nonatomic, assign) BOOL isSamp;                      /**< 是否平摊，配置选项之前设置 */
@property (nonatomic, assign) BOOL isFont;                      /**< 是否改变字体大小，配置选项之前设置 */
@property (nonatomic, assign) BOOL isStop;                      /**< 转屏时控制一下 */

///  1、配置选项
///  @param itemTitles  选项数组
///  @param scrollView  联动scrollView，如果不必联动可为nil
///  @param block       改变选项回调，也可以nil使用delegate
- (void)setItemTitles:(NSArray<NSString *> *)itemTitles
        andScrollView:(UIScrollView *)scrollView
        selectedBlock:(WMNavTabBarBlock)block;

@end
