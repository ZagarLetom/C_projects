#include "s21_string.h"

void handle_precision_for_integer(char *buffer, Kit kit);

// ==============================   UTILITIES   ===============================
bool is_digit_sprintf(int el) {
  return (el >= 48 && el <= 57) || (el >= 0 && el <= 9);
}

bool is_int_specifier(Kit kit) {
  return (kit.specifier == 'd' || kit.specifier == 'i' ||
          kit.specifier == 'u' || kit.specifier == 'o' ||
          kit.specifier == 'x' || kit.specifier == 'X');
}

bool to_abs(long long int *number) {
  bool need = false;

  if (*number < 0) {
    need = true;
    *number = -(*number);
  }

  return need;
}

int str_to_int_sprintf(char *str) {
  int number = 0;

  while (*str != '\0') {
    int digit = (int)*str - 48;
    number = number * 10 + digit;
    str++;
  }
  return number;
}

void int_to_str(long long int number, char *buffer, int base) {
  char tmp[1096] = {'\0'};
  int idx = 0;

  bool negative = to_abs(&number);

  if (number == 0) {
    tmp[idx] = '0';
    idx++;
  }

  while (number > 0) {
    tmp[idx] = (char)(number % base + 48);
    number /= base;
    idx++;
  }

  idx--;
  for (int j = 0; idx >= 0; idx--, j++) {
    if (negative && j == 0) {
      buffer[j] = '-';
      j++;
    }

    buffer[j] = tmp[idx];
  }
}

s21_size_t intlen(long double number) {
  s21_size_t len = 0;
  if (number < 0) number *= -1;
  while (number >= 1.0) {
    number = number / 10;
    len++;
  }
  return (len) ? len : 1;
}

long double s21_roundl(long double number, int precision) {
  number = roundl(number * pow(10, precision)) / pow(10, precision);

  return number;
}

long double absfl(long double number) {
  long double result = number;
  if (result < 0) {
    result *= -1;
  }
  return result;
}

void uint_to_str(unsigned long long int number, char *buffer, int base,
                 Kit kit) {
  char tmp[1096] = {'\0'};
  int idx = 0;

  if (number == 0) {
    tmp[idx] = '0';
    idx++;
  }

  while (number > 0) {
    int mod = number % base;
    if (mod < 10) {
      mod += 48;
    } else if (kit.specifier == 'x' || kit.specifier == 'p') {
      mod += 87;
    } else
      mod += 55;
    tmp[idx] = (char)(mod);

    number /= base;
    idx++;
  }

  idx--;
  for (int j = 0; idx >= 0; idx--, j++) buffer[j] = tmp[idx];
}

void float_right_str(char *string, long double number, int precision) {
  if (precision <
      18) {  // если точность до 18 то ориг выводит более менее точное значение
    int prec = precision;
    while (prec) {
      number *= 10;
      prec--;
    }
    number = roundl(number);
    if ((int)(number * 10) % 10 >= 5) number++;
    if ((int)intlen(number) > precision) {
      number = 0;
    }

    int_to_str(number, string, 10);
  } else {
    int i = 0;
    while (precision > 1) {
      number *= 10;
      string[i] = number + '0';
      i++;
      number -= (int)number;
      precision--;
    }
    number *= 10;
    if (((int)(number * 10) % 10 >= 5)) number++;
    string[i] = number + '0';
  }
}

void float_part_str(char *string, long double number, int precision,
                    int is_right) {
  if (precision < 18 && is_right) {  // если точность до 18 то ориг выводит
                                     // более менее точное значение
    int prec = precision;
    while (prec) {
      number *= 10;
      prec--;
    }
    number = roundl(number);
    if ((int)(number * 10) % 10 >= 5) number++;
    if ((int)intlen(number) > precision) {
      number = 0;
    }

    int_to_str(number, string, 10);
  } else {
    int i = 0;
    while (precision > 1) {
      number *= 10;
      string[i] = number + '0';
      i++;
      number -= (int)number;
      precision--;
    }
    number *= 10;
    if (((int)(number * 10) % 10 >= 5) && (is_right)) number++;
    string[i] = number + '0';
  }
}

