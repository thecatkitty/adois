#pragma once

#include <array>
#include <cstdint>

#include <dos/memory.hpp>


namespace color {
  enum color {
    black = 0,
    blue,
    green,
    cyan,
    red,
    magenta,
    brown,
    gray,
    dark_gray,
    bright_blue,
    bright_green,
    bright_cyan,
    bright_red,
    bright_magenta,
    yellow,
    white
  };
}

union screen_cell {
  std::uint16_t word;
  struct {
    char ch;
    union {
      std::uint8_t byte;
      struct {
        color::color fg : 4;
        color::color bg : 3;
        bool blink : 1;
      };
    } attr;
  } s;
};

inline screen_cell make_screen_cell(
  char ch,
  color::color fg,
  color::color bg,
  bool blink = false) {

  screen_cell cell;
  cell.s.ch = ch;
  cell.s.attr.fg = fg;
  cell.s.attr.bg = bg;
  cell.s.attr.blink = blink;
  return cell;
}

struct screen {
  typedef std::uint16_t length;

  seg_mem<screen_cell> mem;
  const length width;
  const length height;

  screen();
  ~screen();

  void fill(const screen_cell &cell);
  void fill(
    const screen_cell &cell,
    length top,
    length bottom,
    length left,
    length right);

  inline screen_cell far &put(char ch, length row, length column) {
    screen_cell far &cell = mem[row * width + column];
    cell.s.ch = ch;
    return cell;
  }

  inline void put(const char *str, length row, length column) {
    screen_cell far *ptr = mem + row * width + column;
    while(*str) {
      (ptr++)->s.ch = *str;
      str++;
    }
  }

private:
  std::uint8_t restore_attr;
};
