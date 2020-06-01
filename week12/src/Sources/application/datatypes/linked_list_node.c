#include <mvc/linked_list_node.h>

#include <stdlib.h>

linked_list_node* linked_list_node_new() {
    linked_list_node* new_node = (linked_list_node*) malloc(sizeof(linked_list_node));

    new_node->next = NULL;

    return new_node;
}

void              linked_list_node_set_element(linked_list_node* self, element data) {
    if (self)
        self->data = data;
}

void              linked_list_node_set_next(linked_list_node* self, linked_list_node* next) {
    if (self)
        self->next = next;
}

element           linked_list_node_element(linked_list_node* self) {
    return self->data;
}

linked_list_node* linked_list_node_next   (linked_list_node* self) {
    return self->next;
}

void              linked_list_node_delete(linked_list_node* self) {
    if (self != NULL) free(self);
}