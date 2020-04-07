#ifndef __MAGICSQUARE_H__
#define __MAGICSQUARE_H__

#include <stdlib.h>
#include <stdbool.h>

#include "Macros.h"

typedef struct {
	unsigned int order;
	int board[MS_MAX_ORDER][MS_MAX_ORDER];
} MagicSquare;

MagicSquare* MagicSquare_create(unsigned int order);
void         MagicSquare_destroy(MagicSquare* _this);

bool    MagicSquare_orderIsValid(int order);

void    MagicSquare_clear(MagicSquare* _this);
void    MagicSquare_solve(MagicSquare* _this);

#endif