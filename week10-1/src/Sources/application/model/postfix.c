#include <string.h> // strcpy
#include <app/postfix.h>

postfix* postfix_new(int max_token)
{
    postfix* new_pf = (postfix*) malloc( sizeof(postfix) );

    new_pf->max_number_of_tokens = max_token;
    new_pf->expression           = (char*) malloc(max_token);
    new_pf->operand_stack        = stack_new(max_token); 

    return new_pf;
} 

void     postfix_delete(postfix* self)
{
    if (self != NULL) {
        free(self->expression);
        stack_delete(self->operand_stack);
    }
}

void     postfix_set_expression(postfix* self, char* expression)
{
    if (expression != NULL)
        strcpy(self->expression, expression);
}

int      postfix_evaluated_value(postfix* self)
{
    return self->evaluated_value;
}

void     postfix_show_token_and_stack(postfix* self, char current_token)
{
    printf("%c : <Bottom> ", current_token);

    for (int i = 0; i < stack_size(self->operand_stack); ++i) {
        printf("%d ", stack_at(self->operand_stack, i));
    }

    printf("<Top>\n");
}


// problem: if postfix == null?
//          if stack is not enough?
//          if expression is wrong?

bool     postfix_evaluate(postfix* self)
{
    int operand, operand1, operand2, calculated;
    char currentToken;
    int i = 0;
    stack_reset (self->operand_stack);
    while ( self->expression[i] != '\0') {
        currentToken = self->expression[i];
        if (currentToken >='0' && currentToken <= '9') {
        // token is an operand. Push it into stack
        operand = (currentToken - '0');
        stack_push (self->operand_stack, operand);
        } else { // The token is an operator
            if ( currentToken == '+') {
                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 + operand2;
                stack_push (self->operand_stack, calculated);
            } else if ( currentToken == '-') {
                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 - operand2;
                stack_push (self->operand_stack, calculated);
            } else if ( currentToken == '*') {
                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 * operand2;
                stack_push (self->operand_stack, calculated);
            } else if ( currentToken == '/') {
                operand2 = stack_pop (self->operand_stack);
                operand1 =  stack_pop (self->operand_stack);
                calculated = operand1 / operand2;
                stack_push (self->operand_stack, calculated);
            } else if ( currentToken == '%') {
                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 % operand2;
                stack_push (self->operand_stack, calculated);
            }
        }
        postfix_show_token_and_stack (self, currentToken); // 여기에 출력이 있는 이유는?
        i++;
    } // end of while

    // At this point, the result is on top of stack
    self->evaluated_value = stack_pop (self->operand_stack);
    return true;
}