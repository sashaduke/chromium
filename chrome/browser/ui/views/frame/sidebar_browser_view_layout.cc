// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/frame/sidebar_browser_view_layout.h"

#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/frame/tab_strip_region_view.h"
#include "chrome/browser/ui/views/toolbar/toolbar_view.h"
#include "chrome/browser/ui/views/infobars/infobar_container_view.h"
#include "chrome/browser/ui/views/bookmarks/bookmark_bar_view.h"
#include "chrome/browser/ui/views/download/download_shelf_view.h"
#include "ui/views/view.h"

SidebarBrowserViewLayout::SidebarBrowserViewLayout(
    BrowserView* browser_view,
    TabStripRegionView* tab_strip_region_view,
    views::View* toolbar,
    InfoBarContainerView* infobar_container,
    views::View* contents_container)
    : browser_view_(browser_view),
      tab_strip_region_view_(tab_strip_region_view),
      toolbar_(toolbar),
      infobar_container_(infobar_container),
      contents_container_(contents_container) {}

SidebarBrowserViewLayout::~SidebarBrowserViewLayout() = default;

void SidebarBrowserViewLayout::Layout(views::View* host) {
  const int kTabStripWidth = 150;
  const gfx::Rect host_bounds = host->GetLocalBounds();

  // Tab strip on the left.
  tab_strip_region_view_->SetBounds(0, 0, kTabStripWidth, host_bounds.height());

  // Other components are stacked vertically to the right of the tab strip.
  int main_content_x = kTabStripWidth;
  int main_content_width = host_bounds.width() - kTabStripWidth;
  int y = 0;

  // Toolbar
  int toolbar_height = toolbar_->GetPreferredSize().height();
  toolbar_->SetBounds(main_content_x, y, main_content_width, toolbar_height);
  y += toolbar_height;

  // Bookmark bar
  if (bookmark_bar_ && bookmark_bar_->GetVisible()) {
    int bookmark_bar_height = bookmark_bar_->GetPreferredSize().height();
    bookmark_bar_->SetBounds(main_content_x, y, main_content_width, bookmark_bar_height);
    y += bookmark_bar_height;
  }

  // Infobar
  int infobar_height = infobar_container_->GetPreferredSize().height();
  infobar_container_->SetBounds(main_content_x, y, main_content_width, infobar_height);
  y += infobar_height;

  // Contents
  int contents_height = host_bounds.height() - y;
  if (download_shelf_ && download_shelf_->GetVisible()) {
    contents_height -= download_shelf_->GetPreferredSize().height();
  }
  contents_container_->SetBounds(main_content_x, y, main_content_width, contents_height);
  y += contents_height;

  // Download shelf
  if (download_shelf_ && download_shelf_->GetVisible()) {
    int download_shelf_height = download_shelf_->GetPreferredSize().height();
    download_shelf_->SetBounds(main_content_x, y, main_content_width, download_shelf_height);
  }
}

gfx::Size SidebarBrowserViewLayout::GetMinimumSize(const views::View* host) const {
  return gfx::Size(300, 200);
}
