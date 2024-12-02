#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#define SUCCESS 1
#define FAILURE 0

#define ERROR_RATE 1e-7

#include <math.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum { OK, INCORRECT_MATRIX_ERROR, CALCULATION_ERROR };

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

int mat_sizes_eq(matrix_t *A, matrix_t *B);
int mat_is_quadrate(matrix_t *A);
int mat_is_correct(matrix_t *A);
void s21_init_matrix(double number, matrix_t *A);
int inf_or_nan(matrix_t *A);
int det_matrix_is_zero(matrix_t *A);
void dividing_elements_by_dtrm(matrix_t *A, matrix_t *result);

void calc_comp_more_than_1(matrix_t *A, matrix_t *result);
void calc_comp_main(int i, int j, matrix_t *A, matrix_t *result);

// all functions related to the determinant
// checkouts
//  helpfull func -for determinant- //fd
int fd_the_zero_row(matrix_t *A);
int fd_the_zero_col(matrix_t *A);
int fd_matrix_is_sequential(matrix_t *A);
// this is part of the "fd_matrix_is_sequential" function
int check_sequential_rows(matrix_t *A);
int check_sequential_columns(matrix_t *A);
// the main calculation algorithm
void determinant_main(matrix_t *A, double *result);
// these are its constituent parts
void search_zero_row(matrix_t *A, int *zero_counter, int *her_index);
void search_zero_columns(matrix_t *A, int *zero_counter, int *his_index);
void reveal_by_row(matrix_t *A, int *this_row_i, double *result);
void reveal_by_column(matrix_t *A, int *this_columns_j, double *result);
void rewrite_buffer_line_to_matrix(double *buffer_line, matrix_t *A);

#endif