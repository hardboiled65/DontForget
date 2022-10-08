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

void df_linked_list_insert(df_linked_list_t *list, uint32_t index, int32_t val)
{
    df_linked_list_node_t *it = list->first;
    df_linked_list_node_t *new_node = NULL;

    new_node = (df_linked_list_node_t*)malloc(sizeof(df_linked_list_node_t));
    new_node->value = val;

    if (index == 0) {
        new_node->next = list->first;
        list->first = new_node;
    } else {
        for (uint32_t i = 0; i < index - 1; ++i) {
            it = it->next;
        }
        new_node->next = it->next;
        it->next = new_node;
    }

    list->length += 1;
}

int32_t df_linked_list_remove(df_linked_list_t *list, uint32_t index)
{
    df_linked_list_node_t *it = list->first;
    df_linked_list_node_t *next = (it != NULL) ? it->next : NULL;
    int32_t val;

    if (index == 0) {
        val = list->first->value;
        free(list->first);
        list->first = next;
    } else {
        for (uint32_t i = 0; i < index - 1; ++i) {
            it = it->next;
            next = it->next;
        }
        val = next->value;
        it->next = next->next;
        free(next);
    }

    return val;
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
