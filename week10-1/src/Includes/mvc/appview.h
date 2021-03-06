#pragma once

#include <stdbool.h>

char appview_in_char_directly_from_keyboard ();
bool appview_in_postfix_expression();

void appview_out_starting_message();
void appview_out_ending_message();

void appview_out_error_in_expression();
void appview_out_evaluated_value(int value);

void appview_out_bottom_of_stack ();
void appview_out_element (char elem);
void appview_out_top_of_stack ();
