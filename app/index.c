#include <stdio.h>
#include <stdlib.h>

#define INDEX(n_cols, row, col) (row - 1) * n_cols + (col - 1)

int
main(void) {

  size_t m = 10;
  size_t n = 5;

  for (size_t i = 1; i <= m; i++) {
    for (size_t j = 1; j <= n; j++) {
      printf("%4lu", INDEX(n, i, j));
    }
    printf("\n");
  }
  return EXIT_SUCCESS;
}
