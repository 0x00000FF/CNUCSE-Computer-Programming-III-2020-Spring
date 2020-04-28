#pragma once

#include <mvc/oop.h>

CLASS(AppController,
	int arg_count;
	char* arg_variadics[];
);

METHOD_STATIC_DEF(AppController, AppController*, new, int argc, char* argv[]);

METHOD_DEF(AppController, void, run);
METHOD_DEF(AppController, void, destroy);