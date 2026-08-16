#define INT_TYPE_MAX concat3(INT, BITWIDTH, _MAX)
#define INT_TYPE_MIN concat3(INT, BITWIDTH, _MIN)
#define TEST_EQUAL concat2(TEST_ASSERT_EQUAL_INT, BITWIDTH)

void setUp(void) {}
void tearDown(void) {}

TYPE dividend;

void test(void) {
  TYPE expected = get_expected_value(divisor);
  TYPE actual = FUNCTION_TO_TEST(divisor);
  printf("dividend = %u\n", dividend);
  TEST_EQUAL(expected, actual);
}

int main(void) {
  UNITY_BEGIN();

  TYPE divisor_minus_one = divisor - 1;
  TYPE divisor_plus_one = divisor + 1;
  for (dividend = divisor_minus_one; dividend <= divisor_plus_one; ++dividend)
    RUN_TEST(test);

  TYPE divisor_times_99_plus_1 = 99 * divisor + 1;
  TYPE divisor_times_101_minus_1 = 101 * divisor - 1;
  for (dividend = divisor_times_99_plus_1;
       dividend <= divisor_times_101_minus_1; ++dividend)
    RUN_TEST(test);
  for (dividend = -divisor_times_99_plus_1;
       dividend >= -divisor_times_101_minus_1; --dividend)
    RUN_TEST(test);

  TYPE rem = INT_TYPE_MAX % divisor;
  TYPE nbar = INT_TYPE_MAX - (rem + 1) % divisor;

  dividend = nbar;
  RUN_TEST(test);

  rem = INT_TYPE_MIN % divisor;
  nbar = INT_TYPE_MIN - (rem - 1) % divisor;

  dividend = nbar;
  RUN_TEST(test);

  dividend = INT_TYPE_MAX - 1;
  RUN_TEST(test);

  dividend = INT_TYPE_MAX;
  RUN_TEST(test);

  dividend = INT_TYPE_MIN + 1;
  RUN_TEST(test);

  dividend = INT_TYPE_MIN;
  RUN_TEST(test);

  return UNITY_END();
}
