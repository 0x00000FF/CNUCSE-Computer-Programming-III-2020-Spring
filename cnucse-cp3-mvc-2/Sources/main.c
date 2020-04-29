#include <mvc/app_controller.h>           // app_controller

// 진입점
int main(int argc, char* argv[])
{
	// state, app_controller 객체 생성
	int             result     = 0;
	app_controller* controller = app_controller_create(argc, argv);
	
	// app_controller_exit() 구현을 위한 setjmp
	if (setjmp( *app_jmp_env() ) == 0) {
		// 실행, 결과 수신, 객체 해제
		app_controller_run(controller);
		
		result = app_controller_get_result(controller);
		app_controller_delete(controller);
	}

	return result;
}