#include <stdlib.h>

#include <matrix.h>

int
main(void) {

  double vals[] = {1, 1, 1, 1, 2, 2, 1, 2, 3};
  size_t n_rows = 3;
  size_t n_cols = 3;
  size_t len    = n_rows * n_cols;

  Matrix m = matrix_new(n_rows, n_cols);

  for (size_t i = 0; i < len; i++)
    m->values[i] = vals[i];

  matrix_printf(m);

  matrix_free(m);

  return EXIT_SUCCESS;
}
