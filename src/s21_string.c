#include "s21_string.h"

#include <stdarg.h>  // for sscanf and sprintf
#include <stdio.h>   // DELETE IT
#include <stdlib.h>  // for advanced funcs

void* s21_memchr(const void* str, int c, s21_size_t n) {
  // Ищет первое вхождение 'c' в n-байтах str
  // custarlo
  unsigned char* ptr = S21_NULL;
  int flag = 0;
  for (unsigned char* p = (unsigned char*)str; n > 0 && flag != 1; p++, n--) {
    if (*p == c) {
      ptr = p;
      flag = 1;
    }
  }
  return (void*)ptr;
}

int s21_memcmp(const void* str1, const void* str2, s21_size_t n) {
  // custarlo
  // Сравниевает первые n-байт 2ух строк
  int diff = 0;
  int flag = 0;
  for (s21_size_t i = 0; i < n && flag != 1; i++) {
    if (*(unsigned char*)(str1 + i) != *(unsigned char*)(str2 + i)) {
      diff = (int)(*(unsigned char*)(str1 + i) - *(unsigned char*)(str2 + i));
      flag = 1;
    }
  }
  return diff;
}

void* s21_memcpy(void* dest, const void* src, s21_size_t n) {
  // condonar
  // Копирует n символов из dest в src
  unsigned char* destinition = (unsigned char*)dest;
  unsigned const char* source = (unsigned const char*)src;

  for (s21_size_t i = 0; i < n; i++) {
    destinition[i] = source[i];
  }
  return dest;
}

void* s21_memset(void* str, int c, s21_size_t n) {
  // condonar
  unsigned char* ptr = (unsigned char*)str;
  unsigned char ch = (unsigned char)c;

  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = ch;
  }
  return str;
}

char* s21_strncat(char* dest, const char* src, s21_size_t n) {
  // condonar
  char* end_of_dest = dest;

  // Находим конец строки dest
  // (здесь идет арифметика указателей)
  while (*end_of_dest !=
         '\0') {  // здесь происходит неявное преобразование типов
    // '\0' имеет тип int (значение 0)
    // Компилятор автоматически преобразует это в нулевой указатель (char*)0
    end_of_dest++;  // увеличивается на sizeof(char) = 1 байт (указатель
                    // указывает на следующий символ)
  }
  // size_t i = 0;
  while (*src != '\0' && n > 0) {  // size[i] != '\0' && i < n - Эквивалентно
    *end_of_dest = *src;           // end_of_dest[i] = src[i]
    end_of_dest++;                 // i++
    src++;
    n--;
  }
  *end_of_dest = '\0';  // end_of_file[i] = '\0'

  return dest;
}

char* s21_strchr(const char* str, int c) {
  int find_symbol = 0;
  char* search_symbol = S21_NULL;
  do {
    if (*str == (char)c) {
      find_symbol = 1;
      search_symbol = (char*)str;
    }
  } while (*str++ != '\0' && !find_symbol);

  return search_symbol;
}

int s21_strncmp(const char* str1, const char* str2, s21_size_t n) {
  // condonar
  /*
  0 - если равны между собой (нет различающихся символов)
  Положительное число (1) - если символ в первой строке больше символа второй
  Отрицательное число (-1) - если этот различающийся символ меньше в первой
  строке
  */
  int result = 0;
  if (n > 0) {
    while (*str1 && *str2 && *str1 == *str2 &&
           n > 0) {  // *str1 тоже самое что *str1 != '\0'
      str1++;
      str2++;
      n--;
    }
    int c1 = (unsigned char)(*str1);
    int c2 = (unsigned char)(*str2);
    // result = (int)(unsigned char)(*str1) - (int)(unsigned char)(*str2);
    if (n > 0) result = c1 - c2;
  }
  return result;
}

char* s21_strncpy(char* dest, const char* src, s21_size_t n) {
  // если строка src меньше чем n, то оставшиеся n заполняются '\0'
  char* start_dest = dest;
  while (n > 0 && *src != '\0') {
    *dest++ = *src++;
    n--;
  }
  while (n > 0) {
    *dest++ = '\0';
    n--;
  }
  return start_dest;
}

s21_size_t s21_strcspn(const char* str1, const char* str2) {
  // custarlo
  s21_size_t n = 0;
  int flag = 0;
  for (int i = 0; *(str1 + i) != '\0' && flag != 1; i++) {
    for (int j = 0; *(str2 + j) != '\0' && flag != 1; j++) {
      if (*(str1 + i) == *(str2 + j)) {
        n = (s21_size_t)i;
        flag = 1;
      }
    }
  }
  if (flag == 0) {
    n = s21_strlen(str1);
  }
  return n;
}

char* s21_strerror(int errnum) {
  // condonar
  static const char* s21_error[] = s21_errno;
  // определяем через static чтобы указатель на него существовал
  // до конца программы
  static char s21_unknown_error[BUF];
  const char* error_text = S21_NULL;

  if (errnum >= 0 && errnum < (int)(sizeof(s21_error) / sizeof(s21_error[0]))) {
    error_text = s21_error[errnum];
  } else {
    s21_sprintf(s21_unknown_error, unkown_error, errnum);
    error_text = s21_unknown_error;
  }
  return (char*)error_text;
}

s21_size_t s21_strlen(const char* str) {
  // custarlo
  s21_size_t n = 0;
  while (str[n] != '\0') {
    n++;
  }
  return n;
}

char* s21_strpbrk(const char* str1, const char* str2) {
  // condonar
  // находит первый символ в str1, который совпадает с ЛЮБЫМ символом из str2
  // Возвращает указатель на этот символ в str1 или NULL если ничего не найдено
  int flag_find = 0;
  char* search_symbol = S21_NULL;
  for (const char* p1 = str1; *p1 != '\0' && !flag_find;
       p1++) {  // перебираем символы в строке str1
    for (const char* p2 = str2; *p2 != '\0' && !flag_find;
         p2++) {  // перебираем символы в строке str2
      if (*p1 == *p2) {
        flag_find = 1;
        search_symbol = (char*)p1;
      }
    }
  }
  return search_symbol;
}

char* s21_strrchr(const char* str, int c) {
  // custarlo ОШИБКА БЫЛА
  char* ptr = S21_NULL;
  char* current = (char*)str;

  // Проходим по всей строке включая нулевой терминатор
  while (*current != '\0') {
    if (*current == (char)c) {
      ptr = current;
    }
    current++;
  }
  if ((char)c == '\0') {
    ptr = current;
  }

  return ptr;
}

