//
//  LCYPassCodeEditorViewController.h
//  LockScreen
//
//  Created by Krishna Kotecha on 22/11/2010.
//   Copyright 2010 Krishna Kotecha. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "LCYPasscodeUIStateMachine.h"
#import "LCYPasscodeInputViewController.h"

@class LCYPassCodeEditorViewController;
@class LCYChangePasscodeStateMachine;
@class LCYTurnOffPasscodeStateMachine;
@class LCYSetPasscodeStateMachine;

@protocol LCYPassCodeEditorDelegate <NSObject>
- (void) passcodeEditor: (LCYPassCodeEditorViewController *) passcodeEditor newCode:(NSString *) newCode;
@end

@interface LCYPassCodeEditorViewController : LCYPasscodeInputViewController
{
	id<LCYPassCodeEditorDelegate> delegate_;
	
	UIView *digitsContainerView_;

	UILabel *promptLabel_;
	UILabel *errorLabel_;
	
	NSString *passCode_;
	BOOL acceptInput_;
	LCYPasscodeUIStateMachine *stateMachine_;
	
	LCYChangePasscodeStateMachine  *changePasscodeStateMachine_;
	LCYTurnOffPasscodeStateMachine *turnOffPasscodeStateMachine_;
	LCYSetPasscodeStateMachine	*setPasscodeStateMachine_;
}

@property (nonatomic, assign) IBOutlet id<LCYPassCodeEditorDelegate> delegate;

@property (nonatomic, retain) IBOutlet UIView *digitsContainerView;
@property (nonatomic, retain) IBOutlet UILabel *promptLabel;
@property (nonatomic, retain) IBOutlet UILabel *errorLabel;

@property (nonatomic, copy) NSString* passCode;

- (void) attemptToSetANewPassCode;
- (void) attemptToDisablePassCode;

- (IBAction) cancel;

@end
