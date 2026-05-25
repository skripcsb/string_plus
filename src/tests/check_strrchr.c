#include "check_basic_suites.h"

START_TEST(test_strrchr_basic) {
  char* str = "hello world";
  int c = 'o';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_not_found) {
  char* str = "hello world";
  int c = 'z';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_first_char) {
  char* str = "hello world";
  int c = 'h';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_last_char) {
  char* str = "hello world";
  int c = 'd';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_null_terminator) {
  char* str = "hello";
  int c = '\0';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_last_occurrence) {
  char* str = "hello world";
  int c = 'l';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_empty_string) {
  char* str = "";
  int c = 'a';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_null_in_empty) {
  char* str = "";
  int c = '\0';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_negative_char) {
  char str[] = {65, -10, 66, -10, 67, 0};
  int c = -10;
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_special_chars) {
  char* str = "hello\nworld\n!";
  int c = '\n';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_numeric_value) {
  char str[] = {1, 2, 3, 2, 1, 0};
  int c = 2;
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_large_int) {
  char* str = "hello";
  int c = 1000;
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_repeated_chars) {
  char* str = "aaaaaaaab";
  int c = 'a';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strrchr_with_null_byte) {
  char str[] = "hello\0world";
  int c = 'o';
  char* result1 = s21_strrchr(str, c);
  char* result2 = strrchr(str, c);
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

Suite* strrchr_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strrchr");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strrchr_basic);
  tcase_add_test(tc_core, test_strrchr_not_found);
  tcase_add_test(tc_core, test_strrchr_first_char);
  tcase_add_test(tc_core, test_strrchr_last_char);
  tcase_add_test(tc_core, test_strrchr_last_occurrence);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strrchr_null_terminator);
  tcase_add_test(tc_edge, test_strrchr_empty_string);
  tcase_add_test(tc_edge, test_strrchr_null_in_empty);
  tcase_add_test(tc_edge, test_strrchr_large_int);
  tcase_add_test(tc_edge, test_strrchr_repeated_chars);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strrchr_negative_char);
  tcase_add_test(tc_special, test_strrchr_special_chars);
  tcase_add_test(tc_special, test_strrchr_numeric_value);
  tcase_add_test(tc_special, test_strrchr_with_null_byte);
  suite_add_tcase(s, tc_special);

  return s;
}