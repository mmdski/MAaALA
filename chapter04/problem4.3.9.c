#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix S = ala_new_from((double[]) {
    .1, .2, .3,
    .4, .5, .6,
    .7, .8, .901
  }, 3, 3);
  // clang-format on

  puts("S = ");
  spa_mat_print(S);

  puts("(a)");
  SPAMatrix E_S = ala_copy(S);
  spa_gauss_jordan_elim(E_S, spa_mat_prow_exch_no);

  puts("Gauss-Jordan reduced with \"exact\" arithmetic");
  spa_mat_print(E_S);

  puts("(b)");
  spa_precision_set(3);
  SPAMatrix E_S_3 = ala_copy(S);
  spa_gauss_jordan_elim(E_S_3, spa_mat_prow_exch_no);

  puts("Gauss-Jordan reduced with 3-digit arithmetic");
  spa_mat_print(E_S_3);

  return EXIT_SUCCESS;
}
