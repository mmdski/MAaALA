#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]){
      1, -2, 3,
      0, -5, 4,
      4, -3, 8},
    3, 3);

  SPAMatrix B = NULL;
  spa_mat_new_arr(&B, (double[]){
      1, 2,
      0, 4,
      3, 7},
    3, 2);
  // clang-format on

  puts("A:");
  spa_mat_print(A);

  puts("B:");
  spa_mat_print(B);

  SPAMatrix res = NULL;
  spa_mat_new(&res, 3, 2);
  spa_mat_matrix_mult(res, A, B);
  puts("AB=");
  spa_mat_print(res);

  spa_mat_free(&A);
  spa_mat_free(&B);
  spa_mat_free(&res);

  return EXIT_SUCCESS;
}
