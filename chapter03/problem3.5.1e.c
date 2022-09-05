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
  // clang-format on

  SPAMatrix res = NULL;
  spa_mat_new(&res, 3, 3);

  puts("A:");
  spa_mat_print(A);

  puts("A^2=");
  spa_mat_matrix_mult(res, A, A);
  spa_mat_print(res);

  spa_mat_free(&res);
  spa_mat_free(&A);

  return EXIT_SUCCESS;
}
