#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]){
    1, 2, 1,
    2, 1, 5,
    3, 0, 9
  }, 3, 3);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  spa_gauss_jordan_elim(A, spa_mat_prow_exch_max);
  puts("E_A=");
  spa_mat_print(A);

  return EXIT_SUCCESS;
}
