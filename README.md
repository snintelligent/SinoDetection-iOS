# SinoDetection-iOS
SinoDetection.framework是三诺生物传感股份有限公司开发的指标检测SDK，目前已接入3款检测设备，可以便捷的实现多款蓝牙设备的同时连接与数据接收，极大的简化了蓝牙设备的接入流程，接入用户只需要专注自身业务的开发，降低了用户接入蓝牙设备的开发成本。同时我们会为接入用户提供对应的技术支持，及时的响应用户需求。
# 如何集成
### 申请AppKey
请提供Bundle Id，联系我们，获取AppKey。
### 集成SDK
#### 手动导入SDK
下载[SinoDetection.framework]()，拖入到工程中。
#### 依赖的第三方库
需要通过CocoaPods依赖第三方库，如下：
```
pod 'AFNetworking', '3.2.1'
pod 'LKDBHelper', '2.5.3'
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
* WL-1型血糖仪
* 真睿2代血糖仪。
