#pragma once

#include <stdint.h>

typedef uint64_t student_id;

typedef struct {
	student_id id;
	int        score;
} student;

student*       student_create            (student_id id, int score);
void           student_delete            (student*   self);
const char*    student_get_student_id    (student*   self);
int            student_get_score         (student*   self);

