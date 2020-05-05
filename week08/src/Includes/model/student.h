#pragma once

#include <stdbool.h>
#define  STUDENT_ID_LENGTH 9

// 18 for buffered size
typedef char student_id[STUDENT_ID_LENGTH + 18];

typedef struct {
	student_id      id;
	int             score;
} student;

student*       student_create            (student_id id, int score);
void           student_delete            (student*   self);
const char*    student_get_student_id    (student*   self);
int            student_get_score         (student*   self);

bool           student_is_id_valid       (student_id id);
bool           student_is_score_valid    (int score);
