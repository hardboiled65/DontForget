#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct df_array_t {
    int32_t *values;
    uint32_t length;
} df_array_t;

df_array_t df_array_new(uint32_t length)
{
    df_array_t array;
    array.length = length;

    array.values = (int32_t*)malloc(sizeof(int32_t) * length);

    for (uint32_t i = 0; i < length; ++i) {
        array.values[i] = 0;
    }

    return array;
}

void df_array_set(df_array_t *array, uint32_t index, int32_t value)
{
    array->values[index] = value;
}

void df_array_print(df_array_t *array)
{
    printf("[");
    for (uint32_t i = 0; i < array->length; ++i) {
        printf("%d", array->values[i]);
        if (i < array->length - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

