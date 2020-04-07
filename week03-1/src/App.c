#include "App.h"
#include "MagicSquare.h"

static int MagicSquareBoard[MS_MAX_ORDER][MS_MAX_ORDER] = { 0 };

int App_Start(void) {
	int order;
	
	AppView_out_msg_startMagicSquare();

	while ((order = AppView_in_getNextOrder()) != MS_END_RUN) {
		if (MagicSquare_orderIsValid(order)) {
			MagicSquare_clear(MagicSquareBoard, order);
			MagicSquare_solve(MagicSquareBoard, order);

			AppView_out_printMagicSquare(MagicSquareBoard, order);
		}
		else {
			if (order < 3) AppView_err_msg_orderTooSmall();
			else if (order > 99) AppView_err_msg_orderTooLarge();
			else AppView_err_msg_orderIsNotOdd();
		}
	}


	AppView_out_msg_endMagicSquare();
	return 0;
}