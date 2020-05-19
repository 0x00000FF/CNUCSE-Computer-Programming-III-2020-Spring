#pragma once

#include <stdlib.h>
#include <setjmp.h>

#include <app/postfix.h>

#define  KEY_ESC          0x1B
#define  KEY_DASH         0x2D
#define  KEY_SHARP        0x23
#define  KEY_SLASH        0x2F
#define  KEY_BACKSLASH    0x5C
#define  KEY_CARET        0x5E

#define  IS_ALPHA(x)      ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
#define  IS_DIGIT(x)      (x >= '0' && x <= '9')
#define  TO_DIGIT(x)      (x - '0')

#define  MAX_NUMBER_OF_TOKENS  200

typedef struct {
	int       argc, result;
	char**    argv;

    char      expression[MAX_NUMBER_OF_TOKENS];
	postfix*  postfix;
} app_controller;


jmp_buf*           app_jmp_env();

app_controller*    app_controller_create      (int argc, char** argv);
void               app_controller_run         (app_controller* self);
void               app_controller_exit        (app_controller* self, int status);
int                app_controller_get_result  (app_controller* self);
void               app_controller_delete      (app_controller* self);