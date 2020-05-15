#pragma once

char appview_in_char_directly_from_keyboard ();

void appview_out_stack_is_full_against_push (char elem);
void appview_out_pushed_element (char elem);
void appview_out_stack_is_empty_against_pop ();
void appview_out_popped_element_by_pop (char elem);
void appview_out_begin_pops (int number_of_elements);
void appview_out_end_pops ();
void appview_out_stack_is_empty_against_pops ();
void appview_out_top_element (char elem);
void appview_out_no_top_element ();
void appview_out_bottom_of_stack ();
void appview_out_element (char elem);
void appview_out_top_of_stack ();
void appview_out_new_line ();
void appview_out_stack_size (int stackSize);
void appview_out_ignored_char ();
void appview_out_end_input ();
void appview_out_popped_element_by_end_input (char elem);
void appview_out_number_of_input_chars (int number_of_chars);
void appview_out_number_of_normally_processed_chars (int number_of_chars);
void appview_out_number_of_ignored_chars (int number_of_chars);
void appview_out_number_of_pushed_chars (int number_of_chars);
void appview_out_start_program ();
void appview_out_end_program ();