/**********************************************************
  Unit tests for division by multiplication assembly codes
  *********************************************************

  Copyright © 2026 Borderite
  Licnsed under the MIT License     

*/
#include "div_by_mult.h"
#include "unity.h"


static uint32_t unsigned_div_by_3_down_32_c(uint32_t n) { return n / 3; }
static uint32_t unsigned_div_by_3_up_32_c(uint32_t n) {
  uint32_t pos_flag = n > 0;
  return (n - pos_flag) / 3 + pos_flag;
}
static int32_t signed_div_by_3_zero_32_c(int32_t n) { return n / 3; }

static int32_t signed_div_by_3_down_32_c(int32_t n) {
  int32_t neg_flag = n < 0;
  return (n + neg_flag) / 3 - neg_flag;
}

static int32_t signed_div_by_3_up_32_c(int32_t n) {
  int32_t pos_flag = n > 0;
  return (n - pos_flag) / 3 + pos_flag;
}

static uint32_t unsigned_div_by_7_down_32_c(uint32_t n) { return n / 7; }
static uint32_t unsigned_div_by_7_up_32_c(uint32_t n) {
  uint32_t pos_flag = n > 0;
  return (n - pos_flag) / 7 + pos_flag;
}
static int32_t signed_div_by_7_zero_32_c(int32_t n) { return n / 7; }

static int32_t signed_div_by_7_down_32_c(int32_t n) {
  int32_t neg_flag = n < 0;
  return (n + neg_flag) / 7 - neg_flag;
}

static int32_t signed_div_by_7_up_32_c(int32_t n) {
  int32_t pos_flag = n > 0;
  return (n - pos_flag) / 7 + pos_flag;
}

static uint64_t unsigned_div_by_3_down_64_c(uint64_t n) { return n / 3; }

static uint64_t unsigned_div_by_3_up_64_c(uint64_t n) {
  uint64_t pos_flag = n > 0;
  return (n - pos_flag) / 3 + pos_flag;
}
static int64_t signed_div_by_3_zero_64_c(int64_t n) { return n / 3; }

static int64_t signed_div_by_3_down_64_c(int64_t n) {
  int64_t neg_flag = n < 0;
  return (n + neg_flag) / 3 - neg_flag;
}

static int64_t signed_div_by_3_up_64_c(int64_t n) {
  int64_t pos_flag = n > 0;
  return (n - pos_flag) / 3 + pos_flag;
}

static uint64_t unsigned_div_by_21_down_64_c(uint64_t n) { return n / 21; }
static uint64_t unsigned_div_by_21_up_64_c(uint64_t n) {
  uint64_t shift = n > 0;
  uint64_t nu = n - shift;
  return nu / 21 + shift;
}
static int64_t signed_div_by_21_zero_64_c(int64_t n) { return n / 21; }

static int64_t signed_div_by_21_down_64_c(int64_t n) {
  int64_t neg_flag = n < 0;
  return (n + neg_flag) / 21 - neg_flag;
}

static int64_t signed_div_by_21_up_64_c(int64_t n) {
  int64_t pos_flag = n > 0;
  return (n - pos_flag) / 21 + pos_flag;
}

void setUp(void) {}

void tearDown(void) {}

