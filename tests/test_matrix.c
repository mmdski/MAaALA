#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include <matrix.h>

Matrix
test_new(void) {
  Matrix m = matrix_new(3, 3);
  assert(m);
  return m;
}

void
test_set_zeros(Matrix m) {
  size_t n_rows = m->n_rows;
  size_t n_cols = m->n_cols;

  for (size_t i = 1; i <= n_rows; i++)
    for (size_t j = 1; j <= n_cols; j++)
      assert(matrix_set(m, i, j, 0) == 0);
}

void
test_get_zeros(Matrix m) {
  size_t n_rows = m->n_rows;
  size_t n_cols = m->n_cols;
  double value;

  for (size_t i = 1; i <= n_rows; i++) {
    for (size_t j = 1; j <= n_cols; j++) {
      assert(matrix_get(m, i, j, &value) == 0);
      assert(value == 0);
    }
  }
}

int
main(void) {
  Matrix m = test_new();
  test_set_zeros(m);
  test_get_zeros(m);
  assert(matrix_free(m) == 0);
  return EXIT_SUCCESS;
}
