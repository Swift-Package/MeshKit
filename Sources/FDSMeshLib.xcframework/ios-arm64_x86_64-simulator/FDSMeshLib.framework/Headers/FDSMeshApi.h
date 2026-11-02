//
//  FDSMeshApi.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/5/17.
//

#import <Foundation/Foundation.h>

// 蓝牙、设备状态
#define FDS_CONNECTED_NODE_STATE  @"FDS_CONNECTED_NODE_STATE"

// 刷新MESH节点在线状态
#define FDS_REFRESH_NODES_STATE   @"FDS_REFRESH_NODES_STATE"

// 接收MESH消息数据通知
#define FDS_RECIVE_MESSAGE_DATA   @"FDS_RECIVE_MESSAGE_DATA"

// 接收BLE消息数据通知
#define FDS_RECVBLE_MESSAGE_DATA  @"FDS_RECVBLE_MESSAGE_DATA"

NS_ASSUME_NONNULL_BEGIN

@interface FDSMeshApi : NSObject

/**
 获取SDK版本号

 @return 版本x.x.x
 */
+ (NSString *)getVersion;

/**
 初始化SDK，接入使用需要申请AppId

 @param appId 应用AppId
 */
+ (void)startWithAppId:(NSString *)appId;

/**
 启用SDK日志

 @param isOpen YES表示启用，NO表示关闭
 */
+ (void)openSdkLog:(BOOL)isOpen;

/**
 清空SDK日志
 */
+ (void)clearSdkLog;

/**
 配置连接参数
 
 @param connectTimeout 蓝牙连接超时，默认70.0s
 @param serviceTimeout 扫描服务超时，默认20.0s,
 @param retryCount 重试次数，默认2次
 */
+ (void)configConnectParams:(NSTimeInterval)connectTimeout serviceTimeout:(NSTimeInterval)serviceTimeout retryCount:(NSInteger)retryCount;

/**
 获取节点列表

 @return 节点列表
 */
+ (NSArray<FDSMeshNodeModel*>*)getNodes;

/**
 获取组列表

 @return 组列表
 */
+ (NSArray<FDSMeshGroupModel*>*)getGroups;

/**
 获取未订阅组的节点列表

 @return 节点列表
 */
+ (NSArray<FDSMeshNodeModel*>*)getNodesWhitOutGroup;

/**
 刷新节点列表和组
 */
+ (void)refreshNodesAndGroups;

/**
 获取直连节点

 @return 直连节点
 */
+ (FDSMeshNodeModel*)getConnectedNode;

/**
 根据MAC地址获取指定节点

 @param macAddress 节点MAC地址
 @return 节点
 */
+ (FDSMeshNodeModel*)getNodeByMacAddress:(NSString*)macAddress;

/**
 根据单播地址获取指定节点

 @param address 单播地址
 @return 节点
 */
+ (FDSMeshNodeModel *)getNodeByAddress:(NSString *)address;

/**
 根据组地址获取组
 
 @param address 组地址
 @return 组
 */
+ (FDSMeshGroupModel *)getGroupByAddress:(UInt16)address;

/**
 清除脏节点数据

 @param macAddress 节点MAC地址
 */
+ (void)clearDirtyNodeByMacAddress:(NSString *)macAddress;

/**
 修改直连节点并重启网络
 
 @param fdsNodeModel 节点，如果传nil则自动连接任意一个节点
 */
+ (void)changeConnectedNode:(FDSMeshNodeModel *_Nullable)fdsNodeModel;

/**
 过滤组网后自动连接的设备列表
 
 @param macAddressList MAC地址列表
 */
+ (void)filterAutoConnectedNode:(NSArray<NSString*> *)macAddressList;

/**
 是否能够扫描未入网的设备
 
 @return YES表示可以扫描，NO表示不可以
 */
+ (BOOL)isEnableScanProvisionedDevices;

/**
 扫描设备

 @param filterName 基于设备的localname进行过滤，传空默认不过滤
 @param completion 蓝牙外设对象回调
 */
+ (void)startScanDevice:(NSString *)filterName completion:(void (^)(CBPeripheral *peripheral))completion;

/**
 扫描已配网的设备

 @param filterName 基于设备的localname进行过滤，传空默认不过滤
 @param completion 蓝牙外设对象回调
 */
+ (void)startScanProvisionedDevice:(NSString *)filterName completion:(void (^)(CBPeripheral *peripheral))completion;

/**
 停止扫描
 */
+ (void)stopScan;

/**
 通用模式组网（Fast KeyBind）
 
 @param peripherals 蓝牙外设对象列表
 @param progressAction 设备组网回调
 @param resultAction 组网完成回调
 */
+ (void)startAddDeviceToNetWork:(NSArray<CBPeripheral*>*)peripherals progressAction:(void (^)(BOOL success, CBPeripheral *peripheral))progressAction resultAction:(void (^)(BOOL finish, NSArray *addrList))resultAction;

/**
 快速模式组网（Fast Provsion）
 
 @param peripherals 蓝牙外设对象列表
 @param progressAction 设备组网回调
 @param resultAction 组网完成回调
 */
