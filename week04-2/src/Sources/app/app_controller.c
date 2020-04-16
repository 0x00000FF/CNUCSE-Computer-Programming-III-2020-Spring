#include <stdio.h>

#include <mvc.h>

#include <app/app_view.h>
#include <app/model/magic_square.h>


int AppController(int argc, char* argv[]) {
	int order, orderValidCode;
	MagicSquare* ms;

	AppView_out_msg_startMagicSquare();

	while ((order = AppView_in_getNextOrder()) != MS_END_RUN) {
		orderValidCode = METHOD_STATIC(MagicSquare, orderIsValid, order);

		if (orderValidCode == 0) {
			ms = METHOD_STATIC(MagicSquare, create, order);
			if (ms == NULLPTR) {
				AppView_msg_allocationFailed();
				continue;
			}

			METHOD(MagicSquare, ms, clear);

			METHOD(MagicSquare, ms, solve);
			AppView_out_printMagicSquare(ms);

			METHOD(MagicSquare, ms, destroy);
		}
		else {
			if (orderValidCode == 1) AppView_err_msg_orderTooLarge(); 
			else if (orderValidCode == 2) AppView_err_msg_orderTooSmall();
			else AppView_err_msg_orderIsNotOdd();
		}
	}

	AppView_out_msg_endMagicSquare();
	return 0;
}