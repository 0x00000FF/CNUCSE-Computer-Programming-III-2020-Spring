#ifndef __APP_VIEW_H__
#define __APP_VIEW_H__

#include <stdbool.h>
#include <mvc/oop.h>
#include <app/models/quad_equation.h>

METHOD_STATIC_DEF(AppView, void, msg_startQuadEquation);
METHOD_STATIC_DEF(AppView, void, msg_endQuadEquation);

METHOD_STATIC_DEF(AppView, bool, getSolvingRequest);
METHOD_STATIC_DEF(AppView, void, readCoefficient, QuadEquationProblem* problem);
METHOD_STATIC_DEF(AppView, void, printEquation, QuadEquationProblem* problem);
METHOD_STATIC_DEF(AppView, void, printDeterminant, QuadEquationProblem* problem);
METHOD_STATIC_DEF(AppView, void, msg_resourceNotAllocated);
METHOD_STATIC_DEF(AppView, void, msg_coefficientIsNotValid);
METHOD_STATIC_DEF(AppView, void, msg_determinantIsNotValid);
METHOD_STATIC_DEF(AppView, void, printSolution, QuadEquationProblem* problem);

#endif  __APP_VIEW_H__