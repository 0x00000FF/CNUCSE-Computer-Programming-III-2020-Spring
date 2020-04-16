#include <app/model/magic_square.h>

METHOD_STATIC_DEF(MagicSquare, MagicSquare*, create, int order)
{
	if (order < 0) {
		return NULLPTR;
	}

	MagicSquare* ms = (MagicSquare*)malloc(sizeof(MagicSquare)); // C6262

	if (ms == NULLPTR) {
		return NULLPTR;
	}

	ms->order = order;
	ms->board = (int*)malloc( sizeof(int) * order * order );

	return ms;
}

METHOD_DEF(MagicSquare, void, destroy)
{
	if (self == NULLPTR) return;

	free(self->board);
	free(self);
}

METHOD_STATIC_DEF(MagicSquare, int, orderIsValid, int order)
{
	if (order > 99) {
		return 1;
	}
	else if (order < 3) {
		return 2;
	}
	else if ((order % 2) == 0) {
		return 3;
	}
	else {
		return 0;
	}
}

METHOD_DEF(MagicSquare, void, clear)
{
	unsigned int order = self->order;

	for (unsigned int i = 0; i < self->order; ++i) {
		for (unsigned int j = 0; j < self->order; ++j) {
			self->board[i * order + j] = 0;
		}
	}
}

METHOD_DEF(MagicSquare, void, solve)
{
	int col = self->order / 2, row = 0;
	unsigned order = self->order, val = 1;

	while (val <= order * order) {
		if (col < 0) col = order - 1;
		else if ((unsigned int)col >= order) col = col - order; // signed/unsigned mismatch

		if (row < 0)        row = order - 1;
		else if ((unsigned int)row >= order) row = row - order; // signed/unsigned mismatch

		if (self->board[row * order + col] != 0) {
			col--;
			row += 2;
		}
		else {
			self->board[row * order + col] = val;

			row--;
			col++;

			val++;
		}
	}
}