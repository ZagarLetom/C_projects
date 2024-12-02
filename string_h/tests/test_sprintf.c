#include "unit.h"

START_TEST(sprintf0_1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "INT_short: short = '%hd' norm = '%d' long = '%ld'";
  int16_t arg = 32767;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf0_2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "INT: short = '%hd' norm = '%d' long = '%ld'";
  int arg = 2147483647;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf0_3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "INT_long: short = '%hd' norm = '%d' long = '%ld'";
  int64_t arg = 9223372036854775807;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// unsigned short: От 0 до 65 535
// unsigned: От 0 до 4 294 967 295
// unsigned long long:	От 0 до 18 446 744 073 709 551 615
// ============================= unsigned =====================================
START_TEST(sprintf0_4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "unsigned: short = '%hu' norm = '%u' long = '%lu'";
  u_int16_t arg = 65535;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf0_5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "unsigned: short = '%hu' norm = '%u' long = '%lu'";
  unsigned long arg = 4294967295;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf0_6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "unsigned: short = '%hu' norm = '%u' long = '%lu'";
  unsigned long arg = 1844674407;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}

// float short: 3,4E +/- 38 (7 знаков)
// double: 1,7E +/- 308 (15 знаков)
// long double:	double
// =========================== float ===================================
START_TEST(sprintf0_7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "float: short = '%hf' norm = '%f' long = '%lf'";
  float arg =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf0_8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "float: short = '%hf' norm = '%f' long = '%lf'";
  double arg =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf0_9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "float: short = '%hf' norm = '%f' long = '%lf'";
  long double arg =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg, arg, arg),
                   sprintf(str2, format, arg, arg, arg));
  ck_assert_str_eq(str1, str2);
}

// %[флаги][ширина][.точность][длина]спецификатор
// =============================== int ======================================
// -
START_TEST(sprintf1) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%-1.1d' two = '%-1.1d' three = '%-1.1d' four = '%-1.1d'\t5 "
      "= '%-.1d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%-15.15d' two = '%-15.15d' three = '%-15.15d' four = "
      "'%-15.15d'\t5 "
      "= '%-.15d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// +
START_TEST(sprintf3) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%+1.1d' two = '%+1.1d' three = '%+1.1d' four = '%+1.1d'\t5 "
      "= '%+.1d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%+15.5d' two = '%+15.5d' three = '%+15.5d' four = "
      "'%+15.5d'\t5 = '%+.5d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ' '
START_TEST(sprintf5) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '% 1.1d' two = '% 1.1d' three = '% 1.1d' four = '%1.1d'\t5 = "
      "'% .1d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf6) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '% 15.5d' two = '% 15.5d' three = '% 15.5d' four = "
      "'%15.5d'\t5 = '% .5d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// 0
START_TEST(sprintf7) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%01.1d' two = '%01.1d' three = '%01.1d' four = '%01.1d'\t5 "
      "= '%0.0d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%015.5d' two = '%015.5d' three = '%015.5d' four = "
      "'%015.5d'\t5 = '%0.5d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// *
START_TEST(sprintf9) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "INT: one = '%*.*d' ";
  int arg1 = 2147483647;
  int x1 = 1;
  int x2 = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, x1, x2, arg1),
                   sprintf(str2, format, x1, x2, arg1));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// all
