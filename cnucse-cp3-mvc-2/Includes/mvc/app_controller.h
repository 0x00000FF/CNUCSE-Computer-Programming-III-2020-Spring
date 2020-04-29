#pragma once

#include <stdlib.h>
#include <setjmp.h>

typedef struct {
	int    argc, result;
	char** argv;
} app_controller;


jmp_buf*           app_jmp_env();

app_controller*    app_controller_create      (int argc, char* argv);
void               app_controller_run         (app_controller* self);
void               app_controller_exit        (app_controller* self, int status);
int                app_controller_get_result  (app_controller* self);
void               app_controller_delete      (app_controller* self);