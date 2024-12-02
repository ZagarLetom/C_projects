#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  // проверка входных значений

  result->rows = rows;
  result->columns = columns;

  // выделяем память под строки (записи)
  result->matrix = (double **)calloc(rows, sizeof(double *));

  // выделяем память в строках под столбцы (колонки)
  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  if (mat_is_correct(A) == OK) {
    for (int i = 0; i < A->rows; i++) free(A->matrix[i]);
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (mat_is_correct(A) || mat_is_correct(B) || mat_sizes_eq(A, B)) {
    return FAILURE;
  }
  int equal = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double diff = A->matrix[i][j] - B->matrix[i][j];
      diff = (diff < 0) ? diff * -1 : diff;
      if (diff > ERROR_RATE) {
        equal = FAILURE;
        i = A->rows;
        j = A->columns;
      }
    }
  }
  return equal;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (mat_is_correct(A) || mat_is_correct(B) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (mat_sizes_eq(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (mat_is_correct(A) || mat_is_correct(B) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (mat_sizes_eq(A, B) || inf_or_nan(A) || inf_or_nan(B)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (mat_is_correct(A) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (inf_or_nan(A) || isinf(number) || isnan(number)) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (mat_is_correct(A) || mat_is_correct(B) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (inf_or_nan(A) || inf_or_nan(B) || A->columns != B->rows) {
    return CALCULATION_ERROR;
  }
  s21_create_matrix(A->rows, B->columns, result);
  for (int m = 0; m < result->rows; m++) {
    for (int n = 0; n < result->columns; n++) {
      for (int k = 0; k < B->rows; k++) {
        result->matrix[m][n] += A->matrix[m][k] * B->matrix[k][n];
      }
    }
  }
  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (mat_is_correct(A) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return OK;
}

//др. название -"союзная матрица"
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (mat_is_correct(A) || result == NULL) return INCORRECT_MATRIX_ERROR;
  if (mat_is_quadrate(A) != OK) return CALCULATION_ERROR;
  s21_create_matrix(A->rows, A->columns, result);
  if (A->rows > 1) {
    calc_comp_more_than_1(A, result);
  } else {
    result->matrix[0][0] = A->matrix[0][0];
  }
  return OK;
}

void calc_comp_more_than_1(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      calc_comp_main(i, j, A, result);
    }
  }
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      if (((i % 2 == 0) && (j % 2 != 0)) || ((i % 2 != 0) && (j % 2 == 0))) {
        result->matrix[i][j] *= -1;
      }
    }
  }
}

void calc_comp_main(int i, int j, matrix_t *A, matrix_t *result) {
  //создаём временную матрицу для записи в неё значений для поиска определителя
  matrix_t buffer;
  int size = A->rows - 1;
  s21_create_matrix(size, size, &buffer);

  //переписываем из исходной матрицы только "невычеркнутые" значения
  //в одномерный массив
  double line[size * size];
  int g = 0;
  for (int r = 0; r < A->rows; r++) {
    for (int c = 0; c < A->columns; c++) {
      if (r != i && c != j) {
        line[g] = A->matrix[r][c];
        g++;
      }
    }
  }

  //из одномерного массива переписываем найденные значения
  //во временную матрицу для вычисления определителя
  g = 0;
  for (int r = 0; r < buffer.rows; r++) {
    for (int c = 0; c < buffer.columns; c++) {
      buffer.matrix[r][c] = line[g];
      g++;
    }
  }

  //находим определитель временной матрицы
  double buff_num;
  s21_determinant(&buffer, &buff_num);
  s21_remove_matrix(&buffer);
  result->matrix[i][j] = buff_num;
}

int s21_determinant(matrix_t *A, double *result) {
  if (mat_is_correct(A) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (mat_is_quadrate(A) != OK) {
    return CALCULATION_ERROR;
  }
  *result = 0;
  // checking for zero rows, zero columns, and proportional rows or columns
  if (fd_the_zero_row(A) && fd_the_zero_col(A) && fd_matrix_is_sequential(A)) {
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    }
    if (A->rows > 1) {
      determinant_main(A, result);
    }
  }
  return OK;
}

void determinant_main(matrix_t *A, double *result) {
  // searching for a row with the maximum number of zeros
  int max_zero_in_row = 0, this_row_i = 0;
  search_zero_row(A, &max_zero_in_row, &this_row_i);

  // searching for a column with the maximum number of zeros
  int max_zero_in_columns = 0, this_columns_j = 0;
  search_zero_columns(A, &max_zero_in_columns, &this_columns_j);

  // the choice of how to reveal the determinant
  if (max_zero_in_row >= max_zero_in_columns) {
    reveal_by_row(A, &this_row_i, result);
  } else {
    reveal_by_column(A, &this_columns_j, result);
  }
}

void search_zero_row(matrix_t *A, int *zero_counter, int *her_index) {
  for (int i = 0; i < A->rows; i++) {
    int zero_in_row = 0;
    for (int j = 0; j < A->columns; j++) {
      if (A->matrix[i][j] == 0) {
        zero_in_row++;
      }
    }
    if (zero_in_row > *zero_counter) {
      *zero_counter = zero_in_row;
      *her_index = i;
    }
  }
}

void search_zero_columns(matrix_t *A, int *zero_counter, int *his_index) {
  for (int j = 0; j < A->columns; j++) {
    int zero_in_columns = 0;
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i][j] == 0) {
        zero_in_columns++;
      }
    }
    if (zero_in_columns > *zero_counter) {
      *zero_counter = zero_in_columns;
      *his_index = j;
    }
  }
}

