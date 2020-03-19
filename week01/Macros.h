#ifndef __MACROS_H
#define __MACROS_H

#define EPSILON 1.0E-6

#define F32Abs(f0) (float)((long)f0 & 0x7fffffff)
#define F32IsZero(f0) (F32Abs(f0) < EPSILON)

#endif