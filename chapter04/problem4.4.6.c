#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

int
main(void) {

  // clang-format off
  SPAMatrix B = ala_new_from((double[]) {
    2, 1,
    3, 1,
    2, -1
  }, 3, 2);
  SPAMatrix A = ala_new_from((double[]) {
    1, 5, 3,
    2, 8, 4,
    3, 7, 1
  }, 3, 3);
  // clang-format on

  puts("B = ");
  spa_mat_print(B);

  puts("A = ");
  spa_mat_print(A);

  SPAMatrix cat_mat        = ala_mat_colcat(B, A);
  SPAMatrix cat_mat_reduce = ala_copy(cat_mat);
  spa_gauss_jordan_elim(cat_mat_reduce, spa_mat_prow_exch_max);

  size_t *basic_col_nos = malloc(5 * sizeof(size_t));
  size_t  n_basic_cols = spa_gauss_basic_col_nos(cat_mat_reduce, basic_col_nos);

  SPAMatrix basic_cat_cols =
      ala_mat_col_extract(cat_mat, n_basic_cols, basic_col_nos);

  if (spa_mat_isclose(B, basic_cat_cols, 0.05, 0))
    puts("B is a basis for the space spanned by A");
  else
    puts("B is not a basis for the space spanned by A");

  return EXIT_SUCCESS;
}
