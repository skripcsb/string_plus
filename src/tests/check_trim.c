#include "check_basic_suites.h"

START_TEST(test_trim_basic) {
  char* src = "  hello world  ";
  char* trim_chars = " ";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_no_trim_needed) {
  char* src = "hello world";
  char* trim_chars = " ";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_empty_src) {
  char* src = "";
  char* trim_chars = " ";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_empty_trim_chars) {
  char* src = "  hello world  ";
  char* trim_chars = "";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "  hello world  ";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_both_empty) {
  char* src = "";
  char* trim_chars = "";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_multiple_chars) {
  char* src = "xyzhello worldxyz";
  char* trim_chars = "xyz";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_only_trim_chars) {
  char* src = "   ";
  char* trim_chars = " ";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_special_chars) {
  char* src = "\n\thello world\n\t";
  char* trim_chars = "\n\t";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_mixed_chars) {
  char* src = " \t\nhello world\t\n ";
  char* trim_chars = " \t\n";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_numbers) {
  char* src = "123hello world123";
  char* trim_chars = "123";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_punctuation) {
  char* src = "!!!hello world!!!";
  char* trim_chars = "!";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_no_matching_chars) {
  char* src = "hello world";
  char* trim_chars = "xyz";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_single_char) {
  char* src = "aaa";
  char* trim_chars = "a";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_partial_match) {
  char* src = "abchello worldcba";
  char* trim_chars = "abc";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_trim_complex_chars) {
  char* src = "!@#hello world#@!";
  char* trim_chars = "!@#";
  char* result1 = s21_trim(src, trim_chars);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

Suite* trim_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("trim");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_trim_basic);
  tcase_add_test(tc_core, test_trim_no_trim_needed);
  tcase_add_test(tc_core, test_trim_multiple_chars);
  tcase_add_test(tc_core, test_trim_only_trim_chars);
  tcase_add_test(tc_core, test_trim_no_matching_chars);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_trim_empty_src);
  tcase_add_test(tc_edge, test_trim_empty_trim_chars);
  tcase_add_test(tc_edge, test_trim_both_empty);
  tcase_add_test(tc_edge, test_trim_single_char);
  tcase_add_test(tc_edge, test_trim_partial_match);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_trim_special_chars);
  tcase_add_test(tc_special, test_trim_mixed_chars);
  tcase_add_test(tc_special, test_trim_numbers);
  tcase_add_test(tc_special, test_trim_punctuation);
  tcase_add_test(tc_special, test_trim_complex_chars);
  suite_add_tcase(s, tc_special);

  return s;
}