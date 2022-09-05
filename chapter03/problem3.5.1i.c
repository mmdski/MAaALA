#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix B = NULL;
  spa_mat_new_arr(&B, (double[]) {
      1, 2,
      0, 4,
      3, 7
    }, 3, 2);
  // clang-format on

  SPAMatrix B_T = NULL;
  spa_mat_new(&B_T, 2, 3);
  spa_mat_transpose(B_T, B);

  SPAMatrix res = NULL;
  spa_mat_new(&res, 3, 3);

  puts("B:");
  spa_mat_print(B);

  puts("B B^T=");
  spa_mat_matrix_mult(res, B, B_T);
  spa_mat_print(res);

  spa_mat_free(&res);
  spa_mat_free(&B_T);
  spa_mat_free(&B);

  return EXIT_SUCCESS;
}
