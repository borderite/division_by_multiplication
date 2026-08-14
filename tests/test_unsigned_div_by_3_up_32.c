#include "unity.h"
#include <stdint.h>

typedef uint32_t int_type_t;
const int_type_t divisor = 3;
#define FUNCTION_TO_TEST unsigned_div_by_3_up_32
int_type_t INT_TYPE_MAX = UINT32_MAX;
#define TEST_EQUAL TEST_ASSERT_EQUAL_UINT32

#include "test_unsigned_div_up.inc"
