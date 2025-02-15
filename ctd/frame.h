#ifndef CTD_FRAME_H_
#define CTD_FRAME_H_

#include <cstdint>
#include <string>
#include <vector>

namespace slmt_ctd {

// Colors
const int COLOR_BLACK = 0;
const int COLOR_DARK_BLUE = 1;
const int COLOR_DARK_GREEN = 2;
const int COLOR_DARK_CYAN = 3;

const int COLOR_RED = 4;
const int COLOR_PURPLE = 5;
const int COLOR_YELLOW = 6;
const int COLOR_GRAY = 7;

const int COLOR_DARK_GRAY = 8;
const int COLOR_BRIGHT_BLUE = 9;
const int COLOR_BRIGHT_GREEN = 10;
const int COLOR_BRIGHT_CYAN = 11;

const int COLOR_BRIGHT_RED = 12;
const int COLOR_BRIGHT_PURPLE = 13;
const int COLOR_BRIGHT_YELLOW = 14;
const int COLOR_WHITE = 15;

// Represents a frame shown on the terminal.
class Frame {
 public:
  // Create a frame at (`offset_x`, `offset_y`) with size `width` X `height`.
  Frame(int offset_x, int offset_y, int width, int height);

  // Draw a string `str` at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  void DrawString(int x, int y, const std::string& str, int fg_color,
                  int bg_color);

  // Draw a character at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  void DrawASCII(int x, int y, int ch, int fg_color, int bg_color);

  // Flush the frame buffer to the window.
  void Flush();

 private:
  struct FrameChar {
    int ch;
    int fg_color;
    int bg_color;
    bool is_fresh;
  };

  void DrawBorder();
  void DrawInformation();

  // Coordinates
  int offset_x_;
  int offset_y_;

  // Frame size
  int inner_width_;
  int inner_height_;
  int outer_width_;
  int outer_height_;

  // Frame data
  std::vector<std::vector<FrameChar>> data_;
};

}  // namespace slmt_ctd

#endif  // CTD_FRAME_H_
