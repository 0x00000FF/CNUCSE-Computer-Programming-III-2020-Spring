#ifndef __TIMER_H__
#define __TIMER_H__

#include <mvc/oop.h>

CLASS(Timer,
	__int64 frequency;
	__int64 begin_timestamp;
	__int64 end_timestamp;
);

METHOD_STATIC_DEF(Timer, Timer*, create);
METHOD_DEF(Timer, void, destroy);

METHOD_DEF(Timer, void,    start);
METHOD_DEF(Timer, void,    stop);
METHOD_DEF(Timer, double,  get_duration);

#endif