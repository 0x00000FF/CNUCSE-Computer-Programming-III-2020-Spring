#ifndef __MACROS_H
#define __MACROS_H

// 마방진 전용 상수 정의
#define MS_END_RUN   -1
#define MS_MAX_ORDER 99
#define BOARD_ARG(x)    int x[MS_MAX_ORDER][MS_MAX_ORDER]

#define EPSILON 1.0E-6

#define IsOdd(x)   ((x > 0) && (x % 2))
#define Square(x)  (x * x)

#define F32Abs(f0) (float)((long)f0 & 0x7fffffff)
#define F32IsZero(f0) (F32Abs(f0) < EPSILON)

#endif