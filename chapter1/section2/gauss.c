#include <stdbool.h>
#include <stdlib.h>

#include "gauss.h"

int
gauss_init_augmented(Matrix a, Matrix b, Matrix *aug_ptr) {
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
  size_t n_cols_aug = a->n_cols + b->n_cols;

  Matrix aug      = *aug_ptr;
  bool   free_aug = false;
  if (!aug) {
    aug      = matrix_new(n_rows, n_cols_aug);
    *aug_ptr = aug;
    free_aug = true;
  } else {
    if (aug->n_rows != n_rows || aug->n_cols != n_cols_aug)
      return -1;
  }

  if (matrix_fill(aug, a, 1, 1) < 0)
    goto fail;
  if (matrix_fill(aug, b, 1, n_cols_a + 1) < 0)
    goto fail;

  return 0;

fail:
  if (free_aug) {
    matrix_free(aug);
    *aug_ptr = NULL;
  }
  return -1;
}

int
gauss_reduce(Matrix aug) {

  if (!aug)
    return -1;

  size_t n_rows = aug->n_rows;
  size_t n_cols = aug->n_cols;

  if (n_cols <= n_rows)
    return -1;

  double multiplier;
  double pivot_value;
  double row_value;
  size_t pivot_row = 1;
  size_t n_cols_a  = n_rows;

  for (size_t j = 1; j <= n_cols_a; j++) {

    if (matrix_get(aug, pivot_row, j, &pivot_value) < 0)
      return -1;

    for (size_t i = pivot_row + 1; i <= n_rows; i++) {

      if (matrix_get(aug, i, j, &row_value) < 0)
        return -1;

      // pivot column is already zero
      if (row_value == 0)
        continue;

      multiplier = -row_value / pivot_value;

      if (matrix_row_add_row(aug, i, pivot_row, multiplier) < 0)
        return -1;
    }

    pivot_row++;
  }

  return 0;
}

int
gauss_back_sub(Matrix g_reduced, Matrix *x_ptr) {

  if (!g_reduced)
    return -1;

  size_t n_rows   = g_reduced->n_rows;
  size_t n_cols_g = g_reduced->n_cols;

  // the last column is b
  size_t n_cols_a = n_cols_g - 1;

  // a in the reduced matrix must be square
  if (n_rows != n_cols_a)
    return -1;

  Matrix x      = *x_ptr;
  bool   free_x = false;
  if (!x) {
    x      = matrix_new(n_rows, 1);
    *x_ptr = x;
    free_x = true;
  } else {
    if ((x->n_rows != n_rows) || (x->n_cols != 1))
      goto fail;
  }

  double  c_value;
  double  t_value;
  double  x_sum;
  double *x_values = x->values;

  for (size_t i = n_rows; i > 0; i--) {
    if ((matrix_get(g_reduced, i, n_rows + 1, &c_value)) < 0)
      goto fail;

    x_sum = c_value;

    for (size_t j = i + 1; j <= n_cols_a; j++) {

      if ((matrix_get(g_reduced, i, j, &t_value)) < 0)
        goto fail;

      x_sum -= t_value * x_values[j - 1];
    }

    if ((matrix_get(g_reduced, i, i, &t_value)) < 0)
      goto fail;

    x_values[i - 1] = x_sum / t_value;
  }

  return 0;

fail:
  if (free_x) {
    matrix_free(x);
    *x_ptr = NULL;
  }
  return -1;
}

int
gauss_solve(Matrix a, Matrix b, Matrix *x_ptr) {

  Matrix aug = NULL;
  if (gauss_init_augmented(a, b, &aug) < 0)
    goto fail;

  if (gauss_reduce(aug) < 0)
    goto fail;

  if (gauss_back_sub(aug, x_ptr) < 0)
    goto fail;

  return 0;

fail:
  matrix_free(aug);
  return -1;
}
