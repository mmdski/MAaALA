#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "gauss.h"
#include "matrix.h"

int
main(void) {

  size_t n_rows     = 2;
  size_t n_cols     = 2;
  double a_values[] = {1, -1, -9, 10};
  double b_values[] = {-2, 12};

  Matrix a = matrix_from(n_rows, n_cols, a_values);
  Matrix b = matrix_from(n_rows, 1, b_values);
  Matrix x = NULL;

  puts("Ax=b");

  puts("\nA:");
  matrix_printf(a);

  puts("\nb:");
  matrix_printf(b);

  // precision of 3, with partial pivoting
  if (gauss_solve(a, b, &x, 3, true) < 0)
    return EXIT_FAILURE;
  puts("\nx: (with partial pivoting)");
  matrix_printf(x);

  // precision of 3, with partial pivoting and scaling
  Matrix aug = NULL;
  if (gauss_init_augmented(a, b, &aug) < 0)
    return EXIT_FAILURE;

  if (gauss_row_scale(aug, 3) < 0)
    return EXIT_FAILURE;

  puts("\nScaled augmented matrix:");
  matrix_printf(aug);

  if (gauss_reduce(aug, 3, true) < 0)
    return EXIT_FAILURE;

  if (gauss_back_sub(aug, &x, 3) < 0)
    return EXIT_FAILURE;

  puts("\nx: (with partial pivoting and row scaling)");
  matrix_printf(x);

  matrix_free(a);
  matrix_free(b);
  matrix_free(x);

  return EXIT_SUCCESS;
}
