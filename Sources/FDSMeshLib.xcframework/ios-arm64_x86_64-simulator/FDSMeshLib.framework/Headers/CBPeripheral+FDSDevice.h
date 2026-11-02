//
//  CBPeripheral+FDSDevice.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/5/17.
//

#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

@interface CBPeripheral (FDSDevice)

// 设备名称
@property (nonatomic, strong) NSString *device_name;

// 设备类型 - 2字节
@property (nonatomic, strong) NSString *device_type;

// 设备信号强度
@property (nonatomic, strong) NSString *device_rssi;

// 设备MAC地址 - 6字节
@property (nonatomic, strong) NSString *device_macAddress;

// 设备蓝牙固件版本
@property (nonatomic, strong) NSString *device_firmwareVersion;

// 广播包数据
@property (nonatomic, strong) NSData *device_adverData;

// 组网待使用的单播地址（需要上层赋值）
@property (nonatomic, strong) NSNumber *device_address;

// 0x00或0xFF代表非PA，0x01代表PA，其它数字代表其它固件类型
@property (nonatomic, strong) NSString *device_pa_value;

@end

NS_ASSUME_NONNULL_END