+ (void)startAddDeviceToNetWork_Fast:(NSArray<CBPeripheral*>*)peripherals progressAction:(void (^)(CGFloat progress, NSArray *macList))progressAction resultAction:(void (^)(BOOL finish, NSArray *addrList))resultAction;

/**
 移除节点
 
 @param nodeModel 节点
 @param isSupport 是否支持删除离线节点
 @return YES表示删除成功，NO表示删除失败
 */
+ (BOOL)removeNode:(FDSMeshNodeModel *)nodeModel isSupportOutOfLine:(BOOL)isSupport;

/**
 批量移除已组网节点（通过蓝牙广播）
 （只支持固件版本大于000055以上设备）
 
 @param macAddressList MAC地址列表
 @param progressAction 单个设备回调
 @param resultAction 接口回调
 @return YES表示删除成功，NO表示删除失败
 */
+ (BOOL)batchAdvertRemoveNode:(NSArray<NSString *>*)macAddressList progressAction:(void (^)(NSString *macAddress))progressAction resultAction:(void (^)(BOOL finish))resultAction;

/**
 批量移除节点
 
 @param nodeList 节点列表
 @param progressAction 节点回调
 @param resultAction 接口回调
 @return YES表示删除成功，NO表示删除失败
 */
+ (BOOL)batchRemoveNode:(NSArray<FDSMeshNodeModel *>*)nodeList progressAction:(void (^)(BOOL success, FDSMeshNodeModel *nodeModal))progressAction resultAction:(void (^)(BOOL finish))resultAction;

/**
 重命名节点名属性
 
 @param nodeModel 节点
 @param name 节点名称
 @param type 节点类型
 @param firmwareVersion 节点蓝牙固件版本
 @return YES表示成功，NO表示失败
 */
+ (BOOL)renameNode:(FDSMeshNodeModel *)nodeModel name:(NSString *)name type:(NSString *)type firmwareVersion:(NSString *)firmwareVersion;

/**
 创建组
 
 @param name 组名称
 @param address 返回的组地址（组地址范围0xC000-0xFEEF）
 @return YES表示创建成功，NO表示创建失败
 */
+ (BOOL)createGroup:(NSString *)name address:(UInt16*)address;

/**
 重命名组
 
 @param groupModel 组
 @param name 组名称
 @return YES表示重命名成功，NO表示重命名失败
 */
+ (BOOL)renameGroup:(FDSMeshGroupModel *)groupModel name:(NSString *)name;

/**
 移除组
 
 @param groupModel 组
 @return YES表示删除成功，NO表示删除失败
 */
+ (BOOL)removeGroup:(FDSMeshGroupModel *)groupModel;

/**
 配置节点批量“订阅/取消订阅”组
 
 @param nodeList 节点列表
 @param groupModel 组
 @param isAdd YES表示订阅到组，NO表示取消订阅
 @param isCompatible YES兼容旧版-取消订阅速度慢，NO不兼容旧版-取消订阅速度快
 @param progressAction 设备订阅回调
 @param resultAction 订阅完成回调
 @return YES表示成功，NO表示失败
 */
+ (BOOL)configSubscribeGroup:(NSArray<FDSMeshNodeModel *>*)nodeList groupModel:(FDSMeshGroupModel *)groupModel isAdd:(BOOL)isAdd isCompatible:(BOOL)isCompatible progressAction:(void (^)(BOOL success, FDSMeshNodeModel *nodeModal))progressAction resultAction:(void (^)(BOOL finish))resultAction;

/**
 检测和刷新节点在线状态
 注意：只能在主线程内调用，避免频繁调用。
      可调用场景：导入MeshJson后、Mesh组网后、从后台进入前台后，首次进入Studio后。
 */
+ (void)refreshWorkNormal;

/**
 配置节点自动上报在线状态
 
 @param isOn YES表示开启自动上报，NO表示取消自动上报
 @param nodeList 节点列表
 @param resultAction 配置回调，方便上层保存MESH JSON
 */
+ (void)configNodePuslishState:(BOOL)isOn nodeList:(NSArray<FDSMeshNodeModel *>*)nodeList resultAction:(void (^)(BOOL isSuccess))resultAction;

/**
 发送OpINI数据
 
 @param iniData 需要上层组装原始数据 iniData like "a3ff000000000200ffffc21102c4020100".
 @param completion 回响应回调
 */
+ (void)sendOpINIData:(NSData *)iniData completion:(void (^)(NSData *responseData))completion;

/**
 发送消息数据
 
 @param address 发送地址
 @param sendData 消息数据
 @param opcode 操作码 - Godox:0xF0
 @param vendorId 供应商ID - Godox:0x0211
 @param responseMax 回复的节点个数
 @param responseOpcode 回响应操作码 - Godox:0xF0或0xF1
 @param retryCount 重发次数 - Godox:0
 @param completion 回响应回调
 */
+ (void)sendMessageAddress:(UInt16)address sendData:(NSData *)sendData opcode:(UInt8)opcode vendorId:(UInt16)vendorId  responseMax:(UInt8)responseMax responseOpcode:(UInt8)responseOpcode retryCount:(NSInteger)retryCount completion:(void (^)(NSData *responseData))completion;

