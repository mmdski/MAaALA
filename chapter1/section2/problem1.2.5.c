#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <matrix.h>

#include "gauss.h"

int
main(void) {

  double a_vals[] = {4, -8, 5, 4, -7, 4, 3, -4, 2};
  size_t n_rows   = 3;
  size_t n_cols   = 3;

  Matrix a = matrix_from(n_rows, n_cols, a_vals);
  Matrix b = matrix_eye(n_rows);
  Matrix x = NULL;

  puts("AX=B");

  puts("A:");
  matrix_printf(a);

  puts("\nB:");
  matrix_printf(b);

  if (gauss_solve(a, b, &x) < 0)
    return EXIT_FAILURE;

  puts("\nX:");
  matrix_printf(x);

  puts("\nAX=");
  if (matrix_mat_mult(a, x, &b) < 0)
    return EXIT_FAILURE;

  matrix_printf(b);

  return EXIT_SUCCESS;
}
