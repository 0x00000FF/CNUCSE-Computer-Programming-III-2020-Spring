#ifndef __APP_VIEW_H__
#define __APP_VIEW_H__

#include <mvc/oop.h>


METHOD_STATIC_DEF(AppView, void, printl,
	const char* str);

METHOD_STATIC_DEF(AppView, void, printExecTime,
	int    order,
	double duration);

#endif