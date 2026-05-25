#include "check_basic_suites.h"

START_TEST(test_strlen_basic) {
  char* str = "hello world";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_empty) {
  char* str = "";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_single_char) {
  char* str = "a";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_long_string) {
  char* str = "this is a very long string for testing purposes";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_special_chars) {
  char* str = "hello\nworld\t!";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_cyrillic) {
  char* str = "привет мир";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_numbers) {
  char* str = "1234567890";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_mixed_chars) {
  char* str = "Hello123!@# World";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_with_spaces) {
  char* str = "   hello   world   ";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_only_spaces) {
  char* str = "     ";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_null_byte_middle) {
  char str[] = "hello\0world";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_unicode) {
  char* str = "Hello 🌍 World";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_repeated_chars) {
  char* str = "aaaaaaaaaaaaaaaaaaaa";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_escape_chars) {
  char* str = "hello\\nworld\\t!";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_strlen_punctuation) {
  char* str = "!@#$%^&*()_+-=[]{}|;:,.<>?";
  s21_size_t result1 = s21_strlen(str);
  s21_size_t result2 = strlen(str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite* strlen_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strlen");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strlen_basic);
  tcase_add_test(tc_core, test_strlen_empty);
  tcase_add_test(tc_core, test_strlen_single_char);
  tcase_add_test(tc_core, test_strlen_long_string);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strlen_only_spaces);
  tcase_add_test(tc_edge, test_strlen_with_spaces);
  tcase_add_test(tc_edge, test_strlen_null_byte_middle);
  tcase_add_test(tc_edge, test_strlen_repeated_chars);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strlen_special_chars);
  tcase_add_test(tc_special, test_strlen_cyrillic);
  tcase_add_test(tc_special, test_strlen_numbers);
  tcase_add_test(tc_special, test_strlen_mixed_chars);
  tcase_add_test(tc_special, test_strlen_unicode);
  tcase_add_test(tc_special, test_strlen_escape_chars);
  tcase_add_test(tc_special, test_strlen_punctuation);
  suite_add_tcase(s, tc_special);

  return s;
}