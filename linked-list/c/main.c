#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct df_linked_list_node_t df_linked_list_node_t;

typedef struct df_linked_list_node_t {
    int32_t value;
    df_linked_list_node_t *next;
} df_linked_list_node_t;

typedef struct df_linked_list_t {
    df_linked_list_node_t *first;
    uint32_t length;
} df_linked_list_t;

df_linked_list_t df_linked_list_new()
{
    df_linked_list_t list;
    list.first = NULL;
    list.length = 0;

    return list;
}

void df_linked_list_push(df_linked_list_t *list, int32_t value)
{
    df_linked_list_node_t *node = (df_linked_list_node_t*)malloc(
        sizeof(df_linked_list_node_t));
    node->value = value;
    node->next = NULL;

    df_linked_list_node_t *last = list->first;
    while (last != NULL && last->next != NULL) {
        last = last->next;
    }

    if (last == NULL) {
        list->first = node;
    } else {
        last->next = node;
    }

    list->length += 1;
}

void df_linked_list_for_each(df_linked_list_t *list,
        void(f)(df_linked_list_node_t*))
{
    df_linked_list_node_t *it = list->first;

    do {
        f(it);
        it = it->next;
    } while (it != NULL);
}

int32_t df_linked_list_at(df_linked_list_t *list, uint32_t index)
{
    df_linked_list_node_t *it = list->first;

    if (it == NULL) {
        return 0;
    }

    for (uint32_t i = 0; i < index; ++i) {
        it = it->next;
    }

    return it->value;
}

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

    return 0;
}
