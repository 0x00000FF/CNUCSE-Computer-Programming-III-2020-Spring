#pragma once

typedef struct {
    int min_test_size;
    int interval_size;
    int number_of_tests;
} parameter_set;

parameter_set* parameter_set_new(void);
parameter_set* parameter_set_new_with(int min, int interval, int num_tests);

void           parameter_set_delete(parameter_set* self);

void           parameter_set_set_min_test_size(parameter_set* self, int new_min_test_size);
int            parameter_set_get_min_test_size(parameter_set* self);

void           parameter_set_set_interval_size(parameter_set* self, int new_interval_size);
int            parameter_set_get_interval_size(parameter_set* self);

void           parameter_set_set_number_of_tests_size(parameter_set* self, int new_num_tests);
int            parameter_set_get_number_of_tests_size(parameter_set* self);

int            parameter_set_max_test_size(parameter_set* self);