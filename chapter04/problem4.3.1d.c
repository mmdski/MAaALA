#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]){
    2, 2, 2, 2,
    2, 2, 0, 2,
    2, 0, 2, 2
  }, 3, 4);
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
