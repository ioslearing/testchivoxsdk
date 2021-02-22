//
//  ChivoxEngineDelegate.h
//  ChivoxEngineSDKDemo
//
//  Created by John on 16/9/9.
//  Copyright © 2016年 Chivox. All rights reserved.
//

#import <Foundation/Foundation.h>
@protocol ChivoxEngineDelegate <NSObject>
@optional
#pragma mark -------用于oc或者swift3.3版本以上-------
/**
 *  初始化回调
 *
 *  @param engine 引擎实例
 *  @param ret    结果0成功 -1失败
 *  @param msg    返回信息
 */
-(void)initCallback:(id)engine Ret:(int)ret Msg:(NSString*)msg;
/**
 *  引擎启用返回结果 部分关键数据
 *
 *  @param ret 结果0成功 -1失败
 *  @param msg 返回信息评测结果具体也在字典中体现
 */
-(void)engineStartCallBackWithRet:(int)ret Message:(NSDictionary *)msg;
@required
/**
 *  评测结果返回全部数据
 *
 *  @param resultDic 全部数据字典
 */
-(void)engineStartCallBackWithAllResult:(NSDictionary *)resultDic;
/**
 开始回放回调

 @param filePath 回放文件路径
 @param dur 回放文件时长
 */
-(void)recorderReplayStartCallback:(NSString *)filePath duration:(float)dur;

/**
 回放完成

 @param filePath 回放文件路径
 */
-(void)recorderReplayFinishedCallback:(NSString *)filePath;
///**
// 第一次调用完成
// 
// @param resultDic  存放了serialnumber字符串和provision的文件名
// */
-(void)engineStartCallBackWithfirstuser:(NSDictionary *)resultDic;

@optional
#pragma mark -------兼容swift3.3版本及以下-------
/**
 *  初始化回调
 *
 *  @param engine 引擎实例
 *  @param ret    结果0成功 -1失败
 *  @param msg    返回信息
 */
-(void)onInitCallback:(id)engine ret:(int)ret msg:(NSString*)msg;
/**
 *  引擎启用返回结果 部分关键数据
 *
 *  @param ret 结果0成功 -1失败
 *  @param msg 返回信息评测结果具体也在字典中体现
 */
-(void)onEngineStartCallBackWithRet:(int)ret message:(NSDictionary *)msg;


@end
