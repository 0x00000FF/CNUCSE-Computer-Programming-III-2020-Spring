#pragma once

#include <stdbool.h>

#include <mvc/linked_list_node.h>
#include <mvc/unsorted_linked_list.h>

typedef struct {
    unsorted_linked_list* data;
    int                   capacity;
    int                   size;
} stack;

stack*         stack_new(int stack_max);
void          stack_delete(stack* self);

bool          stack_push(stack* self, element c);
element       stack_pop(stack* self);

element       stack_peek(stack* self);
element       stack_at(stack* self, int pos);

int           stack_size(stack* self);
   
bool          stack_full(stack* self);
bool          stack_empty(stack* self);

// added from 10th lect.
void          stack_reset(stack* self);