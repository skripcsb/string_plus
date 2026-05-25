#include "check_basic_suites.h"

// Базовый тест - конкатенация строк
START_TEST(test_strncat_basic) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = " world";

  char* result1 = s21_strncat(dest1, src, 6);
  char* result2 = strncat(dest2, src, 6);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello world");
}
END_TEST

// Тест - частичная конкатенация
START_TEST(test_strncat_partial) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = " world";

  s21_strncat(dest1, src, 3);
  strncat(dest2, src, 3);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello wo");
}
END_TEST

// Тест - нулевое количество символов
START_TEST(test_strncat_zero_chars) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = " world";

  char* result1 = s21_strncat(dest1, src, 0);
  char* result2 = strncat(dest2, src, 0);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
  ck_assert_str_eq(dest1, "hello");
  ck_assert_str_eq(dest2, "hello");
}
END_TEST

// Тест - пустая строка назначения
START_TEST(test_strncat_empty_dest) {
  char dest1[20] = "";
  char dest2[20] = "";
  char* src = "hello";

  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello");
}
END_TEST

// Тест - пустая строка источника
START_TEST(test_strncat_empty_src) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = "";

  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello");
}
END_TEST

// Тест - n больше длины src
START_TEST(test_strncat_n_greater_than_src) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = "123";

  s21_strncat(dest1, src, 10);  // n больше длины src
  strncat(dest2, src, 10);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello123");
}
END_TEST

// Тест - точное количество символов
START_TEST(test_strncat_exact_count) {
  char dest1[20] = "test";
  char dest2[20] = "test";
  char* src = "ing123";

  s21_strncat(dest1, src, 3);  // Добавляем точно "ing"
  strncat(dest2, src, 3);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "testing");
}
END_TEST

// Тест - специальные символы
START_TEST(test_strncat_special_chars) {
  char dest1[20] = "start";
  char dest2[20] = "start";
  char src[] = "\n\t\xFF";

  s21_strncat(dest1, src, 3);
  strncat(dest2, src, 3);

  ck_assert_mem_eq(dest1, dest2, 8);  // "start" + 3 спецсимвола
}
END_TEST

// Тест - возвращаемое значение
START_TEST(test_strncat_return_value) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = " world";

  char* result1 = s21_strncat(dest1, src, 6);
  char* result2 = strncat(dest2, src, 6);

  ck_assert_ptr_eq(result1, dest1);
  ck_assert_ptr_eq(result2, dest2);
}
END_TEST

// Тест - русские символы
START_TEST(test_strncat_cyrillic) {
  char dest1[30] = "привет";
  char dest2[30] = "привет";
  char* src = " мир";

  s21_strncat(dest1, src, 4);
  strncat(dest2, src, 4);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// Тест - нулевой символ в середине src
START_TEST(test_strncat_null_in_src) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char src[] = "wo\0rld";

  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hellowo");
}
END_TEST

// Тест - минимальное добавление (1 символ)
START_TEST(test_strncat_single_char) {
  char dest1[20] = "hello";
  char dest2[20] = "hello";
  char* src = "!";

  s21_strncat(dest1, src, 1);
  strncat(dest2, src, 1);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest1, "hello!");
}
END_TEST

Suite* strncat_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strncat");

  // Основные тесты
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strncat_basic);
  tcase_add_test(tc_core, test_strncat_partial);
  tcase_add_test(tc_core, test_strncat_exact_count);
  tcase_add_test(tc_core, test_strncat_return_value);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strncat_zero_chars);
  tcase_add_test(tc_edge, test_strncat_empty_dest);
  tcase_add_test(tc_edge, test_strncat_empty_src);
  tcase_add_test(tc_edge, test_strncat_n_greater_than_src);
  tcase_add_test(tc_edge, test_strncat_single_char);
  suite_add_tcase(s, tc_edge);

  // Специальные случаи
  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strncat_special_chars);
  tcase_add_test(tc_special, test_strncat_cyrillic);
  tcase_add_test(tc_special, test_strncat_null_in_src);
  suite_add_tcase(s, tc_special);

  return s;
}