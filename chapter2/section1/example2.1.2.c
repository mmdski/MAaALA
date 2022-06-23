#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 3;
  size_t n_cols     = 4;
  double a_values[] = {1, 2, 1, 1, 2, 4, 2, 2, 3, 6, 3, 4};

  Matrix a = matrix_from(n_rows, n_cols, a_values);

  puts("\nA=");
  matrix_printf(a);

  if (gauss_reduce(a, n_cols) < 0) {
    fputs("Gauss reduction failed\n", stderr);

    return EXIT_FAILURE;
  }

  puts("\nA (reduced):");
  matrix_printf(a);

  return EXIT_SUCCESS;
}
