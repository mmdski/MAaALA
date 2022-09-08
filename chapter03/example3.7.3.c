#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]) {
    1, 1, 1,
    1, 2, 2,
    1, 2, 3
  }, 3, 3);
  // clang-format on

  SPAMatrix I = NULL;
  spa_mat_new_eye(&I, 3);

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
  spa_mat_new(&I_check, 3, 3);
  spa_mat_col_extract(I_check, aug, (size_t[]){1, 2, 3});
  if (!spa_mat_isclose(I_check, I, 0.05, 0)) {
    puts("Inversion failed: A is a singular matrix");
    return EXIT_FAILURE;
  }

  SPAMatrix A_inv = NULL;
  spa_mat_new(&A_inv, 3, 3);
  spa_mat_col_extract(A_inv, aug, (size_t[]){4, 5, 6});

  puts("A^-1=");
  spa_mat_print(A_inv);

  SPAMatrix prod = NULL;
  spa_mat_new(&prod, 3, 3);
  spa_mat_matrix_mult(prod, A, A_inv);
  puts("AA^-1=");
  spa_mat_print(prod);

  spa_mat_free(&prod);
  spa_mat_free(&A_inv);
  spa_mat_free(&I_check);
  spa_mat_free(&aug);
  spa_mat_free(&I);
  spa_mat_free(&A);

  return EXIT_SUCCESS;
}
