#include <string.h> // strcpy
#include <app/postfix.h>

postfix* postfix_new(int max_token)
{
    postfix* new_pf = (postfix*) malloc( sizeof(postfix) );

    new_pf->max_number_of_tokens = max_token;
    new_pf->expression           = VECTOR_NEW(char)(max_token);
    new_pf->operand_stack        = stack_new(max_token); 

    return new_pf;
} 

void     postfix_delete(postfix* self)
{
    if (self != NULL) {
        VECTOR_DELETE(element)(self->expression);
        stack_delete(self->operand_stack);
    }
}

void     postfix_set_expression(postfix* self, char* expression)
{
    if (expression != NULL)
        strcpy(self->expression, expression);
}

void     postfix_evaluated_value(postfix* self)
{
    return self->evaluated_value;
}

bool     postfix_evaluate(postfix* self)
{

    self->evaluated_value = stack_pop(self->operand_stack);
    return true;
}