#include <mvc/unsorted_linked_list.h>

#include <stdlib.h>

unsorted_linked_list* unsorted_linked_list_new() {
    unsorted_linked_list* list = (unsorted_linked_list*) malloc(sizeof(unsorted_linked_list));

    if (list == NULL) {
        return (unsorted_linked_list*)NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

void                  unsorted_linked_list_delete(unsorted_linked_list* self) {
    if (!self) return;

    // cleanup remaining nodes
    while (self->head != NULL) {
        linked_list_node* next = linked_list_node_next(self->head);
        linked_list_node_delete(self->head);

        self->head = next;
    }

    free(self);
}

linked_list_node*  unsorted_linked_list_head(unsorted_linked_list* self) {
    return self->head;
}

linked_list_node*  unsorted_linked_list_at(unsorted_linked_list* self, int pos) {
    if (pos >= self->size) return NULL;

    int r_pos              = self->size - pos;
    linked_list_node* node = self->head;

    for (int i = 0; i < r_pos || node != NULL; ++i) {
        node = linked_list_node_next(node);
    }

    return node;
}

bool     unsorted_linked_list_is_empty   (unsorted_linked_list* self) {
    return (self->size == 0);
}

bool     unsorted_linked_list_is_full    (unsorted_linked_list* self) {
    if (!self) return false;
    // by specification
    return false;
}

bool     unsorted_linked_list_add        (unsorted_linked_list* self, element data) {
    if (unsorted_linked_list_is_full(self)) {
        return false; // however this cannot be executed
    } else { // push element in front of head
        linked_list_node* new_node = linked_list_node_new();

        linked_list_node_set_element(new_node, data);
        linked_list_node_set_next(new_node, self->head);

        self->head = new_node;
        self->size++;

        return true;
    }
}

element  unsorted_linked_list_min        (unsorted_linked_list* self) {
    if (unsorted_linked_list_is_empty(self)) {
        return ELEMENT_DOES_NOT_EXIST; // by specification
    } else {
        int               min     = linked_list_node_element(self->head);
        linked_list_node* current = linked_list_node_next(self->head);

        while (current != NULL) {
            if (linked_list_node_element(current) < min) {
                min = linked_list_node_element(current);
            }

            current = linked_list_node_next(current);
        }  

        return min;
    }
}

element  unsorted_linked_list_pop_first  (unsorted_linked_list* self) {
    linked_list_node* head = self->head;
    int               val  = linked_list_node_element(head);
    
    self->head = linked_list_node_next(self->head);
    free(head);

    return val;
}

element  unsorted_linked_list_remove_max (unsorted_linked_list* self) {
    if (unsorted_linked_list_is_empty(self)) {
        return ELEMENT_DOES_NOT_EXIST; // by specification
    } else {
        int               max     = linked_list_node_element(self->head);
        
        linked_list_node* current = self->head;
        linked_list_node* next    = linked_list_node_next(self->head);
        linked_list_node* prev    = NULL;

        while ( next != NULL ) {
            if (linked_list_node_element(next) > max) {
                max  = linked_list_node_element(next);
                prev = current;
            }

            current = next;
            next    = linked_list_node_next(next); 
        }

        linked_list_node* removed = NULL;

        if (prev == NULL) {
            removed    = self->head;
            self->head = linked_list_node_next(self->head);
        } else {
            removed = linked_list_node_next(prev);
            linked_list_node_set_next(prev, linked_list_node_next(removed));
        }

        self->size--;
        linked_list_node_delete(removed);

        return max;
    }
}
