#include <stdlib.h>
#include <app/parameter_set.h>

parameter_set* parameter_set_new(void)
{
    return (parameter_set*) malloc( sizeof(parameter_set) );
}

parameter_set* parameter_set_new_with(int min, int interval, int num_tests)
{
    parameter_set* set = parameter_set_new();

    set->min_test_size   = min;
    set->interval_size   = interval;
    set->number_of_tests = num_tests;

    return set;
}

void           parameter_set_delete(parameter_set* self)
{
    if (self != NULL) free(self);
}

void           parameter_set_set_min_test_size(parameter_set* self, int new_min_test_size)
{
    self->min_test_size = new_min_test_size;
}

int            parameter_set_get_min_test_size(parameter_set* self)
{
    return self->min_test_size;
}

void           parameter_set_set_interval_size(parameter_set* self, int new_interval_size)
{
    self->interval_size = new_interval_size;
}

int            parameter_set_get_interval_size(parameter_set* self)
{
    return self->interval_size;
}

void           parameter_set_set_number_of_tests_size(parameter_set* self, int new_num_tests)
{
    self->number_of_tests = new_num_tests;
}

int            parameter_set_get_number_of_tests_size(parameter_set* self)
{
    return self->number_of_tests;
}

int            parameter_set_max_test_size(parameter_set* self)
{
    return self->min_test_size + ( self->interval_size * (self->number_of_tests - 1) );
}