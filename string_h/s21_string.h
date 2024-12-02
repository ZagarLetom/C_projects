#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  bool minus;
  bool plus;
  bool blank;
  bool sharp;
  bool zero;

  int width;
  int precision;
  bool is_precision;
  bool is_negative;
  char length;
  char specifier;

  bool width_asterisk;
  void *buffer;
  int space_char;
  int no_success;
} Kit;

typedef long unsigned s21_size_t;
#define s21_NULL (void *)0

// 1 Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str.
void *s21_memchr(const void *str, int c, s21_size_t n);

// 2 Сравнивает первые n байтов str1 и str2.
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);

// 3 Копирует n символов из src в dest.
void *s21_memcpy(void *dest, const void *src, s21_size_t n);

// 4 Еще одна функция для копирования n символов из src в dest.
void *s21_memmove(void *dest, const void *src, s21_size_t n);

// 5 Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str.
void *s21_memset(void *str, int c, s21_size_t n);

// 6 Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest.
char *s21_strcat(char *dest, const char *src);

// 7 Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n);

// 8 Выполняет поиск первого вхождения символа c (беззнаковый тип) в строке, на
// которую указывает аргумент str.
char *s21_strchr(const char *str, int c);

// 9 Сравнивает строку, на которую указывает str1, со строкой, на которую
// указывает str2.
int s21_strcmp(const char *str1, const char *str2);

// 10 Сравнивает не более первых n байтов str1 и str2.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);

// 11 Копирует строку, на которую указывает src, в dest.
char *s21_strcpy(char *dest, const char *src);

// 12 Копирует до n символов из строки, на которую указывает src, в dest.
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

// 13 Вычисляет длину начального сегмента str1, который полностью состоит из
// символов, не входящих в str2.
s21_size_t s21_strcspn(const char *str1, const char *str2);

// 14 Выполняет поиск во внутреннем массиве номера ошибки errnum и возвращает
// указатель на строку с сообщением об ошибке. Нужно объявить макросы,
// содержащие массивы сообщений об ошибке для операционных систем mac и linux.
// Описания ошибок есть в оригинальной библиотеке. Проверка текущей ОС
// осуществляется с помощью директив.
char *s21_strerror(int errnum);

// 15 Вычисляет длину строки str, не включая завершающий нулевой символ.
s21_size_t s21_strlen(const char *str);

// 16 Находит первый символ в строке str1, который соответствует любому символу,
// указанному в str2.
char *s21_strpbrk(const char *str1, const char *str2);

// 17 Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке,
// на которую указывает аргумент str.
char *s21_strrchr(const char *str, int c);

// 18 Вычисляет длину начального сегмента str1, который полностью состоит из
// символов str2.
s21_size_t s21_strspn(const char *str1, const char *str2);

// 19 Находит первое вхождение всей строки needle (не включая завершающий
// нулевой символ), которая появляется в строке haystack.
char *s21_strstr(const char *haystack, const char *needle);

// 20 Разбивает строку str на ряд токенов, разделенных delim.
char *s21_strtok(char *str, const char *delim);

int s21_sprintf(char *str, const char *format, ...);
int s21_sscanf(const char *str, const char *format, ...);

// =================  C# ===================
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

#endif  // SRC_S21_STRING_H_