void test_unsigned_div_by_3_down_32_of_0(void) {
  const uint32_t dividend = 0;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_1(void) {
  const uint32_t dividend = 1;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_2(void) {
  const uint32_t dividend = 2;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_3(void) {
  const uint32_t dividend = 3;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_4(void) {
  const uint32_t dividend = 4;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_299(void) {
  const uint32_t dividend = 299;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_300(void) {
  const uint32_t dividend = 300;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_301(void) {
  const uint32_t dividend = 301;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_max_uint(void) {
  const uint32_t dividend = UINT32_MAX;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_max_uint_minus_1(void) {
  const uint32_t dividend = UINT32_MAX - 1;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_down_32_of_nbar(void) {
  uint32_t rem = (UINT32_MAX - 3 + 1) % 3;
  uint32_t nbar = UINT32_MAX - rem;
  const uint32_t dividend = nbar;
  const uint32_t expected = unsigned_div_by_3_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_0(void) {
  const uint32_t dividend = 0;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_1(void) {
  const uint32_t dividend = 1;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_2(void) {
  const uint32_t dividend = 2;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_3(void) {
  const uint32_t dividend = 3;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_4(void) {
  const uint32_t dividend = 4;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_299(void) {
  const uint32_t dividend = 299;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_300(void) {
  const uint32_t dividend = 300;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_301(void) {
  const uint32_t dividend = 301;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_max_uint(void) {
  const uint32_t dividend = UINT32_MAX;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_max_uint_minus_1(void) {
  const uint32_t dividend = UINT32_MAX - 1;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_3_up_32_of_nbar(void) {
  uint32_t rem = (UINT32_MAX - 3 + 1) % 3;
  uint32_t nbar = UINT32_MAX - rem;
  const uint32_t dividend = nbar;
  const uint32_t expected = unsigned_div_by_3_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_2(void) {
  const int32_t dividend = 2;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_3(void) {
  const int32_t dividend = 3;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_4(void) {
  const int32_t dividend = 4;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_299(void) {
  const int32_t dividend = 299;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_300(void) {
  const int32_t dividend = 300;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_301(void) {
  const int32_t dividend = 301;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_2(void) {
  const int32_t dividend = -2;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_3(void) {
  const int32_t dividend = -3;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_4(void) {
  const int32_t dividend = -4;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_299(void) {
  const int32_t dividend = -299;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_300(void) {
  const int32_t dividend = -300;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_301(void) {
  const int32_t dividend = -301;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_zero_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_zero_32_c(dividend);
  const int32_t quot = signed_div_by_3_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_2(void) {
  const int32_t dividend = 2;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_3(void) {
  const int32_t dividend = 3;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_4(void) {
  const int32_t dividend = 4;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_299(void) {
  const int32_t dividend = 299;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_300(void) {
  const int32_t dividend = 300;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_301(void) {
  const int32_t dividend = 301;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_2(void) {
  const int32_t dividend = -2;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_3(void) {
  const int32_t dividend = -3;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_4(void) {
  const int32_t dividend = -4;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_299(void) {
  const int32_t dividend = -299;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_300(void) {
  const int32_t dividend = -300;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_301(void) {
  const int32_t dividend = -301;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_down_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_down_32_c(dividend);
  const int32_t quot = signed_div_by_3_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_2(void) {
  const int32_t dividend = 2;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_3(void) {
  const int32_t dividend = 3;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_4(void) {
  const int32_t dividend = 4;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_299(void) {
  const int32_t dividend = 299;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_300(void) {
  const int32_t dividend = 300;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_301(void) {
  const int32_t dividend = 301;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_2(void) {
  const int32_t dividend = -2;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_3(void) {
  const int32_t dividend = -3;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_4(void) {
  const int32_t dividend = -4;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_299(void) {
  const int32_t dividend = -299;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_300(void) {
  const int32_t dividend = -300;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_301(void) {
  const int32_t dividend = -301;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_3_up_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 3 + 1) % 3;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_3_up_32_c(dividend);
  const int32_t quot = signed_div_by_3_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_0(void) {
  const uint32_t dividend = 0;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_1(void) {
  const uint32_t dividend = 1;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_6(void) {
  const uint32_t dividend = 6;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_7(void) {
  const uint32_t dividend = 7;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_8(void) {
  const uint32_t dividend = 8;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_699(void) {
  const uint32_t dividend = 699;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_700(void) {
  const uint32_t dividend = 700;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_701(void) {
  const uint32_t dividend = 701;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_max_uint(void) {
  const uint32_t dividend = UINT32_MAX;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_max_uint_minus_1(void) {
  const uint32_t dividend = UINT32_MAX - 1;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_down_32_of_nbar(void) {
  uint32_t rem = (UINT32_MAX - 7 + 1) % 7;
  uint32_t nbar = UINT32_MAX - rem;
  const uint32_t dividend = nbar;
  const uint32_t expected = unsigned_div_by_7_down_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_0(void) {
  const uint32_t dividend = 0;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_1(void) {
  const uint32_t dividend = 1;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_6(void) {
  const uint32_t dividend = 6;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_7(void) {
  const uint32_t dividend = 7;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_8(void) {
  const uint32_t dividend = 8;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_699(void) {
  const uint32_t dividend = 699;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_700(void) {
  const uint32_t dividend = 700;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_701(void) {
  const uint32_t dividend = 701;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_max_uint(void) {
  const uint32_t dividend = UINT32_MAX;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_max_uint_minus_1(void) {
  const uint32_t dividend = UINT32_MAX - 1;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_unsigned_div_by_7_up_32_of_nbar(void) {
  uint32_t rem = (UINT32_MAX - 7 + 1) % 7;
  uint32_t nbar = UINT32_MAX - rem;
  const uint32_t dividend = nbar;
  const uint32_t expected = unsigned_div_by_7_up_32_c(dividend);
  const uint32_t quot = unsigned_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_UINT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_6(void) {
  const int32_t dividend = 6;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_7(void) {
  const int32_t dividend = 7;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_8(void) {
  const int32_t dividend = 8;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_699(void) {
  const int32_t dividend = 699;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_700(void) {
  const int32_t dividend = 700;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_701(void) {
  const int32_t dividend = 701;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_6(void) {
  const int32_t dividend = -6;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_7(void) {
  const int32_t dividend = -7;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_8(void) {
  const int32_t dividend = -8;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_699(void) {
  const int32_t dividend = -699;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_700(void) {
  const int32_t dividend = -700;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_701(void) {
  const int32_t dividend = -701;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_zero_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_zero_32_c(dividend);
  const int32_t quot = signed_div_by_7_zero_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_6(void) {
  const int32_t dividend = 6;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_7(void) {
  const int32_t dividend = 7;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_8(void) {
  const int32_t dividend = 8;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_699(void) {
  const int32_t dividend = 699;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_700(void) {
  const int32_t dividend = 700;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_701(void) {
  const int32_t dividend = 701;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_6(void) {
  const int32_t dividend = -6;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_7(void) {
  const int32_t dividend = -7;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_8(void) {
  const int32_t dividend = -8;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_699(void) {
  const int32_t dividend = -699;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_700(void) {
  const int32_t dividend = -700;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_701(void) {
  const int32_t dividend = -701;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_down_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_down_32_c(dividend);
  const int32_t quot = signed_div_by_7_down_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_0(void) {
  const int32_t dividend = 0;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_1(void) {
  const int32_t dividend = 1;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_6(void) {
  const int32_t dividend = 6;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_7(void) {
  const int32_t dividend = 7;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_8(void) {
  const int32_t dividend = 8;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_699(void) {
  const int32_t dividend = 699;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_700(void) {
  const int32_t dividend = 700;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_701(void) {
  const int32_t dividend = 701;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_max_int(void) {
  const int32_t dividend = INT32_MAX;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_max_int_minus_1(void) {
  const int32_t dividend = INT32_MAX - 1;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = INT32_MAX - rem;
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_1(void) {
  const int32_t dividend = -1;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_6(void) {
  const int32_t dividend = -6;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_7(void) {
  const int32_t dividend = -7;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_8(void) {
  const int32_t dividend = -8;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_699(void) {
  const int32_t dividend = -699;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_700(void) {
  const int32_t dividend = -700;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_701(void) {
  const int32_t dividend = -701;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_min_int(void) {
  const int32_t dividend = INT32_MIN;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_min_int_plus_1(void) {
  const int32_t dividend = INT32_MIN + 1;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_signed_div_by_7_up_32_of_minus_nbar(void) {
  int32_t rem = (INT32_MAX - 7 + 1) % 7;
  int32_t nbar = -(INT32_MAX - rem);
  const int32_t dividend = nbar;
  const int32_t expected = signed_div_by_7_up_32_c(dividend);
  const int32_t quot = signed_div_by_7_up_32(dividend);
  TEST_ASSERT_EQUAL_INT32(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_0(void) {
  const uint64_t dividend = 0;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_1(void) {
  const uint64_t dividend = 1;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_2(void) {
  const uint64_t dividend = 2;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_3(void) {
  const uint64_t dividend = 3;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_4(void) {
  const uint64_t dividend = 4;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_299(void) {
  const uint64_t dividend = 299;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_300(void) {
  const uint64_t dividend = 300;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_301(void) {
  const uint64_t dividend = 301;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_max_uint(void) {
  const uint64_t dividend = UINT64_MAX;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_max_uint_minus_1(void) {
  const uint64_t dividend = UINT64_MAX - 1;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_down_64_of_nbar(void) {
  uint64_t rem = (UINT64_MAX - 3 + 1) % 3;
  uint64_t nbar = UINT64_MAX - rem;
  const uint64_t dividend = nbar;
  const uint64_t expected = unsigned_div_by_3_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_0(void) {
  const uint64_t dividend = 0;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_1(void) {
  const uint64_t dividend = 1;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_2(void) {
  const uint64_t dividend = 2;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_3(void) {
  const uint64_t dividend = 3;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_4(void) {
  const uint64_t dividend = 4;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_299(void) {
  const uint64_t dividend = 299;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_300(void) {
  const uint64_t dividend = 300;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_301(void) {
  const uint64_t dividend = 301;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_max_uint(void) {
  const uint64_t dividend = UINT64_MAX;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_max_uint_minus_1(void) {
  const uint64_t dividend = UINT64_MAX - 1;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_3_up_64_of_nbar(void) {
  uint64_t rem = (UINT64_MAX - 3 + 1) % 3;
  uint64_t nbar = UINT64_MAX - rem;
  const uint64_t dividend = nbar;
  const uint64_t expected = unsigned_div_by_3_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_2(void) {
  const int64_t dividend = 2;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_3(void) {
  const int64_t dividend = 3;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_4(void) {
  const int64_t dividend = 4;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_299(void) {
  const int64_t dividend = 299;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_300(void) {
  const int64_t dividend = 300;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_301(void) {
  const int64_t dividend = 301;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_2(void) {
  const int64_t dividend = -2;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_3(void) {
  const int64_t dividend = -3;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_4(void) {
  const int64_t dividend = -4;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_299(void) {
  const int64_t dividend = -299;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_300(void) {
  const int64_t dividend = -300;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_301(void) {
  const int64_t dividend = -301;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_zero_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_zero_64_c(dividend);
  const int64_t quot = signed_div_by_3_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_2(void) {
  const int64_t dividend = 2;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_3(void) {
  const int64_t dividend = 3;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_4(void) {
  const int64_t dividend = 4;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_299(void) {
  const int64_t dividend = 299;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_300(void) {
  const int64_t dividend = 300;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_301(void) {
  const int64_t dividend = 301;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_2(void) {
  const int64_t dividend = -2;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_3(void) {
  const int64_t dividend = -3;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_4(void) {
  const int64_t dividend = -4;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_299(void) {
  const int64_t dividend = -299;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_300(void) {
  const int64_t dividend = -300;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_301(void) {
  const int64_t dividend = -301;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_down_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_down_64_c(dividend);
  const int64_t quot = signed_div_by_3_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_2(void) {
  const int64_t dividend = 2;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_3(void) {
  const int64_t dividend = 3;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_4(void) {
  const int64_t dividend = 4;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_299(void) {
  const int64_t dividend = 299;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_300(void) {
  const int64_t dividend = 300;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_301(void) {
  const int64_t dividend = 301;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_2(void) {
  const int64_t dividend = -2;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_3(void) {
  const int64_t dividend = -3;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_4(void) {
  const int64_t dividend = -4;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_299(void) {
  const int64_t dividend = -299;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_300(void) {
  const int64_t dividend = -300;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_301(void) {
  const int64_t dividend = -301;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_3_up_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 3 + 1) % 3;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_3_up_64_c(dividend);
  const int64_t quot = signed_div_by_3_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_0(void) {
  const uint64_t dividend = 0;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_1(void) {
  const uint64_t dividend = 1;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_6(void) {
  const uint64_t dividend = 6;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_7(void) {
  const uint64_t dividend = 7;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_8(void) {
  const uint64_t dividend = 8;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_699(void) {
  const uint64_t dividend = 699;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_700(void) {
  const uint64_t dividend = 700;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_701(void) {
  const uint64_t dividend = 701;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_max_uint(void) {
  const uint64_t dividend = UINT64_MAX;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_max_uint_minus_1(void) {
  const uint64_t dividend = UINT64_MAX - 1;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_down_64_of_nbar(void) {
  uint64_t rem = (UINT64_MAX - 7 + 1) % 7;
  uint64_t nbar = UINT64_MAX - rem;
  const uint64_t dividend = nbar;
  const uint64_t expected = unsigned_div_by_21_down_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_0(void) {
  const uint64_t dividend = 0;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_1(void) {
  const uint64_t dividend = 1;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_6(void) {
  const uint64_t dividend = 6;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_7(void) {
  const uint64_t dividend = 7;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_8(void) {
  const uint64_t dividend = 8;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_699(void) {
  const uint64_t dividend = 699;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_700(void) {
  const uint64_t dividend = 700;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_701(void) {
  const uint64_t dividend = 701;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_max_uint(void) {
  const uint64_t dividend = UINT64_MAX;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_max_uint_minus_1(void) {
  const uint64_t dividend = UINT64_MAX - 1;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_unsigned_div_by_21_up_64_of_nbar(void) {
  uint64_t rem = (UINT64_MAX - 7 + 1) % 7;
  uint64_t nbar = UINT64_MAX - rem;
  const uint64_t dividend = nbar;
  const uint64_t expected = unsigned_div_by_21_up_64_c(dividend);
  const uint64_t quot = unsigned_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_UINT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_6(void) {
  const int64_t dividend = 6;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_7(void) {
  const int64_t dividend = 7;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_8(void) {
  const int64_t dividend = 8;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_699(void) {
  const int64_t dividend = 699;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_700(void) {
  const int64_t dividend = 700;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_701(void) {
  const int64_t dividend = 701;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_6(void) {
  const int64_t dividend = -6;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_7(void) {
  const int64_t dividend = -7;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_8(void) {
  const int64_t dividend = -8;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_699(void) {
  const int64_t dividend = -699;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_700(void) {
  const int64_t dividend = -700;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_701(void) {
  const int64_t dividend = -701;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_zero_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_zero_64_c(dividend);
  const int64_t quot = signed_div_by_21_zero_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_6(void) {
  const int64_t dividend = 6;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_7(void) {
  const int64_t dividend = 7;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_8(void) {
  const int64_t dividend = 8;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_699(void) {
  const int64_t dividend = 699;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_700(void) {
  const int64_t dividend = 700;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_701(void) {
  const int64_t dividend = 701;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_6(void) {
  const int64_t dividend = -6;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_7(void) {
  const int64_t dividend = -7;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_8(void) {
  const int64_t dividend = -8;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_699(void) {
  const int64_t dividend = -699;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_700(void) {
  const int64_t dividend = -700;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_701(void) {
  const int64_t dividend = -701;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_down_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_down_64_c(dividend);
  const int64_t quot = signed_div_by_21_down_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_0(void) {
  const int64_t dividend = 0;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_1(void) {
  const int64_t dividend = 1;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_6(void) {
  const int64_t dividend = 6;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_7(void) {
  const int64_t dividend = 7;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_8(void) {
  const int64_t dividend = 8;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_699(void) {
  const int64_t dividend = 699;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_700(void) {
  const int64_t dividend = 700;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_701(void) {
  const int64_t dividend = 701;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_max_int(void) {
  const int64_t dividend = INT64_MAX;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_max_int_minus_1(void) {
  const int64_t dividend = INT64_MAX - 1;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = INT64_MAX - rem;
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_1(void) {
  const int64_t dividend = -1;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_6(void) {
  const int64_t dividend = -6;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_7(void) {
  const int64_t dividend = -7;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_8(void) {
  const int64_t dividend = -8;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_699(void) {
  const int64_t dividend = -699;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_700(void) {
  const int64_t dividend = -700;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_701(void) {
  const int64_t dividend = -701;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_min_int(void) {
  const int64_t dividend = INT64_MIN;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_min_int_plus_1(void) {
  const int64_t dividend = INT64_MIN + 1;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

void test_signed_div_by_21_up_64_of_minus_nbar(void) {
  int64_t rem = (INT64_MAX - 7 + 1) % 7;
  int64_t nbar = -(INT64_MAX - rem);
  const int64_t dividend = nbar;
  const int64_t expected = signed_div_by_21_up_64_c(dividend);
  const int64_t quot = signed_div_by_21_up_64(dividend);
  TEST_ASSERT_EQUAL_INT64(expected, quot);
}

int main(void) {
  UNITY_BEGIN();
  RUN_TEST(test_unsigned_div_by_3_down_32_of_0);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_1);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_2);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_3);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_4);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_299);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_300);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_301);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_max_uint);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_3_down_32_of_nbar);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_0);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_1);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_2);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_3);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_4);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_299);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_300);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_301);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_max_uint);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_3_up_32_of_nbar);
  RUN_TEST(test_signed_div_by_3_zero_32_of_0);
  RUN_TEST(test_signed_div_by_3_zero_32_of_1);
  RUN_TEST(test_signed_div_by_3_zero_32_of_2);
  RUN_TEST(test_signed_div_by_3_zero_32_of_3);
  RUN_TEST(test_signed_div_by_3_zero_32_of_4);
  RUN_TEST(test_signed_div_by_3_zero_32_of_299);
  RUN_TEST(test_signed_div_by_3_zero_32_of_300);
  RUN_TEST(test_signed_div_by_3_zero_32_of_301);
  RUN_TEST(test_signed_div_by_3_zero_32_of_max_int);
  RUN_TEST(test_signed_div_by_3_zero_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_zero_32_of_nbar);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_1);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_2);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_3);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_4);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_299);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_300);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_301);
  RUN_TEST(test_signed_div_by_3_zero_32_of_min_int);
  RUN_TEST(test_signed_div_by_3_zero_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_zero_32_of_minus_nbar);
  RUN_TEST(test_signed_div_by_3_down_32_of_0);
  RUN_TEST(test_signed_div_by_3_down_32_of_1);
  RUN_TEST(test_signed_div_by_3_down_32_of_2);
  RUN_TEST(test_signed_div_by_3_down_32_of_3);
  RUN_TEST(test_signed_div_by_3_down_32_of_4);
  RUN_TEST(test_signed_div_by_3_down_32_of_299);
  RUN_TEST(test_signed_div_by_3_down_32_of_300);
  RUN_TEST(test_signed_div_by_3_down_32_of_301);
  RUN_TEST(test_signed_div_by_3_down_32_of_max_int);
  RUN_TEST(test_signed_div_by_3_down_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_down_32_of_nbar);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_1);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_2);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_3);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_4);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_299);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_300);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_301);
  RUN_TEST(test_signed_div_by_3_down_32_of_min_int);
  RUN_TEST(test_signed_div_by_3_down_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_down_32_of_minus_nbar);
  RUN_TEST(test_signed_div_by_3_up_32_of_0);
  RUN_TEST(test_signed_div_by_3_up_32_of_1);
  RUN_TEST(test_signed_div_by_3_up_32_of_2);
  RUN_TEST(test_signed_div_by_3_up_32_of_3);
  RUN_TEST(test_signed_div_by_3_up_32_of_299);
  RUN_TEST(test_signed_div_by_3_up_32_of_300);
  RUN_TEST(test_signed_div_by_3_up_32_of_301);
  RUN_TEST(test_signed_div_by_3_up_32_of_max_int);
  RUN_TEST(test_signed_div_by_3_up_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_up_32_of_nbar);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_1);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_2);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_3);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_4);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_299);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_300);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_301);
  RUN_TEST(test_signed_div_by_3_up_32_of_min_int);
  RUN_TEST(test_signed_div_by_3_up_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_up_32_of_minus_nbar);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_0);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_1);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_6);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_7);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_8);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_699);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_700);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_701);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_max_uint);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_7_down_32_of_nbar);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_0);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_1);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_6);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_7);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_8);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_699);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_700);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_701);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_max_uint);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_7_up_32_of_nbar);
  RUN_TEST(test_signed_div_by_7_zero_32_of_0);
  RUN_TEST(test_signed_div_by_7_zero_32_of_1);
  RUN_TEST(test_signed_div_by_7_zero_32_of_6);
  RUN_TEST(test_signed_div_by_7_zero_32_of_7);
  RUN_TEST(test_signed_div_by_7_zero_32_of_8);
  RUN_TEST(test_signed_div_by_7_zero_32_of_699);
  RUN_TEST(test_signed_div_by_7_zero_32_of_700);
  RUN_TEST(test_signed_div_by_7_zero_32_of_701);
  RUN_TEST(test_signed_div_by_7_zero_32_of_max_int);
  RUN_TEST(test_signed_div_by_7_zero_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_7_zero_32_of_nbar);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_1);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_6);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_7);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_8);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_699);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_700);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_701);
  RUN_TEST(test_signed_div_by_7_zero_32_of_min_int);
  RUN_TEST(test_signed_div_by_7_zero_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_7_zero_32_of_minus_nbar);
  RUN_TEST(test_signed_div_by_7_down_32_of_0);
  RUN_TEST(test_signed_div_by_7_down_32_of_1);
  RUN_TEST(test_signed_div_by_7_down_32_of_6);
  RUN_TEST(test_signed_div_by_7_down_32_of_7);
  RUN_TEST(test_signed_div_by_7_down_32_of_8);
  RUN_TEST(test_signed_div_by_7_down_32_of_699);
  RUN_TEST(test_signed_div_by_7_down_32_of_700);
  RUN_TEST(test_signed_div_by_7_down_32_of_701);
  RUN_TEST(test_signed_div_by_7_down_32_of_max_int);
  RUN_TEST(test_signed_div_by_7_down_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_7_down_32_of_nbar);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_1);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_6);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_7);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_8);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_699);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_700);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_701);
  RUN_TEST(test_signed_div_by_7_down_32_of_min_int);
  RUN_TEST(test_signed_div_by_7_down_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_7_down_32_of_minus_nbar);
  RUN_TEST(test_signed_div_by_7_up_32_of_0);
  RUN_TEST(test_signed_div_by_7_up_32_of_1);
  RUN_TEST(test_signed_div_by_7_up_32_of_6);
  RUN_TEST(test_signed_div_by_7_up_32_of_7);
  RUN_TEST(test_signed_div_by_7_up_32_of_8);
  RUN_TEST(test_signed_div_by_7_up_32_of_699);
  RUN_TEST(test_signed_div_by_7_up_32_of_700);
  RUN_TEST(test_signed_div_by_7_up_32_of_701);
  RUN_TEST(test_signed_div_by_7_up_32_of_max_int);
  RUN_TEST(test_signed_div_by_7_up_32_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_7_up_32_of_nbar);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_1);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_6);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_7);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_8);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_699);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_700);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_701);
  RUN_TEST(test_signed_div_by_7_up_32_of_min_int);
  RUN_TEST(test_signed_div_by_7_up_32_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_7_up_32_of_minus_nbar);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_0);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_1);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_2);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_3);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_4);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_299);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_300);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_301);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_max_uint);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_3_down_64_of_nbar);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_0);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_1);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_2);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_3);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_4);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_299);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_300);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_301);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_max_uint);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_3_up_64_of_nbar);
  RUN_TEST(test_signed_div_by_3_zero_64_of_0);
  RUN_TEST(test_signed_div_by_3_zero_64_of_1);
  RUN_TEST(test_signed_div_by_3_zero_64_of_2);
  RUN_TEST(test_signed_div_by_3_zero_64_of_3);
  RUN_TEST(test_signed_div_by_3_zero_64_of_4);
  RUN_TEST(test_signed_div_by_3_zero_64_of_299);
  RUN_TEST(test_signed_div_by_3_zero_64_of_300);
  RUN_TEST(test_signed_div_by_3_zero_64_of_301);
  RUN_TEST(test_signed_div_by_3_zero_64_of_max_int);
  RUN_TEST(test_signed_div_by_3_zero_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_zero_64_of_nbar);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_1);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_2);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_3);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_4);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_299);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_300);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_301);
  RUN_TEST(test_signed_div_by_3_zero_64_of_min_int);
  RUN_TEST(test_signed_div_by_3_zero_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_zero_64_of_minus_nbar);
  RUN_TEST(test_signed_div_by_3_down_64_of_0);
  RUN_TEST(test_signed_div_by_3_down_64_of_1);
  RUN_TEST(test_signed_div_by_3_down_64_of_2);
  RUN_TEST(test_signed_div_by_3_down_64_of_3);
  RUN_TEST(test_signed_div_by_3_down_64_of_4);
  RUN_TEST(test_signed_div_by_3_down_64_of_299);
  RUN_TEST(test_signed_div_by_3_down_64_of_300);
  RUN_TEST(test_signed_div_by_3_down_64_of_301);
  RUN_TEST(test_signed_div_by_3_down_64_of_max_int);
  RUN_TEST(test_signed_div_by_3_down_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_down_64_of_nbar);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_1);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_2);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_3);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_4);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_299);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_300);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_301);
  RUN_TEST(test_signed_div_by_3_down_64_of_min_int);
  RUN_TEST(test_signed_div_by_3_down_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_down_64_of_minus_nbar);
  RUN_TEST(test_signed_div_by_3_up_64_of_0);
  RUN_TEST(test_signed_div_by_3_up_64_of_1);
  RUN_TEST(test_signed_div_by_3_up_64_of_2);
  RUN_TEST(test_signed_div_by_3_up_64_of_3);
  RUN_TEST(test_signed_div_by_3_up_64_of_299);
  RUN_TEST(test_signed_div_by_3_up_64_of_300);
  RUN_TEST(test_signed_div_by_3_up_64_of_301);
  RUN_TEST(test_signed_div_by_3_up_64_of_max_int);
  RUN_TEST(test_signed_div_by_3_up_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_3_up_64_of_nbar);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_1);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_2);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_3);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_4);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_299);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_300);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_301);
  RUN_TEST(test_signed_div_by_3_up_64_of_min_int);
  RUN_TEST(test_signed_div_by_3_up_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_3_up_64_of_minus_nbar);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_0);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_1);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_6);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_7);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_8);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_699);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_700);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_701);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_max_uint);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_21_down_64_of_nbar);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_0);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_1);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_6);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_7);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_8);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_699);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_700);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_701);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_max_uint);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_max_uint_minus_1);
  RUN_TEST(test_unsigned_div_by_21_up_64_of_nbar);
  RUN_TEST(test_signed_div_by_21_zero_64_of_0);
  RUN_TEST(test_signed_div_by_21_zero_64_of_1);
  RUN_TEST(test_signed_div_by_21_zero_64_of_6);
  RUN_TEST(test_signed_div_by_21_zero_64_of_7);
  RUN_TEST(test_signed_div_by_21_zero_64_of_8);
  RUN_TEST(test_signed_div_by_21_zero_64_of_699);
  RUN_TEST(test_signed_div_by_21_zero_64_of_700);
  RUN_TEST(test_signed_div_by_21_zero_64_of_701);
  RUN_TEST(test_signed_div_by_21_zero_64_of_max_int);
  RUN_TEST(test_signed_div_by_21_zero_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_21_zero_64_of_nbar);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_1);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_6);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_7);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_8);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_699);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_700);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_701);
  RUN_TEST(test_signed_div_by_21_zero_64_of_min_int);
  RUN_TEST(test_signed_div_by_21_zero_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_21_zero_64_of_minus_nbar);
  RUN_TEST(test_signed_div_by_21_down_64_of_0);
  RUN_TEST(test_signed_div_by_21_down_64_of_1);
  RUN_TEST(test_signed_div_by_21_down_64_of_6);
  RUN_TEST(test_signed_div_by_21_down_64_of_7);
  RUN_TEST(test_signed_div_by_21_down_64_of_8);
  RUN_TEST(test_signed_div_by_21_down_64_of_699);
  RUN_TEST(test_signed_div_by_21_down_64_of_700);
  RUN_TEST(test_signed_div_by_21_down_64_of_701);
  RUN_TEST(test_signed_div_by_21_down_64_of_max_int);
  RUN_TEST(test_signed_div_by_21_down_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_21_down_64_of_nbar);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_1);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_6);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_7);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_8);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_699);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_700);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_701);
  RUN_TEST(test_signed_div_by_21_down_64_of_min_int);
  RUN_TEST(test_signed_div_by_21_down_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_21_down_64_of_minus_nbar);
  RUN_TEST(test_signed_div_by_21_up_64_of_0);
  RUN_TEST(test_signed_div_by_21_up_64_of_1);
  RUN_TEST(test_signed_div_by_21_up_64_of_6);
  RUN_TEST(test_signed_div_by_21_up_64_of_7);
  RUN_TEST(test_signed_div_by_21_up_64_of_8);
  RUN_TEST(test_signed_div_by_21_up_64_of_699);
  RUN_TEST(test_signed_div_by_21_up_64_of_700);
  RUN_TEST(test_signed_div_by_21_up_64_of_701);
  RUN_TEST(test_signed_div_by_21_up_64_of_max_int);
  RUN_TEST(test_signed_div_by_21_up_64_of_max_int_minus_1);
  RUN_TEST(test_signed_div_by_21_up_64_of_nbar);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_1);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_6);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_7);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_8);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_699);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_700);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_701);
  RUN_TEST(test_signed_div_by_21_up_64_of_min_int);
  RUN_TEST(test_signed_div_by_21_up_64_of_min_int_plus_1);
  RUN_TEST(test_signed_div_by_21_up_64_of_minus_nbar);
  return UNITY_END();
}

