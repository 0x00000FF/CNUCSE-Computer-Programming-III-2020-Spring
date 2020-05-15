#include <mvc/appview.h>
#include <mvc/app_controller.h>    // app_controller

// app_controller 생성자
app_controller* app_controller_create(int argc, char** argv)
{
	app_controller* controller = (app_controller*)malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;
	
	controller->postfix = NULL;

	return controller;
}


// application routine 시작
void            app_controller_run   (app_controller* self)
{

}

// app_controller 소멸자
void            app_controller_delete(app_controller* self)
{
	if (self == NULL) return;
	if (self->postfix != NULL) 
		postfix_delete(self->postfix);

	free(self);
}