void float_to_str(char *buffer, long double number, int precision, Kit *kit) {
  int left_size = intlen(number);
  char left_str[1096] = {"\0"};

  if (kit->is_negative) {
    number *= -1;
  }
  long double left;
  long double right = modfl(number, &left);

  int exp = 1;
  for (int i = (kit->is_negative) ? left_size : left_size - 1; i >= 0;
       i--, exp++) {
    left_str[i] = fmodl(left, powl(10, exp)) / powl(10, exp - 1) + '0';
  }
  if (kit->is_negative) left_str[0] = '-';

  int i = s21_strlen(left_str);

  if (precision != 0) {
    char right_str[1096] = {"\0"};
    left_str[i] = '.';
    float_right_str(right_str, right, precision);
    i++;
    for (int zero = 0; zero < (precision - (int)s21_strlen(right_str));
         zero++, i++) {
      left_str[i] = '0';
    }
    s21_strcat(left_str, right_str);
  } else if (kit->sharp) {
    left_str[i] = '.';
  }
  s21_strcat(buffer, left_str);
}

// ===================================   HANDLING
// ========================================

void handle_precision_for_string(char *buffer, Kit kit) {
  // если есть точность
  if (kit.is_precision) {
    int buff_len = s21_strlen(buffer);
    // если она < полной строки, то надо обрезать строку
    if (kit.precision < buff_len) {
      char tmp[1096] = {'\0'};
      s21_strncpy(tmp, buffer, kit.precision);
      s21_strcpy(buffer, tmp);
    }
  }
}

void handle_flag(char *buffer, Kit kit) {
  char tmp[1096] = {'\0'};

  if (kit.plus && kit.specifier != 'u' && *buffer != '-') {
    int j = 0;
    tmp[j++] = '+';

    for (int i = 0; buffer[i]; i++, j++) tmp[j] = buffer[i];

    s21_strcpy(buffer, tmp);
  } else if (kit.blank && kit.specifier != 'u') {
    int j = 0;
    if (kit.plus && *buffer != '-') {
      tmp[j++] = '+';
    } else if (*buffer != '-')
      tmp[j++] = ' ';

    for (int i = 0; buffer[i]; i++, j++) tmp[j] = buffer[i];

    s21_strcpy(buffer, tmp);
  }
}

void handle_width(char *buffer, Kit kit) {
  int buff_len = s21_strlen(buffer);

  if (kit.width > buff_len) {
    char tmp[1096] = {'\0'};

    if (kit.minus) {
      int i = 0;
      for (; buffer[i]; i++) tmp[i] = buffer[i];

      int j = i;
      for (; i < kit.width - buff_len + j; i++) tmp[i] = ' ';

      s21_strcpy(buffer, tmp);
    } else {
      int i = 0, j = 0;
      if (kit.zero && (!(kit.precision < kit.width) || !kit.is_precision)) {
        if ((kit.specifier == 'x' || kit.specifier == 'X') && kit.sharp) {
          tmp[i++] = buffer[0];
          tmp[i++] = buffer[1];
          j += 2;
        }
        // printf("%d\n", i);
        for (; i < kit.width - buff_len + j; i++) tmp[i] = '0';
      } else {
        for (; i < kit.width - buff_len; i++) tmp[i] = ' ';
      }

      for (; buffer[j]; j++, i++) tmp[i] = buffer[j];

      s21_strcpy(buffer, tmp);
    }
  }
}

void handle_float_width(char *buffer, Kit kit) {
  int buff_len = (int)s21_strlen(buffer);

  if (kit.width > buff_len) {
    char tmp[1096] = {'\0'};

    if (kit.minus) {
      int i = 0;
      for (; buffer[i]; i++) tmp[i] = buffer[i];

      int j = i;
      for (; i < kit.width - buff_len + j; i++) tmp[i] = ' ';

      s21_strcpy(buffer, tmp);
    } else {
      int i = 0, j = 0;
      if (kit.zero) {
        for (; i < kit.width - buff_len + j; i++) tmp[i] = '0';
      } else {
        for (; i < kit.width - buff_len; i++) tmp[i] = ' ';
      }

      for (; buffer[j]; j++, i++) tmp[i] = buffer[j];

      s21_strcpy(buffer, tmp);
    }
  }
}

void handle_precision_for_integer(char *buffer, Kit kit) {
  char tmp[1096] = {'\0'};

  int buff_len = s21_strlen(buffer);

  int i = 0;
  if (*buffer == '-') {
    tmp[i] = '-';
    i++;
  }

  if (kit.precision > buff_len) {
    int j = i;
    for (; i < kit.precision - (buff_len - j) + j; i++) tmp[i] = '0';

    for (; buffer[j]; j++, i++) tmp[i] = buffer[j];

    s21_strcpy(buffer, tmp);
  }

  if (kit.is_precision && kit.precision == 0 && *buffer == '0' &&
      is_int_specifier(kit)) {
    *buffer = '\0';
  }
}

