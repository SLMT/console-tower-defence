#include "ctd/frame.h"

#include <vector>

#include "absl/log/check.h"
#include "lib/nthu_cs/console_draw.h"

namespace slmt_ctd {

Frame::Frame(int offset_x, int offset_y, int width, int height)
    : offset_x_(offset_x),
      offset_y_(offset_y),
      inner_width_(width),
      inner_height_(height),
      // We create a frame with (w+4, h+2) because we need to put border around
      // the frame, and we use "+4" on X direction because a Big-5 character
      // needs two ASCII character space.
      outer_width_(width + 4),
      outer_height_(height + 2),
      data_(std::vector<std::vector<FrameChar>>(
          outer_width_,
          std::vector<FrameChar>(outer_height_, {0, 0, 0, false}))) {
  DrawBorder();
  DrawInformation();
  Flush();
}

void Frame::DrawString(int x, int y, const std::string& str, int fg_color,
                       int bg_color) {
  CHECK_GE(x, -2);
  CHECK_LT(x, inner_width_ + 2);
  CHECK_GE(y, -1);
  CHECK_LT(y, inner_height_ + 1);

  for (int i = 0; i < str.size(); i++) {
    DrawASCII(x + i, y, str[i], fg_color, bg_color);
  }
}

void Frame::DrawASCII(int x, int y, int ch, int fg_color, int bg_color) {
  CHECK_GE(x, -2);
  CHECK_LT(x, inner_width_ + 2);
  CHECK_GE(y, -1);
  CHECK_LT(y, inner_height_ + 1);

  data_[x + 2][y + 1].ch = ch;
  data_[x + 2][y + 1].fg_color = fg_color;
  data_[x + 2][y + 1].bg_color = bg_color;
  data_[x + 2][y + 1].is_fresh = true;
}

void Frame::Flush() {
  // Draw only the fresh data
  for (int i = 0; i < outer_width_; i++) {
    for (int j = 0; j < outer_height_; j++) {
      if (data_[i][j].is_fresh) {
        nthu_cs::PutASCII(offset_x_ + i, offset_y_ + j, data_[i][j].ch,
                          data_[i][j].fg_color, data_[i][j].bg_color);
        data_[i][j].is_fresh = false;
      }
    }
  }

  nthu_cs::DrawCmdWindow();
}

void Frame::DrawBorder() {
  // Put horizontal borders
  for (int x = -2; x <= inner_width_; x += 2) {
    DrawASCII(x, -1, 0xA1, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(x + 1, -1, 0xBD, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(x, inner_height_, 0xA1, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(x + 1, inner_height_, 0xBD, COLOR_GRAY, COLOR_BLACK);
  }

  // Put vertical borders
  for (int y = -1; y <= inner_height_; y++) {
    DrawASCII(-2, y, 0xA1, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(-1, y, 0xBD, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(inner_width_, y, 0xA1, COLOR_GRAY, COLOR_BLACK);
    DrawASCII(inner_width_ + 1, y, 0xBD, COLOR_GRAY, COLOR_BLACK);
  }
}

void Frame::DrawInformation() {
  DrawString(0, -1, " Tower Defense 2.0  ", COLOR_BRIGHT_YELLOW,
             COLOR_DARK_BLUE);
  DrawString(inner_width_ - 14, -1, " Made by SLMT ", COLOR_BRIGHT_YELLOW,
             COLOR_DARK_CYAN);
}

}  // namespace slmt_ctd