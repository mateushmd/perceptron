#include <stdint.h>
#include <stdio.h>

#define MAGIC 2049

size_t fread_big_endian(void *restrict ptr, size_t size, size_t n,
                        FILE *restrict stream);

int main(void)
{
    FILE *labels_file = fopen("../input/t10k-labels.idx1-ubyte", "rb");

    if (labels_file == NULL)
    {
        perror("Failed to open file");
        return 1;
    }

    int magic = 1, size = 1;

    if (fread_big_endian(&magic, sizeof(int), 1, labels_file) != 1)
    {
        printf("Failed to read file\n");
        fclose(labels_file);
        return 1;
    }
    if (fread_big_endian(&size, sizeof(int), 1, labels_file) != 1)
    {
        printf("Failed to read file\n");
        fclose(labels_file);
        return 1;
    }

    if (magic != MAGIC)
    {
        printf("Magic number mismatch, expected 2049, got %d\n", magic);
        fclose(labels_file);
        return 1;
    }

    uint8_t labels[size];

    for (int i = 0; i < size; i++)
    {
        if (fread(&labels[i], sizeof(uint8_t), 1, labels_file) != 1)
        {
            printf("Failed to read label %d", i + 1);
            fclose(labels_file);
            return 1;
        }
        printf("label %d: %d\n", i, labels[i]);
    }

    printf("successfuly read all labels!\n");

    fclose(labels_file);

    return 0;
}

size_t fread_big_endian(void *restrict ptr, size_t size, size_t n,
                        FILE *restrict stream)
{
    if (size == 0 || n == 0)
        return 0;

    size_t read_bytes = 0;
    uint8_t *byte = ((uint8_t *)ptr) + size - 1;

    for (int i = 0; i < n; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            fread(byte, sizeof(uint8_t), 1, stream);

            if (feof(stream))
                return read_bytes / size;
            if (ferror(stream))
            {
                perror("Read error");
                return read_bytes / size;
            }

            byte--;
            read_bytes++;
        }
        byte += (size * 2) - 1;
    }

    return read_bytes / size;
}
