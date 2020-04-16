#ifndef __MAGIC_SQUARE_H__
#define __MAGIC_SQUARE_H__

#include <stdbool.h>
#include <mvc/oop.h>

#define MS_MAX_ORDER 99

CLASS(MagicSquare,
	PRIVATE(int, order);
	PRIVATE(int, board[MS_MAX_ORDER][MS_MAX_ORDER]);
);

CTOR(MagicSquare, int order);

METHOD_DEF(MagicSquare, int*, get);
METHOD_DEF(MagicSquare, void, solve);
METHOD_DEF(MagicSquare, bool, valid);

#endif