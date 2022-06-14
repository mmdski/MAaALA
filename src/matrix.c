#include <stdlib.h>

#include "matrix.h"

#define INDEX(n_cols, row, col) (row - 1) * n_cols + (col - 1)

Matrix
matrix_new(size_t n_rows, size_t n_cols) {

  if (n_rows == 0 || n_cols == 0)
    return NULL;

  Matrix m;
  m = malloc(sizeof *(m));

  m->n_rows = n_rows;
  m->n_cols = n_cols;

  m->values = malloc(sizeof(double) * n_rows * n_cols);

  return m;
}

int
matrix_free(Matrix m) {

  if (!m)
    return -1;

  free(m->values);
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

  m->values[INDEX(m->n_cols, i, j)] = value;

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

  *value = m->values[INDEX(m->n_cols, i, j)];

  return 0;
}
