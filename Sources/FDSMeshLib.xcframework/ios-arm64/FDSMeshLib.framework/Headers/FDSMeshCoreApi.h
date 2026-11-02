//
//  FDSMeshCoreApi.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2023/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FDSMeshCoreApi : NSObject

/**
 配置是否开启状态查询
 
 @param isCheck YES表示开启(默认)，NO表示关闭
 */
+ (void)configWorkCheck:(BOOL)isCheck;

/**
 配置服务器Provision地址管理方式
 
 @param isCheck YES-规则分配，防冲突(默认)，NO-规则分配
 */
+ (void)configServerProvisionType:(BOOL)isCheck;

/**
 通用模式组网（基础配网）
 
 @param peripherals 蓝牙外设对象列表
 @param progressAction 设备组网回调
 @param resultAction 组网完成回调
 */
+ (void)startAddDeviceToNetWork:(NSArray<CBPeripheral*>*)peripherals progressAction:(void (^)(BOOL success, CBPeripheral *peripheral))progressAction resultAction:(void (^)(BOOL finish, NSArray *addrList))resultAction;

/**
 导入/替换Mesh信息（强制使用外部地址并重启网络）
 
 @param meshJson 组网JSON信息
 @param provisionAddress 外部传入的provisionAddress，范围0-0x7FFF
 @return YES表示能导入，NO表示无法导入
 */
+ (BOOL)importMeshJson:(NSDictionary *)meshJson provisionAddress:(UInt16)provisionAddress;

/**
 获取CPS数据
 
 @param address 节点地址
 @param completion 结果回调
 */
+ (void)getCompositionDataGetWithDestination:(UInt16)address completion:(void (^)(NSData *cpsData))completion;

/**
 获取MeshUUID
 
 @return 返回MeshUUID
 */
+ (NSString *)getMeshUUID;

/**
 获取网络AppUUID
 
 @return 返回网络AppUUID
 */
+ (NSString *)getMeshAppUUID;

/**
 获取网络Key
 
 @return 返回网络Key
 */
+ (NSString *)getMeshNetworkKey;

/**
 获取当前网络地址（用于参考强制刷新）
 
 @return 返回当前网络地址，注意0xFFFF为无效地址
 */
+ (UInt16)getAllocatedUnicastRangeLowAddress;


@end

NS_ASSUME_NONNULL_END
