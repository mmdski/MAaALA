#include <assert.h>
#include <stdlib.h>

#include <spam.h>

SPAMatrix
ala_new(size_t m, size_t n) {

  SPAMatrix a = NULL;
  spa_mat_new(&a, m, n);
  return a;
}

SPAMatrix
ala_new_like(SPAMatrix a) {

  SPAMatrix b = NULL;
  spa_mat_new_like(&b, a);

  return b;
}

SPAMatrix
ala_new_from(double *values, size_t m, size_t n) {
  assert(values);
  assert(m > 0 && n > 0);

  SPAMatrix a = NULL;
  spa_mat_new_arr(&a, values, m, n);

  return a;
}

SPAMatrix
ala_eye(size_t m) {

  SPAMatrix eye = NULL;
  spa_mat_new_eye(&eye, m);

  return eye;
}

SPAMatrix
ala_zeros(size_t m, size_t n) {
  SPAMatrix zeros = NULL;
  spa_mat_new_zeros(&zeros, m, n);
  return zeros;
}

SPAMatrix
ala_copy(SPAMatrix a) {
  SPAMatrix b = NULL;
  spa_mat_new_copy(&b, a);
  return b;
}

SPAMatrix
ala_mat_transpose(SPAMatrix a) {
  assert(a);

  SPAMatrixSize a_size = spa_mat_size(a);

  SPAMatrix a_t = NULL;
  spa_mat_new(&a_t, a_size.n_cols, a_size.n_rows);

  spa_mat_transpose(a_t, a);

  return a_t;
}

SPAMatrix
ala_mat_colcat(SPAMatrix a, SPAMatrix b) {

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrixSize b_size = spa_mat_size(b);

  size_t m = a_size.n_rows;
  size_t n = a_size.n_cols + b_size.n_cols;

  SPAMatrix cat_mat = NULL;
  spa_mat_new(&cat_mat, m, n);
  spa_mat_colcat(cat_mat, a, b);

  return cat_mat;
}

SPAMatrix
ala_mat_rowcat(SPAMatrix a, SPAMatrix b) {

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrixSize b_size = spa_mat_size(b);

  size_t m = a_size.n_rows + b_size.n_rows;
  size_t n = a_size.n_cols;

  SPAMatrix cat_mat = NULL;
  spa_mat_new(&cat_mat, m, n);
  spa_mat_rowcat(cat_mat, a, b);

  return cat_mat;
}

SPAMatrix
ala_mat_col_extract(SPAMatrix a, size_t n_cols, size_t *col_nos) {

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrix     cols   = NULL;
  spa_mat_new(&cols, a_size.n_rows, n_cols);
  spa_mat_col_extract(cols, a, col_nos);
  return cols;
}

SPAMatrix
ala_mat_row_extract(SPAMatrix a, size_t n_rows, size_t *row_nos) {

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrix     rows   = NULL;
  spa_mat_new(&rows, n_rows, a_size.n_cols);
  spa_mat_row_extract(rows, a, row_nos);
  return rows;
}

SPAMatrix
ala_mat_mult(SPAMatrix a, SPAMatrix b) {
  assert(a && b);

  SPAMatrixSize a_size = spa_mat_size(a);
  SPAMatrixSize b_size = spa_mat_size(b);
  assert(a_size.n_cols == b_size.n_rows);

  SPAMatrix prod = NULL;
  spa_mat_new(&prod, a_size.n_rows, b_size.n_cols);
  spa_mat_matrix_mult(prod, a, b);

  return prod;
}

SPAMatrix
ala_mat_inv(SPAMatrix a) {

  assert(a);

  SPAMatrixSize a_size = spa_mat_size(a);
  assert(a_size.n_rows == a_size.n_cols);

  SPAMatrix a_inv = NULL;

  SPAMatrix eye = NULL;
  spa_mat_new_eye(&eye, a_size.n_rows);

  SPAMatrix aug = NULL;
  spa_mat_new_colcat(&aug, a, eye);

  spa_gauss_jordan_elim(aug, spa_mat_prow_exch_max);

  size_t *basic_col_nos = malloc(2 * a_size.n_cols * sizeof(size_t));
  size_t  n_basic_cols  = spa_gauss_basic_col_nos(aug, basic_col_nos);

  if (n_basic_cols != a_size.n_cols)
    goto no_inv;

  size_t last_basic_col_no = 0;
  size_t basic_col_index   = 0;
  size_t basic_col_no      = basic_col_nos[basic_col_index];
  while (basic_col_no != 0) {
    last_basic_col_no = basic_col_no;
    basic_col_no      = basic_col_nos[basic_col_index++];
  }

  assert(last_basic_col_no);
  if (last_basic_col_no != a_size.n_cols)
    goto no_inv;

  SPAMatrixSize aug_size     = spa_mat_size(aug);
  size_t        n_free_cols  = aug_size.n_cols - n_basic_cols;
  size_t       *free_col_nos = malloc(n_free_cols * sizeof(size_t));
  spa_gauss_free_col_nos(free_col_nos, n_free_cols, basic_col_nos);
  spa_mat_new_like(&a_inv, a);
  spa_mat_col_extract(a_inv, aug, free_col_nos);

  free(free_col_nos);

no_inv:
  free(basic_col_nos);

  spa_mat_free(&aug);
  spa_mat_free(&eye);

  return a_inv;
}
