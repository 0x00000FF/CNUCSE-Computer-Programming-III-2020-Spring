#include <stdio.h>

#include <mvc.h>

#include <app/app_view.h>
#include <app/model/magic_square.h>
#include <app/model/timer.h>


int AppController(int argc, char* argv[]) {
	MagicSquare* ms;
	int          order, count;
	Timer*       timer;
	double       exec_time;

	timer = METHOD_STATIC(Timer, create);
	
	METHOD_STATIC(AppView, printl, "<<< 마방진 풀이의 성능 측정을 시작합니다 >>>");
	METHOD_STATIC(AppView, printl, "하나의 차수에 대해 100회 반복 실행한 시간을 측정합니다.\n");

	for (order = 9; order <= MS_MAX_ORDER; order += 10) {
		METHOD(Timer, timer, start);
		for (count = 0; count < 100; ++count) {
			ms = METHOD_STATIC(MagicSquare, create, order);
			METHOD(MagicSquare, ms, solve);
			DELETE(ms);
		}
		METHOD(Timer, timer, stop);

		exec_time = METHOD(Timer, timer, get_duration);
		METHOD_STATIC(AppView, printExecTime, order, exec_time);
	}

	DELETE(timer);
	METHOD_STATIC(AppView, printl, "\n<<< 성능 측정을 종료합니다 >>>");

	return 0;
}