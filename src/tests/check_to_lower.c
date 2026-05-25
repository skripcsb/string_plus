#include "check_basic_suites.h"

START_TEST(test_to_lower_basic) {
  char* str = "HELLO WORLD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_empty) {
  char* str = "";
  char* result1 = s21_to_lower(str);
  ck_assert_str_eq(result1, "");
  free(result1);
}
END_TEST

START_TEST(test_to_lower_already_lower) {
  char* str = "hello world";
  char* result1 = s21_to_lower(str);
  ck_assert_str_eq(result1, "hello world");
  free(result1);
}
END_TEST

START_TEST(test_to_lower_mixed_case) {
  char* str = "HeLlO WoRlD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_numbers) {
  char* str = "HELLO123WORLD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello123world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_special_chars) {
  char* str = "HELLO!@#$WORLD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello!@#$world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_spaces) {
  char* str = "  HELLO  WORLD  ";
  char* result1 = s21_to_lower(str);
  char* expected = "  hello  world  ";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_single_char) {
  char* str = "A";
  char* result1 = s21_to_lower(str);
  ck_assert_str_eq(result1, "a");
  free(result1);
}
END_TEST

START_TEST(test_to_lower_only_upper) {
  char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* result1 = s21_to_lower(str);
  char* expected = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_only_lower) {
  char* str = "abcdefghijklmnopqrstuvwxyz";
  char* result1 = s21_to_lower(str);
  ck_assert_str_eq(result1, "abcdefghijklmnopqrstuvwxyz");
  free(result1);
}
END_TEST

START_TEST(test_to_lower_with_newline) {
  char* str = "HELLO\nWORLD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello\nworld";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_with_tab) {
  char* str = "HELLO\tWORLD";
  char* result1 = s21_to_lower(str);
  char* expected = "hello\tworld";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_punctuation) {
  char* str = "HELLO, WORLD!";
  char* result1 = s21_to_lower(str);
  char* expected = "hello, world!";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_mixed_chars) {
  char* str = "AbCdEfGhIjKlMnOpQrStUvWxYz";
  char* result1 = s21_to_lower(str);
  char* expected = "abcdefghijklmnopqrstuvwxyz";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_lower_long_string) {
  char* str = "THIS IS A VERY LONG STRING FOR TESTING PURPOSES";
  char* result1 = s21_to_lower(str);
  char* expected = "this is a very long string for testing purposes";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

Suite* to_lower_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("to_lower");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_to_lower_basic);
  tcase_add_test(tc_core, test_to_lower_already_lower);
  tcase_add_test(tc_core, test_to_lower_mixed_case);
  tcase_add_test(tc_core, test_to_lower_only_upper);
  tcase_add_test(tc_core, test_to_lower_only_lower);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_to_lower_empty);
  tcase_add_test(tc_edge, test_to_lower_single_char);
  tcase_add_test(tc_edge, test_to_lower_long_string);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_to_lower_numbers);
  tcase_add_test(tc_special, test_to_lower_special_chars);
  tcase_add_test(tc_special, test_to_lower_spaces);
  tcase_add_test(tc_special, test_to_lower_with_newline);
  tcase_add_test(tc_special, test_to_lower_with_tab);
  tcase_add_test(tc_special, test_to_lower_punctuation);
  tcase_add_test(tc_special, test_to_lower_mixed_chars);
  suite_add_tcase(s, tc_special);

  return s;
}