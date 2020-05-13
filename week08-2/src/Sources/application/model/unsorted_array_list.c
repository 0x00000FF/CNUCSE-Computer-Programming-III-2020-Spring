#include <app/unsorted_array_list.h>


bool    unsorted_array_list_is_empty(unsorted_array_list* self)
{
    return self->size == 0;
}

bool    unsorted_array_list_is_full(unsorted_array_list* self)
{
    return self->size == self->capacity;
}

bool    unsorted_array_list_add(unsorted_array_list* self, element elem)
{
    if (unsorted_array_list_is_full(self)) {
        return false;
    }

    VECTOR_PUSH_BACK(element)(self, elem);
    
    return true;
}

element unsorted_array_list_get_min(unsorted_array_list* self)
{
    
}

int     unsorted_array_list_max_position_recursively(unsorted_array_list* self, int left, int right)
{
    if (left == right) {
        return left;
    } else {
        int mid = (left + right) / 2;
 
        int max_position_of_left  = unsorted_array_list_max_position_recursively(self, left, mid);
        int max_position_of_right = unsorted_array_list_max_position_recursively(self, mid + 1, right);

        return VECTOR_AT(element)(self, max_position_of_left) > VECTOR_AT(element)(self, max_position_of_right) 
               ? max_position_of_left : max_position_of_right;
    }
}

element unsorted_array_list_remove_max(unsorted_array_list* self)
{
    element max;
    int     max_position;

    max_position = unsorted_array_list_max_position_recursively(self, 0, self->size - 1);
    max = VECTOR_AT(element)(self, max_position);

    VECTOR_ERASE(element)(self, max_position);
    return max;
}