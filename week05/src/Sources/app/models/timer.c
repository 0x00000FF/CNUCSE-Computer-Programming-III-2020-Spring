#include <Windows.h>
#undef   min
#undef   max
#undef   NEW
#undef   DELETE

#include <app/model/timer.h>

METHOD_STATIC_DEF(Timer, __int64, query_counter) {
	LARGE_INTEGER _tsc;
	BOOL          _query_result = QueryPerformanceCounter(&_tsc);
	
	if (!_query_result) {
		return -1;
	}

	return _tsc.QuadPart;
}

METHOD_STATIC_DEF(Timer, __int64, query_frequency) {
	LARGE_INTEGER _frequency;
	BOOL          _query_result = QueryPerformanceFrequency(&_frequency);

	if (!_query_result) {
		return -1;
	}

	return _frequency.QuadPart;
}

METHOD_STATIC_DEF(Timer, Timer*, create) 
{
	Timer* _timer = NEW(Timer);

	_timer->frequency = METHOD_STATIC(Timer, query_frequency);

	return _timer;
}

METHOD_DEF(Timer, void, destroy)
{
	if (self != NULLPTR)
		free(self);
}

METHOD_DEF(Timer, void, start)
{
	self->begin_timestamp = METHOD_STATIC(Timer, query_counter);
}

METHOD_DEF(Timer, void, stop)
{
	self->end_timestamp = METHOD_STATIC(Timer, query_counter);
}

METHOD_DEF(Timer, double, get_duration)
{
	double elapsed   = (self->end_timestamp - self->begin_timestamp) * 1.0E6;
	double frequency = (double) self->frequency;

	return elapsed / frequency;
}