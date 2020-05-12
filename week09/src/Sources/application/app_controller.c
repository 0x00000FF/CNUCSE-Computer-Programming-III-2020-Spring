#include <mvc/appview.h>
#include <mvc/app_controller.h>    // app_controller

// app_controller 생성자
app_controller* app_controller_create(int argc, char** argv)
{
	app_controller* controller = (app_controller*)malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;

	controller->stack  = stack_new();

	return controller;
}

/*
 *  Private Functions Begin
 */

void            app_controller_init_counting_chars(app_controller* self)
{
	self->c_ignored = 0;
	self->c_input   = 0;
	self->c_push    = 0;
}

void            app_controller_count_input_chars(app_controller* self)
{
	self->c_input++;
}

void            app_controller_push  (app_controller* self, char c)
{
	if (stack_full(self->stack)) {
		appview_out_stack_is_full_against_push(c);
		return;
	}

	stack_push(self->stack, c);
	appview_out_pushed_element(c);

	self->c_push++;
}

void            app_controller_pop_one(app_controller* self)
{
	if (stack_empty(self->stack)) {
		appview_out_stack_is_empty_against_pop();
		return;
	}

	element c = stack_pop(self->stack);

	appview_out_popped_element_by_pop(c);
}

void            app_controller_pops  (app_controller* self, int pop_count)
{
	element c;

	appview_out_begin_pops(pop_count);

	for (int i = 0; i < pop_count; ++i) {
		if (stack_empty(self->stack)) {
			appview_out_stack_is_empty_against_pops();
			return;
		}

		c = stack_pop(self->stack);
		appview_out_popped_element_by_pop(c);
	}

	appview_out_end_pops();	
}

void            app_controller_show_size(app_controller* self)
{
	int size = stack_size(self->stack);
	appview_out_stack_size(size);
}

void            app_controller_show_all_from_bottom(app_controller* self)
{
	element c;
	
	appview_out_bottom_of_stack();

	for (int i = 0; i < stack_size(self->stack); ++i) {
		c = stack_at(self->stack, i);
		appview_out_element(c);
	}

	appview_out_top_of_stack();
	appview_out_new_line();
}

void            app_controller_show_all_from_top(app_controller* self)
{
	element c;
	
	appview_out_top_of_stack();

	for (int i = stack_size(self->stack) - 1; i > -1; --i) {
		c = stack_at(self->stack, i);
		appview_out_element(c);
	}

	appview_out_bottom_of_stack();
	appview_out_new_line();
}

void            app_controller_show_top_element(app_controller* self)
{
	if (stack_empty(self->stack)) {
		appview_out_no_top_element();
		return;
	}

	element c = stack_peek(self->stack);
	appview_out_top_element(c);
}

void            app_controller_ignore(app_controller* self)
{
	appview_out_ignored_char();
	self->c_ignored++;
}

int             app_controller_number_of_input_chars(app_controller* self)
{
	return self->c_input;
}

int             app_controller_number_of_ignored_chars(app_controller* self)
{
	return self->c_ignored;
}

int             app_controller_number_of_normally_processed_chars(app_controller* self)
{
	return self->c_input - self->c_ignored;
}

int             app_controller_number_of_pushed_chars(app_controller* self)
{
	return self->c_push;
}

void            app_controller_end_input(app_controller* self)
{
	element pop_c;

	appview_out_end_input(self);

	while (!stack_empty(self->stack)) {
		pop_c = stack_pop(self->stack);
		appview_out_popped_element_by_end_input(pop_c);
	}
}

void            app_controller_show_statistics(app_controller* self)
{
	appview_out_new_line();

	appview_out_number_of_input_chars(app_controller_number_of_input_chars(self));
	appview_out_number_of_normally_processed_chars(app_controller_number_of_normally_processed_chars(self));
	appview_out_number_of_ignored_chars(app_controller_number_of_ignored_chars(self));
	appview_out_number_of_pushed_chars(app_controller_number_of_pushed_chars(self));
}

/*
 *  Private Functions End
 */

// application routine 시작
void            app_controller_run   (app_controller* self)
{
	appview_out_start_program();

	app_controller_init_counting_chars(self);
	appview_out_new_line();

	char c = appview_in_char_directly_from_keyboard();
	while (c != KEY_ESC) {
		app_controller_count_input_chars(self);
		if (IS_ALPHA(c)) {
			app_controller_push(self, c);
		}
		else if (IS_DIGIT(c)) {
			int pop_count = TO_DIGIT(c);
			app_controller_pops(self, pop_count);
		}
		else if (c == KEY_DASH) {
			app_controller_pop_one(self);
		}
		else if (c == KEY_SHARP) {
			app_controller_show_size(self);
		}
		else if (c == KEY_SLASH) {
			app_controller_show_all_from_bottom(self);
		}
		else if (c == KEY_BACKSLASH) {
			app_controller_show_all_from_top(self);
		}
		else if (c == KEY_CARET) {
			app_controller_show_top_element(self);
		}
		else {
			app_controller_ignore(self);
		}

		appview_out_new_line();
		c = appview_in_char_directly_from_keyboard();
	}

	app_controller_end_input(self);

	app_controller_show_statistics(self);
	appview_out_end_program();
}

// app_controller 소멸자
void            app_controller_delete(app_controller* self)
{
	if (self == NULL) return;

	free(self);
}