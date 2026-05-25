#include "check_basic_suites.h"

START_TEST(test_strstr_basic) {
  char* haystack = "hello world";
  char* needle = "world";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_not_found) {
  char* haystack = "hello world";
  char* needle = "test";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_at_start) {
  char* haystack = "hello world";
  char* needle = "hello";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_at_end) {
  char* haystack = "hello world";
  char* needle = "world";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_empty_needle) {
  char* haystack = "hello world";
  char* needle = "";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_empty_haystack) {
  char* haystack = "";
  char* needle = "hello";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_both_empty) {
  char* haystack = "";
  char* needle = "";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_partial_match) {
  char* haystack = "hello world";
  char* needle = "lo wo";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_single_char) {
  char* haystack = "hello world";
  char* needle = "o";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_special_chars) {
  char* haystack = "hello\nworld\t!";
  char* needle = "\nworld";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_repeated_pattern) {
  char* haystack = "ababababab";
  char* needle = "abab";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_with_null_byte) {
  char haystack[] = "hello\0world";
  char* needle = "world";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_needle_larger_than_haystack) {
  char* haystack = "hello";
  char* needle = "hello world";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_exact_match) {
  char* haystack = "hello";
  char* needle = "hello";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strstr_multiple_occurrences) {
  char* haystack = "hello hello world";
  char* needle = "hello";
  char* result1 = s21_strstr(haystack, needle);
  char* result2 = strstr(haystack, needle);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

Suite* strstr_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strstr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strstr_basic);
  tcase_add_test(tc_core, test_strstr_not_found);
  tcase_add_test(tc_core, test_strstr_at_start);
  tcase_add_test(tc_core, test_strstr_at_end);
  tcase_add_test(tc_core, test_strstr_partial_match);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strstr_empty_needle);
  tcase_add_test(tc_edge, test_strstr_empty_haystack);
  tcase_add_test(tc_edge, test_strstr_both_empty);
  tcase_add_test(tc_edge, test_strstr_single_char);
  tcase_add_test(tc_edge, test_strstr_needle_larger_than_haystack);
  tcase_add_test(tc_edge, test_strstr_exact_match);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strstr_special_chars);
  tcase_add_test(tc_special, test_strstr_repeated_pattern);
  tcase_add_test(tc_special, test_strstr_with_null_byte);
  tcase_add_test(tc_special, test_strstr_multiple_occurrences);
  suite_add_tcase(s, tc_special);

  return s;
}