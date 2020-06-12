//
//  SDCommandController.m
//  SinoDetection
//
//  Created by yangmengqi on 2019/12/24.
//  Copyright © 2019 Sinocare Inc. All rights reserved.
//

#import "SDCommandController.h"
#import <SinoDetection/SDDeviceManager.h>
#import <SinoDetection/NSDate+SDAddition.h>

@interface SDCommandController () <UITableViewDataSource, UITableViewDelegate, UIPickerViewDataSource, UIPickerViewDelegate>
@property (weak, nonatomic) IBOutlet UIView *ccMaskView;
@property (weak, nonatomic) IBOutlet UIView *ccContentView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *vsc_ccContentView_superView;
@property (weak, nonatomic) IBOutlet UIPickerView *ccPickerView;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *ccBarButtonItem;
@property (weak, nonatomic) IBOutlet UIView *timeMaskView;
@property (weak, nonatomic) IBOutlet UIView *timeContentView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *vsc_timeContentView_superView;
@property (weak, nonatomic) IBOutlet UIDatePicker *timePicker;
@property (nonatomic, strong) NSArray *correctCodes;
@property (nonatomic, assign) NSIndexPath *indexPath;
@property (nonatomic, strong) NSArray<SDDeviceModel *> *filteredDevices;
@property (nonatomic, strong) NSArray *goldAQDataTypes;
@property (nonatomic, strong) NSArray *uG11ReadDataTypes;
@property (nonatomic, strong) NSArray *uG11ClearDataTypes;
@end

@implementation SDCommandController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"写命令";
    [self setupCorrectCodes];
    [self setupFilteredDevices];
    [self setupDataTypes];
}

- (void)dealloc {
    NSLog(@"");
}

#pragma mark - Private Methods
- (void)setupCorrectCodes {
    NSMutableArray *correctCodes = [NSMutableArray arrayWithCapacity:0];
    for (NSInteger i = 1; i <= 40; i++) {
        [correctCodes addObject:@(i)];
    }
    _correctCodes = [correctCodes copy];
}

- (void)showCorrectCodeView {
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (writeCmd == SDCCommandTypeSetCorrectCode) {
        _ccBarButtonItem.title = @"设置验证码";
    } else if (boundDevice.type == SDCDeviceTypeGoldAQ
               || boundDevice.type == SDCDeviceTypeGoldAQAir
               || boundDevice.type == SDCDeviceTypeUG11) {
        if (writeCmd == SDCCommandTypeReadHistoryData) {
            _ccBarButtonItem.title = @"读历史数据";
        } else if (writeCmd == SDCCommandTypeClearHistoryData) {
            _ccBarButtonItem.title = @"清历史数据";
        }
    }
    [_ccPickerView reloadAllComponents];
    [_ccPickerView selectRow:0 inComponent:0 animated:NO];
    _ccMaskView.hidden = NO;
    _ccMaskView.layer.backgroundColor = [UIColor clearColor].CGColor;
    _vsc_ccContentView_superView.constant = -CGRectGetHeight(_ccContentView.bounds);
    [_ccMaskView layoutIfNeeded];
    [UIView animateWithDuration:0.25 animations:^{
        _ccMaskView.layer.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.75].CGColor;
        _vsc_ccContentView_superView.constant = 0;
        [_ccMaskView layoutIfNeeded];
    }];
}

- (void)hideCorrectCodeView {
    _ccMaskView.layer.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.75].CGColor;
    _vsc_ccContentView_superView.constant = 0;
    [_ccMaskView layoutIfNeeded];
    [UIView animateWithDuration:0.25 animations:^{
        _ccMaskView.layer.backgroundColor = [UIColor clearColor].CGColor;
        _vsc_ccContentView_superView.constant = -CGRectGetHeight(_ccContentView.bounds);
        [_ccMaskView layoutIfNeeded];
    } completion:^(BOOL finished) {
        _ccMaskView.hidden = YES;
    }];
}

- (void)showTimeView {
    [_timePicker setDate:[NSDate date] animated:NO];
    _timeMaskView.hidden = NO;
    _timeMaskView.layer.backgroundColor = [UIColor clearColor].CGColor;
    _vsc_timeContentView_superView.constant = -CGRectGetHeight(_timeContentView.bounds);
    [_timeMaskView layoutIfNeeded];
    [UIView animateWithDuration:0.25 animations:^{
        _timeMaskView.layer.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.75].CGColor;
        _vsc_timeContentView_superView.constant = 0;
        [_timeMaskView layoutIfNeeded];
    }];
}

