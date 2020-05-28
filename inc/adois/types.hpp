#pragma once

#include <cstdint>

#ifdef __GNUC__
#define __cdecl __attribute__((__cdecl__))
#endif


namespace adois {
  typedef void* native_handle;
  typedef std::uint16_t length;

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
}
