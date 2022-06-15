#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>

#include "gauss.h"

int
main(void) {

  double x_vals[] = {0, 4, -3, -1, 7, -5, -1, 8, -6};
  double b_vals[] = {3, 4, 5};
  size_t n_rows   = 3;
  size_t n_cols   = 3;

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

  puts("\nAx=");
  if (matrix_mat_mult(a, x, &b) < 0)
    return EXIT_FAILURE;

  matrix_printf(b);

  return EXIT_SUCCESS;
}
