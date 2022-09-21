#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    1, 2, 0, 2, 1,
    3, 6, 1, 9, 6,
    2, 4, 1, 7, 5
  }, 3, 5);
  // clang-format on

  puts("A=");
  spa_mat_print(A);

  SPAMatrix E = ala_copy(A);
  spa_gauss_jordan_elim(E, spa_mat_prow_exch_max);

  size_t   *basic_col_nos = malloc(5 * sizeof(size_t));
  size_t    n_basic_cols  = spa_gauss_basic_col_nos(E, basic_col_nos);
  SPAMatrix basic_cols    = ala_new(3, n_basic_cols);
  spa_mat_col_extract(basic_cols, A, basic_col_nos);
  free(basic_col_nos);

  puts("The basis of  R(A) is ");
  spa_mat_print(basic_cols);

  size_t   *nonzero_row_nos = malloc(3 * sizeof(size_t));
  size_t    n_nonzero_rows  = spa_gauss_nonzero_row_nos(E, nonzero_row_nos);
  SPAMatrix nonzero_rows    = ala_new(n_nonzero_rows, 5);
  spa_mat_row_extract(nonzero_rows, E, nonzero_row_nos);

  puts("The basis of R(A^T) is");
  spa_mat_print(ala_mat_transpose(nonzero_rows));

  SPAMatrix zeros = ala_zeros(3, 1);
  SPAMatrix aug   = ala_mat_colcat(A, zeros);
  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);

  basic_col_nos = malloc(6 * sizeof(size_t));
  n_basic_cols  = spa_gauss_basic_col_nos(aug, basic_col_nos);

  size_t  n_free_cols  = 6 - n_basic_cols;
  size_t *free_col_nos = malloc(n_free_cols * sizeof(size_t));
  spa_gauss_free_col_nos(free_col_nos, n_free_cols, basic_col_nos);
  free(basic_col_nos);

  SPAMatrix part_solns = ala_new(5, n_free_cols);
  spa_gauss_part_solns(part_solns, aug, free_col_nos);

  SPAMatrix null_span = ala_mat_col_extract(part_solns, 3, (size_t[]){2, 3, 4});

  puts("The basis of N(A) is");
  spa_mat_print(null_span);

  SPAMatrix eye = ala_eye(3);
  aug           = ala_mat_colcat(A, eye);
  spa_gauss_elim(aug, spa_mat_prow_exch_max);

  SPAMatrix P = ala_mat_col_extract(aug, 3, (size_t[]){6, 7, 8});
  SPAMatrix left_null_span =
      ala_mat_transpose(ala_mat_row_extract(P, 1, (size_t[]){3}));

  puts("The basis of N(A^T) is");
  spa_mat_print(left_null_span);

  return EXIT_SUCCESS;
}
