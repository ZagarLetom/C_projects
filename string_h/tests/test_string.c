#include "unit.h"

START_TEST(memchr1) {
  char str[] = "Hello world";
  int c = 'H';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr2) {
  char str[] = "Hello world";
  int c = 'H';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr3) {
  char str[] = "Hello world";
  int c = 'H';
  s21_size_t n = 20;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr4) {
  char str[] = "Hello world";
  int c = 'Y';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr5) {
  char str[] = "Hello world";
  int c = 'Y';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr6) {
  char str[] = "Hello world";
  int c = 'Y';
  s21_size_t n = 20;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr7) {
  char str[] = "Hello world";
  int c = '\0';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr8) {
  char str[] = "Hello world";
  int c = '\0';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr9) {
  char str[] = "Hello world";
  int c = '\0';
  s21_size_t n = 20;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr10) {
  char str[] = "Hello \0world";
  int c = 'w';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr11) {
  char str[] = "Hello \0world";
  int c = 'w';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr12) {
  char str[] = "Hello \0world";
  int c = 'w';
  s21_size_t n = 20;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr13) {
  char str[] = "\0world";
  int c = 'w';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr14) {
  char str[] = "\0world";
  int c = 'w';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr15) {
  char str[] = "\0world";
  int c = 'w';
  s21_size_t n = 20;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr16) {
  char str[] = "";
  int c = 'w';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr17) {
  char str[] = "";
  int c = 'w';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr18) {
  char str[] = " ";
  int c = 'w';
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr19) {
  char str[] = " ";
  int c = 'w';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr20) {
  char str[] = "12345";
  int c = '5';
  s21_size_t n = 1;
  ck_assert_pstr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr21) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 1;
  s21_size_t n = 0;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr22) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 1;
  s21_size_t n = sizeof(int) * 1;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr23) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 1;
  s21_size_t n = sizeof(int) * 5;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr24) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 1;
  s21_size_t n = sizeof(int) * 10;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr25) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 3;
  s21_size_t n = sizeof(int) * 5;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr26) {
  int arr[] = {1, 2, 3, 4, 5};
  int c = 6;
  s21_size_t n = sizeof(int) * 5;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr27) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  float c = 1.1;
  s21_size_t n = sizeof(float) * 0;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr28) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  float c = 1.1;
  s21_size_t n = sizeof(float) * 1;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr29) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  float c = 1.1;
  s21_size_t n = sizeof(float) * 5;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

START_TEST(memchr30) {
  float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  float c = 6.1;
  s21_size_t n = sizeof(float) * 5;
  ck_assert_pstr_eq(memchr(arr, c, n), s21_memchr(arr, c, n));
}
END_TEST

// ----------------------------------------------------------
// 2 MEMCMP
START_TEST(memcmp1) {
  char str1_1[] = "Hello, World";
  char str1_2[] = "Hello, World";
  s21_size_t n = 0;
  int res = s21_memcmp(str1_1, str1_2, n);
  int orig = memcmp(str1_1, str1_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp2) {
  char str2_1[] = "Hello, World";
  char str2_2[] = "Hello, World";
  s21_size_t n = 5;
  int res = s21_memcmp(str2_1, str2_2, n);
  int orig = memcmp(str2_1, str2_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp3) {
  char str3_1[] = "Hello, World";
  char str3_2[] = "Hello, World";
  s21_size_t n = 15;
  int res = s21_memcmp(str3_1, str3_2, n);
  int orig = memcmp(str3_1, str3_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp4) {
  char str4_1[] = "Hello, World";
  char str4_2[] = "HeLLo, World";
  s21_size_t n = 20;
  int res = s21_memcmp(str4_1, str4_2, n);
  int orig = memcmp(str4_1, str4_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp5) {
  char str5_1[] = "Hello, World";
  char str5_2[] = "H";
  s21_size_t n = 5;
  int res = s21_memcmp(str5_1, str5_2, n);
  int orig = memcmp(str5_1, str5_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp6) {
  char str6_1[] = "Hello, World";
  char str6_2[] = "Y";
  s21_size_t n = 15;
  int res = s21_memcmp(str6_1, str6_2, n);
  int orig = memcmp(str6_1, str6_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp7) {
  char str7_1[] = "H";
  char str7_2[] = "Hello, World";
  s21_size_t n = 15;
  int res = s21_memcmp(str7_1, str7_2, n);
  int orig = memcmp(str7_1, str7_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp8) {
  char str8_1[] = "\0";
  char str8_2[] = "Hello, World";
  s21_size_t n = 15;
  int res = s21_memcmp(str8_1, str8_2, n);
  int orig = memcmp(str8_1, str8_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

START_TEST(memcmp9) {
  char str9_1[] = "Hello, \0World\0";
  char str9_2[] = "Hello, World";
  s21_size_t n = 15;
  int res = s21_memcmp(str9_1, str9_2, n);
  int orig = memcmp(str9_1, str9_2, n);

  ck_assert_int_eq(res, orig);
}
END_TEST

// START_TEST(memcmp10) {
//   char str10_1[] = "\0";
//   char str10_2[] = "\0";
//   s21_size_t n = 15;
//   int res = s21_memcmp(str10_1, str10_2, n);
//   int orig = memcmp(str10_1, str10_2, n);
//   if (orig > 0) {
//     orig = 1;
//   }
//   if (orig < 0) {
//     orig = -1;
//   }
//   ck_assert_int_eq(res, orig);
// }
// END_TEST

// ----------------------------------------------------------
// 3 MEMCPY
START_TEST(memcpy1) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Yesno";
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy2) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Yesno";
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy3) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Yesno";
  s21_size_t n = 10;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy4) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Y";
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy5) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Y";
  s21_size_t n = 5;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy6) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Y!!!!!!!!!!!!!!";
  s21_size_t n = 5;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy7) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "Y!!!!!!!!!!!!!!";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy8) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "\0";
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy9) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "\0";
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy10) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "\0";
  s21_size_t n = 5;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy11) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "hi\0mom";
  s21_size_t n = 3;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy12) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "hi\0mom";
  s21_size_t n = 6;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy13) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "hi\0mom";
  s21_size_t n = 10;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy14) {
  char res[50] = "Hel\0lo";
  char orig[50] = "Hel\0lo";
  char src[] = "hi\0";
  s21_size_t n = 3;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy15) {
  char res[50] = "Hel\0lo";
  char orig[50] = "Hel\0lo";
  char src[] = "hi\0";
  s21_size_t n = 4;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy16) {
  char res[50] = "Hel\0lo";
  char orig[50] = "Hel\0lo";
  char src[] = "hi\0";
  s21_size_t n = 7;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy17) {
  char res[50] = "Hello";
  char orig[50] = "Hello";
  char src[] = "hi\0mom";
  s21_size_t n = 6;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy18) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "hi";
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy19) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "hi";
  s21_size_t n = 5;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy20) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "hi\0mom";
  s21_size_t n = 10;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy21) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy22) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

