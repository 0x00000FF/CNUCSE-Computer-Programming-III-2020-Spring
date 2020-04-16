#ifndef __QUAD_EQUATION_H__
#define __QUAD_EQUATION_H__
#include <stdbool.h>
#include <mvc/oop.h>

CLASS(QuadEquation,
	float c0; float c1; float c2;
);

CLASS(QuadSolution,
	float root1; float root2;
);

CLASS(QuadEquationProblem,
	QuadEquation* equation;
	QuadSolution* solution;
);

METHOD_DEF(QuadEquationProblem, QuadEquation*, getEquation);
METHOD_DEF(QuadEquationProblem, void         , setEquation, 
		   float c0, float c1, float c2);
METHOD_DEF(QuadEquationProblem, bool         , validateDeterminant);
METHOD_DEF(QuadEquationProblem, bool         , validateCoefficient);
METHOD_DEF(QuadEquationProblem, float        , getDeterminant);
METHOD_DEF(QuadEquationProblem, void         , solve);


METHOD_DEF(QuadEquationProblem, void, initialize);
METHOD_DEF(QuadEquationProblem, void, destroy);
#endif