char* s21_strstr(const char* haystack, const char* needle) {
  char* substring_ptr = S21_NULL;
  int flag = 0;
  if (*needle == '\0') {
    substring_ptr = (char*)haystack;
    flag = 1;
  }
  for (int i = 0; *(haystack + i) != '\0' && flag != 1; i++) {
    int j = 0;
    while (*(needle + j) != '\0' && *(haystack + i + j) == *(needle + j)) {
      j++;
    }
    if (*(needle + j) == '\0') {
      substring_ptr = (char*)haystack + i;
      flag = 1;
    }
  }
  if (flag == 0) substring_ptr = S21_NULL;
  return substring_ptr;
}

char* s21_strtok(char* str, const char* delim) {
  static char* ptr_str = S21_NULL;
  char* token = S21_NULL;

  int empty_str = 0, start_token = 0, end_token = 0;
  if (str != S21_NULL) {
    ptr_str = str;
  }
  if (ptr_str == S21_NULL || *ptr_str == '\0') {
    return token;
  }
  while (*ptr_str != '\0' && !start_token) {
    int find_delim = 0;
    for (const char* d = delim; *d != '\0' && !find_delim; d++) {
      if (*ptr_str == *d) {
        find_delim = 1;
      }
    }
    if (find_delim) {
      ptr_str++;
    } else {
      start_token = 1;
    }
  }
  if (*ptr_str == '\0') {
    ptr_str = S21_NULL;
    empty_str = 1;
  }
  token = ptr_str;
  while (!empty_str && *ptr_str != '\0' && !end_token) {
    int find_delim = 0;
    for (const char* d = delim; *d != '\0' && !find_delim; d++) {
      if (*ptr_str == *d) {
        find_delim = 1;
      }
    }
    if (find_delim) {
      *ptr_str = '\0';
      ptr_str++;
      end_token = 1;
    } else {
      ptr_str++;
      if (*ptr_str == '\0') {
        end_token = 1;
      }
    }
  }
  return token;
}

// beedleta((((((())))))
//[$][flags][width][.precision][length modifier]conversion
//  Check case with 0 precision and 0 also
//  need long double for
//  e,f,g!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! check
//  conflicts between flags (priority)
void _get_flags(const char** p, int* flag_minus, int* flag_plus,
                int* flag_space, int* flag_hash, int* flag_zero) {
  int parsing_flags = 1;
  while (parsing_flags) {
    switch (**p) {
      case '-':
        *flag_minus = 1;
        (*p)++;
        break;
      case '+':
        *flag_plus = 1;
        (*p)++;
        break;
      case ' ':
        *flag_space = 1;
        (*p)++;
        break;
      case '#':
        *flag_hash = 1;
        (*p)++;
        break;
      case '0':
        *flag_zero = 1;
        (*p)++;
        break;
      default:
        parsing_flags = 0;
        break;
    }
  }
}

int _parse_width(va_list args, const char** p) {
  int width = 0;
  if (**p == '*') {
    width = va_arg(args, int);  // mb need check for negative width?
    (*p)++;
  } else
    while (**p >= '0' && **p <= '9') {
      width = width * 10 + (**p - '0');
      (*p)++;
    }
  return width;
}

int _parse_precision(va_list args, const char** p) {
  int precision = -1;
  if (**p == '.') {
    (*p)++;
    if (**p == '*') {
      precision = va_arg(args, int);
      (*p)++;
    } else {
      precision = 0;
      while (**p >= '0' && **p <= '9') {
        precision = precision * 10 + (**p - '0');
        (*p)++;
      }
    }
  }
  return precision;
}

char _parse_length(const char** p) {
  char length = 0;
  if (**p == 'h' || **p == 'l' || **p == 'L') {
    length = **p;
    (*p)++;
  }
  return length;
}

// cases
int _sprintf_c(va_list args, char buf[BUF], int len) {
  int is_eof = 0;
  char ch = (char)va_arg(args, int);
  if (ch == '\0') is_eof = 1;
  buf[len++] = ch;
  buf[len] = '\0';
  return is_eof;
}

// for case e f g x 32
int _nan_n_inf_check(int lowercase, char buf[BUF], int flag_plus,
                     int flag_space, long double val, int len, int negative) {
  int is_exit = 0;
  if (!(val == val)) {  // NaN
    const char* nan_str = (lowercase) ? "nan" : "NAN";
    if (negative) buf[len++] = '-';
    int i = 0;
    while (nan_str[i]) buf[len++] = nan_str[i++];
    buf[len] = '\0';
    is_exit = 1;
  }

  if ((val == 1.0 / 0.0 || val == -1.0 / 0.0) && !is_exit) {  // infinity
    if (negative)
      buf[len++] = '-';
    else if (flag_plus)
      buf[len++] = '+';
    else if (flag_space)
      buf[len++] = ' ';
    const char* inf_str = (lowercase) ? "inf" : "INF";
    int i = 0;
    while (inf_str[i]) buf[len++] = inf_str[i++];
    buf[len] = '\0';
    is_exit = 1;
  }
  return is_exit;
}

void _rounding(long double* val, int precision) {
  long double rounding = 0.5;
  for (int i = 0; i < precision; i++) rounding /= 10.0;
  *val += rounding;
}

void _split_parts(long double* val, long long* int_part,
                  long double* frac_part) {
  *int_part = (long long)(*val);
  *frac_part = *val - *int_part;
}

void _add_sign(char buf[BUF], int* len, int negative, int flag_plus,
               int flag_space) {
  if (negative)
    buf[(*len)++] = '-';
  else if (flag_plus)
    buf[(*len)++] = '+';
  else if (flag_space)
    buf[(*len)++] = ' ';
}

void _add_frac_part(char buf[BUF], int* len, int precision, int flag_hash,
                    long double frac_part) {
  if (precision > 0 || flag_hash) {
    buf[(*len)++] = '.';
    for (int i = 0; i < precision; i++) {
      frac_part *= 10.0;
      int digit = (int)frac_part;
      buf[(*len)++] = '0' + digit;
      frac_part -= digit;
    }
  }
}

