//
//  FDSCommandApi.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/6/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FDSCommandApi : NSObject

/**
 获取蓝牙固件版本

 @param address 设备地址
 @param completion 信息回调
    version：固件版本
    paValue：0x00或0xFF代表非PA，0x01代表PA，其它数字代表其它固件类型
 */
+ (void)getBleVersion:(UInt16)address completion:(void (^)(NSString *version, NSInteger paValue))completion;

/**
 获取MCU固件版本
 
 @param address 设备地址
 @param completion 版本回调
    productVersion：产品版本
    mcuVersion：MCU方案版本
 */
+ (void)getMcuVersion:(UInt16)address completion:(void (^)(NSString *productVersion, NSString *mcuVersion))completion;

/**
 获取设备电量
 
 @param address 设备地址
 @param completion 电量回调
    state：1-未充电 2-充电中 其它-未知
    hour：使用时间小时部分
    minute：使用时间分钟部分
    option：0-电量百分比，1-电量格子
    power：如果option为0则范围0-100，如果option为1则范围0-3
 */
+ (void)getBatteryPower:(UInt16)address completion:(void (^)(NSInteger state, NSInteger hour, NSInteger minute, NSInteger option, NSInteger power))completion;

/**
 打开PA固件设备升级限制（注意搭配升级接口使用）
 
 @param address 设备地址
 */
+ (void)openPAOTALimit:(UInt16)address;

/**
 控制设备开关灯

 @param address 设备地址
 @param isSwitch YES表示开灯，NO表示关灯
 */
+ (void)changeLightSwitch:(UInt16)address isSwitch:(BOOL)isSwitch;

/**
 控制设备风扇
 
 @param address 设备地址
 @param mode 模式：0-关 1-智能(自动) 2-手动
 @param speed 速度：模式为2的情况下，0-低速 1-中转速 2-高速 3-静音
 */
+ (void)changeElectricFan:(UInt16)address mode:(NSInteger)mode speed:(NSInteger)speed;


/**
 控制亮度偏移
 
 @param address 设备地址
 @param brightness 偏移亮度 (-100)-(+100)
 @param brightness_point 小数点后偏移亮度 0-9
 */
+ (void)changeBrightnessOffset:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point;

/**
 修改灯光RGBW - 支持V2
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param red 红 0-255
 @param green 绿 0-255
 @param blue 蓝 0-255
 @param white 白 0-255
 */
+ (void)changeLightRGBW:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point red:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue white:(NSInteger)white;

/**
 修改灯光RGBW(扩展1) - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param type 0-RGBW 1-RGBWW 2-RGBACL
 @param red 红 0-255
 @param green 绿 0-255
 @param blue 蓝 0-255
 @param color1 白色/琥珀色 0-255
 @param color2 暖白/青色 0-255
 @param color3 青宁色 0-255
 */
+ (void)changeLightRGBW_Ex:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point type:(NSInteger)type red:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue color1:(NSInteger)color1 color2:(NSInteger)color2 color3:(NSInteger)color3;

/**
 修改灯光RGBW(扩展2) - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param type 0-RGBW 1-RGBWW 2-RGBACL
 @param red 红 0-65535
 @param green 绿 0-65535
 @param blue 蓝 0-65535
 @param color1 白色/琥珀色 0-65535
 @param color2 暖白/青色 0-65535
 @param color3 青宁色 0-65535
 */
+ (void)changeLightRGBW_Ex2:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point type:(NSInteger)type red:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue color1:(NSInteger)color1 color2:(NSInteger)color2 color3:(NSInteger)color3;

/**
 修改灯光CCT
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param temperature 色温
 @param gm V1色调，范围0~255（上层需要完成转换）
 @param circle 曲线模式 0-线性 1-S曲线 2-指数 3-对数
 @param v2gm V2色调，范围-128~127
 */
+ (void)changeLightCCT:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point temperature:(NSInteger)temperature gm:(NSInteger)gm circle:(NSInteger)circle v2gm:(NSInteger)v2gm;

/**
 修改灯光HSI
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param hue 色相 0-360
 @param sat 饱和度 0-100
 @param mode 显示模式 0-HSI 1-拾色器
 */
+ (void)changeLightHSI:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point hue:(NSInteger)hue sat:(NSInteger)sat mode:(NSInteger)mode;

/**
 修改灯光色卡 - 支持V2
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param brand 品牌 0-rosco 1-lee
 @param number 编号 0-255
 @param hue 色相微调 (-20)-(+20) 值为 0-40
 @param sat 饱和度微调 (-20)-(+20) 值为 0-40
 */
