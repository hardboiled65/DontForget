#include <stdio.h>

#include "linked-list.h"

static void print_function(df_linked_list_node_t *node)
{
    printf("%d>", node->value);
    if (node->next == NULL) {
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    df_linked_list_t list = df_linked_list_new();

    // Push values.
    df_linked_list_push(&list, 2);
    df_linked_list_push(&list, 4);
    df_linked_list_push(&list, 6);
    df_linked_list_push(&list, 8);
    df_linked_list_push(&list, 10);
    df_linked_list_push(&list, 12);

    // For each print.
    df_linked_list_for_each(&list, print_function);

    // At.
    int32_t val_at_3 = df_linked_list_at(&list, 3);
    assert(val_at_3 == 8);

    // Insert values.
    df_linked_list_insert(&list, 0, 100);
    df_linked_list_insert(&list, 2, 200);
    df_linked_list_for_each(&list, print_function);

    // Remove values.
    int32_t removed = df_linked_list_remove(&list, 1);
    assert(removed == 2);
    removed = df_linked_list_remove(&list, 6);
    assert(removed == 12);
    df_linked_list_for_each(&list, print_function);

    return 0;
}
