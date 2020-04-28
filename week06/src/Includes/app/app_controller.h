#ifndef __APP_CONTROLLER_H__
#define __APP_CONTROLLER_H__

#include <stdlib.h>
#include <mvc/oop.h>

#include <app/view/appview.h>
#include <app/model/lecture_class.h>

#define  MAX_NUMBER_OF_STUDENTS    100

CLASS(AppController,
	int    arg_count;
	char** arg_list;  // char*[] is not incompatible
	int    result;

	LectureClass* lc;
);

METHOD_STATIC_DEF(AppController, AppController*, create, int argc, char* argv[]);

METHOD_DEF(AppController, void, run);
METHOD_DEF(AppController, int, get_return);
METHOD_DEF(AppController, void, destroy);

#endif __APP_CONTROLLER_H__