START_TEST(memcpy23) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  s21_size_t n = 10;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memcpy(res, src, n), memcpy(orig, src, n), check_n);
}
END_TEST

// ----------------------------------------------------------
// 4 MEMMOVE
// Еще одна функция для копирования n символов из src в dest.
START_TEST(memmove1) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "Yesno";
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove2) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "Yesno";
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove3) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "Yesno";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove4) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  s21_size_t n = 1;
  s21_size_t check_n = 1;
  ck_assert_mem_eq(s21_memmove(res, res + 10, n), memmove(orig, res + 10, n),
                   check_n);
}
END_TEST

START_TEST(memmove5) {
  char res[50] = "1234567890\0qwerty";
  char orig[50] = "1234567890\0qwerty";
  char src[] = "Yesno";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove6) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "Yes\0no";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove7) {
  char res[50] = "1234567\0890qwerty";
  char orig[50] = "1234567\0890qwerty";
  char src[] = "Yes\0no";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove8) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "Yes";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove9) {
  char res[50] = "\0890qwerty";
  char orig[50] = "\0890qwerty";
  char src[] = "Yes";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove10) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "Yes\0no";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove11) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove12) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  char src[] = "\0no";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove13) {
  char res[50] = "\01234567890qwerty";
  char orig[50] = "\01234567890qwerty";
  char src[] = "\0yes\0";
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove14) {
  char res[50] = "01234567890qwerty";
  char orig[50] = "01234567890qwerty";
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t n = 0;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove15) {
  char res[50] = "01234567890qwerty";
  char orig[50] = "01234567890qwerty";
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t n = 1;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove16) {
  char res[50] = "01234567890qwerty";
  char orig[50] = "01234567890qwerty";
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t n = 10;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

START_TEST(memmove17) {
  char res[50] = "01234567890qwerty";
  char orig[50] = "01234567890qwerty";
  int src[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  s21_size_t n = 20;
  s21_size_t check_n = 20;
  ck_assert_mem_eq(s21_memmove(res, src, n), memmove(orig, src, n), check_n);
}
END_TEST

// ----------------------------------------------------------
// 5 MEMSET
// Копирует символ c в первые n символов строки
START_TEST(memset1) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  int c = 'o';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset2) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  int c = 'o';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset3) {
  char res[50] = "1234567890qwerty";
  char orig[50] = "1234567890qwerty";
  int c = 'o';
  s21_size_t n = 20;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset4) {
  char res[50] = "1234567890 qwerty";
  char orig[50] = "1234567890 qwerty";
  int c = '1';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset5) {
  char res[50] = "1234567890 qwerty";
  char orig[50] = "1234567890 qwerty";
  int c = '1';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset6) {
  char res[50] = "1234567890 qwerty";
  char orig[50] = "1234567890 qwerty";
  int c = '1';
  s21_size_t n = 20;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset7) {
  char res[50] = "12345 67890 qwerty";
  char orig[50] = "12345 67890 qwerty";
  int c = '\0';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset8) {
  char res[50] = "12345 67890 qwerty";
  char orig[50] = "12345 67890 qwerty";
  int c = '\0';
  s21_size_t n = 5;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset9) {
  char res[50] = "12345 67890 qwerty";
  char orig[50] = "12345 67890 qwerty";
  int c = '\0';
  s21_size_t n = 20;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset10) {
  char res[50] = "12345 \067890 \0qwerty";
  char orig[50] = "12345 \067890 \0qwerty";
  int c = 'n';
  s21_size_t n = 0;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset11) {
  char res[50] = "12345 \067890 \0qwerty";
  char orig[50] = "12345 \067890 \0qwerty";
  int c = 'n';
  s21_size_t n = 20;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

START_TEST(memset12) {
  char res[50] = "12345 \067890 qwerty";
  char orig[50] = "12345 \067890 qwerty";
  int c = '\0';
  s21_size_t n = 20;
  ck_assert_pstr_eq(s21_memset(res, c, n), memset(orig, c, n));
}
END_TEST

// ----------------------------------------------------------
// 6 STRCAT
START_TEST(strcat1) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "mom";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat2) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "mom. 42";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat3) {
  char res[50] = "Hi";
  char orig[50] = "Hi";
  char src[] = "";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat4) {
  char res[50] = "Hi";
  char orig[50] = "Hi";
  char src[] = "!\0 hi";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat5) {
  char res[50] = "Hi";
  char orig[50] = "Hi";
  char src[] = " ";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat6) {
  char res[] = "";
  char orig[] = "";
  char src[] = "";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat7) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "mom";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat8) {
  char res[50] = "hi\0 hi";
  char orig[50] = "hi\0 hi";
  char src[] = "World";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat9) {
  char res[] = " ";
  char orig[] = " ";
  char src[] = "";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

START_TEST(strcat10) {
  char res[50] = " ";
  char orig[50] = " ";
  char src[] = "mom";
  ck_assert_str_eq(s21_strcat(res, src), strcat(orig, src));
}
END_TEST

// ----------------------------------------------------------
// 7 STRNCAT
START_TEST(strncat1) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "mom";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat2) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "mom";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat3) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "mom";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat4) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "\0";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat5) {
  char res[50] = "Hi, ";
  char orig[50] = "Hi, ";
  char src[] = "\0";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat6) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "mom";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat7) {
  char res[50] = "\0";
  char orig[50] = "\0";
  char src[] = "mom";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat8) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "mom";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat9) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat10) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat11) {
  char res[50] = "Hi, \0 hello, 42 ";
  char orig[50] = "Hi, \0 hello, 42 ";
  char src[] = "mom";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat12) {
  char res[50] = "Hi, \0 hello, 42 ";
  char orig[50] = "Hi, \0 hello, 42 ";
  char src[] = "mom\0 resg";
  s21_size_t n = 4;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

START_TEST(strncat13) {
  char res[50] = "Hi, \0 hello, 42 ";
  char orig[50] = "Hi, \0 hello, 42 ";
  char src[] = "mom\0 resg";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncat(res, src, n), strncat(orig, src, n));
}
END_TEST

