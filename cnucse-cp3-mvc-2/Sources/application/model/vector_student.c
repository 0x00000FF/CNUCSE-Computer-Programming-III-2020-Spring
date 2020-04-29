#include <assert.h> // assert
#include <string.h> // memcpy
#include <app/vector_student.h>

FUNC_VECTOR_NEW(student)
{
	VECTOR(student)* new_vector = (VECTOR(student)*) malloc(sizeof(VECTOR(student)));

	new_vector->data     = (student*)malloc(capacity * sizeof(student));
	new_vector->capacity = capacity;
	new_vector->size     = 0;

	return new_vector;
}

FUNC_VECTOR_AT(student)
{
	assert(at < VECTOR_SIZE(student)(self));
	return self->data[at];
}

FUNC_VECTOR_FRONT(student)
{
	assert(!VECTOR_EMPTY(student)(self));
	return self->data[0];
}

FUNC_VECTOR_BACK(student)
{
	assert(!VECTOR_EMPTY(student)(self));

	int size = VECTOR_SIZE(student)(self);
	return self->data[size - 1];
}

FUNC_VECTOR_DATA(student)
{
	return self->data;
}

FUNC_VECTOR_EMPTY(student)
{
	return self->size == 0;
}

FUNC_VECTOR_SIZE(student)
{
	return self->size;
}

FUNC_VECTOR_MAX_SIZE(student)
{
	return self->capacity;
}

FUNC_VECTOR_CLEAR(student)
{
	free(self->data);
	self->data = (student*)malloc(self->capacity * sizeof(student));
}

FUNC_VECTOR_INSERT(student)
{
	if (self->size == self->capacity) {
		student* temp = self->data;
		
		self->capacity *= 2;
		self->data = (student*)malloc(self->capacity * sizeof(student));

		if (self->data != NULL) {
			memcpy(self->data, temp, self->size);
			free(temp);
		}
		else {
			self->capacity /= 2;
			self->data = temp;

			return;
		}
	}
	
	for (int i = self->size; i > pos; ++i) {
	    self->data[i] = self->data[i - 1];
	}

	self->data[pos] = elem;
	self->size++;
}

FUNC_VECTOR_PUSH_BACK(student)
{
	VECTOR_INSERT(student)(self, elem, self->size);
}

FUNC_VECTOR_ERASE(student)
{
	for (int i = pos; i < self->size - 1; ++i) {
		self->data[i] = self->data[i + 1];
	}

	self->size--;
}

FUNC_VECTOR_POP_BACK(student)
{
	VECTOR_ERASE(student)(self, self->size - 1);
}

FUNC_VECTOR_SWAP(student)
{
	int pos_max = self->size - 1;

	if (pos1 > pos_max || pos2 > pos_max) {
		return;
	}

	student temp = self->data[pos1];
	self->data[pos1] = self->data[pos2];
	self->data[pos2] = temp;
}