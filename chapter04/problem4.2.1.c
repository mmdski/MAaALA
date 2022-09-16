#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
     1,  2, 1, 1,  5,
    -2, -4, 0, 4, -2,
     1,  2, 2, 4,  9
  }, 3, 5);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix E_A = ala_copy(A);
  spa_gauss_jordan_elim(E_A, spa_mat_prow_exch_max);

  puts("E_A=");
  spa_mat_print(E_A);

  size_t   *basic_col_nos = malloc(5 * sizeof(size_t));
  size_t    n_basic_cols  = spa_gauss_basic_col_nos(E_A, basic_col_nos);
  SPAMatrix basic_cols    = ala_new(3, n_basic_cols);
  spa_mat_col_extract(basic_cols, A, basic_col_nos);

  puts("Spanning set for R(A) = ");
  spa_mat_print(basic_cols);

  return EXIT_SUCCESS;
}
