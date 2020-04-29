#include <stdlib.h> // malloc
#include <string.h> // strcpy

#include <model/student.h>

student* student_create(student_id id, int score)
{
	student* new_student = (student*) malloc(sizeof(student));

	if (new_student == NULL) {
		return NULL;
	}

	new_student->id    = id;
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