// ----------------------------------------------------------
// 8 STRCHR
START_TEST(strchr1) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strchr(str, ' '), s21_strchr(str, ' '));
}
END_TEST

START_TEST(strchr2) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strchr(str, 'H'), s21_strchr(str, 'H'));
}
END_TEST

START_TEST(strchr3) {
  char str[] = "Hello, world!42";
  ck_assert_pstr_eq(strchr(str, '2'), s21_strchr(str, '2'));
}
END_TEST

START_TEST(strchr4) {
  char str[] = "Hello, world!";
  ck_assert_pstr_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(strchr5) {
  char str[] = "Hello,\0 world!";
  ck_assert_pstr_eq(strchr(str, 'w'), s21_strchr(str, 'w'));
}
END_TEST

START_TEST(strchr6) {
  char str[] = "";
  ck_assert_pstr_eq(strchr(str, '\0'), s21_strchr(str, '\0'));
}
END_TEST

START_TEST(strchr7) {
  char str[] = "";
  ck_assert_pstr_eq(strchr(str, 'H'), s21_strchr(str, 'H'));
}
END_TEST

// ----------------------------------------------------------
// 9 STRCMP
START_TEST(strcmp1) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp2) {
  char str1[] = "Hello, World";
  char str2[] = "HeLLo, World";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp3) {
  char str1[] = "Hello, World";
  char str2[] = "H";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp4) {
  char str1[] = "Hello, World";
  char str2[] = "L";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp5) {
  char str1[] = "Hello, World";
  char str2[] = "\0";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp6) {
  char str1[] = "\0";
  char str2[] = "Hello, World";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp7) {
  char str1[] = "Hello, \0World";
  char str2[] = "Hello, World";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

START_TEST(strcmp8) {
  char str1[] = "Hello, World";
  char str2[] = "Hello,\0 World";
  ck_assert_int_eq(s21_strcmp(str1, str2), strcmp(str1, str2));
}
END_TEST

// ----------------------------------------------------------
// 10 STRNCMP
START_TEST(strncmp1) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp2) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  s21_size_t n = 12;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp3) {
  char str1[] = "Hello, World";
  char str2[] = "Hello, World";
  s21_size_t n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp4) {
  char str1[] = "Hello, World";
  char str2[] = "HeLLo, World";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp5) {
  char str1[] = "Hello, World";
  char str2[] = "H";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp6) {
  char str1[] = "Hello, World";
  char str2[] = "Y";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp7) {
  char str1[] = "Hello, World";
  char str2[] = "H";
  s21_size_t n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp8) {
  char str1[] = "H";
  char str2[] = "Hello, World";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp9) {
  char str1[] = "H";
  char str2[] = "Hello, World";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp10) {
  char str1[] = "H";
  char str2[] = "Hello, World";
  s21_size_t n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp11) {
  char str1[] = "\0";
  char str2[] = "Hello, World";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp12) {
  char str1[] = "\0";
  char str2[] = "Hello, World";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp13) {
  char str1[] = "\0";
  char str2[] = "Hello, World";
  s21_size_t n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp14) {
  char str1[] = "Hello, World\0";
  char str2[] = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp15) {
  char str1[] = "Hello, World\0";
  char str2[] = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp16) {
  char str1[] = "Hello, World\0";
  char str2[] = "\0";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp17) {
  char str1[] = "Hello, \0World\0";
  char str2[] = "Hello, World";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp18) {
  char str1[] = "Hello, \0World\0";
  char str2[] = "Hello, World";
  s21_size_t n = 15;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp19) {
  char str1[] = "Hello, \0World\0";
  char str2[] = "Hello, Wo\0rld";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp20) {
  char str1[] = "\0";
  char str2[] = "\0";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp21) {
  char str1[] = "\0";
  char str2[] = "\0";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp22) {
  char str1[] = "\0";
  char str2[] = "\0";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp23) {
  char str1[] = "Hello, World";
  char str2[] = "Y";
  s21_size_t n = 1;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp24) {
  char str1[] = "Hello, World";
  char str2[] = "Y";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// ----------------------------------------------------------
// 11 STRCPY
START_TEST(strcpy1) {
  char res[50] = "He110";
  char orig[50] = "He110";
  char src[] = "Yesno";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy2) {
  char res[50] = "He110";
  char orig[50] = "He110";
  char src[] = "Y";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy3) {
  char res[50] = "He110";
  char orig[50] = "He110";
  char src[] = "Hi!!!!!!!!!!";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy4) {
  char res[50] = "He110";
  char orig[50] = "He110";
  char src[] = "\0";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy5) {
  char res[50] = "\0";
  char orig[50] = "\0";
  char src[] = "Hello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy6) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "Hello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy7) {
  char res[50] = "\0hi";
  char orig[50] = "\0hi";
  char src[] = "hello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy8) {
  char res[50] = "";
  char orig[50] = "";
  char src[] = "";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy9) {
  char res[50] = "He110";
  char orig[50] = "He110";
  char src[] = "Yesssssss";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy10) {
  char res[50] = "   hi   ! ";
  char orig[50] = "   hi   ! ";
  char src[] = "42";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy11) {
  char res[50] = "42";
  char orig[50] = "42";
  char src[] = "   hi   ! ";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy12) {
  char res[50] = "He1\010";
  char orig[50] = "He1\010";
  char src[] = "Hello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy13) {
  char res[50] = "He1\0lo";
  char orig[50] = "He1\0lo";
  char src[] = "Hello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy14) {
  char res[50] = "He1\0lo";
  char orig[50] = "He1\0lo";
  char src[] = "H\0ello";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy15) {
  char res[50] = "Hello, world\"";
  char orig[50] = "Hello, world\"";
  char src[] = "Hi111111111111111111111111";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy16) {
  char res[50] = " ";
  char orig[50] = " ";
  char src[] = "Hi";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

START_TEST(strcpy17) {
  char res[50] = " ";
  char orig[50] = " ";
  char src[] = " ";
  ck_assert_str_eq(s21_strcpy(res, src), strcpy(orig, src));
}
END_TEST

// ----------------------------------------------------------
// 12 STRNCPY
// Копирует до n символов из src, в dest.
START_TEST(strncpy1) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yesno";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy2) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yesno";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy3) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yesno";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy4) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yesno";
  s21_size_t n = 15;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy5) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yesno";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy6) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yes no";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy7) {
  char res[50] = "1234567\089qwerty";
  char orig[50] = "1234567\089qwerty";
  char src[] = "Yes no";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy8) {
  char res[50] = "123456789qwerty";
  char orig[50] = "123456789qwerty";
  char src[] = "Yes \0no";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy9) {
  char res[50] = "1234567\089qwerty";
  char orig[50] = "1234567\089qwerty";
  char src[] = "Yes n\0o";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy10) {
  char res[50] = "\0";
  char orig[50] = "\0";
  char src[] = "Yes n\0o";
  s21_size_t n = 20;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy11) {
  char res[50] = "\0";
  char orig[50] = "\0";
  char src[] = "\0 yes";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

START_TEST(strncpy12) {
  char res[50] = "\0";
  char orig[50] = "\0";
  char src[] = "\0 yes";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncpy(res, src, n), strncpy(orig, src, n));
}
END_TEST

