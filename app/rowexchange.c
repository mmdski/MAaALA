#include <stdlib.h>

#include <matrix.h>

int
main(void) {

  Matrix eye = matrix_eye(3);
  matrix_printf(eye);
  matrix_row_exchange(eye, 1, 2);
  matrix_printf(eye);
  return EXIT_SUCCESS;
}
