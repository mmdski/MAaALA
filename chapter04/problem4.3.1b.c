#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]){
    1, 2, 3,
    0, 4, 5,
    0, 0, 6,
    1, 1, 1
  }, 4, 3);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix A_T = ala_mat_transpose(A);

  puts("A_T=");
  spa_mat_print(A_T);

  spa_gauss_jordan_elim(A_T, spa_mat_prow_exch_max);
  puts("E_A_T=");
  spa_mat_print(A_T);

  return EXIT_SUCCESS;
}
