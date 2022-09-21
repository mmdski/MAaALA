#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix a = ala_new_from((double[]) {
    1, 2, 2, 3,
    2, 4, 1, 3,
    3, 6, 1, 4
  }, 3, 4);
  // clang-format on

  puts("A = ");
  spa_mat_print(a);

  SPAMatrixSize a_size = spa_mat_size(a);

  SPAMatrix zeros = NULL;
  spa_mat_new_zeros(&zeros, a_size.n_rows, 1);

  spa_gauss_jordan_elim(a, spa_mat_prow_exch_max);
  puts("E_A = ");
  spa_mat_print(a);

  size_t n_basic_cols = spa_gauss_basic_col_nos(a, NULL);

  printf("dim R(A) = %zu\n", n_basic_cols);
  printf("dim N(A) = %zu\n", a_size.n_cols - n_basic_cols);
  printf("dim R(A^T) = %zu\n", n_basic_cols);
  printf("dim N(A^T) = %zu\n", a_size.n_rows - n_basic_cols);

  return EXIT_SUCCESS;
}
