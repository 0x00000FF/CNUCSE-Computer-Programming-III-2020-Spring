#include <app/stack.h>

stack      stack_new(int stack_max)
{
    return VECTOR_NEW(element)(stack_max);
}

void       stack_delete(stack self)
{
    VECTOR_DELETE(element)(self);
}

bool       stack_push(stack self, element c)
{
    if (stack_full(self)) return false;

    VECTOR_PUSH_BACK(element)(self, c);
    return true;
}

char      stack_pop(stack self)
{
    if (stack_empty(self)) return false;

    element pop = VECTOR_BACK(element)(self);
    VECTOR_POP_BACK(element)(self);

    return pop;
}

element       stack_peek(stack self)
{
    return VECTOR_BACK(element)(self);
}

element       stack_at(stack self, int pos)
{
    if (pos >= VECTOR_SIZE(element)(self)) return -1;

    return VECTOR_AT(element)(self, pos);
}

int        stack_size(stack self)
{
    return VECTOR_SIZE(element)(self);
}

bool       stack_full(stack self)
{
    return VECTOR_SIZE(element)(self) == VECTOR_MAX_SIZE(element)(self);
}

bool       stack_empty(stack self)
{
    return VECTOR_SIZE(element)(self) == 0;
}