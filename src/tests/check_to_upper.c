#include "check_basic_suites.h"

START_TEST(test_to_upper_basic) {
  char* str = "hello world";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO WORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_empty) {
  char* str = "";
  char* result1 = s21_to_upper(str);
  ck_assert_str_eq(result1, "");
  free(result1);
}
END_TEST

START_TEST(test_to_upper_already_upper) {
  char* str = "HELLO WORLD";
  char* result1 = s21_to_upper(str);
  ck_assert_str_eq(result1, "HELLO WORLD");
  free(result1);
}
END_TEST

START_TEST(test_to_upper_mixed_case) {
  char* str = "HeLlO WoRlD";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO WORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_numbers) {
  char* str = "hello123world";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO123WORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_special_chars) {
  char* str = "hello!@#$world";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO!@#$WORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_spaces) {
  char* str = "  hello  world  ";
  char* result1 = s21_to_upper(str);
  char* expected = "  HELLO  WORLD  ";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_single_char) {
  char* str = "a";
  char* result1 = s21_to_upper(str);
  ck_assert_str_eq(result1, "A");
  free(result1);
}
END_TEST

START_TEST(test_to_upper_only_lower) {
  char* str = "abcdefghijklmnopqrstuvwxyz";
  char* result1 = s21_to_upper(str);
  char* expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_only_upper) {
  char* str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* result1 = s21_to_upper(str);
  ck_assert_str_eq(result1, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  free(result1);
}
END_TEST

START_TEST(test_to_upper_with_newline) {
  char* str = "hello\nworld";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO\nWORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_with_tab) {
  char* str = "hello\tworld";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO\tWORLD";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_punctuation) {
  char* str = "hello, world!";
  char* result1 = s21_to_upper(str);
  char* expected = "HELLO, WORLD!";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_mixed_chars) {
  char* str = "aBcDeFgHiJkLmNoPqRsTuVwXyZ";
  char* result1 = s21_to_upper(str);
  char* expected = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_to_upper_long_string) {
  char* str = "this is a very long string for testing purposes";
  char* result1 = s21_to_upper(str);
  char* expected = "THIS IS A VERY LONG STRING FOR TESTING PURPOSES";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

Suite* to_upper_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("to_upper");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_to_upper_basic);
  tcase_add_test(tc_core, test_to_upper_already_upper);
  tcase_add_test(tc_core, test_to_upper_mixed_case);
  tcase_add_test(tc_core, test_to_upper_only_lower);
  tcase_add_test(tc_core, test_to_upper_only_upper);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_to_upper_empty);
  tcase_add_test(tc_edge, test_to_upper_single_char);
  tcase_add_test(tc_edge, test_to_upper_long_string);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_to_upper_numbers);
  tcase_add_test(tc_special, test_to_upper_special_chars);
  tcase_add_test(tc_special, test_to_upper_spaces);
  tcase_add_test(tc_special, test_to_upper_with_newline);
  tcase_add_test(tc_special, test_to_upper_with_tab);
  tcase_add_test(tc_special, test_to_upper_punctuation);
  tcase_add_test(tc_special, test_to_upper_mixed_chars);
  suite_add_tcase(s, tc_special);

  return s;
}