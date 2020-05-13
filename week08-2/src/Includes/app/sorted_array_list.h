#pragma once

#include <stdbool.h>
#include <app/vector_int.h>

typedef VECTOR(element) sorted_array_list;

sorted_array_list*  sorted_array_list_new(int capacity);
void                sorted_array_list_delete(sorted_array_list* self);

bool                sorted_array_list_is_empty(sorted_array_list* self);
bool                sorted_array_list_is_full(sorted_array_list* self);
            
bool                sorted_array_list_add(sorted_array_list* self, element elem);
element             sorted_array_list_remove_max(sorted_array_list* self);
element             sorted_array_list_min(sorted_array_list* self);
