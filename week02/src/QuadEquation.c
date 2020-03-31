#include <math.h> // sqrtf

#include "QuadEquation.h"
#include "Macros.h" // Square, F32IsZero

void  QuadEquationProblem_setEquation(QuadEquationProblem_t* _this, QuadEquation_t problem) {
    _this->equation = problem;
}

bool  QuadEquationProblem_secondOrderTermCofficientIsZero(QuadEquationProblem_t* _this) {
    return F32IsZero(_this->equation.c0);
}

bool  QuadEquationProblem_determinantIsNegative(QuadEquationProblem_t* _this) {
    float determinant = QuadEquationProblem_getDeterminant(_this);
    
    // float을 0과 직접 비교하는것은 위험
    return !F32IsZero(determinant) && determinant < 0;
}

float QuadEquationProblem_getDeterminant(QuadEquationProblem_t* _this) {
    QuadEquation_t equation = _this->equation;
    return Square(equation.c1) - 4 * equation.c0 * equation.c2; // b^2 - 4ac
}

void QuadEquationProblem_solve(QuadEquationProblem_t* _this) {
    QuadEquation_t equation = _this->equation;
    
    float rational    = -equation.c1 / (2 * equation.c0); // -b/2a
    float irrational = sqrtf(QuadEquationProblem_getDeterminant(_this)) / (2 * equation.c0);

    _this->solution.root1 = rational + irrational;
    _this->solution.root2 = rational - irrational;
}