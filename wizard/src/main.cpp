#include <algorithm>
#include <shy/screen.hpp>

#include <conio.h>


static const char MSG_TITLE[] = "It's going to become a Setup program";

int main(int argc, char *argv[]) {
  screen scr;

  screen_cell cell = make_screen_cell(0x00, color::gray, color::blue);
  scr.fill(cell);

  scr.put(MSG_TITLE, 1, 1);
  cell.s.ch = 0xCD;
  scr.fill(cell, 2, 3, 0, sizeof(MSG_TITLE) + 1);

  cell.s.ch = '\0';
  cell.s.attr.fg = color::black;
  cell.s.attr.bg = color::gray;
  scr.fill(cell, scr.height - 1, scr.height, 0, scr.width);
  scr.put(0xB3, scr.height - 1, scr.width - 17);

  getch();
  return 0;
}
