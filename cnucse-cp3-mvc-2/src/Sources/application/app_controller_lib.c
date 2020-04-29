#include <mvc/app_controller.h>

static
jmp_buf         app_jmp_state;

jmp_buf*        app_jmp_env()
{
	return &app_jmp_state;
}

// exit(int) 구현
void            app_controller_exit(app_controller* self, int status)
{
	self->result = status;
	longjmp(*app_jmp_env(), status);
}

int             app_controller_get_result(app_controller* self)
{
	return self->result;
}