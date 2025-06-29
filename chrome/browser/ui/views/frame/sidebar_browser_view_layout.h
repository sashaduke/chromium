// Copyright 2024 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_BROWSER_VIEW_LAYOUT_H_
#define CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_BROWSER_VIEW_LAYOUT_H_

#include "base/memory/raw_ptr.h"
#include "ui/views/layout/layout_manager.h"

class BrowserView;
class TabStripRegionView;
class ToolbarView;
class InfoBarContainerView;
class BookmarkBarView;
class DownloadShelfView;

namespace views {
class View;
}

class SidebarBrowserViewLayout : public views::LayoutManager {
 public:
  SidebarBrowserViewLayout(
      BrowserView* browser_view,
      TabStripRegionView* tab_strip_region_view,
      views::View* toolbar,
      InfoBarContainerView* infobar_container,
      views::View* contents_container);

  SidebarBrowserViewLayout(const SidebarBrowserViewLayout&) = delete;
  SidebarBrowserViewLayout& operator=(const SidebarBrowserViewLayout&) = delete;

  ~SidebarBrowserViewLayout() override;

  // views::LayoutManager:
  void Layout(views::View* host) override;
  gfx::Size GetMinimumSize(const views::View* host) const override;

  void set_bookmark_bar(BookmarkBarView* bookmark_bar) {
    bookmark_bar_ = bookmark_bar;
  }
  void set_download_shelf(views::View* download_shelf) {
    download_shelf_ = download_shelf;
  }

 private:
  const raw_ptr<BrowserView> browser_view_;
  const raw_ptr<TabStripRegionView> tab_strip_region_view_;
  const raw_ptr<views::View> toolbar_;
  const raw_ptr<InfoBarContainerView> infobar_container_;
  const raw_ptr<views::View> contents_container_;

  raw_ptr<BookmarkBarView> bookmark_bar_ = nullptr;
  raw_ptr<views::View> download_shelf_ = nullptr;
};

#endif  // CHROME_BROWSER_UI_VIEWS_FRAME_SIDEBAR_BROWSER_VIEW_LAYOUT_H_
