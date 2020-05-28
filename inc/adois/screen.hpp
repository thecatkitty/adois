#pragma once

#include <adois/types.hpp>


extern "C" const adois::length adsc_width;
extern "C" const adois::length adsc_height;

extern "C" void __cdecl adsc_create(adois::native_handle *phsc);
extern "C" void __cdecl adsc_dispose(adois::native_handle *phsc);

extern "C" void __cdecl adsc_fill(
  adois::color::color fg, adois::color::color bg, char ch);
extern "C" void __cdecl adsc_fill_area(
  adois::length top,
  adois::length bottom,
  adois::length left,
  adois::length right,
  adois::color::color fg,
  adois::color::color bg,
  char ch);

extern "C" void __cdecl adsc_put(
  adois::length row,
  adois::length column,
  char ch);
extern "C" void __cdecl adsc_put_string(
  adois::length row,
  adois::length column,
  const char *str);


namespace adois {
  class screen {
    native_handle hsc;

  public:
    const length width;
    const length height;

    inline screen() : width(adsc_width), height(adsc_height) {
      adsc_create(&hsc);
    }
    inline ~screen() {
      adsc_dispose(&hsc);
    }

    inline void fill(color::color fg, color::color bg, char ch = 0) {
      adsc_fill(fg, bg, ch);
    }
    inline void fill(
      length top,
      length bottom,
      length left,
      length right,
      color::color fg,
      color::color bg,
      char ch = 0) {
      adsc_fill_area(top, bottom, left, right, fg, bg, ch);
    }

    inline void put(length row, length column, char ch) {
      adsc_put(row, column, ch);
    }
    inline void put(length row, length column, const char *str) {
      adsc_put_string(row, column, str);
    }
  };
}
