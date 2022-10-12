#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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

int32_t df_array_at(df_array_t *array, uint32_t index)
{
    assert(index < array->length);

    return array->values[index];
}

void df_array_swap(df_array_t *array, uint32_t index1, uint32_t index2)
{
    assert(index1 < array->length && index2 < array->length);

    int32_t tmp = array->values[index1];
    array->values[index1] = array->values[index2];
    array->values[index2] = tmp;
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

void df_array_free(df_array_t *array)
{
    free(array->values);
}

