#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stddef.h>

struct _Matrix {
  size_t n_rows;
  size_t n_cols;
  double values[];
};

typedef struct _Matrix *Matrix;

/* matrix creation */

extern Matrix matrix_new(size_t n_rows, size_t n_cols);
extern Matrix matrix_new_like(Matrix m);
extern Matrix matrix_from(size_t n_rows, size_t n_cols, double *values);
extern Matrix matrix_zeros(size_t n_rows, size_t n_cols);
extern int    matrix_free(Matrix m);

/* matrix get/set */

extern int matrix_set(Matrix m, size_t i, size_t j, double value);
extern int matrix_get(Matrix m, size_t i, size_t j, double *value);
extern int matrix_fill(Matrix a, Matrix b, size_t i, size_t j);

extern int matrix_printf(Matrix m);

/* matrix row operations */

extern int matrix_row_mult_const(Matrix m, size_t i, double c);
extern int matrix_row_add_row(Matrix m, size_t i1, size_t i2, double c);

#endif
