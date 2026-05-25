#include "check_basic_suites.h"

START_TEST(test_strpbrk_basic) {
  char* str = "hello world";
  char* accept = "aeiou";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_no_match) {
  char* str = "hello world";
  char* accept = "xyz";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_first_char) {
  char* str = "apple";
  char* accept = "a";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_last_char) {
  char* str = "hello";
  char* accept = "o";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_middle_char) {
  char* str = "hello world";
  char* accept = " ";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_multiple_accept) {
  char* str = "hello world";
  char* accept = "ow";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_empty_string) {
  char* str = "";
  char* accept = "abc";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_empty_accept) {
  char* str = "hello world";
  char* accept = "";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_both_empty) {
  char* str = "";
  char* accept = "";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_special_chars) {
  char* str = "hello\nworld\t!";
  char* accept = "\n\t";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_cyrillic) {
  char* str = "привет мир";
  char* accept = "м";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_numeric) {
  char* str = "test123";
  char* accept = "123";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_with_null_byte) {
  char str[] = "hello\0world";
  char* accept = "w";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_all_chars_in_accept) {
  char* str = "hello";
  char* accept = "helo";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strpbrk_accept_includes_null) {
  char* str = "hello";
  char accept[] = "aeiou\0xyz";
  char* result1 = s21_strpbrk(str, accept);
  char* result2 = strpbrk(str, accept);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

Suite* strpbrk_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strpbrk");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strpbrk_basic);
  tcase_add_test(tc_core, test_strpbrk_no_match);
  tcase_add_test(tc_core, test_strpbrk_first_char);
  tcase_add_test(tc_core, test_strpbrk_last_char);
  tcase_add_test(tc_core, test_strpbrk_middle_char);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strpbrk_empty_string);
  tcase_add_test(tc_edge, test_strpbrk_empty_accept);
  tcase_add_test(tc_edge, test_strpbrk_both_empty);
  tcase_add_test(tc_edge, test_strpbrk_multiple_accept);
  tcase_add_test(tc_edge, test_strpbrk_all_chars_in_accept);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strpbrk_special_chars);
  tcase_add_test(tc_special, test_strpbrk_cyrillic);
  tcase_add_test(tc_special, test_strpbrk_numeric);
  tcase_add_test(tc_special, test_strpbrk_with_null_byte);
  tcase_add_test(tc_special, test_strpbrk_accept_includes_null);
  suite_add_tcase(s, tc_special);

  return s;
}