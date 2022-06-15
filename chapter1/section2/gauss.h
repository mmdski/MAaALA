#include <matrix.h>

extern int gauss_back_sub(Matrix gauss_reduced, Matrix *x_ptr);
extern int gauss_init_augmented(Matrix a, Matrix b, Matrix *aug_ptr);
extern int gauss_reduce(Matrix aug);
extern int gauss_solve(Matrix a, Matrix b, Matrix *x_ptr);
