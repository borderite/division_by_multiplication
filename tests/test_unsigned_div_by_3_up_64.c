#include "unity.h"
#include <stdint.h>

typedef uint64_t int_type_t;
const int_type_t divisor = 3;
#define FUNCTION_TO_TEST unsigned_div_by_3_up_64
int_type_t INT_TYPE_MAX = UINT64_MAX;
#define TEST_EQUAL TEST_ASSERT_EQUAL_UINT64

#include "test_unsigned_div_up.inc"