void _add_integer_part(const char conv, char buf[BUF], int* len, int negative,
                       int flag_plus, int flag_space, int flag_hash,
                       long long int_part, int precision) {
  char numbuf[64];
  int numlen = 0, number_sys = 10;
  int is_zero = (int_part == 0), lowercase = (conv == 'x' || conv == 'p');
  if (is_zero && (precision != 0 || conv == 'f'))
    numbuf[numlen++] = '0';
  else if (!is_zero &&
           (conv == 'o' || conv == 'u' || conv == 'i' || conv == 'f')) {
    if (conv == 'o') number_sys = 8;
    do {
      numbuf[numlen++] = '0' + (int_part % number_sys);
      int_part /= number_sys;
    } while (int_part > 0);

  } else if (!is_zero) {
    number_sys = 16;
    do {
      int digit = int_part % number_sys;
      if (digit < 10)
        numbuf[numlen++] = '0' + digit;
      else
        numbuf[numlen++] = (lowercase ? 'a' : 'A') + (digit - 10);
      int_part /= number_sys;
    } while (int_part > 0);
  }

  int is_unsigned =
      (conv == 'o' || conv == 'x' || conv == 'X' || conv == 'u' || conv == 'p');

  // sign add
  if (!is_unsigned && (negative || flag_plus || flag_space)) {
    _add_sign(buf, len, negative, flag_plus, flag_space);
  }
  if (is_unsigned || (conv == 'i' || conv == 'd')) {  // for o u x p
    if (precision > numlen) {
      while (numlen < precision) numbuf[numlen++] = '0';
    }
    if (flag_hash && !is_zero) {
      // for 8sys '0'
      if (number_sys == 8) {
        buf[(*len)++] = '0';
      }
      // 16sys: '0x' or '0X'
      else if (number_sys == 16) {
        buf[(*len)++] = '0';
        buf[(*len)++] = lowercase ? 'x' : 'X';
      }
    }
  }
  for (int i = numlen - 1; i >= 0; i--) buf[(*len)++] = numbuf[i];
}

void _sprintf_di(va_list args, char buf[BUF], int precision, char length,
                 int flag_plus, int flag_space) {
  int len = 0;
  long long val = 0;
  if (length == 'l')
    val = va_arg(args, long);
  else if (length == 'h')
    val = (short)va_arg(args, int);
  else
    val = va_arg(args, int);

  // negative check (i can remove it but i wont =))
  int negative = (val < 0);
  if (negative) val = -val;

  // saving int part
  _add_integer_part('i', buf, &len, negative, flag_plus, flag_space, 0, val,
                    precision);

  buf[len] = '\0';
}

void _sprintf_f(va_list args, char buf[BUF], int precision, char length,
                int flag_plus, int flag_space, int flag_hash) {
  int len = 0;
  long double val = (length == 'L') ? va_arg(args, long double)
                                    : (long double)va_arg(args, double);
  int negative = (val < 0);

  // for eE and gG
  int lowercase = 1;
  int is_exit = _nan_n_inf_check(lowercase, buf, flag_plus, flag_space, val,
                                 len, negative);
  if (!is_exit) {
    if (negative) val = -val;
    if (precision == -1) precision = 6;  // default

    // Rounding
    long long int_part = 0;
    long double frac_part = 0;
    _rounding(&val, precision);
    // saving int part
    _split_parts(&val, &int_part, &frac_part);
    _add_integer_part('f', buf, &len, negative, flag_plus, flag_space, 0,
                      int_part, precision);
    // Fractional part with correct rounding
    _add_frac_part(buf, &len, precision, flag_hash, frac_part);
    buf[len] = '\0';
  }
}

int _define_exponent(long double* val) {
  int exponent = 0;
  if (*val != 0.0) {
    while (*val >= 10.0) {
      *val /= 10.0;
      exponent++;
    }
    while (*val < 1.0) {
      *val *= 10.0;
      exponent--;
    }
  }
  return exponent;
}

void _add_exponent(char buf[BUF], int* len, int exponent, int lowercase) {
  buf[(*len)++] = (lowercase) ? 'e' : 'E';
  if (exponent < 0) {
    buf[(*len)++] = '-';
    exponent = -exponent;
  } else {
    buf[(*len)++] = '+';
  }
  // exponent (for 2+ digit nums)
  if (exponent < 10) {
    buf[(*len)++] = '0';
    buf[(*len)++] = '0' + exponent;
  } else {
    char exp_buf[8];
    int exp_len = 0;
    while (exponent > 0) {
      exp_buf[exp_len++] = '0' + (exponent % 10);
      exponent /= 10;
    }
    for (int i = exp_len - 1; i >= 0; i--) {
      buf[(*len)++] = exp_buf[i];
    }
  }
}

void _sprintf_e(va_list args, char buf[BUF], int precision, char length,
                int flag_plus, int flag_space, int flag_hash, char conv) {
  int len = 0;
  int lowercase = 0;
  long double val = (length == 'L') ? va_arg(args, long double)
                                    : (long double)va_arg(args, double);
  int negative = (val < 0);
  // upper or lower check
  if (conv == 'e') lowercase = 1;
  // nan&inf check
  int is_exit = _nan_n_inf_check(lowercase, buf, flag_plus, flag_space, val,
                                 len, negative);
  if (!is_exit) {
    if (negative) val = -val;
    if (precision == -1) precision = 6;
    int exponent = _define_exponent(&val);
    // rounding
    long long int_part;
    long double frac_part;
    _rounding(&val, precision);
    if (val >= 10.0) {
      val /= 10.0;
      exponent++;
    }
    _split_parts(&val, &int_part, &frac_part);
    _add_integer_part(conv, buf, &len, negative, flag_plus, flag_space, 0,
                      int_part, precision);
    _add_frac_part(buf, &len, precision, flag_hash, frac_part);
    _add_exponent(buf, &len, exponent, lowercase);
    buf[len] = '\0';
  }
}

void __add_frac_digits(char buf[BUF], int* len, int sig, long double* frac) {
  buf[(*len)++] = '.';
  for (int i = 0; i < sig - 1; i++) {
    *frac *= 10.0L;
    int d = (int)(*frac);
    buf[(*len)++] = '0' + d;
    *frac -= d;
  }
}

