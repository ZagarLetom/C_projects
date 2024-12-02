#include <check.h>
#include <stdio.h>

#include "s21_matrix.h"

//===================
// S21_CREATE_MATRIX
//===================

START_TEST(s21_create_matrix_01) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(3, 3, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_02) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(1, 2, &A), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_create_matrix_10) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(0, 2, &A), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_11) {
  matrix_t A = {0};
  ck_assert_int_eq(s21_create_matrix(3, -5, &A), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_12) {
  matrix_t *A = NULL;
  ck_assert_int_eq(s21_create_matrix(1, 2, A), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_create_matrix_13) {
  matrix_t *A = NULL;
  ck_assert_int_eq(s21_create_matrix(-6, 0, A), INCORRECT_MATRIX_ERROR);
}
END_TEST

//===============
// S21_EQ_MATRIX
//===============

START_TEST(s21_eq_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(1.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_100) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_eq_matrix(&A, NULL), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_104) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_eq_matrix(NULL, &A), FAILURE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_00) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(2.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_01) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(3, 4, &B);
  s21_init_matrix(1.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_02) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(10.0, &A);

  s21_create_matrix(3, 2, &B);
  s21_init_matrix(-10.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_03) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(3, 3, &B);
  s21_init_matrix(1.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), FAILURE);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_11) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(10, 10, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(10, 10, &B);
  s21_init_matrix(1.0, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//================
// S21_SUM_MATRIX
//================

START_TEST(s21_sum_matrix_2000) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_2001) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(NULL, &A, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_2002) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sum_matrix(&A, NULL, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_0) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(0.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(2.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-3.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(5.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-3.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[0][2] = 6.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 10.0;
  X.matrix[1][1] = 12.0;
  X.matrix[1][2] = 14.0;
  X.matrix[1][3] = 16.0;
  X.matrix[2][0] = 18.0;
  X.matrix[2][1] = 20.0;
  X.matrix[2][2] = 22.0;
  X.matrix[2][3] = 24.0;
  X.matrix[3][0] = 26.0;
  X.matrix[3][1] = 28.0;
  X.matrix[3][2] = 30.0;
  X.matrix[3][3] = 32.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(1.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 8.0;
  X.matrix[2][0] = 10.0;
  X.matrix[2][1] = 12.0;
  X.matrix[3][0] = 14.0;
  X.matrix[3][1] = 16.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);

  s21_sum_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 2.0;
  X.matrix[0][1] = 4.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 8.0;
  X.matrix[2][0] = 10.0;
  X.matrix[2][1] = 12.0;
  X.matrix[3][0] = 14.0;
  X.matrix[3][1] = 16.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);

  ck_assert_int_eq(s21_sum_matrix(NULL, &B, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &Z), CALCULATION_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_8) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_9) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-1.0, &A);
  A.matrix[0][0] = NAN;
  s21_create_matrix(1, 1, &B);

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = INFINITY;

  ck_assert_int_eq(s21_sum_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

//================
// S21_SUB_MATRIX
//================

START_TEST(s21_sub_matrix_2003) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(1, 1, &B);
  B.matrix[0][0] = INFINITY;

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_2004) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-1.0, &A);
  A.matrix[0][0] = INFINITY;
  s21_create_matrix(1, 1, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_2000) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, &B, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_2001) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(NULL, &A, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_2002) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_sub_matrix(&A, NULL, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_0) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[1][2] = 0.0;
  X.matrix[1][3] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[2][2] = 0.0;
  X.matrix[2][3] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;
  X.matrix[3][2] = 0.0;
  X.matrix[3][3] = 0.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_1) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(0.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(2.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -2.0;
  X.matrix[0][1] = -2.0;
  X.matrix[0][2] = -2.0;
  X.matrix[0][3] = -2.0;
  X.matrix[1][0] = -2.0;
  X.matrix[1][1] = -2.0;
  X.matrix[1][2] = -2.0;
  X.matrix[1][3] = -2.0;
  X.matrix[2][0] = -2.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -2.0;
  X.matrix[2][3] = -2.0;
  X.matrix[3][0] = -2.0;
  X.matrix[3][1] = -2.0;
  X.matrix[3][2] = -2.0;
  X.matrix[3][3] = -2.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-3.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(5.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -8.0;
  X.matrix[0][1] = -8.0;
  X.matrix[0][2] = -8.0;
  X.matrix[0][3] = -8.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -8.0;
  X.matrix[1][2] = -8.0;
  X.matrix[1][3] = -8.0;
  X.matrix[2][0] = -8.0;
  X.matrix[2][1] = -8.0;
  X.matrix[2][2] = -8.0;
  X.matrix[2][3] = -8.0;
  X.matrix[3][0] = -8.0;
  X.matrix[3][1] = -8.0;
  X.matrix[3][2] = -8.0;
  X.matrix[3][3] = -8.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-3.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 8.0;
  X.matrix[0][1] = 8.0;
  X.matrix[0][2] = 8.0;
  X.matrix[0][3] = 8.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 8.0;
  X.matrix[1][2] = 8.0;
  X.matrix[1][3] = 8.0;
  X.matrix[2][0] = 8.0;
  X.matrix[2][1] = 8.0;
  X.matrix[2][2] = 8.0;
  X.matrix[2][3] = 8.0;
  X.matrix[3][0] = 8.0;
  X.matrix[3][1] = 8.0;
  X.matrix[3][2] = 8.0;
  X.matrix[3][3] = 8.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(1.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 0.0;
  X.matrix[1][0] = 0.0;
  X.matrix[1][1] = 0.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 0.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 0.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-1.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(3.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -4.0;
  X.matrix[1][0] = -4.0;
  X.matrix[1][1] = -4.0;
  X.matrix[2][0] = -4.0;
  X.matrix[2][1] = -4.0;
  X.matrix[3][0] = -4.0;
  X.matrix[3][1] = -4.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(4.0, &A);

  s21_create_matrix(4, 2, &B);
  s21_init_matrix(-2.0, &B);

  s21_sub_matrix(&A, &B, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 6.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 6.0;
  X.matrix[1][1] = 6.0;
  X.matrix[2][0] = 6.0;
  X.matrix[2][1] = 6.0;
  X.matrix[3][0] = 6.0;
  X.matrix[3][1] = 6.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 2, &A);

  s21_create_matrix(4, 3, &B);

  ck_assert_int_eq(s21_sub_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_sub_matrix_8) {
  ck_assert_int_eq(s21_sub_matrix(NULL, NULL, NULL), INCORRECT_MATRIX_ERROR);
}
END_TEST

//=================
// S21_MULT_NUMBER
//=================

START_TEST(s21_mult_number_10) {
  double number = 3.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);

  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 3.0;
  X.matrix[0][1] = 6.0;
  X.matrix[0][2] = 9.0;
  X.matrix[0][3] = 12.0;
  X.matrix[1][0] = 15.0;
  X.matrix[1][1] = 18.0;
  X.matrix[1][2] = 21.0;
  X.matrix[1][3] = 24.0;
  X.matrix[2][0] = 27.0;
  X.matrix[2][1] = 30.0;
  X.matrix[2][2] = 33.0;
  X.matrix[2][3] = 36.0;
  X.matrix[3][0] = 39.0;
  X.matrix[3][1] = 42.0;
  X.matrix[3][2] = 45.0;
  X.matrix[3][3] = 48.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_11) {
  double number = 5.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 5.0;
  X.matrix[0][1] = 10.0;
  X.matrix[0][2] = 15.0;
  X.matrix[0][3] = 20.0;
  X.matrix[1][0] = 25.0;
  X.matrix[1][1] = 30.0;
  X.matrix[1][2] = 35.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 45.0;
  X.matrix[2][1] = 50.0;
  X.matrix[2][2] = 55.0;
  X.matrix[2][3] = 60.0;
  X.matrix[3][0] = 65.0;
  X.matrix[3][1] = 70.0;
  X.matrix[3][2] = 75.0;
  X.matrix[3][3] = 80.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_12) {
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = 4.0;
  X.matrix[0][1] = 6.0;
  X.matrix[1][0] = 8.0;
  X.matrix[1][1] = 10.0;
  X.matrix[2][0] = 12.0;
  X.matrix[2][1] = 14.0;
  X.matrix[3][0] = 16.0;
  X.matrix[3][1] = 18.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_13) {
  double number = -2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(4, 2, &X);

  X.matrix[0][0] = -4.0;
  X.matrix[0][1] = -6.0;
  X.matrix[1][0] = -8.0;
  X.matrix[1][1] = -10.0;
  X.matrix[2][0] = -12.0;
  X.matrix[2][1] = -14.0;
  X.matrix[3][0] = -16.0;
  X.matrix[3][1] = -18.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_14) {
  double number = 2.0;
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(2.0, &A);

  s21_mult_number(&A, number, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = 4.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_15) {
  double number = 2.0;
  matrix_t Z = {0};

  ck_assert_int_eq(s21_mult_number(NULL, number, &Z), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_mult_number_7) {
  double number = NAN;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);

  ck_assert_int_eq(s21_mult_number(&A, number, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_8) {
  double number = 7.62;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);

  ck_assert_int_eq(s21_mult_number(&A, number, NULL), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_9) {
  double number = INFINITY;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);

  ck_assert_int_eq(s21_mult_number(&A, number, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_100) {
  double number = 100;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][1] = NAN;
  ck_assert_int_eq(s21_mult_number(&A, number, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_number_101) {
  double number = 101;
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][1] = INFINITY;
  ck_assert_int_eq(s21_mult_number(&A, number, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

//=================
// S21_MULT_MATRIX
//=================

START_TEST(s21_mult_matrix_10) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 90.0;
  X.matrix[0][1] = 100.0;
  X.matrix[0][2] = 110.0;
  X.matrix[0][3] = 120.0;
  X.matrix[1][0] = 202.0;
  X.matrix[1][1] = 228.0;
  X.matrix[1][2] = 254.0;
  X.matrix[1][3] = 280.0;
  X.matrix[2][0] = 314.0;
  X.matrix[2][1] = 356.0;
  X.matrix[2][2] = 398.0;
  X.matrix[2][3] = 440.0;
  X.matrix[3][0] = 426.0;
  X.matrix[3][1] = 484.0;
  X.matrix[3][2] = 542.0;
  X.matrix[3][3] = 600.0;

  ck_assert_int_eq(s21_eq_matrix(&Z, &X), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_11) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(-5.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 30.0;
  X.matrix[0][1] = 40.0;
  X.matrix[0][2] = 50.0;
  X.matrix[0][3] = 60.0;
  X.matrix[1][0] = 46.0;
  X.matrix[1][1] = 72.0;
  X.matrix[1][2] = 98.0;
  X.matrix[1][3] = 124.0;
  X.matrix[2][0] = 62.0;
  X.matrix[2][1] = 104.0;
  X.matrix[2][2] = 146.0;
  X.matrix[2][3] = 188.0;
  X.matrix[3][0] = 78.0;
  X.matrix[3][1] = 136.0;
  X.matrix[3][2] = 194.0;
  X.matrix[3][3] = 252.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_12) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(4, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -78.0;
  X.matrix[0][1] = -92.0;
  X.matrix[0][2] = -106.0;
  X.matrix[0][3] = -120.0;
  X.matrix[1][0] = 34.0;
  X.matrix[1][1] = 36.0;
  X.matrix[1][2] = 38.0;
  X.matrix[1][3] = 40.0;
  X.matrix[2][0] = 146.0;
  X.matrix[2][1] = 164.0;
  X.matrix[2][2] = 182.0;
  X.matrix[2][3] = 200.0;
  X.matrix[3][0] = 258.0;
  X.matrix[3][1] = 292.0;
  X.matrix[3][2] = 326.0;
  X.matrix[3][3] = 360.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_13) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 2, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 4, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -25.0;
  X.matrix[0][1] = -34.0;
  X.matrix[0][2] = -43.0;
  X.matrix[0][3] = -52.0;
  X.matrix[1][0] = -13.0;
  X.matrix[1][1] = -18.0;
  X.matrix[1][2] = -23.0;
  X.matrix[1][3] = -28.0;
  X.matrix[2][0] = -1.0;
  X.matrix[2][1] = -2.0;
  X.matrix[2][2] = -3.0;
  X.matrix[2][3] = -4.0;
  X.matrix[3][0] = 11.0;
  X.matrix[3][1] = 14.0;
  X.matrix[3][2] = 17.0;
  X.matrix[3][3] = 20.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_14) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(1, 1, &B);
  s21_init_matrix(1.0, &B);

  s21_mult_matrix(&A, &B, &Z);

  s21_create_matrix(1, 1, &X);

  X.matrix[0][0] = -5.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_102) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  ck_assert_int_eq(s21_mult_matrix(&A, &B, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_mult_matrix_103) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_mult_matrix(&A, NULL, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_104) {
  matrix_t A = {0}, B = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_mult_matrix(NULL, &A, &B), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_matrix_20) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);

  ck_assert_int_eq(s21_mult_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_100) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_mult_matrix_101) {
  matrix_t A = {0};
  matrix_t B = {0};
  matrix_t Z = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(-5.0, &A);

  s21_create_matrix(2, 2, &B);
  s21_init_matrix(1.0, &B);
  B.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&Z);
}
END_TEST

//===============
// S21_TRANSPOSE
//===============

START_TEST(s21_transpose_00) {
  matrix_t A = {0};

  ck_assert_int_eq(s21_transpose(&A, &A), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_01) {
  matrix_t A = {0};
  matrix_t B = {0};

  s21_create_matrix(3, 4, &A);
  s21_init_matrix(1.0, &A);

  s21_transpose(&A, &B);

  ck_assert_int_eq(s21_eq_matrix(&A, &B), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_transpose_10) {
  matrix_t A = {0};
  matrix_t T = {0};
  matrix_t B = {0};

  s21_create_matrix(2, 3, &A);
  s21_init_matrix(1.0, &A);
  s21_create_matrix(3, 2, &B);
  B.matrix[0][0] = 1.0;
  B.matrix[0][1] = 4.0;
  B.matrix[1][0] = 2.0;
  B.matrix[1][1] = 5.0;
  B.matrix[2][0] = 3.0;
  B.matrix[2][1] = 6.0;

  s21_transpose(&A, &T);

  ck_assert_int_eq(s21_eq_matrix(&T, &B), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&T);
}
END_TEST

START_TEST(s21_transpose_101) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_transpose(&A, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_102) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_transpose(NULL, &A), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

//=================
// S21_DETERMINANT
//=================

START_TEST(s21_determinant_1) {
  double determ = 0.0;
  ck_assert_int_eq(s21_determinant(NULL, &determ), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_determinant_100) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_determinant(&A, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_104) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1 + i * A.columns + j;
    }
  }
  A.matrix[2][3] = 0;
  A.matrix[3][3] = 0;
  double dtrm = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &dtrm), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_105) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 1 + i * A.columns + j;
    }
  }
  A.matrix[2][4] = 0;
  A.matrix[3][4] = 0;
  double dtrm = 0.0;
  ck_assert_int_eq(s21_determinant(&A, &dtrm), OK);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_2) {
  double determ = 0.0;
  matrix_t A = {0};
  s21_create_matrix(1, 2, &A);

  ck_assert_int_eq(s21_determinant(&A, &determ), CALCULATION_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_3) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  s21_init_matrix(1.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 1.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_4) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 4000.87;
  A.matrix[0][1] = 454.0;
  A.matrix[0][2] = 4.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = 1.897;
  A.matrix[1][2] = 3.0;
  A.matrix[2][0] = 0.000087;
  A.matrix[2][1] = 2.5668;
  A.matrix[2][2] = 1.0;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -24105.996724156);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_5) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(2, 2, &A);
  A.matrix[0][0] = -677700.0;
  A.matrix[0][1] = 654.0;
  A.matrix[1][0] = 2.0;
  A.matrix[1][1] = -0.00001;

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, -1301.223);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_6) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(8, 8, &A);
  s21_init_matrix(2.0, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_7) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);

  s21_determinant(&A, &determ);
  ck_assert_double_eq(determ, 0.0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_eq_rows) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 10;
  A.matrix[0][1] = 11;
  A.matrix[0][2] = 12;

  A.matrix[1][0] = 678;
  A.matrix[1][1] = 679.9;
  A.matrix[1][2] = 680;

  A.matrix[2][0] = 30;
  A.matrix[2][1] = 33.9;
  A.matrix[2][2] = 36;
  s21_determinant(&A, &determ);
  ck_assert_double_eq_tol(determ, 1202.4, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_not_eq_rows) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 10;
  A.matrix[0][1] = 11;
  A.matrix[0][2] = 12;

  A.matrix[1][0] = 678;
  A.matrix[1][1] = 679.000000009;
  A.matrix[1][2] = 680;

  A.matrix[2][0] = 30;
  A.matrix[2][1] = 33.000000009;
  A.matrix[2][2] = 36;
  s21_determinant(&A, &determ);
  ck_assert_double_eq_tol(determ, 0., ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_eq_columns) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 10;
  A.matrix[0][1] = 25;
  A.matrix[0][2] = 37;

  A.matrix[1][0] = 9;
  A.matrix[1][1] = 30.0000000001;
  A.matrix[1][2] = 39;

  A.matrix[2][0] = 8;
  A.matrix[2][1] = 35;
  A.matrix[2][2] = 41;
  s21_determinant(&A, &determ);
  ck_assert_ldouble_eq_tol(determ, 0.0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_not_eq_columns) {
  double determ = 0.0;
  matrix_t A = {0};

  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 10;
  A.matrix[0][1] = 25;
  A.matrix[0][2] = 37;

  A.matrix[1][0] = 9;
  A.matrix[1][1] = 30.0000001;
  A.matrix[1][2] = 39;

  A.matrix[2][0] = 8;
  A.matrix[2][1] = 35;
  A.matrix[2][2] = 41.0000001;

  s21_determinant(&A, &determ);
  ck_assert_ldouble_eq_tol(determ, 1.89e-05, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_normal_calc) {
  matrix_t A = {0};
  s21_create_matrix(10, 10, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j;
      switch ((i * A.columns + j) % 3) {
        case 0:
          A.matrix[i][j] = A.matrix[i][j] * 3;
          break;
        case 1:
          A.matrix[i][j] = A.matrix[i][j] * 2;
          break;
        default:
          A.matrix[i][j] = 1 / A.matrix[i][j];
          break;
      }
    }
  }
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("\t%10lf", A.matrix[i][j]);
    }
    printf("\n");
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  printf("\n\t\t\t\t\t\t\t%.10lf\n\t", determ);
  for (int i = 0; i < 154; i++) {
    printf("=");
  }
  printf("\n");
  ck_assert_double_eq_tol(determ, -1206.1766003, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_zero_row) {
  matrix_t A = {0};
  s21_create_matrix(10, 10, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j;
      switch ((i * A.columns + j) % 3) {
        case 0:
          A.matrix[i][j] = A.matrix[i][j] * 3;
          break;
        case 1:
          A.matrix[i][j] = A.matrix[i][j] * 2;
          break;
        default:
          A.matrix[i][j] = 1 / A.matrix[i][j];
          break;
      }
    }
  }
  for (int c = 0; c < A.columns; c++) {
    A.matrix[6][c] = 0;
  }
  for (int i = 0; i < A.rows; i++) {
    if (i == 6) {
      printf("\n→");
    }
    for (int j = 0; j < A.columns; j++) {
      printf("\t%10lf", A.matrix[i][j]);
    }
    if (i == 6) {
      printf("\n");
    }
    printf("\n");
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  printf("\n\t\t\t\t\t\t\t  %lf\n", determ);
  printf("\t ");
  for (int i = 0; i < 153; i++) {
    printf("=");
  }
  printf("\n");
  ck_assert_double_eq_tol(determ, 0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_zero_columns) {
  matrix_t A = {0};
  s21_create_matrix(10, 10, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = i * A.columns + j;
      switch ((i * A.columns + j) % 3) {
        case 0:
          A.matrix[i][j] = A.matrix[i][j] * 3;
          break;
        case 1:
          A.matrix[i][j] = A.matrix[i][j] * 2;
          break;
        default:
          A.matrix[i][j] = 1 / A.matrix[i][j];
          break;
      }
    }
  }
  for (int r = 0; r < A.rows; r++) {
    A.matrix[r][6] = 0;
  }
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("\t%10lf", A.matrix[i][j]);
    }
    printf("\n");
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  printf("\n\t\t\t\t\t\t\t  %lf\t\t\t\t\t\t↑\n", determ);
  printf("\t ");
  for (int i = 0; i < 153; i++) {
    printf("=");
  }
  printf("\n");
  ck_assert_double_eq_tol(determ, 0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_is_sequential_by_row) {
  matrix_t A = {0};
  s21_create_matrix(10, 10, &A);
  int number = 1;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = number + (0.0023003 * number) + i * i;
      number++;
    }
  }
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("\t%10lf", A.matrix[i][j]);
    }
    printf("\n");
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  printf("\n\t\t\t\t\t\t\t  %lf\n", determ);
  ck_assert_double_eq_tol(determ, 0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_is_sequential_by_column) {
  matrix_t A = {0};
  s21_create_matrix(10, 10, &A);
  int number = 1;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = number + (0.0023003 * number) + j * j;
      number++;
    }
  }
  printf("\t ");
  for (int i = 0; i < 153; i++) {
    printf("=");
  }
  printf("\n");
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      printf("\t%10lf", A.matrix[i][j]);
    }
    printf("\n");
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  printf("\n\t\t\t\t\t\t\t  %lf\n", determ);
  ck_assert_double_eq_tol(determ, 0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_determinant_10_10_is_sequential_2000) {
  matrix_t A = {0};
  s21_create_matrix(5, 5, &A);
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      A.matrix[i][j] = 8;
    }
  }
  double determ = 0.0;
  s21_determinant(&A, &determ);
  ck_assert_double_eq_tol(determ, 0, ERROR_RATE);
  s21_remove_matrix(&A);
}
END_TEST

