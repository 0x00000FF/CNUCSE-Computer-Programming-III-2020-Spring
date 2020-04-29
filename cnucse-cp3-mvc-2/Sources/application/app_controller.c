////////////////////////////////////////////////////////////////////////////
//
//    [제 7주차] 성적처리 :: 진입점
//
//    최초 작성일 2020년 04월 29일
//    작성자     201704150 허강준
//
//    클래스 app_controller 관련 구현을 기술합니다.
//
////////////////////////////////////////////////////////////////////////////

#include <mvc/app_controller.h>    // app_controller

// app_controller 생성자
app_controller* app_controller_create(int argc, char* argv)
{
	app_controller* controller = (app_controller*)malloc(sizeof(app_controller));

	controller->argc   = argc;
	controller->argv   = argv;
	controller->result = 0;

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

	free(self);
}