void reveal_by_row(matrix_t *A, int *this_row_i, double *result) {
  double sign = (*this_row_i % 2 == 0) ? 1. : -1.;
  for (int j = 0; j < A->columns; j++) {
    if (A->matrix[*this_row_i][j] != 0) {
      matrix_t buffer_matrix = {0};
      int size = A->rows - 1;
      s21_create_matrix(size, size, &buffer_matrix);
      // rewrite needed matrix
      double *buffer_line = (double *)calloc(size * size, sizeof(double));
      int buff_line_i = 0;
      for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->columns; c++) {
          if (r != *this_row_i && c != j) {
            buffer_line[buff_line_i] = A->matrix[r][c];
            buff_line_i++;
          }
        }
      }
      rewrite_buffer_line_to_matrix(buffer_line, &buffer_matrix);
      free(buffer_line);
      // making a decision loop
      double buffer_dtrm = 0.;
      s21_determinant(&buffer_matrix, &buffer_dtrm);
      s21_remove_matrix(&buffer_matrix);
      *result += sign * A->matrix[*this_row_i][j] * buffer_dtrm;
    }
    sign *= -1.;
  }
}

void reveal_by_column(matrix_t *A, int *this_columns_j, double *result) {
  double sign = (*this_columns_j % 2 == 0) ? 1. : -1.;
  for (int i = 0; i < A->rows; i++) {
    if (A->matrix[i][*this_columns_j] != 0) {
      matrix_t buffer_matrix = {0};
      int size = A->rows - 1;
      s21_create_matrix(size, size, &buffer_matrix);
      // rewrite needed matrix
      double *buffer_line = (double *)calloc(size * size, sizeof(double));
      int buff_line_i = 0;
      for (int r = 0; r < A->rows; r++) {
        for (int c = 0; c < A->columns; c++) {
          if (c != *this_columns_j && r != i) {
            buffer_line[buff_line_i] = A->matrix[r][c];
            buff_line_i++;
          }
        }
      }
      rewrite_buffer_line_to_matrix(buffer_line, &buffer_matrix);
      free(buffer_line);
      double buffer_dtrm = 0.;
      s21_determinant(&buffer_matrix, &buffer_dtrm);
      s21_remove_matrix(&buffer_matrix);
      *result += sign * A->matrix[i][*this_columns_j] * buffer_dtrm;
    }
    sign *= -1.;
  }
}

