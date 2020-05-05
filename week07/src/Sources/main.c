#include <mvc/app_controller.h>           // app_controller

// 진입점
int main(int argc, char* argv[])
{
	// state, app_controller 객체 생성
	int             result     = 0;
	jmp_buf*        jmp_state  = app_jmp_env();
	app_controller* controller = app_controller_create(argc, argv);
	
	// app_controller_exit() 구현을 위한 setjmp
	if (setjmp(*jmp_state) == 0) {
		app_controller_run(controller);
	}

	// 결과 수신, 객체 해제
	result = app_controller_get_result(controller);
	app_controller_delete(controller);

	return result;
}