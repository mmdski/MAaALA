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
  SPAMatrix A = ala_new_from((double[]){
      -2, 1, 1,
      -4, 2, 2,
       0, 0, 0
    }, 3, 3);
  SPAMatrix B = ala_new_from((double[]){
       1, 3, 1, -4,
      -1, -3, 1, 0,
       2, 6, 2, -8
      }, 3, 4);
  // clang-format on

  SPAMatrix E_B = ala_copy(B);
  spa_gauss_jordan_elim(E_B, spa_mat_prow_exch_max);
  size_t   *b_basic_col_nos = malloc(4 * sizeof(size_t));
  size_t    n_b_basic_cols  = spa_gauss_basic_col_nos(E_B, b_basic_col_nos);
  SPAMatrix b_range_basis =
      ala_mat_col_extract(B, n_b_basic_cols, b_basic_col_nos);

  puts("X = ");
  spa_mat_print(b_range_basis);

  SPAMatrix AX = ala_mat_mult(A, b_range_basis);

  SPAMatrix ax_null_basis = mat_null_basis(AX);

  puts("V = ");
  spa_mat_print(ax_null_basis);

  puts("XV = ");
  spa_mat_print(ala_mat_mult(b_range_basis, ax_null_basis));

  return EXIT_SUCCESS;
}
