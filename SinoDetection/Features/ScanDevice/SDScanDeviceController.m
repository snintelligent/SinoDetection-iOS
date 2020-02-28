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
    cell.detailTextLabel.text = scannedDevice.formattedMac;
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    // FIXME: 每种类型的设备应该只绑定一台
    SDDeviceModel *scannedDevice = [SDDeviceManager sharedDeviceManager].scannedDevices[indexPath.row];
    [[SDDeviceManager sharedDeviceManager] addBoundDevice:scannedDevice];
    [self.navigationController popToRootViewControllerAnimated:YES];
}
@end
