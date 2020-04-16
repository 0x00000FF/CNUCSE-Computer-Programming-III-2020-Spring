#include <math.h> // sqrt

#include <app/macro.h>
#include <app/models/quad_equation.h>

METHOD_DEF(QuadEquationProblem, QuadEquation*, getEquation)
{
	return self->equation;
}

METHOD_DEF(QuadEquationProblem, void, setEquation, float c0, float c1, float c2)
{
	self->equation->c0 = c0;
	self->equation->c1 = c1;
	self->equation->c2 = c2;
}

METHOD_DEF(QuadEquationProblem, bool, validateDeterminant)
{
	return METHOD(QuadEquationProblem, self, getDeterminant) >= 0;
}

METHOD_DEF(QuadEquationProblem, bool, validateCoefficient)
{
	return self->equation->c0 != 0;
}

METHOD_DEF(QuadEquationProblem, float, getDeterminant)
{
	QuadEquation* eq = self->equation;
	return Square(eq->c1) - (4 * eq->c0 * eq->c2);
}

METHOD_DEF(QuadEquationProblem, void, solve)
{
	QuadEquation* eq = self->equation;

	float solution;
	float rational = -eq->c1 / (2 * eq->c0);
	float irrational = sqrtf(METHOD(QuadEquationProblem, self, getDeterminant)) / (2 * eq->c0);

	// prevent -0
	solution = rational + irrational;
	self->solution->root1 = solution;

	solution = rational - irrational;
	self->solution->root2 = solution;
}

METHOD_DEF(QuadEquationProblem, void, initialize)
{
	self->equation = NEW(QuadEquation);
	self->solution = NEW(QuadSolution);
}

METHOD_DEF(QuadEquationProblem, void, destroy)
{
	if (self == NULLPTR) {
		return;
	}
	else {
		free(self->equation);
		free(self->solution);

		free(self);
	}
}