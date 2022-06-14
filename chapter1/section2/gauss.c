#include "gauss.h"

Matrix
gauss_solve(Matrix a, Matrix b) {

  if (!a)
    return -1;
  if (!b)
    return -1;

  if (a->n_rows != b->n_rows)
    return -1;

  // a must be square
  if (a->n_rows != a->n_cols)
    return -1;

  size_t n_rows     = a->n_rows;
  size_t n_cols_a   = a->n_cols;
  size_t n_cols_b   = b->n_cols;
  size_t n_cols_aug = a->n_cols + b->n_cols;

  Matrix augmented = matrix_new(n_rows, n_cols_aug);

  double value;

  for (size_t i = 1; i <= n_rows; i++) {
    for (size_t j = 1; j <= n_cols_a; j++) {
      if (matrix_get(a, i, j, &value) < 0)
        return -1;
      if (matrix_set(augmented, i, j, value) < 0)
        return -1;
    }
  }

  return 0;
}