+ (void)changeLightCard:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point brand:(NSInteger)brand number:(NSInteger)number sat:(NSInteger)sat hue:(NSInteger)hue;

/**
 修改灯光色卡(扩展1) - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param brand 品牌 0-rosco 1-lee
 @param number 编号 0-65535
 @param temperature 色温 0-3200K 1-5600K
 @param hue 色相微调 (-20)-(+20) 值为 0-40
 @param sat 饱和度微调 (-20)-(+20) 值为 0-40
 */
+ (void)changeLightCard_Ex:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point brand:(NSInteger)brand number:(NSInteger)number temperature:(NSInteger)temperature sat:(NSInteger)sat hue:(NSInteger)hue;

/**
 修改灯光色卡(扩展2) - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param brand 品牌 0-rosco 1-lee
 @param number 编号 0-65535
 @param temperature 色温 0-3200K 1-5600K
 @param hue 色相微调 (-20)-(+20) 值为 0-40
 @param sat 饱和度微调 (-20)-(+20) 值为 0-40
 @param brandType 对应品牌的类别：0-4
 @param cardNumber 类中对应的色纸序号：0-255
 */
+ (void)changeLightCard_Ex2:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point brand:(NSInteger)brand number:(NSInteger)number temperature:(NSInteger)temperature sat:(NSInteger)sat hue:(NSInteger)hue brandType:(NSInteger)brandType cardNumber:(NSInteger)cardNumber;

/**
 修改灯光XY - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param X 0.xxxx的小数点后四位，需要转为整型
 @param Y 0.xxxx的小数点后四位，需要转为整型
 */
+ (void)changeLightXY:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point X:(NSInteger)X Y:(NSInteger)Y;

/**
 修改灯光XY(扩展) - 支持V3
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param X 0.xxxx的小数点后四位，需要转为整型
 @param Y 0.xxxx的小数点后四位，需要转为整型
 @param colorGamut 色域0-4
 */
+ (void)changeLightXY_Ex:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point X:(NSInteger)X Y:(NSInteger)Y colorGamut:(NSInteger)colorGamut;

/**
 修改灯光特效
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param symbol 底层唯一标识 0-13
 @param speed 速度档位 0,1,2
 */
+ (void)changeLightFX:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point symbol:(NSInteger)symbol speed:(NSInteger)speed;

/**
 修改灯光特效 - 闪光灯
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param trigger 触发方式 0-自动 1-手动
 @param mode 模式 0-闪光灯 1-镁光灯
 @param option 选项 0-CCT 1-HSI
 @param optionValue 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
 @param gm gm值
 */
+ (void)changeLightFX_Flash:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed trigger:(NSInteger)trigger mode:(NSInteger)mode option:(NSInteger)option optionValue:(NSInteger)optionValue gm:(NSInteger)gm;

/**
 修改灯光特效 - 雷闪电
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param frequency 频率 2-60次/分钟；随机：0
 @param trigger 触发方式 0-自动 1-手动
 @param twinkling 闪烁次数 1-10；随机：0
 @param temperature 色温 0-255/单位100K
 */
+ (void)changeLightFX_Lightning:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point frequency:(NSInteger)frequency trigger:(NSInteger)trigger twinkling:(NSInteger)twinkling temperature:(NSInteger)temperature;

/**
 修改灯光特效 - 多云
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100 随机-0
 @param lightDark 亮暗比例 10-90%
 */
+ (void)changeLightFX_Cloudy:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed lightDark:(NSInteger)lightDark;

/**
 修改灯光特效 - 坏灯泡
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param option 选项 0-CCT 1-HSI
 @param optionValue 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
 @param gm gm值
 */
+ (void)changeLightFX_BrokenBulb:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed option:(NSInteger)option optionValue:(NSInteger)optionValue gm:(NSInteger)gm;

/**
 修改灯光特效 - 电视机
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param option 选项 0-CCT 1-HSI
 */
+ (void)changeLightFX_TV:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed option:(NSInteger)option;

/**
 修改灯光特效 - 蜡烛
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 */
+ (void)changeLightFX_Candle:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed;

/**
 修改灯光特效 - 火
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 */
+ (void)changeLightFX_Fire:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed;

/**
 修改灯光特效 - 烟花
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param ember 余烬 1-100
 */
+ (void)changeLightFX_Firework:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed ember:(NSInteger)ember;

/**
 修改灯光特效 - 爆炸
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param ember 余烬 1-100
 @param trigger 触发方式 0-自动 1-手动
 @param option 选项 0-CCT 1-HSI
 @param optionValue 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
 @param gm gm值
 */
+ (void)changeLightFX_Explode:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed ember:(NSInteger)ember trigger:(NSInteger)trigger option:(NSInteger)option optionValue:(NSInteger)optionValue gm:(NSInteger)gm;

