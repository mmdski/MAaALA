#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = NULL;
  spa_mat_new_arr(&A, (double[]) {
    2, 1, 1,
    4, 0, 2,
    2, 2, 0
  }, 3, 3);
  SPAMatrix b = NULL;
  spa_mat_new_arr(&b, (double[]) {
    3,
    10,
    -2
  }, 3, 1);
  // clang-format on

  puts("(a)");
  puts("Ax=b");
  puts("A:");
  spa_mat_print(A);
  puts("b:");
  spa_mat_print(b);

  SPAMatrix s = NULL;
  spa_gauss_solve(A, b, &s, spa_mat_prow_exch_max);

  puts("\n(b)");
  puts("s=");
  spa_mat_print(s);

  SPAMatrix res = NULL;
  spa_mat_new(&res, 3, 1);

  spa_mat_matrix_mult(res, A, s);
  puts("As=");
  spa_mat_print(res);

  puts("\n(c)");
  printf("b = (%g)(A_*1) + (%g)(A_*2) + (%g)(A_*3)\n",
         spa_mat_get(s, 1, 1),
         spa_mat_get(s, 2, 1),
         spa_mat_get(s, 3, 1));

  spa_mat_free(&res);
  spa_mat_free(&s);
  spa_mat_free(&b);
  spa_mat_free(&A);

  return EXIT_SUCCESS;
}
