#include "test_common.h"
#include "macro_tools.h"

#define TYPE concat3(int, BITWIDTH, _t)
#define FUNCTION_TO_TEST concat4(signed_div_by_, DIVISOR, _zero_, BITWIDTH)
const TYPE divisor = DIVISOR;

static TYPE get_expected_value(TYPE n) {
  return n / divisor;
}

#include "test_signed_div_common.inc"