/**
 导入/替换Mesh信息（内部自动云端同步）
 
 @param meshJson 组网JSON信息
 @param isRequest 是否同步云端：本地操作不需要同步，分享导入等操作需要同步。一般都建议传YES。
 @return 最新的provisionAddress, 注意0xFFFF为无效值
 */
+ (UInt16)importMeshJson:(NSDictionary *)meshJson isRequest:(BOOL)isRequest;

/**
 判断能否导入Mesh信息（内部自动云端同步，需要搭配importMeshJson_Ex接口使用）
 
 @param meshJson 组网JSON信息
 @param server_address 从云端获取最新的provisionAddress
 @param isForce 默认传NO，如果传YES则AppUUID会强制修改，后台会重新分配地址（慎传YES避免地址达到上限）
 @return YES表示能导入，NO表示无法导入
 */
+ (BOOL)canImportMeshJson:(NSDictionary *)meshJson isForce:(BOOL)isForce server_address:(NSInteger *)server_address;

/**
 导入/替换Mesh信息
 
 @param meshJson 组网JSON信息
 @param provisionAddress 外部传入的provisionAddress，范围0-0x7FFF
 @return 最新的provisionAddress, 注意0xFFFF为无效值
 */
+ (UInt16)importMeshJson_Ex:(NSDictionary *)meshJson provisionAddress:(UInt16)provisionAddress;

/**
 获取初始Mesh信息（新增场景时需要）
 
 @return Mesh Json字符串
 */
+ (NSString *)getInitMeshJson;

/**
 获取当前Mesh信息（保存或分享场景时需要）
 
 @return Mesh Json字符串
 */
+ (NSString *)getCurrentMeshJson;

/**
 开启OTA升级
 
 @param otaData 固件数据
 @param nodeModel 节点
 @param progressAction 进度回响应
 @param resultAction 结果回响应
 @return YES表示开启成功，NO表示开启失败
 */
+ (BOOL)startOTAWithOtaData:(NSData *)otaData nodeModel:(FDSMeshNodeModel *)nodeModel progressAction:(void(^)(float progress))progressAction resultAction:(void (^)(BOOL isSuccess))resultAction;

/**
 结束OTA升级
 */
+ (void)stopOTA;

/**
 开启Mesh OTA升级
 注：Mesh OTA支持000058及以上版本的设备
 
 @param otaData 固件数据
 @param nodeList 节点列表
 @param progressAction 进度回响应
 @param resultAction 结果回响应
 @param errorAction 错误回响应
 */
+ (void)startMeshOTAWithOtaData:(NSData *)otaData nodeList:(NSArray<FDSMeshNodeModel *>*)nodeList progressAction:(void(^)(float progress))progressAction resultAction:(void (^)(NSArray <NSNumber *>*successAddresses, NSArray <NSNumber *>*failAddresses))resultAction errorAction:(void (^)(void))errorAction;

/**
 结束Mesh OTA升级
 注意：谨慎调用，非必要不调用，要等到回响应再执行其它操作
 
 @param resultAction 结果回响应
 */
+ (void)stopMeshOTA:(void (^)(BOOL isSuccess))resultAction;

/**
 开启MCU OTA升级
 
 @param otaData 固件数据
 @param version 固件版本
 @param nodeModel 节点
 @param progressAction 进度回响应
 @param resultAction 结果回响应
 @return YES表示开启成功，NO表示开启失败
 */
+ (BOOL)startMcuOTAWithOtaData:(NSData *)otaData version:(UInt16)version nodeModel:(FDSMeshNodeModel *)nodeModel progressAction:(void(^)(float progress))progressAction resultAction:(void (^)(BOOL isSuccess))resultAction;

/**
 结束MCU OTA升级
 */
+ (void)stopMcuOTA;

/**
 获取直连节点蓝牙外设
 
 @return 蓝牙外设
 */
+ (CBPeripheral*)getConnectedPeripheral;

/**
 设置蓝牙通道监听
 
 @param peripheral 蓝牙外设
 @param sUUID 服务
 @param cUUID 通道
 @param enabled 是否开启监听
 @return YES表示成功，NO表示失败
 */
+ (BOOL)setNotificationForCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID enable:(BOOL)enabled;

/**
 通过蓝牙通道写数据
 
 @param peripheral 蓝牙外设
 @param sUUID 服务
 @param cUUID 通道
 @param data 数据
 @param isResponse 是否写反馈
 @return YES表示成功，NO表示失败
 */
+ (BOOL)writeCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID data:(NSData *)data response:(BOOL)isResponse;

/**
 通过蓝牙通道读数据
 
 @param peripheral 蓝牙外设
 @param sUUID 服务
 @param cUUID 通道
 @return YES表示成功，NO表示失败
 */
+ (BOOL)readCharacteristic:(CBPeripheral *)peripheral sUUID:(NSString *)sUUID cUUID:(NSString *)cUUID;

@end

NS_ASSUME_NONNULL_END
