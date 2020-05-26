#pragma once

#include <app/vector_int.h>

typedef VECTOR(element) unsorted_array_list;

bool    unsorted_array_list_is_empty(unsorted_array_list* self);
bool    unsorted_array_list_is_full(unsorted_array_list* self);

bool    unsorted_array_list_add(unsorted_array_list* self, element elem);
element unsorted_array_list_remove_max(unsorted_array_list* self);
element unsorted_array_list_min(unsorted_array_list* self);