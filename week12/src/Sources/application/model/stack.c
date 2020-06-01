#include <stdlib.h>

#include <app/stack.h>

stack*      stack_new(int stack_max)
{
    stack* new_stack = (stack*) malloc(sizeof(stack));
    
    new_stack->data     = (unsorted_linked_list*)malloc( sizeof(unsorted_linked_list) );
    new_stack->capacity = stack_max;
    new_stack->size     = 0;

    return new_stack;
}

void       stack_delete(stack* self)
{
    free(self->data);
    free(self);
}

bool       stack_push(stack* self, element c)
{
    if (stack_full(self)) return false;

    unsorted_linked_list_add(self->data, c);
    self->size++;

    return true;
}

int       stack_pop(stack* self)
{
    if (stack_empty(self)) return false;

    int pop = unsorted_linked_list_pop_first(self->data);
    self->size--;

    return pop;
}

element       stack_peek(stack* self)
{
    linked_list_node* data_head = unsorted_linked_list_head(self->data);
    return linked_list_node_element(data_head);
}

element       stack_at(stack* self, int pos)
{
    if (pos >= self->size) return -1;

    linked_list_node* node = unsorted_linked_list_at(self->data, pos);
    
    if (node) {
        return linked_list_node_element(node);
    } else {
        return -1;
    }
}

int        stack_size(stack* self)
{
    return self->size;
}

bool       stack_full(stack* self)
{
    return self->size == self->capacity;
}

bool       stack_empty(stack* self)
{
    return self->size == 0;
}

void       stack_reset(stack* self)
{
    unsorted_linked_list_delete(self->data);

    self->data     = (unsorted_linked_list*)malloc( sizeof(unsorted_linked_list) );
    self->size     = 0;    
}