//
//  ChivoxEngine.h
//  ChivoxEngineSDKDemo
//
//  Created by John on 16/9/9.
//  Copyright © 2016年 Chivox. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ChivoxEngineDelegate.h"
#import <AVFoundation/AVFoundation.h>
#import "CreateInitEngineClass.h"
#import "StartEngineClass.h"
typedef enum{
    ENGINE_STATUS_NULL = -2,// 引擎还未初始化
    ENGINE_STATUS_LOADING = -1,//正在初始化
    ENGINE_STATUS_INITIALIZED = 0,// 初始化成功
    ENGINE_STATUS_ERROR = 1,//初始化失败
    ENGINE_STATUS_SERIALERROR = 2// 获取serialNumber失败
}ENGINE_STATUS;

#define EN_WORD_SCORE           @"en.word.score"
#define EN_SENT_SCORE           @"en.sent.score"
#define EN_WORD_CHILD           @"en.word.child"
#define EN_SENT_CHILD           @"en.sent.child"
#define EN_PRED_EXAM            @"en.pred.exam"
#define CN_WORD_SCORE           @"cn.word.score"
#define CN_SENT_SCORE           @"cn.sent.score"
#define EN_SENT_SYN             @"en.sent.syn"
#define CN_SENT_SYN             @"cn.sent.syn"
#define CN_WORD_RAW             @"cn.word.raw"
#define CN_SENT_RAW             @"cn.sent.raw"
#define CN_SENT_RAW_NEW         @"cn.sent.raw.new"
#define CN_WORD_RAW_NEW         @"cn.word.raw.new"
@interface ChivoxEngine : NSObject<AVAudioPlayerDelegate>
/**
 *  引擎状态
 */
@property ENGINE_STATUS engine_status;
/**
 *  引擎代理
 */
@property (nonatomic,weak)id<ChivoxEngineDelegate>engine_delegate;

/**
 *  最近一次录音的recID
 */
@property (nonatomic,copy) NSString *lastRecID;

/**
 *  最近一次录音的路径
 */
@property (nonatomic,copy) NSString *lastRecPath;
/**
 *  AppKey
 */
@property (nonatomic,copy) NSString *Appkey;
/**
 *  SecretKey
 */
@property (nonatomic,copy) NSString *Secrect;
/**
 *  序列号
 */
@property (nonatomic,copy) NSString *serialNumber;

/**
 *  userid
 */
@property (nonatomic,copy) NSString *userID;
/**
 *  分制
 */
@property (nonatomic,assign) int rank;

/**
 *  引擎版本
 */
@property (nonatomic,copy) NSString *CurrentVersion;
/**
 *标志判断为start还是redo。2为start  1为redo
 */
@property (nonatomic,assign)int chivoxflag;

/**
 *  创建在线引擎
 *
 *  @param creatInitEngineClass 创建引擎参数类
 *  @param _delegate            实现代理
 *
 *  @return 引擎
 */
-(ChivoxEngine *)initCloudEngineWithCreateInitEngineClass:(CreateInitEngineClass *)creatInitEngineClass delegate:(id<ChivoxEngineDelegate>)_delegate;

/**
 *  创建离线引擎
 *
 *  @param creatInitEngineClass 创建引擎参数类
 *  @param _delegate            实现代理
 *
 *  @return 引擎
 */
-(ChivoxEngine *)initNativeEngineWithCreateInitEngineClass:(CreateInitEngineClass *)creatInitEngineClass delegate:(id<ChivoxEngineDelegate>)_delegate;

/**
 *  开始评测
 *
 *  @param startEngineClass 开始评测引擎参数类
 */
-(void)startEngineWithStartEngineClass:(StartEngineClass *)startEngineClass;

/**
 *  停止引擎
 */
-(void)stopEngine;
/**
 *  取消本次评测
 */
- (void)cancelEngine;
/**
 *  删除引擎
 */
-(void)deleteEngine;

/**
 *  回放最近一条录音文件
 */
-(void)replayLastRec;
/**
 *  回放指定recID的录音文件
 *
 *  @param recID 想要回放的recID（是json返回结果里面的tokenId字段）
 */
-(void)replayRecWithRecID:(NSString *)recID;
/**
 *  回放指定路径的录音文件 具体到格式
 *
 *  @param path 想要回放录音的路径
 */
-(void)replayRecWithPath:(NSString *)path;
/**
 *  停止回放
 */
-(void)stopReplay;


/**
 *  获取SDK版本号
 *
 *  @return SDK版本号
 */
-(NSString *)getSDKVersion;
///**
// 第一次调用完成
// 
// @param 回调返回serialnumber字符串和provision的文件名 返回结果是resultDic
// */
-(void)accessActivation:(NSString *)appKey secretKey:(NSString *)secrtKey userId:(NSString *)userId delegate:(id<ChivoxEngineDelegate>)_delegate;

/**
 *  重试接口
 */
-(void)redoEngine;
///**
// 注册获取serialnumber 并且保存。
// 
// */
+ (NSDictionary *)getSerialNumberAndActivateWithAppKey:(NSString *)appKey secretKey:(NSString *)secrtKey userId:(NSString *)userId;



@end
