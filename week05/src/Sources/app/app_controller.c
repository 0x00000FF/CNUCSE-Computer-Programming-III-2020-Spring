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
	
	METHOD_STATIC(AppView, printl, "<<< ������ Ǯ���� ���� ������ �����մϴ� >>>");
	METHOD_STATIC(AppView, printl, "�ϳ��� ������ ���� 100ȸ �ݺ� ������ �ð��� �����մϴ�.\n");

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
	METHOD_STATIC(AppView, printl, "\n<<< ���� ������ �����մϴ� >>>");

	return 0;
}