START_TEST(sprintf10) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "INT: one = '%0-+# 15.5d' two = '%+-# 015.5d' three = '%+ -#015.5d' four "
      "= '%+- #015.5d'\t5 = '%+-#0 .5d'";
  int arg1 = 1;
  int arg2 = 2147483647;
  int arg3 = -1;
  int arg4 = -2147483648;
  int arg5 = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5),
                   sprintf(str2, format, arg1, arg2, arg3, arg4, arg5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// =================================== float
// ========================================
START_TEST(sprintf11) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+1.1f' 2 = '%-1.1f' 3 = '%01.1f' 4 = '% 1.1f' 5 = '%#1.1f' "
      "6 = '%1.1f'";
  double arg1 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  double arg2 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  double arg3 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  double arg4 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  double arg5 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  double arg6 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf12) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+1.1f' 2 = '%-1.1f' 3 = '%01.1f' 4 = '% 1.1f' 5 = '%#1.1f' "
      "6 = '%1.1f'";
  long double arg1 = 1.0;
  long double arg2 = 1.0;
  long double arg3 = 1.0;
  long double arg4 = 1.0;
  long double arg5 = 1.0;
  long double arg6 = 1.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf13) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+1.1f' 2 = '%-1.1f' 3 = '%01.1f' 4 = '% 1.1f' 5 = '%#1.1f' "
      "6 = '%1.1f'";
  long double arg1 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf14) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+30.30f' 2 = '%-30.30f' 3 = '%030.30f' 4 = '% 30.30f' 5 = "
      "'%#30.30f' 6 = '%30.30f'";
  long double arg1 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf15) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+30.30f' 2 = '%-30.30f' 3 = '%030.30f' 4 = '% 30.30f' 5 = "
      "'%#30.30f' 6 = '%30.30f'";
  float arg1 = 1.0;
  float arg2 = 1.0;
  float arg3 = 1.0;
  float arg4 = 1.0;
  float arg5 = 1.0;
  float arg6 = 1.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf16) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+30.30llf' 2 = '%-30.30llf' 3 = '%030.30llf' 4 = '% "
      "30.30llf' 5 = '%#30.30llf' 6 = '%30.30llf'";
  long double arg1 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf17) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%Lf' 2 = '%Lf' 3 = '%Lf' 4 = '%Lf' 5 = '%Lf' 6 = '%Lf'";
  long double arg1 = 1.;
  long double arg2 = -1.;
  long double arg3 = 0;
  long double arg4 = -0;
  long double arg5 = +0;
  long double arg6 = 0.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf18) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%.Lf' 2 = '%.Lf' 3 = '%.Lf' 4 = '%.Lf' 5 = '%.Lf' 6 = "
      "'%.Lf'";
  long double arg1 = 1.;
  long double arg2 = -1.;
  long double arg3 = 0;
  long double arg4 = -0;
  long double arg5 = +0;
  long double arg6 = 0.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}

START_TEST(sprintf19) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+- .Lf' 2 = '%# -+.0Lf' 3 = '%-5Lf' 4 = '%+1.9Lf' 5 = "
      "'%-10.2Lf' 6 = '%05.1Lf'";
  long double arg1 = 1.;
  long double arg2 = -1.;
  long double arg3 = 0.2;
  long double arg4 = -0.1;
  long double arg5 = +0.1;
  long double arg6 = 1.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf20) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ===================================== eE
// ========================================
START_TEST(sprintf21) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+- .Le' 2 = '%# -+.0Le' 3 = '%-5Le' 4 = '%+1.9Le' 5 = "
      "'%-10.2Le' 6 = '% 05.1Le'";
  long double arg1 = 1.;
  long double arg2 = -1.;
  long double arg3 = 0.2;
  long double arg4 = -0.1;
  long double arg5 = +0.1;
  long double arg6 = 1.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf22) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+- .Le' 2 = '%# -+.0Le' 3 = '%-5Le' 4 = '% +1.9Le' 5 = "
      "'%-10.2Le' 6 = '% 05.1Le'";
  long double arg1 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      -123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf23) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%+-5.Le' 2 = '%# -+.0Le' 3 = '%-5Le' 4 = '% +1.9Le' 5 = "
      "'%-10.2Le' 6 = '% 05.1Le'";
  long double arg1 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf24) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%Le' 2 = '%#.2Le' 3 = '%+10Le' 4 = '%-11.9Le' 5 = '% "
      "10.5Le' 6 = '%05.9Le'";
  long double arg1 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf25) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%Le' 2 = '%#1.2Le' 3 = '%+1Le' 4 = '%-1.9Le' 5 = '% 1.2Le' "
      "6 = '%01.1Le'";
  long double arg1 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg2 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg3 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg4 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg5 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  long double arg6 =
      123456789012345678901234567890123456789.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf26) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%Le' 2 = '%#1.2Le' 3 = '%+1Le' 4 = '%-1.9Le' 5 = '% 1.2Le' "
      "6 = '%01.1Le'";
  long double arg1 = 0.123456789012345678901234567890123456789;
  long double arg2 = 0.123456789012345678901234567890123456789;
  long double arg3 = 0.123456789012345678901234567890123456789;
  long double arg4 = 0.123456789012345678901234567890123456789;
  long double arg5 = 0.123456789012345678901234567890123456789;
  long double arg6 = 0.123456789012345678901234567890123456789;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}
