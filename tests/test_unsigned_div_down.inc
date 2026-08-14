#include <stdio.h>
#include "div_by_mult.h"

static int_type_t get_expected_value(int_type_t n) { return n / divisor; }

void setUp(void) {}
void tearDown(void) {}

int_type_t dividend;

void test(void) {
  int_type_t expected = get_expected_value(divisor);
  int_type_t actual = FUNCTION_TO_TEST(divisor);
  printf("dividend = %u\n", dividend);
  TEST_EQUAL(expected, actual);
}

int main(void) {
  UNITY_BEGIN();

  int_type_t divisor_plus_one = divisor + 1;
  for (dividend = 0; dividend <= divisor_plus_one; ++dividend) 
    RUN_TEST(test);    

  int_type_t divisor_times_99_plus_1 = 99 * divisor + 1;
  int_type_t divisor_times_101_minus_1 = 101 * divisor - 1;
  for (dividend = divisor_times_99_plus_1;
       dividend <= divisor_times_101_minus_1; ++dividend) {
    RUN_TEST(test);    
  }

  int_type_t rem = INT_TYPE_MAX % divisor;
  int_type_t nbar = INT_TYPE_MAX - (rem + 1) % divisor;

  dividend = nbar;
  RUN_TEST(test);    

  dividend = INT_TYPE_MAX - 1;
  RUN_TEST(test);

  dividend = INT_TYPE_MAX;
  RUN_TEST(test);

  return UNITY_END();
}  
