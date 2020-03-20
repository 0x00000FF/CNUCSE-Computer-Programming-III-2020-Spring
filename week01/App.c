#include "App.h"

static float c0 = 0.0f, c1 = 0.0f, root = 0.0f;

float App_SolveEquation(void) {
	return (-c1) / c0;
}

int App_Start(void) {
	bool solvingIsRequested = false;

	AppView_out_msg_startSolvingLinearEquation();

	while (solvingIsRequested = AppView_in_getSolvingRequest()) {
		AppView_in_getCoefficient(&c0, &c1);
		AppView_out_showLinearEquation(c0, c1);

		if (F32IsZero(c0)) {
			AppView_out_msg_error_firstOrderTermCoefficientIsZero();
		} else {
			root = App_SolveEquation();
			AppView_out_showRoot(root);
		}
	}

	AppView_out_msg_endSolvingLinearEquation();
	return 0;
}