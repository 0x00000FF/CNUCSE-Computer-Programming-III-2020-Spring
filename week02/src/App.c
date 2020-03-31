#include "App.h"


int App_Start(void) {
	QuadEquationProblem_t problem;
	bool solvingIsRequested = false;

	AppView_out_msg_startSolvingQuadEquation();

	while (solvingIsRequested = AppView_in_getSolvingRequest()) {
		QuadEquation_t equation;
		AppView_in_getCoefficient(&equation);

		QuadEquationProblem_setEquation(&problem, equation);
		AppView_out_showQuadEquation(problem);

		if (F32IsZero(problem.equation.c0)) {
			AppView_out_msg_error_secondOrderTermCoefficientIsZero();
		} else {
			if (QuadEquationProblem_determinantIsNegative(&problem)) {
				AppView_out_msg_error_determinantIsNegative(problem);
			} else {
				QuadEquationProblem_solve(&problem);
				AppView_out_showRoot(problem);
			}
		}
	}

	AppView_out_msg_endSolvingQuadEquation();
	return 0;
}