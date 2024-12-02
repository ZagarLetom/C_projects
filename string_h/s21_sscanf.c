#include "s21_string.h"

// ==========================   UTILITIES   ============================

bool is_digit(int el) { return (el >= 48 && el <= 57) || (el >= 0 && el <= 9); }

int is_space(char c) { return (c == ' ' || c == '\n' || c == '\t'); }

bool is_empty(const char *str) {
  // пока строка пуста
  bool empty = 1;

  for (int i = 0; str[i]; i++) {
    // когда нам попадется символ, то она будет не пустая
    if (!is_space(str[i])) {
      empty = 0;
      break;
    }
  }
  return empty;
}

long long int str_to_int(char *str) {
  long long int number = 0;
  int sign = 1;

  while (is_space(*str)) {
    str++;
  }

  if (*str == '-') {
    str++;
    sign = -1;
  }

  if (*str == '+') {
    str++;
  }

  while (*str && is_digit(*str)) {
    int digit = (int)*str - 48;
    number = number * 10 + digit;
    str++;
  }
  number *= sign;

  return number;
}

long long unsigned oct_or_hex_to_int(char *buff, char **endptr, int base) {
  long long unsigned result = 0;
  int sign = 1;

  while (is_space(*buff)) {
    buff++;
  }

  if (*buff == '-') {
    sign = -1;
    buff++;
  } else if (*buff == '+') {
    buff++;
  }

  if (base == 16 &&
      (!s21_strncmp(buff, "0x", 2) || !s21_strncmp(buff, "0X", 2)))
    buff += 2;

  while (*buff) {
    if (*buff >= '0' && *buff <= '9')
      *buff -= '0';
    else if (*buff >= 'A' && *buff <= 'Z')
      *buff -= 'A' - 10;
    else if (*buff >= 'a' && *buff <= 'z')
      *buff -= 'a' - 10;

    result = result * base + *buff;
    buff++;
  }

  if (endptr != s21_NULL) {
    *endptr = (char *)buff;
  }

  return result * sign;
}

long double str_to_double(char *str) {
  long double number = 0.0;

  while (is_space(*str)) {
    str++;
  }

  while (*str && is_digit(*str)) {
    int digit = (int)*str - 48;
    number = number * 10 + digit;
    str++;
  }

  return number;
}

long double pars_left_float(char ***str, Kit *kit, int **err, int *i, int *sign,
                            int *empty_left) {
  char tmp_left[1096] = {'\0'};

  if (s21_strspn(**str, "+-") != 0) {
    if (***str == '-') {
      *sign = -1;
    } else if (***str == '+') {
      *sign = 1;
    }
    (**str)++;
    (*i)++;
    if (kit->width && kit->width <= 1) {
      **err = 1;
    }
  }

  if (!(**err)) {
    // пустая левая часть
    if (***str == '.') {
      *empty_left = 1;
    } else {
      int j = 0;
      while (***str && s21_strspn(**str, "1234567890") != 0) {
        if ((kit->width && *i >= kit->width)) {
          break;
        }
        tmp_left[(j)++] = ***str;
        (**str)++;
        (*i)++;
      }
    }
  }

  long double left = str_to_double(tmp_left);

  return left;
}

long double pars_right_float(char ***str, Kit *kit, int *i, int *i_after_dot,
                             int *empty_right) {
  char tmp_right[1096] = {'\0'};

  if (***str == '.' && (*i < kit->width || !kit->width)) {
    (**str)++;
    (*i)++;
  }
  if (!is_digit(***str) || ***str == '\0') {
    *empty_right = 1;
  } else {
    while (***str && s21_strspn(**str, "1234567890") != 0) {
      if ((kit->width && *i >= kit->width)) {
        break;
      }
      tmp_right[(*i_after_dot)++] = ***str;
      (**str)++;
      (*i)++;
    }
  }

  long double right = str_to_double(tmp_right);
  return right;
}

