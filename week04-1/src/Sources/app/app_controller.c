#include <stdio.h>

#include <mvc.h>

#include <app/app_view.h>
#include <app/models/quad_equation.h>


int AppController(int argc, char* argv[]) {
	METHOD_STATIC(AppView, msg_startQuadEquation);
	
	QuadEquationProblem* problem = NEW(QuadEquationProblem);
	if (problem == NULLPTR) {
		METHOD_STATIC(AppView, msg_resourceNotAllocated);
		return -1;
	}

	METHOD(QuadEquationProblem, problem, initialize);

	while (METHOD_STATIC(AppView, getSolvingRequest)) {
		METHOD_STATIC(AppView, readCoefficient, problem);
		
		METHOD_STATIC(AppView, printEquation, problem);
		
		if (!METHOD(QuadEquationProblem, problem, validateCoefficient)) {
			METHOD_STATIC(AppView, msg_coefficientIsNotValid);

			continue;
		}
		else if (!METHOD(QuadEquationProblem, problem, validateDeterminant)) {
			METHOD_STATIC(AppView, msg_determinantIsNotValid, problem);

			continue;
		}

		METHOD(QuadEquationProblem, problem, solve);

		METHOD_STATIC(AppView, printDeterminant, problem);
		METHOD_STATIC(AppView, printSolution, problem);
	}
	
	METHOD(QuadEquationProblem, problem, destroy);
	
	METHOD_STATIC(AppView, msg_endQuadEquation);
	return 0;
}