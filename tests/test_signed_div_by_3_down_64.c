#include "unity.h"
#include <stdint.h>

typedef int64_t int_type_t;
const int_type_t divisor = 3;
#define FUNCTION_TO_TEST signed_div_by_3_down_64
int_type_t INT_TYPE_MAX = INT64_MAX;
int_type_t INT_TYPE_MIN = INT64_MIN;
#define TEST_EQUAL TEST_ASSERT_EQUAL_INT64

#include "test_signed_div_down.inc"

