#include "check_basic_suites.h"

START_TEST(test_insert_basic) {
  char* src = "hello world";
  char* str = " beautiful";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello beautiful world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_at_beginning) {
  char* src = "world";
  char* str = "hello ";
  s21_size_t index = 0;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_at_end) {
  char* src = "hello";
  char* str = " world";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_empty_src) {
  char* src = "";
  char* str = "hello";
  s21_size_t index = 0;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_empty_str) {
  char* src = "hello world";
  char* str = "";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_both_empty) {
  char* src = "";
  char* str = "";
  s21_size_t index = 0;
  char* result1 = s21_insert(src, str, index);
  char* expected = "";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_single_char) {
  char* src = "helo world";
  char* str = "l";
  s21_size_t index = 3;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_special_chars) {
  char* src = "hello world";
  char* str = "\n\t!";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello\n\t! world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_numbers) {
  char* src = "hello world";
  char* str = "123";
  s21_size_t index = 6;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello 123world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_middle) {
  char* src = "hello world";
  char* str = " beautiful";
  s21_size_t index = 6;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello  beautifulworld";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_long_string) {
  char* src = "hello";
  char* str = " this is a very long string to insert";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello this is a very long string to insert";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_index_zero_empty_src) {
  char* src = "";
  char* str = "test";
  s21_size_t index = 0;
  char* result1 = s21_insert(src, str, index);
  char* expected = "test";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_repeated_chars) {
  char* src = "aaaa";
  char* str = "bbbb";
  s21_size_t index = 2;
  char* result1 = s21_insert(src, str, index);
  char* expected = "aabbbbaa";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_punctuation) {
  char* src = "hello world";
  char* str = ",!";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello,! world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

START_TEST(test_insert_spaces) {
  char* src = "helloworld";
  char* str = " ";
  s21_size_t index = 5;
  char* result1 = s21_insert(src, str, index);
  char* expected = "hello world";
  ck_assert_str_eq(result1, expected);
  free(result1);
}
END_TEST

Suite* insert_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("insert");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_insert_basic);
  tcase_add_test(tc_core, test_insert_at_beginning);
  tcase_add_test(tc_core, test_insert_at_end);
  tcase_add_test(tc_core, test_insert_middle);
  tcase_add_test(tc_core, test_insert_single_char);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_insert_empty_src);
  tcase_add_test(tc_edge, test_insert_empty_str);
  tcase_add_test(tc_edge, test_insert_both_empty);
  tcase_add_test(tc_edge, test_insert_index_zero_empty_src);
  tcase_add_test(tc_edge, test_insert_long_string);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_insert_special_chars);
  tcase_add_test(tc_special, test_insert_numbers);
  tcase_add_test(tc_special, test_insert_repeated_chars);
  tcase_add_test(tc_special, test_insert_punctuation);
  tcase_add_test(tc_special, test_insert_spaces);
  suite_add_tcase(s, tc_special);

  return s;
}