START_TEST(sprintf27) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format =
      "float: 1 = '%Le' 2 = '%#1.2Le' 3 = '%+1Le' 4 = '%-1.9Le' 5 = '% 1.2Le' "
      "6 = '%01.1Le'";
  long double arg1 = 123456789012345678901234567890123456789.0;
  long double arg2 = 123456789012345678901234567890123456789.0;
  long double arg3 = 123456789012345678901234567890123456789.0;
  long double arg4 = 123456789012345678901234567890123456789.0;
  long double arg5 = 123456789012345678901234567890123456789.0;
  long double arg6 = 123456789012345678901234567890123456789.0;
  ck_assert_int_eq(
      s21_sprintf(str1, format, arg1, arg2, arg3, arg4, arg5, arg6),
      sprintf(str2, format, arg1, arg2, arg3, arg4, arg5, arg6));
  ck_assert_str_eq(str1, str2);
}

// =================================== unsigned
// ========================================
START_TEST(sprintf30) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%u %u %u";
  unsigned int arg1 = 123;
  unsigned int arg2 = -123;
  unsigned int arg3 = +123;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf31) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %1u %1u %1u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf32) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %3.5u %3.5u %3.5u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf33) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %15u %15u %15u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf34) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %+15u %+15u %+15u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf35) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %-15u %-15u %-15u    ";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf36) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015u %015u %015u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf37) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %15u % 15u % +-15u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf38) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#015u   %#15u %#15u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf39) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#05.4u %#15.7u %#-15.7u";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// =================================== p
// ========================================
START_TEST(sprintf45) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

// START_TEST(sprintf46) {
//     char str1[BUFF_SIZE];
//     char str2[BUFF_SIZE];
//     char *format = "%p";
//     char *ptr = NULL;
//     ck_assert_int_eq(s21_sprintf(str1, format, ptr), sprintf(str2, format,
//     ptr)); ck_assert_str_eq(str1, str2);
// } END_TEST

START_TEST(sprintf47) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%10.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf48) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%+- 0#10.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ================================ string =====================================
START_TEST(sprintf50) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %s is %s %s string %s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  ck_assert_int_eq(s21_sprintf(str1, format, s1, s2, s3, s4),
                   sprintf(str2, format, s1, s2, s3, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf51) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %1.10s is %1.10s %10.1s string %10.0s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  ck_assert_int_eq(s21_sprintf(str1, format, s1, s2, s3, s4),
                   sprintf(str2, format, s1, s2, s3, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf52) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %-1.10s is %-1.10s %-10.1s string %-10.0s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  ck_assert_int_eq(s21_sprintf(str1, format, s1, s2, s3, s4),
                   sprintf(str2, format, s1, s2, s3, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf53) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %+1.10s is %+1.10s %+10.1s string %+10.0s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  ck_assert_int_eq(s21_sprintf(str1, format, s1, s2, s3, s4),
                   sprintf(str2, format, s1, s2, s3, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf54) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %*.*s is %+*.*s %-*.*s string %*.*s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  int x1 = 1;
  int x2 = 1;
  ck_assert_int_eq(
      s21_sprintf(str1, format, x1, x2, s1, x1, x2, s2, x1, x2, s3, x1, x2, s4),
      sprintf(str2, format, x1, x2, s1, x1, x2, s2, x1, x2, s3, x1, x2, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf55) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "This %*.*s is %+*.*s %-*.*s string %*.*s";
  char *s1 = "";
  char *s2 = "21";
  char *s3 = "simple";
  char *s4 = "! ok?";
  int x1 = 15;
  int x2 = 15;
  ck_assert_int_eq(
      s21_sprintf(str1, format, x1, x2, s1, x1, x2, s2, x1, x2, s3, x1, x2, s4),
      sprintf(str2, format, x1, x2, s1, x1, x2, s2, x1, x2, s3, x1, x2, s4));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ================================ hex ======================================
START_TEST(sprintf60) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%x %x %x";
  unsigned int arg1 = 123;
  unsigned int arg2 = -123;
  unsigned int arg3 = +123;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf61) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %1x %1x %1x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf62) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %3.5x %3.5x %3.5x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf63) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %15x %15x %15x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf64) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %+15x %+15x %+15x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf65) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %-15x %-15x %-15x   ";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf66) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%015x %015x %015x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf67) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " %15lx % 15lx % +-15lx";
  unsigned long arg1 = 123456789;
  unsigned long arg2 = -123456789;
  unsigned long arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf68) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#015x   %#15x %#15x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf69) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#05.4x %#15.7x %#-15.7x";
  unsigned int arg1 = 123456789;
  unsigned int arg2 = -123456789;
  unsigned int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf70) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%#05.4hx %#15.7hx %#-15.7hx";
  long int arg1 = 123456789;
  long int arg2 = -123456789;
  long int arg3 = +123456789;
  ck_assert_int_eq(s21_sprintf(str1, format, arg1, arg2, arg3),
                   sprintf(str2, format, arg1, arg2, arg3));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf71) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ================================ c ======================================
