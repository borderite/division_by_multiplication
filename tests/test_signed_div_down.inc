#include "test_common.h"
#include "macro_tools.h"
#include <stdbool.h>

#define TYPE concat3(int, BITWIDTH, _t)
#define FUNCTION_TO_TEST concat4(signed_div_by_, DIVISOR, _down_, BITWIDTH)
const TYPE divisor = DIVISOR;

static TYPE get_expected_value(TYPE n) {
#if DIVISOR > 0 
  bool neg_flag = n < 0;
  return (n + neg_flag) / divisor - neg_flag;
#else
  bool pos_flag = n > 0;
  return (n - pos_flag) / divisor - pos_flag;
#endif
}

#include "test_signed_div_common.inc"
