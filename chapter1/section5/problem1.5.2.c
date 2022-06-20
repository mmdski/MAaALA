#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  double a_values[] = {1, 1, -10, 1e5};
  double b_values[] = {3, 1e5};

  size_t n_rows = 2;
  size_t n_cols = 2;

  unsigned int precision = 4;

  Matrix a = matrix_from(n_rows, n_cols, a_values);
  Matrix b = matrix_from(n_rows, 1, b_values);
  Matrix x = NULL;

  puts("Ax=b");

  puts("\nA:");
  matrix_printf(a);

  puts("\nb:");
  matrix_printf(b);

  // part (a) precision of 4, with partial pivoting
  if (gauss_solve(a, b, &x, precision, true) < 0)
    return EXIT_FAILURE;
  puts("\nx: (with partial pivoting)");
  matrix_printf(x);

  // part (c) precision of 4, with partial pivoting and row scaling
  Matrix aug = NULL;
  if (gauss_init_augmented(a, b, &aug) < 0)
    return EXIT_FAILURE;
  if (gauss_row_scale(aug, precision) < 0)
    return EXIT_FAILURE;
  puts("\nScaled augmented matrix:");
  matrix_printf(aug);
  if (gauss_reduce(aug, precision, true) < 0)
    return EXIT_FAILURE;
  if (gauss_back_sub(aug, &x, precision) < 0)
    return EXIT_FAILURE;

  puts("\nx: (with partial pivoting and row scaling)");
  matrix_printf(x);

  // part (d) "exact", with partial pivoting
  if (gauss_solve(a, b, &x, 16, true) < 0)
    return EXIT_FAILURE;
  puts("\nx: (\"exact\")");
  matrix_printf(x);

  matrix_free(a);
  matrix_free(b);
  matrix_free(x);

  return EXIT_SUCCESS;
}
