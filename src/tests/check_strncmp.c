#include "check_basic_suites.h"

START_TEST(test_strncmp_identical) {
  char* str1 = "hello world";
  char* str2 = "hello world";
  s21_size_t n = 11;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_different) {
  char* str1 = "hello";
  char* str2 = "world";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_partial_match) {
  char* str1 = "hello world";
  char* str2 = "hello there";
  s21_size_t n = 11;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_first_char_diff) {
  char* str1 = "apple";
  char* str2 = "bpple";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_last_char_diff) {
  char* str1 = "test1";
  char* str2 = "test2";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_zero_size) {
  char* str1 = "hello";
  char* str2 = "world";
  s21_size_t n = 0;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_partial_comparison) {
  char* str1 = "hello world";
  char* str2 = "hello there";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_n_greater_than_length) {
  char* str1 = "hello";
  char* str2 = "hello";
  s21_size_t n = 10;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_empty_strings) {
  char* str1 = "";
  char* str2 = "";
  s21_size_t n = 1;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_first_empty) {
  char* str1 = "";
  char* str2 = "hello";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_second_empty) {
  char* str1 = "hello";
  char* str2 = "";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_special_chars) {
  char* str1 = "hello\nworld";
  char* str2 = "hello\tworld";
  s21_size_t n = 11;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_cyrillic) {
  char* str1 = "привет";
  char* str2 = "привет";
  s21_size_t n = 6;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_with_null_bytes) {
  char str1[] = "hello\0world";
  char str2[] = "hello\0there";
  s21_size_t n = 11;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strncmp_sign_check) {
  char* str1 = "apple";
  char* str2 = "banana";
  s21_size_t n = 5;
  int result1 = s21_strncmp(str1, str2, n);
  int result2 = strncmp(str1, str2, n);
  ck_assert((result1 < 0 && result2 < 0) || (result1 > 0 && result2 > 0));
}
END_TEST

Suite* strncmp_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strncmp");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strncmp_identical);
  tcase_add_test(tc_core, test_strncmp_different);
  tcase_add_test(tc_core, test_strncmp_partial_match);
  tcase_add_test(tc_core, test_strncmp_first_char_diff);
  tcase_add_test(tc_core, test_strncmp_last_char_diff);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strncmp_zero_size);
  tcase_add_test(tc_edge, test_strncmp_partial_comparison);
  tcase_add_test(tc_edge, test_strncmp_n_greater_than_length);
  tcase_add_test(tc_edge, test_strncmp_empty_strings);
  tcase_add_test(tc_edge, test_strncmp_first_empty);
  tcase_add_test(tc_edge, test_strncmp_second_empty);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strncmp_special_chars);
  tcase_add_test(tc_special, test_strncmp_cyrillic);
  tcase_add_test(tc_special, test_strncmp_with_null_bytes);
  tcase_add_test(tc_special, test_strncmp_sign_check);
  suite_add_tcase(s, tc_special);

  return s;
}