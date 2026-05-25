#include <errno.h>

#include "check_basic_suites.h"

START_TEST(test_strerror_common_errors) {
  int errnums[] = {0, 1, 2, 5, 13, 22};
  int count = sizeof(errnums) / sizeof(errnums[0]);
  for (int i = 0; i < count; i++) {
    char* result1 = s21_strerror(errnums[i]);
    char* result2 = strerror(errnums[i]);
    ck_assert_str_eq(result1, result2);
  }
}
END_TEST

START_TEST(test_strerror_zero) {
  char* result1 = s21_strerror(0);
  char* result2 = strerror(0);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_enoent) {
  char* result1 = s21_strerror(2);
  char* result2 = strerror(2);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_eacces) {
  char* result1 = s21_strerror(13);
  char* result2 = strerror(13);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_enfile) {
  char* result1 = s21_strerror(23);
  char* result2 = strerror(23);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_negative) {
  char* result1 = s21_strerror(-1);
  char* result2 = strerror(-1);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_large_positive) {
  char* result1 = s21_strerror(999);
  char* result2 = strerror(999);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_large_negative) {
  char* result1 = s21_strerror(-999);
  char* result2 = strerror(-999);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_edge_low) {
  char* result1 = s21_strerror(-1000);
  char* result2 = strerror(-1000);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_edge_high) {
  char* result1 = s21_strerror(1000);
  char* result2 = strerror(1000);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_sequential) {
  for (int i = 0; i < 10; i++) {
    char* result1 = s21_strerror(i);
    char* result2 = strerror(i);
    ck_assert_str_eq(result1, result2);
  }
}
END_TEST

START_TEST(test_strerror_max_int) {
  char* result1 = s21_strerror(2147483647);
  char* result2 = strerror(2147483647);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_min_int) {
  char* result1 = s21_strerror(-2147483647);
  char* result2 = strerror(-2147483647);
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strerror_common_unix_errors) {
  int errors[] = {EACCES, EEXIST, EINVAL, ENOENT, ENOMEM};
  int count = sizeof(errors) / sizeof(errors[0]);
  for (int i = 0; i < count; i++) {
    char* result1 = s21_strerror(errors[i]);
    char* result2 = strerror(errors[i]);
    ck_assert_str_eq(result1, result2);
  }
}
END_TEST

START_TEST(test_strerror_consistency) {
  char* result1 = s21_strerror(5);
  char* result2 = s21_strerror(5);
  ck_assert_str_eq(result1, result2);
}
END_TEST

Suite* strerror_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strerror");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strerror_common_errors);
  tcase_add_test(tc_core, test_strerror_zero);
  tcase_add_test(tc_core, test_strerror_enoent);
  tcase_add_test(tc_core, test_strerror_eacces);
  tcase_add_test(tc_core, test_strerror_enfile);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strerror_negative);
  tcase_add_test(tc_edge, test_strerror_large_positive);
  tcase_add_test(tc_edge, test_strerror_large_negative);
  tcase_add_test(tc_edge, test_strerror_edge_low);
  tcase_add_test(tc_edge, test_strerror_edge_high);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strerror_sequential);
  tcase_add_test(tc_special, test_strerror_max_int);
  tcase_add_test(tc_special, test_strerror_min_int);
  tcase_add_test(tc_special, test_strerror_common_unix_errors);
  tcase_add_test(tc_special, test_strerror_consistency);
  suite_add_tcase(s, tc_special);

  return s;
}