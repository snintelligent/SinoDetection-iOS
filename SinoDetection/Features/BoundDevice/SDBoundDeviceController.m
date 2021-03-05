//
//  SDBoundDeviceController.m
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/21.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDBoundDeviceController.h"
#import "SDDeviceTypeController.h"
#import <SinoDetection/SDAuthManager.h>
#import <SinoDetection/SDBluetoothManager.h>
#import <SinoDetection/SDDeviceManager.h>
#import <SinoDetection/SDReportManager.h>

// Debug SDK环境
//#define SDAppKey @"ec58a59bd315a4f39d041dc81d7ec47b"
// Release SDK环境
#define SDAppKey @"edef02939ad62a41f31b9032a3734646"

@interface SDBoundDeviceController () <UITableViewDataSource, UITableViewDelegate>
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@end

@implementation SDBoundDeviceController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"已绑定设备列表（左滑删除）";
    
    NSString *bundleId = [[NSBundle mainBundle] infoDictionary][@"CFBundleIdentifier"];
    [[SDAuthManager sharedAuthManager] authWithAppKey:SDAppKey bundleId:bundleId];
    __weak typeof(self) weakSelf = self;
    [SDDeviceManager sharedDeviceManager].didUpdateBoundDevices = ^(NSArray<SDDeviceModel *> * _Nonnull boundDevices) {
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf.tableView reloadData];
    };
    [SDBluetoothManager sharedBluetoothManager].didReceiveMac = ^(NSString * _Nullable mac, SDDeviceModel * _Nonnull boundDevice) {
        __strong typeof(self) strongSelf = weakSelf;
        [strongSelf.tableView reloadData];
    };
}

#pragma mark - UIButton Methods
- (IBAction)testButtonClicked:(UIButton *)testButton {
    if ([SDDeviceManager sharedDeviceManager].boundDevices.count == 0) {
        NSLog(@"请先绑定设备");
        return;
    }
    [self performSegueWithIdentifier:@"SDTestSegue" sender:testButton];
}

#pragma mark - UIBarButtonItem Methods
- (IBAction)generateReportItemClicked:(UIBarButtonItem *)generateReportItem {
    // @{"name": "ztest", "sex": "1", "birthday": "1991-02-15", "uid":"13512445669", "foodStatus":1, "heightResult":66, "weightResult": "88", "bmi": "4", "glu": "4"}
    NSDictionary *params = @{@"uid": @"13512445669", @"name": @"ztest", @"sex": @"1",
                             @"birthday": @"1991-02-15", @"foodStatus": @"1", @"glu": @"4"};
    [SDReportManager generateReportWithParams:params completion:^(NSString * _Nullable h5Url) {
        if (h5Url.length == 0) {
            NSLog(@"h5链接为空");
            return;
        }
        NSURL *url = [NSURL URLWithString:h5Url];
        [[UIApplication sharedApplication] openURL:url];
    }];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [SDDeviceManager sharedDeviceManager].boundDevices.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifer = @"SDBoundDeviceCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifer forIndexPath:indexPath];
    SDDeviceModel *boundDevice = [SDDeviceManager sharedDeviceManager].boundDevices[indexPath.row];
    cell.textLabel.text = [NSString stringWithFormat:@"%@-%@", boundDevice.name, boundDevice.bluetoothName];
    NSString *tmp;
    if (boundDevice.formattedMac.length > 0) {
        tmp = boundDevice.formattedMac;
    } else if (boundDevice.uuid.length > 0) {
        tmp = boundDevice.uuid;
    }
    cell.detailTextLabel.text = [NSString stringWithFormat:@"%@", tmp];
    return cell;
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath {
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        [[SDDeviceManager sharedDeviceManager] removeBoundDeviceAtIndex:indexPath.row];
    }
}
@end
