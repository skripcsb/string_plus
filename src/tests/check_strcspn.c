#include "check_basic_suites.h"

START_TEST(test_strcspn_basic) {
  char* str = "hello world";
  char* reject = "aeiou";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_no_match) {
  char* str = "hello world";
  char* reject = "xyz";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_first_char_match) {
  char* str = "apple";
  char* reject = "a";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_last_char_match) {
  char* str = "hello";
  char* reject = "o";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_middle_match) {
  char* str = "hello world";
  char* reject = " ";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_empty_string) {
  char* str = "";
  char* reject = "abc";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_empty_reject) {
  char* str = "hello world";
  char* reject = "";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_both_empty) {
  char* str = "";
  char* reject = "";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_multiple_reject_chars) {
  char* str = "hello world";
  char* reject = "aeiou ";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_special_chars) {
  char* str = "hello\nworld\t!";
  char* reject = "\n\t";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_cyrillic) {
  char* str = "привет мир";
  char* reject = "м";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_numeric_chars) {
  char* str = "test123";
  char* reject = "123";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_with_null_byte) {
  char str[] = "hello\0world";
  char* reject = "w";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_all_chars_reject) {
  char* str = "hello";
  char* reject = "helo";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strcspn_reject_includes_null) {
  char* str = "hello";
  char reject[] = "aeiou\0xyz";
  s21_size_t result1 = s21_strcspn(str, reject);
  s21_size_t result2 = strcspn(str, reject);
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite* strcspn_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strcspn");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strcspn_basic);
  tcase_add_test(tc_core, test_strcspn_no_match);
  tcase_add_test(tc_core, test_strcspn_first_char_match);
  tcase_add_test(tc_core, test_strcspn_last_char_match);
  tcase_add_test(tc_core, test_strcspn_middle_match);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strcspn_empty_string);
  tcase_add_test(tc_edge, test_strcspn_empty_reject);
  tcase_add_test(tc_edge, test_strcspn_both_empty);
  tcase_add_test(tc_edge, test_strcspn_multiple_reject_chars);
  tcase_add_test(tc_edge, test_strcspn_all_chars_reject);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strcspn_special_chars);
  tcase_add_test(tc_special, test_strcspn_cyrillic);
  tcase_add_test(tc_special, test_strcspn_numeric_chars);
  tcase_add_test(tc_special, test_strcspn_with_null_byte);
  tcase_add_test(tc_special, test_strcspn_reject_includes_null);
  suite_add_tcase(s, tc_special);

  return s;
}