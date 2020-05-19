#include <string.h> // strcpy
#include <app/postfix.h>

postfix*          postfix_new(int max_token)
{
    postfix* new_pf = (postfix*) malloc( sizeof(postfix) );

    new_pf->max_number_of_tokens = max_token;
    new_pf->expression           = (char*) malloc(max_token * 10); // for operators
    new_pf->operand_stack        = stack_new(max_token); 

    return new_pf;
} 

void              postfix_delete(postfix* self)
{
    if (self != NULL) {
        free(self->expression);
        stack_delete(self->operand_stack);
    }
}

void              postfix_set_expression(postfix* self, char* expression)
{
    if (expression != NULL) {
        strcpy(self->expression, expression);
    }
}

bool              postfix_is_enough_to_eval(postfix* self) {
    return stack_size(self->operand_stack) >= 2;
}

int               postfix_evaluated_value(postfix* self)
{
    return self->evaluated_value;
}

void              postfix_show_token_and_stack(postfix* self, char current_token)
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

postfix_error     postfix_evaluate(postfix* self)
{
    int operand, operand1, operand2, calculated;
    char current_token;
    postfix_error eval_result = postfix_error_none;
    int i = 0;

    stack_reset (self->operand_stack);
    
    while ( self->expression[i] != '\0' && eval_result == postfix_error_none) {
        current_token = self->expression[i];

        if (IS_DIGIT(current_token)) {
        // token is an operand. Push it into stack
            operand = (current_token - '0');

            // check expression is too long
            if (stack_full(self->operand_stack)) {
                eval_result = postfix_error_too_long_expression;
                goto EVAL_FAIL_EXIT;
            }

            stack_push (self->operand_stack, operand);
        } else { // The token is an operator
            if ( current_token == '+') {
                if (!postfix_is_enough_to_eval(self)) {
                    eval_result = postfix_error_too_few_operands;
                    goto EVAL_FAIL_EXIT;
                }

                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 + operand2;

                stack_push (self->operand_stack, calculated);
            } else if ( current_token == '-') {
                if (!postfix_is_enough_to_eval(self)) {
                    eval_result = postfix_error_too_few_operands;
                    goto EVAL_FAIL_EXIT;
                }

                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 - operand2;

                stack_push (self->operand_stack, calculated);
            } else if ( current_token == '*') {
                if (!postfix_is_enough_to_eval(self)) {
                    eval_result = postfix_error_too_few_operands;
                    goto EVAL_FAIL_EXIT;
                }

                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                calculated = operand1 * operand2;

                stack_push (self->operand_stack, calculated);
            } else if ( current_token == '/') {
                if (!postfix_is_enough_to_eval(self)) {
                    eval_result = postfix_error_too_few_operands;
                    goto EVAL_FAIL_EXIT;
                }

                operand2 = stack_pop (self->operand_stack);
                operand1 =  stack_pop (self->operand_stack);

                if (!operand2) {
                    eval_result = postfix_error_divide_by_zero;
                    goto EVAL_FAIL_EXIT;
                }

                calculated = operand1 / operand2;

                stack_push (self->operand_stack, calculated);
            } else if ( current_token == '%') {
                if (!postfix_is_enough_to_eval(self)) {
                    eval_result = postfix_error_too_few_operands;
                    goto EVAL_FAIL_EXIT;
                }

                operand2 = stack_pop (self->operand_stack);
                operand1 = stack_pop (self->operand_stack);
                
                if (!operand2) {
                    eval_result = postfix_error_divide_by_zero;
                    goto EVAL_FAIL_EXIT;
                }

                calculated = operand1 % operand2;

                stack_push (self->operand_stack, calculated);
            } else {
                eval_result = postfix_error_unknown_operator;
                goto EVAL_FAIL_EXIT;
            }
        }
        
    EVAL_FAIL_EXIT:
        postfix_show_token_and_stack (self, current_token); // 여기에 출력이 있는 이유는?
        i++;
    } // end of while

    if (stack_size(self->operand_stack) == 1) {
        // At this point, the result is on top of stack
        self->evaluated_value = stack_pop (self->operand_stack);
    } else if (!stack_empty(self->operand_stack)) {
        eval_result = postfix_error_too_many_operands;
    }

    return eval_result;
}