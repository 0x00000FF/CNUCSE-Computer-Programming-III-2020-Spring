#include "MagicSquare.h"

bool    MagicSquare_orderIsValid(int order) {
	return order < 100 && order >= 3 && IsOdd(order);
}

void    MagicSquare_clear(BOARD_ARG(board), unsigned int order) {
	for (unsigned int i = 0; i < order; ++i) {
		for (unsigned int j = 0; j < order; ++j) {
			board[i][j] = 0;
		}
	}
}


void    MagicSquare_solve(BOARD_ARG(board), unsigned int order) { // unsigned: buffer underrun
	int col = order / 2, row = 0;
	unsigned val = 1;

	while (val <= Square(order)) {
		if (col < 0) col = order - 1;
		else if ((unsigned int)col >= order) col = col - order; // signed/unsigned mismatch

		if (row < 0)        row = order - 1;
		else if ((unsigned int)row >= order) row = row - order; // signed/unsigned mismatch

		if (board[row][col] != 0) {
			col--;
			row += 2;
		}
		else {
			board[row][col] = val;

			row--;
			col++;

			val++;
		}
	}
}