//======================
// S21_CALC_COMPLEMENTS
//======================

START_TEST(s21_calc_complements_1) {
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 112.0;
  A.matrix[0][1] = 243.0;
  A.matrix[0][2] = 3.0;
  A.matrix[0][3] = -8.0;
  A.matrix[1][0] = 47.0;
  A.matrix[1][1] = 51.0;
  A.matrix[1][2] = -66.0;
  A.matrix[1][3] = 99.0;
  A.matrix[2][0] = -74.0;
  A.matrix[2][1] = 85.0;
  A.matrix[2][2] = 97.0;
  A.matrix[2][3] = 63.0;
  A.matrix[3][0] = -13.0;
  A.matrix[3][1] = 79.0;
  A.matrix[3][2] = -99.0;
  A.matrix[3][3] = -121.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = -2879514.0;
  X.matrix[0][1] = -1236631.0;
  X.matrix[0][2] = -1685096.0;
  X.matrix[0][3] = 880697.0;
  X.matrix[1][0] = 1162090.0;
  X.matrix[1][1] = -714015.0;
  X.matrix[1][2] = 4046255.0;
  X.matrix[1][3] = -3901600.0;
  X.matrix[2][0] = 4362897.0;
  X.matrix[2][1] = -2049432.0;
  X.matrix[2][2] = -532912.0;
  X.matrix[2][3] = -1370781.0;
  X.matrix[3][0] = 3412773.0;
  X.matrix[3][1] = -1569493.0;
  X.matrix[3][2] = 3144517.0;
  X.matrix[3][3] = 1284666.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_calc_complements(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = -30.0;
  X.matrix[0][2] = -108.0;
  X.matrix[0][3] = 106.0;
  X.matrix[1][0] = 138.0;
  X.matrix[1][1] = -726.0;
  X.matrix[1][2] = -1137.0;
  X.matrix[1][3] = 1061.0;
  X.matrix[2][0] = 0.0;
  X.matrix[2][1] = 12.0;
  X.matrix[2][2] = 57.0;
  X.matrix[2][3] = -47.0;
  X.matrix[3][0] = 0.0;
  X.matrix[3][1] = 6.0;
  X.matrix[3][2] = -75.0;
  X.matrix[3][3] = 57.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(4, 3, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;

  ck_assert_int_eq(s21_calc_complements(&A, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_100) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(&A, NULL), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_104) {
  matrix_t A = {0};
  s21_create_matrix(3, 3, &A);
  ck_assert_int_eq(s21_calc_complements(NULL, &A), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_calc_complements_5) {
  matrix_t A, B, X;
  ck_assert_int_eq(s21_create_matrix(1, 1, &A), 0);
  ck_assert_int_eq(s21_create_matrix(1, 1, &X), 0);

  A.matrix[0][0] = -64;

  X.matrix[0][0] = -64;

  ck_assert_int_eq(s21_calc_complements(&A, &B), 0);
  ck_assert_int_eq(s21_eq_matrix(&B, &X), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&X);
}
END_TEST

//====================
// S21_INVERSE_MATRIX
//====================

START_TEST(s21_inverse_matrix_1) {
  matrix_t A = {0};
  matrix_t Z = {0};
  matrix_t X = {0};

  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = -1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 7.0;
  A.matrix[0][3] = 9.0;
  A.matrix[1][0] = 1.0;
  A.matrix[1][1] = 0.0;
  A.matrix[1][2] = 0.0;
  A.matrix[1][3] = 0.0;
  A.matrix[2][0] = 47.0;
  A.matrix[2][1] = 13.0;
  A.matrix[2][2] = 17.0;
  A.matrix[2][3] = 21.0;
  A.matrix[3][0] = 22.0;
  A.matrix[3][1] = 7.0;
  A.matrix[3][2] = 1.0;
  A.matrix[3][3] = 3.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(4, 4, &X);

  X.matrix[0][0] = 0.0;
  X.matrix[0][1] = 1.0;
  X.matrix[0][2] = 0.0;
  X.matrix[0][3] = 0.0;
  X.matrix[1][0] = -5.0 / 23.0;
  X.matrix[1][1] = -121.0 / 23.0;
  X.matrix[1][2] = 2.0 / 23.0;
  X.matrix[1][3] = 1.0 / 23.0;
  X.matrix[2][0] = -18.0 / 23.0;
  X.matrix[2][1] = -379.0 / 46.0;
  X.matrix[2][2] = 19.0 / 46.0;
  X.matrix[2][3] = -25.0 / 46.0;
  X.matrix[3][0] = 53.0 / 69.0;
  X.matrix[3][1] = 1061.0 / 138.0;
  X.matrix[3][2] = -47.0 / 138.0;
  X.matrix[3][3] = 19.0 / 46.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  ck_assert_int_eq(s21_inverse_matrix(&A, &Z), OK);

  s21_remove_matrix(&A);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_2000) {
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  ck_assert_int_eq(s21_inverse_matrix(&A, NULL), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_2001) {
  matrix_t A = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 2;

  ck_assert_int_eq(s21_inverse_matrix(NULL, &A), INCORRECT_MATRIX_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_2002) {
  matrix_t A = {0}, F = {0};
  s21_create_matrix(1, 1, &A);
  A.rows = -1;
  ck_assert_int_eq(s21_inverse_matrix(&A, &F), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_2003) {
  matrix_t A = {0}, F = {0};
  s21_create_matrix(1, 1, &A);
  A.columns = -1;
  ck_assert_int_eq(s21_inverse_matrix(&A, &F), INCORRECT_MATRIX_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_2004) {
  matrix_t A = {0}, F = {0};
  A.rows = 1;
  A.columns = 1;
  A.matrix = NULL;
  ck_assert_int_eq(s21_inverse_matrix(&A, &F), INCORRECT_MATRIX_ERROR);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 2, &A);
  s21_init_matrix(1.0, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_5) {
  matrix_t A = {0};
  matrix_t Z = {0};

  s21_create_matrix(3, 3, &A);
  s21_init_matrix(1.0, &A);

  ck_assert_int_eq(s21_inverse_matrix(&A, &Z), CALCULATION_ERROR);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_inverse_matrix_6) {
  matrix_t A = {0}, Z = {0}, X = {0};

  s21_create_matrix(3, 3, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;

  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  A.matrix[2][0] = 8.0;
  A.matrix[2][1] = 6.0;
  A.matrix[2][2] = 9.0;

  s21_inverse_matrix(&A, &Z);

  s21_create_matrix(3, 3, &X);

  X.matrix[0][0] = -3.0 / 5.0;
  X.matrix[0][1] = 0.0;
  X.matrix[0][2] = 1.0 / 5.0;

  X.matrix[1][0] = -4.0 / 5.0;
  X.matrix[1][1] = 1.0;
  X.matrix[1][2] = -2.0 / 5.0;

  X.matrix[2][0] = 16.0 / 15.0;
  X.matrix[2][1] = -2.0 / 3.0;
  X.matrix[2][2] = 1.0 / 5.0;

  ck_assert_int_eq(s21_eq_matrix(&X, &Z), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&X);
  s21_remove_matrix(&Z);
}
END_TEST

START_TEST(s21_inverse_matrix_7) {
  ck_assert_int_eq(s21_inverse_matrix(NULL, NULL), INCORRECT_MATRIX_ERROR);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Alles_suite");
  TCase *tc_core = tcase_create("Alles_case");
  SRunner *sr = srunner_create(s1);
  int nf;

  tcase_add_test(tc_core, s21_create_matrix_01);
  tcase_add_test(tc_core, s21_create_matrix_02);
  tcase_add_test(tc_core, s21_create_matrix_10);
  tcase_add_test(tc_core, s21_create_matrix_11);
  tcase_add_test(tc_core, s21_create_matrix_12);
  tcase_add_test(tc_core, s21_create_matrix_13);

  tcase_add_test(tc_core, s21_eq_matrix_10);
  tcase_add_test(tc_core, s21_eq_matrix_00);
  tcase_add_test(tc_core, s21_eq_matrix_01);
  tcase_add_test(tc_core, s21_eq_matrix_02);
  tcase_add_test(tc_core, s21_eq_matrix_03);
  tcase_add_test(tc_core, s21_eq_matrix_11);
  tcase_add_test(tc_core, s21_eq_matrix_100);
  tcase_add_test(tc_core, s21_eq_matrix_104);

  tcase_add_test(tc_core, s21_sum_matrix_2000);
  tcase_add_test(tc_core, s21_sum_matrix_2001);
  tcase_add_test(tc_core, s21_sum_matrix_2002);
  tcase_add_test(tc_core, s21_sum_matrix_0);
  tcase_add_test(tc_core, s21_sum_matrix_1);
  tcase_add_test(tc_core, s21_sum_matrix_2);
  tcase_add_test(tc_core, s21_sum_matrix_3);
  tcase_add_test(tc_core, s21_sum_matrix_4);
  tcase_add_test(tc_core, s21_sum_matrix_5);
  tcase_add_test(tc_core, s21_sum_matrix_6);
  tcase_add_test(tc_core, s21_sum_matrix_7);
  tcase_add_test(tc_core, s21_sum_matrix_8);
  tcase_add_test(tc_core, s21_sum_matrix_9);
  tcase_add_test(tc_core, s21_sum_matrix_10);

  tcase_add_test(tc_core, s21_sub_matrix_2000);
  tcase_add_test(tc_core, s21_sub_matrix_2001);
  tcase_add_test(tc_core, s21_sub_matrix_2002);
  tcase_add_test(tc_core, s21_sub_matrix_2003);
  tcase_add_test(tc_core, s21_sub_matrix_2004);
  tcase_add_test(tc_core, s21_sub_matrix_0);
  tcase_add_test(tc_core, s21_sub_matrix_1);
  tcase_add_test(tc_core, s21_sub_matrix_2);
  tcase_add_test(tc_core, s21_sub_matrix_3);
  tcase_add_test(tc_core, s21_sub_matrix_4);
  tcase_add_test(tc_core, s21_sub_matrix_5);
  tcase_add_test(tc_core, s21_sub_matrix_6);
  tcase_add_test(tc_core, s21_sub_matrix_7);
  tcase_add_test(tc_core, s21_sub_matrix_8);

  tcase_add_test(tc_core, s21_mult_number_10);
  tcase_add_test(tc_core, s21_mult_number_11);
  tcase_add_test(tc_core, s21_mult_number_12);
  tcase_add_test(tc_core, s21_mult_number_13);
  tcase_add_test(tc_core, s21_mult_number_14);
  tcase_add_test(tc_core, s21_mult_number_15);
  tcase_add_test(tc_core, s21_mult_number_7);
  tcase_add_test(tc_core, s21_mult_number_8);
  tcase_add_test(tc_core, s21_mult_number_9);
  tcase_add_test(tc_core, s21_mult_number_100);
  tcase_add_test(tc_core, s21_mult_number_101);

  tcase_add_test(tc_core, s21_mult_matrix_10);
  tcase_add_test(tc_core, s21_mult_matrix_11);
  tcase_add_test(tc_core, s21_mult_matrix_12);
  tcase_add_test(tc_core, s21_mult_matrix_13);
  tcase_add_test(tc_core, s21_mult_matrix_14);
  tcase_add_test(tc_core, s21_mult_matrix_20);
  tcase_add_test(tc_core, s21_mult_matrix_100);
  tcase_add_test(tc_core, s21_mult_matrix_101);
  tcase_add_test(tc_core, s21_mult_matrix_102);
  tcase_add_test(tc_core, s21_mult_matrix_103);
  tcase_add_test(tc_core, s21_mult_matrix_104);

  tcase_add_test(tc_core, s21_transpose_00);
  tcase_add_test(tc_core, s21_transpose_01);
  tcase_add_test(tc_core, s21_transpose_10);
  tcase_add_test(tc_core, s21_transpose_101);
  tcase_add_test(tc_core, s21_transpose_102);

  tcase_add_test(tc_core, s21_determinant_1);
  tcase_add_test(tc_core, s21_determinant_2);
  tcase_add_test(tc_core, s21_determinant_3);
  tcase_add_test(tc_core, s21_determinant_4);
  tcase_add_test(tc_core, s21_determinant_5);
  tcase_add_test(tc_core, s21_determinant_6);
  tcase_add_test(tc_core, s21_determinant_7);
  tcase_add_test(tc_core, s21_determinant_100);
  tcase_add_test(tc_core, s21_determinant_104);
  tcase_add_test(tc_core, s21_determinant_105);
  tcase_add_test(tc_core, s21_determinant_eq_rows);
  tcase_add_test(tc_core, s21_determinant_not_eq_rows);
  tcase_add_test(tc_core, s21_determinant_eq_columns);
  tcase_add_test(tc_core, s21_determinant_not_eq_columns);
  tcase_add_test(tc_core, s21_determinant_10_10_normal_calc);
  tcase_add_test(tc_core, s21_determinant_10_10_zero_row);
  tcase_add_test(tc_core, s21_determinant_10_10_zero_columns);
  tcase_add_test(tc_core, s21_determinant_10_10_is_sequential_by_row);
  tcase_add_test(tc_core, s21_determinant_10_10_is_sequential_by_column);
  tcase_add_test(tc_core, s21_determinant_10_10_is_sequential_2000);

  tcase_add_test(tc_core, s21_calc_complements_1);
  tcase_add_test(tc_core, s21_calc_complements_2);
  tcase_add_test(tc_core, s21_calc_complements_3);
  tcase_add_test(tc_core, s21_calc_complements_100);
  tcase_add_test(tc_core, s21_calc_complements_104);
  tcase_add_test(tc_core, s21_calc_complements_5);

  tcase_add_test(tc_core, s21_inverse_matrix_1);
  tcase_add_test(tc_core, s21_inverse_matrix_2);
  tcase_add_test(tc_core, s21_inverse_matrix_3);
  tcase_add_test(tc_core, s21_inverse_matrix_4);
  tcase_add_test(tc_core, s21_inverse_matrix_5);
  tcase_add_test(tc_core, s21_inverse_matrix_6);
  tcase_add_test(tc_core, s21_inverse_matrix_7);
  tcase_add_test(tc_core, s21_inverse_matrix_2000);
  tcase_add_test(tc_core, s21_inverse_matrix_2001);
  tcase_add_test(tc_core, s21_inverse_matrix_2002);
  tcase_add_test(tc_core, s21_inverse_matrix_2003);
  tcase_add_test(tc_core, s21_inverse_matrix_2004);

  suite_add_tcase(s1, tc_core);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf ? 1 : 0;
}