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
    3, 7}, 3, 2);
  SPAMatrix C = NULL;
  spa_mat_new_arr(&C, (double[]) {
    1,
    2,
    3}, 3, 1);
  // clang-format on

  SPAMatrix C_T = NULL;
  spa_mat_new(&C_T, 1, 3);

  SPAMatrix res = NULL;
  spa_mat_new(&res, 1, 2);

  spa_mat_transpose(C_T, C);

  puts("C_T:");
  spa_mat_print(C_T);

  puts("B:");
  spa_mat_print(B);

  spa_mat_matrix_mult(res, C_T, B);

  puts("C_T B = ");
  spa_mat_print(res);

  spa_mat_free(&res);
  spa_mat_free(&C_T);
  spa_mat_free(&C);
  spa_mat_free(&B);

  return EXIT_SUCCESS;
}
