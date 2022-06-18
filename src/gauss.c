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

static int
exchange_pivot(Matrix m, size_t pivot_row, size_t pivot_col) {

  size_t n_rows = m->n_rows;
  size_t i_max;
  double value;
  double max_value;

  if (matrix_get(m, pivot_row, pivot_col, &max_value) < 0)
    return -1;

  i_max = pivot_row;

  for (size_t i = pivot_row; i <= n_rows; i++) {

    if (matrix_get(m, i, pivot_col, &value) < 0)
      return -1;

    if (value * value > max_value * max_value) {
      i_max     = i;
      max_value = value;
    }
  }

  if (matrix_row_exchange(m, pivot_row, i_max) < 0)
    return -1;
  else
    return 0;
}

// partial pivoting gauss reduction
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

  for (size_t pivot_col = 1; pivot_col <= n_cols_a; pivot_col++) {

    if (exchange_pivot(aug, pivot_row, pivot_col) < 0)
      return -1;

    if (matrix_get(aug, pivot_row, pivot_col, &pivot_value) < 0)
      return -1;

    for (size_t i = pivot_row + 1; i <= n_rows; i++) {

      if (matrix_get(aug, i, pivot_col, &row_value) < 0)
        return -1;

      // row value in pivot column is already zero
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
  size_t n_cols_b = n_cols_g - n_rows;

  if (n_cols_b == 0)
    return -1;

  size_t n_cols_a = n_rows;

  Matrix x      = *x_ptr;
  bool   free_x = false;
  if (!x) {
    x      = matrix_new(n_rows, n_cols_b);
    *x_ptr = x;
    free_x = true;
  } else {
    if ((x->n_rows != n_rows) || (x->n_cols != n_cols_b))
      goto fail;
  }

  double c_value;
  double t_value;
  double x_sum;
  double x_val;

  for (size_t b_col = 1; b_col <= n_cols_b; b_col++) {
    for (size_t i = n_rows; i > 0; i--) {

      if ((matrix_get(g_reduced, i, n_cols_a + b_col, &c_value)) < 0)
        goto fail;

      x_sum = c_value;

      for (size_t j = i + 1; j <= n_cols_a; j++) {

        if ((matrix_get(g_reduced, i, j, &t_value)) < 0)
          goto fail;

        if (matrix_get(x, j, b_col, &x_val) < 0)
          goto fail;

        x_sum -= t_value * x_val;
      }

      if ((matrix_get(g_reduced, i, i, &t_value)) < 0)
        goto fail;

      if (matrix_set(x, i, b_col, x_sum / t_value) < 0)
        goto fail;
    }
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

  matrix_free(aug);

  return 0;

fail:
  matrix_free(aug);
  return -1;
}
