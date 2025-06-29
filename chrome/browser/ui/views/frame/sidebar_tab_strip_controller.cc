// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/frame/sidebar_tab_strip_controller.h"

#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/tabs/tab_strip.h"

SidebarTabStripController::SidebarTabStripController(
    BrowserView* browser_view,
    TabStrip* tab_strip)
    : browser_view_(browser_view), tab_strip_(tab_strip) {
  tab_strip_->SetLayout(
      std::make_unique<views::BoxLayout>(views::BoxLayout::Orientation::kVertical));
}

SidebarTabStripController::~SidebarTabStripController() = default;
