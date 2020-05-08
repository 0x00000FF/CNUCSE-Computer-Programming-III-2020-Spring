#include <stdlib.h>
#include <app/perf_timer.h>

perf_timer*   perf_timer_new()
{
    return (perf_timer*) malloc( sizeof(perf_timer) );
}

void     perf_timer_delete(perf_timer* self)
{
    if (self != NULL) free(self);
}
  
void     perf_timer_start(perf_timer* self)
{
    self->start = clock();
}

void     perf_timer_stop(perf_timer* self)
{
    self->stop = clock();
}

double   perf_timer_duration(perf_timer* self)
{
    double elapsed = (double) (self->stop - self->start);
    return (elapsed * 1.0E6) / ((double) CLOCKS_PER_SEC);
}