void handle_int(char *buffer, va_list valist, Kit kit) {
  long long int arg = va_arg(valist, long long int);

  if (!kit.length) {
    arg = (int)arg;
  } else if (kit.length == 'h') {
    arg = (short int)arg;
  } else if (kit.length == 'l') {
    arg = (long int)arg;
  } else if (kit.length == 'L') {
    arg = (long long int)arg;
  }

  int_to_str(arg, buffer, 10);
  handle_precision_for_integer(buffer, kit);
  handle_flag(buffer, kit);
  handle_width(buffer, kit);
}

void handle_unsigned_int(char *buffer, va_list valist, Kit kit) {
  unsigned long long arg = va_arg(valist, unsigned long long);

  if (!kit.length) {
    arg = (unsigned)arg;
  } else if (kit.length == 'h') {
    arg = (unsigned short)arg;
  } else if (kit.length == 'l') {
    arg = (unsigned long)arg;
  } else if (kit.length == 'L') {
    arg = (unsigned long long)arg;
  }

  uint_to_str(arg, buffer, 10, kit);
  handle_precision_for_integer(buffer, kit);
  handle_width(buffer, kit);
}

void handle_float(char *buffer, va_list valist, Kit *kit) {
  long double number = (kit->length == 'L') ? va_arg(valist, long double)
                                            : va_arg(valist, double);

  if (number != INFINITY) {
    kit->is_negative = (number < 0) ? 1 : 0;

    if (!(kit->is_precision)) {
      kit->is_precision = 1;
      kit->precision = 6;
    }
    if (intlen(number) < 17) {
      number = s21_roundl(number, kit->precision);
    }

    float_to_str(buffer, number, kit->precision, kit);
  } else {
    s21_strcat(buffer, "inf\0");
  }
  handle_flag(buffer, *kit);
  handle_float_width(buffer, *kit);
}

void number_to_mantissa(long double number, char *string, Kit *kit) {
  int p = 0;  // Степень
  if (kit->is_negative) number *= -1;
  long double left;
  modfl(number, &left);
  if (number != 0) {
    if (left > 0) {  // Если положительная степень
      while ((number /= 10) >= 1) {
        p++;
      }
      if ((p == 0 && (int)number == 0) || (p)) {
        number = number * 10;
      }
      number = s21_roundl(number, kit->precision);
    } else {  // Отрицательная степень
      while (number < 1) {
        number *= 10;
        p--;
      }
      number = s21_roundl(number, kit->precision);
      if ((int)number >= 10) {
        number /= 10;
        p++;
      }
    }
  }
  if (kit->is_negative) number *= -1;
  float_to_str(string, number, kit->precision, kit);

  int index = s21_strlen(string);
  int i = 1;
  string[index] = kit->specifier;
  string[index + i] = (p >= 0) ? '+' : '-';
  i++;
  if (p < 0) {
    p *= -1;
  }
  if (p < 10) {
    string[index + i] = '0';
    i++;
  }

  int_to_str(p, string + (index + i), 10);
}

void handle_exhibitor(char *buffer, va_list valist, Kit *kit) {
  long double N = (kit->length == 'L') ? va_arg(valist, long double)
                                       : va_arg(valist, double);
  if (!(kit->is_precision)) {
    kit->is_precision = 1;
    kit->precision = 6;
  }

  kit->is_negative = (N < 0) ? 1 : 0;
  number_to_mantissa(N, buffer, kit);
  handle_float_width(buffer, *kit);
  handle_flag(buffer, *kit);
}

int g_precision(char *string, int len_number, Kit kit) {
  int result = 0;
  int index_right = len_number + (kit.is_negative);
  int mark = -1;
  for (int i = index_right; (string[i]); i++, kit.precision--) {
    if (string[i] == 'E' || string[i] == 'e') {
      break;
    } else if ((string[i] == '0') && (mark == (-1))) {
      mark = i;
    } else if (string[i] != '0') {
      mark = -1;
    }
  }
  if (mark != -1) {
    if (mark == index_right + 1) {
      string[mark - 1] = 0;
      result = mark - 1;
    } else {
      string[mark] = 0;
      result = mark;
    }
  }
  return result;
}

