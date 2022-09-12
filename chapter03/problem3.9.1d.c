#include <stdio.h>
#include <stdlib.h>

#include <ala.h>
#include <spam.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    1, 2, 3, 4,
    2, 4, 6, 7,
    1, 2, 3, 6
  }, 3, 4);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix eye = NULL;
  spa_mat_new_eye(&eye, 3);

  SPAMatrix aug = ala_mat_colcat(A, eye);

  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);

  SPAMatrix P = NULL;
  spa_mat_new(&P, 3, 3);
  spa_mat_col_extract(P, aug, (size_t[]){5, 6, 7});

  puts("P=");
  spa_mat_print(P);

  SPAMatrix E_A = NULL;
  spa_mat_new_like(&E_A, A);

  spa_mat_matrix_mult(E_A, P, A);
  puts("E_A=");
  spa_mat_print(E_A);

  eye             = ala_eye(4);
  aug             = ala_mat_rowcat(E_A, eye);
  SPAMatrix aug_t = ala_mat_transpose(aug);

  spa_gauss_jordan_elim(aug_t, spa_mat_prow_exch_max);
  SPAMatrix Q_t = ala_mat_col_extract(aug_t, 4, (size_t[]){4, 5, 6, 7});
  SPAMatrix Q   = ala_mat_transpose(Q_t);

  puts("Q=");
  spa_mat_print(Q);

  puts("PAQ=");
  SPAMatrix PAQ = ala_mat_mult(P, ala_mat_mult(A, Q));
  spa_mat_print(PAQ);

  return EXIT_SUCCESS;
}