// for g and G
void _sprintf_g(va_list args, char buf[BUF], int precision, char length,
                int flag_plus, int flag_space, int flag_hash, char conv) {
  int len = 0;
  int lowercase = (conv == 'g');
  long double val = (length == 'L') ? va_arg(args, long double)
                                    : (long double)va_arg(args, double);
  int negative = (val < 0);

  // NaN/Inf
  int is_exit = _nan_n_inf_check(lowercase, buf, flag_plus, flag_space, val,
                                 len, negative);
  if (is_exit) return;

  if (negative) val = -val;
  if (precision == -1) precision = 6;
  if (precision == 0) precision = 1;  // g special

  // special zero
  if (val == 0.0L) {
    _add_sign(buf, &len, negative, flag_plus, flag_space);
    buf[len++] = '0';
    if (flag_hash) {
      buf[len++] = '.';
      for (int i = 0; i < precision - 1; i++) buf[len++] = '0';
    }
    buf[len] = '\0';
    return;
  }

  // compute exponent without modifying original val
  long double tmp = val;
  int exponent = 0;
  while (tmp >= 10.0L) {
    tmp /= 10.0L;
    exponent++;
  }
  while (tmp < 1.0L) {
    tmp *= 10.0L;
    exponent--;
  }

  int use_exp = (exponent < -4 || exponent >= precision);
  int sig = precision;  // significant digits

  if (use_exp) {
    // scientific: 1 digit before dot and sig-1 after
    long double norm = val;
    while (norm >= 10.0L) {
      norm /= 10.0L;
    }
    while (norm < 1.0L) {
      norm *= 10.0L;
    }
    // rounding to sig-1 fractional digits
    long double round = 0.5L;
    for (int i = 0; i < sig - 1; i++) round /= 10.0L;
    norm += round;
    if (norm >= 10.0L) {
      norm /= 10.0L;
      exponent++;
    }

    int first = (int)norm;
    long double frac = norm - first;

    _add_sign(buf, &len, negative, flag_plus, flag_space);

    buf[len++] = '0' + first;
    if (sig > 1 || flag_hash) {
      __add_frac_digits(buf, &len, sig, &frac);
    }
    _add_exponent(buf, &len, exponent, lowercase);
  } else {
    // fixed format
    // integer part
    long long int_part = (long long)val;
    long double frac = val - int_part;
    // count integer digits (for values < 1 there are 0 integer digits)
    int int_digits = 0;
    long long tmpi = int_part;
    if (tmpi == 0) {
      int_digits = 0;
    } else {
      while (tmpi > 0) {
        tmpi /= 10;
        int_digits++;
      }
    }
    int frac_digits = sig - int_digits;
    if (frac_digits < 0) frac_digits = 0;
    // rounding
    long double round = 0.5L;
    for (int i = 0; i < frac_digits; i++) round /= 10.0L;
    frac += round;
    // handle carry into integer part
    if (frac >= 1.0L) {
      int_part += 1;
      frac -= 1.0L;
    }

    _add_sign(buf, &len, negative, flag_plus, flag_space);

    // write integer
    char intbuf[32];
    int ib = 0;
    long long t = int_part;
    if (t == 0)
      intbuf[ib++] = '0';
    else {
      while (t > 0) {
        intbuf[ib++] = '0' + (t % 10);
        t /= 10;
      }
    }

    for (int i = ib - 1; i >= 0; i--) buf[len++] = intbuf[i];

    if (frac_digits > 0 || flag_hash) {
      __add_frac_digits(buf, &len, frac_digits + 1, &frac);
    }
  }

  // strip trailing zeros and dot from the fractional part only (don't touch
  // exponent digits)
  if (!flag_hash) {
    // find exponent position if present
    int exp_pos = -1;
    for (int i = 0; i < len; i++) {
      if (buf[i] == 'e' || buf[i] == 'E') {
        exp_pos = i;
        break;
      }
    }

    // save exponent part (if any)
    char exp_part[32];
    int exp_len = 0;
    if (exp_pos != -1) {
      for (int i = exp_pos; i < len && exp_len < (int)sizeof(exp_part) - 1; i++)
        exp_part[exp_len++] = buf[i];
      exp_part[exp_len] = '\0';
    }

    int last = (exp_pos == -1) ? len - 1 : exp_pos - 1;
    while (last >= 0 && buf[last] == '0') last--;
    if (last >= 0 && buf[last] == '.') last--;

    // terminate at new end of fractional/integer part
    buf[last + 1] = '\0';
    len = last + 1;

    // append exponent back if it existed
    if (exp_pos != -1) {
      for (int i = 0; i < exp_len; i++) buf[len++] = exp_part[i];
    }
  }
  buf[len] = '\0';
}

// for o u x
unsigned long long _init_unsigned(va_list args, char length) {
  unsigned long long val = 0;
  if (length == 'l')
    val = va_arg(args, unsigned long);
  else if (length == 'h')
    val = (unsigned short)va_arg(args, unsigned int);
  else
    val = va_arg(args, unsigned int);
  return val;
}

void _sprintf_o(va_list args, char buf[BUF], int precision, char length,
                int flag_hash) {
  int len = 0;
  unsigned long long val = _init_unsigned(args, length);
  _add_integer_part('o', buf, &len, 0, 0, 0, flag_hash, val, precision);
  buf[len] = '\0';
}

// for n
void _set_falgs_zero(char conv, int* flag_minus, int* flag_plus,
                     int* flag_space, int* flag_hash, int* flag_zero,
                     int* width, int* precision) {
  if (conv != 's') {
    *flag_minus = 0;
    *flag_space = 0;
    *width = 0;
    *precision = -1;
  }
  *flag_plus = 0;
  *flag_hash = 0;
  *flag_zero = 0;
}

// for G
long double _rm_pointless_zeroes(long double val) {
  long int int_part = (long int)val;
  long double frac_part = val - int_part;
  if (frac_part == 0.0) {
    return (double)((long int)(int_part * 100)) / 100;
  }
  return val;
};

