#include "array.h"

int main(int argc, char *argv[])
{
    df_array_t array = df_array_new(3);

    df_array_set(&array, 0, 10);
    df_array_set(&array, 1, 20);
    df_array_set(&array, 2, 30);

    df_array_print(&array);

    df_array_swap(&array, 0, 2);

    df_array_print(&array);

    return 0;
}