void handle_shortest_float(char *buffer, va_list valist, Kit *kit) {
  long double number = (kit->length == 'L') ? va_arg(valist, long double)
                                            : va_arg(valist, double);
  if (number != INFINITY) {
    kit->is_negative = (number < 0) ? 1 : 0;
    if (!(kit->is_precision)) {
      kit->precision = 6;
    } else if (kit->precision == 0) {
      kit->precision++;
    }
    int precision = kit->precision;
    int len_number = (int)intlen(number);
    if ((precision < len_number || absfl(number) < 0.0001) && (number != 0)) {
      kit->precision--;
      kit->specifier = (kit->specifier == 'G') ? 'E' : 'e';
      number_to_mantissa(number, buffer, kit);
      if (!(kit->sharp)) {
        int index = g_precision(buffer, len_number, *kit);
        if (index) {
          char part[10] = {'\0'};
          int elem = 0;
          index = index + s21_strcspn(buffer + (index + 1), "eE");
          for (int i = index + 1; buffer[i]; i++, elem++) {
            part[elem] = buffer[i];
          }
          s21_strcat(buffer, part);
        }
      }
    } else {
      if (absfl(number) < 1) {
        int sum_zero = 0;
        int prec = 0;
        int mark_start_zero = 0;
        for (int i = 1; prec != kit->precision; i++) {
          if (mark_start_zero) {
            prec++;
          } else {
            if ((int)(number * pow(10, i)) != 0) {
              i++;
              mark_start_zero = 1;
            } else {
              sum_zero++;
            }
          }
        }
        kit->precision += sum_zero;
      } else {
        if (precision != len_number) {
          number = s21_roundl(number, kit->precision);
        }
        kit->precision = precision - len_number;
      }
      char float_str[1096] = {'\0'};
      float_to_str(float_str, number, kit->precision, kit);
      if (!(kit->sharp)) {
        g_precision(float_str, len_number, *kit);
      }
      s21_strcat(buffer, float_str);
    }
  } else {
    s21_strcat(buffer, "inf\0");
  }
  handle_flag(buffer, *kit);
  handle_float_width(buffer, *kit);
}

void handle_char(char *buffer, va_list valist, Kit kit) {
  char arg = va_arg(valist, int);

  if (!kit.length) {
    arg = (int)arg;
  }

  if (kit.minus) {
    *buffer = arg;
    buffer++;
  }
  for (int i = 1; i < kit.width; i++) {
    if (kit.zero) {
      *buffer = '0';
    } else {
      *buffer = ' ';
    }
    buffer++;
  }
  if (!(kit.minus)) {
    *buffer = arg;
    buffer++;
  }
}

void handle_string(char *buffer, va_list valist, Kit kit) {
  char *arg_str = va_arg(valist, char *);

  s21_strcpy(buffer, arg_str);
  handle_precision_for_string(buffer, kit);
  handle_width(buffer, kit);
}

void add_prefix(unsigned long long number, char *buffer, Kit kit) {
  if (number != 0 || kit.specifier == 'p') {
    s21_memmove(buffer + 2, buffer, s21_strlen(buffer));
    buffer[0] = '0';
    buffer[1] = kit.specifier == 'x' || kit.specifier == 'p' ? 'x' : 'X';
  }
}

void handle_oct(char *buffer, va_list valist, Kit kit) {
  unsigned long long arg = va_arg(valist, unsigned long long);

  if (!kit.length) {
    arg = (unsigned)arg;
  } else if (kit.length == 'h') {
    arg = (unsigned short)arg;
  } else if (kit.length == 'l') {
    arg = (unsigned long)arg;
  } else if (kit.length == 'L') {
    arg = (unsigned long long)arg;
  }

  buffer[0] = '0';

  uint_to_str(arg, buffer + kit.sharp, 8, kit);
  handle_precision_for_integer(buffer, kit);
  handle_width(buffer, kit);
}

void handle_hex(char *buffer, va_list valist, Kit kit) {
  unsigned long long arg = va_arg(valist, unsigned long long);

  if (!kit.length) {
    arg = (unsigned)arg;
  } else if (kit.length == 'h') {
    arg = (unsigned short)arg;
  } else if (kit.length == 'l') {
    arg = (unsigned long)arg;
  } else if (kit.length == 'L') {
    arg = (unsigned long long)arg;
  }

  uint_to_str(arg, buffer, 16, kit);
  handle_precision_for_integer(buffer, kit);
  if (kit.sharp) add_prefix(arg, buffer, kit);
  handle_width(buffer, kit);
}

