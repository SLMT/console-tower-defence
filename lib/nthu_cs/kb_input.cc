#include "lib/nthu_cs/kb_input.h"

#include <windows.h>

namespace nthu_cs {
namespace {
HANDLE Stdin;
INPUT_RECORD ir = { 0 };
DWORD Read = 0;
}  // namespace

void InitializeKeyInput()
{
  if ((Stdin = GetStdHandle(STD_INPUT_HANDLE)) == NULL)
    exit(1);
  SetConsoleMode(Stdin, ENABLE_LINE_INPUT);
}

int WaitForKeyDown(float sec)
{
  if (WAIT_TIMEOUT == WaitForSingleObject(Stdin, (int)(sec * 1000)))
    return 0;
  else
    return 1;
}

int GetKeyEventASCII()
{
  ReadConsoleInput(Stdin, &ir, 1, &Read);
  FlushConsoleInputBuffer(Stdin);
  if (ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown)
    return ir.Event.KeyEvent.uChar.AsciiChar;
  else
    return -1;
}

int GetKeyEventVirtual()
{
  ReadConsoleInput(Stdin, &ir, 1, &Read);
  FlushConsoleInputBuffer(Stdin);
  if (ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown)
    return ir.Event.KeyEvent.wVirtualKeyCode;
  else
    return -1;
}

}  // namespace nthu_cs
