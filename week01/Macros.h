#ifndef __MACROS_H
#define __MACROS_H

#define EPSILON 1.0E-6

#define FloatAbs(f0) (float)((long)f0 & 0x7fffffff)
#define FloatIsZero(f0) (FloatAbs(f0) < EPSILON)

#endif