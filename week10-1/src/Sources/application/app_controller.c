#include <mvc/appview.h>
#include <mvc/app_controller.h>    // app_controller

// app_controller 생성자
app_controller* app_controller_create(int argc, char** argv)
{
	app_controller* controller = (app_controller*) malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;
	
	controller->postfix = NULL;

	return controller;
}


// application routine 시작
void            app_controller_run (app_controller* self)
{
	bool is_exp_avail, no_error_in_eval;
	appview_out_starting_message();

	self->postfix = postfix_new(MAX_NUMBER_OF_TOKENS);
	is_exp_avail = appview_in_postfix_expression(self->expression);

	while(is_exp_avail) {
		postfix_set_expression(self->postfix, self->expression);
		no_error_in_eval = postfix_evaluate(self->postfix);

		if( ! no_error_in_eval ) {
			appview_out_error_in_expression(); // printf(“>수식에 오류가 있습니다.\n”);
		} else {
			appview_out_evaluated_value(postfix_evaluated_value(self->postfix) );
		}

		is_exp_avail = appview_in_postfix_expression(self->expression);
	}

	appview_out_ending_message();
}

// app_controller 소멸자
void            app_controller_delete(app_controller* self)
{
	if(self == NULL) return;
	if(self->postfix != NULL) 
		postfix_delete(self->postfix);

	free(self);
}