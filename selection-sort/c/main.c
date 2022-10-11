#include "../../array/c/array.h"

void selection_sort(df_array_t *array)
{
    for (uint32_t i = 0; i < array->length; ++i) {
        int32_t min_value = df_array_at(array, i);
        uint32_t min_index = 0;

        for (uint32_t j = i + 1; j < array->length; ++j) {
            // Find minimal value.
            if (min_value > df_array_at(array, j)) {
                min_value = df_array_at(array, j);
                min_index = j;
            }
        }

        // Swap if less.
        if (df_array_at(array, i) > min_value) {
            df_array_swap(array, i, min_index);
        }
    }
}

int main(int argc, char *argv[])
{
    df_array_t array = df_array_new(5);

    df_array_set(&array, 0, 64);
    df_array_set(&array, 1, 25);
    df_array_set(&array, 2, 12);
    df_array_set(&array, 3, 22);
    df_array_set(&array, 4, 11);

    df_array_print(&array);

    // Do sorting.
    selection_sort(&array);

    df_array_print(&array);

    // Free.
    df_array_free(&array);

    return 0;
}
