#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
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

  SPAMatrix res = NULL;
  spa_mat_new(&res, 1, 1);

  puts("C:");
  spa_mat_print(C);

  puts("C^T C=");
  spa_mat_matrix_mult(res, C_T, C);
  spa_mat_print(res);

  spa_mat_free(&res);
  spa_mat_free(&C_T);
  spa_mat_free(&C);

  return EXIT_SUCCESS;
}
