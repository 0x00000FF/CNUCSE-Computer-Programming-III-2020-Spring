#pragma once

#include <app/vector_int.h>

typedef VECTOR(element) unsorted_list;

element unsorted_list_remove_max(VECTOR(element)* self);