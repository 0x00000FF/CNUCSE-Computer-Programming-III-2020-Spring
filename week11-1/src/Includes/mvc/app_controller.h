#pragma once

#include <stdlib.h>
#include <setjmp.h>

#include <app/unsorted_array_list.h>

#include <app/parameter_set.h>

#define  MIN_TEST_SIZE      1000
#define  NUMBER_OF_TESTS    5
#define  INTERVAL_SIZE      1000

typedef struct {
	int                      argc, result;
	char**                   argv;

	unsorted_array_list*     test_data;
	parameter_set*           parameter_set;
} app_controller;


jmp_buf*           app_jmp_env();

app_controller*    app_controller_create      (int argc, char** argv);
void               app_controller_run         (app_controller* self);
void               app_controller_exit        (app_controller* self, int status);
int                app_controller_get_result  (app_controller* self);
void               app_controller_delete      (app_controller* self);