void _switch_sprintf(char** out, char** str, const char** f, va_list args,
                     char buf[BUF], int* ch_is_eof, int* precision,
                     int* flag_plus, int* flag_minus, int* flag_space,
                     int* flag_hash, int* flag_zero, int* width) {
  char length = _parse_length(f);
  // Parse conversion specifier
  char conv = **f;
  (*f)++;
  int len = 0;  // for '\0' ch in case c
  switch (conv) {
    case 'c':
      *ch_is_eof = _sprintf_c(args, buf, len);
      break;
    case 'd':  // cause d and i are the same in sprintf
    case 'i':
      _sprintf_di(args, buf, *precision, length, *flag_plus, *flag_space);
      break;
    case 'e':
    case 'E': {
      _sprintf_e(args, buf, *precision, length, *flag_plus, *flag_space,
                 *flag_hash, conv);
      break;
    }
    case 'f': {
      _sprintf_f(args, buf, *precision, length, *flag_plus, *flag_space,
                 *flag_hash);
      break;
    }
    // would be nice add F, but i cant (not in task)
    case 'g':
    case 'G': {
      _sprintf_g(args, buf, *precision, length, *flag_plus, *flag_space,
                 *flag_hash, conv);
      break;
    }
    case 'o': {
      _sprintf_o(args, buf, *precision, length, *flag_hash);
      break;
    }
    case 's': {
      // тоже особенный, возможно и вправду спринтф страдает у меня?
      _set_falgs_zero(conv, flag_minus, flag_plus, flag_space, flag_hash,
                      flag_zero, width, precision);
      const char* s = va_arg(args, char*);
      if (s == S21_NULL) s = "(null)";

      int i = 0;
      while (s[i] && (*precision < 0 || i < *precision) && len < BUF - 1) {
        buf[len++] = s[i++];
      }
      buf[len] = '\0';
      break;
    }
    case 'u': {
      unsigned long long val = _init_unsigned(args, length);
      _add_integer_part('u', buf, &len, 0, 0, *flag_space, 0, val, *precision);
      buf[len] = '\0';
      break;
    }
    case 'x':
    case 'X': {
      unsigned long long val = _init_unsigned(args, length);
      _add_integer_part(conv, buf, &len, 0, 0, *flag_space, *flag_hash, val,
                        *precision);
      buf[len] = '\0';
      break;
    }
    case 'p': {
      void* ptr = va_arg(args, void*);
      if (ptr == S21_NULL) {
        const char* null_str = "(nil)";
        int slen = 0;
        while (null_str[slen]) buf[len++] = null_str[slen++];
      } else {
        unsigned long val = (unsigned long)ptr;
        _add_integer_part(conv, buf, &len, 0, 0, 0, 1, val, -1);
      }
      buf[len] = '\0';
      break;
    }
    case 'n': {
      _set_falgs_zero(conv, flag_minus, flag_plus, flag_space, flag_hash,
                      flag_zero, width, precision);
      int* nptr = va_arg(args, int*);
      *nptr = (int)(*out - *str);
      buf[0] = '\0';
      break;
    }
    case '%': {
      _set_falgs_zero(conv, flag_minus, flag_plus, flag_space, flag_hash,
                      flag_zero, width, precision);
      buf[len++] = '%';
      buf[len] = '\0';
      break;
    }
    default:
      buf[0] = '\0';
      break;
  }
}

void _apply_width_and_alignment(char** out, char* buf, int width, int precision,
                                int flag_minus, int flag_zero, int ch_is_eof) {
  int outlen = (int)s21_strlen(buf) + ch_is_eof;

  if (width > outlen) {
    int pad = width - outlen;

    if (flag_minus) {
      // Left alignment: content then spaces
      for (int i = 0; i < outlen; i++) *(*out)++ = buf[i];
      for (int i = 0; i < pad; i++) *(*out)++ = ' ';
    } else {
      // Right alignment: padding then content
      char padchar = ' ';
      if (flag_zero && precision == -1) padchar = '0';

      // Handle special cases for zero padding with signs
      if (flag_zero && (buf[0] == '-' || buf[0] == '+' || buf[0] == ' ')) {
        *(*out)++ = buf[0];
        buf[0] = '0';
        pad--;
      }
      // Handle special cases for zero padding with hex prefix
      else if (flag_zero &&
               (buf[0] == '0' && (buf[1] == 'X' || buf[1] == 'x'))) {
        *(*out)++ = buf[0];
        *(*out)++ = buf[1];
        buf[0] = '0';
        buf[1] = '0';
        pad -= 2;
      }

      // Add padding
      for (int i = 0; i < pad; i++) *(*out)++ = padchar;

      // Add content
      for (int i = 0; i < outlen; i++) *(*out)++ = buf[i];
    }
  } else {
    // No padding needed, just copy content
    for (int i = 0; i < outlen; i++) *(*out)++ = buf[i];
  }
}

int s21_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);
  char* out = str;
  const char* f = format;
  while (*f) {
    if (*f != '%') {
      *out++ = *f++;
      // continue;  // Need removal
    } else {
      f++;  // skip '%'
      int flag_minus = 0, flag_plus = 0, flag_space = 0, flag_hash = 0,
          flag_zero = 0;
      _get_flags(&f, &flag_minus, &flag_plus, &flag_space, &flag_hash,
                 &flag_zero);
      int width = _parse_width(args, &f);
      int precision = _parse_precision(args, &f);
      char buf[BUF];
      int ch_is_eof = 0;
      _switch_sprintf(&out, &str, &f, args, buf, &ch_is_eof, &precision,
                      &flag_plus, &flag_minus, &flag_space, &flag_hash,
                      &flag_zero, &width);
      _apply_width_and_alignment(&out, buf, width, precision, flag_minus,
                                 flag_zero, ch_is_eof);
    }
  }
  *out = '\0';
  va_end(args);

  return (int)(out - str);
}

// sscanf внутренние функции
int _parse_suppress(const char** f) {
  int suppress_assignment = 0;
  if (**f == '*') {
    suppress_assignment = 1;
    (*f)++;
  }
  return suppress_assignment;
}
int _isspace(const char p) {
  // проверка на пробел
  int space = 0;
  if (p == ' ' || p == '\t' || p == '\n' || p == '\v') space = 1;
  return space;
}

int _isdigit(const char p) {
  // проверка что символ цифра
  // maybe need check for digit-letters tho
  int digit = 0;
  if (p >= '0' && p <= '9') digit = 1;
  return digit;
}

int _letter_digit(const char p, int* digit) {
  int is_digit = 0;
  if (p >= 'a' && p <= 'f') {
    *digit = p - 'a' + 10;
    is_digit = 1;
  } else if (p >= 'A' && p <= 'F') {
    *digit = p - 'A' + 10;
    is_digit = 1;
  }
  return is_digit;
}

int _handle_sign(const char** str_p) {
  int negative = 0;
  if (**str_p == '-') {
    negative = 1;
    (*str_p)++;
  } else if (**str_p == '+') {
    (*str_p)++;
  }
  return negative;
}

