#ifndef __APPVIEW_H
#define __APPVIEW_H

#include "App.h"
#include <stdbool.h> // C99 Boolean Compliance

void    AppView_out_msg_startSolvingLinearEquation(void);
void    AppView_out_msg_endSolvingLinearEquation(void);
void    AppView_out_showLinearEquation(float c0, float c1);
void    AppView_out_showRoot(float root);
void    AppView_out_msg_error_firstOrderTermCoefficientIsZero(void);

bool    AppView_in_getSolvingRequest();
void    AppView_in_getCoefficient(float* c0, float* c1);

#endif