void handle_pointer(char *buffer, va_list valist, Kit kit) {
  unsigned long long arg = va_arg(valist, unsigned long long);

  uint_to_str(arg, buffer, 16, kit);
  add_prefix(arg, buffer, kit);
  handle_width(buffer, kit);
}

void handle_specifier(char *buffer, va_list valist, Kit kit) {
  if (kit.specifier == 'd' || kit.specifier == 'i') {
    handle_int(buffer, valist, kit);
  } else if (kit.specifier == 'u') {
    handle_unsigned_int(buffer, valist, kit);
  } else if (kit.specifier == 'o') {
    handle_oct(buffer, valist, kit);
  } else if (kit.specifier == 'x' || kit.specifier == 'X') {
    handle_hex(buffer, valist, kit);
  } else if (kit.specifier == 'p') {
    handle_pointer(buffer, valist, kit);
  } else if (kit.specifier == 'c') {
    handle_char(buffer, valist, kit);
  } else if (kit.specifier == 's') {
    handle_string(buffer, valist, kit);
  } else if (kit.specifier == 'f' || kit.specifier == 'F') {
    handle_float(buffer, valist, &kit);
  } else if (kit.specifier == 'e' || kit.specifier == 'E') {
    handle_exhibitor(buffer, valist, &kit);
  } else if (kit.specifier == 'g' || kit.specifier == 'G') {
    handle_shortest_float(buffer, valist, &kit);
  } else if (kit.specifier == '%') {
    buffer[0] = '%';
  }
}

// ===============================   PARSING ==================================

char *parse_flags(const char *format, Kit *kit) {
  while (*format == '-' || *format == '+' || *format == ' ' || *format == '#' ||
         *format == '0') {
    switch (*format) {
      case '-':
        kit->minus = true;
        break;
      case '+':
        kit->plus = true;
        break;
      case ' ':
        kit->blank = true;
        break;
      case '#':
        kit->sharp = true;
        break;
      case '0':
        kit->zero = true;
        break;
    }
    format++;
  }
  return (char *)format;
}

char *parse_width_sprintf(const char *format, va_list valist, Kit *kit) {
  if (*format == '*') {
    kit->width = va_arg(valist, int);
    format++;
  } else if (is_digit_sprintf(*format) && *format != '0') {
    int idx = 0;
    char width_buff[1096] = {'\0'};

    while (is_digit_sprintf(*format)) width_buff[idx++] = *format++;

    kit->width = str_to_int_sprintf(width_buff);
  }

  return (char *)format;
}

char *parse_precision(const char *format, va_list valist, Kit *kit) {
  if (*format == '.') {
    kit->is_precision = true;
    format++;
  }

  if (*format == '*') {
    kit->precision = va_arg(valist, int);
    format++;
  } else if (is_digit_sprintf(*format)) {
    int idx = 0;
    char tmp[1096] = {'\0'};

    while (is_digit_sprintf(*format)) tmp[idx++] = *format++;

    kit->precision = str_to_int_sprintf(tmp);
  }

  return (char *)format;
}

char *parse_length_sprintf(const char *format, Kit *kit) {
  if (*format == 'h' || *format == 'l' || *format == 'L') {
    kit->length = *format;
    format++;
    if (*format == 'l') {
      format++;
    }
  }

  return (char *)format;
}

// ==================================   SPRINTF CORE
// =====================================

int s21_sprintf(char *str, const char *format, ...) {
  Kit kit = {0};
  va_list valist;
  va_start(valist, format);

  char *str_tmp = str;

  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      s21_memset(&kit, 0, sizeof(Kit));
    }

    format = parse_flags(format, &kit);
    format = parse_width_sprintf(format, valist, &kit);
    format = parse_precision(format, valist, &kit);
    format = parse_length_sprintf(format, &kit);

    kit.specifier = *format;
    format++;

    char buffer[1096] = {'\0'};
    handle_specifier(buffer, valist, kit);

    for (int i = 0; buffer[i]; i++, str++) *str = buffer[i];

    if (kit.specifier == 'n') {
      int *address = va_arg(valist, int *);
      *address = str - str_tmp;

      printf("%d\n", *address);
    }
  }
  *str = '\0';

  va_end(valist);
  return str - str_tmp;
}