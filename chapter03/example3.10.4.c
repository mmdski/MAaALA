#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

void
LU_prow_exch_max(SPAMatrix a, SPAMatrix p, size_t pivot_row, size_t pivot_col) {

  SPAMatrixSize a_size        = spa_mat_size(a);
  size_t        max_row       = pivot_row;
  double        abs_max_value = fabs(spa_mat_get(a, pivot_row, pivot_col));
  double        abs_value;

  for (size_t i = pivot_row + 1; i <= a_size.n_rows; ++i) {
    abs_value = fabs(spa_mat_get(a, i, pivot_col));
    if (abs_value > abs_max_value) {
      abs_max_value = abs_value;
      max_row       = i;
    }
  }

  spa_mat_row_exch(a, pivot_row, max_row);
  spa_mat_row_exch(p, pivot_row, max_row);
}

void
LU_add_row(SPAMatrix a, size_t i1, size_t i2, size_t pivot_col, double c) {

  double        sum, prod;
  SPAMatrixSize a_size = spa_mat_size(a);

  for (size_t j = pivot_col; j <= a_size.n_cols; ++j) {
    prod = spa_fl(c * spa_mat_get(a, i2, j));
    sum  = spa_fl(spa_mat_get(a, i1, j) + prod);
    spa_mat_set(a, i1, j, sum);
  }
}

void
LU_decomp(SPAMatrix a, SPAMatrix p) {

  double pivot_value, row_value, multiplier;

  SPAMatrixSize a_size = spa_mat_size(a);

  for (size_t pivot_row = 1, pivot_col = 1;
       pivot_row <= a_size.n_rows && pivot_col <= a_size.n_cols;
       ++pivot_row, ++pivot_col) {

    LU_prow_exch_max(a, p, pivot_row, pivot_col);

    pivot_value = spa_mat_get(a, pivot_row, pivot_col);

    for (size_t i = pivot_row + 1; i <= a_size.n_rows; ++i) {

      row_value = spa_mat_get(a, i, pivot_col);

      multiplier = spa_fl(row_value / pivot_value);
      LU_add_row(a, i, pivot_row, pivot_col, -multiplier);
      spa_mat_set(a, i, pivot_col, multiplier);
    }
  }
}

SPAMatrix
LU_p_to_P(SPAMatrix p) {

  SPAMatrixSize p_size = spa_mat_size(p);

  SPAMatrix P = NULL;
  spa_mat_new_zeros(&P, p_size.n_rows, p_size.n_rows);

  for (size_t i = 1; i <= p_size.n_rows; ++i) {
    spa_mat_set(P, i, spa_mat_get(p, i, 1), 1);
  }

  return P;
}

SPAMatrix
LU_get_L(SPAMatrix a) {

  SPAMatrixSize a_size = spa_mat_size(a);

  SPAMatrix L = ala_new_like(a);

  for (size_t i = 1; i <= a_size.n_rows; ++i) {
    for (size_t j = 1; j <= a_size.n_cols; ++j) {
      if (j < i)
        spa_mat_set(L, i, j, spa_mat_get(a, i, j));
      else if (i == j)
        spa_mat_set(L, i, j, 1);
      else
        spa_mat_set(L, i, j, 0);
    }
  }

  return L;
}

SPAMatrix
LU_get_U(SPAMatrix a) {

  SPAMatrixSize a_size = spa_mat_size(a);

  SPAMatrix U = ala_new_like(a);

  for (size_t i = 1; i <= a_size.n_rows; ++i) {
    for (size_t j = 1; j <= a_size.n_cols; ++j) {
      if (j >= i)
        spa_mat_set(U, i, j, spa_mat_get(a, i, j));
      else
        spa_mat_set(U, i, j, 0);
    }
  }

  return U;
}

void
LU_solve_y(SPAMatrix y, SPAMatrix LU, SPAMatrix b) {

  // forward-solve for y
  spa_mat_set(y, 1, 1, spa_mat_get(b, 1, 1));

  double sum;

  SPAMatrixSize lu_size = spa_mat_size(LU);

  for (size_t i = 2; i <= lu_size.n_rows; ++i) {
    sum = spa_mat_get(b, i, 1);

    for (size_t k = 1; k < i; ++k)
      sum -= spa_mat_get(LU, i, k) * spa_mat_get(y, k, 1);

    spa_mat_set(y, i, 1, sum);
  }
}

void
LU_solve_x(SPAMatrix x, SPAMatrix LU, SPAMatrix y) {

  SPAMatrixSize lu_size = spa_mat_size(LU);

  double sum;

  for (size_t i = lu_size.n_rows; i >= 1; --i) {

    sum = spa_mat_get(y, i, 1);

    for (size_t k = i + 1; k <= lu_size.n_cols; ++k)
      sum -= spa_mat_get(LU, i, k) * spa_mat_get(x, k, 1);

    spa_mat_set(x, i, 1, sum / spa_mat_get(LU, i, i));
  }
}

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
     1,  2, -3,  4,
     4,  8, 12, -8,
     2,  3,  2,  1,
    -3, -1,  1, -4
  }, 4, 4);
  SPAMatrix p = ala_new_from((double[]) {
    1,
    2,
    3,
    4
  }, 4, 1);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix LU = ala_copy(A);

  LU_decomp(LU, p);

  puts("LU=");
  spa_mat_print(LU);

  SPAMatrix P = LU_p_to_P(p);
  SPAMatrix L = LU_get_L(LU);
  SPAMatrix U = LU_get_U(LU);

  puts("L=");
  spa_mat_print(L);

  puts("U=");
  spa_mat_print(U);

  puts("P=");
  spa_mat_print(P);

  return EXIT_SUCCESS;
}
