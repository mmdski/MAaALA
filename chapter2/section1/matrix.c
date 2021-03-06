#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

Matrix
matrix_new(size_t n_rows, size_t n_cols) {

  if (n_rows == 0 || n_cols == 0)
    return NULL;

  Matrix m;
  m = malloc(sizeof(*m) + sizeof(double) * n_rows * n_cols);
  if (!m)
    return NULL;
  m->n_rows = n_rows;
  m->n_cols = n_cols;

  return m;
}

Matrix
matrix_new_like(Matrix m) {

  if (!m)
    return NULL;

  Matrix like_m = matrix_new(m->n_rows, m->n_cols);
  return like_m;
}

Matrix
matrix_ones(size_t n_rows, size_t n_cols) {

  Matrix m;
  if ((m = matrix_new(n_rows, n_cols)) == NULL)
    return NULL;

  for (size_t i = 1; i <= n_rows; i++) {
    for (size_t j = 1; j <= n_cols; j++) {
      m->values[MAT_INDEX(n_cols, i, j)] = 1;
    }
  }

  return m;
}

Matrix
matrix_zeros(size_t n_rows, size_t n_cols) {

  Matrix m;
  if ((m = matrix_new(n_rows, n_cols)) == NULL)
    return NULL;

  for (size_t i = 1; i <= n_rows; i++) {
    for (size_t j = 1; j <= n_cols; j++) {
      m->values[MAT_INDEX(n_cols, i, j)] = 0;
    }
  }

  return m;
}

Matrix
matrix_from(size_t n_rows, size_t n_cols, double *values) {

  Matrix m = matrix_new(n_rows, n_cols);
  for (size_t i = 1; i <= n_rows; i++) {
    for (size_t j = 1; j <= n_cols; j++) {
      m->values[MAT_INDEX(n_cols, i, j)] = values[MAT_INDEX(n_cols, i, j)];
    }
  }

  return m;
}

Matrix
matrix_eye(size_t size) {

  if (size == 0)
    return NULL;

  Matrix  m      = matrix_new(size, size);
  double *values = m->values;

  for (size_t i = 1; i <= size; i++) {
    for (size_t j = 1; j <= size; j++) {
      if (i == j)
        values[MAT_INDEX(size, i, j)] = 1;
      else
        values[MAT_INDEX(size, i, j)] = 0;
    }
  }

  return m;
}

int
matrix_free(Matrix m) {

  if (!m)
    return -1;

  free(m);

  return 0;
}

int
matrix_set(Matrix m, size_t i, size_t j, double value) {

  if (!m)
    return -1;

  if (i < 1 || i > m->n_rows)
    return -1;

  if (j < 1 || j > m->n_cols)
    return -1;

  m->values[MAT_INDEX(m->n_cols, i, j)] = value;

  return 0;
}

int
matrix_get(Matrix m, size_t i, size_t j, double *value) {

  if (!m)
    return -1;
  if (i == 0 || i > m->n_rows)
    return -1;
  if (j == 0 || j > m->n_cols)
    return -1;

  *value = m->values[MAT_INDEX(m->n_cols, i, j)];

  return 0;
}

int
matrix_printf(Matrix m) {

  if (!m)
    return -1;

  size_t num_rows = m->n_rows;
  size_t num_cols = m->n_cols;
  double value;

  for (size_t i = 1; i <= num_rows; i++) {
    for (size_t j = 1; j <= num_cols; j++) {
      if (matrix_get(m, i, j, &value) < 0)
        return -1;
      printf("%10.5g", value);
    }
    printf("\n");
  }

  return 0;
}

int
matrix_fill(Matrix a, Matrix b, size_t i, size_t j) {

  if (!a)
    return -1;
  if (!b)
    return -1;

  if (i == 0 || j == 0)
    return -1;

  size_t last_row = b->n_rows + i - 1;
  size_t last_col = b->n_cols + j - 1;

  if (last_row > a->n_rows)
    return -1;

  if (last_col > a->n_cols)
    return -1;

  size_t n_cols_b = b->n_cols;
  size_t n_cols_a = a->n_cols;

  for (size_t l = j, n = 1; l <= last_col; l++, n++) {
    for (size_t k = i, m = 1; k <= last_row; k++, m++) {
      a->values[MAT_INDEX(n_cols_a, k, l)] =
          b->values[MAT_INDEX(n_cols_b, m, n)];
    }
  }

  return 0;
}

int
matrix_row_add_row(Matrix m, size_t i1, size_t i2, double c) {

  if (!m)
    return -1;
  if (i1 == 0 || i1 > m->n_rows)
    return -1;
  if (i2 == 0 || i2 > m->n_rows)
    return -1;

  size_t  n_cols = m->n_cols;
  double  val;
  double *values = m->values;

  for (size_t j = 1; j <= n_cols; j++) {

    val =
        values[MAT_INDEX(n_cols, i1, j)] + c * values[MAT_INDEX(n_cols, i2, j)];

    values[MAT_INDEX(n_cols, i1, j)] = val;
  }

  return 0;
}

int
matrix_row_exchange(Matrix m, size_t i1, size_t i2) {
  if (!m)
    return -1;
  if (i1 == 0 || i1 > m->n_rows)
    return -1;
  if (i2 == 0 || i2 > m->n_rows)
    return -1;

  // return without swapping if swapped rows are the same
  if (i1 == i2)
    return 0;

  size_t n_cols = m->n_cols;

  double  val1;
  double *values = m->values;

  for (size_t j = 1; j <= n_cols; j++) {
    val1                             = values[MAT_INDEX(n_cols, i1, j)];
    values[MAT_INDEX(n_cols, i1, j)] = values[MAT_INDEX(n_cols, i2, j)];
    values[MAT_INDEX(n_cols, i2, j)] = val1;
  }

  return 0;
}

int
matrix_row_mult(Matrix m, size_t i, double c) {

  if (!m)
    return -1;

  if (i == 0 || i > m->n_rows)
    return -1;

  size_t  n_cols = m->n_cols;
  double *values = m->values;

  for (size_t j = 1; j <= n_cols; j++) {
    values[MAT_INDEX(n_cols, i, j)] = c * values[MAT_INDEX(n_cols, i, j)];
  }

  return 0;
}

int
matrix_mat_mult(Matrix a, Matrix b, Matrix *res_ptr) {

  if (!a)
    return -1;

  if (!b)
    return -1;

  size_t n_rows_a   = a->n_rows;
  size_t n_cols_a   = a->n_cols;
  size_t n_rows_b   = b->n_rows;
  size_t n_cols_b   = b->n_cols;
  size_t n_rows_res = n_rows_a;
  size_t n_cols_res = n_cols_b;

  if (n_cols_a != n_rows_b)
    return -1;

  Matrix res = *res_ptr;
  if (!res) {
    res = matrix_new(n_rows_res, n_cols_res);
  } else {
    if ((res->n_rows != n_rows_res) || (res->n_cols != n_cols_res))
      return -1;
  }

  double  sum;
  double *a_values   = a->values;
  double *b_values   = b->values;
  double *res_values = res->values;

  for (size_t i = 1; i <= n_rows_a; i++) {
    for (size_t j = 1; j <= n_cols_b; j++) {
      sum = 0;
      for (size_t k = 1; k <= n_cols_a; k++) {
        sum += a_values[MAT_INDEX(n_cols_a, i, k)] *
               b_values[MAT_INDEX(n_cols_b, k, j)];
      }
      res_values[MAT_INDEX(n_cols_res, i, j)] = sum;
    }
  }

  return 0;
}
