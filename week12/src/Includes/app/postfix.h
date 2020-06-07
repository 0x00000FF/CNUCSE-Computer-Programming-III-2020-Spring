#pragma once

#include <malloc.h>
#include <stdbool.h>
#include <app/stack.h>
#include <app/macros.h>

typedef enum {
    postfix_error_none,
    postfix_error_too_long_expression,
    postfix_error_too_many_operands,
    postfix_error_too_few_operands,
    postfix_error_unknown_operator,
    postfix_error_divide_by_zero
} postfix_error;

typedef struct {
    int     max_number_of_tokens;
    char*   expression;
    int     evaluated_value;
    stack*  operand_stack;
} postfix;

postfix*          postfix_new (int max_token);
void              postfix_delete(postfix* self);

void              postfix_set_expression(postfix* self, char* expression);
int               postfix_evaluated_value(postfix* self);
postfix_error     postfix_evaluate(postfix* self);
