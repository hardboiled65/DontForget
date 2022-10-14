#include "../../array/c/array.h"

uint32_t binary_search(df_array_t *array, int32_t value)
{
    return 0;
}

int main(int argc, char *argv[])
{
    df_array_t array = df_array_new(6);

    // Set array in sorted state.
    df_array_set(&array, 0, 2);
    df_array_set(&array, 1, 4);
    df_array_set(&array, 2, 6);
    df_array_set(&array, 3, 8);
    df_array_set(&array, 4, 10);
    df_array_set(&array, 5, 12);

    // Search.
    uint32_t index = binary_search(&array, 10);
    assert(index == 4);

    df_array_free(&array);

    return 0;
}
