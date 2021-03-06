// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_PLATFORM_WINDOWS_KEYBOARD_HOOK_HANDLER_H_
#define FLUTTER_SHELL_PLATFORM_WINDOWS_KEYBOARD_HOOK_HANDLER_H_

#include "flutter/shell/platform/windows/public/flutter_windows.h"

#include <string>

namespace flutter {

class FlutterWindowsView;

// Abstract class for handling keyboard input events.
class KeyboardHookHandler {
 public:
  virtual ~KeyboardHookHandler() = default;

  // A function for hooking into keyboard input.
  //
  // Returns true if the key event has been handled, to indicate that other
  // handlers should not be called for this event.
  virtual bool KeyboardHook(FlutterWindowsView* view,
                            int key,
                            int scancode,
                            int action,
                            char32_t character,
                            bool extended) = 0;

  // A function for hooking into Unicode text input.
  virtual void TextHook(FlutterWindowsView* view,
                        const std::u16string& text) = 0;

  // Handler for IME compose begin events.
  //
  // Triggered when the user begins editing composing text using a multi-step
  // input method such as in CJK text input.
  virtual void ComposeBeginHook() = 0;

  // Handler for IME compose end events.
  //
  // Triggered when the user commits the composing text while using a multi-step
  // input method such as in CJK text input.
  virtual void ComposeEndHook() = 0;

  // Handler for IME compose change events.
  //
  // Triggered when the user edits the composing text while using a multi-step
  // input method such as in CJK text input.
  virtual void ComposeChangeHook(const std::u16string& text,
                                 int cursor_pos) = 0;
};

}  // namespace flutter

#endif  // FLUTTER_SHELL_PLATFORM_WINDOWS_KEYBOARD_HOOK_HANDLER_H_
