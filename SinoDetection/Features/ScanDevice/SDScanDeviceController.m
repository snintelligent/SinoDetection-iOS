//
//  SDScanDeviceController.m
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDScanDeviceController.h"
#import <SinoDetection/SDBluetoothManager.h>
#import <SinoDetection/SDDeviceManager.h>

@interface SDScanDeviceController () <UITableViewDataSource, UITableViewDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation SDScanDeviceController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [[SDBluetoothManager sharedBluetoothManager] scanWithDeviceType:_scannedType];
    __weak typeof(self) weakSelf = self;
    [SDDeviceManager sharedDeviceManager].didUpdateScannedDevices = ^(NSArray<SDDeviceModel *> * _Nonnull scannedDevices) {
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf.tableView reloadData];
    };
}

- (void)dealloc {
    [[SDBluetoothManager sharedBluetoothManager] stopScan];
}

#pragma mark - UIButton Methods
- (IBAction)rescanButtonClicked:(UIButton *)rescanButton {
    [[SDBluetoothManager sharedBluetoothManager] rescan];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [SDDeviceManager sharedDeviceManager].scannedDevices.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifer = @"SDScanDeviceCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifer forIndexPath:indexPath];
    SDDeviceModel *scannedDevice = [SDDeviceManager sharedDeviceManager].scannedDevices[indexPath.row];
    cell.textLabel.text = scannedDevice.idName?:@"未命名";
    NSString *tmp;
    if (scannedDevice.formattedMac.length > 0) {
        tmp = scannedDevice.formattedMac;
    } else if (scannedDevice.uuid.length > 0) {
        tmp = scannedDevice.uuid;
    }
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@", tmp];
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    SDDeviceModel *scannedDevice = [SDDeviceManager sharedDeviceManager].scannedDevices[indexPath.row];
    // 根据idName判断类型，并更新设备对象
    if ([scannedDevice.idName containsString:@"SLX120"]) {
        scannedDevice.type = SDCDeviceTypeSLX120;
        scannedDevice.name = @"掌越";
    } else if ([scannedDevice.idName containsString:@"BDE_WEIXIN_TTM"]) {
        scannedDevice.type = SDCDeviceTypeUG11;
        scannedDevice.name = @"UG-11 Code";
    }
    [[SDDeviceManager sharedDeviceManager] addBoundDevice:scannedDevice];
    [self.navigationController popToRootViewControllerAnimated:YES];
}
@end
