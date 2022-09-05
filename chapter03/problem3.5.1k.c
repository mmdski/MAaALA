#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]) {
      1, -2, 3,
      0, -5, 4,
      4, -3, 8
    }, 3, 3);
  SPAMatrix C = NULL;
  spa_mat_new_arr(&C, (double[]) {
      1,
      2,
      3
    }, 3, 1);
  // clang-format on

  SPAMatrix C_T = NULL;
  spa_mat_new(&C_T, 1, 3);
  spa_mat_transpose(C_T, C);

  SPAMatrix res1 = NULL;
  spa_mat_new(&res1, 3, 1);

  SPAMatrix res = NULL;
  spa_mat_new(&res, 1, 1);

  puts("A:");
  spa_mat_print(A);

  puts("C:");
  spa_mat_print(C);

  puts("C^T A C=");
  spa_mat_matrix_mult(res1, A, C);
  spa_mat_matrix_mult(res, C_T, res1);
  spa_mat_print(res);

  spa_mat_free(&res);
  spa_mat_free(&res1);
  spa_mat_free(&C_T);
  spa_mat_free(&C);
  spa_mat_free(&A);

  return EXIT_SUCCESS;
}
