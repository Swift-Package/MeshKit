//
//  FDSMeshModel.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/5/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FDSMeshNodeModel : NSObject

// 节点名称
@property (nonatomic, strong) NSString *name;

// 节点类型
@property (nonatomic, strong) NSString *type;

// 节点单播地址
@property (nonatomic, assign) UInt16 address;

// 节点MAC地址
@property (nonatomic, strong) NSString *macAddress;

// 蓝牙固件版本（从000041开始都能获取到版本，之前的固件都是000000)
@property (nonatomic, strong) NSString *firmwareVersion;

// 0x00或0xFF代表非PA，0x01代表PA，其它数字代表其它固件类型
@property (nonatomic, assign) NSInteger paValue;

// 节点状态
@property (nonatomic, assign) FDS_DeviceState state;

@end

@interface FDSMeshGroupModel : NSObject

// 组名称
@property (nonatomic, strong) NSString *name;

// 组地址
@property (nonatomic, assign) UInt16 address;

// 节点列表
@property (nonatomic, strong) NSArray<FDSMeshNodeModel*> *groupDevices;

@end

@interface FDSMeshModel : NSObject

@end

NS_ASSUME_NONNULL_END