/**
 修改灯光特效 - 焊接
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param option 选项 0-CCT 1-HSI
 @param optionValue 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
 @param gm gm值
 */
+ (void)changeLightFX_Welding:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed option:(NSInteger)option optionValue:(NSInteger)optionValue gm:(NSInteger)gm;

/**
 修改灯光特效 - 警车
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param mode 模式 1-5
 @param color 颜色组合 0-7
 */
+ (void)changeLightFX_PoliceCar:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point mode:(NSInteger)mode color:(NSInteger)color;

/**
 修改灯光特效 - SOS
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param option 选项 0-CCT 1-HSI
 @param optionValue 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
 @param gm gm值
 */
+ (void)changeLightFX_SOS:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point  option:(NSInteger)option optionValue:(NSInteger)optionValue gm:(NSInteger)gm;

/**
 修改灯光特效 - 彩光循环
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param sat 饱和度 0-100
 */
+ (void)changeLightFX_RGBCycle:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed sat:(NSInteger)sat;

/**
 修改灯光特效 - 激光彩灯
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param sat 饱和度 0-100
 */
+ (void)changeLightFX_Laser:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed sat:(NSInteger)sat;

/**
 修改灯光特效 - 彩光渐入
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param direction 方向 0-向左 1-向右 2-双向
 @param colorLength 颜色长度 1-8
 @param backgroundModel 背景色
 @param colorBlockList 色块属性列表
 */
+ (void)changeLightFX_RGBFadeIn:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed direction:(NSInteger)direction colorLength:(NSInteger)colorLength background:(FDSColorBlockModel *)backgroundModel colorBlockList:(NSArray<FDSColorBlockModel*> *)colorBlockList;

/**
 修改灯光特效 - 彩光流动
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param direction 方向 0-向左 1-向右 2-双向
 @param colorLength 颜色长度 1-8
 @param colorBlockList 色块属性列表
 */
+ (void)changeLightFX_RGBFlow:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed direction:(NSInteger)direction colorLength:(NSInteger)colorLength colorBlockList:(NSArray<FDSColorBlockModel*> *)colorBlockList;

/**
 修改灯光特效 - 彩光追逐
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param speed 速度 1-100
 @param direction 方向 0-向左 1-向右 2-双向
 @param mode 模式 0-渐变 1-闪烁 2-静止
 @param colorLength 颜色长度 1-8
 @param colorBlockList 色块属性列表
 */
+ (void)changeLightFX_RGBChase:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point speed:(NSInteger)speed direction:(NSInteger)direction mode:(NSInteger)mode colorLength:(NSInteger)colorLength colorBlockList:(NSArray<FDSColorBlockModel*> *)colorBlockList;

/**
 修改灯光特效 - 音乐
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param mode 模式 0-1
 */
+ (void)changeLightFX_Music:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point mode:(NSInteger)mode;

/**
 修改灯光特效 - 像素火
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param hue 色调 0-2
 @param speed 速度 1-100
 */
+ (void)changeLightFX_PixelFire:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point hue:(NSInteger)hue speed:(NSInteger)speed;

/**
 修改灯光特效 - 像素蜡烛
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param hue 色调 0-2
 @param speed 速度 1-100
 */
+ (void)changeLightFX_PixelCandle:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point hue:(NSInteger)hue speed:(NSInteger)speed;

/**
 修改灯光特效 - 彩虹
 
 @param address 设备地址
 @param brightness 亮度 0-100
 @param brightness_point 小数点后亮度 0-9
 @param pixelCount 像素数
 @param colorLength 颜色长度 1-4
 @param speed 速度 1-100
 @param direction 方向 0-向左 1-向右 2-双向
 @param backgroundModel 背景色（注意有亮度参数）
 @param colorBlockList 色块属性列表（注意没有亮度参数）
 */
+ (void)changeLightFX_Rainbow:(UInt16)address brightness:(NSInteger)brightness brightness_point:(NSInteger)brightness_point pixelCount:(NSInteger)pixelCount colorLength:(NSInteger)colorLength speed:(NSInteger)speed direction:(NSInteger)direction background:(FDSRainbowColorBlockModel *)backgroundModel colorBlockList:(NSArray<FDSRainbowColorBlockModel*> *)colorBlockList;

/**
 滑竿滑动过程中，是否能够修改设备灯光数据
（滑竿滑动过程中使用该接口判断可以避免设备丢包，提高同步率）
 
 @return YES表示可以修改，NO表示不能修改
 */
+ (BOOL)isEnableChangeData;

@end

NS_ASSUME_NONNULL_END
