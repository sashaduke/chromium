// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_TAB_STRIP_CONTROLLER_H_
#define CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_TAB_STRIP_CONTROLLER_H_

#include "base/memory/raw_ptr.h"

class BrowserView;
class TabStrip;

class SidebarTabStripController {
 public:
  SidebarTabStripController(BrowserView* browser_view, TabStrip* tab_strip);
  ~SidebarTabStripController();

 private:
  const raw_ptr<BrowserView> browser_view_;
  const raw_ptr<TabStrip> tab_strip_;
};

#endif  // CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_TAB_STRIP_CONTROLLER_H_
