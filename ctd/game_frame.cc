#include "ctd\game_frame.h"

#include "absl\strings\str_cat.h"
#include "ctd\frame.h"
#include "ctd\raw_frame.h"

namespace slmt_ctd {
namespace {

const int kBorderW = 2;
const int kBorderH = 1;
const int kInfoH = 1;
const int kBorderCode[] = {0xA1, 0xBD};
const std::string kGameInfoPrefix = "Tower Defense ";
const std::string kAuthorInfo = "Made by SLMT";

}  // namespace

GameFrame::GameFrame(int offset_x, int offset_y, int width, int height,
                     const std::string& game_version)
    : raw_frame_(offset_x - kBorderW, offset_y - kBorderH - kInfoH,
                 width + kBorderW * 2, height + kBorderH * 2 + kInfoH) {
  DrawInformation(width, game_version);
  DrawBorder(width, height);
  Flush();
}

void GameFrame::DrawString(int x, int y, const std::string& str, Color fg_color,
                           Color bg_color) {
  raw_frame_.DrawString(x + kBorderW, y + kBorderW, str, fg_color, bg_color);
}

void GameFrame::DrawASCII(int x, int y, int ch, Color fg_color,
                          Color bg_color) {
  raw_frame_.DrawASCII(x + kBorderW, y + kBorderW, ch, fg_color, bg_color);
}

void GameFrame::Flush() { raw_frame_.Flush(); }

void GameFrame::DrawInformation(int inner_width,
                                const std::string& game_version) {
  const std::string game_info = absl::StrCat(kGameInfoPrefix, game_version);
  raw_frame_.DrawString(0, 0, game_info, Color::kBrightYellow,
                        Color::kDarkBlue);
  raw_frame_.DrawString(inner_width - kAuthorInfo.size() + kBorderW * 2, 0,
                        kAuthorInfo, Color::kBrightYellow, Color::kDarkCyan);
}

void GameFrame::DrawBorder(int inner_width, int inner_height) {
  // Put horizontal borders
  for (int x = 0; x <= inner_width + kBorderW; x += 2) {
    DrawBorderChar(x, kInfoH);
    DrawBorderChar(x, inner_height + kInfoH);
  }

  // Put vertical borders
  for (int y = 0; y < inner_height; y++) {
    DrawBorderChar(0, y + kInfoH);
    DrawBorderChar(inner_width + kBorderW, y + kInfoH);
  }
}

void GameFrame::DrawBorderChar(int x, int y) {
  raw_frame_.DrawASCII(x, y, kBorderCode[0], Color::kGray, Color::kBlack);
  raw_frame_.DrawASCII(x + 1, y, kBorderCode[1], Color::kGray, Color::kBlack);
}

}  // namespace slmt_ctd