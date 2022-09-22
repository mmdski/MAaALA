#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    1, 3, 1, -4,
    -1, -3, 1, 0,
    2, 6, 2, -8
  }, 3, 4);
  // clang-format on

  puts("A = ");
  spa_mat_print(A);

  SPAMatrix ATA = ala_mat_mult(ala_mat_transpose(A), A);
  spa_gauss_jordan_elim(ATA, spa_mat_prow_exch_max);
  size_t ata_n_basic_cols = spa_gauss_basic_col_nos(ATA, NULL);

  SPAMatrix AAT = ala_mat_mult(A, ala_mat_transpose(A));
  spa_gauss_jordan_elim(AAT, spa_mat_prow_exch_max);
  size_t aat_n_basic_cols = spa_gauss_basic_col_nos(AAT, NULL);

  spa_gauss_jordan_elim(A, spa_mat_prow_exch_max);
  spa_gauss_jordan_elim(A, spa_mat_prow_exch_max);
  size_t n_basic_cols = spa_gauss_basic_col_nos(A, NULL);

  printf("rank(A^T A) = %zu\n", ata_n_basic_cols);
  printf("rank(AA^T) = %zu\n", aat_n_basic_cols);
  printf("rank(A) = %zu\n", n_basic_cols);

  return EXIT_SUCCESS;
}
