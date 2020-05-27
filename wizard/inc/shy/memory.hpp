#pragma once

#if _MSC_VER
#define __based(x)
#define __segment std::uint16_t
#define far
#endif

template<typename T>
struct seg_mem {
  const __segment base;

  inline seg_mem(std::uint16_t seg) : base(seg) {}
  inline T far *operator+(std::uint16_t idx) {
    T __based(void) *ptr = 0;
    ptr += idx;
    return base :> ptr;
  }
  inline T far &operator[](std::uint16_t idx) {
    return *(*this + idx);
  }
};
