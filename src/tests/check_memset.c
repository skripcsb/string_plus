#include "check_basic_suites.h"

// Базовый тест - заполнение нулями
START_TEST(test_memset_basic_zero) {
  char str1[20] = "hello world";
  char str2[20] = "hello world";

  void* result1 = s21_memset(str1, 0, 5);
  void* result2 = memset(str2, 0, 5);

  ck_assert_ptr_eq(result1, str1);
  ck_assert_ptr_eq(result2, str2);
  ck_assert_mem_eq(str1, str2, 20);
}
END_TEST

// Тест - заполнение символом
START_TEST(test_memset_with_char) {
  char str1[20] = "hello world";
  char str2[20] = "hello world";

  s21_memset(str1, 'X', 5);
  memset(str2, 'X', 5);

  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(str1, "XXXXX world");
}
END_TEST

// Тест - заполнение всего буфера
START_TEST(test_memset_entire_buffer) {
  char str1[15];
  char str2[15];

  s21_memset(str1, 'A', 15);
  memset(str2, 'A', 15);

  ck_assert_mem_eq(str1, str2, 15);
}
END_TEST

// Тест - заполнение числовым значением
START_TEST(test_memset_numeric_value) {
  unsigned char buf1[10];
  unsigned char buf2[10];

  s21_memset(buf1, 0xAB, 10);
  memset(buf2, 0xAB, 10);

  ck_assert_mem_eq(buf1, buf2, 10);

  // Проверяем что все байты заполнены правильно
  for (int i = 0; i < 10; i++) {
    ck_assert_int_eq(buf1[i], 0xAB);
    ck_assert_int_eq(buf2[i], 0xAB);
  }
}
END_TEST

// Тест - отрицательное значение
START_TEST(test_memset_negative_value) {
  char buf1[10];
  char buf2[10];

  s21_memset(buf1, -10, 10);
  memset(buf2, -10, 10);

  ck_assert_mem_eq(buf1, buf2, 10);
}
END_TEST

// Тест - заполнение одного байта
START_TEST(test_memset_single_byte) {
  char str1[] = "hello";
  char str2[] = "hello";

  s21_memset(str1, 'X', 1);
  memset(str2, 'X', 1);

  ck_assert_str_eq(str1, str2);
  ck_assert_str_eq(str1, "Xello");
}
END_TEST

// Тест - большой буфер
START_TEST(test_memset_large_buffer) {
  char buf1[1000];
  char buf2[1000];

  s21_memset(buf1, 0x7F, 1000);
  memset(buf2, 0x7F, 1000);

  ck_assert_mem_eq(buf1, buf2, 1000);
}
END_TEST

// Тест - возвращаемое значение
START_TEST(test_memset_return_value) {
  char buffer[20];

  void* result1 = s21_memset(buffer, 'Z', 10);
  void* result2 = memset(buffer, 'Z', 10);

  ck_assert_ptr_eq(result1, buffer);
  ck_assert_ptr_eq(result2, buffer);
}
END_TEST

// Тест - заполнение части буфера
START_TEST(test_memset_partial_fill) {
  char buf1[20] = "abcdefghijklmnop";
  char buf2[20] = "abcdefghijklmnop";

  s21_memset(buf1 + 5, '1', 5);
  memset(buf2 + 5, '1', 5);

  ck_assert_str_eq(buf1, buf2);
  ck_assert_str_eq(buf1, "abcde11111klmnop");
}
END_TEST

// Тест - граничное значение (заполнение до конца буфера)
START_TEST(test_memset_to_end) {
  char buf1[10] = {0};
  char buf2[10] = {0};

  s21_memset(buf1, 'Y', 9);  // Не трогаем последний байт (нулевой терминатор)
  memset(buf2, 'Y', 9);

  ck_assert_mem_eq(buf1, buf2, 10);
  ck_assert_int_eq(buf1[9], 0);  // Последний байт должен остаться 0
}
END_TEST

// Тест - специальные символы
START_TEST(test_memset_special_chars) {
  char buf1[10];
  char buf2[10];

  s21_memset(buf1, '\n', 10);
  memset(buf2, '\n', 10);

  ck_assert_mem_eq(buf1, buf2, 10);
}
END_TEST

// Тест - максимальное значение unsigned char
START_TEST(test_memset_max_uchar) {
  unsigned char buf1[5];
  unsigned char buf2[5];

  s21_memset(buf1, 0xFF, 5);
  memset(buf2, 0xFF, 5);

  ck_assert_mem_eq(buf1, buf2, 5);

  for (int i = 0; i < 5; i++) {
    ck_assert_int_eq(buf1[i], 0xFF);
  }
}
END_TEST

Suite* memset_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("memset");

  // Основные тесты
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_memset_basic_zero);
  tcase_add_test(tc_core, test_memset_with_char);
  tcase_add_test(tc_core, test_memset_entire_buffer);
  tcase_add_test(tc_core, test_memset_return_value);
  tcase_add_test(tc_core, test_memset_partial_fill);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_memset_single_byte);
  tcase_add_test(tc_edge, test_memset_large_buffer);
  tcase_add_test(tc_edge, test_memset_to_end);
  suite_add_tcase(s, tc_edge);

  // Специальные случаи
  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_memset_numeric_value);
  tcase_add_test(tc_special, test_memset_negative_value);
  tcase_add_test(tc_special, test_memset_special_chars);
  tcase_add_test(tc_special, test_memset_max_uchar);
  suite_add_tcase(s, tc_special);

  return s;
}