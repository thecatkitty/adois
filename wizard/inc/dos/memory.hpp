#pragma once

#ifndef __WATCOMC__
// gcc-ia16 can't utilize far pointers
typedef std::uint16_t __segment;
#define far
#endif

template<typename T>
struct seg_mem {
  const __segment base;

  inline seg_mem(std::uint16_t seg) : base(seg) {}
  inline T far *operator+(std::uint16_t idx) {
#ifdef __WATCOMC__
    return base :> (T __near *)(idx * sizeof(T));
#else
    return idx * sizeof(T);
#endif
  }
  inline T far &operator[](std::uint16_t idx) {
    return *(*this + idx);
  }
};
