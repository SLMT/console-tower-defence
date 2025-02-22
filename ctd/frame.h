#ifndef CTD_FRAME_H_
#define CTD_FRAME_H_

#include <cstdint>
#include <string>
#include <vector>

namespace slmt_ctd {

// Colors
enum class Color {
  kBlack = 0,
  kDarkBlue = 1,
  kDarkGreen = 2,
  kDarkCyan = 3,
  kRed = 4,
  kPurple = 5,
  kYellow = 6,
  kGray = 7,
  kDarkGray = 8,
  kBrightBlue = 9,
  kBrightGreen = 10,
  kBrightCyan = 11,
  kBrightRed = 12,
  kBrightPurple = 13,
  kBrightYellow = 14,
  kWhite = 15,
};

// Represents a frame shown on the terminal.
class Frame {
 public:
  // Create a frame at (`offset_x`, `offset_y`) with size `width` X `height`.
  Frame(int offset_x, int offset_y, int width, int height);

  // Draw a string `str` at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  void DrawString(int x, int y, const std::string& str, Color fg_color,
                  Color bg_color);

  // Draw a character at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  void DrawASCII(int x, int y, int ch, Color fg_color, Color bg_color);

  // Flush the frame buffer to the window.
  void Flush();

 private:
  struct FrameChar {
    int ch;
    Color fg_color;
    Color bg_color;
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
