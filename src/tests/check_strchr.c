#include "check_basic_suites.h"

// Базовый тест - символ найден
START_TEST(test_strchr_basic_found) {
  char* str = "hello world";
  int c = 'o';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "o world");
}
END_TEST

// Тест - символ не найден
START_TEST(test_strchr_not_found) {
  char* str = "hello world";
  int c = 'z';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

// Тест - символ в начале
START_TEST(test_strchr_at_start) {
  char* str = "hello world";
  int c = 'h';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "hello world");
}
END_TEST

// Тест - символ в конце
START_TEST(test_strchr_at_end) {
  char* str = "hello world";
  int c = 'd';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "d");
}
END_TEST

// Тест - нулевой терминатор
START_TEST(test_strchr_null_terminator) {
  char* str = "hello";
  int c = '\0';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "");
}
END_TEST

// Тест - первый вхождение при повторяющихся символах
START_TEST(test_strchr_first_occurrence) {
  char* str = "hello world";
  int c = 'l';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "llo world");
}
END_TEST

// Тест - пустая строка
START_TEST(test_strchr_empty_string) {
  char* str = "";
  int c = 'a';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

// Тест - поиск нулевого терминатора в пустой строке
START_TEST(test_strchr_null_in_empty) {
  char* str = "";
  int c = '\0';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "");
}
END_TEST

// Тест - отрицательное значение символа
START_TEST(test_strchr_negative_char) {
  char str[] = {65, -10, 66, 67, 0};
  int c = -10;

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
}
END_TEST

// Тест - специальные символы
START_TEST(test_strchr_special_chars) {
  char* str = "hello\nworld\t!";
  int c = '\n';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_str_eq(result1, "\nworld\t!");
}
END_TEST

// Тест - числовое значение
START_TEST(test_strchr_numeric_value) {
  char str[] = {1, 2, 3, 4, 5, 0};
  int c = 3;

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
}
END_TEST

// Тест - символ как int (больше 255)
START_TEST(test_strchr_large_int) {
  char* str = "hello";
  int c = 1000;  // Больше чем char может содержать

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);

  // 1000 & 0xFF = 232, которого нет в строке
  ck_assert_ptr_eq(result1, NULL);
}
END_TEST

// Тест - строка с нулевым байтом в середине
START_TEST(test_strchr_null_byte_middle) {
  char str[] = "hello\0world";
  int c = 'w';

  char* result1 = s21_strchr(str, c);
  char* result2 = strchr(str, c);

  ck_assert_ptr_eq(result1, result2);
  ck_assert_ptr_eq(result1,
                   NULL);  // 'w' после нулевого байта не должен находиться
}
END_TEST

Suite* strchr_suite(void) {
  Suite* s;
  TCase* tc_core;
  TCase* tc_edge;
  TCase* tc_special;

  s = suite_create("strchr");

  // Основные тесты
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_strchr_basic_found);
  tcase_add_test(tc_core, test_strchr_not_found);
  tcase_add_test(tc_core, test_strchr_at_start);
  tcase_add_test(tc_core, test_strchr_at_end);
  tcase_add_test(tc_core, test_strchr_first_occurrence);
  suite_add_tcase(s, tc_core);

  // Граничные случаи
  tc_edge = tcase_create("Edge Cases");
  tcase_add_test(tc_edge, test_strchr_null_terminator);
  tcase_add_test(tc_edge, test_strchr_empty_string);
  tcase_add_test(tc_edge, test_strchr_null_in_empty);
  tcase_add_test(tc_edge, test_strchr_large_int);
  tcase_add_test(tc_edge, test_strchr_null_byte_middle);
  suite_add_tcase(s, tc_edge);

  // Специальные случаи
  tc_special = tcase_create("Special Cases");
  tcase_add_test(tc_special, test_strchr_negative_char);
  tcase_add_test(tc_special, test_strchr_special_chars);
  tcase_add_test(tc_special, test_strchr_numeric_value);
  suite_add_tcase(s, tc_special);

  return s;
}