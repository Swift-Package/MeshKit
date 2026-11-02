//
//  FDSEnumeration.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/5/17.
//

#ifndef FDSEnumeration_h
#define FDSEnumeration_h

typedef enum : UInt8 {
    FDS_DeviceStateOn,              // 开灯 - 已上线
    FDS_DeviceStateOff,             // 关灯 - 已上线
    FDS_DeviceStateOutOfLine,       // 未上线
} FDS_DeviceState;                  // 设备状态

typedef enum : UInt8 {
    FDS_Connection_PowerOff,         // 蓝牙已关闭
    FDS_Connection_PowerOn,          // 蓝牙已开启
    FDS_Connection_Unsupported,      // 蓝牙不支持
    FDS_Connection_Unauthorized,     // 蓝牙无权限
    FDS_Connection_BearerOpen,       // 连接已就绪
    FDS_Connection_BearerClose,      // 连接已关闭
} FDS_ConnectionState;               // 连接状态

#endif /* FDSEnumeration_h */
