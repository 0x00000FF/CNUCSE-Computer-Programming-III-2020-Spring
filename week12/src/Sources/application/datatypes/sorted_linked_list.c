#include <mvc/sorted_linked_list.h>

#include <stdlib.h>

sorted_linked_list* sorted_linked_list_new() {
    sorted_linked_list* list = (sorted_linked_list*) malloc(sizeof(sorted_linked_list));

    if (list == NULL) {
        return (sorted_linked_list*)NULL;
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

void                  sorted_linked_list_delete(sorted_linked_list* self) {
    if (!self) return;

    // cleanup remaining nodes
    while (self->head != NULL) {
        linked_list_node* next = linked_list_node_next(self->head);
        linked_list_node_delete(self->head);

        self->head = next;
    }

    free(self);
}

bool     sorted_linked_list_is_empty   (sorted_linked_list* self) {
    return (self->size == 0);
}

bool     sorted_linked_list_is_full    (sorted_linked_list* self) {
    if (!self) return false;
    // by specification
    return false;
}

bool     sorted_linked_list_add        (sorted_linked_list* self, element data) {
    if (sorted_linked_list_is_full(self)) {
        return false; // however this cannot be executed
    } else { // push element in front of head
        linked_list_node* new_node = linked_list_node_new();

        linked_list_node_set_element(new_node, data);

        if ( sorted_linked_list_is_empty (self) ) { // 이 검사는 하지 않아도, 다음 else 부분 코드로 정상적인 처리 가능.
        self->head = new_node;
        }
        else {
            linked_list_node* previous_node = NULL;
            linked_list_node* current_node = self->head;

            while ( current_node != NULL && linked_list_node_element(current_node) < data ) { // 삽입 위치를 찾는다
                previous_node = current_node;
                current_node = linked_list_node_next (current_node);
            }

            if ( previous_node == NULL ) { // 연결 체인의 맨 앞에 삽입
                linked_list_node_set_next (new_node, self->head);
                self->head = new_node;
            }
            else { // previous_node 다음에 삽입
                linked_list_node_set_next (new_node, current_node);
                linked_list_node_set_next (previous_node, new_node);
            }
        }

        self->size++;
        return true;

    }
}

element  sorted_linked_list_min        (sorted_linked_list* self) {
    if (sorted_linked_list_is_empty(self)) {
        return ELEMENT_DOES_NOT_EXIST; // by specification
    } else {
        // first element of sorted linked list is minimum
        return linked_list_node_element(self->head);
    }
}

element  sorted_linked_list_remove_max (sorted_linked_list* self) {
    if (sorted_linked_list_is_empty(self)) {
        return ELEMENT_DOES_NOT_EXIST; // by specification
    } else {
        linked_list_node* curr    = self->head;
        linked_list_node* next    = linked_list_node_next(self->head);
        linked_list_node* prev    = NULL;

        // traverse until tail
        while ( next != NULL ) {
            prev    = curr;
            curr    = next;
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

        int max = linked_list_node_element(removed);
        linked_list_node_delete(removed);

        return max;
    }
}
