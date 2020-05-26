#pragma once

#include <mvc/linked_list.h>
#include <mvc/linked_list_node.h>

typedef struct {
    linked_list_node*  head;
    int                size;
} sorted_linked_list;

sorted_linked_list* sorted_linked_list_new();
void                  sorted_linked_list_delete(sorted_linked_list* self);

bool     sorted_linked_list_is_empty   (sorted_linked_list* self);
bool     sorted_linked_list_is_full    (sorted_linked_list* self);
bool     sorted_linked_list_add        (sorted_linked_list* self, element data);
element  sorted_linked_list_min        (sorted_linked_list* self);
element  sorted_linked_list_remove_max (sorted_linked_list* self);
