#include "App.h"
#include "Calculator.h"

int App_Start(void) {
	float c0 = 0.0f, c1 = 0.0f, root = 0.0f;
	bool solvingIsRequested = false;

	AppView_out_msg_startSolvingLinearEquation();

	while (solvingIsRequested = AppView_in_getSolvingRequest()) {
		AppView_in_getCoefficient(&c0, &c1);
		AppView_out_showLinearEquation(c0, c1);

		if (F32IsZero(c0)) {
			AppView_out_msg_error_firstOrderTermCoefficientIsZero();
		} else {
			root = Calculator_SolveEquation(c0, c1);
			AppView_out_showRoot(root);
		}
	}

	AppView_out_msg_endSolvingLinearEquation();
	return 0;
}