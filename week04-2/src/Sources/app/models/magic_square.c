#include <app/model/magic_square.h>

CTOR(MagicSquare, int order) {
	if ($this == NULLPTR) {
		return;
	}

	$this->m_order = order;
}

METHOD_DEF(MagicSquare, int*, get) {
	if (METHOD(MagicSquare, $this, valid)) {
		return NULLPTR;
	}

	return (int*) $this->m_board;
}

METHOD_DEF(MagicSquare, void, solve) {

}

METHOD_DEF(MagicSquare, bool, valid) {
	return !($);
}