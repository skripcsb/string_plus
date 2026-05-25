#include "check_basic_suites.h"

// %c tests
START_TEST(test_sprintf_c_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Char: %c", 'A');
  int result2 = sprintf(buffer2, "Char: %c", 'A');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_multiple) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%c%c%c", 'A', 'B', 'C');
  int result2 = sprintf(buffer2, "%c%c%c", 'A', 'B', 'C');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_special) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Special: %c%c", '\n', '\t');
  int result2 = sprintf(buffer2, "Special: %c%c", '\n', '\t');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_null) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Null: %c", '\0');
  int result2 = sprintf(buffer2, "Null: %c", '\0');
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_c_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5c", 'X');
  int result2 = sprintf(buffer2, "%5c", 'X');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5c", 'X');
  int result2 = sprintf(buffer2, "%-5c", 'X');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %c", '0');
  int result2 = sprintf(buffer2, "Zero: %c", '0');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_space) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Space: %c", ' ');
  int result2 = sprintf(buffer2, "Space: %c", ' ');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_escape) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Escape: %c", '\\');
  int result2 = sprintf(buffer2, "Escape: %c", '\\');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_c_unicode) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Unicode: %c", 65);
  int result2 = sprintf(buffer2, "Unicode: %c", 65);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %s tests
START_TEST(test_sprintf_s_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "String: %s", "hello");
  int result2 = sprintf(buffer2, "String: %s", "hello");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_empty) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Empty: %s", "");
  int result2 = sprintf(buffer2, "Empty: %s", "");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%10s", "test");
  int result2 = sprintf(buffer2, "%10s", "test");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.3s", "hello");
  int result2 = sprintf(buffer2, "%.3s", "hello");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-10s", "test");
  int result2 = sprintf(buffer2, "%-10s", "test");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_width_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%10.3s", "hello");
  int result2 = sprintf(buffer2, "%10.3s", "hello");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_special_chars) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Special: %s", "hello\nworld\t!");
  int result2 = sprintf(buffer2, "Special: %s", "hello\nworld\t!");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_multiple) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%s %s %s", "one", "two", "three");
  int result2 = sprintf(buffer2, "%s %s %s", "one", "two", "three");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_s_mixed) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%s%d%c", "test", 123, '!');
  int result2 = sprintf(buffer2, "%s%d%c", "test", 123, '!');
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %d tests
START_TEST(test_sprintf_d_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Number: %d", 123);
  int result2 = sprintf(buffer2, "Number: %d", 123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Negative: %d", -456);
  int result2 = sprintf(buffer2, "Negative: %d", -456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %d", 0);
  int result2 = sprintf(buffer2, "Zero: %d", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5d", 42);
  int result2 = sprintf(buffer2, "%5d", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.5d", 42);
  int result2 = sprintf(buffer2, "%.5d", 42);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_d_plus) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%+d", 42);
  int result2 = sprintf(buffer2, "%+d", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_space) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "% d", 42);
  int result2 = sprintf(buffer2, "% d", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5d", 42);
  int result2 = sprintf(buffer2, "%-5d", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%05d", 42);
  int result2 = sprintf(buffer2, "%05d", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_d_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%d", 2147483647);
  int result2 = sprintf(buffer2, "%d", 2147483647);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
// %i tests (10 tests)
START_TEST(test_sprintf_i_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Number: %i", 123);
  int result2 = sprintf(buffer2, "Number: %i", 123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Negative: %i", -456);
  int result2 = sprintf(buffer2, "Negative: %i", -456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %i", 0);
  int result2 = sprintf(buffer2, "Zero: %i", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5i", 42);
  int result2 = sprintf(buffer2, "%5i", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.5i", 42);
  int result2 = sprintf(buffer2, "%.5i", 42);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_i_plus) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%+i", 42);
  int result2 = sprintf(buffer2, "%+i", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_space) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "% i", 42);
  int result2 = sprintf(buffer2, "% i", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5i", 42);
  int result2 = sprintf(buffer2, "%-5i", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%05i", 42);
  int result2 = sprintf(buffer2, "%05i", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_i_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%i", 2147483647);
  int result2 = sprintf(buffer2, "%i", 2147483647);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST
// %e tests (10 tests)
START_TEST(test_sprintf_e_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Scientific: %e", 3.14159);
  int result2 = sprintf(buffer2, "Scientific: %e", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Negative: %e", -3.14159);
  int result2 = sprintf(buffer2, "Negative: %e", -3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %e", 0.0);
  int result2 = sprintf(buffer2, "Zero: %e", 0.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.3e", 3.14159);
  int result2 = sprintf(buffer2, "%.3e", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%15e", 3.14159);
  int result2 = sprintf(buffer2, "%15e", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_width_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%15.3e", 3.14159);
  int result2 = sprintf(buffer2, "%15.3e", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_plus) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%+e", 3.14159);
  int result2 = sprintf(buffer2, "%+e", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%e", 1.234567e10);
  int result2 = sprintf(buffer2, "%e", 1.234567e10);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_small) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%e", 1.234567e-10);
  int result2 = sprintf(buffer2, "%e", 1.234567e-10);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_e_uppercase) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%E", 3.14159);
  int result2 = sprintf(buffer2, "%E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %E tests (10 tests) - uppercase version
START_TEST(test_sprintf_E_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Scientific: %E", 3.14159);
  int result2 = sprintf(buffer2, "Scientific: %E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Negative: %E", -3.14159);
  int result2 = sprintf(buffer2, "Negative: %E", -3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.3E", 3.14159);
  int result2 = sprintf(buffer2, "%.3E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%15E", 3.14159);
  int result2 = sprintf(buffer2, "%15E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%E", 1.234567e20);
  int result2 = sprintf(buffer2, "%E", 1.234567e20);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_small) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%E", 1.234567e-20);
  int result2 = sprintf(buffer2, "%E", 1.234567e-20);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_plus) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%+E", 3.14159);
  int result2 = sprintf(buffer2, "%+E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%015E", 3.14159);
  int result2 = sprintf(buffer2, "%015E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-15E", 3.14159);
  int result2 = sprintf(buffer2, "%-15E", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_E_mixed) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Value: %.2E at index %d", 1.234567e5, 42);
  int result2 = sprintf(buffer2, "Value: %.2E at index %d", 1.234567e5, 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %f tests (10 tests)
START_TEST(test_sprintf_f_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Float: %f", 3.14159);
  int result2 = sprintf(buffer2, "Float: %f", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Negative: %f", -3.14159);
  int result2 = sprintf(buffer2, "Negative: %f", -3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %f", 0.0);
  int result2 = sprintf(buffer2, "Zero: %f", 0.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.2f", 3.14159);
  int result2 = sprintf(buffer2, "%.2f", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%10f", 3.14);
  int result2 = sprintf(buffer2, "%10f", 3.14);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_width_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%10.2f", 3.14159);
  int result2 = sprintf(buffer2, "%10.2f", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_plus) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%+f", 3.14);
  int result2 = sprintf(buffer2, "%+f", 3.14);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%f", 1234567.89);
  int result2 = sprintf(buffer2, "%f", 1234567.89);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_f_small) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%f", 0.000123);
  int result2 = sprintf(buffer2, "%f", 0.000123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_f_scientific_small) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%f", 1.234567e-10);
  int result2 = sprintf(buffer2, "%f", 1.234567e-10);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %g tests (10 tests)
START_TEST(test_sprintf_g_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "General: %g", 3.14159);
  int result2 = sprintf(buffer2, "General: %g", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%g", 1234567.89);
  int result2 = sprintf(buffer2, "%g", 1234567.89);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_small) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%g", 0.000123);
  int result2 = sprintf(buffer2, "%g", 0.000123);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_g_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.3g", 3.14159);
  int result2 = sprintf(buffer2, "%.3g", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_scientific) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%g", 1.234567e10);
  int result2 = sprintf(buffer2, "%g", 1.234567e10);
  ck_assert_str_eq(buffer1, buffer2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_g_negative) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%g", -3.14159);
  int result2 = sprintf(buffer2, "%g", -3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%g", 0.0);
  int result2 = sprintf(buffer2, "%g", 0.0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%10g", 3.14);
  int result2 = sprintf(buffer2, "%10g", 3.14);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_uppercase) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%G", 3.14159);
  int result2 = sprintf(buffer2, "%G", 3.14159);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_g_mixed) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Value: %g", 123.456);
  int result2 = sprintf(buffer2, "Value: %g", 123.456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %o tests (10 tests)
START_TEST(test_sprintf_o_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Octal: %o", 123);
  int result2 = sprintf(buffer2, "Octal: %o", 123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %o", 0);
  int result2 = sprintf(buffer2, "Zero: %o", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%o", 511);
  int result2 = sprintf(buffer2, "%o", 511);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5o", 42);
  int result2 = sprintf(buffer2, "%5o", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.5o", 42);
  int result2 = sprintf(buffer2, "%.5o", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_hash) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%#o", 42);
  int result2 = sprintf(buffer2, "%#o", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5o", 42);
  int result2 = sprintf(buffer2, "%-5o", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%05o", 42);
  int result2 = sprintf(buffer2, "%05o", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_unsigned) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%o", 255);
  int result2 = sprintf(buffer2, "%o", 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_o_max) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%o", 0777);
  int result2 = sprintf(buffer2, "%o", 0777);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %u tests (10 tests)
START_TEST(test_sprintf_u_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Unsigned: %u", 123);
  int result2 = sprintf(buffer2, "Unsigned: %u", 123);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %u", 0);
  int result2 = sprintf(buffer2, "Zero: %u", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%u", 4294967295U);
  int result2 = sprintf(buffer2, "%u", 4294967295U);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5u", 42);
  int result2 = sprintf(buffer2, "%5u", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.5u", 42);
  int result2 = sprintf(buffer2, "%.5u", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5u", 42);
  int result2 = sprintf(buffer2, "%-5u", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%05u", 42);
  int result2 = sprintf(buffer2, "%05u", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_negative_ignored) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%u", -1);
  int result2 = sprintf(buffer2, "%u", -1);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_mixed) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%u %u", 123, 456);
  int result2 = sprintf(buffer2, "%u %u", 123, 456);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_u_bounds) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%u", 4294967295U);
  int result2 = sprintf(buffer2, "%u", 4294967295U);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %x tests (10 tests)
START_TEST(test_sprintf_x_basic) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Hex: %x", 255);
  int result2 = sprintf(buffer2, "Hex: %x", 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_uppercase) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Hex: %X", 255);
  int result2 = sprintf(buffer2, "Hex: %X", 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_zero) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Zero: %x", 0);
  int result2 = sprintf(buffer2, "Zero: %x", 0);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_hash) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%#x", 255);
  int result2 = sprintf(buffer2, "%#x", 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_hash_uppercase) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%#X", 255);
  int result2 = sprintf(buffer2, "%#X", 255);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_width) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%5x", 42);
  int result2 = sprintf(buffer2, "%5x", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_precision) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%.5x", 42);
  int result2 = sprintf(buffer2, "%.5x", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_left_align) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%-5x", 42);
  int result2 = sprintf(buffer2, "%-5x", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_zero_pad) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%05x", 42);
  int result2 = sprintf(buffer2, "%05x", 42);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

START_TEST(test_sprintf_x_large) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "%x", 4294967295U);
  int result2 = sprintf(buffer2, "%x", 4294967295U);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

// %p tests (10 tests)
START_TEST(test_sprintf_p_basic) {
  char buffer1[100], buffer2[100];
  int num = 42;
  int result1 = s21_sprintf(buffer1, "Pointer: %p", &num);
  int result2 = sprintf(buffer2, "Pointer: %p", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_null) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Null: %p", NULL);
  int result2 = sprintf(buffer2, "Null: %p", NULL);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_string) {
  char buffer1[100], buffer2[100];
  char str[] = "test";
  int result1 = s21_sprintf(buffer1, "String ptr: %p", str);
  int result2 = sprintf(buffer2, "String ptr: %p", str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_array) {
  char buffer1[100], buffer2[100];
  int arr[5] = {1, 2, 3, 4, 5};
  int result1 = s21_sprintf(buffer1, "Array ptr: %p", arr);
  int result2 = sprintf(buffer2, "Array ptr: %p", arr);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_function) {
  char buffer1[100], buffer2[100];
  int result1 =
      s21_sprintf(buffer1, "Function ptr: %p", &test_sprintf_p_function);
  int result2 = sprintf(buffer2, "Function ptr: %p", &test_sprintf_p_function);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_multiple) {
  char buffer1[100], buffer2[100];
  int a = 1, b = 2;
  int result1 = s21_sprintf(buffer1, "Ptrs: %p %p", &a, &b);
  int result2 = sprintf(buffer2, "Ptrs: %p %p", &a, &b);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_large) {
  char buffer1[100], buffer2[100];
  void* large_ptr = (void*)0x7ffe12345678;
  int result1 = s21_sprintf(buffer1, "Large: %p", large_ptr);
  int result2 = sprintf(buffer2, "Large: %p", large_ptr);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_format) {
  char buffer1[100], buffer2[100];
  int num = 42;
  int result1 = s21_sprintf(buffer1, "Value: %d at %p", num, &num);
  int result2 = sprintf(buffer2, "Value: %d at %p", num, &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sprintf_p_static) {
  char buffer1[100], buffer2[100];
  static int static_var = 100;
  int result1 = s21_sprintf(buffer1, "Static: %p", &static_var);
  int result2 = sprintf(buffer2, "Static: %p", &static_var);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %n tests (10 tests)
START_TEST(test_sprintf_n_basic) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "hello%n", &n1);
  int result2 = sprintf(buffer2, "hello%n", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_middle) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "hello%n world", &n1);
  int result2 = sprintf(buffer2, "hello%n world", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_multiple) {
  char buffer1[100], buffer2[100];
  int n1, n2, n3;
  int s21_n1, s21_n2, s21_n3;
  int result1 =
      s21_sprintf(buffer1, "hello%n world%n test%n", &s21_n1, &s21_n2, &s21_n3);
  int result2 = sprintf(buffer2, "hello%n world%n test%n", &n1, &n2, &n3);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(s21_n1, n1);
  ck_assert_int_eq(s21_n2, n2);
  ck_assert_int_eq(s21_n3, n3);
}
END_TEST

START_TEST(test_sprintf_n_with_numbers) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "123%n hello", &n1);
  int result2 = sprintf(buffer2, "123%n hello", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_empty) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "%n", &n1);
  int result2 = sprintf(buffer2, "%n", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_format) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "Value: %d%n", 123, &n1);
  int result2 = sprintf(buffer2, "Value: %d%n", 123, &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_mixed) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "%s%n%d", "test", &n1, 456);
  int result2 = sprintf(buffer2, "%s%n%d", "test", &n2, 456);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_position) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "ab%nc", &n1);
  int result2 = sprintf(buffer2, "ab%nc", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n1, 2);
}
END_TEST

START_TEST(test_sprintf_n_complex) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 =
      s21_sprintf(buffer1, "Hello %s, your number is %d%n", "world", 42, &n1);
  int result2 =
      sprintf(buffer2, "Hello %s, your number is %d%n", "world", 42, &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sprintf_n_width) {
  char buffer1[100], buffer2[100];
  int n1, n2;
  int result1 = s21_sprintf(buffer1, "%5s%n", "test", &n1);
  int result2 = sprintf(buffer2, "%5s%n", "test", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

// %% tests (1 test)
START_TEST(test_sprintf_percent) {
  char buffer1[100], buffer2[100];
  int result1 = s21_sprintf(buffer1, "Percent: %%");
  int result2 = sprintf(buffer2, "Percent: %%");
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(buffer1, buffer2);
}
END_TEST

Suite* sprintf_suite(void) {
  Suite* s;
  TCase *tc_c, *tc_s, *tc_d, *tc_i, *tc_e, *tc_E, *tc_f, *tc_g, *tc_o, *tc_u,
      *tc_x, *tc_p, *tc_n, *tc_percent;

  s = suite_create("sprintf");

  // %c tests
  tc_c = tcase_create("c specifier");
  tcase_add_test(tc_c, test_sprintf_c_basic);
  tcase_add_test(tc_c, test_sprintf_c_multiple);
  tcase_add_test(tc_c, test_sprintf_c_special);
  tcase_add_test(tc_c, test_sprintf_c_null);
  tcase_add_test(tc_c, test_sprintf_c_width);
  tcase_add_test(tc_c, test_sprintf_c_left_align);
  tcase_add_test(tc_c, test_sprintf_c_zero);
  tcase_add_test(tc_c, test_sprintf_c_space);
  tcase_add_test(tc_c, test_sprintf_c_escape);
  tcase_add_test(tc_c, test_sprintf_c_unicode);
  suite_add_tcase(s, tc_c);

  // %s tests
  tc_s = tcase_create("s specifier");
  tcase_add_test(tc_s, test_sprintf_s_basic);
  tcase_add_test(tc_s, test_sprintf_s_empty);
  tcase_add_test(tc_s, test_sprintf_s_width);
  tcase_add_test(tc_s, test_sprintf_s_precision);
  tcase_add_test(tc_s, test_sprintf_s_left_align);
  tcase_add_test(tc_s, test_sprintf_s_width_precision);
  tcase_add_test(tc_s, test_sprintf_s_special_chars);
  tcase_add_test(tc_s, test_sprintf_s_multiple);
  tcase_add_test(tc_s, test_sprintf_s_mixed);
  suite_add_tcase(s, tc_s);

  // %d tests
  tc_d = tcase_create("d specifier");
  tcase_add_test(tc_d, test_sprintf_d_basic);
  tcase_add_test(tc_d, test_sprintf_d_negative);
  tcase_add_test(tc_d, test_sprintf_d_zero);
  tcase_add_test(tc_d, test_sprintf_d_width);
  tcase_add_test(tc_d, test_sprintf_d_precision);
  tcase_add_test(tc_d, test_sprintf_d_plus);
  tcase_add_test(tc_d, test_sprintf_d_space);
  tcase_add_test(tc_d, test_sprintf_d_left_align);
  tcase_add_test(tc_d, test_sprintf_d_zero_pad);
  tcase_add_test(tc_d, test_sprintf_d_large);
  suite_add_tcase(s, tc_d);

  // %i tests
  tc_i = tcase_create("i specifier");
  tcase_add_test(tc_i, test_sprintf_i_basic);
  tcase_add_test(tc_i, test_sprintf_i_negative);
  tcase_add_test(tc_i, test_sprintf_i_zero);
  tcase_add_test(tc_i, test_sprintf_i_width);
  tcase_add_test(tc_i, test_sprintf_i_precision);
  tcase_add_test(tc_i, test_sprintf_i_plus);
  tcase_add_test(tc_i, test_sprintf_i_space);
  tcase_add_test(tc_i, test_sprintf_i_left_align);
  tcase_add_test(tc_i, test_sprintf_i_zero_pad);
  tcase_add_test(tc_i, test_sprintf_i_large);
  suite_add_tcase(s, tc_i);

  // %e tests
  tc_e = tcase_create("e specifier");
  tcase_add_test(tc_e, test_sprintf_e_basic);
  tcase_add_test(tc_e, test_sprintf_e_negative);
  tcase_add_test(tc_e, test_sprintf_e_zero);
  tcase_add_test(tc_e, test_sprintf_e_precision);
  tcase_add_test(tc_e, test_sprintf_e_width);
  tcase_add_test(tc_e, test_sprintf_e_width_precision);
  tcase_add_test(tc_e, test_sprintf_e_plus);
  tcase_add_test(tc_e, test_sprintf_e_large);
  tcase_add_test(tc_e, test_sprintf_e_small);
  tcase_add_test(tc_e, test_sprintf_e_uppercase);
  suite_add_tcase(s, tc_e);

  // %E tests
  tc_E = tcase_create("E specifier");
  tcase_add_test(tc_E, test_sprintf_E_basic);
  tcase_add_test(tc_E, test_sprintf_E_negative);
  tcase_add_test(tc_E, test_sprintf_E_precision);
  tcase_add_test(tc_E, test_sprintf_E_width);
  tcase_add_test(tc_E, test_sprintf_E_large);
  tcase_add_test(tc_E, test_sprintf_E_small);
  tcase_add_test(tc_E, test_sprintf_E_plus);
  tcase_add_test(tc_E, test_sprintf_E_zero_pad);
  tcase_add_test(tc_E, test_sprintf_E_left_align);
  tcase_add_test(tc_E, test_sprintf_E_mixed);
  suite_add_tcase(s, tc_E);

  // %f tests
  tc_f = tcase_create("f specifier");
  tcase_add_test(tc_f, test_sprintf_f_basic);
  tcase_add_test(tc_f, test_sprintf_f_negative);
  tcase_add_test(tc_f, test_sprintf_f_zero);
  tcase_add_test(tc_f, test_sprintf_f_precision);
  tcase_add_test(tc_f, test_sprintf_f_width);
  tcase_add_test(tc_f, test_sprintf_f_width_precision);
  tcase_add_test(tc_f, test_sprintf_f_plus);
  tcase_add_test(tc_f, test_sprintf_f_large);
  tcase_add_test(tc_f, test_sprintf_f_small);
  tcase_add_test(tc_f, test_sprintf_f_scientific_small);
  suite_add_tcase(s, tc_f);

  // %g tests
  tc_g = tcase_create("g specifier");
  tcase_add_test(tc_g, test_sprintf_g_basic);
  tcase_add_test(tc_g, test_sprintf_g_large);
  tcase_add_test(tc_g, test_sprintf_g_small);
  tcase_add_test(tc_g, test_sprintf_g_precision);
  tcase_add_test(tc_g, test_sprintf_g_scientific);
  tcase_add_test(tc_g, test_sprintf_g_negative);
  tcase_add_test(tc_g, test_sprintf_g_zero);
  tcase_add_test(tc_g, test_sprintf_g_width);
  tcase_add_test(tc_g, test_sprintf_g_uppercase);
  tcase_add_test(tc_g, test_sprintf_g_mixed);
  suite_add_tcase(s, tc_g);

  // %o tests
  tc_o = tcase_create("o specifier");
  tcase_add_test(tc_o, test_sprintf_o_basic);
  tcase_add_test(tc_o, test_sprintf_o_zero);
  tcase_add_test(tc_o, test_sprintf_o_large);
  tcase_add_test(tc_o, test_sprintf_o_width);
  tcase_add_test(tc_o, test_sprintf_o_precision);
  tcase_add_test(tc_o, test_sprintf_o_hash);
  tcase_add_test(tc_o, test_sprintf_o_left_align);
  tcase_add_test(tc_o, test_sprintf_o_zero_pad);
  tcase_add_test(tc_o, test_sprintf_o_unsigned);
  tcase_add_test(tc_o, test_sprintf_o_max);
  suite_add_tcase(s, tc_o);

  // %u tests
  tc_u = tcase_create("u specifier");
  tcase_add_test(tc_u, test_sprintf_u_basic);
  tcase_add_test(tc_u, test_sprintf_u_zero);
  tcase_add_test(tc_u, test_sprintf_u_large);
  tcase_add_test(tc_u, test_sprintf_u_width);
  tcase_add_test(tc_u, test_sprintf_u_precision);
  tcase_add_test(tc_u, test_sprintf_u_left_align);
  tcase_add_test(tc_u, test_sprintf_u_zero_pad);
  tcase_add_test(tc_u, test_sprintf_u_negative_ignored);
  tcase_add_test(tc_u, test_sprintf_u_mixed);
  tcase_add_test(tc_u, test_sprintf_u_bounds);
  suite_add_tcase(s, tc_u);

  // %x tests
  tc_x = tcase_create("x specifier");
  tcase_add_test(tc_x, test_sprintf_x_basic);
  tcase_add_test(tc_x, test_sprintf_x_uppercase);
  tcase_add_test(tc_x, test_sprintf_x_zero);
  tcase_add_test(tc_x, test_sprintf_x_hash);
  tcase_add_test(tc_x, test_sprintf_x_hash_uppercase);
  tcase_add_test(tc_x, test_sprintf_x_width);
  tcase_add_test(tc_x, test_sprintf_x_precision);
  tcase_add_test(tc_x, test_sprintf_x_left_align);
  tcase_add_test(tc_x, test_sprintf_x_zero_pad);
  tcase_add_test(tc_x, test_sprintf_x_large);
  suite_add_tcase(s, tc_x);

  // %p tests
  tc_p = tcase_create("p specifier");
  tcase_add_test(tc_p, test_sprintf_p_basic);
  tcase_add_test(tc_p, test_sprintf_p_null);
  tcase_add_test(tc_p, test_sprintf_p_string);
  tcase_add_test(tc_p, test_sprintf_p_array);
  tcase_add_test(tc_p, test_sprintf_p_function);
  tcase_add_test(tc_p, test_sprintf_p_multiple);
  tcase_add_test(tc_p, test_sprintf_p_large);
  tcase_add_test(tc_p, test_sprintf_p_format);
  tcase_add_test(tc_p, test_sprintf_p_static);
  suite_add_tcase(s, tc_p);

  // %n tests
  tc_n = tcase_create("n specifier");
  tcase_add_test(tc_n, test_sprintf_n_basic);
  tcase_add_test(tc_n, test_sprintf_n_middle);
  tcase_add_test(tc_n, test_sprintf_n_multiple);
  tcase_add_test(tc_n, test_sprintf_n_with_numbers);
  tcase_add_test(tc_n, test_sprintf_n_empty);
  tcase_add_test(tc_n, test_sprintf_n_format);
  tcase_add_test(tc_n, test_sprintf_n_mixed);
  tcase_add_test(tc_n, test_sprintf_n_position);
  tcase_add_test(tc_n, test_sprintf_n_complex);
  tcase_add_test(tc_n, test_sprintf_n_width);
  suite_add_tcase(s, tc_n);

  // %% test
  tc_percent = tcase_create("percent specifier");
  tcase_add_test(tc_percent, test_sprintf_percent);
  suite_add_tcase(s, tc_percent);

  return s;
}