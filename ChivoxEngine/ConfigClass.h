//
//  ConfigClass.h
//  ChivoxEngine
//
//  Created by John on 2016/10/11.
//  Copyright © 2016年 Chivox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define NATIVERESUPDATE @"CheckNativeResUpdate"
NS_ASSUME_NONNULL_BEGIN
@interface ConfigClass : NSObject
/**
 *  Appkey
 */
@property (nonatomic,copy) NSString *AppKey;
/**
 *  Secretkey
 */
@property (nonatomic,copy) NSString *SecretKey;

/*
 *  UserId
 */
@property (nonatomic,copy) NSString *UserId;

/*
 * alg
 */
@property (nonatomic,copy) NSString *alg;
/*
 *sig
 */
@property (nonatomic,copy) NSString *sig;
/*
 *timestamp
 */
@property (nonatomic,copy) NSString *timestamp;

/**
 *  授权文件路径
 */
@property (nonatomic,copy) NSString *ProvisionFile;
/**
 *  DebugEnable
 */
@property (nonatomic,assign) BOOL DebugEnable;
/**
 *  离线资源路径(SaveResEnable设置为NO时 路径默认为NSTemporaryDirectory() )
 */
@property (nonatomic,copy) NSString *NativeResPath;
/**
 *离线资源得到的路径（不设置默认为根目录下路径）;
 */
@property (nonatomic,copy) NSString *NativeGetPath;
/**
 *  是否存储录音
 */
@property (nonatomic,assign) BOOL SaveRecEnable;
/**
 *  录音存放路径
 */
@property (nonatomic,copy) NSString *SaveRecPath;

/**
 *  特殊处理开关 默认开启的
 */
@property (nonatomic,assign) BOOL isSpecialFilter;
/**
 全局松弛因子 0.5~2
 */
@property (nonatomic,assign)float relaxation_factor;

///**
// 是否根据relaxation_factor调整得分 默认开启
// */
//@property(nonatomic,assign)BOOL isReviseScore;

/**
 *  单例方法
 *
 *  @return ConfigClass对象
 */
+(ConfigClass *)getInstance;

/**
 根据文本来判断所用时间
 
 @param refText 需要评测的文本
 @return 所用时间
 */
-(NSInteger)getDurtimeWithRef:(NSString *)refText;

/**
 转拼音接口

 @param cnWord 中文
 @param completionHandler 转出结果
 */
-(void)translatePinYinFromCnWord:(NSString *)cnWord completionHandler:(void (^_Nullable)(NSString *resultPinYin, NSString *cnWord,NSError * _Nullable error))completionHandler;
/**
 评测结果返回转换音标


 @param dict 原始数据
 @return 请浊音特殊处理变换之后的数据
 */
-(NSDictionary *_Nullable)resultPostProcess:(NSDictionary *)dict;





/**
 检查离线资源更新
 */
-(void)checkAndUpdate;
@end
NS_ASSUME_NONNULL_END
