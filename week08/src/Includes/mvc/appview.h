#pragma once

#include <stdbool.h>

#include <model/student.h>
#include <model/lecture_view.h>

void     appview_out_println(const char* str);
void     appview_out_statistics(lecture_view* view);
void     appview_out_sorted_student_list(lecture_view* view);
void     appview_out_student_info(const student_id id, int score, char grade);

void     appview_err_too_long_id(student_id id, int max_length);
void     appview_err_invalid_score();

bool     appview_in_get_continue();
void     appview_in_get_student(student_id id, int* out_score);

