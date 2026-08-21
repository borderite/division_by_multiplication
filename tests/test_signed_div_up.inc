/* -*- mode: c -*- */
#include "test_common.h"
#include "macro_tools.h"
#include <stdbool.h>

#define TYPE concat3(int, BITWIDTH, _t)
#ifdef NEGATIVE_DIVISOR
#define FUNCTION_TO_TEST                                                       \
  concat4(signed_div_by_neg_, ABS_DIVISOR, _up_, BITWIDTH)
const TYPE divisor = -ABS_DIVISOR;
#else
#define FUNCTION_TO_TEST                                                       \
  concat4(signed_div_by_, ABS_DIVISOR, _up_, BITWIDTH)
const TYPE divisor = ABS_DIVISOR;
#endif
const TYPE abs_divisor = ABS_DIVISOR;


static TYPE get_expected_value(TYPE n) {
#ifdef NEGATIVE_DIVISOR
  bool neg_flag = n < 0;
  return (n + neg_flag) / divisor + neg_flag;
#else
  bool pos_flag = n > 0;
  return (n - pos_flag) / divisor + pos_flag;
#endif
}

#include "test_signed_div_common.inc"
