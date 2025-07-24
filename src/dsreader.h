#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef DSREADER_H
#define DSREADER_H

#define TRAIN 0
#define TEST 1

int read_label(FILE *file, int *labels);
int read_image(FILE *file, u_int8_t *buffer);

int get_label(int type, int *labels);
int get_image(int type, int *buffer);

#endif
