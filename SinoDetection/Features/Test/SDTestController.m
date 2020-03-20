//
//  SDTestController.m
//  SinoDetection
//
//  Created by yangmengqi on 2019/11/26.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDTestController.h"
#import "SDCommandController.h"
#import <SinoDetection/SDBluetoothManager.h>
#import <SinoDetection/SDDeviceManager.h>
#import <SinoDetection/NSDate+SDAddition.h>
#import <SinoDetection/SDDetectionDataModel.h>

static NSString * const kTCState = @"kTCState";
static NSString * const kTCBoundDevice = @"kTCBoundDevice";
static NSString * const kTCTime = @"kTCTime";
static NSString * const kTCData = @"kTCData";

@interface SDTestController () <UITableViewDataSource, UITableViewDelegate>
/// 连接状态视图
@property (weak, nonatomic) IBOutlet UITableView *stateView;
/// 测量数据视图
@property (weak, nonatomic) IBOutlet UITableView *dataView;
@property (nonatomic, strong) NSMutableArray *states;
@property (nonatomic, strong) NSMutableArray *datas;
@end

@implementation SDTestController

- (instancetype)initWithCoder:(NSCoder *)coder
{
    self = [super initWithCoder:coder];
    if (self) {
        _states = [NSMutableArray arrayWithCapacity:0];
        _datas = [NSMutableArray arrayWithCapacity:0];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"测量";
    [[SDBluetoothManager sharedBluetoothManager] connectDevices];
    __weak typeof(self) weakSelf = self;
    [SDBluetoothManager sharedBluetoothManager].didReceiveData = ^(SDDetectionDataModel * _Nullable data, SDBussinessStateModel * _Nullable state, SDDeviceModel * _Nonnull boundDevice) {
        __weak typeof(self) strongSelf = weakSelf;
        NSString *time = [[NSDate date] stringWithFormat:@"yyyy-MM-dd HH:mm:ss"];
        if (state) {
            NSMutableDictionary *dict = [NSMutableDictionary new];
            dict[kTCState] = state;
            dict[kTCBoundDevice] = boundDevice;
            dict[kTCTime] = time;
            [strongSelf.states insertObject:[dict copy] atIndex:0];
            [strongSelf.stateView reloadData];
        }
        if (data) {
            NSMutableDictionary *dict = [NSMutableDictionary new];
            dict[kTCData] = data;
            dict[kTCBoundDevice] = boundDevice;
            dict[kTCTime] = time;
            [strongSelf.datas insertObject:dict atIndex:0];
            [strongSelf.dataView reloadData];
        }
    };
}

- (void)dealloc {
    [[SDBluetoothManager sharedBluetoothManager] disconnectDevices];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"SDCommandSegue"]) {
        UINavigationController *navController = segue.destinationViewController;
        SDCommandController *controller = navController.viewControllers.firstObject;
        controller.writeCommand = ^(SDCCommandType command, NSString * _Nullable content, SDDeviceModel * _Nonnull boundDevice) {
            [[SDBluetoothManager sharedBluetoothManager] writeCommand:command content:content boundDevice:boundDevice];
        };
    }
}

#pragma mark - UIButton Methods
- (IBAction)clearStateLogButtonClicked:(UIButton *)clearStateLogButton {
    [_states removeAllObjects];
    [_stateView reloadData];
}

- (IBAction)clearDataLogButtonClicked:(UIButton *)clearDataLogButton {
    [_datas removeAllObjects];
    [_dataView reloadData];
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (tableView == _stateView) {
        return _states.count;
    } else if (tableView == _dataView) {
        return _datas.count;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    NSString *identifer;
    if (tableView == _stateView) {
        identifer = @"SDConnectStateCell";
    } else {
        identifer = @"SDTestDataCell";
    }
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifer forIndexPath:indexPath];
    if (tableView == _stateView) {
        NSDictionary *dict = _states[indexPath.row];
        SDDeviceModel *boundDevice = dict[kTCBoundDevice];
        SDBussinessStateModel *state = dict[kTCState];
        UILabel *textLabel = [cell.contentView viewWithTag:1000];
        textLabel.text = [NSString stringWithFormat:@"%@（%@）", boundDevice.name, state.desc];
        textLabel = [cell.contentView viewWithTag:1001];
        NSString *tmp;
        if (boundDevice.formattedMac.length > 0) {
            tmp = boundDevice.formattedMac;
        } else if (boundDevice.uuid.length > 0) {
            tmp = boundDevice.uuid;
        }
        textLabel.text = [NSString stringWithFormat:@"%@", tmp];
        textLabel = [cell.contentView viewWithTag:1002];
        textLabel.text = [NSString stringWithFormat:@" %@", dict[kTCTime]];
    } else if (tableView == _dataView) {
        NSDictionary *dict = _datas[indexPath.row];
        SDDeviceModel *boundDevice = dict[kTCBoundDevice];
        SDDetectionDataModel *data = dict[kTCData];
        UILabel *textLabel = [cell.contentView viewWithTag:1000];
        textLabel.text = [data description];
        // !!!: 举例取安稳+Air的数据
        if (boundDevice.type == SDCDeviceTypeAnWenAir) {
            SDAnWenAirDataModel *anWenAirData = (SDAnWenAirDataModel *)data.data;
            NSLog(@"anWenAirData=%@", anWenAirData);
        }
        textLabel = [cell.contentView viewWithTag:1001];
        NSString *tmp;
        if (boundDevice.formattedMac.length > 0) {
            tmp = boundDevice.formattedMac;
        } else if (boundDevice.uuid.length > 0) {
            tmp = boundDevice.uuid;
        }
        textLabel.text = [NSString stringWithFormat:@"%@", tmp];
        textLabel = [cell.contentView viewWithTag:1002];
        textLabel.text = [NSString stringWithFormat:@" %@", dict[kTCTime]];
    }
    return cell;
}

#pragma mark - UITableViewDelegate
//- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
//    return 0;
//}
@end
