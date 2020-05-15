#pragma once

#include <malloc.h>
#include <stdbool.h>
#include <app/stack.h>

typedef struct {
    int    max_number_of_tokens;
    char*  expression;
    int    evaluated_value;
    stack  operand_stack;
} postfix;

postfix* postfix_new (int max_token);
void     postfix_delete(postfix* self);

void     postfix_set_expression(postfix* self, char* expression);
void     postfix_evaluated_value(postfix* self);
bool     postfix_evaluate(postfix* self);
