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
@property (weak, nonatomic) IBOutlet UIView *timeMaskView;
@property (weak, nonatomic) IBOutlet UIView *timeContentView;
@property (weak, nonatomic) IBOutlet NSLayoutConstraint *vsc_timeContentView_superView;
@property (weak, nonatomic) IBOutlet UIDatePicker *timePicker;
@property (nonatomic, strong) NSArray *correctCodes;
@property (nonatomic, assign) NSIndexPath *indexPath;
@property (nonatomic, strong) NSArray<SDDeviceModel *> *filteredDevices;
@end

@implementation SDCommandController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.title = @"写命令";
    [self setupCorrectCodes];
    [self setupFilteredDevices];
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
    NSString *correctCode = [_correctCodes[row] stringValue];
    SDDeviceModel *boundDevice = _filteredDevices[_indexPath.section];
    NSDictionary *writeCommand = boundDevice.writeCommands[_indexPath.row];
    SDCCommandType writeCmd = [writeCommand[SDCWriteCommandType] unsignedIntegerValue];
    if (_writeCommand) {
        _writeCommand(writeCmd, correctCode, boundDevice);
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
    return _correctCodes.count;
}

#pragma mark - UIPickerViewDelegate
- (NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return [_correctCodes[row] stringValue];
}
@end
