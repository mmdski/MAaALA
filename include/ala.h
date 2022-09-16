#ifndef ALA_H_
#define ALA_H_

#include <spam.h>

extern SPAMatrix ala_new(size_t m, size_t n);
extern SPAMatrix ala_new_like(SPAMatrix a);
extern SPAMatrix ala_new_from(double *values, size_t m, size_t n);
extern SPAMatrix ala_eye(size_t m);
extern SPAMatrix ala_zeros(size_t m, size_t n);
extern SPAMatrix ala_copy(SPAMatrix a);
extern SPAMatrix ala_mat_colcat(SPAMatrix a, SPAMatrix b);
extern SPAMatrix ala_mat_rowcat(SPAMatrix a, SPAMatrix b);
extern SPAMatrix
ala_mat_col_extract(SPAMatrix a, size_t n_cols, size_t *col_nos);
extern SPAMatrix
ala_mat_row_extract(SPAMatrix a, size_t n_rows, size_t *row_nos);
extern SPAMatrix ala_mat_transpose(SPAMatrix a);
extern SPAMatrix ala_mat_mult(SPAMatrix a, SPAMatrix b);
extern SPAMatrix ala_mat_inv(SPAMatrix a);

#endif
