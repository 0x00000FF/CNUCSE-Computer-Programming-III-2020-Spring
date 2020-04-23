#include <app/app_view.h>
#include <stdio.h>

#pragma warning(disable: 4996)

METHOD_STATIC_DEF(AppView, void, printl,
	const char* str)
{
	puts(str);
}

METHOD_STATIC_DEF(AppView, void, printExecTime,
	int    order,
	double duration)
{
	printf("차수: %2d, 시간: %.2lf (마이크로 초)\n", order, duration);
}