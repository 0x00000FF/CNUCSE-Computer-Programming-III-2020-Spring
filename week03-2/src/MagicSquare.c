#include "MagicSquare.h"


MagicSquare*  MagicSquare_create(unsigned int order) {
	MagicSquare* ms = (MagicSquare*)malloc(sizeof(MagicSquare)); // C6262
	
	if (ms == NULL) {
		exit(-1);
	}

	ms->order = order;
	MagicSquare_clear(ms);

	return ms;
}

void    MagicSquare_destroy(MagicSquare* _this) {
	if (_this == NULL) return;
	free(_this);
}

bool    MagicSquare_orderIsValid(int order) {
	return order < 100 && order >= 3 && IsOdd(order);
}

void    MagicSquare_clear(MagicSquare* _this) {
	for (unsigned int i = 0; i < _this->order; ++i) {
		for (unsigned int j = 0; j < _this->order; ++j) {
			_this->board[i][j] = 0;
		}
	}
}

void    MagicSquare_solve(MagicSquare* _this) { // unsigned: buffer underrun
	int col = _this->order / 2, row = 0;
	unsigned order = _this->order, val = 1;

	while (val <= Square(order)) {
		if (col < 0) col = order - 1;
		else if ((unsigned int)col >= order) col = col - order; // signed/unsigned mismatch

		if (row < 0)        row = order - 1;
		else if ((unsigned int)row >= order) row = row - order; // signed/unsigned mismatch

		if (_this->board[row][col] != 0) {
			col--;
			row += 2;
		}
		else {
			_this->board[row][col] = val;

			row--;
			col++;

			val++;
		}
	}
}