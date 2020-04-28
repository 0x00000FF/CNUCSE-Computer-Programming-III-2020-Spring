#ifndef __APPVIEW_H__
#define __APPVIEW_H__

#include <stdbool.h>
#include <mvc/oop.h>

METHOD_STATIC_DEF(AppView, void, WriteLine, const char* str);
METHOD_STATIC_DEF(AppView, void, out_average,  float avg);
METHOD_STATIC_DEF(AppView, void, out_aboveAvg, int count);
METHOD_STATIC_DEF(AppView, void, out_max, int max);
METHOD_STATIC_DEF(AppView, void, out_min, int min);
METHOD_STATIC_DEF(AppView, void, out_gradeCount, int grades[5]);

METHOD_STATIC_DEF(AppView, void, error_scoreOutofRange);
METHOD_STATIC_DEF(AppView, void, error_noRecordInput);

METHOD_STATIC_DEF(AppView, void, out_studentInfo, int score, char grade);

METHOD_STATIC_DEF(AppView, bool, inputContinuable);
METHOD_STATIC_DEF(AppView, int,  inputScore);


#endif