#include <stdlib.h> // malloc
#include <string.h> // strcpy

#include <model/student.h>

student* student_create(student_id id, int score)
{
	student* new_student = (student*) malloc(sizeof(student));

	if (new_student == NULL) {
		return NULL;
	}

	strcpy_s(new_student->id, sizeof(id), id);
	new_student->score = score;

	return new_student;
}

void student_delete(student* self)
{
	if (self != NULL) {
		free(self);
	}
}

const char* student_get_student_id(student* self)
{
	return (const char*)self->id;
}

int student_get_score(student* self)
{
	return self->score;
}

bool student_is_id_valid(student_id id)
{
	return strlen(id) >= STUDENT_ID_LENGTH;
}

bool student_is_score_valid(int score)
{
	return score >= 0 || score <= 100;
}