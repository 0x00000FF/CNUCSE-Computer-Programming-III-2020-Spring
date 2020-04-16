#ifndef __MVC_H__
#define __MVC_H__

#include <assert.h>
#include <stdlib.h>


#if   _MSC_VER

#include <Windows.h>

#undef   DELETE                       // mvc_oop DELETE macro redefinition

#define  IS_MSVC                      _MSC_VER

#define  CONFIG_ENABLE_CONSOLE_TITLE  1
#define  CONFIG_CONSOLE_TITLE         L"컴프3: 마방진 MVC App"

#endif

#include <mvc/oop.h>

int AppController(int argc, char* argv[]);

#endif