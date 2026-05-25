#include "check_basic_suites.h"

// Базовый тест (ваш оригинальный)
START_TEST(memchr_basic) {
  char* str = "abcdiefghijklmnop";
  int c = 'g';
  s21_size_t n = 10;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

START_TEST(memchr_basic2) {
  char* str = "500";
  int c = 'g';
  s21_size_t n = 4;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест на символ в начале
START_TEST(memchr_at_start) {
  char* str = "hello world";
  int c = 'h';
  s21_size_t n = 11;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест на символ в конце
START_TEST(memchr_at_end) {
  char* str = "hello world";
  int c = 'd';
  s21_size_t n = 11;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест на отсутствующий символ
START_TEST(memchr_not_found) {
  char* str = "hello world";
  int c = 'z';
  s21_size_t n = 11;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с нулевым байтом
START_TEST(memchr_null_byte) {
  char str[] = "hello\0world";
  int c = 'w';
  s21_size_t n = 12;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с нулевым размером
START_TEST(memchr_zero_size) {
  char* str = "hello world";
  int c = 'h';
  s21_size_t n = 0;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с поиском нулевого терминатора
START_TEST(memchr_null_terminator) {
  char* str = "hello";
  int c = '\0';
  s21_size_t n = 6;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с ограниченным поиском (символ за пределами n)
START_TEST(memchr_out_of_bounds) {
  char* str = "hello world";
  int c = 'd';
  s21_size_t n = 5;  // Ищем только в "hello"
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с большим буфером
START_TEST(memchr_large_buffer) {
  char str[1000];
  memset(str, 'a', 999);
  str[500] = 'X';
  str[999] = '\0';

  int c = 'X';
  s21_size_t n = 1000;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест на первый символ в повторяющейся последовательности
START_TEST(memchr_repeated_chars) {
  char* str = "aaaaaaaab";
  int c = 'b';
  s21_size_t n = 9;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с специальными символами
START_TEST(memchr_special_chars) {
  char* str = "hello\nworld\t!";
  int c = '\n';
  s21_size_t n = 12;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест на граничное значение n
START_TEST(memchr_boundary_n) {
  char* str = "hello";
  int c = 'o';
  s21_size_t n = 5;  // 'o' находится на позиции 4, n=5 включает его
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

// Тест с числовыми значениями
START_TEST(memchr_numeric) {
  char str[] = {1, 2, 3, 4, 5, 0};
  int c = 3;
  s21_size_t n = 6;
  void* ptr1 = s21_memchr(str, c, n);
  void* ptr2 = memchr(str, c, n);
  ck_assert_ptr_eq(ptr1, ptr2);
}
END_TEST

Suite* memchr_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("memchr");

  // Основные тесты
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, memchr_basic);
  tcase_add_test(tc_core, memchr_basic2);
  tcase_add_test(tc_core, memchr_at_start);
  tcase_add_test(tc_core, memchr_at_end);
  tcase_add_test(tc_core, memchr_not_found);
  tcase_add_test(tc_core, memchr_repeated_chars);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, memchr_zero_size);
  tcase_add_test(tc_edge, memchr_out_of_bounds);
  tcase_add_test(tc_edge, memchr_boundary_n);
  tcase_add_test(tc_edge, memchr_large_buffer);
  suite_add_tcase(s, tc_edge);

  // Специальные случаи
  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, memchr_null_byte);
  tcase_add_test(tc_special, memchr_null_terminator);
  tcase_add_test(tc_special, memchr_special_chars);
  tcase_add_test(tc_special, memchr_numeric);
  suite_add_tcase(s, tc_special);

  return s;
}