int _handle_exponent(long double* value, int exponent, int exp_negative) {
  long double exp_value = 1.0;
  for (int i = 0; i < exponent; i++) {
    exp_value *= 10.0;
  }
  if (exp_negative) {
    *value /= exp_value;
  } else {
    *value *= exp_value;
  }
  return 1;
}

int _handle_frac_part(const char* str_p, const char* before_frac,
                      unsigned long long frac_part, long double* value) {
  long double divisor = 1.0L;  // long double
  int digits = str_p - before_frac;
  for (int i = 0; i < digits; i++) {
    divisor *= 10.0L;
  }
  *value += (long double)frac_part / divisor;  // long double арифметика
  return 1;
}

long long _get_signed_int(unsigned long long value, int negative) {
  long long signed_value = (long long)value;
  if (negative) signed_value = -signed_value;
  return signed_value;
}

void _store_signed_int(int suppress_assignment, char length, va_list args,
                       long long signed_value) {
  if (!suppress_assignment) {
    if (length == 'l') {
      long* ptr = va_arg(args, long*);
      *ptr = (long)signed_value;
    } else if (length == 'h') {
      short* ptr = va_arg(args, short*);
      *ptr = (short)signed_value;
    } else {
      int* ptr = va_arg(args, int*);
      *ptr = (int)signed_value;
    }
  }
}

void _store_unsigned_int(int suppress_assignment, char length, va_list args,
                         unsigned long long value) {
  if (!suppress_assignment) {
    if (length == 'l') {
      unsigned long* ptr = va_arg(args, unsigned long*);
      *ptr = (unsigned long)value;
    } else if (length == 'h') {
      unsigned short* ptr = va_arg(args, unsigned short*);
      *ptr = (unsigned short)value;
    } else {
      unsigned int* ptr = va_arg(args, unsigned int*);
      *ptr = (unsigned int)value;
    }
  }
}

void _store_float(int suppress_assignment, char length, va_list args,
                  long double value) {
  if (!suppress_assignment) {
    if (length == 'L') {
      long double* ptr = va_arg(args, long double*);
      *ptr = value;
    } else {
      double* ptr = va_arg(args, double*);
      *ptr = (double)value;
    }
  }
}

// for d, i (Maybe need exit if not digit)
unsigned long long _convert_digits(const char** str_ptr, int number_sys) {
  unsigned long long value = 0;
  const char* str_p = *str_ptr;  // is it need here? mb try w/o it?

  if (number_sys <= 10) {
    while (_isdigit(*str_p)) {
      value = value * number_sys + (*str_p - '0');
      str_p++;
    }
  } else if (number_sys == 16) {
    int digit = 0;
    while (_isdigit(*str_p) || _letter_digit(*str_p, &digit)) {
      if (_isdigit(*str_p)) {
        value = value * 16 + (*str_p - '0');
      } else {
        value = value * 16 + digit;  // digit set in _letter_digit
      }
      str_p++;
    }
  }

  *str_ptr = str_p;  // refresh pointer
  return value;
}

// for o u x
int _convert_unsigned_int(va_list args, const char** str_ptr, char length,
                          int suppress_assignment, int number_sys, int conv) {
  // Skip whitespace
  while (_isspace(**str_ptr)) (*str_ptr)++;

  const char* start = *str_ptr;

  // Handle optional '+'
  if (**str_ptr == '+') {
    (*str_ptr)++;
  }

  // Handle '-'
  if (**str_ptr == '-') {
    (*str_ptr)++;
    suppress_assignment = 1;
  }

  // Handle prefixes based on number system
  if (number_sys == 8) {
    // Optional '0' prefix for octal
    if (**str_ptr == '0') {
      (*str_ptr)++;
      if (**str_ptr < '0' || **str_ptr > '7') (*str_ptr)--;
    }
  } else if (number_sys == 16) {
    // Optional "0x" or "0X" prefix for hex
    if ((*str_ptr)[0] == '0' &&
        ((*str_ptr)[1] == 'x' || (*str_ptr)[1] == 'X')) {
      *str_ptr += 2;
    }
  }

  // Convert digits
  const char* before_conversion = *str_ptr;
  unsigned long long value = _convert_digits(str_ptr, number_sys);

  // Check success
  if (*str_ptr > before_conversion) {
    if (!suppress_assignment) {
      _store_unsigned_int(suppress_assignment, length, args, value);
    }
    conv++;
  } else {
    // Rollback
    *str_ptr = start;
  }

  return conv;
}

int _convert_pointer(va_list args, const char** str_ptr,
                     int suppress_assignment, int conv) {
  // Get pointer (only if not suppressed)
  void** ptr_p = suppress_assignment ? NULL : va_arg(args, void**);
  int success = 0;

  if (!suppress_assignment && ptr_p) {
    *ptr_p = NULL;
  }

  // Skip whitespace
  while (_isspace(**str_ptr)) (*str_ptr)++;

  const char* start = *str_ptr;

  // Handle "(nil)" case
  if (s21_strncmp(*str_ptr, "(nil)", 5) == 0) {
    if (!suppress_assignment && ptr_p) {
      *ptr_p = NULL;
    }
    *str_ptr += 5;
    success = 1;
  } else {
    // Skip "0x" or "0X" prefix
    if ((*str_ptr)[0] == '0' &&
        ((*str_ptr)[1] == 'x' || (*str_ptr)[1] == 'X')) {
      *str_ptr += 2;
    }

    // Convert hexadecimal digits
    const char* before_conversion = *str_ptr;
    unsigned long long address = _convert_digits(str_ptr, 16);

    // Check if we got valid hex digits
    if (*str_ptr > before_conversion) {
      if (!suppress_assignment && ptr_p) {
        *ptr_p = (void*)(unsigned long)address;
      }
      success = 1;
    } else {
      // No valid digits found - rollback to original position
      *str_ptr = start;
    }
  }

  if (success) conv++;
  return conv;
}

void _sscanf_case_n(va_list args, const char** str_ptr,
                    const char* original_str_start, char length,
                    int suppress_assignment) {
  if (!suppress_assignment) {
    int chars_consumed = (int)(*str_ptr - original_str_start);

    // Store based on length modifier
    switch (length) {
      case 'h': {
        short* ptr = va_arg(args, short*);
        *ptr = (short)chars_consumed;
        break;
      }
      case 'l': {
        long* ptr = va_arg(args, long*);
        *ptr = (long)chars_consumed;
        break;
      }
      default: {
        int* ptr = va_arg(args, int*);
        *ptr = chars_consumed;
        break;
      }
    }
  }
}

