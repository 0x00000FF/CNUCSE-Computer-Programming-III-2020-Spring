#pragma once

#include <mvc/vector.h>
#include <model/student.h>
#include <app/vector_student.h>

typedef VECTOR(student) lecture_class;

void  lecture_class_sort_score(lecture_class* self);