int is_NAN(char *tmp) {
  // если строки совпадают, то strcmp возвращает 0
  int res = 1;
  res = (s21_strcmp(tmp, "NAN") && s21_strcmp(tmp, "NAn") &&
         s21_strcmp(tmp, "NaN") && s21_strcmp(tmp, "Nan") &&
         s21_strcmp(tmp, "nAN") && s21_strcmp(tmp, "nAn") &&
         s21_strcmp(tmp, "naN") && s21_strcmp(tmp, "nan"));
  // инверсируем выход
  if (res == 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

int is_INF(char *tmp) {
  // если строки совпадают, то strcmp возвращает 0
  int res = 1;
  res = (s21_strcmp(tmp, "INF") && s21_strcmp(tmp, "INf") &&
         s21_strcmp(tmp, "InF") && s21_strcmp(tmp, "Inf") &&
         s21_strcmp(tmp, "iNF") && s21_strcmp(tmp, "iNf") &&
         s21_strcmp(tmp, "inF") && s21_strcmp(tmp, "inf"));
  // инверсируем выход
  if (res == 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}

// ==========================   LENGTH CAST  =================================

void cast_int(long long result, Kit *kit) {
  if (!kit->length) {
    *(int *)kit->buffer = (int)result;
  } else if (kit->length == 'h') {
    *(short int *)kit->buffer = (short int)result;
  } else if (kit->length == 'l') {
    *(long int *)kit->buffer = (long int)result;
  } else if (kit->length == 'L') {
    *(long long int *)kit->buffer = (long long int)result;
  }
}

void cast_unsigned(unsigned long long result, Kit *kit) {
  if (!kit->length) {
    *(unsigned *)kit->buffer = (unsigned)result;
  } else if (kit->length == 'h') {
    *(short unsigned *)kit->buffer = (short unsigned)result;
  } else if (kit->length == 'l') {
    *(long unsigned *)kit->buffer = (long unsigned)result;
  } else if (kit->length == 'L') {
    *(long long unsigned *)kit->buffer = (long long unsigned)result;
  }
}

void cast_float(long double result, Kit *kit) {
  if (!kit->length) {
    *(float *)kit->buffer = (float)result;
  } else if (kit->length == 'l') {
    *(double *)kit->buffer = (double)result;
  } else if (kit->length == 'L') {
    *(long double *)kit->buffer = (long double)result;
  }
}

// =========================   WRITE TO BUFF   =============================

void write_to_buff_char(char **str, Kit *kit, int *count, int *err) {
  *err = 1;
  if (!kit->no_success) {
    while (**str) {
      *err = 0;
      if (kit->width_asterisk) {
        (*str)++;
        break;
      } else {
        // скипаем пробелы в чаре при пробеле в формате
        if (kit->space_char == 1) {
          while (is_space(**str)) {
            (*str)++;
          }
        }
        *(char *)kit->buffer = **str;
        (*str)++;
        (*count)++;
        break;
      }
    }
    while (kit->width > 1 && **str) {
      (*str)++;
      (kit->width)--;
    }
  }
}

void write_to_buff_string(char **str, Kit *kit, int *count, int *err) {
  char tmp[1096] = {'\0'};
  int i = 0;

  while (is_space(**str)) {
    (*str)++;
  }

  while (**str != '\0' && !*err) {
    tmp[i++] = **str;

    if (!kit->width_asterisk && kit->width && i >= kit->width) {
      break;
    }

    (*str)++;

    if (is_space(**str)) {
      (*str)--;
      break;
    }
  }
  (*str)++;

  if (!kit->width_asterisk && i > 0) {
    s21_strcpy((char *)kit->buffer, tmp);
    (*count)++;
  }
}

void write_to_buff_int(char **str, Kit *kit, int *count, int *err) {
  char tmp[1096] = {'\0'};

  if (**str != '\0') {
    *err = 1;
  }

  while (is_space(**str)) {
    (*str)++;
  }

  if (s21_strspn(*str, "+-1234567890")) {
    int sign = s21_strspn(*str, "+-");

    if (!(sign > 1 || (sign && kit->width && kit->width <= 1))) {
      int i = 0;
      *err = 0;
      tmp[i++] = **str;
      (*str)++;
      while (*tmp && **str && s21_strspn(*str, "1234567890") != 0) {
        if ((kit->width && i >= kit->width)) {
          break;
        }

        tmp[i++] = **str;
        (*str)++;
      }

      if (!kit->width_asterisk) {
        (*count)++;
      }
    }
  }

  long long int res = str_to_int(tmp);

  if (!kit->width_asterisk && !*err) {
    cast_int(res, kit);
  }
}

void write_to_buff_unsigned(char **str, Kit *kit, int *count, int *err) {
  char tmp[1096] = {'\0'};

  kit->no_success = 1;
  while (is_space(**str)) {
    (*str)++;
  }

  if (s21_strspn(*str, "+-1234567890")) {
    int sign = s21_strspn(*str, "+-");

    if (!(sign > 1 || (sign && kit->width && kit->width <= 1))) {
      int i = 0;
      kit->no_success = 0;
      tmp[i++] = **str;
      (*str)++;

      while (*tmp && **str && s21_strspn(*str, "1234567890") != 0) {
        if ((kit->width && i >= kit->width) || is_space(**str)) {
          break;
        }

        tmp[i++] = **str;
        (*str)++;
      }

      if (!kit->width_asterisk) {
        (*count)++;
      }
    }
  }

  unsigned long long int res = str_to_int(tmp);

  if (!kit->width_asterisk && !*err && !kit->no_success) {
    cast_unsigned(res, kit);
  }
}

void write_to_buff_oct_or_hex(char **str, Kit *kit, int base, int *count) {
  char tmp[1096] = {'\0'};
  if (kit->specifier == 'p') {
    base = 16;
  }

  char *chars = (base == 16) ? "0123456789abcdefABCDEF" : "01234567";
  int i = 0;
  kit->no_success = 1;

  while (is_space(**str)) {
    (*str)++;
  }

  if (s21_strspn(*str, "+-") == 1 && !(kit->width && kit->width <= 1)) {
    tmp[i++] = **str;
    (*str)++;
  }

  while (s21_strspn(*str, "0xX") != 0) {
    if (**str == 'x' && kit->specifier == 'o') {
      tmp[i] = '0';
      break;
    }
    (*str)++;
  }

  if (is_space(**str) || **str == '\0')
    tmp[i] = '0';
  else {
    while (s21_strspn(*str, chars) != 0) {
      if ((kit->width && i >= kit->width) || is_space(**str)) {
        break;
      }

      tmp[i++] = **str;
      (*str)++;
    }
  }

  if (*tmp != '\0') {
    kit->no_success = 0;
    unsigned long long res = (base == 16) ? oct_or_hex_to_int(tmp, s21_NULL, 16)
                                          : oct_or_hex_to_int(tmp, s21_NULL, 8);

    if (!kit->width_asterisk) {
      (*count)++;

      if (kit->specifier == 'p') {
        *(int *)kit->buffer = (int)res;
      } else {
        cast_unsigned(res, kit);
      }
    }
  }
}

long double write_exhibitor(char ***str, Kit *kit, int **err, long double *left,
                            long double *right, int *i_counter,
                            int *i_after_dot, int *sign) {
  long double res = 0.0;
  char tmp[1096] = {'\0'};
  int i = 0;
  **err = 0;
  int degree = 0;
  int sign_degree = 1;
  int flag_E = 0;

  // работает если нет длины, если она есть, то до парса всей степени е-10
  while (***str && (!kit->width || *i_counter < kit->width)) {
    if (!is_digit(***str) && !(***str == 'E' || ***str == 'e')) {
      break;
    }
    // скипаем все до е Е
    if ((***str == 'E' || ***str == 'e')) {
      flag_E = 1;
      (**str)++;
      (*i_counter)++;
      // защита от не считанной степени
      if (*i_counter == kit->width) {
        (*i_counter)--;
        break;
      }
      if (s21_strspn(**str, "+") != 0) {
        sign_degree = 1;
        (**str)++;
        (*i_counter)++;
      } else if (s21_strspn(**str, "-") != 0) {
        sign_degree = -1;
        (**str)++;
        (*i_counter)++;
      }
      if (*i_counter == kit->width) {
        (*i_counter)--;
        break;
      }

      while (is_digit(***str) && ***str) {
        tmp[i++] = ***str;
        (**str)++;
        (*i_counter)++;
        if (*i_counter == kit->width) {
          (*i_counter)--;
          break;
        }
      }
      degree = str_to_int(tmp);
      break;
    } else {
      (**str)++;
      (*i_counter)++;
    }
  }

  if ((!kit->width || *i_counter < kit->width) && flag_E) {
    if (sign_degree == 1) {
      res = *left * (long double)pow(10, degree) +
            (*right * (long double)pow(10, degree) / pow(10, *i_after_dot));
    } else if (sign_degree == -1) {
      res = *left / (long double)pow(10, degree) +
            (*right / (long double)pow(10, degree) / pow(10, *i_after_dot));
    }
  } else {
    res = *left + (*right / pow(10, *i_after_dot));
  }
  res = res * (*sign);
  return res;
}

void write_to_buff_float(char **str, Kit *kit, int *count, int *err) {
  int i = 0;
  int i_after_dot = 0;
  int empty_left = 0;
  int empty_right = 0;
  int sign = 1;

  while (is_space(**str)) {
    (*str)++;
  }

  if (s21_strspn(*str, "+-1234567890.")) {
    long double left = pars_left_float(&str, kit, &err, &i, &sign, &empty_left);
    long double right =
        pars_right_float(&str, kit, &i, &i_after_dot, &empty_right);
    long double res;

    // куча краевых случаев
    if (empty_left && empty_right) {
      kit->no_success = 1;
      sign = 1;
    }  // .
    if (empty_left && sign == -1 && kit->width == 2) {
      kit->no_success = 1;
      sign = 1;
    }  // -.  при width == 2
    if (kit->width == 1 && empty_left) {
      kit->no_success = 1;
      sign = 1;
    }

    if (!kit->width_asterisk && !kit->no_success) {
      (*count)++;
    }

    // отправляем чекать e E, склеиваем там с правильным округлением
    if (!*err && !kit->no_success) {
      res = write_exhibitor(&str, kit, &err, &left, &right, &i, &i_after_dot,
                            &sign);
    }
    // если все хорошо приводим к нужному размеру
    if (!kit->width_asterisk && !*err && !kit->no_success) {
      cast_float(res, kit);
    }
  } else if (s21_strspn(*str, "NANnanINFinf")) {
    char tmp[1096] = {'\0'};
    int j = 0;
    int count_nan_int = 3;
    *err = 0;
    while (**str && s21_strspn(*str, "NANnanINFinf") != 0 &&
           (count_nan_int > 0)) {
      tmp[j++] = **str;
      (*str)++;
      count_nan_int--;
    }
    // если это было nan or inf
    if (is_NAN(tmp)) {
      *(float *)kit->buffer = NAN;
      if (!kit->width_asterisk) {
        (*count)++;
      }
    } else if (is_INF(tmp)) {
      *(float *)kit->buffer = INFINITY;
      if (!kit->width_asterisk) {
        (*count)++;
      }
    } else {
      *err = 1;
    }
  }
}

void write_to_buff_handle(char **str, Kit *kit, int *count, int *err) {
  // printf("handle");
  if (kit->specifier == 'c') {
    write_to_buff_char(str, kit, count, err);
  } else if (kit->specifier == 's') {
    write_to_buff_string(str, kit, count, err);
  } else if (kit->specifier == 'd') {
    write_to_buff_int(str, kit, count, err);
  } else if (kit->specifier == 'u') {
    write_to_buff_unsigned(str, kit, count, err);
  } else if (kit->specifier == 'o') {
    write_to_buff_oct_or_hex(str, kit, 8, count);
  } else if (kit->specifier == 'x' || kit->specifier == 'X') {
    write_to_buff_oct_or_hex(str, kit, 16, count);
  } else if (kit->specifier == 'i' || kit->specifier == 'p') {
    while (is_space(**str)) {
      (*str)++;
    }
    if (s21_strspn(*str, "0x") == 2 || kit->specifier == 'p') {
      write_to_buff_oct_or_hex(str, kit, 16, count);
    } else if (s21_strspn(*str, "0") == 1) {
      write_to_buff_oct_or_hex(str, kit, 8, count);
    } else {
      write_to_buff_int(str, kit, count, err);
    }
  } else if (kit->specifier == 'f' || kit->specifier == 'e' ||
             kit->specifier == 'E' || kit->specifier == 'g' ||
             kit->specifier == 'G') {
    write_to_buff_float(str, kit, count, err);
  }
}

// ===============================   PARSING ==================================

char *parse_width(char *format, Kit *kit) {
  if (*format == '*') {
    kit->width_asterisk = true;
    format++;
  } else if (is_digit(*format)) {
    int idx = 0;
    char width_buff[1096] = {'\0'};

    while (is_digit(*format)) {
      // при ширине 0 будет работать
      width_buff[idx++] = *format++;
    }

    kit->width = str_to_int(width_buff);
  }

  return (char *)format;
}

char *parse_length(char *format, Kit *kit) {
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    kit->length = *format;
    format++;
    if (*format == 'l') {
      // kit->length = 'L';
      format++;
    }
  }

  return (char *)format;
}

// =======================   SSCANF CORE   ===========================

void get_kit(char **str, char **format, va_list *valist, Kit *kit) {
  if (is_space(**format)) {
    kit->space_char = 1;
  }

  while (is_space(**format)) {
    (*format)++;
    if (is_space(**str)) {
      (*str)++;
    }
  }
  // s21_sscanf(src, "56%5d", &num); ->seg
  if (!kit->specifier) {
    while (**format && !is_space(**format) && **format != '%') {
      //  printf("#");
      if (**format == **str) {
        (*format)++;
        (*str)++;
      } else {
        // printf("!");
        kit->no_success = 1;
        break;
      }
    }
  }

  if (**format == '%' && !kit->specifier) {
    (*format)++;
    if (is_space(**format)) {
      kit->no_success = 1;
    }

    if (**format == '%') {
      if (**format == **str) {
        (*str)++;
      } else {
        kit->no_success = 1;
      }

      (*format)++;
    } else {
      *format = parse_width(*format, kit);
      *format = parse_length(*format, kit);

      kit->specifier = **format;
      (*format)++;

      if (!kit->width_asterisk) {
        kit->buffer = va_arg(*valist, void *);
      }
    }
  }
}

int s21_sscanf(const char *str, const char *format, ...) {
  int count = 0;
  int err = 0;

  // пуста при 1
  bool is_eof = is_empty(str);
  // если строка пуста, то ошибка
  if (is_eof == 1) {
    err = 1;
  }
  char *str_tmp = (char *)str;

  // не пуста
  if (!is_eof) {
    va_list valist;
    va_start(valist, format);

    char *src = (char *)str;
    char *fsrc = (char *)format;
    int no_succ = 0;
    while (*fsrc && !err && !no_succ) {
      Kit kit = {0};
      get_kit(&src, &fsrc, &valist, &kit);

      if (kit.specifier == 'n') {
        int n = src - str_tmp;
        *(int *)kit.buffer = (int)n;
        // printf("%d", n);
      }
      if (!kit.no_success) {
        write_to_buff_handle(&src, &kit, &count, &err);
      }
      no_succ = kit.no_success;
    }

    va_end(valist);
  }

  // если не было успехов и count == 0, это не значит что были ошибки
  return (count || err == 0) ? count : -1;
}