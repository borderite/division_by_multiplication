/* -*- mode: c -*- */
#include "test_common.h"
#include "macro_tools.h"
#include <stdbool.h>

#define TYPE concat3(uint, BITWIDTH, _t)
#define FUNCTION_TO_TEST concat4(unsigned_div_by_, DIVISOR, _down_, BITWIDTH)
const TYPE divisor = DIVISOR;

static TYPE get_expected_value(TYPE n) {
  return n / divisor;
}

#include "test_unsigned_div_common.inc"
