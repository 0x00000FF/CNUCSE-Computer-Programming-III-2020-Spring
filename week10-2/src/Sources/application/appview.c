#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <mvc/appview.h>
#include <mvc/getchar_direct.h>

void appview_out_new_line ()
{
    printf ("\n");
}

char appview_in_char_directly_from_keyboard ()
{
    printf ("문자를 입력하시오: ");
    char new_char = getchar_direct();

    appview_out_new_line ();

    return new_char;
}

void appview_out_starting_message() {
    puts("<Postfix 수식 계산을 시작합니다>\n");
}

void appview_out_ending_message() {
    puts("\n<Postfix 수식 계산을 종료합니다>\n");
}

void appview_out_error_in_expression() {
    puts("> 수식에 오류가 있습니다.");
}

bool appview_in_postfix_expression(char* expression) {
    printf("> Postfix 수식을 입력하시오: ");
    scanf("%s", expression);
    
    return expression[0] != '$';
}

void appview_out_evaluated_value(int value) {
    printf("계산값 : %d\n", value);
    appview_out_new_line();
}

void appview_out_bottom_of_stack ()
{
    printf ("<Bottom of Stack> ");
}

void appview_out_element (char elem)
{
    printf ("%c ", elem);
}
void appview_out_top_of_stack ()
{
    printf ("<Top of Stack> ");
}