//
//  SDDeviceTypeController.m
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDDeviceTypeController.h"
#import "SDScanDeviceController.h"
#import <SinoDetection/SDDeviceManager.h>

@interface SDDeviceTypeController () <UITableViewDataSource, UITableViewDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation SDDeviceTypeController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"选择设备类型";
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
//    NSLog(@"segue=%@\nsender=%@", segue, sender);
    if ([segue.identifier isEqualToString:@"SDScanDeviceSegue"]) {
        SDScanDeviceController *controller = segue.destinationViewController;
        UITableViewCell *cell = sender;
        controller.title = cell.textLabel.text;
        NSIndexPath *indexPath = [self.tableView indexPathForCell:cell];
        SDDeviceModel *supportDevice = [SDDeviceManager sharedDeviceManager].supportedDevices[indexPath.row];
        controller.scannedType = supportDevice.type;
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [SDDeviceManager sharedDeviceManager].supportedDevices.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifer = @"SDDeviceTypeCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifer forIndexPath:indexPath];
    SDDeviceModel *supportedDevice = [SDDeviceManager sharedDeviceManager].supportedDevices[indexPath.row];
//    NSLog(@"supportedDevice=%@", supportedDevice);
    cell.textLabel.text = [NSString stringWithFormat:@"%@-%@", supportedDevice.name, supportedDevice.bluetoothName];
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}
@end
