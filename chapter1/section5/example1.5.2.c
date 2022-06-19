#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "fl.h"
#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 2;
  size_t n_cols     = 2;
  double a_values[] = {-10, pow(10, 5), 1, 1};
  double b_values[] = {pow(10, 5), 2};

  Matrix a = matrix_from(n_rows, n_cols, a_values);
  Matrix b = matrix_from(n_rows, 1, b_values);
  Matrix x = NULL;

  puts("Ax=b");

  puts("\nA:");
  matrix_printf(a);

  puts("\nb:");
  matrix_printf(b);

  // "exact" solution
  if (gauss_solve(a, b, &x, 15, true) < 0)
    return EXIT_FAILURE;
  puts("\nx: (\"exact\")");
  matrix_printf(x);

  // precision of 3, with partial pivoting
  if (gauss_solve(a, b, &x, 3, true) < 0)
    return EXIT_FAILURE;
  puts("\nx: (with partial pivoting)");
  matrix_printf(x);

  matrix_free(a);
  matrix_free(b);
  matrix_free(x);

  return EXIT_SUCCESS;
}
