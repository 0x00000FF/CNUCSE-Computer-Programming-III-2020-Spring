#pragma once

#include <time.h>

typedef struct {
    clock_t start, stop;
} perf_timer;

perf_timer*   perf_timer_new();
void          perf_timer_delete(perf_timer* self);
       
void          perf_timer_start(perf_timer* self);
void          perf_timer_stop(perf_timer* self);
double        perf_timer_duration(perf_timer* self);