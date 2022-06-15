#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>

#include "gauss.h"

int
main(void) {

  double x_vals[] = {1, 1, 1, 1, 1, 1, 3, 3, 1, 1, 2, 3, 1, 3, 3, 3};
  double b_vals[] = {1, 3, 3, 4};
  size_t n_rows   = 4;
  size_t n_cols   = 4;

  Matrix a = matrix_from(n_rows, n_cols, x_vals);
  Matrix b = matrix_from(n_rows, 1, b_vals);
  Matrix x = NULL;

  puts("Ax=b");

  puts("A:");
  matrix_printf(a);

  puts("\nb:");
  matrix_printf(b);

  if (gauss_solve(a, b, &x) < 0)
    return EXIT_FAILURE;

  puts("\nx:");
  matrix_printf(x);

  return EXIT_SUCCESS;
}
