#ifndef __LECTURE_CLASS_H__
#define __LECTURE_CLASS_H__

#include <stdbool.h>
#include <mvc/oop.h>

CLASS(LectureClass,
	int capacity;
	int last;

	int* scores;
);

METHOD_STATIC_DEF(LectureClass, LectureClass*, create, int capacity);
METHOD_STATIC_DEF(LectureClass, char, grade, int score);
METHOD_STATIC_DEF(LectureClass, bool, scoreValid, int score);

METHOD_DEF(LectureClass, void,    destroy);
METHOD_DEF(LectureClass, int,     capacity);
METHOD_DEF(LectureClass, int,     size);
METHOD_DEF(LectureClass, bool,    empty);
METHOD_DEF(LectureClass, bool,    is_full);
METHOD_DEF(LectureClass, bool,    add,         int score);
METHOD_DEF(LectureClass, int,     at,          int pos);
METHOD_DEF(LectureClass, void,    sort_score);
METHOD_DEF(LectureClass, int*,    list);
METHOD_DEF(LectureClass, int,     min);
METHOD_DEF(LectureClass, int,     max);
METHOD_DEF(LectureClass, int,     sum);
METHOD_DEF(LectureClass, int,     aboveAverage);
METHOD_DEF(LectureClass, float,   average);
METHOD_DEF(LectureClass, void,    grades, int gradeList[5]);

#endif