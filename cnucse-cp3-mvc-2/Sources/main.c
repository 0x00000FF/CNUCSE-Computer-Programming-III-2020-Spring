////////////////////////////////////////////////////////////////////////////
//
//    [제 7주차] 성적처리 :: 진입점
//
//    최초 작성일 2020년 04월 29일
//    작성자     201704150 허강준
//
//    성적처리 Application의 진입점(main)을 정의합니다.
//
////////////////////////////////////////////////////////////////////////////

#include <mvc/app_controller.h>           // app_controller

// 진입점
int main(int argc, char* argv[])
{
	// state, app_controller 객체 생성
	int             result     = 0;
	app_controller* controller = app_controller_create(argc, argv);
	
	if (setjmp( *app_jmp_env() ) == 0) {
		// 실행, 결과 수신, 객체 해제
		app_controller_run(controller);
		
		result = app_controller_get_result(controller);
		app_controller_delete(controller);
	}

	return result;
}