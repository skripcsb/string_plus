#include "check_basic_suites.h"

// %c tests
START_TEST(test_sscanf_c_basic) {
  char c1, c2;
  char str[] = "A B";
  int result1 = s21_sscanf(str, "%c %c", &c1, &c2);
  int result2 = sscanf(str, "%c %c", &c1, &c2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(c1, 'A');
  ck_assert_int_eq(c2, 'B');
}
END_TEST

START_TEST(test_sscanf_c_single) {
  char c;
  char str[] = "X";
  int result1 = s21_sscanf(str, "%c", &c);
  int result2 = sscanf(str, "%c", &c);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(c, 'X');
}
END_TEST

START_TEST(test_sscanf_c_with_spaces) {
  char c1, c2, c3;
  char str[] = "  A  B  C  ";
  int result1 = s21_sscanf(str, "%c%c%c", &c1, &c2, &c3);
  int result2 = sscanf(str, "%c%c%c", &c1, &c2, &c3);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_special_chars) {
  char c1, c2;
  char str[] = "\n\t";
  int result1 = s21_sscanf(str, "%c%c", &c1, &c2);
  int result2 = sscanf(str, "%c%c", &c1, &c2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_width) {
  char str[10];
  char input[] = "hello";
  int result1 = s21_sscanf(input, "%3c", str);
  int result2 = sscanf(input, "%3c", str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_no_match) {
  char c;
  char str[] = "";
  int result1 = s21_sscanf(str, "%c", &c);
  int result2 = sscanf(str, "%c", &c);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_multiple) {
  char c1, c2, c3, c4;
  char str[] = "ABCD";
  int result1 = s21_sscanf(str, "%c%c%c%c", &c1, &c2, &c3, &c4);
  int result2 = sscanf(str, "%c%c%c%c", &c1, &c2, &c3, &c4);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_mixed) {
  char c1, c2;
  int num;
  char str[] = "A 123 B";
  int result1 = s21_sscanf(str, "%c%d%c", &c1, &num, &c2);
  int result2 = sscanf(str, "%c%d%c", &c1, &num, &c2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_newline) {
  char c1, c2;
  char str[] = "X\nY";
  int result1 = s21_sscanf(str, "%c%c", &c1, &c2);
  int result2 = sscanf(str, "%c%c", &c1, &c2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_c_tab) {
  char c1, c2;
  char str[] = "X\tY";
  int result1 = s21_sscanf(str, "%c%c", &c1, &c2);
  int result2 = sscanf(str, "%c%c", &c1, &c2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %s tests
START_TEST(test_sscanf_s_basic) {
  char str1[20], str2[20];
  char input[] = "hello world";
  int result1 = s21_sscanf(input, "%s %s", str1, str2);
  int result2 = sscanf(input, "%s %s", str1, str2);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str1, "hello");
  ck_assert_str_eq(str2, "world");
}
END_TEST

START_TEST(test_sscanf_s_single) {
  char str[20];
  char input[] = "test";
  int result1 = s21_sscanf(input, "%s", str);
  int result2 = sscanf(input, "%s", str);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str, "test");
}
END_TEST

START_TEST(test_sscanf_s_with_spaces) {
  char str1[20], str2[20];
  char input[] = "  hello  world  ";
  int result1 = s21_sscanf(input, "%s%s", str1, str2);
  int result2 = sscanf(input, "%s%s", str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_width) {
  char str[20];
  char input[] = "hello";
  int result1 = s21_sscanf(input, "%3s", str);
  int result2 = sscanf(input, "%3s", str);
  ck_assert_int_eq(result1, result2);
  ck_assert_str_eq(str, "hel");
}
END_TEST

START_TEST(test_sscanf_s_no_match) {
  char str[20];
  char input[] = "";
  int result1 = s21_sscanf(input, "%s", str);
  int result2 = sscanf(input, "%s", str);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_special_chars) {
  char str1[20], str2[20];
  char input[] = "hello\nworld";
  int result1 = s21_sscanf(input, "%s%s", str1, str2);
  int result2 = sscanf(input, "%s%s", str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_multiple) {
  char str1[20], str2[20], str3[20];
  char input[] = "one two three";
  int result1 = s21_sscanf(input, "%s%s%s", str1, str2, str3);
  int result2 = sscanf(input, "%s%s%s", str1, str2, str3);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_mixed) {
  char str1[20], str2[20];
  int num;
  char input[] = "hello 123 world";
  int result1 = s21_sscanf(input, "%s%d%s", str1, &num, str2);
  int result2 = sscanf(input, "%s%d%s", str1, &num, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_empty_fields) {
  char str1[20], str2[20];
  char input[] = "hello";
  int result1 = s21_sscanf(input, "%s%s", str1, str2);
  int result2 = sscanf(input, "%s%s", str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_s_tabs) {
  char str1[20], str2[20];
  char input[] = "hello\tworld";
  int result1 = s21_sscanf(input, "%s%s", str1, str2);
  int result2 = sscanf(input, "%s%s", str1, str2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %d tests
START_TEST(test_sscanf_d_basic) {
  int num1, num2;
  char str[] = "123 456";
  int result1 = s21_sscanf(str, "%d %d", &num1, &num2);
  int result2 = sscanf(str, "%d %d", &num1, &num2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num1, 123);
  ck_assert_int_eq(num2, 456);
}
END_TEST

START_TEST(test_sscanf_d_negative) {
  int num1, num2;
  char str[] = "-123 +456";
  int result1 = s21_sscanf(str, "%d %d", &num1, &num2);
  int result2 = sscanf(str, "%d %d", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_single) {
  int num;
  char str[] = "789";
  int result1 = s21_sscanf(str, "%d", &num);
  int result2 = sscanf(str, "%d", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 789);
}
END_TEST

START_TEST(test_sscanf_d_with_spaces) {
  int num1, num2;
  char str[] = "  123  456  ";
  int result1 = s21_sscanf(str, "%d%d", &num1, &num2);
  int result2 = sscanf(str, "%d%d", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_no_match) {
  int num;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "%d", &num);
  int result2 = sscanf(str, "%d", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_mixed) {
  int num1, num2;
  char str1[20];
  char str[] = "123 hello 456";
  int result1 = s21_sscanf(str, "%d%s%d", &num1, str1, &num2);
  int result2 = sscanf(str, "%d%s%d", &num1, str1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_zero) {
  int num;
  char str[] = "0";
  int result1 = s21_sscanf(str, "%d", &num);
  int result2 = sscanf(str, "%d", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(test_sscanf_d_large) {
  int num;
  char str[] = "2147483647";
  int result1 = s21_sscanf(str, "%d", &num);
  int result2 = sscanf(str, "%d", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_positive_sign) {
  int num;
  char str[] = "+123";
  int result1 = s21_sscanf(str, "%d", &num);
  int result2 = sscanf(str, "%d", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_d_multiple) {
  int num1, num2, num3;
  char str[] = "1 2 3";
  int result1 = s21_sscanf(str, "%d%d%d", &num1, &num2, &num3);
  int result2 = sscanf(str, "%d%d%d", &num1, &num2, &num3);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_i_basic) {
  int num1, num2;
  char str[] = "123 456";
  int result1 = s21_sscanf(str, "%i %i", &num1, &num2);
  int result2 = sscanf(str, "%i %i", &num1, &num2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num1, 123);
  ck_assert_int_eq(num2, 456);
}
END_TEST

START_TEST(test_sscanf_i_hex) {
  int num;
  char str[] = "0x1A";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 26);
}
END_TEST

START_TEST(test_sscanf_i_octal) {
  int num;
  char str[] = "0123";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 83);
}
END_TEST

START_TEST(test_sscanf_i_negative) {
  int num;
  char str[] = "-123";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, -123);
}
END_TEST

START_TEST(test_sscanf_i_positive) {
  int num;
  char str[] = "+456";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 456);
}
END_TEST

START_TEST(test_sscanf_i_hex_no_prefix) {
  int num;
  char str[] = "1A";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_i_zero) {
  int num;
  char str[] = "0";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(num, 0);
}
END_TEST

START_TEST(test_sscanf_i_mixed) {
  int num1, num2, num3;
  char str[] = "123 0x1A 0123";
  int result1 = s21_sscanf(str, "%i%i%i", &num1, &num2, &num3);
  int result2 = sscanf(str, "%i%i%i", &num1, &num2, &num3);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_i_no_match) {
  int num;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "%i", &num);
  int result2 = sscanf(str, "%i", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_i_with_spaces) {
  int num1, num2;
  char str[] = "   123   0x1A   ";
  int result1 = s21_sscanf(str, "%i%i", &num1, &num2);
  int result2 = sscanf(str, "%i%i", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %g tests (10 tests)
START_TEST(test_sscanf_g_basic) {
  float num;
  char str[] = "123.456";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 123.456, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_scientific) {
  float num;
  char str[] = "1.23456e2";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 123.456, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_negative) {
  float num;
  char str[] = "-123.456";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, -123.456, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_positive) {
  float num;
  char str[] = "+123.456";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 123.456, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_no_decimal) {
  float num;
  char str[] = "123";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 123.0, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_only_decimal) {
  float num;
  char str[] = ".456";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 0.456, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_zero) {
  float num;
  char str[] = "0.0";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_float_eq_tol(num, 0.0, 1e-6);
}
END_TEST

START_TEST(test_sscanf_g_large) {
  float num;
  char str[] = "1.234567e10";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_g_small) {
  float num;
  char str[] = "1.234567e-10";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_g_no_match) {
  float num;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "%g", &num);
  int result2 = sscanf(str, "%g", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %o tests (10 tests)
START_TEST(test_sscanf_o_basic) {
  unsigned int num;
  char str[] = "123";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0123);
}
END_TEST

START_TEST(test_sscanf_o_large) {
  unsigned int num;
  char str[] = "777";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0777);
}
END_TEST

START_TEST(test_sscanf_o_zero) {
  unsigned int num;
  char str[] = "0";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0);
}
END_TEST

START_TEST(test_sscanf_o_multiple) {
  unsigned int num1, num2;
  char str[] = "123 456";
  int result1 = s21_sscanf(str, "%o %o", &num1, &num2);
  int result2 = sscanf(str, "%o %o", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_o_with_spaces) {
  unsigned int num;
  char str[] = "   123   ";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_o_invalid_digit) {
  unsigned int num;
  char str[] = "128";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_o_no_match) {
  unsigned int num;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_o_max_octal) {
  unsigned int num;
  char str[] = "377";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0377);
}
END_TEST

START_TEST(test_sscanf_o_mixed) {
  unsigned int num1, num2;
  char str1[20];
  char str[] = "123 hello 456";
  int result1 = s21_sscanf(str, "%o%s%o", &num1, str1, &num2);
  int result2 = sscanf(str, "%o%s%o", &num1, str1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_o_only_octal_digits) {
  unsigned int num;
  char str[] = "01234567";
  int result1 = s21_sscanf(str, "%o", &num);
  int result2 = sscanf(str, "%o", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %u tests (10 tests)
START_TEST(test_sscanf_u_basic) {
  unsigned int num;
  char str[] = "123";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 123);
}
END_TEST

START_TEST(test_sscanf_u_large) {
  unsigned int num;
  char str[] = "4294967295";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_zero) {
  unsigned int num;
  char str[] = "0";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0);
}
END_TEST

START_TEST(test_sscanf_u_multiple) {
  unsigned int num1, num2;
  char str[] = "123 456";
  int result1 = s21_sscanf(str, "%u %u", &num1, &num2);
  int result2 = sscanf(str, "%u %u", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_with_spaces) {
  unsigned int num;
  char str[] = "   123   ";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_no_match) {
  unsigned int num;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_negative_ignored) {
  unsigned int num;
  char str[] = "-123";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_mixed) {
  unsigned int num1, num2;
  char str1[20];
  char str[] = "123 hello 456";
  int result1 = s21_sscanf(str, "%u%s%u", &num1, str1, &num2);
  int result2 = sscanf(str, "%u%s%u", &num1, str1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_only_digits) {
  unsigned int num;
  char str[] = "0123456789";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_u_bounds) {
  unsigned int num;
  char str[] = "4294967295";
  int result1 = s21_sscanf(str, "%u", &num);
  int result2 = sscanf(str, "%u", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 4294967295U);
}
END_TEST

// %x tests (10 tests)
START_TEST(test_sscanf_x_basic) {
  unsigned int num;
  char str[] = "1A3";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0x1A3);
}
END_TEST

START_TEST(test_sscanf_x_uppercase) {
  unsigned int num;
  char str[] = "ABC";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0xABC);
}
END_TEST

START_TEST(test_sscanf_x_with_prefix) {
  unsigned int num;
  char str[] = "0x1A3";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0x1A3);
}
END_TEST

START_TEST(test_sscanf_x_zero) {
  unsigned int num;
  char str[] = "0";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0);
}
END_TEST

START_TEST(test_sscanf_x_multiple) {
  unsigned int num1, num2;
  char str[] = "1A3 2B4";
  int result1 = s21_sscanf(str, "%x %x", &num1, &num2);
  int result2 = sscanf(str, "%x %x", &num1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_x_with_spaces) {
  unsigned int num;
  char str[] = "   1A3   ";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_x_no_match) {
  unsigned int num;
  char str[] = "xyz";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_x_mixed_case) {
  unsigned int num;
  char str[] = "aBc";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
  ck_assert_uint_eq(num, 0xABC);
}
END_TEST

START_TEST(test_sscanf_x_large) {
  unsigned int num;
  char str[] = "FFFFFFFF";
  int result1 = s21_sscanf(str, "%x", &num);
  int result2 = sscanf(str, "%x", &num);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_x_mixed) {
  unsigned int num1, num2;
  char str1[20];
  char str[] = "1A3 hello 2B4";
  int result1 = s21_sscanf(str, "%x%s%x", &num1, str1, &num2);
  int result2 = sscanf(str, "%x%s%x", &num1, str1, &num2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %p tests (10 tests)
START_TEST(test_sscanf_p_basic) {
  void *ptr1, *ptr2;
  char str[] = "0x1234";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_large) {
  void *ptr1, *ptr2;
  char str[] = "0x7ffe12345678";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_null) {
  void *ptr1, *ptr2;
  char str[] = "(nil)";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_no_prefix) {
  void *ptr1, *ptr2;
  char str[] = "1234";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_uppercase) {
  void *ptr1, *ptr2;
  char str[] = "0XABCD";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_multiple) {
  void *ptr1, *ptr2;
  char str[] = "0x1234 0x5678";
  int result1 = s21_sscanf(str, "%p%p", &ptr1, &ptr2);
  int result2 = sscanf(str, "%p%p", &ptr1, &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_with_spaces) {
  void *ptr1, *ptr2;
  char str[] = "   0x1234   ";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_no_match) {
  void *ptr1, *ptr2;
  char str[] = "invalid";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_zero) {
  void *ptr1, *ptr2;
  char str[] = "0x0";
  int result1 = s21_sscanf(str, "%p", &ptr1);
  int result2 = sscanf(str, "%p", &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_p_mixed) {
  void *ptr1, *ptr2;
  char str1[20];
  char str[] = "0x1234 hello 0x5678";
  int result1 = s21_sscanf(str, "%p%s%p", &ptr1, str1, &ptr2);
  int result2 = sscanf(str, "%p%s%p", &ptr1, str1, &ptr2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

// %n tests (10 tests)
START_TEST(test_sscanf_n_basic) {
  int n1, n2;
  char str[] = "hello";
  int result1 = s21_sscanf(str, "hello%n", &n1);
  int result2 = sscanf(str, "hello%n", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_n_middle) {
  int n1, n2;
  char str[] = "hello world";
  int result1 = s21_sscanf(str, "hello%n world", &n1);
  int result2 = sscanf(str, "hello%n world", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_n_multiple) {
  int n1, n2, n3;
  int s21_n1, s21_n2, s21_n3;
  char str[] = "hello world test";
  int result1 =
      s21_sscanf(str, "hello%n world%n test%n", &s21_n1, &s21_n2, &s21_n3);
  int result2 = sscanf(str, "hello%n world%n test%n", &n1, &n2, &n3);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(s21_n1, n1);
  ck_assert_int_eq(s21_n2, n2);
  ck_assert_int_eq(s21_n3, n3);
}
END_TEST

START_TEST(test_sscanf_n_with_numbers) {
  int n1, n2, num;
  char str[] = "123 hello";
  int result1 = s21_sscanf(str, "%d%n hello", &num, &n1);
  int result2 = sscanf(str, "%d%n hello", &num, &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_n_empty) {
  int n1, n2;
  char str[] = "";
  int result1 = s21_sscanf(str, "%n", &n1);
  int result2 = sscanf(str, "%n", &n2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_n_no_input) {
  int n1, n2;
  char str[] = "test";
  int result1 = s21_sscanf(str, "text%n", &n1);
  int result2 = sscanf(str, "text%n", &n2);
  ck_assert_int_eq(result1, result2);
}
END_TEST

START_TEST(test_sscanf_n_with_spaces) {
  int n1, n2;
  char str[] = "   hello";
  int result1 = s21_sscanf(str, "   hello%n", &n1);
  int result2 = sscanf(str, "   hello%n", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_n_mixed_format) {
  int n1, n2, num;
  char str1[20];
  char str[] = "123 hello world";
  int result1 = s21_sscanf(str, "%d%n %s", &num, &n1, str1);
  int result2 = sscanf(str, "%d%n %s", &num, &n2, str1);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_sscanf_n_position) {
  int n1, n2;
  char str[] = "abc";
  int result1 = s21_sscanf(str, "ab%nc", &n1);
  int result2 = sscanf(str, "ab%nc", &n2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(n1, 2);
}
END_TEST

START_TEST(test_sscanf_n_complex) {
  int n1, n2, num1, num2;
  char str1[20];
  char str[] = "123 test 456";
  int result1 = s21_sscanf(str, "%d%n %s %d", &num1, &n1, str1, &num2);
  int result2 = sscanf(str, "%d%n %s %d", &num1, &n2, str1, &num2);
  ck_assert_int_eq(result1, result2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

// %% tests (1 test)
START_TEST(test_sscanf_percent) {
  char str[] = "%";
  int result1 = s21_sscanf(str, "%%");
  int result2 = sscanf(str, "%%");
  ck_assert_int_eq(result1, result2);
}
END_TEST

Suite *sscanf_suite(void) {
  Suite *s;
  TCase *tc_c, *tc_s, *tc_d, *tc_i, *tc_g, *tc_o, *tc_u, *tc_x, *tc_p, *tc_n,
      *tc_percent;

  s = suite_create("sscanf");

  // %c tests
  tc_c = tcase_create("c specifier");
  tcase_add_test(tc_c, test_sscanf_c_basic);
  tcase_add_test(tc_c, test_sscanf_c_single);
  tcase_add_test(tc_c, test_sscanf_c_with_spaces);
  tcase_add_test(tc_c, test_sscanf_c_special_chars);
  tcase_add_test(tc_c, test_sscanf_c_width);
  tcase_add_test(tc_c, test_sscanf_c_no_match);
  tcase_add_test(tc_c, test_sscanf_c_multiple);
  tcase_add_test(tc_c, test_sscanf_c_mixed);
  tcase_add_test(tc_c, test_sscanf_c_newline);
  tcase_add_test(tc_c, test_sscanf_c_tab);
  suite_add_tcase(s, tc_c);

  // %s tests
  tc_s = tcase_create("s specifier");
  tcase_add_test(tc_s, test_sscanf_s_basic);
  tcase_add_test(tc_s, test_sscanf_s_single);
  tcase_add_test(tc_s, test_sscanf_s_with_spaces);
  tcase_add_test(tc_s, test_sscanf_s_width);
  tcase_add_test(tc_s, test_sscanf_s_no_match);
  tcase_add_test(tc_s, test_sscanf_s_special_chars);
  tcase_add_test(tc_s, test_sscanf_s_multiple);
  tcase_add_test(tc_s, test_sscanf_s_mixed);
  tcase_add_test(tc_s, test_sscanf_s_empty_fields);
  tcase_add_test(tc_s, test_sscanf_s_tabs);
  suite_add_tcase(s, tc_s);

  // %d tests
  tc_d = tcase_create("d specifier");
  tcase_add_test(tc_d, test_sscanf_d_basic);
  tcase_add_test(tc_d, test_sscanf_d_negative);
  tcase_add_test(tc_d, test_sscanf_d_single);
  tcase_add_test(tc_d, test_sscanf_d_with_spaces);
  tcase_add_test(tc_d, test_sscanf_d_no_match);
  tcase_add_test(tc_d, test_sscanf_d_mixed);
  tcase_add_test(tc_d, test_sscanf_d_zero);
  tcase_add_test(tc_d, test_sscanf_d_large);
  tcase_add_test(tc_d, test_sscanf_d_positive_sign);
  tcase_add_test(tc_d, test_sscanf_d_multiple);
  suite_add_tcase(s, tc_d);

  // %i tests
  tc_i = tcase_create("i specifier");
  for (int i = 0; i < 10; i++) {
    char test_name[50];
    sprintf(test_name, "test_sscanf_i_%d", i);
    // Добавляем тесты по порядку
  }
  tcase_add_test(tc_i, test_sscanf_i_basic);
  tcase_add_test(tc_i, test_sscanf_i_hex);
  tcase_add_test(tc_i, test_sscanf_i_octal);
  tcase_add_test(tc_i, test_sscanf_i_negative);
  tcase_add_test(tc_i, test_sscanf_i_positive);
  tcase_add_test(tc_i, test_sscanf_i_hex_no_prefix);
  tcase_add_test(tc_i, test_sscanf_i_zero);
  tcase_add_test(tc_i, test_sscanf_i_mixed);
  tcase_add_test(tc_i, test_sscanf_i_no_match);
  tcase_add_test(tc_i, test_sscanf_i_with_spaces);
  suite_add_tcase(s, tc_i);

  // Аналогично добавляем остальные TCase для g, o, u, x, p, n
  // %g tests
  tc_g = tcase_create("g specifier");
  tcase_add_test(tc_g, test_sscanf_g_basic);
  tcase_add_test(tc_g, test_sscanf_g_scientific);
  tcase_add_test(tc_g, test_sscanf_g_negative);
  tcase_add_test(tc_g, test_sscanf_g_positive);
  tcase_add_test(tc_g, test_sscanf_g_no_decimal);
  tcase_add_test(tc_g, test_sscanf_g_only_decimal);
  tcase_add_test(tc_g, test_sscanf_g_zero);
  tcase_add_test(tc_g, test_sscanf_g_large);
  tcase_add_test(tc_g, test_sscanf_g_small);
  tcase_add_test(tc_g, test_sscanf_g_no_match);
  suite_add_tcase(s, tc_g);

  // %o tests
  tc_o = tcase_create("o specifier");
  tcase_add_test(tc_o, test_sscanf_o_basic);
  tcase_add_test(tc_o, test_sscanf_o_large);
  tcase_add_test(tc_o, test_sscanf_o_zero);
  tcase_add_test(tc_o, test_sscanf_o_multiple);
  tcase_add_test(tc_o, test_sscanf_o_with_spaces);
  tcase_add_test(tc_o, test_sscanf_o_invalid_digit);
  tcase_add_test(tc_o, test_sscanf_o_no_match);
  tcase_add_test(tc_o, test_sscanf_o_max_octal);
  tcase_add_test(tc_o, test_sscanf_o_mixed);
  tcase_add_test(tc_o, test_sscanf_o_only_octal_digits);
  suite_add_tcase(s, tc_o);

  // %u tests
  tc_u = tcase_create("u specifier");
  tcase_add_test(tc_u, test_sscanf_u_basic);
  tcase_add_test(tc_u, test_sscanf_u_large);
  tcase_add_test(tc_u, test_sscanf_u_zero);
  tcase_add_test(tc_u, test_sscanf_u_multiple);
  tcase_add_test(tc_u, test_sscanf_u_with_spaces);
  tcase_add_test(tc_u, test_sscanf_u_no_match);
  tcase_add_test(tc_u, test_sscanf_u_negative_ignored);
  tcase_add_test(tc_u, test_sscanf_u_mixed);
  tcase_add_test(tc_u, test_sscanf_u_only_digits);
  tcase_add_test(tc_u, test_sscanf_u_bounds);
  suite_add_tcase(s, tc_u);

  // %x tests
  tc_x = tcase_create("x specifier");
  tcase_add_test(tc_x, test_sscanf_x_basic);
  tcase_add_test(tc_x, test_sscanf_x_uppercase);
  tcase_add_test(tc_x, test_sscanf_x_with_prefix);
  tcase_add_test(tc_x, test_sscanf_x_zero);
  tcase_add_test(tc_x, test_sscanf_x_multiple);
  tcase_add_test(tc_x, test_sscanf_x_with_spaces);
  tcase_add_test(tc_x, test_sscanf_x_no_match);
  tcase_add_test(tc_x, test_sscanf_x_mixed_case);
  tcase_add_test(tc_x, test_sscanf_x_large);
  tcase_add_test(tc_x, test_sscanf_x_mixed);
  suite_add_tcase(s, tc_x);

  // %p tests
  tc_p = tcase_create("p specifier");
  tcase_add_test(tc_p, test_sscanf_p_basic);
  tcase_add_test(tc_p, test_sscanf_p_large);
  tcase_add_test(tc_p, test_sscanf_p_null);
  tcase_add_test(tc_p, test_sscanf_p_no_prefix);
  tcase_add_test(tc_p, test_sscanf_p_uppercase);
  tcase_add_test(tc_p, test_sscanf_p_multiple);
  tcase_add_test(tc_p, test_sscanf_p_with_spaces);
  tcase_add_test(tc_p, test_sscanf_p_no_match);
  tcase_add_test(tc_p, test_sscanf_p_zero);
  tcase_add_test(tc_p, test_sscanf_p_mixed);
  suite_add_tcase(s, tc_p);

  // %n tests
  tc_n = tcase_create("n specifier");
  tcase_add_test(tc_n, test_sscanf_n_basic);
  tcase_add_test(tc_n, test_sscanf_n_middle);
  tcase_add_test(tc_n, test_sscanf_n_multiple);
  tcase_add_test(tc_n, test_sscanf_n_with_numbers);
  tcase_add_test(tc_n, test_sscanf_n_empty);
  tcase_add_test(tc_n, test_sscanf_n_no_input);
  tcase_add_test(tc_n, test_sscanf_n_with_spaces);
  tcase_add_test(tc_n, test_sscanf_n_mixed_format);
  tcase_add_test(tc_n, test_sscanf_n_position);
  tcase_add_test(tc_n, test_sscanf_n_complex);
  suite_add_tcase(s, tc_n);

  // %% test
  tc_percent = tcase_create("percent specifier");
  tcase_add_test(tc_percent, test_sscanf_percent);
  suite_add_tcase(s, tc_percent);

  return s;
}