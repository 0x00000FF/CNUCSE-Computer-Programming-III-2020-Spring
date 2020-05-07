#pragma once

#include <app/vector_student.h>
#include <model/lecture_class.h>
#include <model/student.h>

typedef struct {
    int              total;
    int              grade_count[5];
    lecture_class*   students;
} lecture_view;

lecture_view* lecture_view_create(lecture_class* list);
void          lecture_view_delete(lecture_view* self);

student* lecture_view_list(lecture_view* self);
int      lecture_view_total(lecture_view* self);

char     lecture_view_conv_grade(int score);
int      lecture_view_get_grade_count(lecture_view* self, char grade);
         
float    lecture_view_avg(lecture_view* self);
int      lecture_view_above_avg(lecture_view* self);
         
int      lecture_view_sum(lecture_view* self);
int      lecture_view_min(lecture_view* self);
int      lecture_view_max(lecture_view* self);