- (void)hideTimeView {
    _timeMaskView.layer.backgroundColor = [[UIColor blackColor] colorWithAlphaComponent:0.75].CGColor;
    _vsc_timeContentView_superView.constant = 0;
    [_timeMaskView layoutIfNeeded];
    [UIView animateWithDuration:0.25 animations:^{
        _timeMaskView.layer.backgroundColor = [UIColor clearColor].CGColor;
        _vsc_timeContentView_superView.constant = -CGRectGetHeight(_timeContentView.bounds);
        [_timeMaskView layoutIfNeeded];
    } completion:^(BOOL finished) {
        _timeMaskView.hidden = YES;
    }];
}

- (void)setupFilteredDevices {
    NSMutableArray *filteredDevices = [NSMutableArray arrayWithCapacity:0];
    for (SDDeviceModel *boundDevice in [SDDeviceManager sharedDeviceManager].boundDevices) {
        if (boundDevice.writeCommands.count > 0) {
            [filteredDevices addObject:boundDevice];
        }
    }
    self.filteredDevices = [filteredDevices copy];
}

- (void)setupDataTypes {
    NSMutableArray *dataTypes = [NSMutableArray arrayWithCapacity:0];
    [dataTypes addObject:@(SDCDataTypeBloodSugar)];
    [dataTypes addObject:@(SDCDataTypeBloodSugarQC)];
    self.goldAQDataTypes = [dataTypes copy];
    [dataTypes addObject:@(SDCDataTypeUricAcid)];
    [dataTypes addObject:@(SDCDataTypeUricAcidQC)];
    self.uG11ReadDataTypes = [dataTypes copy];
    [dataTypes addObject:@(SDCDataTypeAll)];
    self.uG11ClearDataTypes = [dataTypes copy];
}

#pragma mark - Gesture Methods
- (IBAction)correctCodeViewTapped:(UITapGestureRecognizer *)tap {
    [self hideCorrectCodeView];
}

- (IBAction)timeViewTapped:(UITapGestureRecognizer *)tap {
    [self hideTimeView];
}