void __convert_char_width(va_list args, int width, const char** str_ptr) {
  char* char_ptr = va_arg(args, char*);
  if (width > 0) {
    int chars_read = 0;
    while (chars_read < width && **str_ptr != '\0') {
      char_ptr[chars_read++] = **str_ptr;
      (*str_ptr)++;
    }
  } else {
    *char_ptr = **str_ptr;
    (*str_ptr)++;
  }
}
int _convert_char(va_list args, const char** str_ptr, char length,
                  int suppress_assignment, int width, int conv) {
  // Need make more compact
  if (**str_ptr != '\0') {
    if (!suppress_assignment) {
      if (length == 'l') {
        wchar_t* wchar_ptr = va_arg(args, wchar_t*);
        *wchar_ptr = (wchar_t) * *str_ptr;
        (*str_ptr)++;
      } else {
        __convert_char_width(args, width, str_ptr);
      }
    } else {
      // Just consume characters without storing
      if (width > 0) {
        int chars_read = 0;
        while (chars_read < width && **str_ptr != '\0') {
          (*str_ptr)++;
          chars_read++;
        }
      } else {
        (*str_ptr)++;
      }
    }
    conv++;
  } else {
    conv = -1;
  }

  return conv;
}

int _convert_string(va_list args, const char** str_ptr, char length,
                    int suppress_assignment, int width, int conv) {
  int chars_copied = 0;
  int is_empty = 0;
  if (**str_ptr == '\0') {
    is_empty = 1;
  }

  // Skip whitespace (for %s only)
  while (_isspace(**str_ptr) && !is_empty) (*str_ptr)++;

  if (!suppress_assignment && !is_empty) {
    if (length == 'l') {
      wchar_t* wstr_out = va_arg(args, wchar_t*);
      while (**str_ptr != '\0' && !_isspace(**str_ptr)) {
        if (width > 0 && chars_copied >= width) break;
        *wstr_out++ = (wchar_t) * *str_ptr;
        (*str_ptr)++;
        chars_copied++;
      }
      *wstr_out = L'\0';
    } else {
      char* str_out = va_arg(args, char*);
      while (**str_ptr != '\0' && !_isspace(**str_ptr)) {
        if (width > 0 && chars_copied >= width) break;
        *str_out++ = **str_ptr;
        (*str_ptr)++;
        chars_copied++;
      }
      *str_out = '\0';
    }
  } else if (suppress_assignment && !is_empty) {
    // Just consume without storing
    while (**str_ptr != '\0' && !_isspace(**str_ptr)) {
      if (width > 0 && chars_copied >= width) break;
      (*str_ptr)++;
      chars_copied++;
    }
  }

  if (chars_copied > 0) {
    conv++;
  }

  if (is_empty && conv == 0) conv = -1;

  return conv;
}

int _convert_decimal_int(va_list args, const char** str_ptr, char length,
                         int suppress_assignment, int conv) {
  // Skip whitespace
  while (_isspace(**str_ptr)) (*str_ptr)++;

  const char* before_sign = *str_ptr;    // Position before potential sign
  int negative = _handle_sign(str_ptr);  // handle sign

  // Save position before conversion
  const char* before_conversion = *str_ptr;
  unsigned long long value = _convert_digits(str_ptr, 10);

  // Check if any digits were converted (pointer advanced)
  if (*str_ptr > before_conversion) {
    // Apply sign
    long long signed_value = _get_signed_int(value, negative);
    // Store if not suppressed
    _store_signed_int(suppress_assignment, length, args, signed_value);
    conv++;  // ALWAYS count conversion for numeric types (even when suppressed)
  } else {
    // No digits found -> rollback to position before sign
    *str_ptr = before_sign;
  }

  return conv;
}

int _convert_signed_int(va_list args, const char** str_ptr, char length,
                        int suppress_assignment, int conv) {
  int number_sys = 10;

  while (_isspace(**str_ptr)) (*str_ptr)++;
  const char* before_sign = *str_ptr;
  int negative = _handle_sign(str_ptr);

  // Determine number system
  if (**str_ptr == '0') {
    (*str_ptr)++;
    if (**str_ptr == 'x' || **str_ptr == 'X') {
      number_sys = 16;
      (*str_ptr)++;
    } else {
      number_sys = 8;
      // Don't advance further yet - might be just "0"
    }
  }

  const char* before_conversion = *str_ptr;
  unsigned long long value = _convert_digits(str_ptr, number_sys);

  // Check for successful conversion
  int converted = 0;
  if (*str_ptr > before_conversion) {
    converted = 1;
  } else if (number_sys == 8 && before_conversion > before_sign) {
    // Input was "0" (octal zero)
    value = 0;
    converted = 1;
  } else if (number_sys == 16 && *str_ptr == before_conversion) {
    // Input was "0x" without digits - invalid
    *str_ptr = before_sign;  // Rollback
  }

  if (converted) {
    long long signed_value = _get_signed_int(value, negative);
    _store_signed_int(suppress_assignment, length, args, signed_value);
    conv++;
  }

  return conv;
}

int _convert_double(va_list args, const char** str_ptr, char length,
                    int suppress_assignment, int conv) {
  const char* str_p = *str_ptr;
  int digits_found = 0, negative = 0;
  long double value = 0.0L;
  while (_isspace(*str_p)) str_p++;
  const char* before_conversion = str_p;
  // Handle sign
  negative = _handle_sign(&str_p);
  // Parse integer part
  const char* before_int = str_p;
  unsigned long long int_part = _convert_digits(&str_p, 10);
  if (str_p > before_int) {
    value += (long double)int_part;
    digits_found = 1;
  }
  // Parse fractional part
  if (*str_p == '.') {
    str_p++;
    const char* before_frac = str_p;
    unsigned long long frac_part = _convert_digits(&str_p, 10);
    if (str_p > before_frac)
      digits_found = _handle_frac_part(str_p, before_frac, frac_part, &value);
  }
  // Parse exponent part (for e, E, g, G)

  if (*str_p == 'e' || *str_p == 'E') {
    int exp_negative = 0;
    int exponent = 0;
    str_p++;
    exp_negative = _handle_sign(&str_p);
    // Exponent digits
    const char* before_exp = str_p;
    exponent = (int)_convert_digits(&str_p, 10);
    if (str_p > before_exp) {
      // Apply exponent
      digits_found = _handle_exponent(&value, exponent, exp_negative);
    }
  }
  // Apply sign
  if (negative) value = -value;
  // Store result if we found valid digits
  if (digits_found) {
    _store_float(suppress_assignment, length, args, value);
    conv++;
  } else {
    // No valid digits found - rollback
    str_p = before_conversion;
  }
  *str_ptr = str_p;
  return conv;
}

