#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 3;
  size_t n_cols     = 5;
  double a_values[] = {2, -4, -8, 6, 3, 0, 1, 3, 2, 3, 3, -2, 0, 0, 8};
  Matrix a          = matrix_from(n_rows, n_cols, a_values);

  puts("\nA=");
  matrix_printf(a);

  if (gauss_jordan_reduce(a) < 0) {
    fputs("Gauss reduction failed\n", stderr);

    return EXIT_FAILURE;
  }

  puts("\nA (reduced):");
  matrix_printf(a);

  return EXIT_SUCCESS;
}
