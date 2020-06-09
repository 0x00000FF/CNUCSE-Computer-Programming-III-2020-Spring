#pragma once

#include <mvc/linked_list.h>
#include <mvc/linked_list_node.h>

typedef struct {
    linked_list_node*  head;
    int                size;
} unsorted_linked_list;

unsorted_linked_list* unsorted_linked_list_new();
void                  unsorted_linked_list_delete(unsorted_linked_list* self);

bool              unsorted_linked_list_is_empty   (unsorted_linked_list* self);
bool              unsorted_linked_list_is_full    (unsorted_linked_list* self);
bool              unsorted_linked_list_add        (unsorted_linked_list* self, element data);
element           unsorted_linked_list_min        (unsorted_linked_list* self);
linked_list_node* unsorted_linked_list_at         (unsorted_linked_list* self, int order);
element           unsorted_linked_list_remove_max (unsorted_linked_list* self);
element           unsorted_linked_list_remove_head(unsorted_linked_list* self);
linked_list_node* unsorted_linked_list_head       (unsorted_linked_list* self);