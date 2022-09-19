#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]){
    2, 1, 1, 0,
    4, 2, 1, 2,
    6, 3, 2, 2
  }, 3, 4);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix E_A = ala_copy(A);
  spa_gauss_jordan_elim(E_A, spa_mat_prow_exch_max);
  puts("E_A=");
  spa_mat_print(E_A);

  size_t *basic_col_nos = malloc(4 * sizeof(size_t));
  size_t  n_basic_cols  = spa_gauss_basic_col_nos(E_A, basic_col_nos);
  printf("n_basic_cols = %zu\n", n_basic_cols);

  puts("(a) The linear independent subset of A is ");
  SPAMatrix basic_cols = ala_mat_col_extract(A, n_basic_cols, basic_col_nos);
  spa_mat_print(basic_cols);

  free(basic_col_nos);

  return EXIT_SUCCESS;
}
