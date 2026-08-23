/* -*- mode: c -*- */
#define INT_TYPE_MAX concat3(INT, BITWIDTH, _MAX)
#define INT_TYPE_MIN concat3(INT, BITWIDTH, _MIN)
#define TEST_EQUAL concat2(TEST_ASSERT_EQUAL_INT, BITWIDTH)

void setUp(void) {}
void tearDown(void) {}

static TYPE dividend;

void test(void) {
  PRINT_DIVIDEND;
  TYPE expected = get_expected_value(dividend);
  TYPE actual = FUNCTION_TO_TEST(dividend);
  TEST_EQUAL(expected, actual);
}

int main(void) {
  UNITY_BEGIN();

  dividend = INT_TYPE_MIN;
  RUN_TEST(test);

  dividend = INT_TYPE_MIN + 1;
  RUN_TEST(test);

  TYPE rem = INT_TYPE_MAX % abs_divisor;
  TYPE nbar = INT_TYPE_MAX - (rem + 1) % divisor;

  dividend = -nbar;
  RUN_TEST(test);
  
  TYPE lb = -101 * abs_divisor + 1;
  TYPE ub = -99 * abs_divisor - 1;
  for (dividend = lb; dividend <= ub; ++dividend)
    RUN_TEST(test);

  lb = -abs_divisor - 1;
  ub = abs_divisor + 1;
  for (dividend = lb; dividend <= ub; ++dividend)
    RUN_TEST(test);

  lb = 99 * abs_divisor + 1;
  ub = 101 * abs_divisor - 1;
  for (dividend = lb; dividend <= ub; ++dividend)
    RUN_TEST(test);

  dividend = nbar;
  RUN_TEST(test);

  dividend = INT_TYPE_MAX - 1;
  RUN_TEST(test);

  dividend = INT_TYPE_MAX;
  RUN_TEST(test);

  return UNITY_END();
}
