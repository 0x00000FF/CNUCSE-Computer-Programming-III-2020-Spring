#pragma once

#include <stdbool.h>
#include <app/vector_char.h>

#define  DEFAULT_STACK_CAPACITY  100

typedef VECTOR(element)* stack;

stack         stack_new();
void          stack_delete(stack self);

bool          stack_push(stack self, element c);
element       stack_pop(stack self);

element       stack_peek(stack self);
element       stack_at(stack self, int pos);

int           stack_size(stack self);
   
bool          stack_full(stack self);
bool          stack_empty(stack self);

