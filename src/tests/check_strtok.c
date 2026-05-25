#include "check_basic_suites.h"

START_TEST(test_strtok_basic) {
  char str1[] = "hello world test";
  char str2[] = "hello world test";
  char* result1 = s21_strtok(str1, " ");
  char* result2 = strtok(str2, " ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, " ");
  result2 = strtok(S21_NULL, " ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, " ");
  result2 = strtok(S21_NULL, " ");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_multiple_delimiters) {
  char str1[] = "hello,world;test";
  char str2[] = "hello,world;test";
  char* result1 = s21_strtok(str1, ",;");
  char* result2 = strtok(str2, ",;");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",;");
  result2 = strtok(S21_NULL, ",;");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",;");
  result2 = strtok(S21_NULL, ",;");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_consecutive_delimiters) {
  char str1[] = "hello,,world,,test";
  char str2[] = "hello,,world,,test";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_no_delimiters) {
  char str1[] = "hello";
  char str2[] = "hello";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_only_delimiters) {
  char str1[] = ",,,,";
  char str2[] = ",,,,";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_empty_string) {
  char str1[] = "";
  char str2[] = "";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_empty_delimiters) {
  char str1[] = "hello world";
  char str2[] = "hello world";
  char* result1 = s21_strtok(str1, "");
  char* result2 = strtok(str2, "");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_special_chars) {
  char str1[] = "hello\nworld\ttest";
  char str2[] = "hello\nworld\ttest";
  char* result1 = s21_strtok(str1, "\n\t");
  char* result2 = strtok(str2, "\n\t");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, "\n\t");
  result2 = strtok(S21_NULL, "\n\t");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, "\n\t");
  result2 = strtok(S21_NULL, "\n\t");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_mixed_delimiters) {
  char str1[] = "hello, world; test";
  char str2[] = "hello, world; test";
  char* result1 = s21_strtok(str1, ",; ");
  char* result2 = strtok(str2, ",; ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",; ");
  result2 = strtok(S21_NULL, ",; ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",; ");
  result2 = strtok(S21_NULL, ",; ");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_delimiters_at_ends) {
  char str1[] = ",hello,world,";
  char str2[] = ",hello,world,";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_single_token) {
  char str1[] = "hello";
  char str2[] = "hello";
  char* result1 = s21_strtok(str1, " ");
  char* result2 = strtok(str2, " ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, " ");
  result2 = strtok(S21_NULL, " ");
  ck_assert_ptr_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_numbers) {
  char str1[] = "123,456,789";
  char str2[] = "123,456,789";
  char* result1 = s21_strtok(str1, ",");
  char* result2 = strtok(str2, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, ",");
  result2 = strtok(S21_NULL, ",");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_with_null_byte) {
  char str1[] = "hello\0world\0test";
  char str2[] = "hello\0world\0test";
  char* result1 = s21_strtok(str1, "\0");
  char* result2 = strtok(str2, "\0");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_different_delimiter_sets) {
  char str1[] = "hello world-test";
  char str2[] = "hello world-test";
  char* result1 = s21_strtok(str1, " ");
  char* result2 = strtok(str2, " ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(S21_NULL, "-");
  result2 = strtok(S21_NULL, "-");
  ck_assert_str_eq(result1, result2);
}
END_TEST

START_TEST(test_strtok_reset_with_new_string) {
  char str1[] = "first string";
  char str2[] = "first string";
  char str3[] = "second string";
  char str4[] = "second string";

  char* result1 = s21_strtok(str1, " ");
  char* result2 = strtok(str2, " ");
  ck_assert_str_eq(result1, result2);

  result1 = s21_strtok(str3, " ");
  result2 = strtok(str4, " ");
  ck_assert_str_eq(result1, result2);
}
END_TEST

Suite* strtok_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strtok");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strtok_basic);
  tcase_add_test(tc_core, test_strtok_multiple_delimiters);
  tcase_add_test(tc_core, test_strtok_consecutive_delimiters);
  tcase_add_test(tc_core, test_strtok_no_delimiters);
  tcase_add_test(tc_core, test_strtok_single_token);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strtok_only_delimiters);
  tcase_add_test(tc_edge, test_strtok_empty_string);
  tcase_add_test(tc_edge, test_strtok_empty_delimiters);
  tcase_add_test(tc_edge, test_strtok_delimiters_at_ends);
  tcase_add_test(tc_edge, test_strtok_with_null_byte);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strtok_special_chars);
  tcase_add_test(tc_special, test_strtok_mixed_delimiters);
  tcase_add_test(tc_special, test_strtok_numbers);
  tcase_add_test(tc_special, test_strtok_different_delimiter_sets);
  tcase_add_test(tc_special, test_strtok_reset_with_new_string);
  suite_add_tcase(s, tc_special);

  return s;
}