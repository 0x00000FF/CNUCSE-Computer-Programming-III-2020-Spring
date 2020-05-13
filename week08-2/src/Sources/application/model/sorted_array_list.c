#include <app/sorted_array_list.h>

sorted_array_list*  sorted_array_list_new(int capacity)
{
    return VECTOR_NEW(element)(capacity);
}

void                sorted_array_list_delete(sorted_array_list* self)
{
    if (self != NULL)
        free(self);
}

bool                sorted_array_list_is_empty(sorted_array_list* self)
{
    return self->size == 0;
}

bool                sorted_array_list_is_full(sorted_array_list* self)
{
    return self->size == self->capacity;
}

int                 sorted_array_list_position_using_binary_search(sorted_array_list* self, element elem)
{
    int left = 0, right = VECTOR_SIZE(element)(self) - 1;
    int mid;

    while (left <= right) {
        mid = (left + right) >> 1;
        
        if (elem == VECTOR_AT(element)(self, mid)) {
            return mid;
        } 
        else if (elem < VECTOR_AT(element)(self, mid)) {
            right = mid - 1;
        }
        else if (elem > VECTOR_AT(element)(self, mid)) {
            left = mid + 1;
        }
    }
    
    return left;
}         

bool                sorted_array_list_add(sorted_array_list* self, element elem)
{
    if ( sorted_array_list_is_full(self) ) {
        return false;
    } 

    int insert_pos = sorted_array_list_position_using_binary_search(self, elem);
    VECTOR_INSERT(element)(self, elem, insert_pos);

    return true;
}

element             sorted_array_list_remove_max(sorted_array_list* self)
{
    element max = VECTOR_BACK(element)(self);
    VECTOR_POP_BACK(element)(self);

    return self;
}

element             sorted_array_list_min(sorted_array_list* self)
{
    return VECTOR_FRONT(element)(self);
}