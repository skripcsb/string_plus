#include "check_basic_suites.h"

// Базовый тест - копирование строки
START_TEST(test_memcpy_basic) {
  char src[] = "hello world";
  char dest1[20];
  char dest2[20];

  void* result1 = s21_memcpy(dest1, src, 12);
  void* result2 = memcpy(dest2, src, 12);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Тест - частичное копирование
START_TEST(test_memcpy_partial) {
  char src[] = "hello world";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);

  dest1[5] = '\0';
  dest2[5] = '\0';

  ck_assert_str_eq(dest1, "hello");
  ck_assert_str_eq(dest2, "hello");
}
END_TEST

// Тест - нулевое количество байт
START_TEST(test_memcpy_zero_bytes) {
  char src[] = "hello";
  char dest1[10] = "test";
  char dest2[10] = "test";

  void* result1 = s21_memcpy(dest1, src, 0);
  void* result2 = memcpy(dest2, src, 0);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_str_eq(dest1, "test");  // dest не должен измениться
}
END_TEST

// Тест - бинарные данные
START_TEST(test_memcpy_binary_data) {
  unsigned char src[] = {0x01, 0x02, 0x03, 0x04, 0x05};
  unsigned char dest1[10] = {0};
  unsigned char dest2[10] = {0};

  s21_memcpy(dest1, src, 5);
  memcpy(dest2, src, 5);

  ck_assert_mem_eq(dest1, dest2, 5);
  ck_assert_int_eq(dest1[0], 0x01);
  ck_assert_int_eq(dest1[4], 0x05);
}
END_TEST

// Тест - большой буфер
START_TEST(test_memcpy_large_buffer) {
  char src[1000];
  char dest1[1000];
  char dest2[1000];

  // Заполняем источник данными
  for (int i = 0; i < 1000; i++) {
    src[i] = (char)(i % 256);
  }

  void* result1 = s21_memcpy(dest1, src, 1000);
  void* result2 = memcpy(dest2, src, 1000);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_mem_eq(dest1, dest2, 1000);
}
END_TEST

// Тест - проверка возвращаемого значения
START_TEST(test_memcpy_return_value) {
  char src[] = "test";
  char dest1[10];
  char dest2[10];

  void* result1 = s21_memcpy(dest1, src, 5);
  void* result2 = memcpy(dest2, src, 5);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
}
END_TEST

// Тест - копирование в середину буфера
START_TEST(test_memcpy_to_middle) {
  char src[] = "12345";
  char dest1[20] = "abcdefghij";
  char dest2[20] = "abcdefghij";

  s21_memcpy(dest1 + 3, src, 5);
  memcpy(dest2 + 3, src, 5);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Тест - копирование из середины буфера
START_TEST(test_memcpy_from_middle) {
  char src[] = "hello world";
  char dest1[20];
  char dest2[20];

  s21_memcpy(dest1, src + 6, 5);
  memcpy(dest2, src + 6, 5);

  dest1[5] = '\0';
  dest2[5] = '\0';

  ck_assert_str_eq(dest1, "world");
  ck_assert_str_eq(dest2, "world");
}
END_TEST

// Тест - один байт
START_TEST(test_memcpy_single_byte) {
  char src[] = "a";
  char dest1[5] = {0};
  char dest2[5] = {0};

  s21_memcpy(dest1, src, 1);
  memcpy(dest2, src, 1);

  ck_assert_int_eq(dest1[0], 'a');
  ck_assert_int_eq(dest2[0], 'a');
}
END_TEST

// Тест - специальные символы
START_TEST(test_memcpy_special_chars) {
  char src[] = "a\n\t\r\xFF";
  char dest1[10];
  char dest2[10];

  s21_memcpy(dest1, src, 6);
  memcpy(dest2, src, 6);

  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

// Тест - перекрывающиеся области (memcpy не гарантирует корректность)
START_TEST(test_memcpy_overlapping) {
  char data1[] = "abcdefghij";
  char data2[] = "abcdefghij";

  // Копируем в пределах одного буфера
  // Поведение memcpy с overlapping areas - undefined
  s21_memcpy(data1 + 2, data1, 5);
  memcpy(data2 + 2, data2, 5);

  // Просто проверяем что не упало
  ck_assert_ptr_ne(s21_memcpy, NULL);
}
END_TEST

// Тест - пустая строка
START_TEST(test_memcpy_empty_string) {
  char src[] = "";
  char dest1[10] = "test";
  char dest2[10] = "test";

  s21_memcpy(dest1, src, 1);  // Копируем только нулевой терминатор
  memcpy(dest2, src, 1);

  ck_assert_int_eq(dest1[0], '\0');
  ck_assert_int_eq(dest2[0], '\0');
}
END_TEST

Suite* memcpy_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("memcpy");

  // Основные тесты
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_memcpy_basic);
  tcase_add_test(tc_core, test_memcpy_partial);
  tcase_add_test(tc_core, test_memcpy_return_value);
  tcase_add_test(tc_core, test_memcpy_to_middle);
  tcase_add_test(tc_core, test_memcpy_from_middle);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_memcpy_zero_bytes);
  tcase_add_test(tc_edge, test_memcpy_single_byte);
  tcase_add_test(tc_edge, test_memcpy_empty_string);
  tcase_add_test(tc_edge, test_memcpy_large_buffer);
  suite_add_tcase(s, tc_edge);

  // Специальные случаи
  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_memcpy_binary_data);
  tcase_add_test(tc_special, test_memcpy_special_chars);
  tcase_add_test(tc_special, test_memcpy_overlapping);
  suite_add_tcase(s, tc_special);

  return s;
}