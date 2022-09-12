#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    2, 2, 0, -1,
    3, -1, 4, 0,
    0, -8, 8, 3
  }, 3, 4);
  SPAMatrix B = ala_new_from((double[]) {
    2, -6, 8, 2,
    5, 1, 4, -1,
    3, -9, 12, 3
  }, 3, 4);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  puts("B=");
  spa_mat_print(B);

  puts("(a)");

  SPAMatrix E_A = ala_copy(A);
  spa_gauss_jordan_elim(E_A, spa_mat_prow_exch_max);

  SPAMatrix E_B = ala_copy(B);
  spa_gauss_jordan_elim(E_B, spa_mat_prow_exch_max);

  size_t a_n_basic_cols = spa_gauss_basic_col_nos(E_A, NULL);
  size_t b_n_basic_cols = spa_gauss_basic_col_nos(E_B, NULL);

  printf("rank(A) = rank(E_A) = %zu\n", a_n_basic_cols);
  printf("rank(B) = rank(E_B) = %zu\n", b_n_basic_cols);

  if (a_n_basic_cols == b_n_basic_cols) {
    puts("A ~ B");
  } else {
    puts("A !~ B");
    return EXIT_FAILURE;
  }

  puts("(b)");

  puts("E_A=");
  spa_mat_print(E_A);

  puts("E_B=");
  spa_mat_print(E_B);

  if (spa_mat_isclose(E_A, E_B, 0.05, 0)) {
    puts("A row~ B");
  } else {
    puts("A !(row~) B");
  }

  puts("(c)");
  SPAMatrix E_A_T = ala_mat_transpose(A);
  spa_gauss_jordan_elim(E_A_T, spa_mat_prow_exch_max);

  SPAMatrix E_B_T = ala_mat_transpose(B);
  spa_gauss_jordan_elim(E_B_T, spa_mat_prow_exch_max);

  puts("E_A_T=");
  spa_mat_print(E_A_T);

  puts("E_B_T=");
  spa_mat_print(E_B_T);

  if (spa_mat_isclose(E_A_T, E_B_T, 0.05, 0)) {
    puts("A col~ B");
  } else {
    puts("A !(col~) B");
  }

  return EXIT_SUCCESS;
}
