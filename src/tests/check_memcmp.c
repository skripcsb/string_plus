#include "check_basic_suites.h"

// Базовый тест - одинаковые строки
START_TEST(test_memcmp_identical) {
  char* str1 = "hello world";
  char* str2 = "hello world";
  s21_size_t n = 11;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - разные строки
START_TEST(test_memcmp_different) {
  char* str1 = "hello";
  char* str2 = "world";
  s21_size_t n = 5;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - частично одинаковые строки
START_TEST(test_memcmp_partial_match) {
  char* str1 = "hello world";
  char* str2 = "hello there";
  s21_size_t n = 11;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - первый символ отличается
START_TEST(test_memcmp_first_char_diff) {
  char* str1 = "apple";
  char* str2 = "bpple";
  s21_size_t n = 5;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - последний символ отличается
START_TEST(test_memcmp_last_char_diff) {
  char* str1 = "test1";
  char* str2 = "test2";
  s21_size_t n = 5;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - сравнение нулевого размера
START_TEST(test_memcmp_zero_size) {
  char* str1 = "hello";
  char* str2 = "world";
  s21_size_t n = 0;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - сравнение части строки
START_TEST(test_memcmp_partial_comparison) {
  char* str1 = "hello world";
  char* str2 = "hello there";
  s21_size_t n = 5;  // Сравниваем только "hello"
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест с бинарными данными
START_TEST(test_memcmp_binary_data) {
  unsigned char data1[] = {0x01, 0x02, 0x03, 0x04};
  unsigned char data2[] = {0x01, 0x02, 0x03, 0x05};
  s21_size_t n = 4;
  int result1 = s21_memcmp(data1, data2, n);
  int result2 = memcmp(data1, data2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - одинаковые бинарные данные
START_TEST(test_memcmp_identical_binary) {
  unsigned char data1[] = {0xFF, 0xFE, 0xFD, 0xFC};
  unsigned char data2[] = {0xFF, 0xFE, 0xFD, 0xFC};
  s21_size_t n = 4;
  int result1 = s21_memcmp(data1, data2, n);
  int result2 = memcmp(data1, data2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - строка с нулевым байтом
START_TEST(test_memcmp_with_null_byte) {
  char str1[] = "hello\0world";
  char str2[] = "hello\0there";
  s21_size_t n = 11;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - отрицательные значения символов
START_TEST(test_memcmp_negative_chars) {
  char str1[] = {65, -10, 66, 0};
  char str2[] = {65, -20, 66, 0};
  s21_size_t n = 3;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - большие буферы
START_TEST(test_memcmp_large_buffers) {
  char str1[1000];
  char str2[1000];
  memset(str1, 'A', 999);
  memset(str2, 'A', 999);
  str1[999] = '\0';
  str2[999] = '\0';

  // Делаем один символ разным
  str2[500] = 'B';

  s21_size_t n = 1000;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// Тест - первый байт больше
START_TEST(test_memcmp_first_greater) {
  char* str1 = "b";
  char* str2 = "a";
  s21_size_t n = 1;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);

  // Оба должны быть > 0
  ck_assert((result1 > 0 && result2 > 0) || (result1 < 0 && result2 < 0));
}
END_TEST

// Тест - первый байт меньше
START_TEST(test_memcmp_first_less) {
  char* str1 = "a";
  char* str2 = "b";
  s21_size_t n = 1;
  int result1 = s21_memcmp(str1, str2, n);
  int result2 = memcmp(str1, str2, n);

  // Оба должны быть < 0
  ck_assert((result1 < 0 && result2 < 0) || (result1 > 0 && result2 > 0));
}
END_TEST

Suite* memcmp_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_binary;

  s = suite_create("memcmp");

  // Основные тесты со строками
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_memcmp_identical);
  tcase_add_test(tc_core, test_memcmp_different);
  tcase_add_test(tc_core, test_memcmp_partial_match);
  tcase_add_test(tc_core, test_memcmp_first_char_diff);
  tcase_add_test(tc_core, test_memcmp_last_char_diff);
  tcase_add_test(tc_core, test_memcmp_partial_comparison);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_memcmp_zero_size);
  tcase_add_test(tc_edge, test_memcmp_with_null_byte);
  tcase_add_test(tc_edge, test_memcmp_negative_chars);
  tcase_add_test(tc_edge, test_memcmp_large_buffers);
  tcase_add_test(tc_edge, test_memcmp_first_greater);
  tcase_add_test(tc_edge, test_memcmp_first_less);
  suite_add_tcase(s, tc_edge);

  // Бинарные данные
  tc_binary = tcase_create("Binary Data");
  tcase_add_test(tc_binary, test_memcmp_binary_data);
  tcase_add_test(tc_binary, test_memcmp_identical_binary);
  suite_add_tcase(s, tc_binary);

  return s;
}