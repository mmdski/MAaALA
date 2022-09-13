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
    2, 2, 2,
    4, 7, 7,
    6, 18, 22
  }, 3, 3);
  SPAMatrix b = ala_new_from((double[]) {
    12,
    24,
    12
  }, 3, 1);
  SPAMatrix b_tilde = ala_new_from((double[]) {
    6,
    24,
    70
  }, 3, 1);
  // clang-format on

  puts("Solution 1:");

  puts("A=");
  spa_mat_print(A);

  puts("b=");
  spa_mat_print(b);

  SPAMatrix LU = ala_copy(A);

  LU_decomp(LU);

  SPAMatrix y = ala_new(3, 1);
  LU_solve_y(y, LU, b);
  puts("y=");
  spa_mat_print(y);

  SPAMatrix x = ala_new_like(y);
  LU_solve_x(x, LU, y);
  puts("x=");
  spa_mat_print(x);

  puts("\nSolution 2:");

  puts("b~=");
  spa_mat_print(b_tilde);

  LU_solve_y(y, LU, b_tilde);
  puts("y=");
  spa_mat_print(y);

  LU_solve_x(x, LU, y);
  puts("x=");
  spa_mat_print(x);

  return EXIT_SUCCESS;
}
