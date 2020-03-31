#ifndef __APPVIEW_H
#define __APPVIEW_H

#include <stdbool.h>

#include "Macros.h"
#include "QuadEquation.h"

void    AppView_out_msg_startSolvingQuadEquation(void);
void    AppView_out_msg_endSolvingQuadEquation(void);
void    AppView_out_showQuadEquation(QuadEquationProblem_t problem);
void    AppView_out_showRoot(QuadEquationProblem_t problem);
void    AppView_out_msg_error_secondOrderTermCoefficientIsZero(void);
void    AppView_out_msg_error_determinantIsNegative(QuadEquationProblem_t problem);

bool    AppView_in_getSolvingRequest(void);
void    AppView_in_getCoefficient(QuadEquationProblem_t* problem);

#endif