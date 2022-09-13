#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

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
LU_decomp(SPAMatrix a) {

  double pivot_value, row_value, multiplier;

  SPAMatrixSize a_size = spa_mat_size(a);

  for (size_t pivot_row = 1, pivot_col = 1;
       pivot_row <= a_size.n_rows && pivot_col <= a_size.n_cols;
       ++pivot_row, ++pivot_col) {

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

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    2, 2, 2,
    4, 7, 7,
    6, 18, 22
  }, 3, 3);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix LU = ala_copy(A);

  LU_decomp(LU);

  puts("LU=");
  spa_mat_print(LU);

  SPAMatrix L = LU_get_L(LU);
  puts("L=");
  spa_mat_print(L);

  SPAMatrix U = LU_get_U(LU);
  puts("U=");
  spa_mat_print(U);

  return EXIT_SUCCESS;
}
