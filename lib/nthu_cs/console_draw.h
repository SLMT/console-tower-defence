#ifndef LIB_NTHU_CS_CONSOLE_DRAW_H_
#define LIB_NTHU_CS_CONSOLE_DRAW_H_

#include <cstdint>
#include <windows.h>

namespace nthu_cs {

const int32_t kScreenWidth = 80;
const int32_t kScreenHeight = 25;

// Set the ASCII character at the given coordinate on the terminal.
//
// Here are the color code:
// 0: Black        1: Dark Blue      2: Dark Green     3: Dark Cyan 
// 4: Dark Red     5: Dark Purple    6: Dark Yellow    7: Light Gray
// 8: Dark Gray    9: Bright Blue    10: Bright Green  11: Bright Cyan
// 12: Bright Red  13: Bright Purple 14: Bright Yellow 15: White
void PutASCII(int x, int y, int ch, int fgcolor, int bgcolor);

// Make the command line terminal draw the terminal window.
void DrawCmdWindow();

}  // namespace nthu_cs

#endif  // LIB_NTHU_CS_CONSOLE_DRAW_H_