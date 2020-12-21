# SinoDetection-iOS
SinoDetection.framework是三诺生物传感股份有限公司开发的指标检测SDK，可以便捷的实现多款蓝牙设备的同时连接与数据接收，极大的简化了蓝牙设备的接入流程，接入用户只需要专注自身业务的开发，降低了用户接入蓝牙设备的开发成本。同时我们会为接入用户提供对应的技术支持，及时的响应用户需求。
# 如何集成
### 申请AppKey
请提供Bundle Id，联系我们，获取AppKey。
### 集成SDK
#### 手动导入SDK
下载[SinoDetection.framework](https://github.com/snintelligent/SinoDetection-iOS/releases/download/1.7.0/SinoDetection.framework.zip)，拖入到工程中。
#### 依赖的第三方库
需要通过CocoaPods依赖第三方库，如下：
```
pod 'AFNetworking', '4.0.1'
pod 'LKDBHelper', '2.5.3'
pod 'ProtocolBuffers', '1.9.11'
```
#### 项目配置
在Build Settings下的Other Link Flags中添加`-ObjC`。
# 使用说明
请参考SinoDetection-iOS项目的代码。
# 最低要求
* iOS 9+
* 蓝牙4.0+
# 支持的设备
* 安稳+Air血糖仪
* 蓝牙WL-1型血糖仪
* 真睿2代血糖仪
* EA-12型血糖尿酸测试仪
* EA-18型血糖尿酸测试仪
* 卡迪克干式生化分析仪
* 掌越血脂血糖仪
* 金准+血糖仪
* 金准+Air血糖仪
* UG-11 Code血糖尿酸测试仪
* 脉搏波臂式血压计
* PCH-100便携式糖化血红蛋白分析仪
* 脉搏波台式血压计
* 爱立康RLF-A1红外额温计
* 体重秤
* 呼吸家
* 安诺心血压计
* 美心温度和脉搏血氧仪
* 蓝牙WL-1型血糖仪（微信版）
* 脉搏波血压计（RBP-9804）
