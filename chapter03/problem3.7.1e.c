#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]) {
    1, 1, 1, 1,
    1, 2, 2, 2,
    1, 2, 3, 3,
    1, 2, 3, 4
  }, 4, 4);
  // clang-format on

  SPAMatrixSize A_size = spa_mat_size(A);

  SPAMatrix I = NULL;
  spa_mat_new_eye(&I, A_size.n_cols);

  SPAMatrix aug = NULL;
  spa_mat_new_colcat(&aug, A, I);

  puts("Augmented matrix:");
  spa_mat_print(aug);

  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);
  puts("Reduced augmented matrix:");
  spa_mat_print(aug);

  // make sure the identity matrix is on the left of the reduced augmented
  // matrix ([I|A^-1])
  SPAMatrix I_check = NULL;
  spa_mat_new_like(&I_check, A);

  size_t *col_nos = malloc(A_size.n_cols * sizeof(size_t));
  for (size_t i = 0; i < A_size.n_cols; ++i) {
    col_nos[i] = i + 1;
  }

  spa_mat_col_extract(I_check, aug, col_nos);
  if (spa_mat_isclose(I_check, I, 0.05, 0)) {
    puts("A is an invertible matrix.");
  } else {
    puts("Inversion failed: A is a singular matrix");
    goto exit;
  }

  for (size_t i = 0; i < A_size.n_cols; ++i) {
    col_nos[i] = i + 1 + A_size.n_cols;
  }

  SPAMatrix A_inv = NULL;
  spa_mat_new_like(&A_inv, A);
  spa_mat_col_extract(A_inv, aug, col_nos);

  puts("A^-1=");
  spa_mat_print(A_inv);

  SPAMatrix prod = NULL;
  spa_mat_new_like(&prod, A);
  spa_mat_matrix_mult(prod, A, A_inv);
  puts("AA^-1=");
  spa_mat_print(prod);

  spa_mat_free(&prod);
  spa_mat_free(&A_inv);

exit:
  spa_mat_free(&I_check);
  spa_mat_free(&aug);
  spa_mat_free(&I);
  spa_mat_free(&A);

  return EXIT_SUCCESS;
}
