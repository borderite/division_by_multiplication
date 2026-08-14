#include "unity.h"
#include <stdint.h>

typedef int32_t int_type_t;
const int_type_t divisor = 7;
#define FUNCTION_TO_TEST signed_div_by_7_zero_32
int_type_t INT_TYPE_MAX = INT32_MAX;
int_type_t INT_TYPE_MIN = INT32_MIN;
#define TEST_EQUAL TEST_ASSERT_EQUAL_INT32

#include "test_signed_div_zero.inc"

