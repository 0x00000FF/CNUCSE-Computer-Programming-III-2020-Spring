#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <mvc/appview.h>
#include <mvc/getchar_direct.h>

char appview_in_char_directly_from_keyboard ()
{
    printf ("문자를 입력하시오: ");
    char new_char = getchar_direct();

    appview_out_new_line ();

    return new_char;
}

void appview_out_stack_is_full_against_push (char elem)
{
    printf ("[Push: Full] 스택이 꽉 차서 원소 \'%c\' 는 삽입이 불가능합니다.\n", elem);
}
void appview_out_pushed_element (char elem)
{
    printf ("[Push] 삽입된 원소는 \'%c\' 입니다.\n", elem);
}
void appview_out_stack_is_empty_against_pop ()
{
    printf ("[Pop1: Empty] 스택에 삭제할 원소가 없습니다.\n");
}
void appview_out_popped_element_by_pop (char elem)
{
    printf ("[Pop1] 삭제된 원소는 \'%c\' 입니다.\n", elem);
}
void appview_out_begin_pops (int number_of_elements)
{
    printf ("[Pops] %d 개의 원소를 삭제하려고 합니다:\n", number_of_elements);
}
void appview_out_end_pops ()
{
    printf ("[Pops] 삭제를 종료합니다. \n");
}
void appview_out_stack_is_empty_against_pops ()
{
    printf ("[Pops: Empty] 스택에 더 이상 삭제할 원소가 없습니다.\n");
}
void appview_out_top_element (char elem)
{
    printf ("[Top] Top 원소는 \'%c\' 입니다.\n", elem);
}
void appview_out_no_top_element ()
{
    printf ("[Top: Empty] 현재 스택은 비어 있습니다.\n");
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

void appview_out_new_line ()
{
    printf ("\n");
}

void appview_out_stack_size (int stackSize)
{
    printf ("[Size] 현재 스택의 크기는 %d 입니다.\n", stackSize);
}
void appview_out_ignored_char ()
{
    printf ("[Ignore] 의미 없는 문자가 입력되었습니다.\n");
}
void appview_out_end_input ()
{
    printf ("[End Input] 입력을 종료하며, 스택의 모든 원소를 삭제합니다:\n");
}
void appview_out_popped_element_by_end_input (char elem)
{
    printf ("-End Input: 삭제된 원소는 \'%c\' 입니다.\n", elem);
}

void appview_out_number_of_input_chars (int number_of_chars)
{
    printf ("……입력된 문자는 모두 %d 개 입니다.\n ", number_of_chars);
}

void appview_out_number_of_normally_processed_chars (int number_of_chars)
{
    printf ("……정상으로 처리된 문자는 %d 개 입니다.\n ", number_of_chars);
}

void appview_out_number_of_ignored_chars (int number_of_chars)
{
    printf ("……무시된 문자는 %d 개 입니다.\n ", number_of_chars);
}

void appview_out_number_of_pushed_chars (int number_of_chars)
{
    printf ("……스택에 넣은 문자는 %d 개 입니다.\n ", number_of_chars);
}

void appview_out_start_program ()
{
    printf ("<<< 스택 처리 프로그램을 시작합니다 >>>\n ");
    appview_out_new_line ();
}

void appview_out_end_program ()
{
    appview_out_new_line ();
    printf ("<<< 스택 처리 프로그램을 종료합니다 >>>\n ");
}