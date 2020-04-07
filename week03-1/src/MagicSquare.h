#ifndef __MAGICSQUARE_H__
#define __MAGICSQUARE_H__

#include "App.h"

bool    MagicSquare_orderIsValid(int order);

void    MagicSquare_clear(BOARD_ARG(board), unsigned int order);
void    MagicSquare_solve(BOARD_ARG(board), unsigned int order);

#endif