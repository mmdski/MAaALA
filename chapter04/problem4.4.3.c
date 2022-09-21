#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix S = ala_new_from((double[]) {
    1, 1, 2, 1, 3,
    2, 0, 8, 1, 3,
    -1, 0, -4, 1, 0,
    3, 2, 8, 1, 6
  }, 4, 5);
  // clang-format on

  spa_gauss_jordan_elim(S, spa_mat_prow_exch_max);

  size_t n_basic_cols = spa_gauss_basic_col_nos(S, NULL);

  printf("dim span(S) = %zu\n", n_basic_cols);

  return EXIT_SUCCESS;
}
