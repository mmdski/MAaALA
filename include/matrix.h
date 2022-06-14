#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stddef.h>

struct _Matrix {
  size_t  n_rows;
  size_t  n_cols;
  double *values;
};

typedef struct _Matrix *Matrix;

extern Matrix matrix_new(size_t n_rows, size_t n_cols);
extern int    matrix_free(Matrix m);
extern int    matrix_set(Matrix m, size_t i, size_t j, double value);
extern int    matrix_get(Matrix m, size_t i, size_t j, double *value);

#endif
