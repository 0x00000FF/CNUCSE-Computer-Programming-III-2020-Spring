#ifndef __MAGIC_SQUARE_H__
#define __MAGIC_SQUARE_H__

#include <stdbool.h>
#include <mvc/oop.h>

#define MS_MAX_ORDER 99
#define MS_END_RUN   -1

CLASS(MagicSquare,
	unsigned int order;
	int*         board;
);

METHOD_STATIC_DEF(MagicSquare, MagicSquare*, create, int order);
METHOD_DEF(MagicSquare, void, destroy);
METHOD_STATIC_DEF(MagicSquare, int, orderIsValid, int order);
METHOD_DEF(MagicSquare, void, clear);
METHOD_DEF(MagicSquare, void, solve);

#endif
