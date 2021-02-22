//
//  CreateInitEngineClass.h
//  ChivoxEngine
//
//  Created by John on 16/9/13.
//  Copyright © 2016年 Chivox. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CreateInitEngineClass : NSObject
/**
 直接传json格式的参数
 */
@property (nonatomic,copy)NSString *jsonCreateParams;
/**
 *  是否开启
 */
@property (nonatomic,assign) int cloudEnable;
/**
 * 协议类型
 */
@property (nonatomic,assign) int cloudprotocol;
/**
 *  服务器地址
 */
@property (nonatomic,copy) NSString *cloudServer;
/**
 *  服务器list
 */
@property (nonatomic,copy) NSString *serverList;
/**
 *  建立连接超时时间
 */
@property  (nonatomic,assign) int connectTimeout;
/**
 *  响应超时时间
 */
@property (nonatomic,assign) int serverTimeout;
/**
*是否使用服务器时间作为 cloud 模块的认证时间戳, 0 不使用 1 使用，默认 0
 */
@property (nonatomic,assign) int useServerTime;

/**
 *  离线参数
 */
@property (nonatomic,assign) int nativeEnable;
/**
 *  离线加载内核类型
 */
@property (nonatomic,copy) NSArray *nativeResArr;
/**
 *  是否加载Vad
 */
@property (nonatomic,assign) int vadEnable;
/**
 *  必须, 如果enable为1则必须(资源路径)
 */
@property (nonatomic,copy) NSString * res;
/**
 *  默认为资源里的配置, 单位帧, 一帧10ms, 表示静音敏感度, 静音等待时间
 */
@property (nonatomic,assign) int speechLowSeek;
/**
 *  默认为资源里的配置
 */
@property (nonatomic,assign) int sampleRate;
/**
 *  默认为1 即过滤首尾静音, 0表示仅用于判断发音结束
 */
@property (nonatomic,assign) int strip;
/**
 *  prof日志是否开启，1为开启。
 */
@property (nonatomic,assign) int profEnable ;
/**
 *  prof日志生成的路径，该路径需要有读写权限，如document目录，需要加上文件名称 如1.txt
 */
@property (nonatomic,copy) NSString *output;
@end
