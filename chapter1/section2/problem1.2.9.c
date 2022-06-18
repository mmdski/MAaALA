#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>

#include "gauss.h"

int
main(void) {

  double x_vals[] = {-1, 3, -2, -1, 4, -3, -1, 5, -4};
  double b_vals[] = {4, 5, 6};
  size_t n_rows   = 3;
  size_t n_cols   = 3;

  Matrix a   = matrix_from(n_rows, n_cols, x_vals);
  Matrix b   = matrix_from(n_rows, 1, b_vals);
  Matrix aug = NULL;
  gauss_init_augmented(a, b, &aug);
  gauss_reduce(aug);

  puts("Ax=b");

  puts("A:");
  matrix_printf(a);

  puts("\nb:");
  matrix_printf(b);

  puts("\nReduced augmented matrix:");
  matrix_printf(aug);

  matrix_free(a);
  matrix_free(b);
  matrix_free(aug);

  return EXIT_SUCCESS;
}
