#include <stdbool.h>

#include "matrix.h"

extern int
gauss_back_sub(Matrix g_reduced, Matrix *x_ptr, unsigned int precision);
extern int gauss_init_augmented(Matrix a, Matrix b, Matrix *aug_ptr);
extern int gauss_reduce(Matrix aug, unsigned int precision, bool partial_pivot);
extern int gauss_solve(Matrix       a,
                       Matrix       b,
                       Matrix      *x_ptr,
                       unsigned int precision,
                       bool         partial_pivot);