int _handle_sscanf(va_list args, const char** str_p, char specifier,
                   char length, int suppress_assignment, int width, int conv,
                   const char* original_start, int* parsing_failed) {
  switch (specifier) {  // Используем specifier вместо *f
    case 'c': {
      conv =
          _convert_char(args, str_p, length, suppress_assignment, width, conv);
      break;
    }
    case 's': {
      conv = _convert_string(args, str_p, length, suppress_assignment, width,
                             conv);
      break;
    }
    case 'd': {
      conv =
          _convert_decimal_int(args, str_p, length, suppress_assignment, conv);
      break;
    }
    case 'i': {
      conv =
          _convert_signed_int(args, str_p, length, suppress_assignment, conv);
      break;
    }
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G': {
      conv = _convert_double(args, str_p, length, suppress_assignment, conv);
      break;
    }
    case 'o': {
      conv = _convert_unsigned_int(args, str_p, length, suppress_assignment, 8,
                                   conv);
      break;
    }
    case 'u': {
      conv = _convert_unsigned_int(args, str_p, length, suppress_assignment, 10,
                                   conv);
      break;
    }
    case 'x':
    case 'X': {
      conv = _convert_unsigned_int(args, str_p, length, suppress_assignment, 16,
                                   conv);
      break;
    }
    case 'p': {
      conv = _convert_pointer(args, str_p, suppress_assignment, conv);
      break;
    }
    case 'n': {
      _sscanf_case_n(args, str_p, original_start, length, suppress_assignment);
      break;
    }
    case '%': {
      if (**str_p == '%')
        (*str_p)++;  // Исправлен инкремент указателя
      else
        *parsing_failed = 1;  // Используем переданный указатель
      break;
    }
    default: {
      *parsing_failed = 1;  // Используем переданный указатель
      break;
    }
  }
  return conv;
}

// NEED TO ADD SUPPORT FOR l h L!!!!!!!!!!!! (recheck internal funcs)
int s21_sscanf(const char* str, const char* format, ...) {
  //%[*][width][length]specifier
  va_list args;
  va_start(args, format);

  int conv = 0;

  const char* str_p = str;
  const char* f = format;
  int parsing_failed = 0;
  const char* original_str_start = str;

  while (*f && !parsing_failed) {
    if (*f != '%') {
      if (*f == *str_p) {
        f++;
        str_p++;
      } else {
        break;
      }
    } else {
      f++;                                            // skip '%'
      int suppress_assignment = _parse_suppress(&f);  // flag *
      int width = _parse_width(args, &f);
      char length = _parse_length(&f);
      char specifier = *f;
      conv =
          _handle_sscanf(args, &str_p, specifier, length, suppress_assignment,
                         width, conv, original_str_start, &parsing_failed);

      if (!parsing_failed) {
        f++;  // Move to next format character
      }
    }
  }
  va_end(args);
  return conv;  // remade
}

void* s21_to_upper(const char* str) {
  // raymarle
  if (str == S21_NULL) {  // Проверка входных данных
    return S21_NULL;
  }
  s21_size_t length = s21_strlen(str);  // Вычисление длины
  char* result = (char*)malloc(length + 1);  // выдел. памяти для новой строки
  if (result == S21_NULL) {  // проверка выдел памяти
    return S21_NULL;
  }

  for (s21_size_t i = 0; i < length; i++) {  // для преобразования(регистр)
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - 32;  // разница между а и А 32
    } else {
      result[i] = str[i];
    }
  }
  result[length] = '\0';  // терминатор :)
  return result;
}

void* s21_to_lower(const char* str) {
  // achachat
  char* result = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t length = s21_strlen(str);
    result = malloc(length + 1);
    if (result != S21_NULL) {
      for (s21_size_t i = 0; i < length; i++)
        if (str[i] >= 'A' && str[i] <= 'Z')
          result[i] = str[i] + 32;
        else
          result[i] = str[i];
      result[length] = '\0';
    }
  }
  return result;
}

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  if (src == S21_NULL || str == S21_NULL) return S21_NULL;

  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  if (start_index > src_len) return S21_NULL;

  char* out = (char*)malloc(src_len + str_len + 1);
  if (out == S21_NULL) return S21_NULL;

  if (start_index > 0) {
    s21_memcpy(out, src, start_index);
  }
  if (str_len > 0) {
    s21_memcpy(out + start_index, str, str_len);
  }
  s21_memcpy(out + start_index + str_len, src + start_index,
             src_len - start_index);

  out[src_len + str_len] = '\0';
  return out;
}

void* s21_trim(const char* src, const char* trim_chars) {
  // achachat
  char* result = S21_NULL;
  const char* default_chars = " \t\n";
  s21_size_t flag = 0;

  if (src == S21_NULL) flag = 1;
  if (trim_chars == S21_NULL) trim_chars = default_chars;

  if (!flag) {
    s21_size_t len = s21_strlen(src);

    if (len == 0) {
      result = malloc(1);
      if (result != S21_NULL) {
        result[0] = '\0';
      }
    }

    // Находим начало строки
    s21_size_t start_str = 0;
    while (start_str < len &&
           s21_strchr(trim_chars, src[start_str]) != S21_NULL) {
      start_str++;
    }

    // Находим конец строки
    s21_size_t end_str = len;
    while (end_str > start_str &&
           s21_strchr(trim_chars, src[end_str - 1]) != S21_NULL) {
      end_str--;
    }

    // Выделяем память для результата
    s21_size_t len_result = end_str - start_str;
    result = malloc(len_result + 1);
    if (result != S21_NULL) {
      // Копируем нужную часть строки
      s21_strncpy(result, src + start_str, len_result);
      result[len_result] = '\0';
    }
  }

  return result;
}
