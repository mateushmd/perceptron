#include "matrix.h"

void mat_add(float *a, float *b, float *c, size_t n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            c[MAT_IDX(i, j, n)] = a[MAT_IDX(i, j, n)] + b[MAT_IDX(i, j, n)];
}

void mat_mult(float *a, float *b, float *c, size_t n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                c[MAT_IDX(i, j, n)] += a[MAT_IDX(i, k, n)] * b[MAT_IDX(j, k ,n)];
}
