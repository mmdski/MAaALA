#include <stdio.h>
#include <stdlib.h>

#include <spam.h>

#include <ala.h>

SPAMatrix
mat_null_basis(SPAMatrix a) {

  SPAMatrix null_basis = NULL;

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrix     zeros  = ala_zeros(a_size.n_rows, 1);
  SPAMatrix     aug    = ala_mat_colcat(a, zeros);

  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);
  size_t *basic_col_nos = malloc(a_size.n_cols * sizeof(size_t));
  size_t  n_basic_cols  = spa_gauss_basic_col_nos(aug, basic_col_nos);
  size_t  n_free_cols   = a_size.n_cols + 1 - n_basic_cols;

  if (n_free_cols == 1)
    goto empty_basis;

  size_t *free_col_nos = malloc(n_free_cols * sizeof(size_t));
  spa_gauss_free_col_nos(free_col_nos, n_free_cols, basic_col_nos);
  SPAMatrix free_cols = ala_new(a_size.n_cols, n_free_cols);
  spa_gauss_part_solns(free_cols, aug, free_col_nos);

  size_t *soln_col_nos = malloc((n_free_cols - 1) * sizeof(size_t));

  for (size_t i = 0; i < (n_free_cols - 1); ++i)
    soln_col_nos[i] = i + 2;

  null_basis = ala_mat_col_extract(free_cols, n_free_cols - 1, soln_col_nos);

  free(soln_col_nos);
  spa_mat_free(&free_cols);
  free(free_col_nos);

empty_basis:
  free(basic_col_nos);

  spa_mat_free(&aug);
  spa_mat_free(&zeros);

  return null_basis;
}

int
main(void) {

  // clang-format off
  SPAMatrix A = ala_new_from((double[]) {
    1, 2, 2, 0, 5,
    2, 4, 3, 1, 8,
    3, 6, 1, 5, 5
  }, 3, 5);
  SPAMatrix v = ala_new_from((double[]) {
    -8,
    1,
    3,
    3,
    0
  }, 5, 1);
  // clang-format on

  puts("A = ");
  spa_mat_print(A);

  puts("v = ");
  spa_mat_print(v);

  puts("Av = ");
  spa_mat_print(ala_mat_mult(A, v));

  SPAMatrix null_basis = mat_null_basis(A);

  SPAMatrix extended         = ala_mat_colcat(v, null_basis);
  SPAMatrix extended_reduced = ala_mat_colcat(v, null_basis);
  spa_gauss_jordan_elim(extended_reduced, spa_mat_prow_exch_max);

  SPAMatrixSize extended_size   = spa_mat_size(extended);
  size_t       *basic_null_cols = malloc(extended_size.n_cols * sizeof(size_t));
  size_t        n_basic_null_cols =
      spa_gauss_basic_col_nos(extended_reduced, basic_null_cols);
  SPAMatrix v_null_basis =
      ala_mat_col_extract(extended, n_basic_null_cols, basic_null_cols);

  puts("basis N(A) = ");
  spa_mat_print(v_null_basis);

  return EXIT_SUCCESS;
}