START_TEST(sprintf80) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%c%c%c%c%c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'c', 'a', 'b', 'b', 't'),
                   sprintf(str2, format, 'c', 'a', 'b', 'b', 't'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf81) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = "%c %c %c %c %c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'c', 'a', 'b', 'b', 't'),
                   sprintf(str2, format, 'c', 'a', 'b', 'b', 't'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf82) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " hello %5c %-5c %+5c % 5c %05c";
  ck_assert_int_eq(s21_sprintf(str1, format, 'c', 'a', 'b', 'b', 't'),
                   sprintf(str2, format, 'c', 'a', 'b', 'b', 't'));
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(sprintf83) {
  char str1[BUFF_SIZE];
  char str2[BUFF_SIZE];
  char *format = " hello %5.2c %-5.3c %+5.2c %#5.2c %05.5c mom";
  ck_assert_int_eq(s21_sprintf(str1, format, 'c', 'a', 'b', 'b', 't'),
                   sprintf(str2, format, 'c', 'a', 'b', 'b', 't'));
  ck_assert_str_eq(str1, str2);
}
END_TEST

// ========================= f ================================
START_TEST(s21_sprintf_f_test) {
  char str[80];
  char str_orig[80];

  double b = 1;
  int res_1 = s21_sprintf(str, "%.f", b);
  int res_1_orig = sprintf(str_orig, "%.f", b);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.00000002345;
  int res_2 = s21_sprintf(str, "%+-10.3f", b_2);
  int res_2_orig = sprintf(str_orig, "%+-10.3f", b_2);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  long double b_3 = -23.087654;
  int res_3 = s21_sprintf(str, "%20.10Lf", b_3);
  int res_3_orig = sprintf(str_orig, "%20.10Lf", b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  double b_4 = 0;
  int res_4 = s21_sprintf(str, "%0+.15F", b_4);
  int res_4_orig = sprintf(str_orig, "%0+.15F", b_4);

  ck_assert_int_eq(res_4, res_4_orig);
  ck_assert_str_eq(str, str_orig);

  long double b_5 = 0;
  int res_5 = s21_sprintf(str, "%#.0Lf", b_5);
  int res_5_orig = sprintf(str_orig, "%#.0Lf", b_5);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  //   double b_6 = 1.0 / 0.0;

  //   int res_6 = s21_sprintf(str, "%#10.0f", b_6);
  //   int res_6_orig = sprintf(str_orig, "%#10.0f", b_6);

  //   ck_assert_int_eq(res_6, res_6_orig);
  //   ck_assert_str_eq(str, str_orig);

  double b_7 = 1234523459.123456789;
  int res_7 = s21_sprintf(str, "%.5f", b_7);
  int res_7_orig = sprintf(str_orig, "%.5f", b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_8 = 1;
  int res_8 = s21_sprintf(str, "%f", b_8);
  int res_8_orig = sprintf(str_orig, "%f", b_8);

  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_9 = 0.00345;
  int res_9 = s21_sprintf(str, "%f", b_9);
  int res_9_orig = sprintf(str_orig, "%f", b_9);

  ck_assert_int_eq(res_9, res_9_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 0.00345;
  int res_10 = s21_sprintf(str, "%f", b_10);
  int res_10_orig = sprintf(str_orig, "%f", b_10);

  ck_assert_int_eq(res_10, res_10_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 1234567.0034598765432987654321;
  int res_11 = s21_sprintf(str, "%.20f", b_11);
  int res_11_orig = sprintf(str_orig, "%.20f", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

START_TEST(s21_sprintf_g_test) {
  char str[80];
  char str_orig[80];

  double b_1 = -22.25600;
  int res_1 = s21_sprintf(str, "%+-10.3G", b_1);
  int res_1_orig = sprintf(str_orig, "%+-10.3G", b_1);

  ck_assert_int_eq(res_1, res_1_orig);
  ck_assert_str_eq(str, str_orig);

  double b_2 = 0.00000000000001;
  int res_2 = s21_sprintf(str, "%#G", b_2);
  int res_2_orig = sprintf(str_orig, "%#G", b_2);

  ck_assert_int_eq(res_2, res_2_orig);
  ck_assert_str_eq(str, str_orig);

  int a = 10;
  long double b_3 = 1234567.2345678;
  int res_3 = s21_sprintf(str, "%+30.*Lg", a, b_3);
  int res_3_orig = sprintf(str_orig, "%+30.*Lg", a, b_3);

  ck_assert_int_eq(res_3, res_3_orig);
  ck_assert_str_eq(str, str_orig);

  // int width = 10, precision = 2;
  // double b_4 = 0;
  // int res_4 = s21_sprintf(str, "%-#*.*g", width, precision, b_4);
  // int res_4_orig = sprintf(str_orig, "%-#*.*g", width, precision, b_4);

  // ck_assert_int_eq(res_4, res_4_orig);
  // ck_assert_str_eq(str, str_orig);

  double b_5 = -0.000000654;
  int res_5 = s21_sprintf(str, "%+-25g", b_5);
  int res_5_orig = sprintf(str_orig, "%+-25g", b_5);

  ck_assert_int_eq(res_5, res_5_orig);
  ck_assert_str_eq(str, str_orig);

  double b_6 = 320.0;
  int res_6 = s21_sprintf(str, "%+-25g%g", b_5, b_6);
  int res_6_orig = sprintf(str_orig, "%+-25g%g", b_5, b_6);

  ck_assert_int_eq(res_6, res_6_orig);
  ck_assert_str_eq(str, str_orig);

  double b_7 = -120.0001;
  int res_7 = s21_sprintf(str, "TESTS%# 20.3G ARE %+.5f BITCH", b_7, b_7);
  int res_7_orig = sprintf(str_orig, "TESTS%# 20.3G ARE %+.5f BITCH", b_7, b_7);

  ck_assert_int_eq(res_7, res_7_orig);
  ck_assert_str_eq(str, str_orig);

  double b_10 = 5.0, b_8 = 0.0000000012345, b_9 = 1.0;
  int res_8 = s21_sprintf(str, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  int res_8_orig = sprintf(str_orig, "%-20G %010.5g %+Fhello", b_8, b_9, b_10);
  ck_assert_int_eq(res_8, res_8_orig);
  ck_assert_str_eq(str, str_orig);

  double b_11 = 0.001;
  int res_11 = s21_sprintf(str, "%0.g", b_11);
  int res_11_orig = sprintf(str_orig, "%0.g", b_11);

  ck_assert_int_eq(res_11, res_11_orig);
  ck_assert_str_eq(str, str_orig);

  double b_12 = 21222212222.111000;
  int res_12 = s21_sprintf(str, "%.10g", b_12);
  int res_12_orig = sprintf(str_orig, "%.10g", b_12);

  ck_assert_int_eq(res_12, res_12_orig);
  ck_assert_str_eq(str, str_orig);

  double b_13 = 123.321;
  int res_13 = s21_sprintf(str, "%#g", b_13);
  int res_13_orig = sprintf(str_orig, "%#g", b_13);

  ck_assert_int_eq(res_13, res_13_orig);
  ck_assert_str_eq(str, str_orig);

  double b_14 = 555.111;
  int res_14 = s21_sprintf(str, "%-+#.10g", b_14);
  int res_14_orig = sprintf(str_orig, "%-+#.10g", b_14);

  ck_assert_int_eq(res_14, res_14_orig);
  ck_assert_str_eq(str, str_orig);

  double b_15 = 5.00000001;
  int res_15 = s21_sprintf(str, "%e", b_15);
  int res_15_orig = sprintf(str_orig, "%e", b_15);

  ck_assert_int_eq(res_15, res_15_orig);
  ck_assert_str_eq(str, str_orig);

  double b_16 = 8.11222;
  int res_16 = s21_sprintf(str, "%-+#.10e", b_16);
  int res_16_orig = sprintf(str_orig, "%-+#.10e", b_16);

  ck_assert_int_eq(res_16, res_16_orig);
  ck_assert_str_eq(str, str_orig);
}
END_TEST

Suite *suite_s21_sprintf(void) {
  Suite *s = suite_create("s21_sprintf");
  TCase *tc = tcase_create("s21_sprintf");

  suite_add_tcase(s, tc);

  // size
  tcase_add_test(tc, sprintf0_1);
  tcase_add_test(tc, sprintf0_2);
  tcase_add_test(tc, sprintf0_3);
  tcase_add_test(tc, sprintf0_4);
  tcase_add_test(tc, sprintf0_5);
  tcase_add_test(tc, sprintf0_6);
  tcase_add_test(tc, sprintf0_7);
  tcase_add_test(tc, sprintf0_8);
  tcase_add_test(tc, sprintf0_9);

  // int
  tcase_add_test(tc, sprintf1);
  tcase_add_test(tc, sprintf2);
  tcase_add_test(tc, sprintf3);
  tcase_add_test(tc, sprintf4);
  tcase_add_test(tc, sprintf5);
  tcase_add_test(tc, sprintf6);
  tcase_add_test(tc, sprintf7);
  tcase_add_test(tc, sprintf8);
  tcase_add_test(tc, sprintf9);
  tcase_add_test(tc, sprintf9);
  tcase_add_test(tc, sprintf10);

  // float
  tcase_add_test(tc, sprintf11);
  tcase_add_test(tc, sprintf12);
  tcase_add_test(tc, sprintf13);
  tcase_add_test(tc, sprintf14);
  tcase_add_test(tc, sprintf15);
  tcase_add_test(tc, sprintf16);
  tcase_add_test(tc, sprintf17);
  tcase_add_test(tc, sprintf18);
  tcase_add_test(tc, sprintf19);
  tcase_add_test(tc, sprintf20);

  // eE
  tcase_add_test(tc, sprintf21);
  tcase_add_test(tc, sprintf22);
  tcase_add_test(tc, sprintf23);
  tcase_add_test(tc, sprintf24);
  tcase_add_test(tc, sprintf25);
  tcase_add_test(tc, sprintf26);
  tcase_add_test(tc, sprintf27);

  // unsigned
  tcase_add_test(tc, sprintf30);
  tcase_add_test(tc, sprintf31);
  tcase_add_test(tc, sprintf32);
  tcase_add_test(tc, sprintf33);
  tcase_add_test(tc, sprintf34);
  tcase_add_test(tc, sprintf35);
  tcase_add_test(tc, sprintf36);
  tcase_add_test(tc, sprintf37);
  tcase_add_test(tc, sprintf38);
  tcase_add_test(tc, sprintf39);

  // p
  tcase_add_test(tc, sprintf45);
  // tcase_add_test(tc, sprintf46);
  tcase_add_test(tc, sprintf47);
  tcase_add_test(tc, sprintf48);

  // string
  tcase_add_test(tc, sprintf50);
  tcase_add_test(tc, sprintf51);
  tcase_add_test(tc, sprintf52);
  tcase_add_test(tc, sprintf53);
  tcase_add_test(tc, sprintf54);
  tcase_add_test(tc, sprintf55);
  // tcase_add_test(tc, sprintf56);

  // hex
  tcase_add_test(tc, sprintf60);
  tcase_add_test(tc, sprintf61);
  tcase_add_test(tc, sprintf62);
  tcase_add_test(tc, sprintf63);
  tcase_add_test(tc, sprintf64);
  tcase_add_test(tc, sprintf65);
  tcase_add_test(tc, sprintf66);
  tcase_add_test(tc, sprintf67);
  tcase_add_test(tc, sprintf68);
  tcase_add_test(tc, sprintf69);
  tcase_add_test(tc, sprintf70);
  tcase_add_test(tc, sprintf71);

  // c
  tcase_add_test(tc, sprintf80);
  tcase_add_test(tc, sprintf81);
  tcase_add_test(tc, sprintf82);
  tcase_add_test(tc, sprintf83);

  // f
  tcase_add_test(tc, s21_sprintf_f_test);
  tcase_add_test(tc, s21_sprintf_g_test);

  return s;
}