void rewrite_buffer_line_to_matrix(double *buffer_line, matrix_t *A) {
  int buff_line_i = 0;
  for (int r = 0; r < A->rows; r++) {
    for (int c = 0; c < A->columns; c++) {
      A->matrix[r][c] = buffer_line[buff_line_i];
      buff_line_i++;
    }
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (mat_is_correct(A) || result == NULL) {
    return INCORRECT_MATRIX_ERROR;
  }
  if (mat_is_quadrate(A) != OK || det_matrix_is_zero(A) != OK) {
    return CALCULATION_ERROR;
  }
  if (A->rows > 1) {
    matrix_t buffer;
    s21_calc_complements(A, &buffer);
    s21_transpose(&buffer, result);
    s21_remove_matrix(&buffer);
    dividing_elements_by_dtrm(A, result);
  } else {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1 / A->matrix[0][0];
  }
  return OK;
}

void dividing_elements_by_dtrm(matrix_t *A, matrix_t *result) {
  double dtrm = 0;
  s21_determinant(A, &dtrm);
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] /= dtrm;
    }
  }
}

int det_matrix_is_zero(matrix_t *A) {
  int is_zero = OK;
  double dtrm = 0, diff = 0;
  s21_determinant(A, &dtrm);
  diff -= dtrm;
  diff = (diff < 0) ? diff * -1 : diff;
  if (diff < ERROR_RATE) {
    is_zero = CALCULATION_ERROR;
  }
  return is_zero;
}

int mat_is_correct(matrix_t *A) {
  return (A == NULL) ? 1
                     : (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL);
}

int mat_is_quadrate(matrix_t *A) {
  return (A->rows == A->columns) ? OK : INCORRECT_MATRIX_ERROR;
}

int mat_sizes_eq(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && B->columns == A->columns)
             ? OK
             : INCORRECT_MATRIX_ERROR;
}

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x++) {
    for (int y = 0; y < A->columns; y++) {
      A->matrix[x][y] = number++;
    }
  }
}

int inf_or_nan(matrix_t *A) {
  int res = OK;
  for (int r = 0; r < A->rows; r++) {
    for (int c = 0; c < A->columns; c++) {
      if (isnan(A->matrix[r][c]) || isinf(A->matrix[r][c])) {
        res = CALCULATION_ERROR;
        r = A->rows;
        c = A->columns;
      }
    }
  }
  return res;
}

int fd_the_zero_row(matrix_t *A) {
  int check = 1;
  for (int r = 0; r < A->rows && check; r++) {
    if (A->matrix[r][0] == 0.) {
      int c = 1;
      while (c < A->columns && A->matrix[r][c] == A->matrix[r][c - 1]) {
        c++;
      }
      if (c == A->columns) {
        check = 0;
      }
    }
  }
  return check;
}

int fd_the_zero_col(matrix_t *A) {
  int check = 1;
  for (int c = 0; c < A->columns && check; c++) {
    if (A->matrix[0][c] == 0.) {
      int r = 1;
      while (r < A->rows && A->matrix[r][c] == A->matrix[r - 1][c]) {
        r++;
      }
      if (r == A->rows) {
        check = 0;
      }
    }
  }
  return check;
}

int fd_matrix_is_sequential(matrix_t *A) {
  return (A->rows > 2)
             ? (check_sequential_rows(A) && check_sequential_columns(A))
             : 1;
}

int check_sequential_rows(matrix_t *A) {
  int sequential = 1;
  for (int r = 0; r < A->columns && sequential; r++) {
    double diff = A->matrix[r][0] - A->matrix[r][1];
    for (int c = 2; c < A->columns && sequential; c++) {
      double buff_diff = A->matrix[r][c - 1] - A->matrix[r][c];
      if (fabs(diff - buff_diff) > ERROR_RATE) {
        sequential = 0;
      }
    }
  }
  return !sequential;
}

int check_sequential_columns(matrix_t *A) {
  int sequential = 1;
  for (int c = 0; c < A->columns && sequential; c++) {
    double diff = A->matrix[0][c] - A->matrix[1][c];
    for (int r = 2; r < A->columns && sequential; r++) {
      double buff_diff = A->matrix[r - 1][c] - A->matrix[r][c];
      if (fabs(diff - buff_diff) > ERROR_RATE) {
        sequential = 0;
      }
    }
  }
  return !sequential;
}
