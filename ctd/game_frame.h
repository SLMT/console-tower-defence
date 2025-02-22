#ifndef CTD_GAME_FRAME_H_
#define CTD_GAME_FRAME_H_

#include "ctd\frame.h"
#include "ctd\raw_frame.h"

namespace slmt_ctd {

// A special type of `Frame` that draws the border of the frame and shows
// other information above the border. The other drawing requests will be
// forwarded to the underlying frame.
class GameFrame : public Frame {
 public:
  GameFrame(int offset_x, int offset_y, int width, int height,
            const std::string& game_version);

  void DrawString(int x, int y, const std::string& str, Color fg_color,
                  Color bg_color) override;

  void DrawASCII(int x, int y, int ch, Color fg_color, Color bg_color) override;

  void Flush() override;

 private:
  void DrawInformation(int inner_width, const std::string& game_version);
  void DrawBorder(int inner_width, int inner_height);
  void DrawBorderChar(int x, int y);

  RawFrame raw_frame_;
};

}  // namespace slmt_ctd

#endif  // CTD_GAME_FRAME_H_
