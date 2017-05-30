//
// Copyright (c) 2017 Dmitry Krutskikh
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
#import <Cocoa/Cocoa.h>
#include "app.hpp"

@interface PlayerAppDelegate : NSObject<NSApplicationDelegate> {
  bool _appInited;
  bool _appShutdowned;

  bool _alertActive;

  NSTimer *_updateTimer;
}

- (instancetype)init;
- (void)dealloc;

- (void)applicationDidFinishLaunching:(NSNotification *)notification;
- (void)applicationDidBecomeActive:(NSNotification *)notification;
- (void)applicationWillResignActive:(NSNotification *)notification;

- (void)alertActivateDeactivate:(bool)activate;

- (void)nextFrame;

@end

@implementation PlayerAppDelegate

- (instancetype)init {
  _appInited = false;
  _appShutdowned = false;

  _alertActive = false;

  _updateTimer = [NSTimer scheduledTimerWithTimeInterval:(1.0f / 60.0f)
                                                  target:self
                                                selector:@selector(nextFrame)
                                                userInfo:nil
                                                 repeats:TRUE];

  return self;
}

- (void)dealloc {
  if (_updateTimer != nil) {
    [_updateTimer invalidate];
    _updateTimer = nil;
  }
}

- (void)applicationDidFinishLaunching:(NSNotification *)__unused notification {
  toygine::app *app = toygine::app::instance();
  if (app == nullptr || !app->initialize()) {
    [[NSApplication sharedApplication] terminate:nil];
    return;
  }

  _appInited = true;
}

- (void)applicationDidBecomeActive:(NSNotification *)__unused notification{};

- (void)applicationWillResignActive:(NSNotification *)__unused notification{};

- (void)alertActivateDeactivate:(bool)activate {
  _alertActive = activate;
}

- (void)nextFrame {
  if (!_appInited || _appShutdowned || _alertActive) return;

  toygine::app *app = toygine::app::instance();
  if (app != nullptr && !app->process()) {
    app->shutdown();
    _appShutdowned = true;
    [[NSApplication sharedApplication] terminate:self];
  }
}

@end

int osxStartPoint() {
#if defined(STORETYPE_APPSTORE) && defined(BUILDTYPE_UNLOCK_BY_INAPP)
  if ([NSFileManager.defaultManager
          fileExistsAtPath:NSBundle.mainBundle.appStoreReceiptURL.path] == NO) {
    exit(173);
  }
#endif  // defined(STORETYPE_APPSTORE) && defined(BUILDTYPE_UNLOCK_BY_INAPP)

  return NSApplicationMain(0, nullptr);
}
