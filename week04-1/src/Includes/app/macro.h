#ifndef __MACRO_H__
#define __MACRO_H__

#define EPSILON 1.0E-6

#define Square(x)  ((x) * (x))

#define F32Abs(f0)    (float)((long)f0 & 0x7fffffff)
#define F32IsZero(f0) (F32Abs(f0) < EPSILON)

#endif