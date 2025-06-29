// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_VIEWS_TABS_VERTICAL_TAB_STRIP_LAYOUT_H_
#define CHROME_BROWSER_UI_VIEWS_TABS_VERTICAL_TAB_STRIP_LAYOUT_H_

#include "ui/views/layout/layout_manager.h"

class VerticalTabStripLayout : public views::LayoutManager {
 public:
  VerticalTabStripLayout() = default;
  VerticalTabStripLayout(const VerticalTabStripLayout&) = delete;
  VerticalTabStripLayout& operator=(const VerticalTabStripLayout&) = delete;
  ~VerticalTabStripLayout() override = default;

  // views::LayoutManager:
  void Layout(views::View* host) override;
  gfx::Size GetPreferredSize(const views::View* host) const override;
};

#endif  // CHROME_BROWSER_UI_VIEWS_TABS_VERTICAL_TAB_STRIP_LAYOUT_H_
