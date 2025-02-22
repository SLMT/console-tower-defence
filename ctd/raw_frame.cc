#include "ctd/raw_frame.h"

#include <vector>

#include "absl/log/check.h"
#include "ctd/frame.h"
#include "lib/nthu_cs/console_draw.h"

namespace slmt_ctd {

RawFrame::RawFrame(int offset_x, int offset_y, int width, int height)
    : offset_x_(offset_x),
      offset_y_(offset_y),
      width_(width),
      height_(height),
      data_(std::vector<std::vector<FrameChar>>(
          width, std::vector<FrameChar>(
                     height, {0, Color::kBlack, Color::kBlack, true}))) {}

void RawFrame::DrawString(int x, int y, const std::string& str, Color fg_color,
                          Color bg_color) {
  CHECK_GE(x, 0);
  CHECK_LT(x + str.size() - 1, width_);
  CHECK_GE(y, 0);
  CHECK_LT(y, height_);

  for (int i = 0; i < str.size(); i++) {
    DrawASCII(x + i, y, str[i], fg_color, bg_color);
  }
}

void RawFrame::DrawASCII(int x, int y, int ch, Color fg_color, Color bg_color) {
  CHECK_GE(x, 0);
  CHECK_LT(x, width_);
  CHECK_GE(y, 0);
  CHECK_LT(y, height_);

  data_[x][y].ch = ch;
  data_[x][y].fg_color = fg_color;
  data_[x][y].bg_color = bg_color;
  data_[x][y].is_fresh = true;
}

void RawFrame::Flush() {
  // Draw only the fresh data
  for (int i = 0; i < width_; i++) {
    for (int j = 0; j < height_; j++) {
      if (data_[i][j].is_fresh) {
        nthu_cs::PutASCII(offset_x_ + i, offset_y_ + j, data_[i][j].ch,
                          static_cast<int>(data_[i][j].fg_color),
                          static_cast<int>(data_[i][j].bg_color));
        data_[i][j].is_fresh = false;
      }
    }
  }

  nthu_cs::DrawCmdWindow();
}

}  // namespace slmt_ctd