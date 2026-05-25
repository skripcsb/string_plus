#include "check_basic_suites.h"

START_TEST(test_strncpy_basic) {
  char src[] = "hello world";
  char dest1[20];
  char dest2[20];
  char* result1 = s21_strncpy(dest1, src, 12);
  char* result2 = strncpy(dest2, src, 12);
  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_strncpy_partial) {
  char src[] = "hello world";
  char dest1[20];
  char dest2[20];
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  dest1[5] = '\0';
  dest2[5] = '\0';
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_strncpy_n_greater_than_src) {
  char src[] = "hello";
  char dest1[20];
  char dest2[20];
  s21_strncpy(dest1, src, 10);
  strncpy(dest2, src, 10);
  ck_assert_mem_eq(dest1, dest2, 10);
}
END_TEST

START_TEST(test_strncpy_exact_length) {
  char src[] = "hello";
  char dest1[10];
  char dest2[10];
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_strncpy_padding_with_zeros) {
  char src[] = "hi";
  char dest1[10];
  char dest2[10];
  s21_strncpy(dest1, src, 5);
  strncpy(dest2, src, 5);
  ck_assert_mem_eq(dest1, dest2, 5);
}
END_TEST

START_TEST(test_strncpy_empty_src) {
  char src[] = "";
  char dest1[10] = "test";
  char dest2[10] = "test";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_mem_eq(dest1, dest2, 3);
}
END_TEST

START_TEST(test_strncpy_return_value) {
  char src[] = "test";
  char dest1[10];
  char dest2[10];
  char* result1 = s21_strncpy(dest1, src, 5);
  char* result2 = strncpy(dest2, src, 5);
  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
}
END_TEST

START_TEST(test_strncpy_overwrite) {
  char src[] = "new";
  char dest1[10] = "old_data";
  char dest2[10] = "old_data";
  s21_strncpy(dest1, src, 3);
  strncpy(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(test_strncpy_special_chars) {
  char src[] = "a\n\t\xFF";
  char dest1[10];
  char dest2[10];
  s21_strncpy(dest1, src, 4);
  strncpy(dest2, src, 4);
  ck_assert_mem_eq(dest1, dest2, 4);
}
END_TEST

START_TEST(test_strncpy_cyrillic) {
  char src[] = "привет";
  char dest1[20];
  char dest2[20];
  s21_strncpy(dest1, src, 6);
  strncpy(dest2, src, 6);
  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(test_strncpy_single_char) {
  char src[] = "a";
  char dest1[5] = {0};
  char dest2[5] = {0};
  s21_strncpy(dest1, src, 1);
  strncpy(dest2, src, 1);
  ck_assert_int_eq(dest1[0], 'a');
  ck_assert_int_eq(dest2[0], 'a');
}
END_TEST

START_TEST(test_strncpy_large_n) {
  char src[] = "small";
  char dest1[20];
  char dest2[20];
  s21_strncpy(dest1, src, 15);
  strncpy(dest2, src, 15);
  ck_assert_mem_eq(dest1, dest2, 15);
}
END_TEST

START_TEST(test_strncpy_with_null_byte) {
  char src[] = "hello\0world";
  char dest1[20];
  char dest2[20];
  s21_strncpy(dest1, src, 11);
  strncpy(dest2, src, 11);
  ck_assert_mem_eq(dest1, dest2, 11);
}
END_TEST

START_TEST(test_strncpy_buffer_boundary) {
  char src[] = "hello world";
  char dest1[10];
  char dest2[10];
  s21_strncpy(dest1, src, 9);
  strncpy(dest2, src, 9);
  ck_assert_mem_eq(dest1, dest2, 9);
}
END_TEST

Suite* strncpy_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strncpy");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strncpy_basic);
  tcase_add_test(tc_core, test_strncpy_partial);
  tcase_add_test(tc_core, test_strncpy_exact_length);
  tcase_add_test(tc_core, test_strncpy_return_value);
  tcase_add_test(tc_core, test_strncpy_overwrite);
  suite_add_tcase(s, tc_core);

  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strncpy_n_greater_than_src);
  tcase_add_test(tc_edge, test_strncpy_padding_with_zeros);
  tcase_add_test(tc_edge, test_strncpy_empty_src);
  tcase_add_test(tc_edge, test_strncpy_single_char);
  tcase_add_test(tc_edge, test_strncpy_large_n);
  tcase_add_test(tc_edge, test_strncpy_buffer_boundary);
  suite_add_tcase(s, tc_edge);

  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strncpy_special_chars);
  tcase_add_test(tc_special, test_strncpy_cyrillic);
  tcase_add_test(tc_special, test_strncpy_with_null_byte);
  suite_add_tcase(s, tc_special);

  return s;
}