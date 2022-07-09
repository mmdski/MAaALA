#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 6;
  size_t n_cols     = 7;
  double a_values[] = {2, 1, 1, 3,  0, 4, 1, 4, 2, 4, 4,  1, 5,  5,
                       2, 1, 3, 1,  0, 4, 3, 6, 3, 4, 8,  1, 9,  5,
                       0, 0, 3, -3, 0, 0, 3, 8, 4, 2, 14, 1, 13, 3};
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