#pragma mark - UIBarButtonItem Methods
- (IBAction)cancelBarButtonItemClicked:(UIBarButtonItem *)cancelBarButtonItem {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (IBAction)ccCancelBarButtonItemClicked:(UIBarButtonItem *)ccCancelBarButtonItem {
    [self hideCorrectCodeView];
}

- (IBAction)ccDoneBarButtonItemClicked:(UIBarButtonItem *)ccDoneBarButtonItem {
    [self dismissViewControllerAnimated:YES completion:nil];
    NSInteger row = [_ccPickerView selectedRowInComponent:0];
    NSString *content;
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (writeCmd == SDCCommandTypeSetCorrectCode) {
         content = [_correctCodes[row] stringValue];
    } else if (writeCmd == SDCCommandTypeReadHistoryData
                || writeCmd == SDCCommandTypeClearHistoryData) {
        if (boundDevice.type == SDCDeviceTypeGoldAQ
            || boundDevice.type == SDCDeviceTypeGoldAQAir) {
            content = [NSString stringWithFormat:@"%@", _goldAQDataTypes[row]];
        } else if (boundDevice.type == SDCDeviceTypeUG11) {
            if (writeCmd == SDCCommandTypeReadHistoryData) {
                content = [NSString stringWithFormat:@"%@", _uG11ReadDataTypes[row]];
            } else {
                content = [NSString stringWithFormat:@"%@", _uG11ClearDataTypes[row]];
            }
        }
    }
    if (_writeCommand) {
        _writeCommand(writeCmd, content, boundDevice);
    }
}

- (IBAction)timeCancelBarButtonItemClicked:(UIBarButtonItem *)timeCancelBarButtonItem {
    [self hideTimeView];
}

- (IBAction)timeDoneBarButtonItemClicked:(UIBarButtonItem *)timeDoneBarButtonItem {
    [self dismissViewControllerAnimated:YES completion:nil];
    NSString *time = [_timePicker.date stringWithFormat:@"yyyy-MM-dd HH:mm:ss"];
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (_writeCommand) {
        _writeCommand(writeCmd, time, boundDevice);
    }
}

#pragma mark - UITableViewDataSource
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return _filteredDevices.count;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return _filteredDevices[section].writeCommands.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    static NSString *identifer = @"SDCommandCell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifer forIndexPath:indexPath];
    SDDeviceModel *boundDevice = _filteredDevices[indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[indexPath.row];
    cell.textLabel.text = writeCommand[SDCWriteCommandDescription];
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    SDDeviceModel *boundDevice = _filteredDevices[section];
    NSString *tmp;
    if (boundDevice.formattedMac.length > 0) {
        tmp = boundDevice.formattedMac;
    } else if (boundDevice.uuid.length > 0) {
        tmp = boundDevice.uuid;
    }
    return [NSString stringWithFormat:@"%@-%@ %@", boundDevice.name, boundDevice.bluetoothName, tmp];
}

#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    self.indexPath = indexPath;
    SDDeviceModel *boundDevice = _filteredDevices[indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (writeCmd == SDCCommandTypeSetCorrectCode) {
        [self showCorrectCodeView];
        return;
    } else if (writeCmd == SDCCommandTypeSetTime) {
        [self showTimeView];
        return;
    } else if ((writeCmd == SDCCommandTypeReadHistoryData
                || writeCmd == SDCCommandTypeClearHistoryData)
              && (boundDevice.type == SDCDeviceTypeGoldAQ
                  || boundDevice.type == SDCDeviceTypeGoldAQAir
                  || boundDevice.type == SDCDeviceTypeUG11)) {
        [self showCorrectCodeView];
        return;
    }
    [self dismissViewControllerAnimated:YES completion:nil];
    if (_writeCommand) {
        _writeCommand(writeCmd, nil, boundDevice);
    }
}

#pragma mark - UIPickerViewDataSource
- (NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component {
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (writeCmd == SDCCommandTypeReadHistoryData
         || writeCmd == SDCCommandTypeClearHistoryData) {
        if (boundDevice.type == SDCDeviceTypeGoldAQ
            || boundDevice.type == SDCDeviceTypeGoldAQAir) {
            return _goldAQDataTypes.count;
        } else if (boundDevice.type == SDCDeviceTypeUG11) {
            if (writeCmd == SDCCommandTypeReadHistoryData) {
                return _uG11ReadDataTypes.count;
            } else {
                return _uG11ClearDataTypes.count;
            }
        }
    }
    return _correctCodes.count;
}

#pragma mark - UIPickerViewDelegate
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (writeCmd == SDCCommandTypeReadHistoryData
        || writeCmd == SDCCommandTypeClearHistoryData) {
        NSMutableString *title = [NSMutableString stringWithCapacity:0];
        if (writeCmd == SDCCommandTypeReadHistoryData) {
            [title appendString:@"读"];
        } else {
            [title appendString:@"清"];
        }
        SDCDataType dataType = SDCDataTypeUnknown;
        if (boundDevice.type == SDCDeviceTypeGoldAQ
            || boundDevice.type == SDCDeviceTypeGoldAQAir) {
            dataType = [_goldAQDataTypes[row] unsignedIntegerValue];
        } else if (boundDevice.type == SDCDeviceTypeUG11) {
            if (writeCmd == SDCCommandTypeReadHistoryData) {
                dataType = [_uG11ReadDataTypes[row] unsignedIntegerValue];
            } else {
                dataType = [_uG11ClearDataTypes[row] unsignedIntegerValue];
            }
        }
        if (dataType == SDCDataTypeBloodSugar) {
            [title appendString:@"血糖历史数据"];
        } else if (dataType == SDCDataTypeBloodSugarQC) {
            [title appendString:@"血糖质控历史数据"];
        } else if (dataType == SDCDataTypeUricAcid) {
            [title appendString:@"尿酸历史数据"];
        } else if (dataType == SDCDataTypeUricAcidQC) {
            [title appendString:@"尿酸质控历史数据"];
        } else if (dataType == SDCDataTypeAll) {
            [title appendString:@"所有历史数据"];
        } else {
            [title appendString:@"历史数据"];
        }
        return [title copy];
    }
    return [_correctCodes[row] stringValue];
}
@end
