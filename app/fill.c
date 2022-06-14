#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>

int
main(void) {

  double vals[] = {1, 1, 1, 1, 2, 2, 1, 2, 3};
  size_t n_rows = 3;
  size_t n_cols = 3;

  Matrix a = matrix_zeros(2 * n_rows, 2 * n_cols);
  Matrix b = matrix_from(n_rows, n_cols, vals);

  puts("A:");
  matrix_printf(a);

  puts("\nB:");
  matrix_printf(b);

  assert(matrix_fill(a, b, 2, 2) == 0);

  puts("\nA after filling:");
  matrix_printf(a);

  // this should fail
  assert(matrix_fill(a, b, 5, 5) < 0);

  matrix_free(a);
  matrix_free(b);

  return EXIT_SUCCESS;
}
