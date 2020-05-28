#include <algorithm>
#include <conio.h>

#include <adois/screen.hpp>

using namespace adois;


static const char MSG_TITLE[] = "It's going to become a Setup program";

int main(int argc, char *argv[]) {
  screen scr;

  scr.fill(color::gray, color::blue);

  scr.put(1, 1, MSG_TITLE);
  scr.fill(2, 3, 0, sizeof(MSG_TITLE) + 1, color::gray, color::blue, 0xCD);

  scr.fill(scr.height - 1, scr.height, 0, scr.width, color::black, color::gray);
  scr.put(0xB3, scr.height - 1, scr.width - 17);

  while (!_kbhit());
  return 0;
}
