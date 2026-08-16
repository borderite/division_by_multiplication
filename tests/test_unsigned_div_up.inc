#include "test_common.h"
#include "macro_tools.h"
#include <stdbool.h>

#define TYPE concat3(uint, BITWIDTH, _t)
#define FUNCTION_TO_TEST concat4(unsigned_div_by_, DIVISOR, _up_, BITWIDTH)
const TYPE divisor = DIVISOR;

static TYPE get_expected_value(TYPE n) {
  bool pos_flag = n > 0;
  return (n - pos_flag) / divisor + pos_flag;
}

#include "test_signed_div_common.inc"
