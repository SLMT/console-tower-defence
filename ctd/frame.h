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

// An interface that presents a frame shown on the terminal.
class Frame {
 public:
  // Draw a string `str` at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  virtual void DrawString(int x, int y, const std::string& str, Color fg_color,
                          Color bg_color) = 0;

  // Draw a character at (`x`, `y`) with foreground color `fg_color` and
  // background color `bg_color`.
  virtual void DrawASCII(int x, int y, int ch, Color fg_color,
                         Color bg_color) = 0;

  // Flush the frame buffer to the window.
  virtual void Flush() = 0;
};

}  // namespace slmt_ctd

#endif  // CTD_FRAME_H_
