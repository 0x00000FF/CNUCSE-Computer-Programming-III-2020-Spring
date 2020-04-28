#ifndef __MVC_H__
#define __MVC_H__

#include <assert.h>
#include <stdlib.h>


#if   _MSC_VER

#include <Windows.h>

#undef   min                          
#undef   max                          // min, max macro of Windows.h undef
#undef   DELETE                       // mvc_oop DELETE macro redefinition

#define  IS_MSVC                      _MSC_VER

#define  CONFIG_ENABLE_CONSOLE_TITLE  1
#define  CONFIG_CONSOLE_TITLE         L"6林瞒: 己利 贸府 App"

#endif

#include <mvc/oop.h>
#include <app/app_controller.h>

#endif