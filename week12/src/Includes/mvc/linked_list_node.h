#pragma once

#include <mvc/linked_list.h>

typedef struct _lln {
    element             data;
    struct _lln*        next;
} linked_list_node;

linked_list_node* linked_list_node_new();

void              linked_list_node_set_element(linked_list_node* self, element data);
void              linked_list_node_set_next(linked_list_node* self, linked_list_node* next);
element           linked_list_node_element(linked_list_node* self);
linked_list_node* linked_list_node_next   (linked_list_node* self);

void              linked_list_node_delete(linked_list_node* self);

