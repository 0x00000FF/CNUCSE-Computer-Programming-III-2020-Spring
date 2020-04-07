#include "App.h"
#include "MagicSquare.h"

int App_Start(void) {
	int order;
	MagicSquare* ms;
	
	AppView_out_msg_startMagicSquare();

	while ((order = AppView_in_getNextOrder()) != MS_END_RUN) {
		if (MagicSquare_orderIsValid(order)) {
			ms = MagicSquare_create(order);

			MagicSquare_clear(ms);
			MagicSquare_solve(ms);

			AppView_out_printMagicSquare(ms);

			MagicSquare_destroy(ms);
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