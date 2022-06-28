#ifndef __GAUSS_H__
#define __GAUSS_H__

#include <stdbool.h>

#include "matrix.h"

extern int gauss_back_sub(Matrix g_reduced, Matrix *x_ptr);
extern int gauss_init_augmented(Matrix a, Matrix b, Matrix *aug_ptr);
extern int gauss_reduce(Matrix a);
extern int gauss_jordan_reduce(Matrix a);
extern int gauss_solve(Matrix a, Matrix b, Matrix *x_ptr);
extern int gauss_row_scale(Matrix aug);

#endif
