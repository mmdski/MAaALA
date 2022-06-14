#include <stdlib.h>

#include "matrix.h"

#define MAT_INDEX(n_cols, row, col) (row - 1) * n_cols + (col - 1)

Matrix
matrix_new(size_t n_rows, size_t n_cols) {

  if (n_rows == 0 || n_cols == 0)
    return NULL;

  Matrix m;
  m         = malloc(sizeof(*m) + sizeof(double) * n_rows * n_cols);
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
matrix_row_mult_const(Matrix m, size_t i, double c) {

  if (!m)
    return -1;
  if (i == 0 || i > m->n_rows)
    return -1;

  size_t n_cols = m->n_cols;
  double val;

  for (size_t j = 1; j <= n_cols; j++) {
    val = m->values[MAT_INDEX(n_cols, i, j)];
    m->values[MAT_INDEX(n_cols, i, j)] *= c * val;
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

  size_t n_cols = m->n_cols;
  double val;

  for (size_t j = 1; j <= n_cols; j++) {
    val = m->values[MAT_INDEX(n_cols, i2, j)];
    m->values[MAT_INDEX(n_cols, i1, j)] *= c * val;
  }

  return 0;
}
