#ifndef __QUADEQUATION_H
#define __QUADEQUATION_H

#include <stdbool.h>

typedef struct {
	float c0, c1, c2;
} QuadEquation_t;

typedef struct {
	float root1;
	float root2;
} QuadSolution_t;

typedef struct {
	QuadEquation_t equation;
	QuadSolution_t solution;
} QuadEquationProblem_t;

void  QuadEquationProblem_setEquation(QuadEquationProblem_t* _this, QuadEquation_t problem);
bool  QuadEquationProblem_secondOrderTermCofficientIsZero(QuadEquationProblem_t* _this);
bool  QuadEquationProblem_determinantIsNegative(QuadEquationProblem_t* _this);
float QuadEquationProblem_getDeterminant(QuadEquationProblem_t* _this);
void QuadEquationProblem_solve(QuadEquationProblem_t* _this);


#endif