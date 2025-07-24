#include "dsreader.h"

#include <stdint.h>

#define TRAIN_LABEL_FILE "../input/train-labels.idx1-ubyte"
#define TRAIN_IMAGE_FILE "../input/train-images.idx3-ubyte"
#define TEST_LABEL_FILE "../input/t10k-labels.idx1-ubyte"
#define TEST_IMAGE_FILE "../input/t10k-images.idx3-ubyte"

int read_label(FILE *file, int *labels)
{
    int magic;
    size_t size;


}
