#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    1, 1, 10,
    2, 1, 12,
    2, 2, 15,
    3, 2, 17
  }, 4, 3);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix ones = NULL;
  spa_mat_new_ones(&ones, 4, 1);

  SPAMatrix aug = ala_mat_colcat(ones, A);
  puts("aug=");
  spa_mat_print(aug);

  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);
  puts("E=");
  spa_mat_print(aug);

  return EXIT_SUCCESS;
}
