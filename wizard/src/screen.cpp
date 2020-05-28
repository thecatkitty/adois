#include <algorithm>

#include <dos/screen.hpp>


screen::screen() : mem(0xB800), width(80), height(25) {
  restore_attr = mem[0].s.attr.byte;
}

screen::~screen() {
  screen_cell cell;
  cell.s.ch = '\0';
  cell.s.attr.byte = restore_attr;
  fill(cell);
}

void screen::fill(const screen_cell &cell) {
  std::fill(mem + 0, mem + width * height, cell);
}

void screen::fill(
  const screen_cell &cell,
  length top,
  length bottom,
  length left,
  length right) {
  for(std::uint16_t row = top; row < bottom; row++) {
    std::fill(mem + row * width + left, mem + row * width + right, cell);
  }
}
