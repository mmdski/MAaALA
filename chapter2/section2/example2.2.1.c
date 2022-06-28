#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 4;
  size_t n_cols     = 5;
  double a_values[] = {1, 2, 1, 3, 3, 2, 4, 0, 4, 4,
                       1, 2, 3, 5, 5, 2, 4, 0, 4, 7};
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
