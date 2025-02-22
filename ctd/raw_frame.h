#ifndef CTD_RAW_FRAME_H_
#define CTD_RAW_FRAME_H_

#include <cstdint>
#include <string>
#include <vector>

#include "ctd\frame.h"

namespace slmt_ctd {

// The frame that directly interacts with the Windows API.
class RawFrame : public Frame {
 public:
  RawFrame(int offset_x, int offset_y, int width, int height);

  void DrawString(int x, int y, const std::string& str, Color fg_color,
                  Color bg_color) override;

  void DrawASCII(int x, int y, int ch, Color fg_color, Color bg_color) override;

  void Flush() override;

 private:
  struct FrameChar {
    int ch;
    Color fg_color;
    Color bg_color;
    bool is_fresh;
  };

  // Coordinates
  int offset_x_;
  int offset_y_;

  // Frame size
  int width_;
  int height_;

  // Frame data
  std::vector<std::vector<FrameChar>> data_;
};

}  // namespace slmt_ctd

#endif  // CTD_RAW_FRAME_H_
