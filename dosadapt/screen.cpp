#include <algorithm>

#include <adois/screen.hpp>

#include "memory.hpp"

extern "C" {

union screen_cell {
  std::uint16_t word;
  struct {
    char ch;
    union {
      std::uint8_t byte;
      struct {
        adois::color::color fg : 4;
        adois::color::color bg : 3;
        bool blink : 1;
      };
    } attr;
  } s;
};

inline screen_cell make_screen_cell(
  char ch,
  adois::color::color fg,
  adois::color::color bg,
  bool blink = false) {

  screen_cell cell;
  cell.s.ch = ch;
  cell.s.attr.fg = fg;
  cell.s.attr.bg = bg;
  cell.s.attr.blink = blink;
  return cell;
}


static seg_mem<screen_cell> vga_fb(0xB800);


const adois::length adsc_width = 80;
const adois::length adsc_height = 25;


void adsc_create(adois::native_handle *hsc)
{
  *reinterpret_cast<std::uint8_t *>(hsc) = vga_fb[0].s.attr.byte;
}

void adsc_dispose(adois::native_handle *hsc)
{
  screen_cell cell;
  cell.s.ch = '\0';
  cell.s.attr.byte = *reinterpret_cast<std::uint8_t *>(hsc);
  std::fill(
    vga_fb + 0, vga_fb + adsc_width * adsc_height, cell);
}


void adsc_fill(
  adois::color::color fg,
  adois::color::color bg,
  char ch)
{
  screen_cell cell = make_screen_cell(ch, fg, bg);
  std::fill(
    vga_fb + 0, vga_fb + adsc_width * adsc_height, cell);
}

void adsc_fill_area(
  adois::length top,
  adois::length bottom,
  adois::length left,
  adois::length right,
  adois::color::color fg,
  adois::color::color bg,
  char ch)
{
  screen_cell cell = make_screen_cell(ch, fg, bg);
  for(std::uint16_t row = top; row < bottom; row++) {
    std::fill(
      vga_fb + row * adsc_width + left,
      vga_fb + row * adsc_width + right,
      cell);
  }
}

void adsc_put(
  adois::length row,
  adois::length column,
  char ch)
{
  vga_fb[row * adsc_width + column].s.ch = ch;
}

void adsc_put_string(
  adois::length row,
  adois::length column,
  const char *str)
{
  screen_cell far *ptr = vga_fb + row * adsc_width + column;
  while(*str) {
    (ptr++)->s.ch = *str;
    str++;
  }
}

}
