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
	printf("����: %2d, �ð�: %.2lf (����ũ�� ��)\n", order, duration);
}