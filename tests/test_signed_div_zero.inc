/* -*- mode: c -*- */
#include "test_common.h"
#include "macro_tools.h"

#define TYPE concat3(int, BITWIDTH, _t)
#ifdef NEGATIVE_DIVISOR
#define FUNCTION_TO_TEST                                                       \
  concat4(signed_div_by_neg_, ABS_DIVISOR, _zero_, BITWIDTH)
const TYPE divisor = -ABS_DIVISOR;
#else
#define FUNCTION_TO_TEST                                                       \
  concat4(signed_div_by_, ABS_DIVISOR, _zero_, BITWIDTH)
const TYPE divisor = ABS_DIVISOR;
#endif
const TYPE abs_divisor = ABS_DIVISOR;

static TYPE get_expected_value(TYPE n) {
  return n / divisor;
}

#include "test_signed_div_common.inc"
