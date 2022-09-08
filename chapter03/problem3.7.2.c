#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]) {
    0, -1,  0,
    0,  0, -1,
    0,  0,  0
  }, 3, 3);
  SPAMatrix B = NULL;
  spa_mat_new_arr(&B, (double[]) {
    1, 2,
    2, 1,
    3, 3
  }, 3, 2);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  puts("B=");
  spa_mat_print(B);

  SPAMatrix I = NULL;
  spa_mat_new_like(&I, A);
  spa_mat_eye(I);

  SPAMatrix diff = NULL;
  spa_mat_new_like(&diff, A);
  spa_mat_matrix_sub(diff, I, A);

  SPAMatrix aug = NULL;
  spa_mat_new_colcat(&aug, diff, I);
  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);

  puts("Reduced augmented matrix:");
  spa_mat_print(aug);

  SPAMatrix inv = NULL;
  spa_mat_new_like(&inv, diff);
  spa_mat_col_extract(inv, aug, (size_t[]){4, 5, 6});

  SPAMatrix X = NULL;
  spa_mat_new_like(&X, B);
  spa_mat_matrix_mult(X, inv, B);

  puts("X=");
  spa_mat_print(X);

  return EXIT_SUCCESS;
}
