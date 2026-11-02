//
//  FDSColorBlockModel.h
//  FDSMeshLib
//
//  Created by LEIPENG on 2022/7/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FDSRainbowColorBlockModel : NSObject

// 色温
@property (nonatomic, assign) NSInteger temperature;

// 叠化 0-100
@property (nonatomic, assign) NSInteger pile;

// 色相 0-360
@property (nonatomic, assign) NSInteger hue;

// 饱和度 0-100
@property (nonatomic, assign) NSInteger sat;

// 亮度 0-100
@property (nonatomic, assign) NSInteger brightness;

// 初始化
- (id)initWithTemperature:(NSInteger)temperature pile:(NSInteger)pile hue:(NSInteger)hue sat:(NSInteger)sat brightness:(NSInteger)brightness;
- (id)initWithTemperature:(NSInteger)temperature pile:(NSInteger)pile hue:(NSInteger)hue sat:(NSInteger)sat;

@end

@interface FDSColorBlockModel : NSObject

// 选项 0-CCT 1-HSI 2-黑色(0xFF)
@property (nonatomic, assign) NSInteger option;

// 选项option为0时传色温（0-255/单位100K），option为1时传色相（0-360）
@property (nonatomic, assign) NSInteger optionValue;

// 饱和度 0-100
@property (nonatomic, assign) NSInteger sat;

// 初始化
- (id)initWithOption:(NSInteger)option optionValue:(NSInteger)optionValue sat:(NSInteger)sat;

@end

NS_ASSUME_NONNULL_END