// ----------------------------------------------------------
// 13 STRCSPN
// Вычисляет длину str1, состоящий не из символов str2.

START_TEST(strcspn1) {
  char str1[] = "12345 67890 qwerty";
  char str2[] = "";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn2) {
  char str1[] = "1234567890 qwerty";
  char str2[] = "1";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn3) {
  char str1[] = "123456 7890qwerty";
  char str2[] = "5";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn4) {
  char str1[] = "1234567890q werty";
  char str2[] = "q";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn5) {
  char str1[] = "1234567890qwe rty";
  char str2[] = "5yn";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn6) {
  char str1[] = "1234567 890qwerty";
  char str2[] = "n";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn7) {
  char str1[] = "1234567890 qwerty";
  char str2[] = "9\02";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn8) {
  char str1[] = "1234567890qwerty";
  char str2[] = "9e3\02";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn9) {
  char str1[] = "123456 7890 qwer ty";
  char str2[] = "9e3 \02";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(strcspn10) {
  char str1[] = "123456 7890 qwer ty";
  char str2[] = "y\02";
  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

// ----------------------------------------------------------
// 14 STRERROR
START_TEST(strerror1) {
  for (int i = 0; i < 106; i++) {
    char *res = s21_strerror(i);
    char *orig = strerror(i);
    ck_assert_str_eq(res, orig);
  }
}
END_TEST

// ----------------------------------------------------------
// 15 STRLEN
START_TEST(strlen1) {
  char *str_1 = "hello\0";
  ck_assert_int_eq(strlen(str_1), s21_strlen(str_1));
}
END_TEST

START_TEST(strlen2) {
  char *str_2 = "\0";
  ck_assert_int_eq(strlen(str_2), s21_strlen(str_2));
}
END_TEST

START_TEST(strlen3) {
  char *str_3 = "hello\0hi!";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

START_TEST(strlen4) {
  char *str_3 = "\0hi!";
  ck_assert_int_eq(strlen(str_3), s21_strlen(str_3));
}
END_TEST

// ----------------------------------------------------------
// 16 STRPBRK
// Находит первый символ в str1, который в str2
START_TEST(strpbrk1) {
  char str1[] = "Hello, WorldH";
  char str2[] = "H";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk2) {
  char str1[] = "Hello, Worldllo";
  char str2[] = "llo";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk3) {
  char str1[] = "Hello, World";
  char str2[] = "oe";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk4) {
  char str1[] = "Hello, Hello, Hello\0World";
  char str2[] = "ll";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk5) {
  char str1[] = "Hello, Hello, Hello\0World yes";
  char str2[] = "yes";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk6) {
  char str1[] = "Hello, Hello, Hello\0World yes";
  char str2[] = "\0";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk7) {
  char str1[] = "\0Hello, Hello, HelloWorld yes";
  char str2[] = "\0yes";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk8) {
  char str1[] = "Hello, Hello, HelloWorld yes";
  char str2[] = "yes\0 he";
  ck_assert_pstr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

// ----------------------------------------------------------
// 17 STRECHR
// поиск последнего вхождения символа в строке из str.
START_TEST(strrchr1) {
  char str[] = "Hello, World";
  int c = 'H';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr2) {
  char str[] = "Hello, World";
  int c = 'o';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr3) {
  char str[] = "Hello, World";
  int c = 'x';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr4) {
  char str[] = "qqqqqqqqq";
  int c = 'q';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr5) {
  char str[] = "Hello, \0World";
  int c = 'd';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr6) {
  char str[] = "Hello, \0World";
  int c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr7) {
  char str[] = "\0Hello, \0World";
  int c = '\0';
  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// ----------------------------------------------------------
// 18 STRSPN
// длину начального сегмента str1, который  состоит из str2
START_TEST(strspn1) {
  char str1[] = "1234567890qwerty";
  char str2[] = "";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn2) {
  char str1[] = "1234567890qwerty";
  char str2[] = "4567";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn3) {
  char str1[] = "1234567890qwerty";
  char str2[] = "37q";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn4) {
  char str1[] = "1234 56789 0qwe rty";
  char str2[] = "0q";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn5) {
  char str1[] = "1234 56789 0qwe rty";
  char str2[] = "\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn6) {
  char str1[] = "1234 56\0789 0qwe rty";
  char str2[] = "0q";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn7) {
  char str1[] = "\01234 56789 0qwe rty";
  char str2[] = "\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn8) {
  char str1[] = "1234 56\0789 0qwe rty";
  char str2[] = "\0";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn9) {
  char str1[] = "1234 56\0789 0qwe rty";
  char str2[] = "\056";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

START_TEST(strspn10) {
  char str1[] = "1234 56111\0789 0qwe rty";
  char str2[] = "1\056";
  ck_assert_int_eq(s21_strspn(str1, str2), strspn(str1, str2));
}
END_TEST

// ----------------------------------------------------------
// 19 STRSTR
// первое вхождение всей строки needle которая в строке haystack.
START_TEST(strstr1) {
  char haystack[] = "Hello, World";
  char needle[] = "Hello";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr2) {
  char haystack[] = "Hello, World";
  char needle[] = "";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr3) {
  char haystack[] = "Hello, World";
  char needle[] = "rt";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr4) {
  char haystack[] = "Hello, World";
  char needle[] = ", ";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr5) {
  char haystack[] = "Hello,\0 World";
  char needle[] = "or";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr6) {
  char haystack[] = "Hello,\0 World";
  char needle[] = "r\0l";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr7) {
  char haystack[] = "Hello,\0 World";
  char needle[] = "or\0l";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr8) {
  char haystack[] = "Hello,\0 World";
  char needle[] = "\0";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr9) {
  char haystack[] = "\0 World";
  char needle[] = "\0";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr10) {
  char haystack[] = "\0 World";
  char needle[] = "or";
  ck_assert_pstr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// ----------------------------------------------------------
// 20 STRTOK
START_TEST(strtok1) {
  char str1[] = "str1/str2/str3";
  char str2[] = "str1/str2/str3";
  char delim[] = "/";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok2) {
  char str1[] = "str1/str2/str3/";
  char str2[] = "str1/str2/str3/";
  char delim[] = "/";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok3) {
  char str1[] = "str1/.str2/.str3/";
  char str2[] = "str1/.str2/.str3/";
  char delim[] = "/.";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok4) {
  char str1[] = "str1/.str2/.str3/.";
  char str2[] = "str1/.str2/.str3/.";
  char delim[] = "/.";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok5) {
  char str1[] = "12.,3*45.678*90";
  char str2[] = "12.,3*45.678*90";
  char delim[] = ".,*";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok6) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = ".";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok7) {
  char str1[] = "1 2 3 4 5 6 7 8 9";
  char str2[] = "1 2 3 4 5 6 7 8 9";
  char delim[] = " ";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok8) {
  char str1[] = "1 2 3 4 5 6 7 8 9 ";
  char str2[] = "1 2 3 4 5 6 7 8 9 ";
  char delim[] = " ";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok9) {
  char str1[] = "";
  char str2[] = "";
  char delim[] = ".*r";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok10) {
  char str1[] = "1234r567r890";
  char str2[] = "1234r567r890";
  char delim[] = ".r5";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

START_TEST(strtok11) {
  char str1[] = "1234r567r890";
  char str2[] = "1234r567r890";
  char delim[] = ".r5*";
  char *p1, *p2;
  p1 = strtok(str1, delim);
  p2 = s21_strtok(str2, delim);
  while (p1 != s21_NULL) {
    ck_assert_pstr_eq(p1, p2);
    p1 = strtok(s21_NULL, delim);
    p2 = s21_strtok(s21_NULL, delim);
  }
}
END_TEST

// =====  C#  ========
// 21 --> s21_to_upper

START_TEST(to_upper_t1) {
  char str[] = "";
  char expected[] = "";
  char *upp = s21_to_upper(str);
  ck_assert_pstr_eq(upp, expected);
  if (upp) free(upp);
}
END_TEST

START_TEST(to_upper_t2) {
  char str[] = "project";
  char expected[] = "PROJECT";
  char *upp = s21_to_upper(str);
  ck_assert_pstr_eq(upp, expected);
  if (upp) free(upp);
}
END_TEST

START_TEST(to_upper_t3) {
  char str[] = "Pr1OjE44 +1*cT";
  char expected[] = "PR1OJE44 +1*CT";
  char *upp = s21_to_upper(str);
  ck_assert_pstr_eq(upp, expected);
  if (upp) free(upp);
}

START_TEST(to_upper_t4) {
  char str[] = "pro\0ject";
  char expected[] = "PRO";
  char *upp = s21_to_upper(str);
  ck_assert_pstr_eq(upp, expected);
  if (upp) free(upp);
}
END_TEST

START_TEST(to_upper_t5) {
  char str[] = " ";
  char expected[] = " ";
  char *upp = s21_to_upper(str);
  ck_assert_pstr_eq(upp, expected);
  if (upp) free(upp);
}
END_TEST

// 22 --> s21_to_lower

START_TEST(to_lower_t1) {
  char str[] = "";
  char expected[] = "";
  char *low = s21_to_lower(str);
  ck_assert_pstr_eq(low, expected);
  if (low) free(low);
}
END_TEST

START_TEST(to_lower_t2) {
  char str[] = "PROJECT";
  char expected[] = "project";
  char *low = s21_to_lower(str);
  ck_assert_pstr_eq(low, expected);
  if (low) free(low);
}
END_TEST

START_TEST(to_lower_t3) {
  char str[] = "Pr1OjE44 +1*CT";
  char expected[] = "pr1oje44 +1*ct";
  char *low = s21_to_lower(str);
  ck_assert_pstr_eq(low, expected);
  if (low) free(low);
}
END_TEST

START_TEST(to_lower_t4) {
  char str[] = "PRO\0ject";
  char expected[] = "pro";
  char *low = s21_to_lower(str);
  ck_assert_pstr_eq(low, expected);
  if (low) free(low);
}
END_TEST

START_TEST(to_lower_t5) {
  char str[] = " ";
  char expected[] = " ";
  char *low = s21_to_lower(str);
  ck_assert_pstr_eq(low, expected);
  if (low) free(low);
}
END_TEST

// 23 --> s21_insert

START_TEST(insert_t1) {
  char str[] = "hello";
  char src[] = "_WORLD_";
  s21_size_t index = 2;
  char expected[] = "he_WORLD_llo";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t2) {
  char str[] = "hello";
  char src[] = "_WOR\0LD_";
  s21_size_t index = 2;
  char expected[] = "he_WORllo";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t3) {
  char str[] = "h\0ello";
  char src[] = "_WORLD_";
  s21_size_t index = 2;
  char *expected = NULL;
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t4) {
  char str[] = "hello";
  char src[] = "";
  s21_size_t index = 2;
  char expected[] = "hello";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t5) {
  char str[] = "hello";
  char src[] = "_WORLD_";
  s21_size_t index = 100;
  char *expected = s21_NULL;
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t6) {
  char str[] = "hello";
  char src[] = "_WORLD_";
  s21_size_t index = 0;
  char expected[] = "_WORLD_hello";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t7) {
  char str[] = "";
  char src[] = "_WORLD_";
  s21_size_t index = 0;
  char *expected = "_WORLD_";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

START_TEST(insert_t8) {
  char str[] = "hello";
  char src[] = "WORLD";
  s21_size_t index = 5;
  char *expected = "helloWORLD";
  char *ins = (char *)s21_insert(str, src, index);
  ck_assert_pstr_eq(ins, expected);
  if (ins) free(ins);
}
END_TEST

// 24 --> s21_trim

START_TEST(trim_t1) {
  char str[] = "";
  char trim_ch[] = "";
  char *expected = "";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t2) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *expected = "";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t3) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char *expected = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t4) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *expected = "";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t5) {
  char str[] = "hepllios";
  char trim_ch[] = "\0sip";
  char *expected = "hepllios";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t6) {
  char str[] = "OOLLLOOO";
  char trim_ch[] = "LO";
  char *expected = "";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

START_TEST(trim_t7) {
  char str[] = " WORLD ";
  char trim_ch[] = " 2R2";
  char *expected = "WORLD";
  char *tr = s21_trim(str, trim_ch);
  ck_assert_pstr_eq(tr, expected);
  if (tr) free(tr);
}
END_TEST

Suite *suite_s21_string() {
  Suite *s = suite_create("s21_string");
  TCase *tc = tcase_create("test_string");

  suite_add_tcase(s, tc);
  // 1
  tcase_add_test(tc, memchr1);
  tcase_add_test(tc, memchr2);
  tcase_add_test(tc, memchr3);
  tcase_add_test(tc, memchr4);
  tcase_add_test(tc, memchr5);
  tcase_add_test(tc, memchr6);
  tcase_add_test(tc, memchr7);
  tcase_add_test(tc, memchr8);
  tcase_add_test(tc, memchr9);
  tcase_add_test(tc, memchr10);
  tcase_add_test(tc, memchr11);
  tcase_add_test(tc, memchr12);
  tcase_add_test(tc, memchr13);
  tcase_add_test(tc, memchr14);
  tcase_add_test(tc, memchr15);
  tcase_add_test(tc, memchr16);
  tcase_add_test(tc, memchr17);
  tcase_add_test(tc, memchr18);
  tcase_add_test(tc, memchr19);
  tcase_add_test(tc, memchr20);
  tcase_add_test(tc, memchr21);
  tcase_add_test(tc, memchr22);
  tcase_add_test(tc, memchr23);
  tcase_add_test(tc, memchr24);
  tcase_add_test(tc, memchr25);
  tcase_add_test(tc, memchr26);
  tcase_add_test(tc, memchr27);
  tcase_add_test(tc, memchr28);
  tcase_add_test(tc, memchr29);
  tcase_add_test(tc, memchr30);

  // 2
  tcase_add_test(tc, memcmp1);
  tcase_add_test(tc, memcmp2);
  tcase_add_test(tc, memcmp3);
  tcase_add_test(tc, memcmp4);
  tcase_add_test(tc, memcmp5);
  tcase_add_test(tc, memcmp6);
  tcase_add_test(tc, memcmp7);
  tcase_add_test(tc, memcmp8);
  tcase_add_test(tc, memcmp9);
  // tcase_add_test(tc, memcmp10);

  // 3
  tcase_add_test(tc, memcpy1);
  tcase_add_test(tc, memcpy2);
  tcase_add_test(tc, memcpy3);
  tcase_add_test(tc, memcpy4);
  tcase_add_test(tc, memcpy5);
  tcase_add_test(tc, memcpy6);
  tcase_add_test(tc, memcpy7);
  tcase_add_test(tc, memcpy8);
  tcase_add_test(tc, memcpy9);
  tcase_add_test(tc, memcpy10);
  tcase_add_test(tc, memcpy11);
  tcase_add_test(tc, memcpy12);
  tcase_add_test(tc, memcpy13);
  tcase_add_test(tc, memcpy14);
  tcase_add_test(tc, memcpy15);
  tcase_add_test(tc, memcpy16);
  tcase_add_test(tc, memcpy17);
  tcase_add_test(tc, memcpy18);
  tcase_add_test(tc, memcpy19);
  tcase_add_test(tc, memcpy20);
  tcase_add_test(tc, memcpy21);
  tcase_add_test(tc, memcpy22);
  tcase_add_test(tc, memcpy23);

  // 4
  tcase_add_test(tc, memmove1);
  tcase_add_test(tc, memmove2);
  tcase_add_test(tc, memmove3);
  tcase_add_test(tc, memmove4);
  tcase_add_test(tc, memmove5);
  tcase_add_test(tc, memmove6);
  tcase_add_test(tc, memmove7);
  tcase_add_test(tc, memmove8);
  tcase_add_test(tc, memmove9);
  tcase_add_test(tc, memmove10);
  tcase_add_test(tc, memmove11);
  tcase_add_test(tc, memmove12);
  tcase_add_test(tc, memmove13);
  tcase_add_test(tc, memmove14);
  tcase_add_test(tc, memmove15);
  tcase_add_test(tc, memmove16);
  tcase_add_test(tc, memmove17);

  // 5
  tcase_add_test(tc, memset1);
  tcase_add_test(tc, memset2);
  tcase_add_test(tc, memset3);
  tcase_add_test(tc, memset4);
  tcase_add_test(tc, memset5);
  tcase_add_test(tc, memset6);
  tcase_add_test(tc, memset7);
  tcase_add_test(tc, memset8);
  tcase_add_test(tc, memset9);
  tcase_add_test(tc, memset10);
  tcase_add_test(tc, memset11);
  tcase_add_test(tc, memset12);

  // 6
  tcase_add_test(tc, strcat1);
  tcase_add_test(tc, strcat2);
  tcase_add_test(tc, strcat3);
  tcase_add_test(tc, strcat4);
  tcase_add_test(tc, strcat5);
  tcase_add_test(tc, strcat6);
  tcase_add_test(tc, strcat7);
  tcase_add_test(tc, strcat8);
  tcase_add_test(tc, strcat9);
  tcase_add_test(tc, strcat10);

  // 7
  tcase_add_test(tc, strncat1);
  tcase_add_test(tc, strncat2);
  tcase_add_test(tc, strncat3);
  tcase_add_test(tc, strncat4);
  tcase_add_test(tc, strncat5);
  tcase_add_test(tc, strncat6);
  tcase_add_test(tc, strncat7);
  tcase_add_test(tc, strncat8);
  tcase_add_test(tc, strncat9);
  tcase_add_test(tc, strncat10);
  tcase_add_test(tc, strncat11);
  tcase_add_test(tc, strncat12);
  tcase_add_test(tc, strncat13);

  // 8
  tcase_add_test(tc, strchr1);
  tcase_add_test(tc, strchr2);
  tcase_add_test(tc, strchr3);
  tcase_add_test(tc, strchr4);
  tcase_add_test(tc, strchr5);
  tcase_add_test(tc, strchr6);
  tcase_add_test(tc, strchr7);

  // 9
  tcase_add_test(tc, strcmp1);
  tcase_add_test(tc, strcmp2);
  tcase_add_test(tc, strcmp3);
  tcase_add_test(tc, strcmp4);
  tcase_add_test(tc, strcmp5);
  tcase_add_test(tc, strcmp6);
  tcase_add_test(tc, strcmp7);
  tcase_add_test(tc, strcmp8);

  // 10
  tcase_add_test(tc, strncmp1);
  tcase_add_test(tc, strncmp2);
  tcase_add_test(tc, strncmp3);
  tcase_add_test(tc, strncmp4);
  tcase_add_test(tc, strncmp5);
  tcase_add_test(tc, strncmp6);
  tcase_add_test(tc, strncmp7);
  tcase_add_test(tc, strncmp8);
  tcase_add_test(tc, strncmp9);
  tcase_add_test(tc, strncmp10);
  tcase_add_test(tc, strncmp11);
  tcase_add_test(tc, strncmp12);
  tcase_add_test(tc, strncmp13);
  tcase_add_test(tc, strncmp14);
  tcase_add_test(tc, strncmp15);
  tcase_add_test(tc, strncmp16);
  tcase_add_test(tc, strncmp17);
  tcase_add_test(tc, strncmp18);
  tcase_add_test(tc, strncmp19);
  tcase_add_test(tc, strncmp20);
  tcase_add_test(tc, strncmp21);
  tcase_add_test(tc, strncmp22);
  tcase_add_test(tc, strncmp23);
  tcase_add_test(tc, strncmp24);

  // 11
  tcase_add_test(tc, strcpy1);
  tcase_add_test(tc, strcpy2);
  tcase_add_test(tc, strcpy3);
  tcase_add_test(tc, strcpy4);
  tcase_add_test(tc, strcpy5);
  tcase_add_test(tc, strcpy6);
  tcase_add_test(tc, strcpy7);
  tcase_add_test(tc, strcpy8);
  tcase_add_test(tc, strcpy9);
  tcase_add_test(tc, strcpy10);
  tcase_add_test(tc, strcpy11);
  tcase_add_test(tc, strcpy12);
  tcase_add_test(tc, strcpy13);
  tcase_add_test(tc, strcpy14);
  tcase_add_test(tc, strcpy15);
  tcase_add_test(tc, strcpy16);
  tcase_add_test(tc, strcpy17);

  // 12
  tcase_add_test(tc, strncpy1);
  tcase_add_test(tc, strncpy2);
  tcase_add_test(tc, strncpy3);
  tcase_add_test(tc, strncpy4);
  tcase_add_test(tc, strncpy5);
  tcase_add_test(tc, strncpy6);
  tcase_add_test(tc, strncpy7);
  tcase_add_test(tc, strncpy8);
  tcase_add_test(tc, strncpy9);
  tcase_add_test(tc, strncpy10);
  tcase_add_test(tc, strncpy11);
  tcase_add_test(tc, strncpy12);

  // 13
  tcase_add_test(tc, strcspn1);
  tcase_add_test(tc, strcspn2);
  tcase_add_test(tc, strcspn3);
  tcase_add_test(tc, strcspn4);
  tcase_add_test(tc, strcspn5);
  tcase_add_test(tc, strcspn6);
  tcase_add_test(tc, strcspn7);
  tcase_add_test(tc, strcspn8);
  tcase_add_test(tc, strcspn9);
  tcase_add_test(tc, strcspn10);

  // 14
  tcase_add_test(tc, strerror1);

  // 15
  tcase_add_test(tc, strlen1);
  tcase_add_test(tc, strlen2);
  tcase_add_test(tc, strlen3);
  tcase_add_test(tc, strlen4);

  // 16
  tcase_add_test(tc, strpbrk1);
  tcase_add_test(tc, strpbrk2);
  tcase_add_test(tc, strpbrk3);
  tcase_add_test(tc, strpbrk4);
  tcase_add_test(tc, strpbrk5);
  tcase_add_test(tc, strpbrk6);
  tcase_add_test(tc, strpbrk7);
  tcase_add_test(tc, strpbrk8);

  // 17
  tcase_add_test(tc, strrchr1);
  tcase_add_test(tc, strrchr2);
  tcase_add_test(tc, strrchr3);
  tcase_add_test(tc, strrchr4);
  tcase_add_test(tc, strrchr5);
  tcase_add_test(tc, strrchr6);
  tcase_add_test(tc, strrchr7);

  // 18
  tcase_add_test(tc, strspn1);
  tcase_add_test(tc, strspn2);
  tcase_add_test(tc, strspn3);
  tcase_add_test(tc, strspn4);
  tcase_add_test(tc, strspn5);
  tcase_add_test(tc, strspn6);
  tcase_add_test(tc, strspn7);
  tcase_add_test(tc, strspn8);
  tcase_add_test(tc, strspn9);
  tcase_add_test(tc, strspn10);

  // 19
  tcase_add_test(tc, strstr1);
  tcase_add_test(tc, strstr2);
  tcase_add_test(tc, strstr3);
  tcase_add_test(tc, strstr4);
  tcase_add_test(tc, strstr5);
  tcase_add_test(tc, strstr6);
  tcase_add_test(tc, strstr7);
  tcase_add_test(tc, strstr8);
  tcase_add_test(tc, strstr9);
  tcase_add_test(tc, strstr10);

  // 20
  tcase_add_test(tc, strtok1);
  tcase_add_test(tc, strtok2);
  tcase_add_test(tc, strtok3);
  tcase_add_test(tc, strtok4);
  tcase_add_test(tc, strtok5);
  tcase_add_test(tc, strtok6);
  tcase_add_test(tc, strtok7);
  tcase_add_test(tc, strtok8);
  tcase_add_test(tc, strtok9);
  tcase_add_test(tc, strtok10);
  tcase_add_test(tc, strtok11);
  // 21
  tcase_add_test(tc, to_upper_t1);
  tcase_add_test(tc, to_upper_t2);
  tcase_add_test(tc, to_upper_t3);
  tcase_add_test(tc, to_upper_t4);
  tcase_add_test(tc, to_upper_t5);

  // 22
  tcase_add_test(tc, to_lower_t1);
  tcase_add_test(tc, to_lower_t2);
  tcase_add_test(tc, to_lower_t3);
  tcase_add_test(tc, to_lower_t4);
  tcase_add_test(tc, to_lower_t5);

  // 23
  tcase_add_test(tc, insert_t1);
  tcase_add_test(tc, insert_t2);
  tcase_add_test(tc, insert_t3);
  tcase_add_test(tc, insert_t4);
  tcase_add_test(tc, insert_t5);
  tcase_add_test(tc, insert_t6);
  tcase_add_test(tc, insert_t7);
  tcase_add_test(tc, insert_t8);

  // 24
  tcase_add_test(tc, trim_t1);
  tcase_add_test(tc, trim_t2);
  tcase_add_test(tc, trim_t3);
  tcase_add_test(tc, trim_t4);
  tcase_add_test(tc, trim_t5);
  tcase_add_test(tc, trim_t6);
  tcase_add_test(tc, trim_t7);

  return s;
}
