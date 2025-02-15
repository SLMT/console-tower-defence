#include "lib\nthu_cs\console_draw.h"

#include <cstdint>
#include <windows.h>

namespace nthu_cs {
namespace {

constexpr COORD dwBufferSize = { kScreenWidth, kScreenHeight };
constexpr COORD dwBufferCoord = { 0, 0 };

CHAR_INFO screen_buffer[kScreenHeight][kScreenWidth];
SMALL_RECT rcRegion = { 0, 0, kScreenWidth - 1, kScreenHeight - 1 };
HANDLE hOutput;
int32_t touched = 0;

}  // namespace

void putASCII2(int x, int y, int ch, int fgcolor, int bgcolor)
{
  if (touched == 0) {
    hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
    ReadConsoleOutput(hOutput, (CHAR_INFO*)screen_buffer, dwBufferSize,
      dwBufferCoord, &rcRegion);
    touched = 1;
  }
  if (x < kScreenWidth && x >= 0 && y < kScreenHeight && y >= 0) {
    screen_buffer[y][x].Char.AsciiChar = ch;
    screen_buffer[y][x].Attributes = fgcolor | bgcolor << 4;
  }
}

void drawCmdWindow()
{
  WriteConsoleOutput(hOutput, (CHAR_INFO*)screen_buffer, dwBufferSize,
    dwBufferCoord, &rcRegion);
  touched = 1;
}

}  // namespace nthu_cs
