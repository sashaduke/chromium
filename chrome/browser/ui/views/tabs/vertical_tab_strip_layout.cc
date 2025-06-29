// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/tabs/vertical_tab_strip_layout.h"

#include "ui/views/view.h"

void VerticalTabStripLayout::Layout(views::View* host) {
  int y = 0;
  for (views::View* child : host->children()) {
    if (child->GetVisible()) {
      child->SetBounds(0, y, host->width(), child->GetPreferredSize().height());
      y += child->GetPreferredSize().height();
    }
  }
}

gfx::Size VerticalTabStripLayout::GetPreferredSize(const views::View* host) const {
  int height = 0;
  int width = 0;
  for (const views::View* child : host->children()) {
    if (child->GetVisible()) {
      gfx::Size child_size = child->GetPreferredSize();
      height += child_size.height();
      width = std::max(width, child_size.width());
    }
  }
  return gfx::Size(width, height);
}
