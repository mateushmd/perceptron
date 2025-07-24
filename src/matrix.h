#include <stdlib.h>

#ifndef MATRIX_H
#define MATRIX_H

#define MAT_IDX(row, col, num_cols) ((row) * (num_cols) + (col))

void mat_add(float *a, float *b, float *c, size_t n);

void mat_mult(float *a, float *b, float *c, size_t n);

#endif
